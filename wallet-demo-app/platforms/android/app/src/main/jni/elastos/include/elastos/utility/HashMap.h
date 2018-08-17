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

#ifndef __ELASTOS_UTILITY_HashMap_H__
#define __ELASTOS_UTILITY_HashMap_H__

#include "elastos/utility/AbstractMap.h"
#include "elastos/core/Object.h"

using Elastos::Core::ICloneable;
using Elastos::IO::ISerializable;
//using Elastos::IO::IObjectInputStream;
//using Elastos::IO::IObjectOutputStream;
//using Elastos::IO::IObjectStreamField;

namespace Elastos {
namespace Utility {

class ECO_PUBLIC HashMap
    : public AbstractMap
    , public IHashMap
    , public ICloneable
    , public ISerializable
{
public:
    class HashMapEntry
        : public Object
        , public IMapEntry
    {
    public:
        HashMapEntry(
            /* [in] */ IInterface* key,
            /* [in] */ IInterface* value,
            /* [in] */ Int32 hash,
            /* [in] */ HashMapEntry* next);

        CAR_INTERFACE_DECL()

        CARAPI GetKey(
            /* [out] */ PInterface* key);

        CARAPI GetValue(
            /* [out] */ PInterface* key);

        CARAPI SetValue(
            /* [in] */ IInterface* value,
            /* [out] */ IInterface** valueReplacee);

        CARAPI Equals(
            /* [in] */ IInterface* o,
            /* [out] */ Boolean* result);

        CARAPI GetHashCode(
            /* [out] */ Int32* hashCode);

        CARAPI ToString(
            /* [out] */ String *str);

    public:
        AutoPtr<IInterface> mKey;
        AutoPtr<IInterface> mValue;
        Int32 mHash;
        AutoPtr<HashMapEntry> mNext;
    };

private:
    class ECO_LOCAL HashIterator
        : public Object
    {
    public:
        HashIterator();

        HashIterator(
            /* [in] */ HashMap* host);

        virtual CARAPI HasNext(
            /* [out] */ Boolean* result);

        CARAPI_(AutoPtr<HashMapEntry>) NextEntry();

        virtual CARAPI Remove();

    public:
        Int32 mNextIndex;
        AutoPtr<HashMapEntry> mNextEntry;
        AutoPtr<HashMapEntry> mLastEntryReturned;
        Int32 mExpectedModCount;
        AutoPtr<HashMap> mHost;
    };

    class ECO_LOCAL KeyIterator
        : public HashIterator
        , public IIterator
    {
    public:
        KeyIterator(
            /* [in] */ HashMap* host);

        CAR_INTERFACE_DECL()

        CARAPI GetNext(
            /* [out] */ IInterface** object);

        CARAPI HasNext(
            /* [out] */ Boolean* result);

        CARAPI Remove();
    };

    class ECO_LOCAL ValueIterator
        : public HashIterator
        , public IIterator
    {
    public:
        ValueIterator(
            /* [in] */ HashMap* host);

        CAR_INTERFACE_DECL()

        CARAPI GetNext(
            /* [out] */ IInterface** object);

        CARAPI HasNext(
            /* [out] */ Boolean* result);

        CARAPI Remove();
    };

    class ECO_LOCAL EntryIterator
        : public HashIterator
        , public IIterator
    {
    public:
        EntryIterator(
            /* [in] */ HashMap* host);

        CAR_INTERFACE_DECL()

        CARAPI GetNext(
            /* [out] */ IInterface** object);

        CARAPI HasNext(
            /* [out] */ Boolean* result);

        CARAPI Remove();
    };

    class ECO_LOCAL _KeySet
        : public AbstractSet
    {
    public:
        _KeySet(
            /* [in] */ HashMap* host);

        CARAPI GetIterator(
            /* [out] */ IIterator** result);

        CARAPI GetSize(
            /* [out] */ Int32* size);

        CARAPI IsEmpty(
            /* [out] */ Boolean* result);

        CARAPI Contains(
            /* [in] */ IInterface* o,
            /* [out] */ Boolean* result);

        CARAPI Remove(
            /* [in] */ IInterface* o,
            /* [out] */ Boolean* result);

        CARAPI Clear();

        CARAPI Add(
            /* [in] */ IInterface* object,
            /* [out] */ Boolean* modified);

        CARAPI AddAll(
            /* [in] */ ICollection* collection,
            /* [out] */ Boolean* modified);

        CARAPI ContainsAll(
            /* [in] */ ICollection* collection,
            /* [out] */ Boolean* result);

        CARAPI RemoveAll(
            /* [in] */ ICollection* collection,
            /* [out] */ Boolean* result);

        CARAPI RetainAll(
            /* [in] */ ICollection* collection,
            /* [out] */ Boolean* result);

        CARAPI ToArray(
            /* [out, callee] */ ArrayOf<IInterface*>** array);

        CARAPI ToArray(
            /* [in] */ ArrayOf<IInterface*>* contents,
            /* [out, callee] */ ArrayOf<IInterface*>** outArray);

        CARAPI Equals(
            /* [in] */ IInterface* object,
            /* [out] */ Boolean* result);

        CARAPI GetHashCode(
            /* [out] */ Int32* hashCode);

    protected:
        CARAPI_(String) GetClassName() { return String("HashMap::KeySet"); }

    private:
        HashMap* mHost;
    };

    class ECO_LOCAL _Values
        : public AbstractCollection
    {
    public:
        _Values();

        _Values(
            /* [in] */ HashMap* host);

        CARAPI GetIterator(
            /* [out] */ IIterator** result);

        CARAPI GetSize(
            /* [out] */ Int32* size);

        CARAPI IsEmpty(
            /* [out] */ Boolean* result);

        CARAPI Contains(
            /* [in] */ IInterface* o,
            /* [out] */ Boolean* result);

        CARAPI Clear();

        CARAPI Add(
            /* [in] */ IInterface* object,
            /* [out] */ Boolean* modified);

        CARAPI AddAll(
            /* [in] */ ICollection* collection,
            /* [out] */ Boolean* modified);

        CARAPI ContainsAll(
            /* [in] */ ICollection* collection,
            /* [out] */ Boolean* result);

        CARAPI Remove(
            /* [in] */ IInterface* object,
            /* [out] */ Boolean* result);

        CARAPI RemoveAll(
            /* [in] */ ICollection* collection,
            /* [out] */ Boolean* result);

        CARAPI RetainAll(
            /* [in] */ ICollection* collection,
            /* [out] */ Boolean* result);

        CARAPI ToArray(
            /* [out, callee] */ ArrayOf<IInterface*>** array);

        CARAPI ToArray(
            /* [in] */ ArrayOf<IInterface*>* contents,
            /* [out, callee] */ ArrayOf<IInterface*>** outArray);

        CARAPI Equals(
            /* [in] */ IInterface* object,
            /* [out] */ Boolean* result);

        CARAPI GetHashCode(
            /* [out] */ Int32* hashCode);

    protected:
        CARAPI_(String) GetClassName() { return String("HashMap::Values"); }

    public:
        HashMap* mHost;
    };

    class ECO_LOCAL _EntrySet
        : public AbstractSet
    {
    public:
        _EntrySet(
            /* [in] */ HashMap* host);

        CARAPI GetIterator(
            /* [out] */ IIterator** result);

        CARAPI Contains(
            /* [in] */ IInterface* o,
            /* [out] */ Boolean* result);

        CARAPI Remove(
            /* [in] */ IInterface* o,
            /* [out] */ Boolean* result);

        CARAPI GetSize(
            /* [out] */ Int32* size);

        CARAPI IsEmpty(
            /* [out] */ Boolean* result);

        CARAPI Clear();

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
        CARAPI_(String) GetClassName() { return String("HashMap::EntrySet"); }

    private:
        HashMap* mHost;
    };

public:
    /**
     * Constructs a new empty {@code HashMap} instance.
     */
    // @SuppressWarnings("unchecked")
    CARAPI constructor();

    /**
     * Constructs a new {@code HashMap} instance with the specified capacity.
     *
     * @param capacity
     *            the initial capacity of this hash map.
     * @throws IllegalArgumentException
     *                when the capacity is less than zero.
     */
    CARAPI constructor(
        /* [in] */ Int32 capacity);

    /**
     * Constructs a new {@code HashMap} instance with the specified capacity and
     * load factor.
     *
     * @param capacity
     *            the initial capacity of this hash map.
     * @param loadFactor
     *            the initial load factor.
     * @throws IllegalArgumentException
     *                when the capacity is less than zero or the load factor is
     *                less or equal to zero or NaN.
     */
    CARAPI constructor(
        /* [in] */ Int32 capacity,
        /* [in] */ Float loadFactor);

    /**
     * Constructs a new {@code HashMap} instance containing the mappings from
     * the specified map.
     *
     * @param map
     *            the mappings to add.
     */
    CARAPI constructor(
        /* [in] */ IMap* map);

protected:
    HashMap();


    CARAPI_(String) GetClassName() { return String("HashMap"); }

public:
    CAR_INTERFACE_DECL()

    /**
     * Removes all elements from this {@code Map}, leaving it empty.
     *
     * @throws UnsupportedOperationException
     *                if removing elements from this {@code Map} is not supported.
     * @see #isEmpty()
     * @see #size()
     */
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
        /* [out] */ ISet** entries);

