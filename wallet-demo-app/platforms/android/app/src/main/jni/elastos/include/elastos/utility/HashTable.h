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

#ifndef __ELASTOS_UTILITY_HASHTABLE_H__
#define __ELASTOS_UTILITY_HASHTABLE_H__

#include "elastos/utility/AbstractSet.h"

using Elastos::Core::ICloneable;
//using Elastos::IO::IObjectInputStream;
//using Elastos::IO::IObjectOutputStream;
//using Elastos::IO::IObjectStreamField;
using Elastos::IO::ISerializable;

namespace Elastos {
namespace Utility {

/**
 * Hashtable is a synchronized implementation of {@link Map}. All optional operations are supported.
 *
 * <p>Neither keys nor values can be null. (Use {@code HashMap} or {@code LinkedHashMap} if you
 * need null keys or values.)
 *
 * @param <K> the type of keys maintained by this map
 * @param <V> the type of mapped values
 * @see HashMap
 */
class ECO_PUBLIC HashTable
    : public Object
    , public IHashTable
    , public IDictionary
    , public IMap
    , public ICloneable
    , public ISerializable
{
private:
    /**
     * Note: technically the methods of this class should synchronize the
     * backing map.  However, this would require them to have a reference
     * to it, which would cause considerable bloat.  Moreover, the RI
     * behaves the same way.
     */
    class ECO_LOCAL HashtableEntry
        : public Object
        , public IMapEntry
    {
    public:
        HashtableEntry(
            /* [in] */ IInterface* key,
            /* [in] */ IInterface* value,
            /* [in] */ Int32 hash,
            /* [in] */ HashtableEntry* next);

        CAR_INTERFACE_DECL()

        CARAPI GetKey(
            /* [out] */ IInterface** outface);

        CARAPI GetValue(
            /* [out] */ IInterface** outface);

        CARAPI SetValue(
            /* [in] */ IInterface* value,
            /* [out] */ IInterface** outface);

        CARAPI Equals(
            /* [in] */ IInterface* o,
            /* [out] */ Boolean* value);

        CARAPI GetHashCode(
            /* [out] */ Int32* value);

        CARAPI ToString(
            /* [out] */ String* str);

    public:
        AutoPtr<IInterface> mKey;
        AutoPtr<IInterface> mValue;
        Int32 mHash;
        AutoPtr<HashtableEntry> mNext;
    };

    class ECO_LOCAL HashIterator
        : public Object
    {
    public:
        HashIterator();

        HashIterator(
            /* [in] */ HashTable* host);

        CARAPI HasNext(
            /* [out] */ Boolean* value);

        CARAPI_(AutoPtr<HashtableEntry>) NextEntry();

        CARAPI_(AutoPtr<HashtableEntry>) NextEntryNotFailFast();

        CARAPI Remove();

    public:
        Int32 mNextIndex;
        AutoPtr<HashtableEntry> mNextEntry;
        AutoPtr<HashtableEntry> mLastEntryReturned;
        Int32 mExpectedModCount;
        AutoPtr<HashTable> mHost;
    };

    class ECO_LOCAL KeyIterator
        : public HashIterator
        , public IIterator
    {
    public:
        KeyIterator(
            /* [in] */ HashTable* host);

        CAR_INTERFACE_DECL()

        CARAPI GetNext(
            /* [out] */ IInterface** outface);

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
            /* [in] */ HashTable* host);

        CAR_INTERFACE_DECL()

        CARAPI GetNext(
            /* [out] */ IInterface** outface);

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
            /* [in] */ HashTable* host);

        CAR_INTERFACE_DECL()

        CARAPI GetNext(
            /* [out] */ IInterface** outface);

        CARAPI HasNext(
            /* [out] */ Boolean* result);

        CARAPI Remove();
    };

    class ECO_LOCAL KeyEnumeration
        : public HashIterator
        , public IEnumeration
    {
    public:
        KeyEnumeration(
            /* [in] */ HashTable* host);

        CAR_INTERFACE_DECL()

        CARAPI HasMoreElements(
            /* [out] */ Boolean * value);

        CARAPI GetNextElement(
            /* [out] */ IInterface ** inter);
    };

    class ECO_LOCAL ValueEnumeration
        : public HashIterator
        , public IEnumeration
    {
    public:
        ValueEnumeration(
            /* [in] */ HashTable* host);

        CAR_INTERFACE_DECL()

        CARAPI HasMoreElements(
            /* [out] */ Boolean * value);

        CARAPI GetNextElement(
            /* [out] */ IInterface ** inter);
    };

