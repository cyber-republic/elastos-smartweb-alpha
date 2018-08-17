// Copyright (c) 2012-2018 The Elastos Open Source Project
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


#include "ElaUtils.h"

const char* WALLETEXCEPTION = "com/elastos/spvcore/WalletException";
void ThrowLogicException(JNIEnv* env, const char* errorInfo)
{
    jclass walletException = env->FindClass(WALLETEXCEPTION);
    env->ExceptionClear();
    env->ThrowNew(walletException, errorInfo);
}

void ThrowWalletExceptionWithECode(JNIEnv* env, int errorcode, const char* errorInfo)
{
    jclass walletException = env->FindClass(WALLETEXCEPTION);
    jmethodID methodId = env->GetMethodID(walletException, "<init>", "(ILjava/lang/String;)V");
    jstring arg = env->NewStringUTF(errorInfo);
    jthrowable throwable = (jthrowable) env->NewObject(walletException, methodId, errorcode, arg);
    env->ExceptionClear();
    env->Throw(throwable);
}

void ThrowWalletException(JNIEnv* env, const char* errorInfo)
{
    env->ExceptionClear();
    jclass walletException = env->FindClass(WALLETEXCEPTION);
    jmethodID methodId = env->GetMethodID(walletException, "<init>", "(Ljava/lang/String;)V");
    jstring arg = env->NewStringUTF(errorInfo);
    jthrowable throwable = (jthrowable) env->NewObject(walletException, methodId, arg);
    env->Throw(throwable);
}

int UTF82UnicodeOne(const char* utf8, wchar_t& wch)
{
    unsigned char firstCh = utf8[0];
    if (firstCh >= 0xC0)
    {
        int afters, code;
        if ((firstCh & 0xE0) == 0xC0)
        {
            afters = 2;
            code = firstCh & 0x1F;
        }
        else if ((firstCh & 0xF0) == 0xE0)
        {
            afters = 3;
            code = firstCh & 0xF;
        }
        else if ((firstCh & 0xF8) == 0xF0)
        {
            afters = 4;
            code = firstCh & 0x7;
        }
        else if ((firstCh & 0xFC) == 0xF8)
        {
            afters = 5;
            code = firstCh & 0x3;
        }
        else if ((firstCh & 0xFE) == 0xFC)
        {
            afters = 6;
            code = firstCh & 0x1;
        }
        else
        {
            wch = firstCh;
            return 1;
        }

        for(int k = 1; k < afters; ++ k)
        {
            if ((utf8[k] & 0xC0) != 0x80)
            {
                wch = firstCh;
                return 1;
            }

            code <<= 6;
            code |= (unsigned char)utf8[k] & 0x3F;
        }

        wch = code;
        return afters;
    }
    else
    {
        wch = firstCh;
    }

    return 1;
}

int UTF82Unicode(const char* utf8Buf, wchar_t *pUniBuf, int utf8Leng)
{
    int i = 0, count = 0;
    while(i < utf8Leng)
    {
        i += UTF82UnicodeOne(utf8Buf + i, pUniBuf[count]);
        count ++;
    }

    return count;
}

jstring stringTojstring(JNIEnv* env, std::string str)
{
    int len = str.length();
    wchar_t *wcs = new wchar_t[len * 2];
    int nRet = UTF82Unicode(str.c_str(), wcs, len);
    jchar* jcs = new jchar[nRet];
    for (int i = 0; i < nRet; i++)
    {
        jcs[i] = (jchar) wcs[i];
    }

    jstring retString = env->NewString(jcs, nRet);
    delete[] wcs;
    delete[] jcs;
    return retString;
}
