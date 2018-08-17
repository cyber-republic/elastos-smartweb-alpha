#ifndef __CAR_ELASTOS_DID_H__
#define __CAR_ELASTOS_DID_H__

#ifndef _NO_INCLIST
#include "elastos.h"
using namespace Elastos;
#include "Elastos.CoreLibrary.h"

#include "Elastos.Wallet.h"

#endif // !_NO_INCLIST

#ifndef __UUNM_Elastos_DID_DEFINED__
#define __UUNM_Elastos_DID_DEFINED__
#define c_pElastos_DIDUunm "libElastos.DID.so"
#endif // __UUNM_Elastos_DID_DEFINED__

#ifndef __ECLSID_CDIDChecker_DEFINED__
#define __ECLSID_CDIDChecker_DEFINED__
static const _ELASTOS ClassID ECLSID_CDIDChecker = {
    {0x0C1A1728,0x034C,0x0D09,{0xF2,0xDC,0xFF,0xD1,0xDE,0xC6,0x0D,0x19}},
    (char *)c_pElastos_DIDUunm,
    0x883b8772 };
#endif // __CLSID_CDIDChecker_DEFINED__

#ifndef __ECLSID_CDIDCheckerClassObject_DEFINED__
#define __ECLSID_CDIDCheckerClassObject_DEFINED__
static const _ELASTOS ClassID ECLSID_CDIDCheckerClassObject = {
    {0xDAF92224,0x034C,0x0D09,{0xF2,0xDC,0xD7,0x63,0xF4,0x47,0x7B,0x1B}},
    (char *)c_pElastos_DIDUunm,
    0x883b8772 };
#endif // __CLSID_CDIDCheckerClassObject_DEFINED__

#ifndef __ECLSID_CDIDManager_DEFINED__
#define __ECLSID_CDIDManager_DEFINED__
static const _ELASTOS ClassID ECLSID_CDIDManager = {
    {0x150B1733,0x034C,0x0D09,{0x56,0xFE,0x68,0x6F,0xE3,0x86,0x0C,0x1B}},
    (char *)c_pElastos_DIDUunm,
    0x883b8772 };
#endif // __CLSID_CDIDManager_DEFINED__

#ifndef __ECLSID_CDIDManagerClassObject_DEFINED__
#define __ECLSID_CDIDManagerClassObject_DEFINED__
static const _ELASTOS ClassID ECLSID_CDIDManagerClassObject = {
    {0xE3EA223C,0x034C,0x0D09,{0x56,0xEA,0x31,0xFA,0xA3,0xBD,0x8D,0x1B}},
    (char *)c_pElastos_DIDUunm,
    0x883b8772 };
#endif // __CLSID_CDIDManagerClassObject_DEFINED__

#ifndef __EIID_IDID_DEFINED__
#define __EIID_IDID_DEFINED__
static const _ELASTOS InterfaceID EIID_IDID = \
    {0x8EBC603D,0x0352,0x0D09,{0x7E,0x90,0x6B,0x20,0xA1,0x41,0x50,0xCD}};
#endif // __IID_IDID_DEFINED__

#ifndef __EIID_IDIDManagerCallback_DEFINED__
#define __EIID_IDIDManagerCallback_DEFINED__
static const _ELASTOS InterfaceID EIID_IDIDManagerCallback = \
    {0xDB6D252D,0x0352,0x0D09,{0x56,0xC6,0xF9,0xC1,0x34,0x1E,0x6B,0x1C}};
#endif // __IID_IDIDManagerCallback_DEFINED__

#ifndef __EIID_IDIDManager_DEFINED__
#define __EIID_IDIDManager_DEFINED__
static const _ELASTOS InterfaceID EIID_IDIDManager = \
    {0xF8FF5127,0x0352,0x0D09,{0x56,0xFE,0xB0,0xD4,0x40,0x42,0x03,0x72}};
#endif // __IID_IDIDManager_DEFINED__

#ifndef __EIID_IDIDChecker_DEFINED__
#define __EIID_IDIDChecker_DEFINED__
static const _ELASTOS InterfaceID EIID_IDIDChecker = \
    {0x150A4A3D,0x0352,0x0D09,{0xF2,0xDC,0xFF,0x41,0xEE,0x3B,0xB9,0x08}};
#endif // __IID_IDIDChecker_DEFINED__

#ifndef __EIID_ICDIDCheckerClassObject_DEFINED__
#define __EIID_ICDIDCheckerClassObject_DEFINED__
static const _ELASTOS InterfaceID EIID_ICDIDCheckerClassObject = \
    {0x124B5839,0x8312,0x1206,{0x1A,0xE4,0xB9,0xAF,0xC7,0xE8,0x0F,0x4B}};
