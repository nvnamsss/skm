import { ReactElement, useState, useEffect } from 'react'
import { getDailyQuote, sendLikeRequest } from "./services/quote";


function App(): ReactElement {
  let [quoteData, setQuoteData] = useState({
    "id": 0,
    "content": "I'm at a payphone trying to go home",
    "author": "Maroon5",
    "like": 0,
  })
  let [likeClicked, setLikeClicked] = useState(true)
  let [dislikeClicked, setDislikeClicked] = useState(true)
  let [like, setLike] = useState(0)
  useEffect(() => {
    async function call() {
      let res = await getDailyQuote();
      setQuoteData(res.data);
      console.log("get quotes of the day: ", quoteData);
      setLike(res.data.like);
    }
    call();
  }, []);

  useEffect( () => {
     async function call() {
      let res = await sendLikeRequest(quoteData.id, false);
      console.log("like", res);
      setLike(res.data.like);
    }

    if (quoteData.id > 0) {
      call();
    }
  }, [likeClicked]);

  useEffect( () => {
     async function call() {
      let res = await sendLikeRequest(quoteData.id, true);
      console.log("dislike", res);
      setLike(res.data.like);
    }

    if (quoteData.id > 0) {
      call();
    }
  }, [dislikeClicked]);
  return (
    <div className="border border-gray-50 rounded-xl px-48 py-20">
      <header>
        <p className="text-4xl pb-3 font-quote">{quoteData.content}</p>
        
        <p className="pb-3 pt-3">
          <code className="border border-1 pl-1 pr-1 pb-0.5 pt-0.5 rounded border-purple-400 font-mono text-sm bg-purple-100 text-purple-900">
            { quoteData.author }
          </code> 
        </p>
        <p>Like: {like}</p>
        <p className='mt-10'>
          <button className='bg-blue-500 hover:bg-blue-700 text-white py-2 px-4 rounded' onClick={()=> {setLikeClicked(!likeClicked)}} >Like</button>
          <button className='bg-blue-500 hover:bg-blue-700 text-white py-2 px-4 rounded' onClick={()=> {setDislikeClicked(!dislikeClicked)}} >Dislike</button>
        </p>
      </header>
    </div>
  )
}

export default App
