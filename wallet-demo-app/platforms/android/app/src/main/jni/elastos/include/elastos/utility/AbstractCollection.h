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

#ifndef __ELASTOS_UTILITY_ABSTRACTCOLLECTION_H__
#define __ELASTOS_UTILITY_ABSTRACTCOLLECTION_H__

#include "Elastos.CoreLibrary.Utility.h"
#include "elastos/core/Object.h"

using Elastos::Core::Object;
using Elastos::Utility::ICollection;
using Elastos::Utility::IIterable;

namespace Elastos {
namespace Utility {

class ECO_PUBLIC AbstractCollection
    : public Object
    , public ICollection
    , public IIterable
{
public:
    CAR_INTERFACE_DECL()

    /**
     * Constructs a new instance of this AbstractCollection.
     */
    AbstractCollection();

    virtual ~AbstractCollection();


    CARAPI Add(
        /* [in] */ IInterface* object,
        /* [out] */ Boolean* modified);

    CARAPI Add(
        /* [in] */ IInterface* object);

    /**
     * Attempts to add all of the objects contained in {@code collection}
     * to the contents of this {@code Collection} (optional). This implementation
     * iterates over the given {@code Collection} and calls {@code add} for each
     * element. If any of these calls return {@code true}, then {@code true} is
     * returned as result of this method call, {@code false} otherwise. If this
     * {@code Collection} does not support adding elements, an {@code
     * UnsupportedOperationException} is thrown.
     * <p>
     * If the passed {@code Collection} is changed during the process of adding elements
     * to this {@code Collection}, the behavior depends on the behavior of the passed
     * {@code Collection}.
     *
     * @param collection
     *            the collection of objects.
     * @return {@code true} if this {@code Collection} is modified, {@code false}
     *         otherwise.
     * @throws UnsupportedOperationException
     *                if adding to this {@code Collection} is not supported.
     * @throws ClassCastException
     *                if the class of an object is inappropriate for this
     *                {@code Collection}.
     * @throws IllegalArgumentException
     *                if an object cannot be added to this {@code Collection}.
     * @throws NullPointerException
     *                if {@code collection} is {@code null}, or if it contains
     *                {@code null} elements and this {@code Collection} does not support
     *                such elements.
     */
    CARAPI AddAll(
        /* [in] */ ICollection* collection,
        /* [out] */ Boolean* modified);

    CARAPI AddAll(
        /* [in] */ ICollection* collection);

    /**
     * Removes all elements from this {@code Collection}, leaving it empty (optional).
     * This implementation iterates over this {@code Collection} and calls the {@code
     * remove} method on each element. If the iterator does not support removal
     * of elements, an {@code UnsupportedOperationException} is thrown.
     * <p>
     * Concrete implementations usually can clear a {@code Collection} more efficiently
     * and should therefore overwrite this method.
     *
     * @throws UnsupportedOperationException
     *                it the iterator does not support removing elements from
     *                this {@code Collection}
     * @see #iterator
     * @see #isEmpty
     * @see #size
     */
    CARAPI Clear();

    /**
     * Tests whether this {@code Collection} contains the specified object. This
     * implementation iterates over this {@code Collection} and tests, whether any
     * element is equal to the given object. If {@code object != null} then
     * {@code object.equals(e)} is called for each element {@code e} returned by
     * the iterator until the element is found. If {@code object == null} then
     * each element {@code e} returned by the iterator is compared with the test
     * {@code e == null}.
     *
     * @param object
     *            the object to search for.
     * @return {@code true} if object is an element of this {@code Collection}, {@code
     *         false} otherwise.
     * @throws ClassCastException
     *                if the object to look for isn't of the correct type.
     * @throws NullPointerException
     *                if the object to look for is {@code null} and this
     *                {@code Collection} doesn't support {@code null} elements.
     */
    CARAPI Contains(
        /* [in] */ IInterface* object,
        /* [out] */ Boolean* result);

    /**
     * Tests whether this {@code Collection} contains all objects contained in the
     * specified {@code Collection}. This implementation iterates over the specified
     * {@code Collection}. If one element returned by the iterator is not contained in
     * this {@code Collection}, then {@code false} is returned; {@code true} otherwise.
     *
     * @param collection
     *            the collection of objects.
     * @return {@code true} if all objects in the specified {@code Collection} are
     *         elements of this {@code Collection}, {@code false} otherwise.
     * @throws ClassCastException
     *                if one or more elements of {@code collection} isn't of the
     *                correct type.
     * @throws NullPointerException
     *                if {@code collection} contains at least one {@code null}
     *                element and this {@code Collection} doesn't support {@code null}
     *                elements.
     * @throws NullPointerException
     *                if {@code collection} is {@code null}.
     */
    CARAPI ContainsAll(
        /* [in] */ ICollection* collection,
        /* [out] */ Boolean* result);

    /**
     * Returns if this {@code Collection} contains no elements. This implementation
     * tests, whether {@code size} returns 0.
     *
     * @return {@code true} if this {@code Collection} has no elements, {@code false}
     *         otherwise.
     *
     * @see #size
     */
    CARAPI IsEmpty(
        /* [out] */ Boolean* result);

    /**
     * Returns an instance of {@link Iterator} that may be used to access the
     * objects contained by this {@code Collection}. The order in which the elements are
     * returned by the {@link Iterator} is not defined unless the instance of the
     * {@code Collection} has a defined order.  In that case, the elements are returned in that order.
     * <p>
     * In this class this method is declared abstract and has to be implemented
     * by concrete {@code Collection} implementations.
     *
     * @return an iterator for accessing the {@code Collection} contents.
     */
    virtual CARAPI GetIterator(
        /* [out] */ IIterator** result) = 0;

    /**
     * Removes one instance of the specified object from this {@code Collection} if one
     * is contained (optional). This implementation iterates over this
     * {@code Collection} and tests for each element {@code e} returned by the iterator,
     * whether {@code e} is equal to the given object. If {@code object != null}
     * then this test is performed using {@code object.equals(e)}, otherwise
     * using {@code object == null}. If an element equal to the given object is
     * found, then the {@code remove} method is called on the iterator and
     * {@code true} is returned, {@code false} otherwise. If the iterator does
     * not support removing elements, an {@code UnsupportedOperationException}
     * is thrown.
     *
     * @param object
     *            the object to remove.
     * @return {@code true} if this {@code Collection} is modified, {@code false}
     *         otherwise.
     * @throws UnsupportedOperationException
     *                if removing from this {@code Collection} is not supported.
     * @throws ClassCastException
     *                if the object passed is not of the correct type.
     * @throws NullPointerException
     *                if {@code object} is {@code null} and this {@code Collection}
     *                doesn't support {@code null} elements.
     */
    CARAPI Remove(
        /* [in] */ IInterface* object,
        /* [out] */ Boolean* result);

    CARAPI Remove(
        /* [in] */ IInterface* object);

    /**
     * Removes all occurrences in this {@code Collection} of each object in the
     * specified {@code Collection} (optional). After this method returns none of the
     * elements in the passed {@code Collection} can be found in this {@code Collection}
     * anymore.
     * <p>
     * This implementation iterates over this {@code Collection} and tests for each
     * element {@code e} returned by the iterator, whether it is contained in
     * the specified {@code Collection}. If this test is positive, then the {@code
     * remove} method is called on the iterator. If the iterator does not
     * support removing elements, an {@code UnsupportedOperationException} is
     * thrown.
     *
     * @param collection
     *            the collection of objects to remove.
     * @return {@code true} if this {@code Collection} is modified, {@code false}
     *         otherwise.
     * @throws UnsupportedOperationException
     *                if removing from this {@code Collection} is not supported.
     * @throws ClassCastException
     *                if one or more elements of {@code collection} isn't of the
     *                correct type.
     * @throws NullPointerException
     *                if {@code collection} contains at least one {@code null}
     *                element and this {@code Collection} doesn't support {@code null}
     *                elements.
     * @throws NullPointerException
     *                if {@code collection} is {@code null}.
     */
    CARAPI RemoveAll(
        /* [in] */ ICollection* collection,
        /* [out] */ Boolean* result);

    CARAPI RemoveAll(
        /* [in] */ ICollection* collection);

    /**
     * Removes all objects from this {@code Collection} that are not also found in the
     * {@code Collection} passed (optional). After this method returns this {@code Collection}
     * will only contain elements that also can be found in the {@code Collection}
     * passed to this method.
     * <p>
     * This implementation iterates over this {@code Collection} and tests for each
     * element {@code e} returned by the iterator, whether it is contained in
     * the specified {@code Collection}. If this test is negative, then the {@code
     * remove} method is called on the iterator. If the iterator does not
     * support removing elements, an {@code UnsupportedOperationException} is
     * thrown.
     *
     * @param collection
     *            the collection of objects to retain.
     * @return {@code true} if this {@code Collection} is modified, {@code false}
     *         otherwise.
     * @throws UnsupportedOperationException
     *                if removing from this {@code Collection} is not supported.
     * @throws ClassCastException
     *                if one or more elements of {@code collection}
     *                isn't of the correct type.
     * @throws NullPointerException
     *                if {@code collection} contains at least one
     *                {@code null} element and this {@code Collection} doesn't support
     *                {@code null} elements.
     * @throws NullPointerException
     *                if {@code collection} is {@code null}.
     */
    CARAPI RetainAll(
        /* [in] */ ICollection* collection,
        /* [out] */ Boolean* result);

    CARAPI RetainAll(
        /* [in] */ ICollection* collection);

    /**
     * Returns a count of how many objects this {@code Collection} contains.
     * <p>
     * In this class this method is declared abstract and has to be implemented
     * by concrete {@code Collection} implementations.
     *
     * @return how many objects this {@code Collection} contains, or {@code Integer.MAX_VALUE}
     *         if there are more than {@code Integer.MAX_VALUE} elements in this
     *         {@code Collection}.
     */
    virtual CARAPI GetSize(
        /* [out] */ Int32* size) = 0;

    CARAPI ToArray(
        /* [out, callee] */ ArrayOf<IInterface*>** array);

    CARAPI ToArray(
        /* [in] */ ArrayOf<IInterface*>* contents,
        /* [out, callee] */ ArrayOf<IInterface*>** outArray);

    /**
     * Returns the string representation of this {@code Collection}. The presentation
     * has a specific format. It is enclosed by square brackets ("[]"). Elements
     * are separated by ', ' (comma and space).
     *
     * @return the string representation of this {@code Collection}.
     */
    CARAPI ToString(
        /* [out] */ String* result);

    CARAPI Equals(
        /* [in] */ IInterface* object,
        /* [out] */ Boolean* result);

    CARAPI GetHashCode(
        /* [out] */ Int32* hashCode);

protected:
    virtual CARAPI_(String) GetClassName() = 0;
};

} // namespace Utility
} // namespace Elastos

#endif // __ELASTOS_UTILITY__ABSTRACTCOLLECTION_H__