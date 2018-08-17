cordova.define("ElaWallet.Wallet", function(require, exports, module) {
var exec = require('cordova/exec');

var walletFunc = function() {};


walletFunc.prototype.print = function(arg0, success, error) {
    exec(success, error, "Wallet", "print", arg0);
};


walletFunc.prototype.recoverWallet = function(arg0, success, error) {
    exec(success, error, "Wallet", "recoverWallet", arg0);
};

walletFunc.prototype.createWallet = function(arg0, success, error) {
    exec(success, error, "Wallet", "createWallet", arg0);
};

walletFunc.prototype.start = function(arg0, success, error) {
    exec(success, error, "Wallet", "start", arg0);
};

walletFunc.prototype.stop = function(arg0, success, error) {
    exec(success, error, "Wallet", "stop", arg0);
};

walletFunc.prototype.createSubWallet = function(arg0, success, error) {
    exec(success, error, "Wallet", "createSubWallet", arg0);
};

walletFunc.prototype.recoverSubWallet = function(arg0, success, error) {
    exec(success, error, "Wallet", "createSubWallet", arg0);
};

walletFunc.prototype.getPublicKey = function(arg0, success, error) {
    exec(success, error, "Wallet", "getPublicKey", arg0);
};

walletFunc.prototype.createMasterWallet = function(arg0, success, error) {
    exec(success, error, "Wallet", "createMasterWallet", arg0);
};

walletFunc.prototype.importWalletWithKeystore = function(arg0, success, error) {
    exec(success, error, "Wallet", "importWalletWithKeystore", arg0);
};

walletFunc.prototype.importWalletWithMnemonic = function(arg0, success, error) {
    exec(success, error, "Wallet", "importWalletWithMnemonic", arg0);
};

walletFunc.prototype.exportWalletWithKeystore = function(arg0, success, error) {
    exec(success, error, "Wallet", "exportWalletWithKeystore", arg0);
};
walletFunc.prototype.exportWalletWithMnemonic = function(arg0, success, error) {
    exec(success, error, "Wallet", "exportWalletWithMnemonic", arg0);
};

walletFunc.prototype.getBalanceInfo = function(arg0, success, error) {
    exec(success, error, "Wallet", "getBalanceInfo", arg0);
};

walletFunc.prototype.getBalance = function(arg0, success, error) {
    exec(success, error, "Wallet", "getBalance", arg0);
};

walletFunc.prototype.createAddress = function(arg0, success, error) {
    exec(success, error, "Wallet", "createAddress", arg0);
};

walletFunc.prototype.getAllAddress = function(arg0, success, error) {
    exec(success, error, "Wallet", "getAllAddress", arg0);
};
walletFunc.prototype.getBalanceWithAddress = function(arg0, success, error) {
    exec(success, error, "Wallet", "getBalanceWithAddress", arg0);
};

walletFunc.prototype.generateMultiSignTransaction = function(arg0, success, error) {
    exec(success, error, "Wallet", "generateMultiSignTransaction", arg0);
};
walletFunc.prototype.createMultiSignAddress = function(arg0, success, error) {
    exec(success, error, "Wallet", "createMultiSignAddress", arg0);
};
walletFunc.prototype.getAllTransaction = function(arg0, success, error) {
    exec(success, error, "Wallet", "getAllTransaction", arg0);
};
walletFunc.prototype.sign = function(arg0, success, error) {
    exec(success, error, "Wallet", "sign", arg0);
};
walletFunc.prototype.checkSign = function(arg0, success, error) {
    exec(success, error, "Wallet", "checkSign", arg0);
};

walletFunc.prototype.deriveIdAndKeyForPurpose = function(arg0, success, error) {
    exec(success, error, "Wallet", "deriveIdAndKeyForPurpose", arg0);
};

walletFunc.prototype.getAllMasterWallets = function(arg0, success, error) {
    exec(success, error, "Wallet", "getAllMasterWallets", arg0);

};

walletFunc.prototype.getBalanceInfo = function(arg0, success, error) {
    exec(success, error, "Wallet", "getBalanceInfo", arg0);

};

walletFunc.prototype.registerWalletListener = function(arg0, success, error) {
    exec(success, error, "Wallet", "registerWalletListener", arg0);

};


//



walletFunc.prototype.isAddressValid = function(arg0, success, error) {
    exec(success, error, "Wallet", "isAddressValid", arg0);
};

walletFunc.prototype.generateMnemonic = function(arg0, success, error) {
    exec(success, error, "Wallet", "generateMnemonic", arg0);
};

walletFunc.prototype.saveConfigs = function(arg0, success, error) {
    exec(success, error, "Wallet", "saveConfigs", arg0);
};

walletFunc.prototype.getWalletId = function(arg0, sucess, error) {
    exec(sucess, error, "Wallet", "getWalletId", arg0);
};

walletFunc.prototype.getAllChainIds = function(arg0, sucess, error) {
    exec(sucess, error, "Wallet", "getAllChainIds", arg0);
};

walletFunc.prototype.getSupportedChains = function(arg0, sucess, error) {
    exec(sucess, error, "Wallet", "getSupportedChains", arg0);
};

walletFunc.prototype.getAllSubWallets = function(arg0, sucess, error) {
    exec(sucess, error, "Wallet", "getAllSubWallets", arg0);
};

walletFunc.prototype.changePassword = function(arg0, sucess, error) {
    exec(sucess, error, "Wallet", "changePassword", arg0);
};

walletFunc.prototype.sendRawTransaction = function(arg0, sucess, error) {
    exec(sucess, error, "Wallet", "sendRawTransaction", arg0);
};

walletFunc.prototype.calculateTransactionFee = function(arg0, sucess, error) {
    exec(sucess, error, "Wallet", "calculateTransactionFee", arg0);
};

walletFunc.prototype.createTransaction = function(arg0, sucess, error) {
    exec(sucess, error, "Wallet", "createTransaction", arg0);
};


walletFunc.prototype.createDID = function(arg0, sucess, error) {
    exec(sucess, error, "Wallet", "createDID", arg0);
};

walletFunc.prototype.getDIDList = function(arg0, sucess, error) {
    exec(sucess, error, "Wallet", "getDIDList", arg0);
};

walletFunc.prototype.destoryDID = function(arg0, sucess, error) {
    exec(sucess, error, "Wallet", "destoryDID", arg0);
};

walletFunc.prototype.didSetValue = function(arg0, sucess, error) {
    exec(sucess, error, "Wallet", "didSetValue", arg0);
};

walletFunc.prototype.didGetValue = function(arg0, sucess, error) {
    exec(sucess, error, "Wallet", "didGetValue", arg0);
};

walletFunc.prototype.didGetHistoryValue = function(arg0, sucess, error) {
    exec(sucess, error, "Wallet", "didGetHistoryValue", arg0);
};


walletFunc.prototype.didGetAllKeys = function(arg0, sucess, error) {
    exec(sucess, error, "Wallet", "didGetAllKeys", arg0);
};


walletFunc.prototype.didSign = function(arg0, sucess, error) {
    exec(sucess, error, "Wallet", "didSign", arg0);
};

walletFunc.prototype.didCheckSign = function(arg0, sucess, error) {
    exec(sucess, error, "Wallet", "didCheckSign", arg0);
};

walletFunc.prototype.didGetPublicKey = function(arg0, sucess, error) {
    exec(sucess, error, "Wallet", "didGetPublicKey", arg0);
};

walletFunc.prototype.destroyWallet = function(arg0, sucess, error) {
    exec(sucess, error, "Wallet", "destroyWallet", arg0);
};

walletFunc.prototype.createIdTransaction = function(arg0, sucess, error) {
    exec(sucess, error, "Wallet", "createIdTransaction", arg0);
};

walletFunc.prototype.createDepositTransaction = function(arg0, sucess, error) {
    exec(sucess, error, "Wallet", "createDepositTransaction", arg0);
};

walletFunc.prototype.createWithdrawTransaction = function(arg0, sucess, error) {
    exec(sucess, error, "Wallet", "createWithdrawTransaction", arg0);
};

walletFunc.prototype.getGenesisAddress = function(arg0, sucess, error) {
    exec(sucess, error, "Wallet", "getGenesisAddress", arg0);
};


walletFunc.prototype.didGenerateProgram = function(arg0, sucess, error) {
    exec(sucess, error, "Wallet", "didGenerateProgram", arg0);
};

walletFunc.prototype.getAllCreatedSubWallets = function(arg0, sucess, error) {
    exec(sucess, error, "Wallet", "getAllCreatedSubWallets", arg0);
};

walletFunc.prototype.registerIdListener = function(arg0, success, error) {
  exec(success, error, "Wallet", "registerIdListener", arg0);

};

var WALLETFUNC = new walletFunc();
module.exports = WALLETFUNC;

});
