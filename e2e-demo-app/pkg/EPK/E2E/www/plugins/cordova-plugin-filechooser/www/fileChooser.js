cordova.define("cordova-plugin-filechooser.FileChooser", function(require, exports, module) {
module.exports = {
    open: function (success, failure) {
        cordova.exec(success, failure, "FileChooser", "open", []);
    }
};

});
