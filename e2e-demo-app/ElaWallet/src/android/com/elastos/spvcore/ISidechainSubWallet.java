package com.elastos.spvcore;

/**
 * ISidechainSubWallet jni
 */
public class ISidechainSubWallet {
    private long mSidechainProxy;

    public String CreateWithdrawTransaction(String fromAddress, String toAddress, long amount, String mainchainAccounts,
                String mainchainAmounts, String mainchainIndexs, long fee, String memo, String remark)
    {
        return nativeCreateWithdrawTransaction(mSidechainProxy, fromAddress, toAddress, amount, mainchainAccounts, mainchainAmounts,
                    mainchainIndexs, fee, memo, remark);
    }

    public ISidechainSubWallet(long proxy) {
        mSidechainProxy = proxy;
    }

    private native String nativeCreateWithdrawTransaction(long proxy, String fromAddress, String toAddress, long amount, String mainchainAccounts,
                String mainchainAmounts, String mainchainIndexs, long fee, String memo, String remark);
}