#endif // __IID_ICDIDCheckerClassObject_DEFINED__

#ifndef __EIID_ICDIDManagerClassObject_DEFINED__
#define __EIID_ICDIDManagerClassObject_DEFINED__
static const _ELASTOS InterfaceID EIID_ICDIDManagerClassObject = \
    {0xE2C76128,0x8312,0x1206,{0x1A,0xAC,0xD4,0x63,0xF4,0x87,0x25,0xA3}};
#endif // __IID_ICDIDManagerClassObject_DEFINED__

interface IDID;
interface IDIDManagerCallback;
interface IDIDManager;
interface IDIDChecker;
interface ICDIDCheckerClassObject;
interface ICDIDManagerClassObject;





#ifdef __ELASTOS_DID_USER_TYPE_H__
#include "Elastos.DID_user_type.h"
#endif
ELAPI _Impl_AcquireCallbackHandler(PInterface pServerObj, _ELASTOS REIID iid, PInterface *ppHandler);
ELAPI _Impl_CheckClsId(PInterface pServerObj, const _ELASTOS ClassID* pClassid, PInterface *ppServerObj);

CAR_INTERFACE("8EBC603D-0352-0D09-7E90-6B20A14150CD")
IDID : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDID*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDID*)pObj->Probe(EIID_IDID);
    }

    static CARAPI_(IDID*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDID*)pObj->Probe(EIID_IDID);
    }

    static CARAPI_(IDID*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetDIDName(
        /* [out] */ _ELASTOS String * did) = 0;

    virtual CARAPI SetValue(
        /* [in] */ const _ELASTOS String& keyPath,
        /* [in] */ const _ELASTOS String& valueJson) = 0;

    virtual CARAPI GetValue(
        /* [in] */ const _ELASTOS String& keyPath,
        /* [out] */ _ELASTOS String * valueJson) = 0;

    virtual CARAPI GetHistoryValue(
        /* [in] */ const _ELASTOS String& keyPath,
        /* [out] */ _ELASTOS String * valuesListJson) = 0;

    virtual CARAPI GetAllKeys(
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 count,
        /* [out] */ _ELASTOS String * keyListJson) = 0;

    virtual CARAPI Sign(
        /* [in] */ const _ELASTOS String& message,
        /* [in] */ const _ELASTOS String& password,
        /* [out] */ _ELASTOS String * signature) = 0;

    virtual CARAPI GenerateProgram(
        /* [in] */ const _ELASTOS String& message,
        /* [in] */ const _ELASTOS String& password,
        /* [out] */ _ELASTOS String * resultJson) = 0;

    virtual CARAPI CheckSign(
        /* [in] */ const _ELASTOS String& message,
        /* [in] */ const _ELASTOS String& signature,
        /* [out] */ _ELASTOS String * resultJson) = 0;

    virtual CARAPI GetPublicKey(
        /* [out] */ _ELASTOS String * publicKey) = 0;

};
CAR_INTERFACE("DB6D252D-0352-0D09-56C6-F9C1341E6B1C")
IDIDManagerCallback : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDIDManagerCallback*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDIDManagerCallback*)pObj->Probe(EIID_IDIDManagerCallback);
    }

    static CARAPI_(IDIDManagerCallback*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDIDManagerCallback*)pObj->Probe(EIID_IDIDManagerCallback);
    }

    static CARAPI_(IDIDManagerCallback*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI OnIdStatusChanged(
        /* [in] */ const _ELASTOS String& id,
        /* [in] */ const _ELASTOS String& path,
        /* [in] */ const _ELASTOS String& valueJson) = 0;

};
CAR_INTERFACE("F8FF5127-0352-0D09-56FE-B0D440420372")
IDIDManager : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDIDManager*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDIDManager*)pObj->Probe(EIID_IDIDManager);
    }

    static CARAPI_(IDIDManager*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDIDManager*)pObj->Probe(EIID_IDIDManager);
    }

    static CARAPI_(IDIDManager*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateDID(
        /* [in] */ const _ELASTOS String& password,
        /* [out] */ IDID ** did) = 0;

    virtual CARAPI GetDID(
        /* [in] */ const _ELASTOS String& didName,
        /* [out] */ IDID ** did) = 0;

    virtual CARAPI GetDIDList(
        /* [out] */ _ELASTOS String * didListJson) = 0;

    virtual CARAPI DestoryDID(
        /* [in] */ const _ELASTOS String& did) = 0;

    virtual CARAPI RegisterCallback(
        /* [in] */ const _ELASTOS String& did,
        /* [in] */ IDIDManagerCallback * didcallback) = 0;

    virtual CARAPI UnregisterCallback(
        /* [in] */ const _ELASTOS String& did) = 0;

};
CAR_INTERFACE("150A4A3D-0352-0D09-F2DC-FF41EE3BB908")
IDIDChecker : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDIDChecker*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDIDChecker*)pObj->Probe(EIID_IDIDChecker);
    }

    static CARAPI_(IDIDChecker*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDIDChecker*)pObj->Probe(EIID_IDIDChecker);
    }

    static CARAPI_(IDIDChecker*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetValue(
        /* [in] */ const _ELASTOS String& did,
        /* [in] */ const _ELASTOS String& keyPath,
        /* [out] */ _ELASTOS String * valueJson) = 0;

    virtual CARAPI GetHistoryValue(
        /* [in] */ const _ELASTOS String& did,
        /* [in] */ const _ELASTOS String& keyPath,
        /* [out] */ _ELASTOS String * valueListJson) = 0;

    virtual CARAPI GetAllKeys(
        /* [in] */ const _ELASTOS String& did,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 count,
        /* [out] */ _ELASTOS String * keyListJson) = 0;

    virtual CARAPI GetPublicKey(
        /* [in] */ const _ELASTOS String& did,
        /* [out] */ _ELASTOS String * publicKey) = 0;

    virtual CARAPI CheckSign(
        /* [in] */ const _ELASTOS String& did,
        /* [in] */ const _ELASTOS String& publicKey,
        /* [in] */ const _ELASTOS String& message,
        /* [in] */ const _ELASTOS String& signature,
        /* [out] */ _ELASTOS String * resultJson) = 0;

    virtual CARAPI CheckDID(
        /* [in] */ const _ELASTOS String& did,
        /* [in] */ const _ELASTOS String& nonce,
        /* [in] */ const _ELASTOS String& appid,
        /* [in] */ const _ELASTOS String& declaration,
        /* [in] */ const _ELASTOS String& password,
        /* [out] */ _ELASTOS String * resultJson) = 0;

};
CAR_INTERFACE("124B5839-8312-1206-1AE4-B9AFC7E80F4B")
ICDIDCheckerClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDIDCheckerClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDIDCheckerClassObject*)pObj->Probe(EIID_ICDIDCheckerClassObject);
    }

    static CARAPI_(ICDIDCheckerClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDIDCheckerClassObject*)pObj->Probe(EIID_ICDIDCheckerClassObject);
    }

    static CARAPI_(ICDIDCheckerClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
CAR_INTERFACE("E2C76128-8312-1206-1AAC-D463F48725A3")
ICDIDManagerClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDIDManagerClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDIDManagerClassObject*)pObj->Probe(EIID_ICDIDManagerClassObject);
    }

    static CARAPI_(ICDIDManagerClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDIDManagerClassObject*)pObj->Probe(EIID_ICDIDManagerClassObject);
    }

    static CARAPI_(ICDIDManagerClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithMasterWalletRootPath(
        /* [in] */ IMasterWallet * masterWallet,
        /* [in] */ const _ELASTOS String& rootPath,
        /* [out] */ IInterface ** newObj) = 0;

};
#ifndef _INSIDE_ELASTOS_DID_
class CDIDChecker
{
public:
    static _ELASTOS ECode New(
        /* [out] */ IDIDChecker** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDIDChecker, RGM_SAME_DOMAIN, EIID_IDIDChecker, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDIDChecker, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDIDChecker, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDIDChecker, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
#endif // _INSIDE_ELASTOS_DID_
#ifndef _INSIDE_ELASTOS_DID_
class CDIDManager
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ IMasterWallet * masterWallet,
        /* [in] */ const _ELASTOS String& rootPath,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDIDManagerClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDIDManager, RGM_SAME_DOMAIN,
                EIID_ICDIDManagerClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithMasterWalletRootPath(masterWallet, rootPath, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IMasterWallet * masterWallet,
        /* [in] */ const _ELASTOS String& rootPath,
        /* [out] */ IDIDManager** __IDIDManager)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(masterWallet, rootPath, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDIDManager = (IDIDManager*)__pNewObj->Probe(EIID_IDIDManager);
        if (*__IDIDManager) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IMasterWallet * masterWallet,
        /* [in] */ const _ELASTOS String& rootPath,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(masterWallet, rootPath, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IMasterWallet * masterWallet,
        /* [in] */ const _ELASTOS String& rootPath,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(masterWallet, rootPath, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IMasterWallet * masterWallet,
        /* [in] */ const _ELASTOS String& rootPath,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(masterWallet, rootPath, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
#endif // _INSIDE_ELASTOS_DID_


#endif // __CAR_ELASTOS_DID_H__
