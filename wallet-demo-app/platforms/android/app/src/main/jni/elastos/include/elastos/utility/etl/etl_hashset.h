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

#ifndef __ETL_HASHSET_H__
#define __ETL_HASHSET_H__

#include "elastos/utility/etl/etl_def.h"
#include "elastos/utility/etl/etl_hashtable.h"
#include "elastos/utility/etl/ConceptCheck.h"
#include <elrefbase.h>

using Elastos::ElLightRefBase;

_ETL_NAMESPACE_BEGIN

// Forward declaration of equality operator; needed for friend declaration.

template <class Value,
          class HashFcn  = Hash<Value>,
          class EqualKey = EqualTo<Value>,
          class Alloc =  Allocator<Value> >
class HashSet;

template <class Value, class HashFcn, class EqualKey, class Alloc>
inline Boolean
operator==(const HashSet<Value,HashFcn,EqualKey,Alloc>& hs1,
           const HashSet<Value,HashFcn,EqualKey,Alloc>& hs2);

template <class Value, class HashFcn, class EqualKey, class Alloc>
class HashSet : public ElLightRefBase
{
    // concept requirements
    Concept_ClassRequires(Value, SGIAssignableConcept)
    Concept_ClassRequires3(HashFcn, size_t, Value, UnaryFunctionConcept);
    Concept_ClassRequires3(EqualKey, Value, Value, BinaryPredicateConcept);

private:
    typedef HashTable<Value, Value, HashFcn, Identity<Value>,
            EqualKey, Alloc> Ht;
    Ht mHashtable;

public:
    typedef typename Ht::KeyType KeyType;
    typedef typename Ht::ValueType ValueType;
    typedef typename Ht::Hasher Hasher;
    typedef typename Ht::KeyEqual KeyEqual;

    typedef typename Ht::SizeType SizeType;
    typedef typename Ht::DifferenceType DifferenceType;
    typedef typename Ht::ConstPointer Pointer;
    typedef typename Ht::ConstPointer ConstPointer;
    typedef typename Ht::ConstReference Reference;
    typedef typename Ht::ConstReference ConstReference;

    typedef typename Ht::ConstIterator Iterator;
    typedef typename Ht::ConstIterator ConstIterator;

    typedef typename Ht::AllocatorType AllocatorType;

    Hasher GetHashFunc() const { return mHashtable.GetHashFunc(); }
    KeyEqual GetKeyEqual() const { return mHashtable.GetKeyEqual(); }
    AllocatorType GetAllocator() const { return mHashtable.GetAllocator(); }

public:
    HashSet() :
            mHashtable(100, Hasher(), KeyEqual(), AllocatorType()) {}
    explicit HashSet(SizeType n) :
            mHashtable(n, Hasher(), KeyEqual(), AllocatorType()) {}
    HashSet(SizeType n, const Hasher& hf) :
            mHashtable(n, hf, KeyEqual(), AllocatorType()) {}
    HashSet(SizeType n, const Hasher& hf, const KeyEqual& eql,
            const AllocatorType& a = AllocatorType()) :
            mHashtable(n, hf, eql, a) {}

    template <class InputIterator>
    HashSet(InputIterator f, InputIterator l) :
            mHashtable(100, Hasher(), KeyEqual(), AllocatorType())
    {
        mHashtable.InsertUnique(f, l);
    }
    template <class InputIterator>
    HashSet(InputIterator f, InputIterator l, SizeType n) :
            mHashtable(n, Hasher(), KeyEqual(), AllocatorType())
    {
        mHashtable.InsertUnique(f, l);
    }
    template <class InputIterator>
    HashSet(InputIterator f, InputIterator l, SizeType n,
            const Hasher& hf) :
            mHashtable(n, hf, KeyEqual(), AllocatorType())
    {
        mHashtable.InsertUnique(f, l);
    }
    template <class InputIterator>
    HashSet(InputIterator f, InputIterator l, SizeType n,
            const Hasher& hf, const KeyEqual& eql,
            const AllocatorType& a = AllocatorType()) :
            mHashtable(n, hf, eql, a)
    {
        mHashtable.InsertUnique(f, l);
    }

public:
    SizeType GetSize() const { return mHashtable.GetSize(); }
    SizeType GetMaxSize() const { return mHashtable.GetMaxSize(); }
    Boolean IsEmpty() const { return mHashtable.IsEmpty(); }
    void Swap(HashSet& hs) { mHashtable.Swap(hs.mHashtable); }

