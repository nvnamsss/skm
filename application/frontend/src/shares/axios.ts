import axios from "axios";

const instance = axios.create({
  baseURL: "http://localhost:8080",
  // baseURL: "http://ec2-13-250-113-138.ap-southeast-1.compute.amazonaws.com",
  headers: {
    'Access-Control-Allow-Origin' : 'origin',
    // 'Origin': 'localhost',
    'Content-Type': 'application/json'
  },
});

export default instance;
