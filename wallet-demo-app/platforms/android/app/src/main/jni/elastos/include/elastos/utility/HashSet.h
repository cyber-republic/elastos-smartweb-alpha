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

#ifndef __ELASTOS_UTILITY_HASHSET_H__
#define __ELASTOS_UTILITY_HASHSET_H__

#include "elastos/utility/AbstractSet.h"

using Elastos::Core::ICloneable;
//using Elastos::IO::IObjectInputStream;
//using Elastos::IO::IObjectOutputStream;
using Elastos::IO::ISerializable;

namespace Elastos {
namespace Utility {

class ECO_PUBLIC HashSet
    : public AbstractSet
    , public IHashSet
    , public ICloneable
    , public ISerializable
{
public:

    CAR_INTERFACE_DECL()

    /**
     * Adds the specified object to this {@code HashSet} if not already present.
     *
     * @param object
     *            the object to add.
     * @return {@code true} when this {@code HashSet} did not already contain
     *         the object, {@code false} otherwise
     */
    CARAPI Add(
        /* [in] */ IInterface* object,
        /* [out] */ Boolean* modified);

    /**
     * Removes all elements from this {@code Collection}, leaving it empty (optional).
     *
     * @throws UnsupportedOperationException
     *                if removing from this {@code Collection} is not supported.
     *
     * @see #isEmpty
     * @see #size
     */
    CARAPI Clear();

    /**
     * Returns a new {@code HashSet} with the same elements and size as this
     * {@code HashSet}.
     *
     * @return a shallow copy of this {@code HashSet}.
     * @see java.lang.Cloneable
     */
    // @Override
    // @SuppressWarnings("unchecked")
    CARAPI Clone(
        /* [out] */ IInterface** outface);

    /**
     * Searches this {@code HashSet} for the specified object.
     *
     * @param object
     *            the object to search for.
     * @return {@code true} if {@code object} is an element of this
     *         {@code HashSet}, {@code false} otherwise.
     */
    CARAPI Contains(
        /* [in] */ IInterface* object,
        /* [out] */ Boolean* result);

    /**
     * Returns true if this {@code HashSet} has no elements, false otherwise.
     *
     * @return {@code true} if this {@code HashSet} has no elements,
     *         {@code false} otherwise.
     * @see #size
     */
    CARAPI IsEmpty(
        /* [out] */ Boolean* result);

    /**
     * Removes the specified object from this {@code HashSet}.
     *
     * @param object
     *            the object to remove.
     * @return {@code true} if the object was removed, {@code false} otherwise.
     */
    CARAPI Remove(
        /* [in] */ IInterface* object,
        /* [out] */ Boolean* modified);

    /**
     * Returns the number of elements in this {@code HashSet}.
     *
     * @return the number of elements in this {@code HashSet}.
     */
    CARAPI GetSize(
        /* [out] */ Int32* size);

    /**
     * Returns an Iterator on the elements of this {@code HashSet}.
     *
     * @return an Iterator on the elements of this {@code HashSet}.
     * @see Iterator
     */
    CARAPI GetIterator(
        /* [out] */ IIterator** it);

    CARAPI Add(
        /* [in] */  IInterface* object);

    CARAPI AddAll(
        /* [in] */  ICollection* collection,
        /* [out] */  Boolean* modified);

    CARAPI AddAll(
        /* [in] */  ICollection* collection);

    CARAPI ContainsAll(
        /* [in] */  ICollection* collection,
        /* [out] */  Boolean* result);

    CARAPI Equals(
        /* [in] */  IInterface* object,
        /* [out] */  Boolean* result);

    CARAPI GetHashCode(
        /* [out] */  Int32* hashCode);

    CARAPI Remove(
        /* [in] */  IInterface* object);

    CARAPI RemoveAll(
        /* [in] */  ICollection* collection,
        /* [out] */  Boolean* modified);

    CARAPI RemoveAll(
        /* [in] */  ICollection* collection);

    CARAPI RetainAll(
        /* [in] */  ICollection* collection,
        /* [out] */  Boolean* modified);

    CARAPI RetainAll(
        /* [in] */  ICollection* collection);

    CARAPI ToArray(
        /* [out, callee] */ ArrayOf<IInterface*>** array);

    CARAPI ToArray(
        /* [in] */  ArrayOf<IInterface*>* inArray,
        /* [out, callee] */ ArrayOf<IInterface*>** outArray);

protected:
    HashSet() {}

    CARAPI_(String) GetClassName() { return String("HashSet"); }

public:
    /**
     * Constructs a new empty instance of {@code HashSet}.
     */
    CARAPI constructor();

    /**
     * Constructs a new instance of {@code HashSet} with the specified capacity.
     *
     * @param capacity
     *            the initial capacity of this {@code HashSet}.
     */
    CARAPI constructor(
        /* [in] */ Int32 capacity);

    /**
     * Constructs a new instance of {@code HashSet} with the specified capacity
     * and load factor.
     *
     * @param capacity
     *            the initial capacity.
     * @param loadFactor
     *            the initial load factor.
     */
    CARAPI constructor(
        /* [in] */ Int32 capacity,
        /* [in] */ Float loadFactor);

    /**
     * Constructs a new instance of {@code HashSet} containing the unique
     * elements in the specified collection.
     *
     * @param collection
     *            the collection of elements to add.
     */
    CARAPI constructor(
        /* [in] */ ICollection* collection);

    CARAPI constructor(
        /* [in] */ IMap* backingMap);

    virtual CARAPI_(AutoPtr<IMap>) CreateBackingMap(
        /* [in] */ Int32 capacity,
        /* [in] */ Float loadFactor);

private:
//    CARAPI WriteObject(
//        /* [in] */ IObjectOutputStream* stream);

    // @SuppressWarnings("unchecked")
//    CARAPI ReadObject(
//        /* [in] */ IObjectInputStream* stream);

private:
    ECO_LOCAL static const Int64 sSerialVersionUID = -5024744406713321676LL;

    /* transient */ AutoPtr<IMap> mBackingMap;
    AutoPtr<IWeakReference> mWeakThis;
};

} // namespace Utility
} // namespace Elastos

#endif // __ELASTOS_UTILITY__HASHSET_H__
