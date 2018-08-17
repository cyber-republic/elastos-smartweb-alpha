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

/** @addtogroup SystemRef
  *   @{
  *
  * Elastos API is Elastos's core set of application programming interfaces (APIs).
  */


#ifndef __ELAPI_H__
#define __ELAPI_H__

// #include <stdint.h>

/** @} */
/** @addtogroup CARRef
  *   @{
  */
#include <eltypes.h>
#ifdef _CAR_RUNTIME
#define _NO_INCLIST
#endif
#include <elstring.h>
#include <ElastosCore.h>
#include <carapi.h>

ELAPI ECO_PUBLIC _CReflector_AcquireModuleInfo(
    /* [in] */ const _ELASTOS String& name,
    /* [out] */ IModuleInfo **piModuleInfo);

ELAPI ECO_PUBLIC _CReflector_AcquireIntrinsicTypeInfo(
    /* [in] */ CarDataType intrinsicType,
    /* [out] */ IDataTypeInfo **ppIntrinsicTypeInfo);

ELAPI ECO_PUBLIC _CReflector_AcquireEnumInfo(
    /* [in] */ const _ELASTOS String& name,
    /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> *pItemNames,
    /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int32> *pItemValues,
    /* [out] */ IEnumInfo **ppEnumInfo);

ELAPI ECO_PUBLIC _CReflector_AcquireStructInfo(
    /* [in] */ const _ELASTOS String& name,
    /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> *pFieldNames,
    /* [in] */ _ELASTOS ArrayOf<IDataTypeInfo *> *pFieldTypeInfos,
    /* [out] */ IStructInfo **ppStructInfo);

ELAPI ECO_PUBLIC _CReflector_AcquireCppVectorInfo(
    /* [in] */ IDataTypeInfo *pElementTypeInfo,
    /* [in] */ _ELASTOS Int32 length,
    /* [out] */ ICppVectorInfo **ppCppVectorInfo);

ELAPI ECO_PUBLIC _CReflector_AcquireCarArrayInfo(
    /* [in] */ CarDataType quintetType,
    /* [in] */ IDataTypeInfo *pElementTypeInfo,
    /* [out] */ ICarArrayInfo **ppCarArrayInfo);

ELAPI ECO_PUBLIC _CObject_ReflectModuleInfo(
    /* [in] */ PInterface pObj,
    /* [out] */ IModuleInfo **piModuleInfo);

ELAPI ECO_PUBLIC _CObject_ReflectClassInfo(
    /* [in] */ PInterface pObj,
    /* [out] */ IClassInfo **piClassInfo);

ELAPI ECO_PUBLIC _CObject_ReflectInterfaceInfo(
    /* [in] */ PInterface pObj,
    /* [out] */ IInterfaceInfo **piInterfaceInfo);

ELAPI_(_ELASTOS Boolean) ECO_PUBLIC _Impl_CheckHelperInfoFlag(
    /* [in] */ _ELASTOS UInt32 flag);

ELAPI_(void) ECO_PUBLIC _Impl_SetHelperInfoFlag(
    /* [in] */ _ELASTOS UInt32 flag,
    /* [in] */ _ELASTOS Boolean value);

ELAPI ECO_PUBLIC _Impl_EnterProtectedZone();

ELAPI ECO_PUBLIC _Impl_LeaveProtectedZone();

ELAPI ECO_PUBLIC _Impl_InsideProtectedZone();

// callback helper api for making parameters
ELAPI ECO_PUBLIC _Impl_CheckClsId(
    /* [in] */ PInterface pServerObj,
    /* [in] */ const _ELASTOS ClassID* pClassID,
    /* [out] */ PInterface *ppServerObj);

ELAPI ECO_PUBLIC _Impl_AcquireCallbackHandler(
    /* [in] */ PInterface pServerObj,
    /* [in] */ _ELASTOS REIID iid,
    /* [out] */  PInterface *ppHandler);

ELAPI ECO_PUBLIC _CCallbackParcel_New(
    /* [out] */ IParcel **ppObj);

ELAPI ECO_PUBLIC _CParcel_New(
    /* [out] */ IParcel **ppObj);

ELAPI ECO_PUBLIC _CObject_MarshalInterface(
    /* [in] */ IInterface *pObj,
    /* [in] */ MarshalType type,
    /* [out] */ void **ppBuf,
    /* [out] */ _ELASTOS Int32 *pSize);

ELAPI ECO_PUBLIC _CObject_UnmarshalInterface(
    /* [in] */ void *pBuf,
    /* [in] */ MarshalType type,
    /* [in] */ UnmarshalFlag flag,
    /* [out] */ IInterface **ppObj,
    /* [out] */ _ELASTOS Int32 *pSize);

ELAPI ECO_PUBLIC _CCarrier_GetInstance(
    /* [out] */ ICarrier** carrier);

ELAPI ECO_PUBLIC _CServiceManager_AcquireInstance(
    /* [out] */ IServiceManager** manager);

ELAPI ECO_PUBLIC _CJavaCarManager_AcquireInstance(
    /* [out] */ IJavaCarManager** manager);

#endif // __ELAPI_H__
/** @} */
