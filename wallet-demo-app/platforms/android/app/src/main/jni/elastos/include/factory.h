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

#ifndef __CAR_FACTORY_H__
#define __CAR_FACTORY_H__

extern "C" {

typedef interface IClassObject IClassObject;
typedef interface IClassObject* PClassObject;

EXTERN_C const _ELASTOS InterfaceID EIID_IClassObject;
EXTERN_C const _ELASTOS ClassID ECLSID_CClassObject;

CAR_INTERFACE("00000001-0000-0000-C000-000000000046")
IClassObject : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    virtual CARAPI CreateObject(
        /* [in] */ PInterface outerObject,
        /* [in] */ _ELASTOS REIID riid,
        /* [out] */ PInterface* object) = 0;

    virtual CARAPI StayResident(
        /* [in] */ _ELASTOS Boolean isStayResident) = 0;
};

typedef _ELASTOS ECode (CARAPICALLTYPE *CreateObjectFunc)(PInterface* object);

class _CBaseClassObject
    : public IObject
    , public IClassObject
{
public:
    CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid);

    CARAPI_(_ELASTOS UInt32) AddRef();

    CARAPI_(_ELASTOS UInt32) Release();

    CARAPI GetInterfaceID(
        /* [in] */ IInterface* object,
        /* [out] */ _ELASTOS InterfaceID* iid);

    CARAPI Aggregate(
        /* [in] */ AggrType type,
        /* [in] */ PInterface object);

    CARAPI GetDomain(
        /* [out] */ PInterface* object);

    CARAPI GetClassID(
        /* [out] */ _ELASTOS ClassID* clsid);

    CARAPI CreateObject(
        /* [in] */ PInterface outerObject,
        /* [in] */ _ELASTOS REIID riid,
        /* [out] */ PInterface* object);

    CARAPI StayResident(
        /* [in] */ _ELASTOS Boolean isStayResident);

    _CBaseClassObject(
        /* [in] */ CreateObjectFunc fn)
        : mCreateObjectFunc(fn)
    {}

private:
    CreateObjectFunc mCreateObjectFunc;
};

struct _IInterface : IInterface {};

typedef enum _SingletonObjState_
{
    _SingletonObjState_Uninitialize,
    _SingletonObjState_Initializing,
    _SingletonObjState_Initialized,
} _SingletonObjState_;

typedef enum _InitComponentFlags_
{
    _InitComponentFlags_InitSyncLock            = 0x1,
    _InitComponentFlags_IncrementDllLockCount   = 0x2,
    _InitComponentFlags_InitCallbackLock        = 0x4,
} _InitComponentFlags_;

ELAPI_(void) IncrementDllLockCount();
ELAPI_(void) DecrementDllLockCount();

}   // extern "C"

#endif // __CAR_FACTORY_H__
