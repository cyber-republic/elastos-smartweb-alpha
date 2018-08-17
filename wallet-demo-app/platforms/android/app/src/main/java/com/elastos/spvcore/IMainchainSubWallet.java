package com.elastos.spvcore;

/**
 * IMainchainSubWallet jni
 */
public class IMainchainSubWallet extends ISubWallet {
    private long mMainchainProxy;


    public String CreateDepositTransaction(String fromAddress, String toAddress, long amount, String sidechainAccounts,
            String sidechainAmounts, String sidechainIndexs, String memo, String remark) throws WalletException {
        return nativeCreateDepositTransaction(mMainchainProxy, fromAddress, toAddress, amount, sidechainAccounts,
                    sidechainAmounts, sidechainIndexs, memo, remark);
    }

    public IMainchainSubWallet(long proxy) {
        super(proxy);
        mMainchainProxy = proxy;
    }

    private native String nativeCreateDepositTransaction(long proxy, String fromAddress, String toAddress, long amount
            , String sidechainAccounts, String sidechainAmounts, String sidechainIndexs, String memo, String remark);
}
