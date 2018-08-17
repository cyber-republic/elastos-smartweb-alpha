// Copyright (c) 2012-2018 The Elastos Open Source Project
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "ElaUtils.h"
#include "Elastos.DID.h"

//"(J)J"
static jlong JNICALL nativeCreateIdManager(JNIEnv *env, jobject clazz, jlong jmasterWalletProxy, jstring jrootPath)
{
    const char* rootPath = env->GetStringUTFChars(jrootPath, NULL);
    IMasterWallet* masterWallet = (IMasterWallet*)jmasterWalletProxy;
    AutoPtr<IDIDManager> idManager;
    CDIDManager::New(masterWallet, String(rootPath), (IDIDManager**)&idManager);
    idManager->AddRef();

    env->ReleaseStringUTFChars(jrootPath, rootPath);
    return (jlong)idManager.Get();
}

//"(J)V"
static void JNICALL nativeDestroy(JNIEnv *env, jobject clazz, jlong jdidManagerProxy)
{
    IDIDManager* idManager = (IDIDManager*)jdidManagerProxy;
    if (idManager) {
        idManager->Release();
    }
}

static const JNINativeMethod gMethods[] = {
    {"nativeCreateIdManager", "(JLjava/lang/String;)J", (void*)nativeCreateIdManager},
    {"nativeDestroy", "(J)V", (void*)nativeDestroy},
};

jint register_elastos_spv_IdManagerFactory(JNIEnv *env)
{
    return jniRegisterNativeMethods(env, "com/elastos/spvcore/IdManagerFactory",
        gMethods, NELEM(gMethods));
}
