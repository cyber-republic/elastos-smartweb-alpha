package com.elastos.spvcore;

/**
 * IIdChainSubWallet jni
 */
public class IIdChainSubWallet extends ISidechainSubWallet{
    private long mIDchainProxy;


    public String CreateIdTransaction(String fromAddress, String payloadJson, String programJson, String memo, String remark) throws WalletException {
        return nativeCreateIdTransaction(mIDchainProxy, fromAddress, payloadJson, programJson, memo, remark);
    }

    public IIdChainSubWallet(long proxy) {
        super(proxy);
        mIDchainProxy = proxy;
    }

    private native String nativeCreateIdTransaction(long proxy, String fromAddress,
            String payloadJson, String programJson, String memo, String remark);
}
