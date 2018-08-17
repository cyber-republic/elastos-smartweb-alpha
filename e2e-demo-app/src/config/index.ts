export default {
  ditto : {
    url : 'http://localhost:8000/remote.php/dav/files/admin',
    username : 'admin',
    password : '111111',

    getUrl(url){
      return `http://${url}/remote.php/dav/files/admin`;
    },

    // address : 'R5eKQ7xe4iBiJZR5nujP5jpSLKM9daEjnxFweNQBy5HhqQDsNDB9',   //local
    secret : 'secret'
  },
  ipfs : {
    url : '/ip4/127.0.0.1/tcp/5001'
  },
  did : {
    key : 'E2E_DEMO'
  },
  wallet : {
    SELA : 100000000
  }
};