    template <class Val, class HF, class EqK, class Al>
    friend Boolean
    operator== (const HashSet<Val, HF, EqK, Al>&,
                const HashSet<Val, HF, EqK, Al>&);

    Iterator Begin() const { return mHashtable.Begin(); }
    Iterator End() const { return mHashtable.End(); }

public:
    Pair<Iterator, Boolean> Insert(const ValueType& obj)
    {
        Pair<typename Ht::Iterator, Boolean> p = mHashtable.InsertUnique(obj);
        return Pair<Iterator,Boolean>(p.mFirst, p.mSecond);
    }
    template <class InputIterator>
    void Insert(InputIterator f, InputIterator l)
    {
        mHashtable.InsertUnique(f,l);
    }
    Pair<Iterator, Boolean> InsertWithoutResize(const ValueType& obj)
    {
        Pair<typename Ht::Iterator, Boolean> p =
                mHashtable.insert_unique_noresize(obj);
        return Pair<Iterator, Boolean>(p.mFirst, p.mSecond);
    }

    Iterator Find(const KeyType& key) const { return mHashtable.Find(key); }

    SizeType GetCount(const KeyType& key) const { return mHashtable.GetCount(key); }

    Pair<Iterator, Iterator> GetEqualRange(const KeyType& key) const
    {
        return mHashtable.GetEqualRange(key);
    }

    SizeType Erase(const KeyType& key) {return mHashtable.Erase(key); }
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

template <class Value, class HashFcn, class EqualKey, class Alloc>
inline Boolean
operator==(const HashSet<Value,HashFcn,EqualKey,Alloc>& hs1,
           const HashSet<Value,HashFcn,EqualKey,Alloc>& hs2)
{
    return hs1.mHashtable == hs2.mHashtable;
}

template <class Value, class HashFcn, class EqualKey, class Alloc>
inline Boolean
operator!=(const HashSet<Value,HashFcn,EqualKey,Alloc>& hs1,
           const HashSet<Value,HashFcn,EqualKey,Alloc>& hs2)
{
    return !(hs1 == hs2);
}

template <class Val, class HashFcn, class EqualKey, class Alloc>
inline void
Swap(HashSet<Val,HashFcn,EqualKey,Alloc>& hs1,
     HashSet<Val,HashFcn,EqualKey,Alloc>& hs2)
{
    hs1.Swap(hs2);
}

template <class Value,
          class HashFcn  = Hash<Value>,
          class EqualKey = EqualTo<Value>,
          class Alloc = Allocator<Value> >
class HashMultiset;

template <class Val, class HashFcn, class EqualKey, class Alloc>
inline Boolean
operator==(const HashMultiset<Val,HashFcn,EqualKey,Alloc>& hs1,
           const HashMultiset<Val,HashFcn,EqualKey,Alloc>& hs2);


template <class Value, class HashFcn, class EqualKey, class Alloc>
class HashMultiset
{
    // concept requirements
    Concept_ClassRequires(Value, SGIAssignableConcept)
    Concept_ClassRequires3(HashFcn, size_t, Value, UnaryFunctionConcept);
    Concept_ClassRequires3(EqualKey, Value, Value, BinaryPredicateConcept);

private:
    typedef HashTable<Value, Value, HashFcn, Identity<Value>,
                      EqualKey, Alloc> Ht;
    Ht mHashtable;

public:
    typedef typename Ht::KeyType KeyType;
    typedef typename Ht::ValueType ValueType;
    typedef typename Ht::Hasher Hasher;
    typedef typename Ht::KeyEqual KeyEqual;

    typedef typename Ht::SizeType SizeType;
    typedef typename Ht::DifferenceType DifferenceType;
    typedef typename Ht::ConstPointer Pointer;
    typedef typename Ht::ConstPointer ConstPointer;
    typedef typename Ht::ConstReference Reference;
    typedef typename Ht::ConstReference ConstReference;

    typedef typename Ht::ConstIterator Iterator;
    typedef typename Ht::ConstIterator ConstIterator;