    class ECO_LOCAL _KeySet
        : public AbstractSet
    {
    public:
        _KeySet(
            /* [in] */ HashTable* host);

        CARAPI GetIterator(
            /* [out] */ IIterator** outiter);

        CARAPI GetSize(
            /* [out] */ Int32* size);

        CARAPI Contains(
            /* [in] */ IInterface* o,
            /* [out] */ Boolean* value);

        CARAPI Remove(
            /* [in] */ IInterface* o,
            /* [out] */ Boolean* value);

        CARAPI Clear();

        CARAPI Add(
            /* [in] */ IInterface* object,
            /* [out] */ Boolean* modified);

        CARAPI AddAll(
            /* [in] */ ICollection* collection,
            /* [out] */ Boolean* modified);

        CARAPI IsEmpty(
            /* [out] */ Boolean* result);

        CARAPI RemoveAll(
            /* [in] */ ICollection* collection,
            /* [out] */ Boolean* value);

        CARAPI RetainAll(
            /* [in] */ ICollection* collection,
            /* [out] */ Boolean* value);

        CARAPI ContainsAll(
            /* [in] */ ICollection* collection,
            /* [out] */ Boolean* value);

        CARAPI Equals(
            /* [in] */ IInterface* object,
            /* [out] */ Boolean* value);

        CARAPI GetHashCode(
            /* [out] */ Int32* value);

        CARAPI ToString(
            /* [out] */ String* str);

        CARAPI ToArray(
            /* [out, callee] */ ArrayOf<IInterface*>** array);

        CARAPI ToArray(
            /* [in] */ ArrayOf<IInterface*>* contents,
            /* [out, callee] */ ArrayOf<IInterface*>** outArray);

    protected:
        CARAPI_(String) GetClassName() { return String("Hashtable::KeySet"); }

    public:
        HashTable* mHost;
    };

    class ECO_LOCAL _Values
        : public AbstractCollection
    {
    public:
        _Values(
            /* [in] */ HashTable* host);

        CARAPI GetIterator(
            /* [out] */ IIterator** outiter);

        CARAPI GetSize(
            /* [out] */ Int32* size);

        CARAPI Contains(
            /* [in] */ IInterface* o,
            /* [out] */ Boolean* value);

        CARAPI Clear();

        CARAPI Remove(
            /* [in] */ IInterface* o,
            /* [out] */ Boolean* value);

        CARAPI Add(
            /* [in] */ IInterface* object,
            /* [out] */ Boolean* modified);

        CARAPI AddAll(
            /* [in] */ ICollection* collection,
            /* [out] */ Boolean* modified);

        CARAPI IsEmpty(
            /* [out] */ Boolean* result);

        CARAPI RemoveAll(
            /* [in] */ ICollection* collection,
            /* [out] */ Boolean* value);

        CARAPI RetainAll(
            /* [in] */ ICollection* collection,
            /* [out] */ Boolean* value);

        CARAPI Equals(
            /* [in] */ IInterface* object,
            /* [out] */ Boolean* value);

        CARAPI GetHashCode(
            /* [out] */ Int32* value);

        CARAPI ContainsAll(
            /* [in] */ ICollection* collection,
            /* [out] */ Boolean* value);

        CARAPI ToString(
            /* [out] */ String* str);

        CARAPI ToArray(
            /* [out, callee] */ ArrayOf<IInterface*>** array);

        CARAPI ToArray(
            /* [in] */ ArrayOf<IInterface*>* contents,
            /* [out, callee] */ ArrayOf<IInterface*>** outArray);

    protected:
        CARAPI_(String) GetClassName() { return String("Hashtable::Values"); }

    public:
        HashTable* mHost;;
    };

