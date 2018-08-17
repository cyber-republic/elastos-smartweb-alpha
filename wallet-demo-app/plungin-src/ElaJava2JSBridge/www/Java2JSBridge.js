
  
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
      },


      getDeviceID:function(succeedCallback) {
        cordova.require('cordova/channel').onCordovaReady.subscribe(function()
        {
            exec(succeedCallback, null, "Java2JSBridge", "getDeviceID", []);
        });
      },

      getRegistrationID:function(succeedCallback) {
        cordova.require('cordova/channel').onCordovaReady.subscribe(function()
        {
            exec(succeedCallback, null, "Java2JSBridge", "getRegistrationID", []);
        });
      }

};

module.exports = Java2jsBridge;
