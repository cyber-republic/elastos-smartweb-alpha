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

#ifndef __ETL_HASHMAP_H__
#define __ETL_HASHMAP_H__

#include "elastos/utility/etl/etl_def.h"
#include "elastos/utility/etl/etl_hashtable.h"
#include "elastos/utility/etl/ConceptCheck.h"
#include <elrefbase.h>

using Elastos::ElLightRefBase;

_ETL_NAMESPACE_BEGIN

// Forward declaration of equality operator; needed for friend declaration.

template <class Key, class T,
          class HashFcn  = Hash<Key>,
          class EqualKey = EqualTo<Key>,
          class Alloc =  Allocator<T> >
class HashMap;

template <class Key, class T, class HashFn, class EqKey, class Alloc>
inline Boolean operator==(const HashMap<Key, T, HashFn, EqKey, Alloc>&,
                          const HashMap<Key, T, HashFn, EqKey, Alloc>&);

template <class Key, class T, class HashFcn, class EqualKey, class Alloc>
class HashMap : public ElLightRefBase
{
private:
    typedef HashTable<Pair<const Key,T>,Key,HashFcn,
                      Select1st<Pair<const Key,T> >,EqualKey,Alloc> Ht;
    Ht mHashtable;

public:
    typedef typename Ht::KeyType KeyType;
    typedef T DataType;
    typedef T MappedType;
    typedef typename Ht::ValueType ValueType;
    typedef typename Ht::Hasher Hasher;
    typedef typename Ht::KeyEqual KeyEqual;

    typedef typename Ht::SizeType SizeType;
    typedef typename Ht::DifferenceType DifferenceType;
    typedef typename Ht::Pointer Pointer;
    typedef typename Ht::ConstPointer ConstPointer;
    typedef typename Ht::Reference Reference;
    typedef typename Ht::ConstReference ConstReference;

    typedef typename Ht::Iterator Iterator;
    typedef typename Ht::ConstIterator ConstIterator;

    typedef typename Ht::AllocatorType AllocatorType;

    Hasher GetHashFunc() const { return mHashtable.GetHashFunc(); }
    KeyEqual GetKeyEqual() const { return mHashtable.GetKeyEqual(); }
    AllocatorType GetAllocator() const { return mHashtable.GetAllocator(); }

public:
    HashMap() : mHashtable(100, Hasher(), KeyEqual(), AllocatorType()) {}
    explicit HashMap(SizeType n) : mHashtable(n, Hasher(), KeyEqual(), AllocatorType()) {}
    HashMap(SizeType n, const Hasher& hf) : mHashtable(n, hf, KeyEqual(), AllocatorType()) {}
    HashMap(SizeType n, const Hasher& hf, const KeyEqual& eql,
             const AllocatorType& a = AllocatorType()) : mHashtable(n, hf, eql, a) {}

    template <class InputIterator>
    HashMap(InputIterator f, InputIterator l) :
            mHashtable(100, Hasher(), KeyEqual(), AllocatorType())
    {
        mHashtable.InsertUnique(f, l);
    }
    template <class InputIterator>
    HashMap(InputIterator f, InputIterator l, SizeType n) :
            mHashtable(n, Hasher(), KeyEqual(), AllocatorType())
    {
        mHashtable.InsertUnique(f, l);
    }
    template <class InputIterator>
    HashMap(InputIterator f, InputIterator l, SizeType n, const Hasher& hf) :
            mHashtable(n, hf, KeyEqual(), AllocatorType())
    {
        mHashtable.InsertUnique(f, l);
    }
    template <class InputIterator>
    HashMap(InputIterator f, InputIterator l, SizeType n,
            const Hasher& hf, const KeyEqual& eql,
            const AllocatorType& a = AllocatorType()) : mHashtable(n, hf, eql, a)
    {
        mHashtable.InsertUnique(f, l);
    }

public:
    SizeType GetSize() const { return mHashtable.GetSize(); }
    SizeType GetMaxSize() const { return mHashtable.GetMaxSize(); }
    Boolean IsEmpty() const { return mHashtable.IsEmpty(); }
    void Swap(HashMap& hs) { mHashtable.Swap(hs.mHashtable); }

