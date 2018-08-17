package com.elastos.spvcore;

/**
 * ISidechainSubWallet jni
 */
public class ISidechainSubWallet extends ISubWallet {
    private long mSidechainProxy;

    public String CreateWithdrawTransaction(String fromAddress, String toAddress, long amount, String mainchainAccounts,
                String mainchainAmounts, String mainchainIndexs, String memo, String remark) throws WalletException {
        return nativeCreateWithdrawTransaction(mSidechainProxy, fromAddress, toAddress, amount, mainchainAccounts, mainchainAmounts,
                    mainchainIndexs, memo, remark);
    }

    public String GetGenesisAddress() throws WalletException {
        return nativeGetGenesisAddress(mSidechainProxy);
    }

    public ISidechainSubWallet(long proxy) {
        super(proxy);
        mSidechainProxy = proxy;
    }

    private native String nativeCreateWithdrawTransaction(long proxy, String fromAddress, String toAddress, long amount, String mainchainAccounts,
                String mainchainAmounts, String mainchainIndexs, String memo, String remark);

    private native String nativeGetGenesisAddress(long proxy);
}
