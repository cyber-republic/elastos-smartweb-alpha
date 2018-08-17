//=========================================================================
// Copyright (C) 2012 The Elastos Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=========================================================================

#ifndef __ELASTOS_CORE_DEF_H__
#define __ELASTOS_CORE_DEF_H__

#ifndef __USE_MALLOC
#define __USE_MALLOC
#endif

#include <errno.h>
#include <unistd.h>

#include <elastos.h>
using namespace Elastos;

#define ANDROID_SMP 1

#ifdef __GNUC__
#define UNUSED(x) x __attribute__((__unused__))
#else
#define UNUSED(x) x
#endif

/*
 * TEMP_FAILURE_RETRY is defined by some, but not all, versions of
 * <unistd.h>. (Alas, it is not as standard as we'd hoped!) So, if it's
 * not already defined, then define it here.
 */
#ifndef TEMP_FAILURE_RETRY
/* Used to retry syscalls that can return EINTR. */
#define TEMP_FAILURE_RETRY(exp) ({         \
    typeof (exp) _rc;                      \
    do {                                   \
        _rc = (exp);                       \
    } while (_rc == -1 && errno == EINTR); \
    _rc; })
#endif

#ifndef ASSERT_TRUE
#define ASSERT_TRUE(expr) \
    do { \
        Boolean UNUSED(assert_result_) = (Boolean)(expr); \
        assert(assert_result_); \
    } while(0);
#endif

#ifndef ASSERT_SUCCEEDED
#define ASSERT_SUCCEEDED(expr) \
   do { \
       ECode UNUSED(assert_ec_) = expr; \
       assert(SUCCEEDED(assert_ec_)); \
   } while(0);
#endif

#ifndef VALIDATE_NOT_NULL
#define VALIDATE_NOT_NULL(x) if (!x) { return E_ILLEGAL_ARGUMENT_EXCEPTION; }
#endif

#ifndef FAIL_RETURN
#define FAIL_RETURN(expr) \
    do { \
        ECode fail_ec_ = expr; \
        if (FAILED(fail_ec_)) return fail_ec_; \
    } while(0);
#endif

#ifndef FAIL_RETURN_NULL
#define FAIL_RETURN_NULL(expr) \
    do { \
        ECode fail_ec_ = expr; \
        if (FAILED(fail_ec_)) return NULL; \
    } while(0);
#endif

#ifndef FAIL_GOTO
#define FAIL_GOTO(expr, label) \
    do { \
        ECode fail_ec_ = expr; \
        if (FAILED(fail_ec_)) goto label; \
    } while(0);
#endif

#ifndef TO_IINTERFACE
#define TO_IINTERFACE(obj) ((obj) == NULL ? NULL : (obj)->Probe(EIID_IInterface))
#endif

#ifndef TO_STR
#define TO_STR(obj) (Object::ToString(obj))
#endif

#ifndef TO_CSTR
#define TO_CSTR(obj) (Object::ToString(obj).string())
#endif

#ifndef __UUNM_Elastos_CoreLibrary_DEFINED__
#define __UUNM_Elastos_CoreLibrary_DEFINED__
#if defined(_android)
#define c_pElastos_CoreLibraryUunm "libElastos.CoreLibrary.so"
#else
#define c_pElastos_CoreLibraryUunm "Elastos.CoreLibrary.eco"
#endif // _android
#endif // __UUNM_Elastos_CoreLibrary_DEFINED__

#ifndef __SAME_CLASS_NAME_OF_JNI__
#define __SAME_CLASS_NAME_OF_JNI__
// for jni class has same name with car implement class
#define NATIVE(x) ::x
#endif // __SAME_CLASS_NAME_OF_JNI__

// defines for ETL hash functions
//
#ifndef __ETL_HASH_FUN_H__
#include "elastos/utility/etl/etl_hash_fun.h"
#endif

#ifndef __ETL_FUNCTION_H__
#include "elastos/utility/etl/etl_function.h"
#endif

#ifndef DEFINE_OBJECT_HASH_FUNC_FOR
#define DEFINE_OBJECT_HASH_FUNC_FOR(TypeName)                                           \
_ETL_NAMESPACE_BEGIN                                                                    \
template<> struct Hash<TypeName *>                                                      \
{                                                                                       \
    size_t operator()(TypeName * s) const                                               \
    {                                                                                   \
        return (size_t)Elastos::Core::Object::GetHashCode(s);                           \
    }                                                                                   \
};                                                                                      \
                                                                                        \
template<> struct Hash<AutoPtr<TypeName> >                                              \
{                                                                                       \
    size_t operator()(const AutoPtr<TypeName> & s) const                                \
    {                                                                                   \
        return (size_t)Elastos::Core::Object::GetHashCode(s.Get());                     \
    }                                                                                   \
};                                                                                      \
                                                                                        \
template<> struct EqualTo<TypeName *>                                                   \
{                                                                                       \
    Boolean operator()(TypeName * x, TypeName * y) const                                \
    {                                                                                   \
        return Elastos::Core::Object::Equals(x, y);                                     \
    }                                                                                   \
};                                                                                      \
                                                                                        \
template<> struct EqualTo<AutoPtr<TypeName> >                                           \
{                                                                                       \
    Boolean operator()(const AutoPtr<TypeName> & x, const AutoPtr<TypeName> & y) const  \
    {                                                                                   \
        return Elastos::Core::Object::Equals(x, y);                                     \
    }                                                                                   \
};                                                                                      \
                                                                                        \
_ETL_NAMESPACE_END
#endif // DEFINE_OBJECT_HASH_FUNC_FOR

#ifndef DEFINE_OBJECT_HASH_FUNC_USING_ADDR_FOR
#define DEFINE_OBJECT_HASH_FUNC_USING_ADDR_FOR(TypeName)                                \
_ETL_NAMESPACE_BEGIN                                                                    \
template<> struct Hash<TypeName *>                                                      \
{                                                                                       \
    size_t operator()(TypeName * s) const                                               \
    {                                                                                   \
        return (size_t)s;                                                               \
    }                                                                                   \
};                                                                                      \
                                                                                        \
template<> struct Hash<AutoPtr<TypeName> >                                              \
{                                                                                       \
    size_t operator()(const AutoPtr<TypeName> & s) const                                \
    {                                                                                   \
        return (size_t)s.Get();                                                         \
    }                                                                                   \
};                                                                                      \
                                                                                        \
template<> struct EqualTo<TypeName *>                                                   \
{                                                                                       \
    Boolean operator()(TypeName * x, TypeName * y) const                                \
    {                                                                                   \
        return (x == y);                                                                \
    }                                                                                   \
};                                                                                      \
                                                                                        \
