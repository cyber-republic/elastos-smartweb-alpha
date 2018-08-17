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

#ifndef __ELASTOS_CORE_COREUTILS_H__
#define __ELASTOS_CORE_COREUTILS_H__

#include "elastos/core/Object.h"
#ifdef ELASTOS_CORELIBRARY
#include "elastos/core/CArrayOf.h"
#endif

using Elastos::Core::IByte;
using Elastos::Core::IChar32;
using Elastos::Core::IBoolean;
using Elastos::Core::IInteger16;
using Elastos::Core::IInteger32;
using Elastos::Core::IInteger64;
using Elastos::Core::IFloat;
using Elastos::Core::IDouble;
using Elastos::Core::ICharSequence;
using Elastos::Core::IArrayOf;
using Elastos::Core::CArrayOf;

namespace Elastos {
namespace Core {

class ECO_PUBLIC CoreUtils
{
public:
    static CARAPI_(AutoPtr<IByte>) ConvertByte(
        /* [in] */ Byte value);

    static CARAPI_(AutoPtr<IChar32>) ConvertChar32(
        /* [in] */ Char32 value);

    static CARAPI_(AutoPtr<IBoolean>) Convert(
        /* [in] */ Boolean value);

    static CARAPI_(AutoPtr<IInteger16>) Convert(
        /* [in] */ Int16 value);

    static CARAPI_(AutoPtr<IInteger32>) Convert(
        /* [in] */ Int32 value);

    static CARAPI_(Int32) Unbox(
        /* [in] */ IInteger32* value);

    static CARAPI_(AutoPtr<IInteger64>) Convert(
        /* [in] */ Int64 value);

    static CARAPI_(AutoPtr<IFloat>) Convert(
        /* [in] */ Float value);

    static CARAPI_(AutoPtr<IDouble>) Convert(
        /* [in] */ Double value);

    static CARAPI_(AutoPtr<ICharSequence>) Convert(
        /* [in] */ const String & value);

    static CARAPI_(String) Unbox(
        /* [in] */ ICharSequence* value);

    static CARAPI_(String) Unbox(
        /* [in] */ IString* value);

    static CARAPI_(AutoPtr<ICharSequence>) Convert(
        /* [in] */ const char* str);

    // Convert ArrayOf to IArrayOf
    //
    static CARAPI_(AutoPtr<IArrayOf>) ConvertByteArray(
        /* [in] */ ArrayOf<Byte>* arr);

    static CARAPI_(AutoPtr<IArrayOf>) ConvertChar32Array(
        /* [in] */ ArrayOf<Char32>* arr);

    static CARAPI_(AutoPtr<IArrayOf>) Convert(
        /* [in] */ ArrayOf<Boolean>* arr);

    static CARAPI_(AutoPtr<IArrayOf>) Convert(
        /* [in] */ ArrayOf<Int16>* arr);

    static CARAPI_(AutoPtr<IArrayOf>) Convert(
        /* [in] */ ArrayOf<Int32>* arr);

    static CARAPI_(AutoPtr<IArrayOf>) Convert(
        /* [in] */ ArrayOf<Int64>* arr);

    static CARAPI_(AutoPtr<IArrayOf>) Convert(
        /* [in] */ ArrayOf<Float>* arr);

    static CARAPI_(AutoPtr<IArrayOf>) Convert(
        /* [in] */ ArrayOf<Double>* arr);

    static CARAPI_(AutoPtr<IArrayOf>) Convert(
        /* [in] */ ArrayOf<String>* arr);

    static CARAPI_(AutoPtr<IArrayOf>) ConvertByteArray(
        /* [in] */ const AutoPtr< ArrayOf<Byte> >& arr)
    {
        return ConvertByteArray(arr.Get());
    }

    static CARAPI_(AutoPtr<IArrayOf>) ConvertChar32Array(
        /* [in] */ const AutoPtr< ArrayOf<Char32> >& arr)
    {
        return ConvertChar32Array(arr.Get());
    }

    static CARAPI_(AutoPtr<IArrayOf>) Convert(
        /* [in] */ const AutoPtr< ArrayOf<Boolean> >& arr)
    {
        return Convert(arr.Get());
    }

    static CARAPI_(AutoPtr<IArrayOf>) Convert(
        /* [in] */ const AutoPtr< ArrayOf<Int16> >& arr)
    {
        return Convert(arr.Get());
    }

    static CARAPI_(AutoPtr<IArrayOf>) Convert(
        const AutoPtr< ArrayOf<Int32> >& arr)
    {
        return Convert(arr.Get());
    }

    static CARAPI_(AutoPtr<IArrayOf>) Convert(
        const AutoPtr< ArrayOf<Int64> >& arr)
    {
        return Convert(arr.Get());
    }

    static CARAPI_(AutoPtr<IArrayOf>) Convert(
        const AutoPtr< ArrayOf<Float> >& arr)
    {
        return Convert(arr.Get());
    }