    CARAPI Equals(
        /* [in] */  IInterface* object,
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

    CARAPI GetHashCode(
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
     * Returns a shallow copy of this map.
     *
     * @return a shallow copy of this map.
     */
    virtual CARAPI Clone(
        /* [out] */ IInterface** object);

    /**
     * Inserts all of the elements of map into this HashMap in a manner
     * suitable for use by constructors and pseudo-constructors (i.e., clone,
     * readObject). Also used by LinkedHashMap.
     */
    virtual CARAPI ConstructorPutAll(
        /* [in] */ IMap* map);

    /**
     * Returns an appropriate capacity for the specified initial size. Does
     * not round the result up to a power of two; the caller must do this!
     * The returned value will be between 0 and MAXIMUM_CAPACITY (inclusive).
     */
    static CARAPI_(Int32) CapacityForInitSize(
        /* [in] */ Int32 size);

    /**
     * This method is called from the pseudo-constructors (clone and readObject)
     * prior to invoking constructorPut/constructorPutAll, which invoke the
     * overridden constructorNewEntry method. Normally it is a VERY bad idea to
     * invoke an overridden method from a pseudo-constructor (Effective Java
     * Item 17). In this case it is unavoidable, and the init method provides a
     * workaround.
     */
    virtual CARAPI Init_();

    /**
     * Give LinkedHashMap a chance to take action when we modify an existing
     * entry.
     *
     * @param e the entry we're about to modify.
     */
    virtual CARAPI PreModify(
        /* [in] */ HashMapEntry* e);

    /**
     * Creates a new entry for the given key, value, hash, and index and
     * inserts it into the hash table. This method is called by put
     * (and indirectly, putAll), and overridden by LinkedHashMap. The hash
     * must incorporate the secondary hash function.
     */
    virtual CARAPI AddNewEntry(
        /* [in] */ IInterface* key,
        /* [in] */ IInterface* value,
        /* [in] */ Int32 hash,
        /* [in] */ Int32 index);

    /**
     * Creates a new entry for the null key, and the given value and
     * inserts it into the hash table. This method is called by put
     * (and indirectly, putAll), and overridden by LinkedHashMap.
     */
    virtual CARAPI AddNewEntryForNullKey(
        /* [in] */ IInterface* value);

    /**
     * Like newEntry, but does not perform any activity that would be
     * unnecessary or inappropriate for constructors. In this class, the
     * two methods behave identically; in LinkedHashMap, they differ.
     */
    virtual CARAPI_(AutoPtr<HashMapEntry>) ConstructorNewEntry(
        /* [in] */ IInterface* key,
        /* [in] */ IInterface* value,
        /* [in] */ Int32 hash,
        /* [in] */ HashMapEntry* first);

    /**
     * Subclass overrides this method to unlink entry.
     */
    virtual CARAPI PostRemove(
        /* [in] */ HashMapEntry* e);

    // Subclass (LinkedHashMap) overrides these for correct iteration order
    virtual CARAPI_(AutoPtr<IIterator>) NewKeyIterator();

    virtual CARAPI_(AutoPtr<IIterator>) NewValueIterator();

    virtual CARAPI_(AutoPtr<IIterator>) NewEntryIterator();

private:
    ECO_LOCAL CARAPI_(AutoPtr<IInterface>) PutValueForNullKey(
        /* [in] */ IInterface* value);

    /**
     * This method is just like put, except that it doesn't do things that
     * are inappropriate or unnecessary for constructors and pseudo-constructors
     * (i.e., clone, readObject). In particular, this method does not check to
     * ensure that capacity is sufficient, and does not increment modCount.
     */
    ECO_LOCAL CARAPI ConstructorPut(
        /* [in] */ IInterface* key,
        /* [in] */ IInterface* value);

    /**
     * Ensures that the hash table has sufficient capacity to store the
     * specified number of mappings, with room to grow. If not, it increases the
     * capacity as appropriate. Like doubleCapacity, this method moves existing
     * entries to new buckets as appropriate. Unlike doubleCapacity, this method
     * can grow the table by factors of 2^n for n > 1. Hopefully, a single call
     * to this method will be faster than multiple calls to doubleCapacity.
     *
     *  <p>This method is called only by putAll.
     */
    ECO_LOCAL CARAPI EnsureCapacity(
        /* [in] */ Int32 numMappings);

    /**
     * Allocate a table of the given capacity and set the threshold accordingly.
     * @param newCapacity must be a power of two
     */
    ECO_LOCAL CARAPI_(AutoPtr< ArrayOf<HashMapEntry*> >) MakeTable(
        /* [in] */ Int32 newCapacity);

    /**
     * Doubles the capacity of the hash table. Existing entries are placed in
     * the correct bucket on the enlarged table. If the current capacity is,
     * MAXIMUM_CAPACITY, this method is a no-op. Returns the table, which
     * will be new unless we were already at MAXIMUM_CAPACITY.
     */
    ECO_LOCAL CARAPI_(AutoPtr< ArrayOf<HashMapEntry*> >) DoubleCapacity();

    ECO_LOCAL CARAPI_(AutoPtr<IInterface>) RemoveNullKey();

    /**
     * Returns true if this map contains the specified mapping.
     */
    ECO_LOCAL CARAPI_(Boolean) ContainsMapping(
        /* [in] */ IInterface* key,
        /* [in] */ IInterface* value);

    /**
     * Removes the mapping from key to value and returns true if this mapping
     * exists; otherwise, returns does nothing and returns false.
     */
    ECO_LOCAL CARAPI_(Boolean) RemoveMapping(
        /* [in] */ IInterface* key,
        /* [in] */ IInterface* value);

    /**
     * Applies a supplemental hash function to a given hashCode, which defends
     * against poor quality hash functions. This is critical because HashMap
     * uses power-of-two length hash tables, that otherwise encounter collisions
     * for hashCodes that do not differ in lower or upper bits.
     */
    ECO_LOCAL static CARAPI_(Int32) SecondaryHash(
        /* [in] */ Int32 h);

    /**
     * Returns the smallest power of two >= its argument, with several caveats:
     * If the argument is negative but not Integer.MIN_VALUE, the method returns
     * zero. If the argument is > 2^30 or equal to Integer.MIN_VALUE, the method
     * returns Integer.MIN_VALUE. If the argument is zero, the method returns
     * zero.
     */
    ECO_LOCAL static CARAPI_(Int32) RoundUpToPowerOfTwo(
        /* [in] */ Int32 i);

//    ECO_LOCAL CARAPI WriteObject(
//        /* [in] */ IObjectOutputStream* stream);

//    ECO_LOCAL CARAPI ReadObject(
//        /* [in] */ IObjectInputStream* stream);

public:
    /**
     * The default load factor. Note that this implementation ignores the
     * load factor, but cannot do away with it entirely because it's
     * mentioned in the API.
     *
     * <p>Note that this constant has no impact on the behavior of the program,
     * but it is emitted as part of the serialized form. The load factor of
     * .75 is hardwired into the program, which uses cheap shifts in place of
     * expensive division.
     */
    static constexpr Float DEFAULT_LOAD_FACTOR = 0.75F;

    /**
     * The hash table. If this hash map contains a mapping for null, it is
     * not represented this hash table.
     */
    /* transient */ AutoPtr< ArrayOf<HashMapEntry*> > mTable;

protected:
    /**
     * Incremented by "structural modifications" to allow (best effort)
     * detection of concurrent modification.
     */
    /* transient */ Int32 mModCount;

    /**
     * The entry representing the null key, or null if there's no such mapping.
     */
    /* transient */ AutoPtr<HashMapEntry> mEntryForNullKey;

private:
    ECO_LOCAL static const Int64 sSerialVersionUID = 362498820763181265L;

//    ECO_LOCAL static AutoPtr< ArrayOf<IObjectStreamField*> > sSerialPersistentFields;

    /**
     * Min capacity (other than zero) for a HashMap. Must be a power of two
     * greater than 1 (and less than 1 << 30).
     */
    ECO_LOCAL static const Int32 MINIMUM_CAPACITY = 4;

    /**
     * Max capacity for a HashMap. Must be a power of two >= MINIMUM_CAPACITY.
     */
    ECO_LOCAL static const Int32 MAXIMUM_CAPACITY = 1 << 30;

    /**
     * An empty table shared by all zero-capacity maps (typically from default
     * constructor). It is never written to, and replaced on first put. Its size
     * is set to half the minimum, so that the first resize will create a
     * minimum-sized table.
     */
    ECO_LOCAL static const AutoPtr< ArrayOf<HashMapEntry*> > EMPTY_TABLE; // = new HashMapEntry[MINIMUM_CAPACITY >>> 1];

    /**
     * The number of mappings in this hash map.
     */
    /* transient */ Int32 mSize;

    /**
     * The table is rehashed when its size exceeds this threshold.
     * The value of this field is generally .75 * capacity, except when
     * the capacity is zero, as described in the EMPTY_TABLE declaration
     * above.
     */
    /* transient */ Int32 mThreshold;

    // Views - lazily initialized
    /* transient */ AutoPtr<ISet> mKeySet;
    /* transient */ AutoPtr<ISet> mEntrySet;
    /* transient */ AutoPtr<ICollection> mValues;

};

} // namespace Utility
} // namespace Elastos

DEFINE_CONVERSION_FOR(Elastos::Utility::HashMap::HashMapEntry, IInterface)

#endif // __ELASTOS_UTILITY_HashMap_H__
