
package com.elastos.spvcore;

/**
 * ISubWallet
 */
public class ISubWallet {
    private long mSubProxy;

    public String GetChainId() {
        return nativeGetChainId(mSubProxy);
    }

    public String GetBalanceInfo() {
        return nativeGetBalanceInfo(mSubProxy);
    }

    public long GetBalance() {
        return nativeGetBalance(mSubProxy);
    }

    public String CreateAddress() {
        return nativeCreateAddress(mSubProxy);
    }

    public String GetAllAddress(int start, int count) {
        return nativeGetAllAddress(mSubProxy, start, count);
    }

    public long GetBalanceWithAddress(String address) {
        return nativeGetBalanceWithAddress(mSubProxy, address);
    }

    public void AddCallback(ISubWalletCallback subCallback) {
        nativeAddCallback(mSubProxy, subCallback);
    }

    public void RemoveCallback(ISubWalletCallback subCallback) {
        nativeRemoveCallback(mSubProxy, subCallback);
    }

    public String CreateTransaction(String fromAddress, String toAddress, long amount, long fee, String memo, String remark) throws WalletException {
        return nativeCreateTransaction(mSubProxy, fromAddress, toAddress, amount, fee, memo, remark);
    }

    public String CreateMultiSignAddress(String multiPublicKeyJson, int totalSignNum, int requiredSignNum) {
        return nativeCreateMultiSignAddress(mSubProxy, multiPublicKeyJson, totalSignNum, requiredSignNum);
    }

    public String CreateMultiSignTransaction(String fromAddress, String toAddress, long amount, long fee, String memo) throws WalletException {
        return nativeCreateMultiSignTransaction(mSubProxy, fromAddress, toAddress, amount, fee, memo);
    }

    public String SendRawTransaction(String transactionJson, long fee, String payPassword) throws WalletException {
        return nativeSendRawTransaction(mSubProxy, transactionJson, fee, payPassword);
    }

    public String GetAllTransaction(int start, int count, String addressOrTxId) {
        return nativeGetAllTransaction(mSubProxy, start, count, addressOrTxId);
    }

    public String Sign(String message, String payPassword) throws WalletException {
        return nativeSign(mSubProxy, message, payPassword);
    }

    public boolean CheckSign(String address, String message, String signature) throws WalletException {
        return nativeCheckSign(mSubProxy, address, message, signature);
    }

    public long CalculateTransactionFee(String rawTransaction, long feePerKb) throws WalletException {
        return nativeCalculateTransactionFee(mSubProxy, rawTransaction, feePerKb);
    }

    public ISubWallet(long proxy) {
        mSubProxy = proxy;
    }

    protected long getProxy() {
        return mSubProxy;
    }

    private native String nativeGetChainId(long subProxy);
    private native String nativeGetBalanceInfo(long subProxy);
    private native long nativeGetBalance(long subProxy);
    private native String nativeCreateAddress(long subProxy);
    private native String nativeGetAllAddress(long subProxy, int start,int count);
    private native long nativeGetBalanceWithAddress(long subProxy, String address);
    private native void nativeAddCallback(long subProxy, ISubWalletCallback subCallback);
    private native void nativeRemoveCallback(long subProxy, ISubWalletCallback subCallback);
    private native String nativeCreateTransaction(long subProxy, String fromAddress, String toAddress, long amount, long fee, String memo, String remark);
    private native String nativeCreateMultiSignTransaction(long subProxy, String fromAddress, String toAddress, long amount, long fee, String memo);
    private native String nativeCreateMultiSignAddress(long subProxy, String multiPublicKeyJson, int totalSignNum, int requiredSignNum);
    private native String nativeSendRawTransaction(long subProxy, String transactionJson, long fee, String payPassword);
    private native String nativeGetAllTransaction(long subProxy, int start, int count, String addressOrTxId);
    private native String nativeSign(long subProxy, String message, String payPassword);
    private native boolean nativeCheckSign(long subProxy, String address, String message, String signature);
    private native long nativeCalculateTransactionFee(long subProxy, String rawTransaction, long feePerKb);
}
