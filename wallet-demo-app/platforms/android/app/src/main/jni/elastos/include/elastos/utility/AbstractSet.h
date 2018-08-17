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

#ifndef __ELASTOS_UTILITY_ABSTRACTSET_H__
#define __ELASTOS_UTILITY_ABSTRACTSET_H__

#include "elastos/utility/AbstractCollection.h"

using Elastos::Utility::ICollection;
using Elastos::Utility::AbstractCollection;

namespace Elastos {
namespace Utility {

/**
 * An AbstractSet is an abstract implementation of the Set interface. This
 * implementation does not support adding. A subclass must implement the
 * abstract methods iterator() and size().
 *
 * @since 1.2
 */
class ECO_PUBLIC AbstractSet
    : public AbstractCollection
    , public ISet
{
public:
    CAR_INTERFACE_DECL()

    /**
     * Constructs a new instance of this AbstractSet.
     */
    AbstractSet();

    virtual ~AbstractSet();

    /**
     * Compares the specified object to this Set and returns true if they are
     * equal. The object must be an instance of Set and contain the same
     * objects.
     *
     * @param object
     *            the object to compare with this set.
     * @return {@code true} if the specified object is equal to this set,
     *         {@code false} otherwise
     * @see #hashCode
     */
    // @Override
    CARAPI Equals(
        /* [in] */ IInterface* object,
        /* [out] */ Boolean* value);

    /**
     * Returns the hash code for this set. Two set which are equal must return
     * the same value. This implementation calculates the hash code by adding
     * each element's hash code.
     *
     * @return the hash code of this set.
     * @see #equals
     */
    // @Override
    CARAPI GetHashCode(
        /* [out] */ Int32* value);

    /**
     * Removes all occurrences in this collection which are contained in the
     * specified collection.
     *
     * @param collection
     *            the collection of objects to remove.
     * @return {@code true} if this collection was modified, {@code false}
     *         otherwise.
     * @throws UnsupportedOperationException
     *                if removing from this collection is not supported.
     */
    // @Override
    CARAPI RemoveAll(
        /* [in] */ ICollection* collection,
        /* [out] */ Boolean* value);

    CARAPI GetIterator(
        /* [out] */ IIterator** it);

    CARAPI Add(
        /* [in] */ IInterface* object,
        /* [out] */ Boolean* modified);

    CARAPI Add(
        /* [in] */ IInterface* object);

    CARAPI AddAll(
        /* [in] */ ICollection* collection,
        /* [out] */ Boolean* modified);

    CARAPI AddAll(
        /* [in] */ ICollection* collection);

    CARAPI Clear();

    CARAPI Contains(
        /* [in] */ IInterface* object,
        /* [out] */ Boolean* result);

    CARAPI ContainsAll(
        /* [in] */ ICollection* collection,
        /* [out] */ Boolean* result);

    CARAPI IsEmpty(
        /* [out] */ Boolean* result);

    CARAPI Remove(
        /* [in] */ IInterface* object,
        /* [out] */ Boolean* modified);

    CARAPI Remove(
        /* [in] */ IInterface* object);

    CARAPI RemoveAll(
        /* [in] */ ICollection* collection);

    CARAPI RetainAll(
        /* [in] */ ICollection* collection,
        /* [out] */ Boolean* modified);

    CARAPI RetainAll(
        /* [in] */ ICollection* collection);

    CARAPI GetSize(
        /* [out] */ Int32* size);

    CARAPI ToArray(
        /* [out, callee] */ ArrayOf<IInterface*>** array);

    CARAPI ToArray(
        /* [in] */ ArrayOf<IInterface*>* inArray,
        /* [out, callee] */ ArrayOf<IInterface*>** outArray);
};

} // namespace Utility
} // namespace Elastos

#endif // __ELASTOS_UTILITY__ABSTRACTSET_H__
