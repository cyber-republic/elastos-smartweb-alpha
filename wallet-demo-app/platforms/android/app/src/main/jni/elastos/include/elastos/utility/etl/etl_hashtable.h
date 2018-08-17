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

#ifndef __ETL_HASHTABLE_H__
#define __ETL_HASHTABLE_H__

#include "elastos/utility/etl/etl_def.h"
#include "elastos/utility/etl/etl_function_exception.h"
#include "elastos/utility/etl/etl_algobase.h"
#include "elastos/utility/etl/etl_alloc.h"
#include "elastos/utility/etl/etl_construct.h"
#include "elastos/utility/etl/etl_algo.h"
#include "elastos/utility/etl/etl_uninitialized.h"
#include "elastos/utility/etl/etl_function.h"
#include "elastos/utility/etl/etl_vector.h"
#include "elastos/utility/etl/etl_hash_fun.h"
#include <elrefbase.h>

using Elastos::ElLightRefBase;

_ETL_NAMESPACE_BEGIN

template <class Val>
struct HashTableNode
{
    HashTableNode* mNext;
    Val mVal;
};

template <class Val, class Key, class HashFcn,
          class ExtractKey, class EqualKey, class Alloc = Allocator<Alloc> >
class HashTable;

template <class Val, class Key, class HashFcn,
          class ExtractKey, class EqualKey, class Alloc>
struct HashTableIterator;

template <class Val, class Key, class HashFcn,
          class ExtractKey, class EqualKey, class Alloc>
struct HashTableConstIterator;

template <class Val, class Key, class HashFcn,
          class ExtractKey, class EqualKey, class Alloc>
struct HashTableIterator
{
    typedef HashTable<Val,Key,HashFcn,ExtractKey,EqualKey,Alloc> _HashTable;

    typedef HashTableIterator<Val, Key, HashFcn,
            ExtractKey, EqualKey, Alloc> Iterator;

    typedef HashTableConstIterator<Val, Key, HashFcn,
            ExtractKey, EqualKey, Alloc> ConstIterator;

    typedef HashTableNode<Val> Node;

    typedef ForwardIteratorTag IteratorCategory;
    typedef Val ValueType;
    typedef ptrdiff_t DifferenceType;
    typedef size_t SizeType;
    typedef Val& Reference;
    typedef Val* Pointer;

    Node* mCurrent;
    _HashTable* mHashtable;

    HashTableIterator(Node* n, _HashTable* tab) :
            mCurrent(n), mHashtable(tab) {}
    HashTableIterator() {}

    Reference operator*() const { return mCurrent->mVal; }
    Pointer operator->() const { return &(operator*()); }
    Iterator& operator++();
    Iterator operator++(int);
    Boolean operator==(const Iterator& it) const
    {
        return mCurrent == it.mCurrent;
    }
    Boolean operator!=(const Iterator& it) const
    {
        return mCurrent != it.mCurrent;
    }
};

template <class Val, class Key, class HashFcn,
          class ExtractKey, class EqualKey, class Alloc>
struct HashTableConstIterator
{
    typedef HashTable<Val,Key,HashFcn,ExtractKey,EqualKey,Alloc> _HashTable;

    typedef HashTableIterator<Val,Key,HashFcn,
            ExtractKey,EqualKey,Alloc> Iterator;

    typedef HashTableConstIterator<Val, Key, HashFcn,
            ExtractKey, EqualKey, Alloc> ConstIterator;

    typedef HashTableNode<Val> Node;

    typedef ForwardIteratorTag IteratorCategory;
    typedef Val ValueType;
    typedef ptrdiff_t DifferenceType;
    typedef size_t SizeType;
    typedef const Val& Reference;
    typedef const Val* Pointer;

    const Node* mCurrent;
    const _HashTable* mHashtable;

    HashTableConstIterator(const Node* n, const _HashTable* tab) :
            mCurrent(n), mHashtable(tab) {}
    HashTableConstIterator() {}
    HashTableConstIterator(const Iterator& it) :
            mCurrent(it.mCurrent), mHashtable(it.mHashtable) {}

