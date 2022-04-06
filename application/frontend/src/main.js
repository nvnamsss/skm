import { createApp, onMounted } from 'vue'
import App from './App.vue'
// const app = createApp({
//     data() {
//       return {
//         quote: 'aaaa'
//       }
//     },
//     watch: {
//         quote(newQuote, oldQuote) {

//         }
//     },
//     mounted() {
//         console.log('hi mom');
//     }
// });

const app = createApp(App);
app.mount('#app')
