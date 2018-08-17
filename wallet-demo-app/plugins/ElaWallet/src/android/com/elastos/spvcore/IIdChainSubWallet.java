package com.elastos.spvcore;

/**
 * IIdChainSubWallet jni
 */
public class IIdChainSubWallet extends ISubWallet{
    private long mIDchainProxy;


    public String CreateIdTransaction(String fromAddress, String toAddress, long amount,
            String payloadJson, String programJson, long fee, String memo, String remark) throws WalletException {
        return nativeCreateIdTransaction(mIDchainProxy, fromAddress, toAddress, amount, payloadJson, programJson, fee, memo, remark);
    }

    public IIdChainSubWallet(long proxy) {
        super(proxy);
        mIDchainProxy = proxy;
    }

    private native String nativeCreateIdTransaction(long proxy, String fromAddress, String toAddress, long amount,
            String payloadJson, String programJson, long fee, String memo, String remark);
}