    Reference operator*() const { return mCurrent->mVal; }
    Pointer operator->() const { return &(operator*()); }
    ConstIterator& operator++();
    ConstIterator operator++(int);
    Boolean operator==(const ConstIterator& it) const
    {
        return mCurrent == it.mCurrent;
    }
    Boolean operator!=(const ConstIterator& it) const
    {
        return mCurrent != it.mCurrent;
    }
};

// Note: assumes long is at least 32 bits.
enum { etl_num_primes = 28 };

static const unsigned long etl_prime_list[31] =
{
    5ul,          11ul,         23ul,
    53ul,         97ul,         193ul,       389ul,       769ul,
    1543ul,       3079ul,       6151ul,      12289ul,     24593ul,
    49157ul,      98317ul,      196613ul,    393241ul,    786433ul,
    1572869ul,    3145739ul,    6291469ul,   12582917ul,  25165843ul,
    50331653ul,   100663319ul,  201326611ul, 402653189ul, 805306457ul,
    1610612741ul, 3221225473ul, 4294967291ul
};

inline unsigned long GetNextPrime(unsigned long n)
{
    const unsigned long* first = etl_prime_list;
    const unsigned long* last = etl_prime_list + (int)etl_num_primes;
    const unsigned long* pos = GetLowerBound(first, last, n);
    return pos == last ? *(last - 1) : *pos;
}

// Forward declaration of operator==.

template <class Val, class Key, class HF, class Ex, class Eq, class All>
class HashTable;

template <class Val, class Key, class HF, class Ex, class Eq, class All>
Boolean operator==(const HashTable<Val,Key,HF,Ex,Eq,All>& ht1,
                   const HashTable<Val,Key,HF,Ex,Eq,All>& ht2);


// Hashtables handle allocators a bit differently than other containers
//  do.  If we're using standard-conforming allocators, then a HashTable
//  unconditionally has a member variable to hold its allocator, even if
//  it so happens that all instances of the allocator type are identical.
// This is because, for hashtables, this extra storage is negligible.
//  Additionally, a base class wouldn't serve any other purposes; it
//  wouldn't, for example, simplify the exception-handling code.

template <class Val, class Key, class HashFcn,
          class ExtractKey, class EqualKey, class Alloc>
class HashTable : public ElLightRefBase
{
public:
    typedef Key KeyType;
    typedef Val ValueType;
    typedef HashFcn Hasher;
    typedef EqualKey KeyEqual;

    typedef size_t           SizeType;
    typedef ptrdiff_t        DifferenceType;
    typedef ValueType*       Pointer;
    typedef const ValueType* ConstPointer;
    typedef ValueType&       Reference;
    typedef const ValueType& ConstReference;

    Hasher GetHashFunc() const { return mHasher; }
    KeyEqual GetKeyEqual() const { return mEquals; }

private:
    typedef HashTableNode<Val> Node;

public:
    typedef typename AllocTraits<Val,Alloc>::AllocatorType AllocatorType;
    AllocatorType GetAllocator() const { return mNodeAllocator; }

private:
    typename AllocTraits<Node, Alloc>::AllocatorType mNodeAllocator;
    Node* GetNode() { return mNodeAllocator.Allocate(1); }
    void PutNode(Node* p) { mNodeAllocator.Deallocate(p, 1); }

private:
    Hasher               mHasher;
    KeyEqual             mEquals;
    ExtractKey           mGetKey;
    Vector<Node*,Alloc>  mBuckets;
    SizeType             mNumElements;

public:
    typedef HashTableIterator<Val,Key,HashFcn,ExtractKey,EqualKey,Alloc>
            Iterator;

    typedef HashTableConstIterator<Val,Key,HashFcn,ExtractKey,EqualKey,
            Alloc> ConstIterator;

