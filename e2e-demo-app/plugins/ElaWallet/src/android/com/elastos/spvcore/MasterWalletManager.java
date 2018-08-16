
package com.elastos.spvcore;

import java.util.ArrayList;
import android.util.Log;

/**
 * MasterWalletManager jni
 */
public class MasterWalletManager {
    private long mManagerProxy = 0;
    private String mRootPath = null;


    /***
     * 创建主私钥
     * @param masterWalletId
     * @param language
     */
    public IMasterWallet CreateMasterWallet(String masterWalletId, String mnemonic, String phrasePassword, String payPassword
            , String language) throws WalletException
    {
        long masterProxy = nativeCreateMasterWallet(mManagerProxy, masterWalletId, mnemonic, phrasePassword, payPassword, language);
        return new IMasterWallet(masterProxy);
    }

    public ArrayList<IMasterWallet> GetAllMasterWallets() throws WalletException {
        long[] masterWalletProxies = nativeGetAllMasterWallets(mManagerProxy);
        if (masterWalletProxies != null) {
            ArrayList<IMasterWallet> list = new ArrayList<IMasterWallet>();
            for (int i = 0; i < masterWalletProxies.length; i++) {
                list.add(new IMasterWallet(masterWalletProxies[i]));
            }
            return list;
        }
        return null;
    }

    public void DestroyWallet(String masterWalletId) throws WalletException {
        nativeDestroyWallet(mManagerProxy, masterWalletId);
    }

    /***
     * 导入私钥
     * @param keystoreContent      文件路径
     * @param backupPassWord    备份密码
     * @param payPassWord       支付密码
     * @return
     */
    public IMasterWallet ImportWalletWithKeystore(String masterWalletId, String keystoreContent,String backupPassWord
                    ,String payPassWord, String phrasePassword) throws WalletException {
        long masterProxy = nativeImportWalletWithKeystore(mManagerProxy, masterWalletId, keystoreContent, backupPassWord, payPassWord, phrasePassword);
        return new IMasterWallet(masterProxy);
    }

    /***
     * 导入助记词
     * @param masterWalletId
     * @param mnemonic
     * @param phrasePassword
     * @param payPassWord
     * @return
     */
    public IMasterWallet ImportWalletWithMnemonic(String masterWalletId, String mnemonic, String phrasePassword
                    ,String payPassWord, String language) throws WalletException {
        long masterProxy = nativeImportWalletWithMnemonic(mManagerProxy, masterWalletId, mnemonic, phrasePassword, payPassWord, language);
        return new IMasterWallet(masterProxy);
    }

    /***
     * 导出私钥
     * @param masterWallet
     * @param backupPassWord
     * @param keystorePath
     */
    public String ExportWalletWithKeystore(IMasterWallet masterWallet, String backupPassWord, String payPassword) throws WalletException {
        return nativeExportWalletWithKeystore(mManagerProxy, masterWallet, backupPassWord, payPassword);
    }

    /***
     * 导出助记词
     * @param masterWallet
     * @param backupPassWord
     * @return
     */
    public String ExportWalletWithMnemonic(IMasterWallet masterWallet,String backupPassWord) throws WalletException {
        return nativeExportWalletWithMnemonic(mManagerProxy, masterWallet, backupPassWord);
    }

    public MasterWalletManager(String rootPath) {
        mRootPath = rootPath;
        mManagerProxy = nativeInitMasterWalletManager(mRootPath);
    }

    public String GenerateMnemonic(String language) throws WalletException {
        return nativeGenerateMnemonic(mManagerProxy, language);
    }

    public void finalize() {
        nativeDisposeNative(mManagerProxy);
    }

    public void SaveConfigs() {
        nativeSaveConfigs(mManagerProxy);
    }

    private native long nativeInitMasterWalletManager(String rootPath);

    private native long nativeCreateMasterWallet(long proxy, String masterWalletId, String mnemonic, String phrasePassword
                    , String payPassword, String language);

    private native long nativeImportWalletWithKeystore(long proxy, String masterWalletId,
                    String keystoreContent,String backupPassWord ,String payPassWord, String phrasePassword);

    private native long nativeImportWalletWithMnemonic(long proxy, String masterWalletId, String mnemonic,
                    String phrasePassword,String payPassWord,String language);

    private native String nativeExportWalletWithKeystore(long proxy, IMasterWallet masterWallet,
                    String backupPassWord,String payPassword);

    private native String nativeExportWalletWithMnemonic(long proxy, IMasterWallet masterWallet,String backupPassWord);
    private native void nativeDestroyWallet(long proxy, String masterWalletId);
    private native void nativeDisposeNative(long proxy);
    private native long[] nativeGetAllMasterWallets(long proxy);
    private native String nativeGenerateMnemonic(long proxy, String language);
    private native void nativeSaveConfigs(long proxy);
}