    class ECO_LOCAL _EntrySet
        : public AbstractSet
    {
    public:
        _EntrySet(
            /* [in] */ HashTable* host);

        CARAPI GetIterator(
            /* [out] */ IIterator** outiter);

        CARAPI GetSize(
            /* [out] */ Int32* size);

        CARAPI Contains(
            /* [in] */ IInterface* o,
            /* [out] */ Boolean* value);

        CARAPI Remove(
            /* [in] */ IInterface* o,
            /* [out] */ Boolean* value);

        CARAPI Clear();

        CARAPI Add(
            /* [in] */ IInterface* object,
            /* [out] */ Boolean* modified);

        CARAPI AddAll(
            /* [in] */ ICollection* collection,
            /* [out] */ Boolean* modified);

        CARAPI IsEmpty(
            /* [out] */ Boolean* result);

        CARAPI RemoveAll(
            /* [in] */ ICollection* collection,
            /* [out] */ Boolean* value);

        CARAPI RetainAll(
            /* [in] */ ICollection* collection,
            /* [out] */ Boolean* value);

        CARAPI ContainsAll(
            /* [in] */ ICollection* collection,
            /* [out] */ Boolean* value);

        CARAPI Equals(
            /* [in] */ IInterface* object,
            /* [out] */ Boolean* value);

        CARAPI GetHashCode(
            /* [out] */ Int32* value);

        CARAPI ToString(
            /* [out] */ String* str);

        CARAPI ToArray(
            /* [out, callee] */ ArrayOf<IInterface*>** array);

        CARAPI ToArray(
            /* [in] */ ArrayOf<IInterface*>* contents,
            /* [out, callee] */ ArrayOf<IInterface*>** outArray);

    protected:
        CARAPI_(String) GetClassName() { return String("Hashtable::EntrySet"); }

    public:
        HashTable* mHost;
    };

public:
    CAR_INTERFACE_DECL()

    CARAPI constructor();

    CARAPI constructor(
        /* [in] */ Int32 capacity);

    CARAPI constructor(
        /* [in] */ Int32 capacity,
        /* [in] */ Float loadFactor);

    CARAPI constructor(
        /* [in] */ IMap* map);

    /**
     * Returns an enumeration on the elements of this dictionary.
     *
     * @return an enumeration of the values of this dictionary.
     * @see #keys
     * @see #size
     * @see Enumeration
     */
    virtual CARAPI GetElements(
        /* [out] */ IEnumeration** enm);

    /**
     * Returns the value which is associated with {@code key}.
     *
     * @param key
     *            the key of the value returned.
     * @return the value associated with {@code key}, or {@code null} if the
     *         specified key does not exist.
     * @see #put
     */
    virtual CARAPI Get(
        /* [in] */ IInterface* key,
        /* [out] */ IInterface** outface);

    /**
     * Returns true if this dictionary has no key/value pairs.
     *
     * @return {@code true} if this dictionary has no key/value pairs,
     *         {@code false} otherwise.
     * @see #size
     */
    virtual CARAPI IsEmpty(
        /* [out] */ Boolean* value);

    /**
     * Returns an enumeration on the keys of this dictionary.
     *
     * @return an enumeration of the keys of this dictionary.
     * @see #elements
     * @see #size
     * @see Enumeration
     */
    virtual CARAPI GetKeys(
        /* [out] */ IEnumeration** enm);

    /**
     * Associate {@code key} with {@code value} in this dictionary. If {@code
     * key} exists in the dictionary before this call, the old value in the
     * dictionary is replaced by {@code value}.
     *
     * @param key
     *            the key to add.
     * @param value
     *            the value to add.
     * @return the old value previously associated with {@code key} or {@code
     *         null} if {@code key} is new to the dictionary.
     * @see #elements
     * @see #get
     * @see #keys
     */
    virtual CARAPI Put(
        /* [in] */ IInterface* key,
        /* [in] */ IInterface* value,
        /* [out] */ IInterface** outface);

    virtual CARAPI Put(
        /* [in] */ IInterface* key,
        /* [in] */ IInterface* value);

    /**
     * Removes the key/value pair with the specified {@code key} from this
     * dictionary.
     *
     * @param key
     *            the key to remove.
     * @return the associated value before the deletion or {@code null} if
     *         {@code key} was not known to this dictionary.
     * @see #get
     * @see #put
     */
    virtual CARAPI Remove(
        /* [in] */ IInterface* key,
        /* [out] */ IInterface** outface);

    virtual CARAPI Remove(
        /* [in] */ IInterface* key);