    friend struct HashTableIterator<Val,Key,HashFcn,ExtractKey,EqualKey,Alloc>;
    friend struct HashTableConstIterator<Val,Key,HashFcn,ExtractKey,EqualKey,Alloc>;

public:
    HashTable(SizeType n,
              const HashFcn&    hf,
              const EqualKey&   eql,
              const ExtractKey& ext,
              const AllocatorType& a = AllocatorType()) :
            mNodeAllocator(a),
            mHasher(hf),
            mEquals(eql),
            mGetKey(ext),
            mBuckets(a),
            mNumElements(0)
    {
        InitializeBuckets(n);
    }

    HashTable(SizeType n,
              const HashFcn&    hf,
              const EqualKey&   eql,
              const AllocatorType& a = AllocatorType()) :
            mNodeAllocator(a),
            mHasher(hf),
            mEquals(eql),
            mGetKey(ExtractKey()),
            mBuckets(a),
            mNumElements(0)
    {
        InitializeBuckets(n);
    }

    HashTable(const HashTable& ht) :
            mNodeAllocator(ht.GetAllocator()),
            mHasher(ht.mHasher),
            mEquals(ht.mEquals),
            mGetKey(ht.mGetKey),
            mBuckets(ht.GetAllocator()),
            mNumElements(0)
    {
        CopyFrom(ht);
    }

    HashTable& operator= (const HashTable& ht)
    {
        if (&ht != this) {
            Clear();
            mHasher = ht.mHasher;
            mEquals = ht.mEquals;
            mGetKey = ht.mGetKey;
            CopyFrom(ht);
        }
        return *this;
    }

    ~HashTable() { Clear(); }

    SizeType GetSize() const { return mNumElements; }
    SizeType GetMaxSize() const { return SizeType(-1); }
    Boolean IsEmpty() const { return GetSize() == 0; }

    void Swap(HashTable& ht)
    {
        _ETL Swap(mHasher, ht.mHasher);
        _ETL Swap(mEquals, ht.mEquals);
        _ETL Swap(mGetKey, ht.mGetKey);
        mBuckets.Swap(ht.mBuckets);
        _ETL Swap(mNumElements, ht.mNumElements);
    }

    Iterator Begin()
    {
        SizeType size = mBuckets.GetSize();
        for (SizeType n = 0; n < size; ++n) {
            if (mBuckets[n]) return Iterator(mBuckets[n], this);
        }

        return End();
    }

    Iterator End() { return Iterator(0, this); }

    ConstIterator Begin() const
    {
        SizeType size = mBuckets.GetSize();
        for (SizeType n = 0; n < size; ++n) {
            if (mBuckets[n]) return ConstIterator(mBuckets[n], this);
        }

        return End();
    }

    ConstIterator End() const { return ConstIterator(0, this); }

    template <class Vl, class Ky, class HF, class Ex, class Eq, class Al>
    friend Boolean operator== (const HashTable<Vl, Ky, HF, Ex, Eq, Al>&,
                               const HashTable<Vl, Ky, HF, Ex, Eq, Al>&);
public:

    SizeType GetBucketCount() const { return mBuckets.GetSize(); }

    SizeType GetMaxBucketCount() const
    {
        return etl_prime_list[(int)etl_num_primes - 1];
    }

    SizeType GetElementCountInBucket(SizeType bucket) const
    {
        SizeType result = 0;
        for (Node* cur = mBuckets[bucket]; cur; cur = cur->mNext) result += 1;
        return result;
    }

    Pair<Iterator, Boolean> InsertUnique(const ValueType& obj)
    {
        Resize(mNumElements + 1);
        return InsertUniqueWithoutResize(obj);
    }

    Iterator InsertEqual(const ValueType& obj)
    {
        Resize(mNumElements + 1);
        return InsertEqualWithoutResize(obj);
    }

    Pair<Iterator, Boolean> InsertUniqueWithoutResize(const ValueType& obj);
    Iterator InsertEqualWithoutResize(const ValueType& obj);

