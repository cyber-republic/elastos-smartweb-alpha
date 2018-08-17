// Copyright (c) 2012-2018 The Elastos Open Source Project
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "ElaUtils.h"
#include "Elastos.Wallet.h"

//"(JLjava/lang/String;Ljava/lang/String;JLjava/lang/String;Ljava/lang/String;JLjava/lang/String;)Ljava/lang/String;"
static jstring JNICALL nativeCreateIdTransaction(JNIEnv *env, jobject clazz, jlong jIdSubWalletProxy, jstring jfromAddress,
        jstring jpayloadJson, jstring jprogramJson, jstring jmemo, jstring jremark)
{
    const char* fromAddress = env->GetStringUTFChars(jfromAddress, NULL);
    const char* payloadJson = env->GetStringUTFChars(jpayloadJson, NULL);
    const char* programJson = env->GetStringUTFChars(jprogramJson, NULL);
    const char* memo = env->GetStringUTFChars(jmemo, NULL);
    const char* remark = env->GetStringUTFChars(jremark, NULL);

    LOGD("FUNC=[%s]=========================line=[%d], fromAddress=[%s]", __FUNCTION__, __LINE__, fromAddress);
    LOGD("FUNC=[%s]=========================line=[%d], programJson=[%s]", __FUNCTION__, __LINE__, payloadJson);
    LOGD("FUNC=[%s]=========================line=[%d], programJson=[%s]", __FUNCTION__, __LINE__, programJson);
    LOGD("FUNC=[%s]=========================line=[%d], memo=[%s]", __FUNCTION__, __LINE__, memo);
    LOGD("FUNC=[%s]=========================line=[%d], remark=[%s]", __FUNCTION__, __LINE__, remark);

    IIdChainSubWallet* wallet = IIdChainSubWallet::Probe((ISubWallet*)jIdSubWalletProxy);
    String txidJson;

    try {
        wallet->CreateIdTransaction(String(fromAddress), String(payloadJson), String(programJson), String(memo), String(remark), &txidJson);
        return stringTojstring(env, txidJson.string());
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
    env->ReleaseStringUTFChars(jpayloadJson, payloadJson);
    env->ReleaseStringUTFChars(jprogramJson, programJson);
    env->ReleaseStringUTFChars(jmemo, memo);
    env->ReleaseStringUTFChars(jremark, remark);

    LOGD("FUNC=[%s]===================LINE=[%d], keys=[%s]", __FUNCTION__, __LINE__, txidJson.string());
    return NULL;
}


static const JNINativeMethod gMethods[] = {
    {"nativeCreateIdTransaction",
    "(JLjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;",
    (void*)nativeCreateIdTransaction},
};

jint register_elastos_spv_IIdChainSubWallet(JNIEnv *env)
{
    return jniRegisterNativeMethods(env, "com/elastos/spvcore/IIdChainSubWallet",
        gMethods, NELEM(gMethods));
}