    static CARAPI_(AutoPtr<IArrayOf>) Convert(
        const AutoPtr< ArrayOf<Double> >& arr)
    {
        return Convert(arr.Get());
    }

    static CARAPI_(AutoPtr<IArrayOf>) Convert(
        const AutoPtr< ArrayOf<String> >& arr)
    {
        return Convert(arr.Get());
    }

    template<typename InterfaceType>
    static CARAPI_(AutoPtr<IArrayOf>) Convert(
        /* [in] */ ArrayOf<InterfaceType*>* arr,
        /* [in] */ const InterfaceID& iid = EIID_IInterface)
    {
        if (arr == NULL) {
            return NULL;
        }

        Int32 length = arr->GetLength();
        AutoPtr<IArrayOf> arrObj;
        CArrayOf::New(iid, length, (IArrayOf**)&arrObj);
        for (Int32 i = 0; i < length; ++i) {
            arrObj->Set(i, (*arr)[i] ? (*arr)[i]->Probe(iid) : NULL);
        }

        return arrObj;
    }

    template<typename InterfaceType>
    static CARAPI_(AutoPtr<IArrayOf>) Convert(
        /* [in] */ const AutoPtr<ArrayOf<InterfaceType*> >& arr,
        /* [in] */ const InterfaceID& iid)
    {
        return Convert<InterfaceType>(arr.Get(), iid);
    }

    // Convert IArrayOf to ArrayOf
    //
    // example: AutoPtr<ArrayOf<Byte> > array = Convert<Byte, IByte>(arrayOf);
    //
    template<typename ElementType, typename InterfaceType>
    static AutoPtr<ArrayOf<ElementType> > Convert(
        /* [in] */ IArrayOf* arrayOf)
    {
        if (arrayOf == NULL) {
            return NULL;
        }

        Int32 length;
        arrayOf->GetLength(&length);
        AutoPtr<ArrayOf<ElementType> > array = ArrayOf<ElementType>::Alloc(length);
        InterfaceID iid;
        arrayOf->GetTypeId(&iid);

        assert(iid == EIID_IByte
            || iid == EIID_IChar32
            || iid == EIID_IBoolean
            || iid == EIID_IInteger16
            || iid == EIID_IInteger32
            || iid == EIID_IInteger64
            || iid == EIID_IFloat
            || iid == EIID_IDouble);

        for (Int32 i = 0; i < length; ++i) {
            AutoPtr<IInterface> obj;
            arrayOf->Get(i, (IInterface**)&obj);
            InterfaceType* elementObj = (InterfaceType*)obj->Probe(iid);
            ElementType element;
            elementObj->GetValue(&element);
            array->Set(i, element);
        }
        return array;
    }

    template<typename InterfaceType>
    static AutoPtr<ArrayOf<InterfaceType*> > Convert(
        /* [in] */ IArrayOf* arrayOf)
    {
        if (arrayOf == NULL) {
            return NULL;
        }

        Int32 length;
        arrayOf->GetLength(&length);
        AutoPtr<ArrayOf<InterfaceType*> > array = ArrayOf<InterfaceType*>::Alloc(length);
        InterfaceID iid;
        arrayOf->GetTypeId(&iid);

        for (Int32 i = 0; i < length; ++i) {
            AutoPtr<IInterface> obj;
            arrayOf->Get(i, (IInterface**)&obj);
            array->Set(i, obj ? (InterfaceType*)obj->Probe(iid) : NULL);
        }
        return array;
    }

    static AutoPtr<ArrayOf<String> > Convert(
        /* [in] */ IArrayOf* arrayOf)
    {
        if (arrayOf == NULL) {
            return NULL;
        }

        Int32 length;
        arrayOf->GetLength(&length);
        AutoPtr<ArrayOf<String> > array = ArrayOf<String>::Alloc(length);
        for (Int32 i = 0; i < length; ++i) {
            AutoPtr<IInterface> obj;
            arrayOf->Get(i, (IInterface**)&obj);
            array->Set(i, Object::ToString(obj));
        }
        return array;
    }

private:
    template<typename T1, typename T2>
    ECO_LOCAL static CARAPI_(AutoPtr<IArrayOf>) ConvertImpl(
        /* [in] */ ArrayOf<T1>* arr,
        /* [in] */ const InterfaceID& itfc)
    {
        if (arr) {
            Int32 length = arr->GetLength();
            AutoPtr<IArrayOf> arrObj;
            CArrayOf::New(itfc, length, (IArrayOf**)&arrObj);
            for (Int32 i = 0; i < length; ++i) {
                AutoPtr<T2> item = Convert((*arr)[i]);
                arrObj->Set(i, item.Get());
            }

            return arrObj;
        }
        return NULL;
    }



private:
    ECO_LOCAL CoreUtils();
    ECO_LOCAL ~CoreUtils();
};

} // namespace Core
} // namespace Elastos

using Elastos::Core::CoreUtils;

#endif // __ELASTOS_CORE_COREUTILS_H__