    template <class InputIterator>
    void InsertUnique(InputIterator f, InputIterator l)
    {
        InsertUnique(f, l, IteratorCategory(f));
    }

    template <class InputIterator>
    void InsertEqual(InputIterator f, InputIterator l)
    {
        InsertEqual(f, l, IteratorCategory(f));
    }

    template <class InputIterator>
    void InsertUnique(InputIterator f, InputIterator l,
            InputIteratorTag)
    {
        for ( ; f != l; ++f) InsertUnique(*f);
    }

    template <class InputIterator>
    void InsertEqual(InputIterator f, InputIterator l,
            InputIteratorTag)
    {
      for ( ; f != l; ++f) InsertEqual(*f);
    }

    template <class ForwardIterator>
    void InsertUnique(ForwardIterator f, ForwardIterator l,
            ForwardIteratorTag)
    {
        SizeType n = Distance(f, l);
        Resize(mNumElements + n);
        for ( ; n > 0; --n, ++f) InsertUniqueWithoutResize(*f);
    }

    template <class ForwardIterator>
    void InsertEqual(ForwardIterator f, ForwardIterator l,
            ForwardIteratorTag)
    {
        SizeType n = Distance(f, l);
        Resize(mNumElements + n);
        for ( ; n > 0; --n, ++f) InsertEqualWithoutResize(*f);
    }

    Reference FindOrInsert(const ValueType& obj);

    Iterator Find(const KeyType& key)
    {
        SizeType n = GetBktNumKey(key);
        Node* first;
        for (first = mBuckets[n];
             first && !mEquals(mGetKey(first->mVal), key);
             first = first->mNext)
        {}
        return Iterator(first, this);
    }

    ConstIterator Find(const KeyType& key) const
    {
        SizeType n = GetBktNumKey(key);
        const Node* first;
        for (first = mBuckets[n];
             first && !mEquals(mGetKey(first->mVal), key);
             first = first->mNext)
        {}
        return ConstIterator(first, this);
    }

    SizeType GetCount(const KeyType& key) const
    {
        const SizeType n = GetBktNumKey(key);
        SizeType result = 0;

        for (const Node* cur = mBuckets[n]; cur; cur = cur->mNext) {
            if (mEquals(mGetKey(cur->mVal), key)) ++result;
        }
        return result;
    }

    Pair<Iterator, Iterator>
    GetEqualRange(const KeyType& key);

    Pair<ConstIterator, ConstIterator>
    GetEqualRange(const KeyType& key) const;

    SizeType Erase(const KeyType& key);
    void Erase(const Iterator& it);
    void Erase(Iterator first, Iterator last);

    void Erase(const ConstIterator& it);
    void Erase(ConstIterator first, ConstIterator last);

    void Resize(SizeType num_elements_hint);
    void Clear();

private:
    SizeType GetNextSize(SizeType n) const
    {
        return GetNextPrime(n);
    }

    void InitializeBuckets(SizeType n)
    {
        const SizeType buckets = GetNextSize(n);
        mBuckets.Reserve(buckets);
        mBuckets.Insert(mBuckets.End(), buckets, (Node*) 0);
        mNumElements = 0;
    }

    SizeType GetBktNumKey(const KeyType& key) const
    {
        return GetBktNumKey(key, mBuckets.GetSize());
    }

    SizeType GetBktNum(const ValueType& obj) const
    {
        return GetBktNumKey(mGetKey(obj));
    }

    SizeType GetBktNumKey(const KeyType& key, size_t n) const
    {
        return mHasher(key) % n;
    }

    SizeType GetBktNum(const ValueType& obj, size_t n) const
    {
        return GetBktNumKey(mGetKey(obj), n);
    }

    Node* NewNode(const ValueType& obj)
    {
        Node* n = GetNode();
        n->mNext = 0;
        try {
            Construct(&n->mVal, obj);
            return n;
        }
        catch(...) {
	        PutNode(n);
	        THROW_EXCEPTION_AGAIN;
        }
    }