template<> struct EqualTo<AutoPtr<TypeName> >                                           \
{                                                                                       \
    Boolean operator()(const AutoPtr<TypeName> & x, const AutoPtr<TypeName> & y) const  \
    {                                                                                   \
        return (x.Get() == y.Get());                                                    \
    }                                                                                   \
};                                                                                      \
                                                                                        \
_ETL_NAMESPACE_END
#endif // DEFINE_OBJECT_HASH_FUNC_USING_ADDR_FOR

// Car interface decls and impls
//
#ifndef CAR_INTERFACE_DECL
#define CAR_INTERFACE_DECL()                                \
    CARAPI_(UInt32) AddRef();                               \
                                                            \
    CARAPI_(UInt32) Release();                              \
                                                            \
    CARAPI_(PInterface) Probe(                              \
        /* [in] */ REIID riid);                             \
                                                            \
    CARAPI GetInterfaceID(                                  \
        /* [in] */ IInterface* object,                      \
        /* [out] */ InterfaceID* iid);
#endif

#ifndef CAR_INTERFACE_IMPL_1
#define CAR_INTERFACE_IMPL_1(ClassName, SupperClassName, InterfaceName)       \
                                                           \
    UInt32 ClassName::AddRef()                             \
    {                                                      \
        return SupperClassName::AddRef();                  \
    }                                                      \
                                                           \
    UInt32 ClassName::Release()                            \
    {                                                      \
        return SupperClassName::Release();                 \
    }                                                      \
                                                           \
    PInterface ClassName::Probe(                           \
        /* [in] */ REIID riid)                             \
    {                                                      \
        if (riid == EIID_IInterface) {                     \
            return (IInterface*)(InterfaceName*)this;      \
        }                                                  \
        else if (riid == EIID_##InterfaceName) {           \
            return (InterfaceName*)this;                   \
        }                                                  \
        return SupperClassName::Probe(riid);               \
    }                                                      \
                                                           \
    ECode ClassName::GetInterfaceID(                       \
        /* [in] */ IInterface* object,                     \
        /* [out] */ InterfaceID* iid)                      \
    {                                                      \
        VALIDATE_NOT_NULL(iid);                            \
                                                           \
        if (object == (IInterface*)(InterfaceName*)this) { \
            *iid = EIID_##InterfaceName;                   \
            return NOERROR;                                \
        }                                                  \
        return SupperClassName::GetInterfaceID(object, iid); \
    }
#endif

#ifndef CAR_INTERFACE_IMPL_LIGHT_1
#define CAR_INTERFACE_IMPL_LIGHT_1(ClassName, SupperClassName, InterfaceName) \
    UInt32 ClassName::AddRef()                             \
    {                                                      \
        return ElLightRefBase::AddRef();                   \
    }                                                      \
                                                           \
    UInt32 ClassName::Release()                            \
    {                                                      \
        return ElLightRefBase::Release();                  \
    }                                                      \
                                                           \
    PInterface ClassName::Probe(                           \
        /* [in] */ REIID riid)                             \
    {                                                      \
        if (riid == EIID_IInterface) {                     \
            return (IInterface*)(InterfaceName*)this;      \
        }                                                  \
        else if (riid == EIID_##InterfaceName) {           \
            return (InterfaceName*)this;                   \
        }                                                  \
        return SupperClassName::Probe(riid);               \
    }                                                      \
                                                           \
    ECode ClassName::GetInterfaceID(                       \
        /* [in] */ IInterface* object,                     \
        /* [out] */ InterfaceID* iid)                      \
    {                                                      \
        VALIDATE_NOT_NULL(iid);                            \
                                                           \
        if (object == (IInterface*)(InterfaceName*)this) { \
            *iid = EIID_##InterfaceName;                   \
            return NOERROR;                                \
        }                                                  \
        return SupperClassName::GetInterfaceID(object, iid); \
    }
#endif

#ifndef CAR_INTERFACE_IMPL_2
#define CAR_INTERFACE_IMPL_2(ClassName, SupperClassName, Interface1, Interface2) \
    UInt32 ClassName::AddRef()                                  \
    {                                                           \
        return SupperClassName::AddRef();                       \
    }                                                           \
                                                                \
    UInt32 ClassName::Release()                                 \
    {                                                           \
        return SupperClassName::Release();                      \
    }                                                           \
                                                                \
    PInterface ClassName::Probe(                                \
        /* [in] */ REIID riid)                                  \
    {                                                           \
        if (riid == EIID_IInterface) {                          \
            return (IInterface*)(Interface1*)this;              \
        }                                                       \
        else if (riid == EIID_##Interface1) {                   \
            return (Interface1*)this;                           \
        }                                                       \
        else if (riid == EIID_##Interface2) {                   \
            return (Interface2*)this;                           \
        }                                                       \
        return SupperClassName::Probe(riid);                    \
    }                                                           \
                                                                \
    ECode ClassName::GetInterfaceID(                            \
        /* [in] */ IInterface* object,                          \
        /* [out] */ InterfaceID* iid)                           \
    {                                                           \
        VALIDATE_NOT_NULL(iid);                                 \
                                                                \
        if (object == (IInterface*)(Interface1*)this) {         \
            *iid = EIID_##Interface1;                           \
        }                                                       \
        else if (object == (IInterface*)(Interface2*)this) {    \
            *iid = EIID_##Interface2;                           \
        }                                                       \
        else {                                                  \
            return SupperClassName::GetInterfaceID(object, iid); \
        }                                                       \
        return NOERROR;                                         \
    }
#endif

#ifndef CAR_INTERFACE_IMPL_LIGHT_2
#define CAR_INTERFACE_IMPL_LIGHT_2(ClassName, SupperClassName, Interface1, Interface2) \
    UInt32 ClassName::AddRef()                                        \
    {                                                                 \
        return ElLightRefBase::AddRef();                              \
    }                                                                 \
                                                                      \
    UInt32 ClassName::Release()                                       \
    {                                                                 \
        return ElLightRefBase::Release();                             \
    }                                                                 \
                                                                      \
    PInterface ClassName::Probe(                                      \
        /* [in] */ REIID riid)                                        \
    {                                                                 \
        if (riid == EIID_IInterface) {                                \
            return (IInterface*)(Interface1*)this;                    \
        }                                                             \
        else if (riid == EIID_##Interface1) {                         \
            return (Interface1*)this;                                 \
        }                                                             \
        else if (riid == EIID_##Interface2) {                         \
            return (Interface2*)this;                                 \
        }                                                             \
        return SupperClassName::Probe(riid);                          \
    }                                                                 \
                                                                      \
    ECode ClassName::GetInterfaceID(                                  \
        /* [in] */ IInterface* object,                                \
        /* [out] */ InterfaceID* iid)                                 \
    {                                                                 \
        VALIDATE_NOT_NULL(iid);                                       \
                                                                      \
        if (object == (IInterface*)(Interface1*)this) {               \
            *iid = EIID_##Interface1;                                 \
        }                                                             \
        else if (object == (IInterface*)(Interface2*)this) {          \
            *iid = EIID_##Interface2;                                 \
        }                                                             \
        else {                                                        \
            return SupperClassName::GetInterfaceID(object, iid);      \
        }                                                             \
        return NOERROR;                                               \
    }