    template <class K1, class T1, class HF, class EqK, class Al>
    friend Boolean operator== (const HashMap<K1, T1, HF, EqK, Al>&,
                               const HashMap<K1, T1, HF, EqK, Al>&);

    Iterator Begin() { return mHashtable.Begin(); }
    Iterator End() { return mHashtable.End(); }
    ConstIterator Begin() const { return mHashtable.Begin(); }
    ConstIterator End() const { return mHashtable.End(); }

public:
    Pair<Iterator,Boolean> Insert(const ValueType& obj)
    {
        return mHashtable.InsertUnique(obj);
    }

    template <class InputIterator>
    void Insert(InputIterator f, InputIterator l)
    {
        mHashtable.InsertUnique(f,l);
    }

    Pair<Iterator,Boolean> InsertWithoutResize(const ValueType& obj)
    {
        return mHashtable.InsertUniqueWithoutResize(obj);
    }

    Iterator Find(const KeyType& key) { return mHashtable.Find(key); }
    ConstIterator Find(const KeyType& key) const
    {
        return mHashtable.Find(key);
    }

    T& operator[](const KeyType& key)
    {
        return mHashtable.FindOrInsert(ValueType(key, T())).mSecond;
    }

    SizeType GetCount(const KeyType& key) const { return mHashtable.GetCount(key); }

    Pair<Iterator, Iterator> GetEqualRange(const KeyType& key)
    {
        return mHashtable.GetEqualRange(key);
    }
    Pair<ConstIterator, ConstIterator>
    GetEqualRange(const KeyType& key) const
    {
        return mHashtable.GetEqualRange(key);
    }

    SizeType Erase(const KeyType& key) { return mHashtable.Erase(key); }
    void Erase(Iterator it) { mHashtable.Erase(it); }
    void Erase(Iterator f, Iterator l) { mHashtable.Erase(f, l); }
    void Clear() { mHashtable.Clear(); }

    void Resize(SizeType hint) { mHashtable.Resize(hint); }
    SizeType GetBucketCount() const { return mHashtable.GetBucketCount(); }
    SizeType GetMaxBucketCount() const { return mHashtable.GetMaxBucketCount(); }
    SizeType GetElementCountInBucket(SizeType n) const
    {
        return mHashtable.GetElementCountInBucket(n);
    }
};

template <class Key, class T, class HashFcn, class EqlKey, class Alloc>
inline Boolean
operator==(const HashMap<Key,T,HashFcn,EqlKey,Alloc>& hm1,
           const HashMap<Key,T,HashFcn,EqlKey,Alloc>& hm2)
{
    return hm1.mHashtable == hm2.mHashtable;
}

template <class Key, class T, class HashFcn, class EqlKey, class Alloc>
inline Boolean
operator!=(const HashMap<Key,T,HashFcn,EqlKey,Alloc>& hm1,
           const HashMap<Key,T,HashFcn,EqlKey,Alloc>& hm2)
{
    return !(hm1 == hm2);
}

template <class Key, class T, class HashFcn, class EqlKey, class Alloc>
inline void
Swap(HashMap<Key,T,HashFcn,EqlKey,Alloc>& hm1,
     HashMap<Key,T,HashFcn,EqlKey,Alloc>& hm2)
{
    hm1.Swap(hm2);
}

// Forward declaration of equality operator; needed for friend declaration.

template <class Key, class T,
          class HashFcn  = Hash<Key>,
          class EqualKey = EqualTo<Key>,
          class Alloc =  Allocator<T> >
class HashMultimap;

template <class Key, class T, class HF, class EqKey, class Alloc>
inline Boolean
operator==(const HashMultimap<Key,T,HF,EqKey,Alloc>& hm1,
           const HashMultimap<Key,T,HF,EqKey,Alloc>& hm2);

