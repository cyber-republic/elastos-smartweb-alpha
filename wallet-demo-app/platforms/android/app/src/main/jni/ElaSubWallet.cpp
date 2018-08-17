// Copyright (c) 2012-2018 The Elastos Open Source Project
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "ElaUtils.h"
#include "Elastos.Wallet.h"
#include "elastos/core/Object.h"
#include <map>

#define  CLASS_SUBWALLET   "com/elastos/spvcore/ISubWallet"
#define  FIELD_SUBWALLET   "mSubProxy"

static jstring JNICALL nativeGetChainId(JNIEnv *env, jobject clazz, jlong jSubProxy)
{
    ISubWallet* subWallet = (ISubWallet*)jSubProxy;
    String result;
    subWallet->GetChainId(&result);
    return env->NewStringUTF(result.string());
}

static jstring JNICALL nativeGetBalanceInfo(JNIEnv *env, jobject clazz, jlong jSubProxy)
{
    ISubWallet* subWallet = (ISubWallet*)jSubProxy;
    String result;
    subWallet->GetBalanceInfo(&result);
    return env->NewStringUTF(result.string());
}

static jlong JNICALL nativeGetBalance(JNIEnv *env, jobject clazz, jlong jSubProxy)
{
    ISubWallet* subWallet = (ISubWallet*)jSubProxy;
    Int64 balance = 0;
    subWallet->GetBalance(&balance);
    return (jlong)balance;
}

static jstring JNICALL nativeCreateAddress(JNIEnv *env, jobject clazz, jlong jSubProxy)
{
    ISubWallet* subWallet = (ISubWallet*)jSubProxy;
    String result;
    subWallet->CreateAddress(&result);
    return env->NewStringUTF(result.string());
}

static jstring JNICALL nativeGetAllAddress(JNIEnv *env, jobject clazz, jlong jSubProxy, jint jStart, jint jCount)
{
    ISubWallet* subWallet = (ISubWallet*)jSubProxy;
    String addresses;
    subWallet->GetAllAddress(jStart, jCount, &addresses);
    return env->NewStringUTF(addresses.string());
}

static jlong JNICALL nativeGetBalanceWithAddress(JNIEnv *env, jobject clazz, jlong jSubProxy, jstring jaddress)
{
    const char* address = env->GetStringUTFChars(jaddress, NULL);

    ISubWallet* subWallet = (ISubWallet*)jSubProxy;
    Int64 result = 0;
    subWallet->GetBalanceWithAddress(String(address), &result);

    env->ReleaseStringUTFChars(jaddress, address);
    return (jlong)result;
}

class ElaSubWalletListener
    : public Object
    , public ISubWalletListener
{
public:
    CAR_INTERFACE_DECL();

    ElaSubWalletListener(
        /* [in] */ JNIEnv* env,
        /* [in] */ jobject jobj);

    ~ElaSubWalletListener();

    /**
     * Callback method fired when status of a transaction changed.
     * @param txid indicate hash of the transaction.
     * @param status can be "Added", "Deleted" or "Updated".
     * @param desc is an detail description of transaction status.
     * @param confirms is confirm count util this callback fired.
     */
    CARAPI OnTransactionStatusChanged(
        /* [in] */ const String& txid,
        /* [in] */ const String& status,
        /* [in] */ const String& desc,
        /* [in] */ Int32 confirms);

    /**
     * Callback method fired when block begin synchronizing with a peer. This callback could be used to show progress.
     */
    CARAPI OnBlockSyncStarted();

    /**
     * Callback method fired when best block chain height increased. This callback could be used to show progress.
     * @param currentBlockHeight is the of current block when callback fired.
     * @param progress is current progress when block height increased.
     */
    CARAPI OnBlockHeightIncreased(
        /* [in] */ Int32 currentBlockHeight,
        /* [in] */ Double progress);

    /**
     * Callback method fired when block end synchronizing with a peer. This callback could be used to show progress.
     */
    CARAPI OnBlockSyncStopped();

private:
    JNIEnv* GetEnv();
    void Detach();

private:
    JavaVM* mVM;
    jobject mObj;
};


static std::map<jobject, ElaSubWalletListener*> sSubCallbackMap;
static void JNICALL nativeAddCallback(JNIEnv *env, jobject clazz, jlong jSubProxy, jobject jsubCallback)
{
    LOGD("FUNC=[%s]========================LINE=[%d]", __FUNCTION__, __LINE__);
    ElaSubWalletListener* subCallback = new ElaSubWalletListener(env, jsubCallback);
    ISubWallet* subWallet = (ISubWallet*)jSubProxy;
    subWallet->AddCallback(subCallback);
    sSubCallbackMap[jsubCallback] = subCallback;
}

