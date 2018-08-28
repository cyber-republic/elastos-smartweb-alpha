
package com.elastos.spvcore;

import java.util.ArrayList;
import android.util.Log;

/**
 * IMasterWallet
 */
public class IMasterWallet {
    static public class CHAINID {
        public static String MAIN = "ELA";
        public static String ID = "IdChain";
    }

    private long mMasterProxy;

    public String GetId() {
        return nativeGetId(mMasterProxy);
    }

    public ArrayList<ISubWallet> GetAllSubWallets() {
        long[] subWalletProxies = nativeGetAllSubWallets(mMasterProxy);
        ArrayList<ISubWallet> list = new ArrayList<ISubWallet>();
        for (int i = 0; i < subWalletProxies.length; i++) {
            list.add(new ISubWallet(subWalletProxies[i]));
        }
        return list;
    }

    public ISubWallet CreateSubWallet(String chainID, String payPassword, boolean singleAddress, long feePerKb) throws WalletException {
        if ((!CHAINID.MAIN.equals(chainID)) && (!CHAINID.ID.equals(chainID))) {
            throw new WalletException("Not support the other sidechain now.");
        }

        long subProxy = nativeCreateSubWallet(mMasterProxy, chainID, payPassword, singleAddress, feePerKb);
        if (CHAINID.MAIN.equals(chainID)) {
            return new IMainchainSubWallet(subProxy);
        }
        else if (CHAINID.ID.equals(chainID)) {
            return new IIdChainSubWallet(subProxy);
        }

        throw new WalletException("Not support the other sidechain now..");
        // return new ISubWallet(subProxy);
    }

    public ISubWallet RecoverSubWallet(String chainID, String payPassword, boolean singleAddress, int limitGap, long feePerKb) throws WalletException {
        long subProxy = nativeRecoverSubWallet(mMasterProxy, chainID, payPassword, singleAddress, limitGap, feePerKb);
        return new ISubWallet(subProxy);
    }

    public void DestroyWallet(ISubWallet wallet)
    {
        nativeDestroyWallet(mMasterProxy, wallet.getProxy());
    }

    public String GetPublicKey()
    {
        return nativeGetPublicKey(mMasterProxy);
    }

    public String Sign(String message, String payPassword) throws WalletException {
        return nativeSign(mMasterProxy, message, payPassword);
    }

    public String CheckSign(String publicKey, String message, String signature) throws WalletException {
        return nativeCheckSign(mMasterProxy, publicKey, message, signature);
    }

    public IMasterWallet(long proxy) {
        mMasterProxy = proxy;
    }

    public boolean IsAddressValid(String address) {
        return nativeIsAddressValid(mMasterProxy, address);
    }

    public String[] GetSupportedChains() {
        return nativeGetSupportedChains(mMasterProxy);
    }

    public long GetProxy() {
        return mMasterProxy;
    }

    public void ChangePassword(String oldPassword, String newPassword) throws WalletException {
        nativeChangePassword(mMasterProxy, oldPassword, newPassword);
    }

    public void ResetAddressCache(String payPassword) {
        nativeResetAddressCache(mMasterProxy, payPassword);
    }

    private native String nativeGetId(long masterProxy);
    private native long[] nativeGetAllSubWallets(long masterProxy);
    private native long nativeCreateSubWallet(long masterProxy, String chainID, String payPassword, boolean singleAddress, long feePerKb);
    private native long nativeRecoverSubWallet(long masterProxy, String chainID, String payPassword, boolean singleAddress, int limitGap, long feePerKb);
    private native String nativeGetPublicKey(long masterProxy);
    private native void nativeDestroyWallet(long masterProxy, long subWalletProxy);
    private native String nativeSign(long masterProxy, String message, String payPassword);
    private native String nativeCheckSign(long masterProxy, String publicKey, String message, String signature);
    private native boolean nativeIsAddressValid(long masterProxy, String address);
    private native String[] nativeGetSupportedChains(long masterProxy);
    private native void nativeChangePassword(long proxy, String oldPassword, String newPassword);
    private native void nativeResetAddressCache(long proxy, String payPassword);
}