template <class Key, class T, class HashFcn, class EqualKey, class Alloc>
class HashMultimap : public ElLightRefBase
{
    // concept requirements
    Concept_ClassRequires(Key, SGIAssignableConcept)
    Concept_ClassRequires(T, SGIAssignableConcept)
    Concept_ClassRequires3(HashFcn, size_t, Key, UnaryFunctionConcept);
    Concept_ClassRequires3(EqualKey, Key, Key, BinaryPredicateConcept);

private:
    typedef HashTable<Pair<const Key, T>, Key, HashFcn,
                      Select1st<Pair<const Key, T> >, EqualKey, Alloc> Ht;
    Ht mHashtable;

public:
    typedef typename Ht::KeyType KeyType;
    typedef T DataType;
    typedef T MappedType;
    typedef typename Ht::ValueType ValueType;
    typedef typename Ht::Hasher Hasher;
    typedef typename Ht::KeyEqual KeyEqual;

    typedef typename Ht::SizeType SizeType;
    typedef typename Ht::DifferenceType DifferenceType;
    typedef typename Ht::Pointer Pointer;
    typedef typename Ht::ConstPointer ConstPointer;
    typedef typename Ht::Reference Reference;
    typedef typename Ht::ConstReference ConstReference;

    typedef typename Ht::Iterator Iterator;
    typedef typename Ht::ConstIterator ConstIterator;

    typedef typename Ht::AllocatorType AllocatorType;

    Hasher GetHashFunc() const { return mHashtable.GetHashFunc(); }
    KeyEqual GetKeyEqual() const { return mHashtable.GetKeyEqual(); }
    AllocatorType GetAllocator() const { return mHashtable.GetAllocator(); }

public:
    HashMultimap() : mHashtable(100, Hasher(), KeyEqual(), AllocatorType()) {}
    explicit HashMultimap(SizeType n) :
            mHashtable(n, Hasher(), KeyEqual(), AllocatorType()) {}
    HashMultimap(SizeType n, const Hasher& hf) :
            mHashtable(n, hf, KeyEqual(), AllocatorType()) {}
    HashMultimap(SizeType n, const Hasher& hf, const KeyEqual& eql,
                 const AllocatorType& a = AllocatorType()) :
            mHashtable(n, hf, eql, a) {}

    template <class InputIterator>
    HashMultimap(InputIterator f, InputIterator l) :
            mHashtable(100, Hasher(), KeyEqual(), AllocatorType())
    {
        mHashtable.InsertEqual(f, l);
    }
    template <class InputIterator>
    HashMultimap(InputIterator f, InputIterator l, SizeType n) :
            mHashtable(n, Hasher(), KeyEqual(), AllocatorType())
    {
        mHashtable.InsertEqual(f, l);
    }
    template <class InputIterator>
    HashMultimap(InputIterator f, InputIterator l, SizeType n,
                 const Hasher& hf) : mHashtable(n, hf, KeyEqual(), AllocatorType())
    {
        mHashtable.InsertEqual(f, l);
    }
    template <class InputIterator>
    HashMultimap(InputIterator f, InputIterator l, SizeType n,
                 const Hasher& hf, const KeyEqual& eql,
                 const AllocatorType& a = AllocatorType()) :
            mHashtable(n, hf, eql, a)
    {
        mHashtable.InsertEqual(f, l);
    }

public:
    SizeType GetSize() const { return mHashtable.GetSize(); }
    SizeType GetMaxSize() const { return mHashtable.GetMaxSize(); }
    Boolean IsEmpty() const { return mHashtable.IsEmpty(); }
    void Swap(HashMultimap& hs) { mHashtable.Swap(hs.mHashtable); }

    template <class K1, class T1, class HF, class EqK, class Al>
    friend Boolean operator== (const HashMultimap<K1, T1, HF, EqK, Al>&,
                               const HashMultimap<K1, T1, HF, EqK, Al>&);

    Iterator Begin() { return mHashtable.Begin(); }
    Iterator End() { return mHashtable.End(); }
    ConstIterator Begin() const { return mHashtable.Begin(); }
    ConstIterator End() const { return mHashtable.End(); }

public:
    Iterator Insert(const ValueType& obj)
    {
        return mHashtable.InsertEqual(obj);
    }
    template <class InputIterator>
    void Insert(InputIterator f, InputIterator l)
    {
        mHashtable.InsertEqual(f,l);
    }
    Iterator InsertWithoutResize(const ValueType& obj)
    {
        return mHashtable.InsertEqualWithoutResize(obj);
    }

    Iterator Find(const KeyType& key) { return mHashtable.Find(key); }
    ConstIterator Find(const KeyType& key) const
    {
        return mHashtable.Find(key);
    }

