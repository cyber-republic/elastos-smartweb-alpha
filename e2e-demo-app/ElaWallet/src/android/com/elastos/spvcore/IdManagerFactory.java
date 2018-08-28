
package com.elastos.spvcore;


public class IdManagerFactory {
    public static IDidManager CreateIdManager(IMasterWallet masterWallet, String rootPath) {
        long didManagerProxy = nativeCreateIdManager(masterWallet.GetProxy(), rootPath);
        return new IDidManager(didManagerProxy);
    }

    private static native long nativeCreateIdManager(long masterWalletProxy, String rootPath);
}
