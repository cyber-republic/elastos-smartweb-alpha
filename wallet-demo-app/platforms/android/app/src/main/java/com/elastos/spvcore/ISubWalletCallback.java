
package com.elastos.spvcore;


public interface ISubWalletCallback {
    /**
     * Callback method fired when status of a transaction changed.
     * @param txid indicate hash of the transaction.
     * @param status can be "Added", "Deleted" or "Updated".
     * @param desc is an detail description of transaction status.
     * @param confirms is confirm count util this callback fired.
     */
    public void OnTransactionStatusChanged(String txId, String status, String desc,int confirms);

    /**
     * Callback method fired when block begin synchronizing with a peer. This callback could be used to show progress.
     */
    public void OnBlockSyncStarted();

    /**
     * Callback method fired when best block chain height increased. This callback could be used to show progress.
     * @param currentBlockHeight is the of current block when callback fired.
     * @param progress is current progress when block height increased.
     */
    public void OnBlockHeightIncreased(int currentBlockHeight, double progress);

    /**
     * Callback method fired when block end synchronizing with a peer. This callback could be used to show progress.
     */
    public void OnBlockSyncStopped();
}
