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

#ifndef __ELASTOS_UTILITY_ABSTRACTMAP_H__
#define __ELASTOS_UTILITY_ABSTRACTMAP_H__

#include "elastos/utility/AbstractSet.h"

using Elastos::Utility::ICollection;
using Elastos::Utility::ISet;
using Elastos::IO::ISerializable;

namespace Elastos {
namespace Utility {

/**
 * A base class for {@code Map} implementations.
 *
 * <p>Subclasses that permit new mappings to be added must override {@link
 * #put}.
 *
 * <p>The default implementations of many methods are inefficient for large
 * maps. For example in the default implementation, each call to {@link #get}
 * performs a linear iteration of the entry set. Subclasses should override such
 * methods to improve their performance.
 *
 * @since 1.2
 */
class ECO_PUBLIC AbstractMap
    : public Object
    , public IMap
{
public:

    CAR_INTERFACE_DECL()

    /**
     * An immutable key-value mapping. Despite the name, this class is non-final
     * and its subclasses may be mutable.
     *
     * @since 1.6
     */
    class SimpleImmutableEntry
        : public Object
        , public IMapEntry
        , public ISerializable
    {
    public:
        CAR_INTERFACE_DECL()

        SimpleImmutableEntry(
            /* [in] */ IInterface* theKey,
            /* [in] */ IInterface* theValue);

        /**
         * Constructs an instance with the key and value of {@code copyFrom}.
         */
        SimpleImmutableEntry(
            /* [in] */ IMapEntry* copyFrom);

        CARAPI GetKey(
            /* [out] */ PInterface* key);

        CARAPI GetValue(
            /* [out] */ PInterface* value);

        /**
         * This base implementation throws {@code UnsupportedOperationException}
         * always.
         */
        CARAPI SetValue(
            /* [in] */ IInterface* valueReplacer,
            /* [out] */ IInterface** valueReplacee);

        CARAPI Equals(
            /* [in] */ IInterface* object,
            /* [out] */ Boolean* result);

        CARAPI GetHashCode(
            /* [out] */ Int32* hashCode);

        CARAPI ToString(
            /* [out] */ String* str);

    private:
        AutoPtr<IInterface> mKey;
        AutoPtr<IInterface> mValue;
    };

    /**
     * A key-value mapping with mutable values.
     *
     * @since 1.6
     */
    class SimpleEntry
        : public Object
        , public IMapEntry
        , public ISerializable
    {
    public:
        CAR_INTERFACE_DECL()

        SimpleEntry(
            /* [in] */ IInterface* theKey,
            /* [in] */ IInterface* theValue);

        /**
         * Constructs an instance with the key and value of {@code copyFrom}.
         */
        SimpleEntry(
            /* [in] */ IMapEntry* copyFrom);

        CARAPI GetKey(
            /* [out] */ PInterface* key);

        CARAPI GetValue(
            /* [out] */ PInterface* value);

        /**
         * This base implementation throws {@code UnsupportedOperationException}
         * always.
         */
        CARAPI SetValue(
            /* [in] */ IInterface* valueReplacer,
            /* [out] */ IInterface** valueReplacee);

        CARAPI Equals(
            /* [in] */ IInterface* object,
            /* [out] */ Boolean* result);

        CARAPI GetHashCode(
            /* [out] */ Int32* hashCode);

        CARAPI ToString(
            /* [out] */ String* str);

    private:
        AutoPtr<IInterface> mKey;
        AutoPtr<IInterface> mValue;
    };

    class AbstractMapKeySet
        : public AbstractSet
    {
    public:
        CAR_INTERFACE_DECL()

        TO_STRING_IMPL("AbstractMap::AbstractMapKeySet")

        AbstractMapKeySet(
            /* [in] */ AbstractMap* hm);

        CARAPI GetSize(
            /* [out] */ Int32* value);

        CARAPI Clear();

        CARAPI Remove(
            /* [in] */ IInterface* object,
            /* [out] */ Boolean* value);

        CARAPI Contains(
            /* [in] */ IInterface* object,
            /* [out] */ Boolean* value);

        CARAPI GetIterator(
            /* [out] */ IIterator** outiter);

        CARAPI IsEmpty(
            /* [out] */ Boolean* result);

        CARAPI Add(
            /* [in] */ IInterface* object,
            /* [out] */ Boolean* modified);

        CARAPI AddAll(
            /* [in] */ ICollection* collection,
            /* [out] */ Boolean* modified);

        CARAPI ContainsAll(
            /* [in] */ ICollection* collection,
            /* [out] */ Boolean* result);

        CARAPI Equals(
            /* [in] */ IInterface* object,
            /* [out] */ Boolean* result);

        CARAPI GetHashCode(
            /* [out] */ Int32* hashCode);

        CARAPI RemoveAll(
            /* [in] */ ICollection* collection,
            /* [out] */ Boolean* modified);

        CARAPI RetainAll(
            /* [in] */ ICollection* collection,
            /* [out] */ Boolean* modified);

        CARAPI ToArray(
            /* [out, callee] */ ArrayOf<IInterface*>** array);

        CARAPI ToArray(
            /* [in] */ ArrayOf<IInterface*>* inArray,
            /* [out, callee] */ ArrayOf<IInterface*>** outArray);

    protected:
        CARAPI_(String) GetClassName() { return String("AbstractMap::AbstractMapKeySet"); }

    private:
        AbstractMap* mMap;
    };

    class AbstractMapKeySetIterator
        : public Object
        , public IIterator
    {
    public:
        CAR_INTERFACE_DECL()

        TO_STRING_IMPL("AbstractMap::AbstractMapKeySetIterator")

        AbstractMapKeySetIterator(
            /* [in] */ AbstractMap* hm);

        CARAPI HasNext(
            /* [out] */ Boolean* result);

        CARAPI GetNext(
            /* [out] */ IInterface** object);

        CARAPI Remove();

    private:
        AbstractMap* mMap;
        AutoPtr<IIterator> mSetIterator;
    };

    class AbstractMapValues
        : public AbstractCollection
    {
    public:
        AbstractMapValues(
            /* [in] */ AbstractMap* hm);

        CARAPI GetSize(
            /* [out] */ Int32* value);

        CARAPI Clear();

        CARAPI Remove(
            /* [in] */ IInterface* object,
            /* [out] */ Boolean* value);

        CARAPI Contains(
            /* [in] */ IInterface* object,
            /* [out] */ Boolean* value);

        CARAPI GetIterator(
            /* [out] */ IIterator** outiter);

        CARAPI IsEmpty(
            /* [out] */ Boolean* result);

        CARAPI Add(
            /* [in] */ IInterface* object,
            /* [out] */ Boolean* modified);

        CARAPI AddAll(
            /* [in] */ ICollection* collection,
            /* [out] */ Boolean* modified);

        CARAPI ContainsAll(
            /* [in] */ ICollection* collection,
            /* [out] */ Boolean* result);

        CARAPI Equals(
            /* [in] */ IInterface* object,
            /* [out] */ Boolean* result);

        CARAPI GetHashCode(
            /* [out] */ Int32* hashCode);

        CARAPI RemoveAll(
            /* [in] */ ICollection* collection,
            /* [out] */ Boolean* modified);

        CARAPI RetainAll(
            /* [in] */ ICollection* collection,
            /* [out] */ Boolean* modified);

        CARAPI ToArray(
            /* [out, callee] */ ArrayOf<IInterface*>** array);

        CARAPI ToArray(
            /* [in] */ ArrayOf<IInterface*>* inArray,
            /* [out, callee] */ ArrayOf<IInterface*>** outArray);

    protected:
        CARAPI_(String) GetClassName() { return String("AbstractMap::AbstractMapValues"); }

    private:
        AbstractMap* mMap;
    };

    class AbstractMapValuesIterator
        : public Object
        , public IIterator
    {
    public:
        CAR_INTERFACE_DECL()

        TO_STRING_IMPL("AbstractMap::AbstractMapValuesIterator")

        AbstractMapValuesIterator(
            /* [in] */ AbstractMap* hm);

        CARAPI HasNext(
            /* [out] */ Boolean* result);

        CARAPI GetNext(
            /* [out] */ IInterface** object);

        CARAPI Remove();

    private:
        AbstractMap* mMap;
        AutoPtr<IIterator> mSetIterator;
    };

public:
    AbstractMap();

    virtual CARAPI Clear();

    /**
     * Returns whether this {@code Map} contains the specified key.
     *
     * @param key
     *            the key to search for.
     * @return {@code true} if this map contains the specified key,
     *         {@code false} otherwise.
     */
    virtual CARAPI ContainsKey(
        /* [in] */ IInterface* key,
        /* [out] */ Boolean* result);

    /**
     * Returns whether this {@code Map} contains the specified value.
     *
     * @param value
     *            the value to search for.
     * @return {@code true} if this map contains the specified value,
     *         {@code false} otherwise.
     */
    virtual CARAPI ContainsValue(
        /* [in] */ IInterface* value,
        /* [out] */ Boolean* result);

    /**
     * Returns a {@code Set} containing all of the mappings in this {@code Map}. Each mapping is
     * an instance of {@link Map.Entry}. As the {@code Set} is backed by this {@code Map},
     * changes in one will be reflected in the other.
     *
     * @return a set of the mappings
     */
    virtual CARAPI GetEntrySet(
        /* [out] */ ISet** entries) = 0;

    /**
     * Compares the argument to the receiver, and returns {@code true} if the
     * specified object is a {@code Map} and both {@code Map}s contain the same mappings.
     *
     * @param object
     *            the {@code Object} to compare with this {@code Object}.
     * @return boolean {@code true} if the {@code Object} is the same as this {@code Object}
     *         {@code false} if it is different from this {@code Object}.
     * @see #hashCode()
     * @see #entrySet()
     */
    virtual CARAPI Equals(
        /* [in] */ IInterface* object,
        /* [out] */ Boolean* result);

    /**
     * Returns the value of the mapping with the specified key.
     *
     * @param key
     *            the key.
     * @return the value of the mapping with the specified key, or {@code null}
     *         if no mapping for the specified key is found.
     */
    virtual CARAPI Get(
        /* [in] */ PInterface key,
        /* [out] */ PInterface* value);

    /**
     * Returns an integer hash code for the receiver. {@code Object}s which are equal
     * return the same value for this method.
     *
     * @return the receiver's hash.
     * @see #equals(Object)
     */
    virtual CARAPI GetHashCode(
        /* [out] */ Int32* hashCode);

    /**
     * Returns whether this map is empty.
     *
     * @return {@code true} if this map has no elements, {@code false}
     *         otherwise.
     * @see #size()
     */
    virtual CARAPI IsEmpty(
        /* [out] */ Boolean* result);

    /**
     * Returns a set of the keys contained in this {@code Map}. The {@code Set} is backed by
     * this {@code Map} so changes to one are reflected by the other. The {@code Set} does not
     * support adding.
     *
     * @return a set of the keys.
     */
    virtual CARAPI GetKeySet(
        /* [out] */ ISet** keySet);

    /**
     * Maps the specified key to the specified value.
     *
     * @param key
     *            the key.
     * @param value
     *            the value.
     * @return the value of any previous mapping with the specified key or
     *         {@code null} if there was no mapping.
     * @throws UnsupportedOperationException
     *                if adding to this {@code Map} is not supported.
     * @throws ClassCastException
     *                if the class of the key or value is inappropriate for
     *                this {@code Map}.
     * @throws IllegalArgumentException
     *                if the key or value cannot be added to this {@code Map}.
     * @throws NullPointerException
     *                if the key or value is {@code null} and this {@code Map} does
     *                not support {@code null} keys or values.
     */
    virtual CARAPI Put(
        /* [in] */ PInterface key,
        /* [in] */ PInterface value,
        /* [out] */ PInterface* oldValue);

    virtual CARAPI Put(
        /* [in] */ PInterface key,
        /* [in] */ PInterface value);

    /**
     * Copies every mapping in the specified {@code Map} to this {@code Map}.
     *
     * @param map
     *            the {@code Map} to copy mappings from.
     * @throws UnsupportedOperationException
     *                if adding to this {@code Map} is not supported.
     * @throws ClassCastException
     *                if the class of a key or a value of the specified {@code Map} is
     *                inappropriate for this {@code Map}.
     * @throws IllegalArgumentException
     *                if a key or value cannot be added to this {@code Map}.
     * @throws NullPointerException
     *                if a key or value is {@code null} and this {@code Map} does not
     *                support {@code null} keys or values.
     */
    virtual CARAPI PutAll(
        /* [in] */ IMap* map);

    /**
     * Removes a mapping with the specified key from this {@code Map}.
     *
     * @param key
     *            the key of the mapping to remove.
     * @return the value of the removed mapping or {@code null} if no mapping
     *         for the specified key was found.
     * @throws UnsupportedOperationException
     *                if removing from this {@code Map} is not supported.
     */
    virtual CARAPI Remove(
        /* [in] */ PInterface key,
        /* [out] */ PInterface* value);

    virtual CARAPI Remove(
        /* [in] */ PInterface key);

    /**
     * Returns the number of mappings in this {@code Map}.
     *
     * @return the number of mappings in this {@code Map}.
     */
    virtual CARAPI GetSize(
        /* [out] */ Int32* size);

    /**
     * Returns a {@code Collection} of the values contained in this {@code Map}. The {@code Collection}
     * is backed by this {@code Map} so changes to one are reflected by the other. The
     * {@code Collection} supports {@link Collection#remove}, {@link Collection#removeAll},
     * {@link Collection#retainAll}, and {@link Collection#clear} operations,
     * and it does not support {@link Collection#add} or {@link Collection#addAll} operations.
     * <p>
     * This method returns a {@code Collection} which is the subclass of
     * {@link AbstractCollection}. The {@link AbstractCollection#iterator} method of this subclass returns a
     * "wrapper object" over the iterator of this {@code Map}'s {@link #entrySet()}. The {@link AbstractCollection#size} method
     * wraps this {@code Map}'s {@link #size} method and the {@link AbstractCollection#contains} method wraps this {@code Map}'s
     * {@link #containsValue} method.
     * <p>
     * The collection is created when this method is called at first time and
     * returned in response to all subsequent calls. This method may return
     * different Collection when multiple calls to this method, since it has no
     * synchronization performed.
     *
     * @return a collection of the values contained in this map.
     */
    virtual CARAPI GetValues(
        /* [out] */ ICollection** value);

    /**
     * {@inheritDoc}
     *
     * <p>This implementation composes a string by iterating its entry set. If
     * this map contains itself as a key or a value, the string "(this Map)"
     * will appear in its place.
     */
    virtual CARAPI ToString(
        /* [out] */ String* str);

    // @SuppressWarnings("unchecked")
    CARAPI Clone(
        /* [out] */ IInterface** outface);

public:
    // Lazily initialized key set.
    AutoPtr<ISet> mKeySet;

    AutoPtr<ICollection> mValuesCollection;
};

} // namespace Utility
} // namespace Elastos

#endif // __ELASTOS_UTILITY_ABSTRACTMAP_H__
