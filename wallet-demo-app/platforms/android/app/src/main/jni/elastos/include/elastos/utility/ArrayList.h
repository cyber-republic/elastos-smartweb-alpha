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

#ifndef __ELASTOS_UTILITY_ARRAYLIST_H__
#define __ELASTOS_UTILITY_ARRAYLIST_H__

#include "elastos/utility/AbstractList.h"

using Elastos::Core::ICloneable;
//using Elastos::IO::IObjectOutputStream;
//using Elastos::IO::IObjectInputStream;
using Elastos::IO::ISerializable;
using Elastos::Utility::AbstractList;

namespace Elastos {
namespace Utility {

class ECO_PUBLIC ArrayList
    : public AbstractList
    , public IArrayList
    , public ICloneable
    , public ISerializable
    , public IRandomAccess
{
public:
    class ECO_LOCAL ArrayListIterator
        : public Object
        , public IIterator
    {
    public:
        CAR_INTERFACE_DECL()

        ArrayListIterator();

        CARAPI constructor(
            /* [in] */ IArrayList* owner);

        CARAPI HasNext(
            /* [out] */ Boolean* result);

        CARAPI GetNext(
            /* [out] */ IInterface** object);;

        CARAPI Remove();

    private:
        /** Number of elements remaining in this iteration */
        Int32 mRemaining;

        /** Index of element that remove() would remove, or -1 if no such elt */
        Int32 mRemovalIndex;

        /** The expected modCount value */
        Int32 mExpectedModCount;

        AutoPtr<ArrayList> mOwner;
    };

public:
    CAR_INTERFACE_DECL()

    ArrayList();

    CARAPI constructor();

    CARAPI constructor(
        /* [in] */ Int32 capacity);

    CARAPI constructor(
        /* [in] */ ICollection* collection);

    CARAPI Add(
        /* [in] */ IInterface* object,
        /* [out] */ Boolean* modified);

    CARAPI Add(
        /* [in] */ Int32 location,
        /* [in] */ IInterface* object);

    CARAPI AddAll(
        /* [in] */ ICollection* collection,
        /* [out] */ Boolean* modified);

    CARAPI AddAll(
        /* [in] */ Int32 location,
        /* [in] */ ICollection* collection,
        /* [out] */ Boolean* modified);

    CARAPI Clear();

    CARAPI Clone(
        /* [out] */ IInterface** object);

    CARAPI EnsureCapacity(
        /* [in] */ Int32 minimumCapacity);

    CARAPI Get(
        /* [in] */ Int32 location,
        /* [out] */ IInterface** object);

    CARAPI GetSize(
        /* [out] */ Int32* size);

    CARAPI IsEmpty(
        /* [out] */ Boolean* result);

    CARAPI Contains(
        /* [in] */ IInterface* object,
        /* [out] */ Boolean* result);

    CARAPI IndexOf(
        /* [in] */ IInterface* object,
        /* [out] */ Int32* index);

    CARAPI LastIndexOf(
        /* [in] */ IInterface* object,
        /* [out] */ Int32* index);

    CARAPI Remove(
        /* [in] */ Int32 location,
        /* [out] */ IInterface** object);

    CARAPI Remove(
        /* [in] */ IInterface* object,
        /* [out] */ Boolean* modified);

    CARAPI Set(
        /* [in] */ Int32 location,
        /* [in] */ IInterface* object,
        /* [out] */ IInterface** prevObject);

    CARAPI ToArray(
        /* [out, callee] */ ArrayOf<IInterface*>** array);

    CARAPI ToArray(
        /* [in] */ ArrayOf<IInterface*>* inArray,
        /* [out, callee] */ ArrayOf<IInterface*>** outArray);

    CARAPI TrimToSize();

    CARAPI GetIterator(
        /* [out] */ IIterator** it);

    CARAPI GetHashCode(
        /* [out] */ Int32* hashCode);

    CARAPI Equals(
        /* [in] */ IInterface* object,
        /* [out] */ Boolean* result);

    CARAPI ContainsAll(
        /* [in] */ ICollection* collection,
        /* [out] */ Boolean* result);

    CARAPI RemoveAll(
        /* [in] */ ICollection* collection,
        /* [out] */ Boolean* modified);

    CARAPI RetainAll(
        /* [in] */ ICollection* collection,
        /* [out] */ Boolean* modified);

    CARAPI GetListIterator(
        /* [out] */ IListIterator** it);

    CARAPI GetListIterator(
        /* [in] */ Int32 location,
        /* [out] */ IListIterator** it);

    CARAPI GetSubList(
        /* [in] */ Int32 start,
        /* [in] */ Int32 end,
        /* [out] */ IList** subList);

    CARAPI Add(
        /* [in] */ IInterface* obj);

    CARAPI AddAll(
        /* [in] */ Int32 value,
        /* [in] */ ICollection* collection);

    CARAPI Remove(
        /* [in] */ Int32 value);

    CARAPI Set(
        /* [in] */ Int32 value,
        /* [in] */ IInterface* obj);

    CARAPI AddAll(
        /* [in] */ ICollection* collection);

    CARAPI Remove(
        /* [in] */ IInterface* obj);

    CARAPI RemoveAll(
        /* [in] */ ICollection* collection);

    CARAPI RetainAll(
        /* [in] */ ICollection* collection);

protected:
    CARAPI RemoveRange(
        /* [in] */ Int32 fromIndex,
        /* [in] */ Int32 toIndex);

    CARAPI_(String) GetClassName() { return String("CArrayList"); }

private:
    ECO_LOCAL static CARAPI_(Int32) NewCapacity(
        /* [in] */ Int32 currentCapacity);

//    ECO_LOCAL CARAPI WriteObject(
//        /* [in] */ IObjectOutputStream* stream);

//    ECO_LOCAL CARAPI ReadObject(
//        /* [in] */ IObjectInputStream* stream);

private:
    /**
     * The minimum amount by which the capacity of an ArrayList will increase.
     * This tuning parameter controls a time-space tradeoff. This value (12)
     * gives empirically good results and is arguably consistent with the。
     * RI's specified default initial capacity of 10: instead of 10, we start
     * with 0 (sans allocation) and jump to 12.
     */
    ECO_LOCAL static const Int32 MIN_CAPACITY_INCREMENT;

    // static const Int64 mSerialVersionUID; // = 8683452581122892189L;

    /**
     * The number of elements in this list.
     */
    Int32 mSize;

    /**
     * The elements in this list, followed by nulls.
     */
    /* transient */ AutoPtr< ArrayOf<IInterface*> > mArray;
};

} // namespace Utility
} // namespace Elastos

#endif // __ELASTOS_UTILITY_ARRAYLIST_H__
