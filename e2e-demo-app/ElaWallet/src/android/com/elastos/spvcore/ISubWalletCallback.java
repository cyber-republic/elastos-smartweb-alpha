
package com.elastos.spvcore;


public interface ISubWalletCallback {
    //public void OnBalanceChanged(String address,double oldAmount,double newAmount);
    public void OnTransactionStatusChanged(String txId, String status, String desc,int confirms);
}