    void DeleteNode(Node* n)
    {
        Destroy(&n->mVal);
        PutNode(n);
    }

    void EraseBucket(const SizeType n, Node* first, Node* last);
    void EraseBucket(const SizeType n, Node* last);

    void CopyFrom(const HashTable& ht);

};

template <class Val, class Key, class HF, class ExK, class EqK,
          class All>
HashTableIterator<Val,Key,HF,ExK,EqK,All>&
HashTableIterator<Val,Key,HF,ExK,EqK,All>::operator++()
{
    const Node* old = mCurrent;
    mCurrent = mCurrent->mNext;
    if (!mCurrent) {
        SizeType bucket = mHashtable->GetBktNum(old->mVal);

        SizeType size = mHashtable->mBuckets.GetSize();
        while (!mCurrent && ++bucket < size) {
            mCurrent = mHashtable->mBuckets[bucket];
        }
    }
    return *this;
}

template <class Val, class Key, class HF, class ExK, class EqK,
          class All>
inline HashTableIterator<Val,Key,HF,ExK,EqK,All>
HashTableIterator<Val,Key,HF,ExK,EqK,All>::operator++(int)
{
    Iterator tmp = *this;
    ++*this;
    return tmp;
}

template <class Val, class Key, class HF, class ExK, class EqK,
          class All>
HashTableConstIterator<Val,Key,HF,ExK,EqK,All>&
HashTableConstIterator<Val,Key,HF,ExK,EqK,All>::operator++()
{
    const Node* old = mCurrent;
    mCurrent = mCurrent->mNext;
    if (!mCurrent) {
        SizeType bucket = mHashtable->GetBktNum(old->mVal);
        SizeType size = mHashtable->mBuckets.GetSize();
        while (!mCurrent && ++bucket < size) {
            mCurrent = mHashtable->mBuckets[bucket];
        }
    }
    return *this;
}

template <class Val, class Key, class HF, class ExK, class EqK,
          class All>
inline HashTableConstIterator<Val,Key,HF,ExK,EqK,All>
HashTableConstIterator<Val,Key,HF,ExK,EqK,All>::operator++(int)
{
    ConstIterator tmp = *this;
    ++*this;
    return tmp;
}

template <class Val, class Key, class HF, class Ex, class Eq, class All>
Boolean operator==(const HashTable<Val,Key,HF,Ex,Eq,All>& ht1,
                   const HashTable<Val,Key,HF,Ex,Eq,All>& ht2)
{
    typedef typename HashTable<Val,Key,HF,Ex,Eq,All>::Node Node;
    size_t size = ht1.mBuckets.GetSize();
    if (size != ht2.mBuckets.GetSize()) return FALSE;

    for (size_t n = 0; n < size; ++n) {
        Node* cur1 = ht1.mBuckets[n];
        Node* cur2 = ht2.mBuckets[n];
        for ( ; cur1 && cur2 && cur1->mVal == cur2->mVal;
                cur1 = cur1->mNext, cur2 = cur2->mNext)
        {}
        if (cur1 || cur2) return FALSE;
    }
    return TRUE;
}

template <class Val, class Key, class HF, class Ex, class Eq, class All>
inline Boolean operator!=(const HashTable<Val,Key,HF,Ex,Eq,All>& ht1,
                          const HashTable<Val,Key,HF,Ex,Eq,All>& ht2)
{
    return !(ht1 == ht2);
}

template <class Val, class Key, class HF, class Extract, class EqKey,
          class All>
inline void Swap(HashTable<Val, Key, HF, Extract, EqKey, All>& ht1,
                 HashTable<Val, Key, HF, Extract, EqKey, All>& ht2)
{
    ht1.Swap(ht2);
}