#endif

#ifndef CAR_INTERFACE_IMPL_3
#define CAR_INTERFACE_IMPL_3(ClassName, SupperClassName, Interface1, Interface2, Interface3) \
    UInt32 ClassName::AddRef()                                              \
    {                                                                       \
        return SupperClassName::AddRef();                                   \
    }                                                                       \
                                                                            \
    UInt32 ClassName::Release()                                             \
    {                                                                       \
        return SupperClassName::Release();                                  \
    }                                                                       \
                                                                            \
    PInterface ClassName::Probe(                                            \
        /* [in] */ REIID riid)                                              \
    {                                                                       \
        if (riid == EIID_IInterface) {                                      \
            return (IInterface*)(Interface1*)this;                          \
        }                                                                   \
        else if (riid == EIID_##Interface1) {                               \
            return (Interface1*)this;                                       \
        }                                                                   \
        else if (riid == EIID_##Interface2) {                               \
            return (Interface2*)this;                                       \
        }                                                                   \
        else if (riid == EIID_##Interface3) {                               \
            return (Interface3*)this;                                       \
        }                                                                   \
        return SupperClassName::Probe(riid);                                \
    }                                                                       \
                                                                            \
    ECode ClassName::GetInterfaceID(                                        \
        /* [in] */ IInterface* object,                                      \
        /* [out] */ InterfaceID* iid)                                       \
    {                                                                       \
        VALIDATE_NOT_NULL(iid);                                             \
                                                                            \
        if (object == (IInterface*)(Interface1*)this) {                     \
            *iid = EIID_##Interface1;                                       \
        }                                                                   \
        else if (object == (IInterface*)(Interface2*)this) {                \
            *iid = EIID_##Interface2;                                       \
        }                                                                   \
        else if (object == (IInterface*)(Interface3*)this) {                \
            *iid = EIID_##Interface3;                                       \
        }                                                                   \
        else {                                                              \
            return SupperClassName::GetInterfaceID(object, iid);            \
        }                                                                   \
        return NOERROR;                                                     \
    }
#endif

#ifndef CAR_INTERFACE_IMPL_LIGHT_3
#define CAR_INTERFACE_IMPL_LIGHT_3(ClassName, SupperClassName, Interface1, Interface2, Interface3) \
    UInt32 ClassName::AddRef()                                                    \
    {                                                                             \
        return ElLightRefBase::AddRef();                                          \
    }                                                                             \
                                                                                  \
    UInt32 ClassName::Release()                                                   \
    {                                                                             \
        return ElLightRefBase::Release();                                         \
    }                                                                             \
                                                                                  \
    PInterface ClassName::Probe(                                                  \
        /* [in] */ REIID riid)                                                    \
    {                                                                             \
        if (riid == EIID_IInterface) {                                            \
            return (IInterface*)(Interface1*)this;                                \
        }                                                                         \
        else if (riid == EIID_##Interface1) {                                     \
            return (Interface1*)this;                                             \
        }                                                                         \
        else if (riid == EIID_##Interface2) {                                     \
            return (Interface2*)this;                                             \
        }                                                                         \
        else if (riid == EIID_##Interface3) {                                     \
            return (Interface3*)this;                                             \
        }                                                                         \
        return SupperClassName::Probe(riid);                                      \
    }                                                                             \
                                                                                  \
    ECode ClassName::GetInterfaceID(                                              \
        /* [in] */ IInterface* object,                                            \
        /* [out] */ InterfaceID* iid)                                             \
    {                                                                             \
        VALIDATE_NOT_NULL(iid);                                                   \
                                                                                  \
        if (object == (IInterface*)(Interface1*)this) {                           \
            *iid = EIID_##Interface1;                                             \
        }                                                                         \
        else if (object == (IInterface*)(Interface2*)this) {                      \
            *iid = EIID_##Interface2;                                             \
        }                                                                         \
        else if (object == (IInterface*)(Interface3*)this) {                      \
            *iid = EIID_##Interface3;                                             \
        }                                                                         \
        else {                                                                    \
            return SupperClassName::GetInterfaceID(object, iid);                  \
        }                                                                         \
        return NOERROR;                                                           \
    }
#endif

#ifndef CAR_INTERFACE_IMPL_4
#define CAR_INTERFACE_IMPL_4(ClassName, SupperClassName, Interface1, Interface2, Interface3, Interface4) \
    UInt32 ClassName::AddRef()                                                          \
    {                                                                                   \
        return SupperClassName::AddRef();                                               \
    }                                                                                   \
                                                                                        \
    UInt32 ClassName::Release()                                                         \
    {                                                                                   \
        return SupperClassName::Release();                                              \
    }                                                                                   \
                                                                                        \
    PInterface ClassName::Probe(                                                        \
        /* [in] */ REIID riid)                                                          \
    {                                                                                   \
        if (riid == EIID_IInterface) {                                                  \
            return (IInterface*)(Interface1*)this;                                      \
        }                                                                               \
        else if (riid == EIID_##Interface1) {                                           \
            return (Interface1*)this;                                                   \
        }                                                                               \
        else if (riid == EIID_##Interface2) {                                           \
            return (Interface2*)this;                                                   \
        }                                                                               \
        else if (riid == EIID_##Interface3) {                                           \
            return (Interface3*)this;                                                   \
        }                                                                               \
        else if (riid == EIID_##Interface4) {                                           \
            return (Interface4*)this;                                                   \
        }                                                                               \
        return SupperClassName::Probe(riid);                                            \
    }                                                                                   \
                                                                                        \
    ECode ClassName::GetInterfaceID(                                                    \
        /* [in] */ IInterface* object,                                                  \
        /* [out] */ InterfaceID* iid)                                                   \
    {                                                                                   \
        VALIDATE_NOT_NULL(iid);                                                         \
                                                                                        \
        if (object == (IInterface*)(Interface1*)this) {                                 \
            *iid = EIID_##Interface1;                                                   \
        }                                                                               \
        else if (object == (IInterface*)(Interface2*)this) {                            \
            *iid = EIID_##Interface2;                                                   \
        }                                                                               \
        else if (object == (IInterface*)(Interface3*)this) {                            \
            *iid = EIID_##Interface3;                                                   \
        }                                                                               \
        else if (object == (IInterface*)(Interface4*)this) {                            \
            *iid = EIID_##Interface4;                                                   \
        }                                                                               \
        else {                                                                          \
            return SupperClassName::GetInterfaceID(object, iid);                        \
        }                                                                               \
        return NOERROR;                                                                 \
    }
