cordova.define("Elastos.Carrier", function(require, exports, module) {
module.exports = {
    connect: function (arg, success, failure) {
        cordova.exec(success, failure, "ElaCarrier", "init", arg);
    }
};

});