template <class Val, class Key, class HF, class Ex, class Eq, class All>
Pair<typename HashTable<Val,Key,HF,Ex,Eq,All>::Iterator, Boolean>
HashTable<Val,Key,HF,Ex,Eq,All>::InsertUniqueWithoutResize(const ValueType& obj)
{
    const SizeType n = GetBktNum(obj);
    Node* first = mBuckets[n];

    for (Node* cur = first; cur; cur = cur->mNext) {
        if (mEquals(mGetKey(cur->mVal), mGetKey(obj))) {
            return Pair<Iterator, Boolean>(Iterator(cur, this), FALSE);
        }
    }

    Node* tmp = NewNode(obj);
    tmp->mNext = first;
    mBuckets[n] = tmp;
    ++mNumElements;
    return Pair<Iterator, Boolean>(Iterator(tmp, this), TRUE);
}

template <class Val, class Key, class HF, class Ex, class Eq, class All>
typename HashTable<Val,Key,HF,Ex,Eq,All>::Iterator
HashTable<Val,Key,HF,Ex,Eq,All>::InsertEqualWithoutResize(const ValueType& obj)
{
    const SizeType n = GetBktNum(obj);
    Node* first = mBuckets[n];

    for (Node* cur = first; cur; cur = cur->mNext) {
        if (mEquals(mGetKey(cur->mVal), mGetKey(obj))) {
            Node* tmp = NewNode(obj);
            tmp->mNext = cur->mNext;
            cur->mNext = tmp;
            ++mNumElements;
            return Iterator(tmp, this);
      }
    }

    Node* tmp = NewNode(obj);
    tmp->mNext = first;
    mBuckets[n] = tmp;
    ++mNumElements;
    return Iterator(tmp, this);
}

template <class Val, class Key, class HF, class Ex, class Eq, class All>
typename HashTable<Val,Key,HF,Ex,Eq,All>::Reference
HashTable<Val,Key,HF,Ex,Eq,All>::FindOrInsert(const ValueType& obj)
{
    Resize(mNumElements + 1);

    SizeType n = GetBktNum(obj);
    Node* first = mBuckets[n];

    for (Node* cur = first; cur; cur = cur->mNext) {
        if (mEquals(mGetKey(cur->mVal), mGetKey(obj))) return cur->mVal;
    }

    Node* tmp = NewNode(obj);
    tmp->mNext = first;
    mBuckets[n] = tmp;
    ++mNumElements;
    return tmp->mVal;
}

template <class Val, class Key, class HF, class Ex, class Eq, class All>
Pair<typename HashTable<Val,Key,HF,Ex,Eq,All>::Iterator,
     typename HashTable<Val,Key,HF,Ex,Eq,All>::Iterator>
HashTable<Val,Key,HF,Ex,Eq,All>::GetEqualRange(const KeyType& key)
{
    typedef Pair<Iterator, Iterator> Pii;
    const SizeType n = GetBktNumKey(key);

    for (Node* first = mBuckets[n]; first; first = first->mNext) {
        if (mEquals(mGetKey(first->mVal), key)) {
            for (Node* cur = first->mNext; cur; cur = cur->mNext) {
                if (!mEquals(mGetKey(cur->mVal), key)) {
                    return Pii(Iterator(first, this), Iterator(cur, this));
                }
            }
            SizeType size = mBuckets.GetSize();
            for (SizeType m = n + 1; m < size; ++m) {
                if (mBuckets[m]) {
                    return Pii(Iterator(first, this), Iterator(mBuckets[m], this));
                }
            }
            return Pii(Iterator(first, this), End());
        }
    }
    return Pii(End(), End());
}

template <class Val, class Key, class HF, class Ex, class Eq, class All>
Pair<typename HashTable<Val,Key,HF,Ex,Eq,All>::ConstIterator,
     typename HashTable<Val,Key,HF,Ex,Eq,All>::ConstIterator>