#endif

#ifndef CAR_INTERFACE_IMPL_LIGHT_4
#define CAR_INTERFACE_IMPL_LIGHT_4(ClassName, SupperClassName, Interface1, Interface2, Interface3, Interface4) \
    UInt32 ClassName::AddRef()                                                                \
    {                                                                                         \
        return ElLightRefBase::AddRef();                                                      \
    }                                                                                         \
                                                                                              \
    UInt32 ClassName::Release()                                                               \
    {                                                                                         \
        return ElLightRefBase::Release();                                                     \
    }                                                                                         \
                                                                                              \
    PInterface ClassName::Probe(                                                              \
        /* [in] */ REIID riid)                                                                \
    {                                                                                         \
        if (riid == EIID_IInterface) {                                                        \
            return (IInterface*)(Interface1*)this;                                            \
        }                                                                                     \
        else if (riid == EIID_##Interface1) {                                                 \
            return (Interface1*)this;                                                         \
        }                                                                                     \
        else if (riid == EIID_##Interface2) {                                                 \
            return (Interface2*)this;                                                         \
        }                                                                                     \
        else if (riid == EIID_##Interface3) {                                                 \
            return (Interface3*)this;                                                         \
        }                                                                                     \
        else if (riid == EIID_##Interface4) {                                                 \
            return (Interface4*)this;                                                         \
        }                                                                                     \
        return SupperClassName::Probe(riid);                                                  \
    }                                                                                         \
                                                                                              \
    ECode ClassName::GetInterfaceID(                                                          \
        /* [in] */ IInterface* object,                                                        \
        /* [out] */ InterfaceID* iid)                                                         \
    {                                                                                         \
        VALIDATE_NOT_NULL(iid);                                                               \
                                                                                              \
        if (object == (IInterface*)(Interface1*)this) {                                       \
            *iid = EIID_##Interface1;                                                         \
        }                                                                                     \
        else if (object == (IInterface*)(Interface2*)this) {                                  \
            *iid = EIID_##Interface2;                                                         \
        }                                                                                     \
        else if (object == (IInterface*)(Interface3*)this) {                                  \
            *iid = EIID_##Interface3;                                                         \
        }                                                                                     \
        else if (object == (IInterface*)(Interface4*)this) {                                  \
            *iid = EIID_##Interface4;                                                         \
        }                                                                                     \
        else {                                                                                \
            return SupperClassName::GetInterfaceID(object, iid);                              \
        }                                                                                     \
        return NOERROR;                                                                       \
    }
#endif

#ifndef CAR_INTERFACE_IMPL_5
#define CAR_INTERFACE_IMPL_5(ClassName, SupperClassName, Interface1, Interface2, Interface3, Interface4, Interface5) \
    UInt32 ClassName::AddRef()                                                          \
    {                                                                                   \
        return SupperClassName::AddRef();                                               \
    }                                                                                   \
                                                                                        \
    UInt32 ClassName::Release()                                                         \
    {                                                                                   \
        return SupperClassName::Release();                                              \
    }                                                                                   \
                                                                                        \
    PInterface ClassName::Probe(                                                        \
        /* [in] */ REIID riid)                                                          \
    {                                                                                   \
        if (riid == EIID_IInterface) {                                                  \
            return (IInterface*)(Interface1*)this;                                      \
        }                                                                               \
        else if (riid == EIID_##Interface1) {                                           \
            return (Interface1*)this;                                                   \
        }                                                                               \
        else if (riid == EIID_##Interface2) {                                           \
            return (Interface2*)this;                                                   \
        }                                                                               \
        else if (riid == EIID_##Interface3) {                                           \
            return (Interface3*)this;                                                   \
        }                                                                               \
        else if (riid == EIID_##Interface4) {                                           \
            return (Interface4*)this;                                                   \
        }                                                                               \
        else if (riid == EIID_##Interface5) {                                           \
            return (Interface5*)this;                                                   \
        }                                                                               \
        return SupperClassName::Probe(riid);                                            \
    }                                                                                   \
                                                                                        \
    ECode ClassName::GetInterfaceID(                                                    \
        /* [in] */ IInterface* object,                                                  \
        /* [out] */ InterfaceID* iid)                                                   \
    {                                                                                   \
        VALIDATE_NOT_NULL(iid);                                                         \
                                                                                        \
        if (object == (IInterface*)(Interface1*)this) {                                 \
            *iid = EIID_##Interface1;                                                   \
        }                                                                               \
        else if (object == (IInterface*)(Interface2*)this) {                            \
            *iid = EIID_##Interface2;                                                   \
        }                                                                               \
        else if (object == (IInterface*)(Interface3*)this) {                            \
            *iid = EIID_##Interface3;                                                   \
        }                                                                               \
        else if (object == (IInterface*)(Interface4*)this) {                            \
            *iid = EIID_##Interface4;                                                   \
        }                                                                               \
        else if (object == (IInterface*)(Interface5*)this) {                            \
            *iid = EIID_##Interface5;                                                   \
        }                                                                               \
        else {                                                                          \
            return SupperClassName::GetInterfaceID(object, iid);                        \
        }                                                                               \
        return NOERROR;                                                                 \
    }
#endif

