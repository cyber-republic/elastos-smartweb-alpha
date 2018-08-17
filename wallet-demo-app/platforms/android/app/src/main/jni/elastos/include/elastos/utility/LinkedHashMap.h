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

#ifndef __ELASTOS_UTILITY_LINKEDHASHMAP_H__
#define __ELASTOS_UTILITY_LINKEDHASHMAP_H__

#include "elastos/utility/HashMap.h"

namespace Elastos {
namespace Utility {

class ECO_PUBLIC LinkedHashMap
    : public HashMap
    , public ILinkedHashMap
{
private:
    /**
     * LinkedEntry adds nxt/prv double-links to plain HashMapEntry.
     */
    class ECO_LOCAL LinkedEntry
        : public HashMapEntry
    {
    public:
        /** Create the header entry */
        LinkedEntry()
            : HashMapEntry(NULL, NULL, 0, NULL)
        {
            mNxt = this;
            mPrv = this;
        }

        /** Create a normal entry */
        LinkedEntry(
            /* [in] */ IInterface* key,
            /* [in] */ IInterface* value,
            /* [in] */ Int32 hash,
            /* [in] */ HashMapEntry* next,
            /* [in] */ LinkedEntry* nxt,
            /* [in] */ LinkedEntry* prv)
            : HashMapEntry(key, value, hash, next)
        {
            mNxt = nxt;
            mPrv = prv;
        }

    public:
        AutoPtr<LinkedEntry> mNxt;
        AutoPtr<LinkedEntry> mPrv;
    };

    class ECO_LOCAL LinkedHashIterator
        : public Object
        , public IIterator
    {
    protected:
        LinkedHashIterator(
            /* [in] */ LinkedHashMap* host);

    public:
        CAR_INTERFACE_DECL()

        CARAPI HasNext(
            /* [out] */ Boolean* value);

        CARAPI NextEntry(LinkedEntry** outface);

        CARAPI Remove();

    public:
        AutoPtr<LinkedEntry> mNext;
        AutoPtr<LinkedEntry> mLastReturned;
        Int32 mExpectedModCount;
        AutoPtr<LinkedHashMap> mHost;
    };

    class ECO_LOCAL KeyIterator
        : public LinkedHashIterator
    {
    public:
        KeyIterator(
            /* [in] */ LinkedHashMap* host);

        CARAPI GetNext(
            /* [out] */ IInterface** outface);
    };

    class ECO_LOCAL ValueIterator
        : public LinkedHashIterator
    {
    public:
        ValueIterator(
            /* [in] */ LinkedHashMap* host);

        CARAPI GetNext(
            /* [out] */ IInterface** outface);
    };

    class ECO_LOCAL EntryIterator : public LinkedHashIterator
    {
    public:
        EntryIterator(
            /* [in] */ LinkedHashMap* host);

        CARAPI GetNext(
            /* [out] */ IInterface** outface);
    };

public:
    CAR_INTERFACE_DECL()

    ~LinkedHashMap();

    /**
     * Constructs a new empty {@code LinkedHashMap} instance.
     */
    CARAPI constructor();

    /**
     * Constructs a new {@code LinkedHashMap} instance with the specified
     * capacity.
     *
     * @param initialCapacity
     *            the initial capacity of this map.
     * @exception IllegalArgumentException
     *                when the capacity is less than zero.
     */
    CARAPI constructor(
        /* [in] */ Int32 initialCapacity);

    /**
     * Constructs a new {@code LinkedHashMap} instance with the specified
     * capacity and load factor.
     *
     * @param initialCapacity
     *            the initial capacity of this map.
     * @param loadFactor
     *            the initial load factor.
     * @throws IllegalArgumentException
     *             when the capacity is less than zero or the load factor is
     *             less or equal to zero.
     */
    CARAPI constructor(
        /* [in] */ Int32 initialCapacity,
        /* [in] */ Float loadFactor);

    /**
     * Constructs a new {@code LinkedHashMap} instance with the specified
     * capacity, load factor and a flag specifying the ordering behavior.
     *
     * @param initialCapacity
     *            the initial capacity of this hash map.
     * @param loadFactor
     *            the initial load factor.
     * @param accessOrder
     *            {@code true} if the ordering should be done based on the last
     *            access (from least-recently accessed to most-recently
     *            accessed), and {@code false} if the ordering should be the
     *            order in which the entries were inserted.
     * @throws IllegalArgumentException
     *             when the capacity is less than zero or the load factor is
     *             less or equal to zero.
     */
    CARAPI constructor(
        /* [in] */ Int32 initialCapacity,
        /* [in] */ Float loadFactor,
        /* [in] */ Boolean accessOrder);

    /**
     * Constructs a new {@code LinkedHashMap} instance containing the mappings
     * from the specified map. The order of the elements is preserved.
     *
     * @param map
     *            the mappings to add.
     */
    CARAPI constructor(
        /* [in] */ IMap* map);

    /**
     * Removes all elements from this {@code Map}, leaving it empty.
     *
     * @throws UnsupportedOperationException
     *                if removing elements from this {@code Map} is not supported.
     * @see #isEmpty()
     * @see #size()
     */
    CARAPI Clear();

    /**
     * Returns whether this {@code Map} contains the specified key.
     *
     * @param key
     *            the key to search for.
     * @return {@code true} if this map contains the specified key,
     *         {@code false} otherwise.
     */
    CARAPI ContainsKey(
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
    CARAPI ContainsValue(
        /* [in] */ IInterface* value,
        /* [out] */ Boolean* result);

    /**
     * Returns a {@code Set} containing all of the mappings in this {@code Map}. Each mapping is
     * an instance of {@link Map.Entry}. As the {@code Set} is backed by this {@code Map},
     * changes in one will be reflected in the other.
     *
     * @return a set of the mappings
     */
    CARAPI GetEntrySet(
        /* [out] */ ISet** entries);

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
    CARAPI Equals(
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
    CARAPI Get(
        /* [in] */ PInterface key,
        /* [out] */ PInterface* value);

    /**
     * Returns an integer hash code for the receiver. {@code Object}s which are equal
     * return the same value for this method.
     *
     * @return the receiver's hash.
     * @see #equals(Object)
     */
    CARAPI GetHashCode(
        /* [out] */ Int32* hashCode);

    /**
     * Returns whether this map is empty.
     *
     * @return {@code true} if this map has no elements, {@code false}
     *         otherwise.
     * @see #size()
     */
    CARAPI IsEmpty(
        /* [out] */ Boolean* result);

    /**
     * Returns a set of the keys contained in this {@code Map}. The {@code Set} is backed by
     * this {@code Map} so changes to one are reflected by the other. The {@code Set} does not
     * support adding.
     *
     * @return a set of the keys.
     */
    CARAPI GetKeySet(
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
    CARAPI Put(
        /* [in] */ PInterface key,
        /* [in] */ PInterface value,
        /* [out] */ PInterface* oldValue);

    CARAPI Put(
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
    CARAPI PutAll(
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
    CARAPI Remove(
        /* [in] */ PInterface key,
        /* [out] */ PInterface* value);

    CARAPI Remove(
        /* [in] */ PInterface key);

    /**
     * Returns the number of mappings in this {@code Map}.
     *
     * @return the number of mappings in this {@code Map}.
     */
    CARAPI GetSize(
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
    CARAPI GetValues(
        /* [out] */ ICollection** value);

    /**
     * Returns a shallow copy of this map.
     *
     * @return a shallow copy of this map.
     */
    CARAPI Clone(
        /* [out] */ IInterface** object);

    /**
     * This method is called from the pseudo-constructors (clone and readObject)
     * prior to invoking constructorPut/constructorPutAll, which invoke the
     * overridden constructorNewEntry method. Normally it is a VERY bad idea to
     * invoke an overridden method from a pseudo-constructor (Effective Java
     * Item 17). In this case it is unavoidable, and the init method provides a
     * workaround.
     */
    CARAPI Init_();

    /**
     * Give LinkedHashMap a chance to take action when we modify an existing
     * entry.
     *
     * @param e the entry we're about to modify.
     */
    CARAPI PreModify(
        /* [in] */ HashMapEntry* e);

    /**
     * Creates a new entry for the given key, value, hash, and index and
     * inserts it into the hash table. This method is called by put
     * (and indirectly, putAll), and overridden by LinkedHashMap. The hash
     * must incorporate the secondary hash function.
     */
    CARAPI AddNewEntry(
        /* [in] */ IInterface* key,
        /* [in] */ IInterface* value,
        /* [in] */ Int32 hash,
        /* [in] */ Int32 index);

    /**
     * Creates a new entry for the null key, and the given value and
     * inserts it into the hash table. This method is called by put
     * (and indirectly, putAll), and overridden by LinkedHashMap.
     */
    CARAPI AddNewEntryForNullKey(
        /* [in] */ IInterface* value);

    /**
     * Subclass overrides this method to unlink entry.
     */
    CARAPI PostRemove(
        /* [in] */ HashMapEntry* e);

    /**
     * Returns the eldest entry in the map, or {@code null} if the map is empty.
     * @hide
     */
    CARAPI GetEldest(
        /* [out] */ IMapEntry** outent);

    /**
     * Like newEntry, but does not perform any activity that would be
     * unnecessary or inappropriate for constructors. In this class, the
     * two methods behave identically; in LinkedHashMap, they differ.
     */
    CARAPI_(AutoPtr<HashMapEntry>) ConstructorNewEntry(
        /* [in] */ IInterface* key,
        /* [in] */ IInterface* value,
        /* [in] */ Int32 hash,
        /* [in] */ HashMapEntry* first);

protected:
    virtual CARAPI_(Boolean) RemoveEldestEntry(
        /* [in] */ IMapEntry* eldest);

    CARAPI_(AutoPtr<IIterator>) NewKeyIterator();

    CARAPI_(AutoPtr<IIterator>) NewValueIterator();

    CARAPI_(AutoPtr<IIterator>) NewEntryIterator();

private:
    /**
     * Relinks the given entry to the tail of the list. Under access ordering,
     * this method is invoked whenever the value of a  pre-existing entry is
     * read by Map.get or modified by Map.put.
     */
    ECO_LOCAL CARAPI_(void) MakeTail(
        /* [in] */ LinkedEntry* e);

private:
    /**
     * A dummy entry in the circular linked list of entries in the map.
     * The first real entry is header.nxt, and the last is header.prv.
     * If the map is empty, header.nxt == header && header.prv == header.
     */
    /* transient */ AutoPtr<LinkedEntry> mHeader;

    /**
     * True if access ordered, false if insertion ordered.
     */
    Boolean mAccessOrder;
};

} // namespace Utility
} // namespace Elastos

#endif // __ELASTOS_UTILITY__LINKEDHASHMAP_H__