    SizeType GetCount(const KeyType& key) const { return mHashtable.GetCount(key); }

    Pair<Iterator, Iterator> GetEqualRange(const KeyType& key)
    {
        return mHashtable.GetEqualRange(key);
    }
    Pair<ConstIterator, ConstIterator>
    GetEqualRange(const KeyType& key) const
    {
        return mHashtable.GetEqualRange(key);
    }

    SizeType Erase(const KeyType& key) { return mHashtable.Erase(key); }
    void Erase(Iterator it) { mHashtable.Erase(it); }
    void Erase(Iterator f, Iterator l) { mHashtable.Erase(f, l); }
    void Clear() { mHashtable.Clear(); }

public:
    void Resize(SizeType hint) { mHashtable.Resize(hint); }
    SizeType GetBucketCount() const { return mHashtable.GetBucketCount(); }
    SizeType GetMaxBucketCount() const { return mHashtable.GetMaxBucketCount(); }
    SizeType GetElementCountInBucket(SizeType n) const
    {
        return mHashtable.GetElementCountInBucket(n);
    }
};

template <class Key, class T, class HF, class EqKey, class Alloc>
inline Boolean
operator==(const HashMultimap<Key,T,HF,EqKey,Alloc>& hm1,
           const HashMultimap<Key,T,HF,EqKey,Alloc>& hm2)
{
    return hm1.mHashtable == hm2.mHashtable;
}

template <class Key, class T, class HF, class EqKey, class Alloc>
inline Boolean
operator!=(const HashMultimap<Key,T,HF,EqKey,Alloc>& hm1,
           const HashMultimap<Key,T,HF,EqKey,Alloc>& hm2)
{
    return !(hm1 == hm2);
}

template <class Key, class T, class HashFcn, class EqlKey, class Alloc>
inline void
Swap(HashMultimap<Key,T,HashFcn,EqlKey,Alloc>& hm1,
     HashMultimap<Key,T,HashFcn,EqlKey,Alloc>& hm2)
{
    hm1.Swap(hm2);
}


// Specialization of InsertIterator so that it will work for HashMap
// and hash_multimap.

template <class Key, class T, class HashFn,  class EqKey, class Alloc>
class InsertIterator<HashMap<Key, T, HashFn, EqKey, Alloc> >
{
protected:
    typedef HashMap<Key, T, HashFn, EqKey, Alloc> Container;
    Container* container;
public:
    typedef Container           ContainerType;
    typedef OutputIteratorTag   IteratorCategory;
    typedef void                ValueType;
    typedef void                DifferenceType;
    typedef void                Pointer;
    typedef void                Reference;

    InsertIterator(Container& x) : container(&x) {}
    InsertIterator(Container& x, typename Container::iterator) : container(&x) {}
    InsertIterator<Container>&
    operator=(const typename Container::ValueType& value)
    {
        container->Insert(value);
        return *this;
    }
    InsertIterator<Container>& operator*() { return *this; }
    InsertIterator<Container>& operator++() { return *this; }
    InsertIterator<Container>& operator++(int) { return *this; }
};

template <class Key, class T, class HashFn,  class EqKey, class Alloc>
class InsertIterator<HashMultimap<Key, T, HashFn, EqKey, Alloc> >
{
protected:
    typedef HashMultimap<Key, T, HashFn, EqKey, Alloc> Container;
    Container* container;
    typename Container::Iterator iter;
public:
    typedef Container           ContainerType;
    typedef OutputIteratorTag   IteratorCategory;
    typedef void                ValueType;
    typedef void                DifferenceType;
    typedef void                Pointer;
    typedef void                Reference;

    InsertIterator(Container& x) : container(&x) {}
    InsertIterator(Container& x, typename Container::Iterator) : container(&x) {}
    InsertIterator<Container>&
    operator=(const typename Container::ValueType& value)
    {
        container->Insert(value);
        return *this;
    }
    InsertIterator<Container>& operator*() { return *this; }
    InsertIterator<Container>& operator++() { return *this; }
    InsertIterator<Container>& operator++(int) { return *this; }
};

_ETL_NAMESPACE_END

#endif //__ETL_HASHMAP_H__