    /**
     * Returns the number of key/value pairs in this dictionary.
     *
     * @return the number of key/value pairs in this dictionary.
     * @see #elements
     * @see #keys
     */
    virtual CARAPI GetSize(
        /* [out] */ Int32* value);

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
     * Returns true if this {@code Hashtable} contains the specified object as
     * the value of at least one of the key/value pairs.
     *
     * @param value
     *            the object to look for as a value in this {@code Hashtable}.
     * @return {@code true} if object is a value in this {@code Hashtable},
     *         {@code false} otherwise.
     * @see #containsKey
     * @see java.lang.Object#equals
     */
    virtual CARAPI Contains(
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
     * Returns an integer hash code for the receiver. {@code Object}s which are equal
     * return the same value for this method.
     *
     * @return the receiver's hash.
     * @see #equals(Object)
     */
    virtual CARAPI GetHashCode(
        /* [out] */ Int32* hashCode);

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

    virtual CARAPI Clone(
        /* [out] */ IInterface** object);

    /**
     * Returns the string representation of this {@code Hashtable}.
     *
     * @return the string representation of this {@code Hashtable}.
     */
    virtual CARAPI ToString(
        /* [out] */ String* str);

    /**
     * Increases the capacity of this {@code Hashtable}. This method is called
     * when the size of this {@code Hashtable} exceeds the load factor.
     */
    virtual CARAPI Rehash();

protected:
    HashTable();

    CARAPI_(String) GetClassName() { return String("Hashtable"); }

private:
    /**
     * Inserts all of the elements of map into this Hashtable in a manner
     * suitable for use by constructors and pseudo-constructors (i.e., clone,
     * readObject).
     */
    ECO_LOCAL CARAPI ConstructorPutAll(
        /* [in] */ IMap* map);

    /**
     * Returns an appropriate capacity for the specified initial size. Does
     * not round the result up to a power of two; the caller must do this!
     * The returned value will be between 0 and MAXIMUM_CAPACITY (inclusive).
     */
    ECO_LOCAL static CARAPI_(Int32) CapacityForInitSize(
        /* [in] */ Int32 size);

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
    ECO_LOCAL CARAPI_(AutoPtr<ArrayOf<HashtableEntry*> >) MakeTable(
        /* [in] */ Int32 newCapacity);

    /**
     * Doubles the capacity of the hash table. Existing entries are placed in
     * the correct bucket on the enlarged table. If the current capacity is,
     * MAXIMUM_CAPACITY, this method is a no-op. Returns the table, which
     * will be new unless we were already at MAXIMUM_CAPACITY.
     */
    ECO_LOCAL CARAPI_(AutoPtr<ArrayOf<HashtableEntry*> >) DoubleCapacity();

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
     * against poor quality hash functions. This is critical because Hashtable
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

private:
    /**
     * Min capacity (other than zero) for a Hashtable. Must be a power of two
     * greater than 1 (and less than 1 << 30).
     */
    ECO_LOCAL static const Int32 MINIMUM_CAPACITY = 4;

    /**
     * Max capacity for a Hashtable. Must be a power of two >= MINIMUM_CAPACITY.
     */
    ECO_LOCAL static const Int32 MAXIMUM_CAPACITY = 1 << 30;

    /**
     * An empty table shared by all zero-capacity maps (typically from default
     * constructor). It is never written to, and replaced on first put. Its size
     * is set to half the minimum, so that the first resize will create a
     * minimum-sized table.
     */
    ECO_LOCAL static const AutoPtr<ArrayOf<HashtableEntry*> > EMPTY_TABLE; // = new HashtableEntry[MINIMUM_CAPACITY >>> 1];

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
    ECO_LOCAL static constexpr Float DEFAULT_LOAD_FACTOR = 0.75F;

    /**
     * A rough estimate of the number of characters per entry, for use
     * when creating a string buffer in the toString method.
     */
    ECO_LOCAL static const Int32 CHARS_PER_ENTRY = 15;

    ECO_LOCAL static const Int64 sSerialVersionUID = 1421746759512286392LL;

//    ECO_LOCAL static const AutoPtr<ArrayOf<IObjectStreamField*> > sSerialPersistentFields; // = {
    //     new ObjectStreamField("threshold", int.class),
    //     new ObjectStreamField("loadFactor", float.class),
    // };

    /**
     * The hash table.
     */
    /* transient */ AutoPtr<ArrayOf<HashtableEntry*> > mTable;

    /**
     * The number of mappings in this hash map.
     */
    /* transient */ Int32 mSize;

    /**
     * Incremented by "structural modifications" to allow (best effort)
     * detection of concurrent modification.
     */
    /* transient */ Int32 mModCount;

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


DEFINE_CONVERSION_FOR(Elastos::Utility::HashTable::HashtableEntry, IInterface)


#endif // __ELASTOS_UTILITY__HASHTABLE_H__
