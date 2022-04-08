import axios from "axios";

const instance = axios.create({
  // baseURL: "http://ec2-13-250-113-138.ap-southeast-1.compute.amazonaws.com",
  baseURL: import.meta.env.VITE_FAMOUS_QUOTES_HOST,
  headers: {
    'Access-Control-Allow-Origin' : 'origin',
    // 'Origin': 'localhost',
    'Content-Type': 'application/json'
  },
});

export default instance;
