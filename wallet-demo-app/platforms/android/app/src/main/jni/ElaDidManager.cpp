// Copyright (c) 2012-2018 The Elastos Open Source Project
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "ElaUtils.h"
#include "Elastos.DID.h"
#include "elastos/core/Object.h"
#include <map>

//"(JLjava/lang/String;)J"
static jlong JNICALL nativeCreateDID(JNIEnv *env, jobject clazz, jlong jDidMgrProxy, jstring jpassword)
{
    const char* password = env->GetStringUTFChars(jpassword, NULL);
    IDIDManager* didMgr = (IDIDManager*)jDidMgrProxy;
    IDID* did = NULL;
    didMgr->CreateDID(String(password), &did);
    env->ReleaseStringUTFChars(jpassword, password);
    return (jlong)did;
}

//"(JLjava/lang/String;)J"
static jlong JNICALL nativeGetDID(JNIEnv *env, jobject clazz, jlong jDidMgrProxy, jstring jdidName)
{
    const char* didName = env->GetStringUTFChars(jdidName, NULL);
    IDIDManager* didMgr = (IDIDManager*)jDidMgrProxy;
    IDID* did = NULL;
    didMgr->GetDID(String(didName), &did);
    env->ReleaseStringUTFChars(jdidName, didName);
    return (jlong)did;
}

//"(J)Ljava/lang/String;"
static /*nlohmann::json*/ jstring JNICALL nativeGetDIDList(JNIEnv *env, jobject clazz, jlong jDidMgrProxy)
{
    IDIDManager* didMgr = (IDIDManager*)jDidMgrProxy;
    String jsonValue;
    didMgr->GetDIDList(&jsonValue);
    LOGD("FUNC=[%s]========================value=[%s]", __FUNCTION__, jsonValue.string());
    return env->NewStringUTF(jsonValue.string());
}

//"(JLjava/lang/String;)V"
static void JNICALL nativeDestoryDID(JNIEnv *env, jobject clazz, jlong jDidMgrProxy, jstring jdidName)
{
    const char* didName = env->GetStringUTFChars(jdidName, NULL);
    IDIDManager* didMgr = (IDIDManager*)jDidMgrProxy;
    didMgr->DestoryDID(String(didName));
    env->ReleaseStringUTFChars(jdidName, didName);
}


class ElaIdManagerCallback
    : public Object
    , public IDIDManagerCallback
{
public:
    CAR_INTERFACE_DECL()

    ElaIdManagerCallback(
        /* [in] */ JNIEnv* env,
        /* [in] */ jobject jobj);

    ~ElaIdManagerCallback();

    ECode OnIdStatusChanged(
        /* [in] */ const String& id,
        /* [in] */ const String& path,
        /* [in] */ const String& valueJson);

private:
    JNIEnv* GetEnv();
    void Detach();

private:
    JavaVM* mVM;
    jobject mObj;
};

static std::map<jstring, ElaIdManagerCallback*> sIdCallbackMap;
static jboolean JNICALL nativeRegisterCallback(JNIEnv *env, jobject clazz, jlong jDidMgrProxy, jstring jdidName, jobject jidCallback)
{
    LOGD("FUNC=[%s]========================LINE=[%d]", __FUNCTION__, __LINE__);
    const char* didName = env->GetStringUTFChars(jdidName, NULL);
    ElaIdManagerCallback* idCallback = new ElaIdManagerCallback(env, jidCallback);
    IDIDManager* didMgr = (IDIDManager*)jDidMgrProxy;
    Boolean status = didMgr->RegisterCallback(String(didName), idCallback);
    sIdCallbackMap[jdidName] = idCallback;

    env->ReleaseStringUTFChars(jdidName, didName);
    return (jboolean)status;
}

static jboolean JNICALL nativeUnregisterCallback(JNIEnv *env, jobject clazz, jlong jDidMgrProxy, jstring jdidName)
{
    const char* didName = env->GetStringUTFChars(jdidName, NULL);

    IDIDManager* didMgr = (IDIDManager*)jDidMgrProxy;
    std::map<jstring, ElaIdManagerCallback*>::iterator it;
    Boolean status = FALSE;
    for (it = sIdCallbackMap.begin(); it != sIdCallbackMap.end(); it++) {
        if (jdidName == it->first) {
            status = didMgr->UnregisterCallback(String(didName));
            delete it->second;
            sIdCallbackMap.erase(it);
            break;
        }
    }

    env->ReleaseStringUTFChars(jdidName, didName);
    return (jboolean)status;
}

static const JNINativeMethod gMethods[] = {
    {"nativeCreateDID", "(JLjava/lang/String;)J", (void*)nativeCreateDID},
    {"nativeGetDID", "(JLjava/lang/String;)J", (void*)nativeGetDID},
    {"nativeGetDIDList", "(J)Ljava/lang/String;", (void*)nativeGetDIDList},
    {"nativeDestoryDID", "(JLjava/lang/String;)V", (void*)nativeDestoryDID},
    {"nativeRegisterCallback", "(JLjava/lang/String;Lcom/elastos/spvcore/IIdManagerCallback;)Z", (void*)nativeRegisterCallback},
    {"nativeUnregisterCallback", "(JLjava/lang/String;)Z", (void*)nativeUnregisterCallback},
};

jint register_elastos_spv_IDidManager(JNIEnv *env)
{
    return jniRegisterNativeMethods(env, "com/elastos/spvcore/IDidManager",
        gMethods, NELEM(gMethods));
}

CAR_INTERFACE_IMPL(ElaIdManagerCallback, Object, IDIDManagerCallback)
ElaIdManagerCallback::ElaIdManagerCallback(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj)
{
    LOGD("FUNC=[%s]========================LINE=[%d]", __FUNCTION__, __LINE__);
    mObj = env->NewGlobalRef(jobj);
    env->GetJavaVM(&mVM);
}

ElaIdManagerCallback::~ElaIdManagerCallback()
{
    LOGD("FUNC=[%s]========================LINE=[%d]", __FUNCTION__, __LINE__);
    if (mObj) {
        GetEnv()->DeleteGlobalRef(mObj);
    }
}

JNIEnv* ElaIdManagerCallback::GetEnv()
{
    JNIEnv* env;
    assert(mVM != NULL);
    mVM->AttachCurrentThread(&env, NULL);
    return env;
}

void ElaIdManagerCallback::Detach()
{
    assert(mVM != NULL);
    mVM->DetachCurrentThread();
}

ECode ElaIdManagerCallback::OnIdStatusChanged(
    /* [in] */ const String& id,
    /* [in] */ const String& path,
    /* [in] */ const String& valueJson)
{
    JNIEnv* env = GetEnv();
    LOGD("FUNC=[%s]========================LINE=[%d]", __FUNCTION__, __LINE__);

    jclass clazz = env->GetObjectClass(mObj);
    //"(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;I)V"
    jmethodID methodId = env->GetMethodID(clazz, "OnIdStatusChanged","(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
    jstring jid = env->NewStringUTF(id.string());
    jstring jpath = env->NewStringUTF(path.string());
    jstring jvalue = env->NewStringUTF(valueJson.string());

    env->CallVoidMethod(mObj, methodId, jid, jpath, jvalue);

    Detach();
    return NOERROR;
}