static void JNICALL nativeRemoveCallback(JNIEnv *env, jobject clazz, jlong jSubProxy, jobject jsubCallback)
{
    ISubWallet* subWallet = (ISubWallet*)jSubProxy;
    std::map<jobject, ElaSubWalletListener*>::iterator it;
    for (it = sSubCallbackMap.begin(); it != sSubCallbackMap.end(); it++) {
        if (jsubCallback == it->first) {
            subWallet->RemoveCallback(it->second);
            delete it->second;
            sSubCallbackMap.erase(it);
            break;
        }
    }
}

static jstring JNICALL nativeCreateTransaction(JNIEnv *env, jobject clazz, jlong jSubProxy, jstring jfromAddress,
        jstring jtoAddress, jlong amount, jstring jmemo, jstring jremark)
{
    const char* fromAddress = env->GetStringUTFChars(jfromAddress, NULL);
    const char* toAddress = env->GetStringUTFChars(jtoAddress, NULL);
    const char* memo = env->GetStringUTFChars(jmemo, NULL);
    const char* remark = env->GetStringUTFChars(jremark, NULL);

    ISubWallet* subWallet = (ISubWallet*)jSubProxy;
    jstring retValue = NULL;
    try {
        String result;
        subWallet->CreateTransaction(String(fromAddress), String(toAddress), amount, String(memo), String(remark), &result);
        retValue = env->NewStringUTF(result.string());
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
    env->ReleaseStringUTFChars(jmemo, memo);
    env->ReleaseStringUTFChars(jremark, remark);
    return retValue;
}

static jstring JNICALL nativeCreateMultiSignAddress(JNIEnv *env, jobject clazz, jlong jSubProxy, jstring jmultiPublicKeyJson,
        jint totalSignNum, jint requiredSignNum)
{
    const char* multiPublicKeyJson = env->GetStringUTFChars(jmultiPublicKeyJson, NULL);

    ISubWallet* subWallet = (ISubWallet*)jSubProxy;
    jstring retValue = NULL;
    try {
        String result;
        subWallet->CreateMultiSignAddress(String(multiPublicKeyJson), totalSignNum, requiredSignNum, &result);
        retValue = env->NewStringUTF(result.string());
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

    env->ReleaseStringUTFChars(jmultiPublicKeyJson, multiPublicKeyJson);
    return retValue;
}

//"(JLjava/lang/String;Ljava/lang/String;JJLjava/lang/String;Ljava/lang/String;)Ljava/lang/String;"
static jstring JNICALL nativeCreateMultiSignTransaction(JNIEnv *env, jobject clazz, jlong jSubProxy, jstring jfromAddress,
        jstring jtoAddress, jlong amount, jstring jmemo)
{
    const char* fromAddress = env->GetStringUTFChars(jfromAddress, NULL);
    const char* toAddress = env->GetStringUTFChars(jtoAddress, NULL);
    const char* memo = env->GetStringUTFChars(jmemo, NULL);

    ISubWallet* subWallet = (ISubWallet*)jSubProxy;
    jstring retValue = NULL;

    try {
        String result;
        subWallet->CreateMultiSignTransaction(String(fromAddress), String(toAddress), amount, String(memo), &result);
        retValue = env->NewStringUTF(result.string());
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
    env->ReleaseStringUTFChars(jmemo, memo);
    return retValue;
}

static jstring JNICALL nativeSendRawTransaction(JNIEnv *env, jobject clazz, jlong jSubProxy, jstring jtransactionJson
    ,jlong jfee, jstring jsignJson)
{
    const char* transactionJson = env->GetStringUTFChars(jtransactionJson, NULL);
    const char* signJson = env->GetStringUTFChars(jsignJson, NULL);

    ISubWallet* subWallet = (ISubWallet*)jSubProxy;
    jstring retValue = NULL;

    try {
        String result;
        subWallet->SendRawTransaction(String(transactionJson), jfee, String(signJson), &result);
        retValue = env->NewStringUTF(result.string());
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

    env->ReleaseStringUTFChars(jtransactionJson, transactionJson);
    env->ReleaseStringUTFChars(jsignJson, signJson);
    return retValue;
}

static jstring JNICALL nativeGetAllTransaction(JNIEnv *env, jobject clazz, jlong jSubProxy, jint start,
        jint count, jstring jaddressOrTxid)
{
    const char* addressOrTxid = env->GetStringUTFChars(jaddressOrTxid, NULL);

    ISubWallet* subWallet = (ISubWallet*)jSubProxy;
    String result;
    subWallet->GetAllTransaction(start, count, String(addressOrTxid), &result);
    LOGD("Func=[%s]====Line=[%d]====================result=[%s]", __FUNCTION__, __LINE__, result.string());

    env->ReleaseStringUTFChars(jaddressOrTxid, addressOrTxid);
    return env->NewStringUTF(result.string());
}


static jstring JNICALL nativeSign(JNIEnv *env, jobject clazz, jlong jSubProxy, jstring jmessage, jstring jpayPassword)
{
    const char* message = env->GetStringUTFChars(jmessage, NULL);
    const char* payPassword = env->GetStringUTFChars(jpayPassword, NULL);

    ISubWallet* subWallet = (ISubWallet*)jSubProxy;
    jstring retValue = NULL;

    try {
        String result;
        subWallet->Sign(String(message), String(payPassword), &result);
        retValue = env->NewStringUTF(result.string());
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

    env->ReleaseStringUTFChars(jmessage, message);
    env->ReleaseStringUTFChars(jpayPassword, payPassword);
    return retValue;
}

static jstring JNICALL nativeCheckSign(JNIEnv *env, jobject clazz, jlong jSubProxy, jstring jaddress, jstring jmessage, jstring jsignature)
{
    const char* address = env->GetStringUTFChars(jaddress, NULL);
    const char* message = env->GetStringUTFChars(jmessage, NULL);
    const char* signature = env->GetStringUTFChars(jsignature, NULL);

    ISubWallet* subWallet = (ISubWallet*)jSubProxy;
    jstring retValue = NULL;
    try {
        String result;
        subWallet->CheckSign(String(address), String(message), String(signature), &result);
        retValue = env->NewStringUTF(result.string());
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

    env->ReleaseStringUTFChars(jaddress, address);
    env->ReleaseStringUTFChars(jmessage, message);
    env->ReleaseStringUTFChars(jsignature, signature);
    return retValue;
}

static jlong JNICALL nativeCalculateTransactionFee(JNIEnv *env, jobject clazz, jlong jSubProxy, jstring jrawTransaction, jlong feePerKb)
{
    const char* rawTransaction = env->GetStringUTFChars(jrawTransaction, NULL);
    ISubWallet* subWallet = (ISubWallet*)jSubProxy;
    Int64 fee = 0;

    try {
        subWallet->CalculateTransactionFee(String(rawTransaction), feePerKb, &fee);
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

    env->ReleaseStringUTFChars(jrawTransaction, rawTransaction);
    return (jlong)fee;
}

static const JNINativeMethod gMethods[] = {
    {"nativeGetChainId", "(J)Ljava/lang/String;", (void*)nativeGetChainId},
    {"nativeGetBalanceInfo", "(J)Ljava/lang/String;", (void*)nativeGetBalanceInfo},
    {"nativeGetBalance", "(J)J", (void*)nativeGetBalance},
    {"nativeCreateAddress", "(J)Ljava/lang/String;", (void*)nativeCreateAddress},
    {"nativeGetAllAddress", "(JII)Ljava/lang/String;", (void*)nativeGetAllAddress},
    {"nativeGetBalanceWithAddress", "(JLjava/lang/String;)J", (void*)nativeGetBalanceWithAddress},
    {"nativeAddCallback", "(JLcom/elastos/spvcore/ISubWalletCallback;)V", (void*)nativeAddCallback},
    {"nativeRemoveCallback", "(JLcom/elastos/spvcore/ISubWalletCallback;)V", (void*)nativeRemoveCallback},
    {"nativeCreateTransaction", "(JLjava/lang/String;Ljava/lang/String;JLjava/lang/String;Ljava/lang/String;)Ljava/lang/String;", (void*)nativeCreateTransaction},
    {"nativeCreateMultiSignTransaction", "(JLjava/lang/String;Ljava/lang/String;JLjava/lang/String;)Ljava/lang/String;", (void*)nativeCreateMultiSignTransaction},
    {"nativeCreateMultiSignAddress", "(JLjava/lang/String;II)Ljava/lang/String;", (void*)nativeCreateMultiSignAddress},
    {"nativeSendRawTransaction", "(JLjava/lang/String;JLjava/lang/String;)Ljava/lang/String;", (void*)nativeSendRawTransaction},
    {"nativeGetAllTransaction", "(JIILjava/lang/String;)Ljava/lang/String;", (void*)nativeGetAllTransaction},
    {"nativeSign", "(JLjava/lang/String;Ljava/lang/String;)Ljava/lang/String;", (void*)nativeSign},
    {"nativeCheckSign", "(JLjava/lang/String;Ljava/lang/String;Ljava/lang/String;)Z", (void*)nativeCheckSign},
    {"nativeCalculateTransactionFee", "(JLjava/lang/String;J)J", (void*)nativeCalculateTransactionFee},
};

jint register_elastos_spv_ISubWallet(JNIEnv *env)
{
    return jniRegisterNativeMethods(env, "com/elastos/spvcore/ISubWallet",
        gMethods, NELEM(gMethods));
}

CAR_INTERFACE_IMPL(ElaSubWalletListener, Object, ISubWalletListener)
ElaSubWalletListener::ElaSubWalletListener(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj)
{
    LOGD("FUNC=[%s]========================LINE=[%d]", __FUNCTION__, __LINE__);
    mObj = env->NewGlobalRef(jobj);
    env->GetJavaVM(&mVM);
}

ElaSubWalletListener::~ElaSubWalletListener()
{
    LOGD("FUNC=[%s]========================LINE=[%d]", __FUNCTION__, __LINE__);
    if (mObj) {
        GetEnv()->DeleteGlobalRef(mObj);
    }
}

JNIEnv* ElaSubWalletListener::GetEnv()
{
    JNIEnv* env;
    assert(mVM != NULL);
    mVM->AttachCurrentThread(&env, NULL);
    return env;
}

void ElaSubWalletListener::Detach()
{
    assert(mVM != NULL);
    mVM->DetachCurrentThread();
}

ECode ElaSubWalletListener::OnTransactionStatusChanged(
    /* [in] */ const String& txid,
    /* [in] */ const String& status,
    /* [in] */ const String& desc,
    /* [in] */ Int32 confirms)
{
    JNIEnv* env = GetEnv();
    LOGD("FUNC=[%s]========================LINE=[%d], txid=[%s], status=[%s], desc=[%s]", __FUNCTION__, __LINE__,
                txid.string(), status.string(), desc.string());

    jclass clazz = env->GetObjectClass(mObj);
    //"(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;I)V"
    jmethodID methodId = env->GetMethodID(clazz, "OnTransactionStatusChanged","(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;I)V");
    jstring jtxid = env->NewStringUTF(txid.string());
    jstring jstatus = env->NewStringUTF(status.string());
    jstring jdesc = env->NewStringUTF(desc.string());

    env->CallVoidMethod(mObj, methodId, jtxid, jstatus, jdesc, confirms);

    Detach();
    return NOERROR;
}

ECode ElaSubWalletListener::OnBlockSyncStarted()
{
    JNIEnv* env = GetEnv();
    LOGD("FUNC=[%s]========================LINE=[%d]", __FUNCTION__, __LINE__);

    jclass clazz = env->GetObjectClass(mObj);
    jmethodID methodId = env->GetMethodID(clazz, "OnBlockSyncStarted","()V");
    env->CallVoidMethod(mObj, methodId);

    Detach();
    return NOERROR;
}

ECode ElaSubWalletListener::OnBlockHeightIncreased(
    /* [in] */ Int32 currentBlockHeight,
    /* [in] */ Double progress)
{
    JNIEnv* env = GetEnv();
    LOGD("FUNC=[%s]========================LINE=[%d]", __FUNCTION__, __LINE__);

    jclass clazz = env->GetObjectClass(mObj);
    jmethodID methodId = env->GetMethodID(clazz, "OnBlockHeightIncreased","(ID)V");
    env->CallVoidMethod(mObj, methodId, currentBlockHeight, progress);

    Detach();
    return NOERROR;
}

ECode ElaSubWalletListener::OnBlockSyncStopped()
{
    JNIEnv* env = GetEnv();
    LOGD("FUNC=[%s]========================LINE=[%d]", __FUNCTION__, __LINE__);

    jclass clazz = env->GetObjectClass(mObj);
    jmethodID methodId = env->GetMethodID(clazz, "OnBlockSyncStopped","()V");
    env->CallVoidMethod(mObj, methodId);

    Detach();
    return NOERROR;
}
