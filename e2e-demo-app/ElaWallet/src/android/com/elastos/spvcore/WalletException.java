
package com.elastos.spvcore;

public class WalletException extends RuntimeException {
    private int mErrorCode = 0;
    private String mErrorInfo = null;

    public WalletException(){
        super();
    }

    public WalletException(String message){
        super(message);
        mErrorInfo = message;
    }

    public WalletException(int errorCode, String message){
        super(message);
        mErrorCode = errorCode;
        mErrorInfo = message;
    }

    public int GetErrorCode() {
        return mErrorCode;
    }

    public String GetErrorInfo() {
        return mErrorInfo;
    }
}