#ifndef CAR_INTERFACE_IMPL_6
#define CAR_INTERFACE_IMPL_6(ClassName, SupperClassName, Interface1, Interface2, Interface3, Interface4, Interface5, Interface6) \
    UInt32 ClassName::AddRef()                                                          \
    {                                                                                   \
        return SupperClassName::AddRef();                                               \
    }                                                                                   \
                                                                                        \
    UInt32 ClassName::Release()                                                         \
    {                                                                                   \
        return SupperClassName::Release();                                              \
    }                                                                                   \
                                                                                        \
    PInterface ClassName::Probe(                                                        \
        /* [in] */ REIID riid)                                                          \
    {                                                                                   \
        if (riid == EIID_IInterface) {                                                  \
            return (IInterface*)(Interface1*)this;                                      \
        }                                                                               \
        else if (riid == EIID_##Interface1) {                                           \
            return (Interface1*)this;                                                   \
        }                                                                               \
        else if (riid == EIID_##Interface2) {                                           \
            return (Interface2*)this;                                                   \
        }                                                                               \
        else if (riid == EIID_##Interface3) {                                           \
            return (Interface3*)this;                                                   \
        }                                                                               \
        else if (riid == EIID_##Interface4) {                                           \
            return (Interface4*)this;                                                   \
        }                                                                               \
        else if (riid == EIID_##Interface5) {                                           \
            return (Interface5*)this;                                                   \
        }                                                                               \
        else if (riid == EIID_##Interface6) {                                           \
            return (Interface6*)this;                                                   \
        }                                                                               \
        return SupperClassName::Probe(riid);                                            \
    }                                                                                   \
                                                                                        \
    ECode ClassName::GetInterfaceID(                                                    \
        /* [in] */ IInterface* object,                                                  \
        /* [out] */ InterfaceID* iid)                                                   \
    {                                                                                   \
        VALIDATE_NOT_NULL(iid);                                                         \
                                                                                        \
        if (object == (IInterface*)(Interface1*)this) {                                 \
            *iid = EIID_##Interface1;                                                   \
        }                                                                               \
        else if (object == (IInterface*)(Interface2*)this) {                            \
            *iid = EIID_##Interface2;                                                   \
        }                                                                               \
        else if (object == (IInterface*)(Interface3*)this) {                            \
            *iid = EIID_##Interface3;                                                   \
        }                                                                               \
        else if (object == (IInterface*)(Interface4*)this) {                            \
            *iid = EIID_##Interface4;                                                   \
        }                                                                               \
        else if (object == (IInterface*)(Interface5*)this) {                            \
            *iid = EIID_##Interface5;                                                   \
        }                                                                               \
        else if (object == (IInterface*)(Interface6*)this) {                            \
            *iid = EIID_##Interface6;                                                   \
        }                                                                               \
        else {                                                                          \
            return SupperClassName::GetInterfaceID(object, iid);                        \
        }                                                                               \
        return NOERROR;                                                                 \
    }
#endif

#ifndef CAR_INTERFACE_IMPL_7
#define CAR_INTERFACE_IMPL_7(ClassName, SupperClassName, Interface1, Interface2, Interface3, Interface4, Interface5, Interface6, Interface7) \
    UInt32 ClassName::AddRef()                                                          \
    {                                                                                   \
        return SupperClassName::AddRef();                                               \
    }                                                                                   \
                                                                                        \
    UInt32 ClassName::Release()                                                         \
    {                                                                                   \
        return SupperClassName::Release();                                              \
    }                                                                                   \
                                                                                        \
    PInterface ClassName::Probe(                                                        \
        /* [in] */ REIID riid)                                                          \
    {                                                                                   \
        if (riid == EIID_IInterface) {                                                  \
            return (IInterface*)(Interface1*)this;                                      \
        }                                                                               \
        else if (riid == EIID_##Interface1) {                                           \
            return (Interface1*)this;                                                   \
        }                                                                               \
        else if (riid == EIID_##Interface2) {                                           \
            return (Interface2*)this;                                                   \
        }                                                                               \
        else if (riid == EIID_##Interface3) {                                           \
            return (Interface3*)this;                                                   \
        }                                                                               \
        else if (riid == EIID_##Interface4) {                                           \
            return (Interface4*)this;                                                   \
        }                                                                               \
        else if (riid == EIID_##Interface5) {                                           \
            return (Interface5*)this;                                                   \
        }                                                                               \
        else if (riid == EIID_##Interface6) {                                           \
            return (Interface6*)this;                                                   \
        }                                                                               \
        else if (riid == EIID_##Interface7) {                                           \
            return (Interface7*)this;                                                   \
        }                                                                               \
        return SupperClassName::Probe(riid);                                            \
    }                                                                                   \
                                                                                        \
    ECode ClassName::GetInterfaceID(                                                    \
        /* [in] */ IInterface* object,                                                  \
        /* [out] */ InterfaceID* iid)                                                   \
    {                                                                                   \
        VALIDATE_NOT_NULL(iid);                                                         \
                                                                                        \
        if (object == (IInterface*)(Interface1*)this) {                                 \
            *iid = EIID_##Interface1;                                                   \
        }                                                                               \
        else if (object == (IInterface*)(Interface2*)this) {                            \
            *iid = EIID_##Interface2;                                                   \
        }                                                                               \
        else if (object == (IInterface*)(Interface3*)this) {                            \
            *iid = EIID_##Interface3;                                                   \
        }                                                                               \
        else if (object == (IInterface*)(Interface4*)this) {                            \
            *iid = EIID_##Interface4;                                                   \
        }                                                                               \
        else if (object == (IInterface*)(Interface5*)this) {                            \
            *iid = EIID_##Interface5;                                                   \
        }                                                                               \
        else if (object == (IInterface*)(Interface6*)this) {                            \
            *iid = EIID_##Interface6;                                                   \
        }                                                                               \
        else if (object == (IInterface*)(Interface7*)this) {                            \
            *iid = EIID_##Interface7;                                                   \
        }                                                                               \
        else {                                                                          \
            return SupperClassName::GetInterfaceID(object, iid);                        \
        }                                                                               \
        return NOERROR;                                                                 \
    }
#endif

