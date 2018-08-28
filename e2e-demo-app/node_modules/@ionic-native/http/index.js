var __extends = (this && this.__extends) || (function () {
    var extendStatics = Object.setPrototypeOf ||
        ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
        function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (this && this.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};
import { Injectable } from '@angular/core';
import { Cordova, IonicNativePlugin, Plugin } from '@ionic-native/core';
/**
 * @name HTTP
 * @description
 * Cordova / Phonegap plugin for communicating with HTTP servers. Supports iOS and Android.
 *
 * Advantages over Javascript requests:
 * - Background threading - all requests are done in a background thread
 * - SSL Pinning
 *
 * @usage
 * ```typescript
 * import { HTTP } from '@ionic-native/http';
 *
 * constructor(private http: HTTP) {}
 *
 * ...
 *
 * this.http.get('http://ionic.io', {}, {})
 *   .then(data => {
 *
 *     console.log(data.status);
 *     console.log(data.data); // data received by server
 *     console.log(data.headers);
 *
 *   })
 *   .catch(error => {
 *
 *     console.log(error.status);
 *     console.log(error.error); // error message as string
 *     console.log(error.headers);
 *
 *   });
 *
 * ```
 * @interfaces
 * HTTPResponse
 */
var HTTP = (function (_super) {
    __extends(HTTP, _super);
    function HTTP() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    /**
     * This returns an object representing a basic HTTP Authorization header of the form.
     * @param username {string} Username
     * @param password {string} Password
     * @returns {Object} an object representing a basic HTTP Authorization header of the form {'Authorization': 'Basic base64encodedusernameandpassword'}
     */
    HTTP.prototype.getBasicAuthHeader = function (username, password) {
        return;
    };
    /**
     * This sets up all future requests to use Basic HTTP authentication with the given username and password.
     * @param username {string} Username
     * @param password {string} Password
     */
    HTTP.prototype.useBasicAuth = function (username, password) { };
    /**
     * Get all headers defined for a given hostname.
     * @param host {string} The hostname
     * @returns {string} return all headers defined for the hostname
     */
    HTTP.prototype.getHeaders = function (host) {
        return;
    };
    /**
     * Set a header for all future requests. Takes a hostname, a header and a value.
     * @param host {string} The hostname to be used for scoping this header
     * @param header {string} The name of the header
     * @param value {string} The value of the header
     */
    HTTP.prototype.setHeader = function (host, header, value) { };
    /**
     * Get the name of the data serializer which will be used for all future POST and PUT requests.
     * @returns {string} returns the name of the configured data serializer
     */
    HTTP.prototype.getDataSerializer = function () {
        return;
    };
    /**
     * Set the data serializer which will be used for all future POST and PUT requests. Takes a string representing the name of the serializer.
     * @param serializer {string} The name of the serializer. Can be urlencoded, utf8 or json
     */
    HTTP.prototype.setDataSerializer = function (serializer) { };
    /**
     * Add a custom cookie.
     * @param url {string} Scope of the cookie
     * @param cookie {string} RFC compliant cookie string
     */
    HTTP.prototype.setCookie = function (url, cookie) { };
    /**
     * Clear all cookies.
     */
    HTTP.prototype.clearCookies = function () { };
    /**
     * Remove cookies for given URL.
     * @param url {string}
     * @param cb
     */
    HTTP.prototype.removeCookies = function (url, cb) { };
    /**
     * Resolve cookie string for given URL.
     * @param url {string}
     */
    HTTP.prototype.getCookieString = function (url) { return; };
    /**
     * Get global request timeout value in seconds.
     * @returns {number} returns the global request timeout value
     */
    HTTP.prototype.getRequestTimeout = function () {
        return;
    };
    /**
     * Set global request timeout value in seconds.
     * @param timeout {number} The timeout in seconds. Default 60
     */
    HTTP.prototype.setRequestTimeout = function (timeout) { };
    /**
     * Enable or disable SSL Pinning. This defaults to false.
     *
     * To use SSL pinning you must include at least one .cer SSL certificate in your app project. You can pin to your server certificate or to one of the issuing CA certificates. For ios include your certificate in the root level of your bundle (just add the .cer file to your project/target at the root level). For android include your certificate in your project's platforms/android/assets folder. In both cases all .cer files found will be loaded automatically. If you only have a .pem certificate see this [stackoverflow answer](https://stackoverflow.com/questions/16583428/how-to-convert-an-ssl-certificate-in-linux/16583429#16583429). You want to convert it to a DER encoded certificate with a .cer extension.
     *
     * As an alternative, you can store your .cer files in the www/certificates folder.
     * @param enable {boolean} Set to true to enable
     * @returns {Promise<void>} returns a promise that will resolve on success, and reject on failure
     */
    HTTP.prototype.enableSSLPinning = function (enable) {
        return;
    };
    /**
     * Accept all SSL certificates. Or disabled accepting all certificates. Defaults to false.
     * @param accept {boolean} Set to true to accept
     * @returns {Promise<void>} returns a promise that will resolve on success, and reject on failure
     */
    HTTP.prototype.acceptAllCerts = function (accept) {
        return;
    };
    /**
     * Disable following redirects automatically.
     * @param disable {boolean} Set to true to disable following redirects automatically
     * @returns {Promise<void>} returns a promise that will resolve on success, and reject on failure
     */
    HTTP.prototype.disableRedirect = function (disable) { return; };
    /**
     * Make a POST request
     * @param url {string} The url to send the request to
     * @param body {Object} The body of the request
     * @param headers {Object} The headers to set for this request
     * @returns {Promise<HTTPResponse>} returns a promise that resolve on success, and reject on failure
     */
    HTTP.prototype.post = function (url, body, headers) {
        return;
    };
    /**
     * Make a GET request
     * @param url {string} The url to send the request to
     * @param parameters {Object} Parameters to send with the request
     * @param headers {Object} The headers to set for this request
     * @returns {Promise<HTTPResponse>} returns a promise that resolve on success, and reject on failure
     */
    HTTP.prototype.get = function (url, parameters, headers) {
        return;
    };
    /**
     * Make a PUT request
     * @param url {string} The url to send the request to
     * @param body {Object} The body of the request
     * @param headers {Object} The headers to set for this request
     * @returns {Promise<HTTPResponse>} returns a promise that resolve on success, and reject on failure
     */
    HTTP.prototype.put = function (url, body, headers) {
        return;
    };
    /**
     * Make a PATCH request
     * @param url {string} The url to send the request to
     * @param body {Object} The body of the request
     * @param headers {Object} The headers to set for this request
     * @returns {Promise<HTTPResponse>} returns a promise that resolve on success, and reject on failure
     */
    HTTP.prototype.patch = function (url, body, headers) {
        return;
    };
    /**
     * Make a DELETE request
     * @param url {string} The url to send the request to
     * @param parameters {Object} Parameters to send with the request
     * @param headers {Object} The headers to set for this request
     * @returns {Promise<HTTPResponse>} returns a promise that resolve on success, and reject on failure
     */
    HTTP.prototype.delete = function (url, parameters, headers) {
        return;
    };
    /**
     * Make a HEAD request
     * @param url {string} The url to send the request to
     * @param parameters {Object} Parameters to send with the request
     * @param headers {Object} The headers to set for this request
     * @returns {Promise<HTTPResponse>} returns a promise that resolve on success, and reject on failure
     */
    HTTP.prototype.head = function (url, parameters, headers) {
        return;
    };
    /**
     *
     * @param url {string} The url to send the request to
     * @param body {Object} The body of the request
     * @param headers {Object} The headers to set for this request
     * @param filePath {string} The local path of the file to upload
     * @param name {string} The name of the parameter to pass the file along as
     * @returns {Promise<HTTPResponse>} returns a promise that resolve on success, and reject on failure
     */
    HTTP.prototype.uploadFile = function (url, body, headers, filePath, name) {
        return;
    };
    /**
     *
     * @param url {string} The url to send the request to
     * @param body {Object} The body of the request
     * @param headers {Object} The headers to set for this request
     * @param filePath {string} The path to donwload the file to, including the file name.
     * @returns {Promise<HTTPResponse>} returns a promise that resolve on success, and reject on failure
     */
    HTTP.prototype.downloadFile = function (url, body, headers, filePath) {
        return;
    };
    HTTP.decorators = [
        { type: Injectable },
    ];
    /** @nocollapse */
    HTTP.ctorParameters = function () { return []; };
    __decorate([
        Cordova({ sync: true }),
        __metadata("design:type", Function),
        __metadata("design:paramtypes", [String, String]),
        __metadata("design:returntype", Object)
    ], HTTP.prototype, "getBasicAuthHeader", null);
    __decorate([
        Cordova({ sync: true }),
        __metadata("design:type", Function),
        __metadata("design:paramtypes", [String, String]),
        __metadata("design:returntype", void 0)
    ], HTTP.prototype, "useBasicAuth", null);
    __decorate([
        Cordova({ sync: true }),
        __metadata("design:type", Function),
        __metadata("design:paramtypes", [String]),
        __metadata("design:returntype", String)
    ], HTTP.prototype, "getHeaders", null);
    __decorate([
        Cordova({ sync: true }),
        __metadata("design:type", Function),
        __metadata("design:paramtypes", [String, String, String]),
        __metadata("design:returntype", void 0)
    ], HTTP.prototype, "setHeader", null);
    __decorate([
        Cordova({ sync: true }),
        __metadata("design:type", Function),
        __metadata("design:paramtypes", []),
        __metadata("design:returntype", String)
    ], HTTP.prototype, "getDataSerializer", null);
    __decorate([
        Cordova({ sync: true }),
        __metadata("design:type", Function),
        __metadata("design:paramtypes", [String]),
        __metadata("design:returntype", void 0)
    ], HTTP.prototype, "setDataSerializer", null);
    __decorate([
        Cordova({ sync: true }),
        __metadata("design:type", Function),
        __metadata("design:paramtypes", [String, String]),
        __metadata("design:returntype", void 0)
    ], HTTP.prototype, "setCookie", null);
    __decorate([
        Cordova({ sync: true }),
        __metadata("design:type", Function),
        __metadata("design:paramtypes", []),
        __metadata("design:returntype", void 0)
    ], HTTP.prototype, "clearCookies", null);
    __decorate([
        Cordova({ sync: true }),
        __metadata("design:type", Function),
        __metadata("design:paramtypes", [String, Function]),
        __metadata("design:returntype", void 0)
    ], HTTP.prototype, "removeCookies", null);
    __decorate([
        Cordova({ sync: true }),
        __metadata("design:type", Function),
        __metadata("design:paramtypes", [String]),
        __metadata("design:returntype", String)
    ], HTTP.prototype, "getCookieString", null);
    __decorate([
        Cordova({ sync: true }),
        __metadata("design:type", Function),
        __metadata("design:paramtypes", []),
        __metadata("design:returntype", Number)
    ], HTTP.prototype, "getRequestTimeout", null);
    __decorate([
        Cordova({ sync: true }),
        __metadata("design:type", Function),
        __metadata("design:paramtypes", [Number]),
        __metadata("design:returntype", void 0)
    ], HTTP.prototype, "setRequestTimeout", null);
    __decorate([
        Cordova(),
        __metadata("design:type", Function),
        __metadata("design:paramtypes", [Boolean]),
        __metadata("design:returntype", Promise)
    ], HTTP.prototype, "enableSSLPinning", null);
    __decorate([
        Cordova(),
        __metadata("design:type", Function),
        __metadata("design:paramtypes", [Boolean]),
        __metadata("design:returntype", Promise)
    ], HTTP.prototype, "acceptAllCerts", null);
    __decorate([
        Cordova(),
        __metadata("design:type", Function),
        __metadata("design:paramtypes", [Boolean]),
        __metadata("design:returntype", Promise)
    ], HTTP.prototype, "disableRedirect", null);
    __decorate([
        Cordova(),
        __metadata("design:type", Function),
        __metadata("design:paramtypes", [String, Object, Object]),
        __metadata("design:returntype", Promise)
    ], HTTP.prototype, "post", null);
    __decorate([
        Cordova(),
        __metadata("design:type", Function),
        __metadata("design:paramtypes", [String, Object, Object]),
        __metadata("design:returntype", Promise)
    ], HTTP.prototype, "get", null);
    __decorate([
        Cordova(),
        __metadata("design:type", Function),
        __metadata("design:paramtypes", [String, Object, Object]),
        __metadata("design:returntype", Promise)
    ], HTTP.prototype, "put", null);
    __decorate([
        Cordova(),
        __metadata("design:type", Function),
        __metadata("design:paramtypes", [String, Object, Object]),
        __metadata("design:returntype", Promise)
    ], HTTP.prototype, "patch", null);
    __decorate([
        Cordova(),
        __metadata("design:type", Function),
        __metadata("design:paramtypes", [String, Object, Object]),
        __metadata("design:returntype", Promise)
    ], HTTP.prototype, "delete", null);
    __decorate([
        Cordova(),
        __metadata("design:type", Function),
        __metadata("design:paramtypes", [String, Object, Object]),
        __metadata("design:returntype", Promise)
    ], HTTP.prototype, "head", null);
    __decorate([
        Cordova(),
        __metadata("design:type", Function),
        __metadata("design:paramtypes", [String, Object, Object, String, String]),
        __metadata("design:returntype", Promise)
    ], HTTP.prototype, "uploadFile", null);
    __decorate([
        Cordova(),
        __metadata("design:type", Function),
        __metadata("design:paramtypes", [String, Object, Object, String]),
        __metadata("design:returntype", Promise)
    ], HTTP.prototype, "downloadFile", null);
    HTTP = __decorate([
        Plugin({
            pluginName: 'HTTP',
            plugin: 'cordova-plugin-advanced-http',
            pluginRef: 'cordova.plugin.http',
            repo: 'https://github.com/silkimen/cordova-plugin-advanced-http',
            platforms: ['Android', 'iOS']
        })
    ], HTTP);
    return HTTP;
}(IonicNativePlugin));
export { HTTP };
//# sourceMappingURL=index.js.map