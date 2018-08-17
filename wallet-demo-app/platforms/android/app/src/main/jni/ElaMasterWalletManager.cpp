// Copyright (c) 2012-2018 The Elastos Open Source Project
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "ElaUtils.h"
#include "Elastos.Wallet.h"

#define  CLASS_MASTERWALLET   "com/elastos/spvcore/IMasterWallet"
#define  FIELD_MASTERWALLET   "mMasterProxy"

static jlong JNICALL nativeInitMasterWalletManager(JNIEnv *env, jobject clazz, jstring jrootPath)
{
    const char* rootPath = env->GetStringUTFChars(jrootPath, NULL);

    IMasterWalletManager* walletManager;
    CMasterWalletManager::New(String(rootPath), &walletManager);
    walletManager->AddRef();

    env->ReleaseStringUTFChars(jrootPath, rootPath);
    return (jlong)walletManager;
}

static void JNICALL nativeDisposeNative(JNIEnv *env, jobject clazz, jlong jWalletMgr)
{
    IMasterWalletManager* walletManager = (IMasterWalletManager*)jWalletMgr;
    walletManager->Release();
}

//"(JLjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)J"
static jlong JNICALL nativeCreateMasterWallet(JNIEnv *env, jobject clazz, jlong jWalletMgr, jstring jmasterWalletId
    , jstring jmnemonic, jstring jphrasePassword, jstring jpayPassword, jstring jlanguage)
{
    const char* masterWalletId = env->GetStringUTFChars(jmasterWalletId, NULL);
    const char* mnemonic = env->GetStringUTFChars(jmnemonic, NULL);
    const char* phrasePassword = env->GetStringUTFChars(jphrasePassword, NULL);
    const char* payPassword = env->GetStringUTFChars(jpayPassword, NULL);
    const char* language = env->GetStringUTFChars(jlanguage, NULL);

    IMasterWalletManager* walletManager = (IMasterWalletManager*)jWalletMgr;
    IMasterWallet* masterWallet;

    try {
        walletManager->CreateMasterWallet(String(masterWalletId), String(mnemonic), String(phrasePassword), String(payPassword)
                , String(language), &masterWallet);
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

    env->ReleaseStringUTFChars(jmasterWalletId, masterWalletId);
    env->ReleaseStringUTFChars(jmnemonic, mnemonic);
    env->ReleaseStringUTFChars(jphrasePassword, phrasePassword);
    env->ReleaseStringUTFChars(jpayPassword, payPassword);
    env->ReleaseStringUTFChars(jlanguage, language);
    return (jlong)masterWallet;
}

static void JNICALL nativeDestroyWallet(JNIEnv *env, jobject clazz, jlong jWalletMgr, jstring jmasterWalletId)
{
    const char* masterWalletId = env->GetStringUTFChars(jmasterWalletId, NULL);

    IMasterWalletManager* walletManager = (IMasterWalletManager*)jWalletMgr;
    LOGD("FUNC=[%s]===================LINE=[%d], masterWalletId=[%s], walletManager=[%p]", __FUNCTION__, __LINE__, masterWalletId, walletManager);

    try {
        walletManager->DestroyWallet(String(masterWalletId));
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

    LOGD("FUNC=[%s]===================LINE=[%d]", __FUNCTION__, __LINE__);

    env->ReleaseStringUTFChars(jmasterWalletId, masterWalletId);
}

static jlong JNICALL nativeImportWalletWithKeystore(JNIEnv *env, jobject clazz, jlong jWalletMgr, jstring jmasterWalletId, jstring jkeystoreContent,
        jstring jbackupPassword, jstring jpayPassword, jstring jphrasePassword)
{
    const char* masterWalletId = env->GetStringUTFChars(jmasterWalletId, NULL);
    const char* keystoreContent = env->GetStringUTFChars(jkeystoreContent, NULL);
    const char* backupPassword = env->GetStringUTFChars(jbackupPassword, NULL);
    const char* payPassword = env->GetStringUTFChars(jpayPassword, NULL);
    const char* phrasePassword = env->GetStringUTFChars(jphrasePassword, NULL);

    IMasterWalletManager* walletManager = (IMasterWalletManager*)jWalletMgr;
    IMasterWallet* masterWallet = NULL;

    try {
        walletManager->ImportWalletWithKeystore(String(masterWalletId), String(keystoreContent), String(backupPassword)
                , String(payPassword), String(phrasePassword), &masterWallet);
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

    env->ReleaseStringUTFChars(jmasterWalletId, masterWalletId);
    env->ReleaseStringUTFChars(jkeystoreContent, keystoreContent);
    env->ReleaseStringUTFChars(jbackupPassword, backupPassword);
    env->ReleaseStringUTFChars(jpayPassword, payPassword);
    env->ReleaseStringUTFChars(jphrasePassword, phrasePassword);
    return (jlong)masterWallet;
}

static jlong JNICALL nativeImportWalletWithMnemonic(JNIEnv *env, jobject clazz, jlong jWalletMgr, jstring jmasterWalletId,
        jstring jmnemonic, jstring jphrasePassword, jstring jpayPassword, jstring jlanguage)
{
    const char* masterWalletId = env->GetStringUTFChars(jmasterWalletId, NULL);
    const char* mnemonic = env->GetStringUTFChars(jmnemonic, NULL);
    const char* phrasePassword = env->GetStringUTFChars(jphrasePassword, NULL);
    const char* payPassword = env->GetStringUTFChars(jpayPassword, NULL);
    const char* language = env->GetStringUTFChars(jlanguage, NULL);

    IMasterWalletManager* walletManager = (IMasterWalletManager*)jWalletMgr;
    IMasterWallet* masterWallet = NULL;

    try {
        walletManager->ImportWalletWithMnemonic(String(masterWalletId), String(mnemonic), String(phrasePassword)
                    , String(payPassword), String(language), &masterWallet);
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

    env->ReleaseStringUTFChars(jmasterWalletId, masterWalletId);
    env->ReleaseStringUTFChars(jmnemonic, mnemonic);
    env->ReleaseStringUTFChars(jphrasePassword, phrasePassword);
    env->ReleaseStringUTFChars(jpayPassword, payPassword);
    env->ReleaseStringUTFChars(jlanguage, language);
    return (jlong)masterWallet;
}

static jstring JNICALL nativeExportWalletWithKeystore(JNIEnv *env, jobject clazz, jlong jWalletMgr, jobject jmasterWallet,
        jstring jbackupPassword, jstring jpayPassword)
{
    const char* backupPassword = env->GetStringUTFChars(jbackupPassword, NULL);
    const char* payPassword = env->GetStringUTFChars(jpayPassword, NULL);

    jclass cls = env->FindClass(CLASS_MASTERWALLET);
    long masterProxy = GetJavaLongField(env, cls, jmasterWallet, FIELD_MASTERWALLET);
    CheckErrorAndLog(env, "nativeExportWalletWithKeystore", __LINE__);
    IMasterWallet* masterWallet = (IMasterWallet*)masterProxy;
    IMasterWalletManager* walletManager = (IMasterWalletManager*)jWalletMgr;
    String result;

    try {
        walletManager->ExportWalletWithKeystore(masterWallet, String(backupPassword), String(payPassword), &result);
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

    env->ReleaseStringUTFChars(jbackupPassword, backupPassword);
    env->ReleaseStringUTFChars(jpayPassword, payPassword);
    return env->NewStringUTF(result.string());
}

static jstring JNICALL nativeExportWalletWithMnemonic(JNIEnv *env, jobject clazz, jlong jWalletMgr,
        jobject jmasterWallet, jstring jpayPassword)
{
    jclass cls = env->FindClass(CLASS_MASTERWALLET);
    long masterProxy = GetJavaLongField(env, cls, jmasterWallet, FIELD_MASTERWALLET);
    CheckErrorAndLog(env, "nativeExportWalletWithMnemonic", __LINE__);
    IMasterWallet* masterWallet = (IMasterWallet*)masterProxy;

    const char* payPassword = env->GetStringUTFChars(jpayPassword, NULL);

    IMasterWalletManager* walletManager = (IMasterWalletManager*)jWalletMgr;
    String result;

    try {
        walletManager->ExportWalletWithMnemonic(masterWallet, String(payPassword), &result);
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

    env->ReleaseStringUTFChars(jpayPassword, payPassword);
    return env->NewStringUTF(result.string());
}

//"(J)[J"
static jlongArray JNICALL nativeGetAllMasterWallets(JNIEnv *env, jobject clazz, jlong jWalletMgr)
{
    IMasterWalletManager* walletManager = (IMasterWalletManager*)jWalletMgr;
    LOGD("FUNC=[%s]===================LINE=[%d]", __FUNCTION__, __LINE__);
    AutoPtr<ArrayOf<IMasterWallet*> > array;

    try {
        walletManager->GetAllMasterWallets((ArrayOf<IMasterWallet*>**)&array);
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

    if (array != NULL) {
        const int length = array->GetLength();
        if (length > 0) {
            jlong* proxies = new jlong[length];
            for (int i = 0; i < length; ++i) {
                IMasterWallet* masterWallet = (*array)[i];
                proxies[i] = (jlong)masterWallet;
            }
            jlongArray jarray = env->NewLongArray(length);
            env->SetLongArrayRegion(jarray, 0, length, proxies);
            delete[] proxies;
            return jarray;
        }
    }

    return NULL;
}

//"(JLjava/lang/String;)Ljava/lang/String;"
static jstring JNICALL nativeGenerateMnemonic(JNIEnv *env, jobject clazz, jlong jWalletMgr, jstring jlanguage)
{
    IMasterWalletManager* walletManager = (IMasterWalletManager*)jWalletMgr;
    const char* language = env->GetStringUTFChars(jlanguage, NULL);
    String mnemonic;

    try {
        walletManager->GenerateMnemonic(String(language), &mnemonic);
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

    env->ReleaseStringUTFChars(jlanguage, language);
    return env->NewStringUTF(mnemonic.string());
}

//"()V"
static void JNICALL nativeSaveConfigs(JNIEnv *env, jobject clazz, jlong jWalletMgr)
{
    IMasterWalletManager* walletManager = (IMasterWalletManager*)jWalletMgr;
    walletManager->SaveConfigs();
}


static const JNINativeMethod gMethods[] = {
    {"nativeInitMasterWalletManager", "(Ljava/lang/String;)J", (void*)nativeInitMasterWalletManager},
    {"nativeCreateMasterWallet", "(JLjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)J"
            , (void*)nativeCreateMasterWallet},
    {"nativeDisposeNative", "(J)V", (void*)nativeDisposeNative},
    {"nativeDestroyWallet", "(JLjava/lang/String;)V", (void*)nativeDestroyWallet},
    {"nativeImportWalletWithKeystore", "(JLjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)J", (void*)nativeImportWalletWithKeystore},
    {"nativeImportWalletWithMnemonic", "(JLjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)J", (void*)nativeImportWalletWithMnemonic},
    {"nativeExportWalletWithKeystore", "(JLcom/elastos/spvcore/IMasterWallet;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", (void*)nativeExportWalletWithKeystore},
    {"nativeExportWalletWithMnemonic", "(JLcom/elastos/spvcore/IMasterWallet;Ljava/lang/String;)Ljava/lang/String;", (void*)nativeExportWalletWithMnemonic},
    {"nativeGetAllMasterWallets", "(J)[J", (void*)nativeGetAllMasterWallets},
    {"nativeGenerateMnemonic", "(JLjava/lang/String;)Ljava/lang/String;", (void*)nativeGenerateMnemonic},
    {"nativeSaveConfigs", "(J)V", (void*)nativeSaveConfigs},
};

int register_elastos_spv_IMasterWalletManager(JNIEnv *env)
{
    return jniRegisterNativeMethods(env, "com/elastos/spvcore/MasterWalletManager",
        gMethods, NELEM(gMethods));
}
