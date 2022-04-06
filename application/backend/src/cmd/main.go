package main

import (
	"context"
	"famous-quote/adapters/cache"
	"famous-quote/adapters/database"
	"famous-quote/configs"
	"famous-quote/controllers"
	"famous-quote/logger"
	"famous-quote/repositories"
	"famous-quote/services"
	"net"
	"net/http"
	"os"
	"os/signal"
	"time"

	"github.com/gin-gonic/gin"
	"github.com/go-redis/redis/v8"
	"gorm.io/gorm"
)

func main() {
	db := database.NewDatabase()
	if err := db.Open(configs.Config.MySql.ConnectionString(), gorm.Config{}); err != nil {
		logger.Fatalf(err, "Creating connection to DB: %v", err)
	}

	redisClient := redis.NewClient(&redis.Options{
		Addr:               configs.Config.Redis.URL(),
		Password:           configs.Config.Redis.Password,
		DB:                 configs.Config.Redis.Database,
		IdleCheckFrequency: 60 * time.Second,
		Dialer: func(ctx context.Context, network, addr string) (net.Conn, error) {
			netDialer := &net.Dialer{
				Timeout:   10 * time.Second,
				KeepAlive: 5 * time.Minute,
			}
			conn, err := netDialer.DialContext(ctx, network, addr)
			if err != nil {
				logger.Context(ctx).Errorf("[Redis] Dial connection %v", err)
			}
			return conn, err
		},
	})

	if _, err := redisClient.Ping(context.Background()).Result(); err != nil {
		logger.Fatalf(err, "Creating connection to redis: %v", err)
	}
	var r = gin.Default()

	var (
		cacheAdapter = cache.NewRedisAdapter(redisClient)
	)
	var (
		quotesRepository = repositories.NewQuotesRepository(db, cacheAdapter)
	)
	var (
		quotesService = services.NewQuotesService(quotesRepository)
	)
	var (
		quotesController = controllers.NewQuotesController(quotesService)
	)

	v1 := r.Group("/famous-quotes/v1")
	{
		quotes := v1.Group("/quotes")
		{
			quotes.POST("/", quotesController.Create)
			quotes.GET("/", quotesController.Get)
			quotes.POST("/like/:id", quotesController.Like)
		}
	}

	server := &http.Server{
		Addr:    configs.Config.AddressListener(),
		Handler: r,
	}

	go func() {
		logger.Infof("Starting Server on %v", server.Addr)
		if err := server.ListenAndServe(); err != nil && err != http.ErrServerClosed {
			logger.Fatalf(err, "Opening HTTP server: %v", err)
		}
	}()
	c := make(chan os.Signal, 1)
	signal.Notify(c, os.Interrupt)
	<-c

	logger.Infof("Shutting down...")

	ctx, cancel := context.WithTimeout(context.Background(), time.Second*30)
	defer cancel()
	if err := server.Shutdown(ctx); err != nil {
		logger.Errorf("Shutdown error: %v", err)
	}
}

func init() {
	if _, err := configs.New(); err != nil {
		os.Exit(1)
	}
}