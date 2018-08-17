cordova.define("ElaJava2JSBridge.Java2JSBridge", function(require, exports, module) {
  /*
   *
   * xxl
   *
  */
  
  var exec = require('cordova/exec');
  
  var Java2jsBridge = {
        init:function(handle) {
  
  
            cordova.require('cordova/channel').onCordovaReady.subscribe(function()
            {
  
               exec(succeedCallback, null, "Java2JSBridge", "callJSInit", []);
               function succeedCallback(message){
  
                 var result = eval(message);
                 exec(succeedCallback, null, "Java2JSBridge", "getResult", [result]);
               }
            });
        }
  };
  module.exports = Java2jsBridge;
  
  });
  