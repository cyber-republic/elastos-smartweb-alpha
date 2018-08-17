// Copyright (c) 2012-2018 The Elastos Open Source Project
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "ElaUtils.h"
#include "Elastos.Wallet.h"

//"(JLjava/lang/String;Ljava/lang/String;JLjava/lang/String;Ljava/lang/String;Ljava/lang/String;JLjava/lang/String;)Ljava/lang/String;"
static jstring JNICALL nativeCreateDepositTransaction(JNIEnv *env, jobject clazz, jlong jMainSubWalletProxy,
        jstring jfromAddress, jstring jtoAddress, jlong amount, jstring jsidechainAccounts, jstring jsidechainAmounts
        , jstring jsidechainIndexs, jstring jmemo, jstring jremark)
{
    const char* fromAddress = env->GetStringUTFChars(jfromAddress, NULL);
    const char* toAddress = env->GetStringUTFChars(jtoAddress, NULL);
    const char* sidechainAccounts = env->GetStringUTFChars(jsidechainAccounts, NULL);
    const char* sidechainAmounts = env->GetStringUTFChars(jsidechainAmounts, NULL);
    const char* sidechainIndexs = env->GetStringUTFChars(jsidechainIndexs, NULL);
    const char* memo = env->GetStringUTFChars(jmemo, NULL);
    const char* remark = env->GetStringUTFChars(jremark, NULL);

    IMainchainSubWallet* wallet = IMainchainSubWallet::Probe((ISubWallet*)jMainSubWalletProxy);
    String txidJson;

    LOGD("FUNC=[%s]=========================line=[%d], fromAddress=[%s]", __FUNCTION__, __LINE__, fromAddress);
    LOGD("FUNC=[%s]=========================line=[%d], toAddress=[%s]", __FUNCTION__, __LINE__, toAddress);
    LOGD("FUNC=[%s]=========================line=[%d], sidechainAccounts=[%s]", __FUNCTION__, __LINE__, sidechainAccounts);
    LOGD("FUNC=[%s]=========================line=[%d], sidechainAmounts=[%s]", __FUNCTION__, __LINE__, sidechainAmounts);
    LOGD("FUNC=[%s]=========================line=[%d], sidechainIndexs=[%s]", __FUNCTION__, __LINE__, sidechainIndexs);

    try {
        wallet->CreateDepositTransaction(String(fromAddress), String(toAddress), amount , String(sidechainAccounts)
            , String(sidechainAmounts), String(sidechainIndexs), String(memo), String(remark), &txidJson);
        return env->NewStringUTF(txidJson.string());
    }
    catch (std::invalid_argument& e) {
        ThrowWalletException(env, e.what());
    }
    catch (std::logic_error& e) {
        ThrowWalletException(env, e.what());
    }
    catch (std::runtime_error& e) {
        ThrowWalletException(env, e.what());
    }
    catch (std::exception& e) {
        ThrowWalletException(env, e.what());
    }

    env->ReleaseStringUTFChars(jfromAddress, fromAddress);
    env->ReleaseStringUTFChars(jtoAddress, toAddress);
    env->ReleaseStringUTFChars(jsidechainAccounts, sidechainAccounts);
    env->ReleaseStringUTFChars(jsidechainAmounts, sidechainAmounts);
    env->ReleaseStringUTFChars(jsidechainIndexs, sidechainIndexs);
    env->ReleaseStringUTFChars(jmemo, memo);
    env->ReleaseStringUTFChars(jremark, remark);
    return NULL;
}

static const JNINativeMethod gMethods[] = {
    {"nativeCreateDepositTransaction",
    "(JLjava/lang/String;Ljava/lang/String;JLjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;"
            , (void*)nativeCreateDepositTransaction},
};

jint register_elastos_spv_IMainchainSubWallet(JNIEnv *env)
{
    return jniRegisterNativeMethods(env, "com/elastos/spvcore/IMainchainSubWallet",
        gMethods, NELEM(gMethods));
}