#ifndef CAR_INTERFACE_IMPL_8
#define CAR_INTERFACE_IMPL_8(ClassName, SupperClassName, Interface1, Interface2, Interface3, Interface4, Interface5, Interface6, Interface7, Interface8) \
    UInt32 ClassName::AddRef()                                                          \
    {                                                                                   \
        return SupperClassName::AddRef();                                               \
    }                                                                                   \
                                                                                        \
    UInt32 ClassName::Release()                                                         \
    {                                                                                   \
        return SupperClassName::Release();                                              \
    }                                                                                   \
                                                                                        \
    PInterface ClassName::Probe(                                                        \
        /* [in] */ REIID riid)                                                          \
    {                                                                                   \
        if (riid == EIID_IInterface) {                                                  \
            return (IInterface*)(Interface1*)this;                                      \
        }                                                                               \
        else if (riid == EIID_##Interface1) {                                           \
            return (Interface1*)this;                                                   \
        }                                                                               \
        else if (riid == EIID_##Interface2) {                                           \
            return (Interface2*)this;                                                   \
        }                                                                               \
        else if (riid == EIID_##Interface3) {                                           \
            return (Interface3*)this;                                                   \
        }                                                                               \
        else if (riid == EIID_##Interface4) {                                           \
            return (Interface4*)this;                                                   \
        }                                                                               \
        else if (riid == EIID_##Interface5) {                                           \
            return (Interface5*)this;                                                   \
        }                                                                               \
        else if (riid == EIID_##Interface6) {                                           \
            return (Interface6*)this;                                                   \
        }                                                                               \
        else if (riid == EIID_##Interface7) {                                           \
            return (Interface7*)this;                                                   \
        }                                                                               \
        else if (riid == EIID_##Interface8) {                                           \
            return (Interface8*)this;                                                   \
        }                                                                               \
        return SupperClassName::Probe(riid);                                            \
    }                                                                                   \
                                                                                        \
    ECode ClassName::GetInterfaceID(                                                    \
        /* [in] */ IInterface* object,                                                  \
        /* [out] */ InterfaceID* iid)                                                   \
    {                                                                                   \
        VALIDATE_NOT_NULL(iid);                                                         \
                                                                                        \
        if (object == (IInterface*)(Interface1*)this) {                                 \
            *iid = EIID_##Interface1;                                                   \
        }                                                                               \
        else if (object == (IInterface*)(Interface2*)this) {                            \
            *iid = EIID_##Interface2;                                                   \
        }                                                                               \
        else if (object == (IInterface*)(Interface3*)this) {                            \
            *iid = EIID_##Interface3;                                                   \
        }                                                                               \
        else if (object == (IInterface*)(Interface4*)this) {                            \
            *iid = EIID_##Interface4;                                                   \
        }                                                                               \
        else if (object == (IInterface*)(Interface5*)this) {                            \
            *iid = EIID_##Interface5;                                                   \
        }                                                                               \
        else if (object == (IInterface*)(Interface6*)this) {                            \
            *iid = EIID_##Interface6;                                                   \
        }                                                                               \
        else if (object == (IInterface*)(Interface7*)this) {                            \
            *iid = EIID_##Interface7;                                                   \
        }                                                                               \
        else if (object == (IInterface*)(Interface8*)this) {                            \
            *iid = EIID_##Interface8;                                                   \
        }                                                                               \
        else {                                                                          \
            return SupperClassName::GetInterfaceID(object, iid);                        \
        }                                                                               \
        return NOERROR;                                                                 \
    }
#endif

#ifndef CAR_INTERFACE_IMPL_9
#define CAR_INTERFACE_IMPL_9(ClassName, SupperClassName, i1, i2, i3, i4, i5, i6, i7, i8, i9) \
    UInt32 ClassName::AddRef()                                                          \
    {                                                                                   \
        return SupperClassName::AddRef();                                               \
    }                                                                                   \
                                                                                        \
    UInt32 ClassName::Release()                                                         \
    {                                                                                   \
        return SupperClassName::Release();                                              \
    }                                                                                   \
                                                                                        \
    PInterface ClassName::Probe(                                                        \
        /* [in] */ REIID riid)                                                          \
    {                                                                                   \
        if (riid == EIID_IInterface) {                                                  \
            return (IInterface*)(i1*)this;                                              \
        }                                                                               \
        else if (riid == EIID_##i1) {                                                   \
            return (i1*)this;                                                           \
        }                                                                               \
        else if (riid == EIID_##i2) {                                                   \
            return (i2*)this;                                                           \
        }                                                                               \
        else if (riid == EIID_##i3) {                                                   \
            return (i3*)this;                                                           \
        }                                                                               \
        else if (riid == EIID_##i4) {                                                   \
            return (i4*)this;                                                           \
        }                                                                               \
        else if (riid == EIID_##i5) {                                                   \
            return (i5*)this;                                                           \
        }                                                                               \
        else if (riid == EIID_##i6) {                                                   \
            return (i6*)this;                                                           \
        }                                                                               \
        else if (riid == EIID_##i7) {                                                   \
            return (i7*)this;                                                           \
        }                                                                               \
        else if (riid == EIID_##i8) {                                                   \
            return (i8*)this;                                                           \
        }                                                                               \
        else if (riid == EIID_##i9) {                                                   \
            return (i9*)this;                                                           \
        }                                                                               \
        return SupperClassName::Probe(riid);                                            \
    }                                                                                   \
                                                                                        \
    ECode ClassName::GetInterfaceID(                                                    \
        /* [in] */ IInterface* object,                                                  \
        /* [out] */ InterfaceID* iid)                                                   \
    {                                                                                   \
        VALIDATE_NOT_NULL(iid);                                                         \
                                                                                        \
        if (object == (IInterface*)(i1*)this) {                                         \
            *iid = EIID_##i1;                                                           \
        }                                                                               \
        else if (object == (IInterface*)(i2*)this) {                                    \
            *iid = EIID_##i2;                                                           \
        }                                                                               \
        else if (object == (IInterface*)(i3*)this) {                                    \
            *iid = EIID_##i3;                                                           \
        }                                                                               \
        else if (object == (IInterface*)(i4*)this) {                                    \
            *iid = EIID_##i4;                                                           \
        }                                                                               \
        else if (object == (IInterface*)(i5*)this) {                                    \
            *iid = EIID_##i5;                                                           \
        }                                                                               \
        else if (object == (IInterface*)(i6*)this) {                                    \
            *iid = EIID_##i6;                                                           \
        }                                                                               \
        else if (object == (IInterface*)(i7*)this) {                                    \
            *iid = EIID_##i7;                                                           \
        }                                                                               \
        else if (object == (IInterface*)(i8*)this) {                                    \
            *iid = EIID_##i8;                                                           \
        }                                                                               \
        else if (object == (IInterface*)(i9*)this) {                                    \
            *iid = EIID_##i9;                                                           \
        }                                                                               \
        else {                                                                          \
            return SupperClassName::GetInterfaceID(object, iid);                        \
        }                                                                               \
        return NOERROR;                                                                 \
    }
#endif

