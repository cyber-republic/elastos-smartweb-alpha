// Copyright (c) 2012-2018 The Elastos Open Source Project
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "ElaUtils.h"
#include <unistd.h>

extern int register_elastos_spv_IMasterWalletManager(JNIEnv* env);
extern int register_elastos_spv_IMasterWallet(JNIEnv* env);
extern int register_elastos_spv_ISubWallet(JNIEnv* env);
extern int register_elastos_spv_IMainchainSubWallet(JNIEnv* env);
extern int register_elastos_spv_ISidechainSubWallet(JNIEnv* env);
extern int register_elastos_spv_IIdChainSubWallet(JNIEnv* env);

//did
extern int register_elastos_spv_IDid(JNIEnv* env);
extern int register_elastos_spv_IDidManager(JNIEnv* env);
extern int register_elastos_spv_IdManagerFactory(JNIEnv* env);

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved){
    JNIEnv * env;
    jclass cls;
    jint result = -1;
    if(vm->GetEnv((void **)&env,JNI_VERSION_1_6) != JNI_OK){
        return JNI_ERR;
    }

    register_elastos_spv_IMasterWalletManager(env);
    register_elastos_spv_IMasterWallet(env);
    register_elastos_spv_ISubWallet(env);
    register_elastos_spv_IMainchainSubWallet(env);
    register_elastos_spv_ISidechainSubWallet(env);
    register_elastos_spv_IIdChainSubWallet(env);

    //did
    register_elastos_spv_IDid(env);
    register_elastos_spv_IDidManager(env);
    register_elastos_spv_IdManagerFactory(env);

    return JNI_VERSION_1_6;
}

int jniRegisterNativeMethods(JNIEnv* env, const char* className,
    const JNINativeMethod* gMethods, int numMethods)
{
    LOGW("Registering %s's %d native methods...", className, numMethods);

    jclass cls = env->FindClass(className);
    env->RegisterNatives(cls, gMethods, numMethods);

    return 0;
}

void CheckErrorAndLog(
    /* [in] */ JNIEnv* env,
    /* [in] */ const char* errlog,
    /* [in] */ int line)
{
    if (env->ExceptionCheck() != 0) {
        LOGW(errlog, line);
        env->ExceptionDescribe();
        env->ExceptionClear();
    }
}

void CheckErrorAndLog(
    /* [in] */ JNIEnv* env,
    /* [in] */ const char* errlog,
    /* [in] */ const char* paramname,
    /* [in] */ int line)
{
    if (env->ExceptionCheck() != 0) {
        LOGW(errlog, paramname, line);
        env->ExceptionDescribe();
        env->ExceptionClear();
    }
}

jlong GetJavaLongField(JNIEnv* env, jclass klass, jobject jobj, const char* fieldName)
{
    if (env == NULL || jobj == NULL || fieldName == NULL) {
        LOGW("GetJavaLongField() invalid param while get field:%s  : %d!\n", fieldName, __LINE__);
        return 0;
    }

    jfieldID field = env->GetFieldID(klass, fieldName, "J");
    CheckErrorAndLog(env, "Fail get long field id:%s  : %d!\n", fieldName, __LINE__);
    jlong value = env->GetLongField(jobj, field);
    CheckErrorAndLog(env, "Fail get long field: %s : %d!\n", fieldName, __LINE__);
    return value;
}