HashTable<Val,Key,HF,Ex,Eq,All>::GetEqualRange(const KeyType& key) const
{
    typedef Pair<ConstIterator, ConstIterator> Pii;
    const SizeType n = GetBktNumKey(key);

    for (const Node* first = mBuckets[n] ; first;
         first = first->mNext) {
        if (mEquals(mGetKey(first->mVal), key)) {
            for (const Node* cur = first->mNext; cur;
                 cur = cur->mNext) {
                if (!mEquals(mGetKey(cur->mVal), key)) {
                    return Pii(ConstIterator(first, this),
                            ConstIterator(cur, this));
                }
            }
            SizeType size = mBuckets.GetSize();
            for (SizeType m = n + 1; m < size; ++m) {
                if (mBuckets[m]) {
                    return Pii(ConstIterator(first, this),
                            ConstIterator(mBuckets[m], this));
                }
            }
            return Pii(ConstIterator(first, this), End());
        }
    }
    return Pii(End(), End());
}

template <class Val, class Key, class HF, class Ex, class Eq, class All>
typename HashTable<Val,Key,HF,Ex,Eq,All>::SizeType
HashTable<Val,Key,HF,Ex,Eq,All>::Erase(const KeyType& key)
{
    const SizeType n = GetBktNumKey(key);
    Node* first = mBuckets[n];
    SizeType erased = 0;

    if (first) {
        Node* cur = first;
        Node* next = cur->mNext;
        while (next) {
            if (mEquals(mGetKey(next->mVal), key)) {
                cur->mNext = next->mNext;
                DeleteNode(next);
                next = cur->mNext;
                ++erased;
                --mNumElements;
            }
            else {
                cur = next;
                next = cur->mNext;
            }
        }
        if (mEquals(mGetKey(first->mVal), key)) {
            mBuckets[n] = first->mNext;
            DeleteNode(first);
            ++erased;
            --mNumElements;
        }
    }
    return erased;
}

template <class Val, class Key, class HF, class Ex, class Eq, class All>
void HashTable<Val,Key,HF,Ex,Eq,All>::Erase(const Iterator& it)
{
    Node* p = it.mCurrent;
    if (p) {
        const SizeType n = GetBktNum(p->mVal);
        Node* cur = mBuckets[n];

        if (cur == p) {
             mBuckets[n] = cur->mNext;
            DeleteNode(cur);
            --mNumElements;
        }
        else {
            Node* next = cur->mNext;
            while (next) {
                if (next == p) {
                    cur->mNext = next->mNext;
                    DeleteNode(next);
                    --mNumElements;
                    break;
                }
                else {
                cur = next;
                next = cur->mNext;
                }
            }
        }
    }
}

template <class Val, class Key, class HF, class Ex, class Eq, class All>
void HashTable<Val,Key,HF,Ex,Eq,All>::Erase(Iterator first, Iterator last)
{
    SizeType fBucket = first.mCurrent ?
            GetBktNum(first.mCurrent->mVal) : mBuckets.GetSize();
    SizeType lBucket = last.mCurrent ?
            GetBktNum(last.mCurrent->mVal) : mBuckets.GetSize();

    if (first.mCurrent == last.mCurrent) return;
    else if (fBucket == lBucket) EraseBucket(fBucket, first.mCurrent, last.mCurrent);
    else {
        EraseBucket(fBucket, first.mCurrent, 0);
        for (SizeType n = fBucket + 1; n < lBucket; ++n) EraseBucket(n, 0);
        if (lBucket != mBuckets.GetSize()) EraseBucket(lBucket, last.mCurrent);
    }
}

template <class Val, class Key, class HF, class Ex, class Eq, class All>
inline void
HashTable<Val,Key,HF,Ex,Eq,All>::Erase(ConstIterator first,
                                             ConstIterator last)
{
    Erase(Iterator(const_cast<Node*>(first.mCurrent),
                   const_cast<HashTable*>(first.mHashtable)),
          Iterator(const_cast<Node*>(last.mCurrent),
                   const_cast<HashTable*>(last.mHashtable)));
}

template <class Val, class Key, class HF, class Ex, class Eq, class All>
inline void
HashTable<Val,Key,HF,Ex,Eq,All>::Erase(const ConstIterator& it)
{
    Erase(Iterator(const_cast<Node*>(it.mCurrent),
                   const_cast<HashTable*>(it.mHashtable)));
}

