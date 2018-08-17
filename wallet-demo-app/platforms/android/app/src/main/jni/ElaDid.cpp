// Copyright (c) 2012-2018 The Elastos Open Source Project
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "ElaUtils.h"
#include "Elastos.DID.h"

//"(J)Ljava/lang/String;"
static jstring JNICALL nativeGetDIDName(JNIEnv *env, jobject clazz, jlong jDidProxy)
{
    IDID* did = (IDID*)jDidProxy;
    String value;
    did->GetDIDName(&value);
    return env->NewStringUTF(value.string());
}

//"(JLjava/lang/String;Ljava/lang/String;)V"
static void JNICALL nativeSetValue(JNIEnv *env, jobject clazz, jlong jDidProxy, jstring jkeyPath, jstring jvalueJson)
{
    const char* keyPath = env->GetStringUTFChars(jkeyPath, NULL);
    const char* valueJson = env->GetStringUTFChars(jvalueJson, NULL);
    IDID* did = (IDID*)jDidProxy;
    LOGD("FUNC=[%s]===================LINE=[%d], p=[%s], v=[%s]", __FUNCTION__, __LINE__, keyPath, valueJson);
    did->SetValue(String(keyPath), String(valueJson));
    env->ReleaseStringUTFChars(jkeyPath, keyPath);
    env->ReleaseStringUTFChars(jvalueJson, valueJson);
}

//"(JLjava/lang/String;)Ljava/lang/String;"
static /*nlohmann::json*/ jstring JNICALL nativeGetValue(JNIEnv *env, jobject clazz, jlong jDidProxy, jstring jpath)
{
    const char* path = env->GetStringUTFChars(jpath, NULL);
    IDID* did = (IDID*)jDidProxy;
    String value;
    did->GetValue(String(path), &value);
    env->ReleaseStringUTFChars(jpath, path);

    LOGD("FUNC=[%s]===================LINE=[%d], p=[%s], v=[%s]", __FUNCTION__, __LINE__, path, value.string());
    return env->NewStringUTF(value.string());
}

//"(JLjava/lang/String;)Ljava/lang/String;"
static /*nlohmann::json*/ jstring JNICALL nativeGetHistoryValue(JNIEnv *env, jobject clazz, jlong jDidProxy, jstring jkeyPath)
{
    const char* keyPath = env->GetStringUTFChars(jkeyPath, NULL);
    IDID* did = (IDID*)jDidProxy;
    String value;
    did->GetHistoryValue(String(keyPath), &value);
    env->ReleaseStringUTFChars(jkeyPath, keyPath);
    return env->NewStringUTF(value.string());
}

//"(JII)Ljava/lang/String;"
static /*nlohmann::json*/ jstring JNICALL nativeGetAllKeys(JNIEnv *env, jobject clazz, jlong jDidProxy, jint jstart, jint jcount)
{
    IDID* did = (IDID*)jDidProxy;
    String value;
    did->GetAllKeys(jstart, jcount, &value);
    LOGD("FUNC=[%s]===================LINE=[%d], keys=[%s]", __FUNCTION__, __LINE__, value.string());
    return stringTojstring(env, value.string());
}

//"(JLjava/lang/String;Ljava/lang/String;)Ljava/lang/String;"
static jstring JNICALL nativeSign(JNIEnv *env, jobject clazz, jlong jDidProxy, jstring jmessage, jstring jpassword)
{
    const char* message = env->GetStringUTFChars(jmessage, NULL);
    const char* password = env->GetStringUTFChars(jpassword, NULL);
    IDID* did = (IDID*)jDidProxy;
    String value;
    did->Sign(String(message), String(password), &value);
    env->ReleaseStringUTFChars(jmessage, message);
    env->ReleaseStringUTFChars(jpassword, password);
    return env->NewStringUTF(value.string());
}

//"(JLjava/lang/String;Ljava/lang/String;)Ljava/lang/String;"
static /*nlohmann::json*/ jstring JNICALL nativeCheckSign(JNIEnv *env, jobject clazz, jlong jDidProxy
                , jstring jmessage, jstring jsignature)
{
    const char* message = env->GetStringUTFChars(jmessage, NULL);
    const char* signature = env->GetStringUTFChars(jsignature, NULL);
    IDID* did = (IDID*)jDidProxy;
    String jsonValue;
    did->CheckSign(String(message), String(signature), &jsonValue);
    env->ReleaseStringUTFChars(jmessage, message);
    env->ReleaseStringUTFChars(jsignature, signature);

    return env->NewStringUTF(jsonValue.string());
}

//"(J)Ljava/lang/String;"
static jstring JNICALL nativeGetPublicKey(JNIEnv *env, jobject clazz, jlong jDidProxy)
{
    IDID* did = (IDID*)jDidProxy;
    String value;
    did->GetPublicKey(&value);
    return env->NewStringUTF(value.string());
}

//"(JLjava/lang/String;Ljava/lang/String;)Ljava/lang/String;"
static jstring JNICALL nativeGenerateProgram(JNIEnv *env, jobject clazz, jlong jDidProxy, jstring jmessage, jstring jpassword)
{
    const char* message = env->GetStringUTFChars(jmessage, NULL);
    const char* password = env->GetStringUTFChars(jpassword, NULL);
    IDID* did = (IDID*)jDidProxy;
    String jsonValue;
    did->GenerateProgram(String(message), String(password), &jsonValue);
    env->ReleaseStringUTFChars(jmessage, message);
    env->ReleaseStringUTFChars(jpassword, password);
    return env->NewStringUTF(jsonValue.string());
}

static const JNINativeMethod gMethods[] = {
    {"nativeGetDIDName", "(J)Ljava/lang/String;", (void*)nativeGetDIDName},
    {"nativeSetValue", "(JLjava/lang/String;Ljava/lang/String;)V", (void*)nativeSetValue},
    {"nativeGetValue", "(JLjava/lang/String;)Ljava/lang/String;", (void*)nativeGetValue},
    {"nativeGetHistoryValue", "(JLjava/lang/String;)Ljava/lang/String;", (void*)nativeGetHistoryValue},
    {"nativeGetAllKeys", "(JII)Ljava/lang/String;", (void*)nativeGetAllKeys},
    {"nativeSign", "(JLjava/lang/String;Ljava/lang/String;)Ljava/lang/String;", (void*)nativeSign},
    {"nativeCheckSign", "(JLjava/lang/String;Ljava/lang/String;)Ljava/lang/String;", (void*)nativeCheckSign},
    {"nativeGetPublicKey", "(J)Ljava/lang/String;", (void*)nativeGetPublicKey},
    {"nativeGenerateProgram", "(JLjava/lang/String;Ljava/lang/String;)Ljava/lang/String;", (void*)nativeGenerateProgram},
};

jint register_elastos_spv_IDid(JNIEnv *env)
{
    return jniRegisterNativeMethods(env, "com/elastos/spvcore/IDid",
        gMethods, NELEM(gMethods));
}