#ifndef CAR_INTERFACE_IMPL_10
#define CAR_INTERFACE_IMPL_10(ClassName, SupperClassName, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10) \
    UInt32 ClassName::AddRef()                                                          \
    {                                                                                   \
        return SupperClassName::AddRef();                                               \
    }                                                                                   \
                                                                                        \
    UInt32 ClassName::Release()                                                         \
    {                                                                                   \
        return SupperClassName::Release();                                              \
    }                                                                                   \
                                                                                        \
    PInterface ClassName::Probe(                                                        \
        /* [in] */ REIID riid)                                                          \
    {                                                                                   \
        if (riid == EIID_IInterface) {                                                  \
            return (IInterface*)(i1*)this;                                              \
        }                                                                               \
        else if (riid == EIID_##i1) {                                                   \
            return (i1*)this;                                                           \
        }                                                                               \
        else if (riid == EIID_##i2) {                                                   \
            return (i2*)this;                                                           \
        }                                                                               \
        else if (riid == EIID_##i3) {                                                   \
            return (i3*)this;                                                           \
        }                                                                               \
        else if (riid == EIID_##i4) {                                                   \
            return (i4*)this;                                                           \
        }                                                                               \
        else if (riid == EIID_##i5) {                                                   \
            return (i5*)this;                                                           \
        }                                                                               \
        else if (riid == EIID_##i6) {                                                   \
            return (i6*)this;                                                           \
        }                                                                               \
        else if (riid == EIID_##i7) {                                                   \
            return (i7*)this;                                                           \
        }                                                                               \
        else if (riid == EIID_##i8) {                                                   \
            return (i8*)this;                                                           \
        }                                                                               \
        else if (riid == EIID_##i9) {                                                   \
            return (i9*)this;                                                           \
        }                                                                               \
        else if (riid == EIID_##i10) {                                                  \
            return (i10*)this;                                                          \
        }                                                                               \
        return SupperClassName::Probe(riid);                                            \
    }                                                                                   \
                                                                                        \
    ECode ClassName::GetInterfaceID(                                                    \
        /* [in] */ IInterface* object,                                                  \
        /* [out] */ InterfaceID* iid)                                                   \
    {                                                                                   \
        VALIDATE_NOT_NULL(iid);                                                         \
                                                                                        \
        if (object == (IInterface*)(i1*)this) {                                         \
            *iid = EIID_##i1;                                                           \
        }                                                                               \
        else if (object == (IInterface*)(i2*)this) {                                    \
            *iid = EIID_##i2;                                                           \
        }                                                                               \
        else if (object == (IInterface*)(i3*)this) {                                    \
            *iid = EIID_##i3;                                                           \
        }                                                                               \
        else if (object == (IInterface*)(i4*)this) {                                    \
            *iid = EIID_##i4;                                                           \
        }                                                                               \
        else if (object == (IInterface*)(i5*)this) {                                    \
            *iid = EIID_##i5;                                                           \
        }                                                                               \
        else if (object == (IInterface*)(i6*)this) {                                    \
            *iid = EIID_##i6;                                                           \
        }                                                                               \
        else if (object == (IInterface*)(i7*)this) {                                    \
            *iid = EIID_##i7;                                                           \
        }                                                                               \
        else if (object == (IInterface*)(i8*)this) {                                    \
            *iid = EIID_##i8;                                                           \
        }                                                                               \
        else if (object == (IInterface*)(i9*)this) {                                    \
            *iid = EIID_##i9;                                                           \
        }                                                                               \
        else if (object == (IInterface*)(i10*)this) {                                   \
            *iid = EIID_##i10;                                                          \
        }                                                                               \
        else {                                                                          \
            return SupperClassName::GetInterfaceID(object, iid);                        \
        }                                                                               \
        return NOERROR;                                                                 \
    }
#endif

#ifndef CAR_INTERFACE_IMPL_11
#define CAR_INTERFACE_IMPL_11(ClassName, SupperClassName, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11) \
    UInt32 ClassName::AddRef()                                                          \
    {                                                                                   \
        return SupperClassName::AddRef();                                               \
    }                                                                                   \
                                                                                        \
    UInt32 ClassName::Release()                                                         \
    {                                                                                   \
        return SupperClassName::Release();                                              \
    }                                                                                   \
                                                                                        \
    PInterface ClassName::Probe(                                                        \
        /* [in] */ REIID riid)                                                          \
    {                                                                                   \
        if (riid == EIID_IInterface) {                                                  \
            return (IInterface*)(i1*)this;                                              \
        }                                                                               \
        else if (riid == EIID_##i1) {                                                   \
            return (i1*)this;                                                           \
        }                                                                               \
        else if (riid == EIID_##i2) {                                                   \
            return (i2*)this;                                                           \
        }                                                                               \
        else if (riid == EIID_##i3) {                                                   \
            return (i3*)this;                                                           \
        }                                                                               \
        else if (riid == EIID_##i4) {                                                   \
            return (i4*)this;                                                           \
        }                                                                               \
        else if (riid == EIID_##i5) {                                                   \
            return (i5*)this;                                                           \
        }                                                                               \
        else if (riid == EIID_##i6) {                                                   \
            return (i6*)this;                                                           \
        }                                                                               \
        else if (riid == EIID_##i7) {                                                   \
            return (i7*)this;                                                           \
        }                                                                               \
        else if (riid == EIID_##i8) {                                                   \
            return (i8*)this;                                                           \
        }                                                                               \
        else if (riid == EIID_##i9) {                                                   \
            return (i9*)this;                                                           \
        }                                                                               \
        else if (riid == EIID_##i10) {                                                  \
            return (i10*)this;                                                          \
        }                                                                               \
        else if (riid == EIID_##i11) {                                                  \
            return (i11*)this;                                                          \
        }                                                                               \
        return SupperClassName::Probe(riid);                                            \
    }                                                                                   \
                                                                                        \
    ECode ClassName::GetInterfaceID(                                                    \
        /* [in] */ IInterface* object,                                                  \
        /* [out] */ InterfaceID* iid)                                                   \
    {                                                                                   \
        VALIDATE_NOT_NULL(iid);                                                         \
                                                                                        \
        if (object == (IInterface*)(i1*)this) {                                         \
            *iid = EIID_##i1;                                                           \
        }                                                                               \
        else if (object == (IInterface*)(i2*)this) {                                    \
            *iid = EIID_##i2;                                                           \
        }                                                                               \
        else if (object == (IInterface*)(i3*)this) {                                    \
            *iid = EIID_##i3;                                                           \
        }                                                                               \
        else if (object == (IInterface*)(i4*)this) {                                    \
            *iid = EIID_##i4;                                                           \
        }                                                                               \
        else if (object == (IInterface*)(i5*)this) {                                    \
            *iid = EIID_##i5;                                                           \
        }                                                                               \
        else if (object == (IInterface*)(i6*)this) {                                    \
            *iid = EIID_##i6;                                                           \
        }                                                                               \
        else if (object == (IInterface*)(i7*)this) {                                    \
            *iid = EIID_##i7;                                                           \
        }                                                                               \
        else if (object == (IInterface*)(i8*)this) {                                    \
            *iid = EIID_##i8;                                                           \
        }                                                                               \
        else if (object == (IInterface*)(i9*)this) {                                    \
            *iid = EIID_##i9;                                                           \
        }                                                                               \
        else if (object == (IInterface*)(i10*)this) {                                   \
            *iid = EIID_##i10;                                                          \
        }                                                                               \
        else if (object == (IInterface*)(i11*)this) {                                   \
            *iid = EIID_##i11;                                                          \
        }                                                                               \
        else {                                                                          \
            return SupperClassName::GetInterfaceID(object, iid);                        \
        }                                                                               \
        return NOERROR;                                                                 \
    }