template <class Val, class Key, class HF, class Ex, class Eq, class All>
void HashTable<Val,Key,HF,Ex,Eq,All>::Resize(SizeType num_elements_hint)
{
    const SizeType oldN = mBuckets.GetSize();
    if (num_elements_hint > oldN) {
        const SizeType n = GetNextSize(num_elements_hint);
        if (n > oldN) {
            Vector<Node*, All> tmp(n, (Node*)(0), mBuckets.GetAllocator());
            try {
                for (SizeType bucket = 0; bucket < oldN; ++bucket) {
                    Node* first = mBuckets[bucket];
                    while (first) {
                        SizeType newBucket = GetBktNum(first->mVal, n);
                        mBuckets[bucket] = first->mNext;
                        first->mNext = tmp[newBucket];
                        tmp[newBucket] = first;
                        first = mBuckets[bucket];
                    }
                }
                mBuckets.Swap(tmp);
            }
            catch(...) {
                SizeType tmpN = tmp.GetSize();
                for (SizeType bucket = 0; bucket < tmpN; ++bucket) {
                    while (tmp[bucket]) {
                        Node* next = tmp[bucket]->mNext;
                        DeleteNode(tmp[bucket]);
                        tmp[bucket] = next;
                    }
                }
                THROW_EXCEPTION_AGAIN;
            }
        }
    }
}

template <class Val, class Key, class HF, class Ex, class Eq, class All>
void HashTable<Val,Key,HF,Ex,Eq,All>::EraseBucket(const SizeType n, Node* first, Node* last)
{
    Node* cur = mBuckets[n];
    if (cur == first) EraseBucket(n, last);
    else {
        Node* next;
        for (next = cur->mNext;
             next != first;
             cur = next, next = cur->mNext);
        while (next != last) {
          cur->mNext = next->mNext;
          DeleteNode(next);
          next = cur->mNext;
          --mNumElements;
        }
    }
}

template <class Val, class Key, class HF, class Ex, class Eq, class All>
void HashTable<Val,Key,HF,Ex,Eq,All>::EraseBucket(const SizeType n, Node* last)
{
    Node* cur = mBuckets[n];
    while (cur != last) {
        Node* next = cur->mNext;
        DeleteNode(cur);
        cur = next;
        mBuckets[n] = cur;
        --mNumElements;
    }
}

template <class Val, class Key, class HF, class Ex, class Eq, class All>
void HashTable<Val,Key,HF,Ex,Eq,All>::Clear()
{
    if (mNumElements == 0)
        return;

    SizeType size = mBuckets.GetSize();
    for (SizeType i = 0; i < size; ++i) {
        Node* cur = mBuckets[i];
        while (cur != 0) {
            Node* next = cur->mNext;
            DeleteNode(cur);
            cur = next;
        }
        mBuckets[i] = 0;
    }
    mNumElements = 0;
}


template <class Val, class Key, class HF, class Ex, class Eq, class All>
void HashTable<Val,Key,HF,Ex,Eq,All>::CopyFrom(const HashTable& ht)
{
    SizeType size = ht.mBuckets.GetSize();
    mBuckets.Clear();
    mBuckets.Reserve(size);
    mBuckets.Insert(mBuckets.End(), size, (Node*) 0);
    try {
        for (SizeType i = 0; i < size; ++i) {
            const Node* cur = ht.mBuckets[i];
            if (cur) {
                Node* localCopy = NewNode(cur->mVal);
                mBuckets[i] = localCopy;

                for (Node* next = cur->mNext;
                     next;
                     cur = next, next = cur->mNext) {
                    localCopy->mNext = NewNode(next->mVal);
                    localCopy = localCopy->mNext;
                }
            }
        }
        mNumElements = ht.mNumElements;
    }
    catch(...) {
        Clear();
        THROW_EXCEPTION_AGAIN;
    }
}

_ETL_NAMESPACE_END

#endif //__ETL_HASHTABLE_H__