    typedef typename Ht::AllocatorType AllocatorType;

    Hasher GetHashFunc() const { return mHashtable.GetHashFunc(); }
    KeyEqual GetKeyEqual() const { return mHashtable.GetKeyEqual(); }
    AllocatorType GetAllocator() const { return mHashtable.GetAllocator(); }

public:
    HashMultiset() :
            mHashtable(100, Hasher(), KeyEqual(), AllocatorType()) {}
    explicit HashMultiset(SizeType n) :
            mHashtable(n, Hasher(), KeyEqual(), AllocatorType()) {}
    HashMultiset(SizeType n, const Hasher& hf) :
            mHashtable(n, hf, KeyEqual(), AllocatorType()) {}
    HashMultiset(SizeType n, const Hasher& hf, const KeyEqual& eql,
            const AllocatorType& a = AllocatorType()) :
            mHashtable(n, hf, eql, a) {}

    template <class InputIterator>
    HashMultiset(InputIterator f, InputIterator l) :
            mHashtable(100, Hasher(), KeyEqual(), AllocatorType())
    {
        mHashtable.InsertEqual(f, l);
    }
    template <class InputIterator>
    HashMultiset(InputIterator f, InputIterator l, SizeType n) :
            mHashtable(n, Hasher(), KeyEqual(), AllocatorType())
    {
        mHashtable.InsertEqual(f, l);
    }
    template <class InputIterator>
    HashMultiset(InputIterator f, InputIterator l, SizeType n,
            const Hasher& hf) :
            mHashtable(n, hf, KeyEqual(), AllocatorType())
    {
        mHashtable.InsertEqual(f, l);
    }
    template <class InputIterator>
    HashMultiset(InputIterator f, InputIterator l, SizeType n,
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
    void Swap(HashMultiset& hs) { mHashtable.Swap(hs.mHashtable); }

    template <class Val, class HF, class EqK, class Al>
    friend Boolean
    operator== (const HashMultiset<Val, HF, EqK, Al>&,
                const HashMultiset<Val, HF, EqK, Al>&);

    Iterator Begin() const { return mHashtable.Begin(); }
    Iterator End() const { return mHashtable.End(); }

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

    Iterator Find(const KeyType& key) const { return mHashtable.Find(key); }

    SizeType GetCount(const KeyType& key) const { return mHashtable.GetCount(key); }

    Pair<Iterator, Iterator> GetEqualRange(const KeyType& key) const
    {
        return mHashtable.GetEqualRange(key);
    }

    SizeType Erase(const KeyType& key) {return mHashtable.Erase(key); }
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

template <class Val, class HashFcn, class EqualKey, class Alloc>
inline Boolean
operator==(const HashMultiset<Val,HashFcn,EqualKey,Alloc>& hs1,
           const HashMultiset<Val,HashFcn,EqualKey,Alloc>& hs2)
{
    return hs1.mHashtable == hs2.mHashtable;
}

template <class Val, class HashFcn, class EqualKey, class Alloc>
inline Boolean
operator!=(const HashMultiset<Val,HashFcn,EqualKey,Alloc>& hs1,
           const HashMultiset<Val,HashFcn,EqualKey,Alloc>& hs2)
{
    return !(hs1 == hs2);
}

template <class Val, class HashFcn, class EqualKey, class Alloc>
inline void
Swap(HashMultiset<Val,HashFcn,EqualKey,Alloc>& hs1,
     HashMultiset<Val,HashFcn,EqualKey,Alloc>& hs2)
{
    hs1.Swap(hs2);
}

// Specialization of InsertIterator so that it will work for hash_set
// and HashMultiset.

template <class Value, class HashFcn, class EqualKey, class Alloc>
class InsertIterator<HashSet<Value, HashFcn, EqualKey, Alloc> >
{
protected:
    typedef HashSet<Value, HashFcn, EqualKey, Alloc> Container;
    Container* container;
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

template <class Value, class HashFcn, class EqualKey, class Alloc>
class InsertIterator<HashMultiset<Value, HashFcn, EqualKey, Alloc> >
{
protected:
    typedef HashMultiset<Value, HashFcn, EqualKey, Alloc> Container;
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

#endif //__ETL_HASHSET_H__