#endif

#define CAR_MACRO_CONCATENATE(arg1, arg2)   arg1##arg2
#define CAR_MACRO_NARG(...) CAR_MACRO_NARG_(__VA_ARGS__, CAR_MACRO_RSEQ_N())
#define CAR_MACRO_NARG_(...) CAR_MACRO_ARG_N(__VA_ARGS__)
#define CAR_MACRO_ARG_N(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, N, ...) N
#define CAR_MACRO_RSEQ_N() 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0

#define CAR_INTERFACE_IMPL_(N, ClassName, SupperClassName, ...) CAR_MACRO_CONCATENATE(CAR_INTERFACE_IMPL_, N)(ClassName, SupperClassName, __VA_ARGS__)
#define CAR_INTERFACE_IMPL(ClassName, SupperClassName, ...) CAR_INTERFACE_IMPL_(CAR_MACRO_NARG(__VA_ARGS__), ClassName, SupperClassName, __VA_ARGS__)

#define CAR_INTERFACE_IMPL_LIGHT_(N, ClassName, SupperClassName, ...) CAR_MACRO_CONCATENATE(CAR_INTERFACE_IMPL_LIGHT_, N)(ClassName, SupperClassName, __VA_ARGS__)
#define CAR_INTERFACE_IMPL_LIGHT(ClassName, SupperClassName, ...) CAR_INTERFACE_IMPL_LIGHT_(CAR_MACRO_NARG(__VA_ARGS__), ClassName, SupperClassName, __VA_ARGS__)


// Car object decls and impls
//
#ifndef CAR_OBJECT_DECL
#define CAR_OBJECT_DECL()                                                               \
    CARAPI Aggregate(                                                                   \
        /* [in] */ AggregateType type,                                                  \
        /* [in] */ IInterface* object);                                                 \
                                                                                        \
    CARAPI GetDomain(                                                                   \
        /* [out] */ IInterface** object);                                               \
                                                                                        \
    CARAPI GetClassID(                                                                  \
        /* [out] */ ClassID* clsid);
#endif

#ifndef CAR_OBJECT_IMPL
#define CAR_OBJECT_IMPL(ClassName)                                                      \
    ECode ClassName::Aggregate(                                                         \
        /* [in] */ AggregateType type,                                                  \
        /* [in] */ IInterface* object)                                                  \
    {                                                                                   \
        return E_NOT_IMPLEMENTED;                                                       \
    }                                                                                   \
                                                                                        \
    ECode ClassName::GetDomain(                                                         \
        /* [out] */ IInterface** object)                                                \
    {                                                                                   \
        return E_NOT_IMPLEMENTED;                                                       \
    }                                                                                   \
                                                                                        \
    ECode ClassName::GetClassID(                                                        \
        /* [out] */ ClassID* clsid)                                                     \
    {                                                                                   \
        VALIDATE_NOT_NULL(clsid);                                                       \
                                                                                        \
        *clsid = ECLSID_##ClassName;                                                    \
        return NOERROR;                                                                 \
    }
#endif


// Car Singleton decls and impls
//
#ifndef CAR_SINGLETON_METHODS_DECL
#define CAR_SINGLETON_METHODS_DECL()                                                    \
private:                                                                                \
    CARAPI_(void) OnLastStrongRef(                                                      \
        /* [in] */ const void* id);                                                     \
                                                                                        \
    CARAPI_(SpinLock&) GetSelfSpinLock();
#endif

#ifndef CAR_SINGLETON_METHODS_IMPL
#define CAR_SINGLETON_METHODS_IMPL(ClassName)                                           \
    void ClassName::OnLastStrongRef(                                                    \
        /* [in] */ const void* id)                                                      \
    {                                                                                   \
        _##ClassName::OnLastStrongRef(id);                                              \
    }                                                                                   \
                                                                                        \
    SpinLock& ClassName::GetSelfSpinLock()                                              \
    {                                                                                   \
        return _##ClassName::GetSelfSpinLock();                                         \
    }
#endif


#ifndef CAR_SINGLETON_DECL
#define CAR_SINGLETON_DECL()                                                            \
private:                                                                                \
    CAR_SINGLETON_METHODS_DECL()                                                        \
                                                                                        \
public:                                                                                 \
    CAR_OBJECT_DECL()
#endif

#ifndef CAR_SINGLETON_IMPL
#define CAR_SINGLETON_IMPL(ClassName)                                                   \
    CAR_OBJECT_IMPL(ClassName)                                                          \
                                                                                        \
    CAR_SINGLETON_METHODS_IMPL(ClassName)
#endif

#ifndef CAR_INNER_INTERFACE_IMPL
// for define interface functions in class declare area
// only sub class of pure virtual interface need it
#define CAR_INNER_INTERFACE_IMPL(SupperClassName, InterfaceName)       \
                                                           \
    UInt32 AddRef()                                        \
    {                                                      \
        return SupperClassName::AddRef();                  \
    }                                                      \
                                                           \
    UInt32 Release()                                       \
    {                                                      \
        return SupperClassName::Release();                 \
    }                                                      \
                                                           \
    PInterface Probe(                                      \
        /* [in] */ REIID riid)                             \
    {                                                      \
        if (riid == EIID_IInterface) {                     \
            return (IInterface*)(InterfaceName*)this;      \
        }                                                  \
        else if (riid == EIID_##InterfaceName) {           \
            return (InterfaceName*)this;                   \
        }                                                  \
        return SupperClassName::Probe(riid);               \
    }                                                      \
                                                           \
    ECode GetInterfaceID(                                  \
        /* [in] */ IInterface* object,                     \
        /* [out] */ InterfaceID* iid)                      \
    {                                                      \
        VALIDATE_NOT_NULL(iid);                            \
                                                           \
        if (object == (IInterface*)(InterfaceName*)this) { \
            *iid = EIID_##InterfaceName;                   \
            return NOERROR;                                \
        }                                                  \
        return SupperClassName::GetInterfaceID(object, iid); \
    }
#endif // CAR_INNER_INTERFACE_IMPL

#endif //__ELASTOS_CORE_DEF_H__
