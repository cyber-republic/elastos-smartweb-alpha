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

#ifndef __ETL_DEQUE_H__
#define __ETL_DEQUE_H__

/** @file stl_deque.h
 *  This is an internal header file, included by other library headers.
 *  You should not attempt to use it directly.
 */

#include "elastos/utility/etl/etl_def.h"
#include "elastos/utility/etl/ConceptCheck.h"
#include "elastos/utility/etl/etl_iterator_base_types.h"
#include "elastos/utility/etl/etl_iterator_base_funcs.h"
#include <elrefbase.h>

using Elastos::ElLightRefBase;

_ETL_NAMESPACE_BEGIN

/**
 *  @maint
 *  @brief This function controls the GetSize of memory nodes.
 *  @param  GetSize  The GetSize of an element.
 *  @return   The number (not bytesize) of elements per node.
 *
 *  This function started off as a compiler kludge from SGI, but seems to
 *  be a useful wrapper around a repeated constant expression.
 *  @endmaint
*/
inline size_t
__deque_buf_size(size_t GetSize)
{ return GetSize < 512 ? size_t(512 / GetSize) : size_t(1); }


/// A Deque::Iterator.
/**
 *  Quite a bit of intelligence here.  Much of the functionality of Deque is
 *  actually passed off to this class.  A Deque holds two of these internally,
 *  marking its valid range.  Access to elements is done as offsets of either
 *  of those two, relying on operator overloading in this class.
 *
 *  @maint
 *  All the functions are op overloads except for SetNode.
 *  @endmaint
*/
template <class Tp, class Ref, class Ptr>
struct DequeIterator
{
    typedef DequeIterator<Tp, Tp&, Tp*>             Iterator;
    typedef DequeIterator<Tp, const Tp&, const Tp*> ConstIterator;
    static size_t GetBufferSize() { return __deque_buf_size(sizeof(Tp)); }

    typedef RandomAccessIteratorTag IteratorCategory;
    typedef Tp                         ValueType;
    typedef Ptr                        Pointer;
    typedef Ref                        Reference;
    typedef size_t                     SizeType;
    typedef ptrdiff_t                 DifferenceType;
    typedef Tp**                       MapPointer;
    typedef DequeIterator             Self;

    Tp* mCur;
    Tp* mFirst;
    Tp* mLast;
    MapPointer mNode;

    DequeIterator(Tp* x, MapPointer y)
        : mCur(x), mFirst(*y),
          mLast(*y + GetBufferSize()), mNode(y) {}
    DequeIterator() : mCur(0), mFirst(0), mLast(0), mNode(0) {}
    DequeIterator(const Iterator& x)
        : mCur(x.mCur), mFirst(x.mFirst),
          mLast(x.mLast), mNode(x.mNode) {}

    Reference operator*() const { return *mCur; }
    Pointer operator->() const { return mCur; }

    DifferenceType operator-(const Self& x) const
    {
        return DifferenceType(GetBufferSize()) * (mNode - x.mNode - 1) +
            (mCur - mFirst) + (x.mLast - x.mCur);
    }

    Self& operator++()
    {
        ++mCur;
        if (mCur == mLast) {
          SetNode(mNode + 1);
          mCur = mFirst;
        }
        return *this;
    }
    Self operator++(int)
    {
        Self tmp = *this;
        ++*this;
        return tmp;
    }

    Self& operator--()
    {
        if (mCur == mFirst) {
          SetNode(mNode - 1);
          mCur = mLast;
        }
        --mCur;
        return *this;
    }
    Self operator--(int)
    {
        Self tmp = *this;
        --*this;
        return tmp;
    }

    Self& operator+=(DifferenceType n)
    {
        DifferenceType offset = n + (mCur - mFirst);
        if (offset >= 0 && offset < DifferenceType(GetBufferSize())) {
            mCur += n;
        }
        else {
            DifferenceType nodeOffset =
            offset > 0 ? offset / DifferenceType(GetBufferSize())
                       : -DifferenceType((-offset - 1) / GetBufferSize()) - 1;
            SetNode(mNode + nodeOffset);
            mCur = mFirst +
                (offset - nodeOffset * DifferenceType(GetBufferSize()));
        }
        return *this;
    }

    Self operator+(DifferenceType n) const
    {
        Self tmp = *this;
        return tmp += n;
    }

    Self& operator-=(DifferenceType n) { return *this += -n; }

    Self operator-(DifferenceType n) const
    {
        Self tmp = *this;
        return tmp -= n;
    }

    Reference operator[](DifferenceType n) const { return *(*this + n); }

    Boolean operator==(const Self& x) const { return mCur == x.mCur; }
    Boolean operator!=(const Self& x) const { return !(*this == x); }
    Boolean operator<(const Self& x) const
    {
        return (mNode == x.mNode) ?
            (mCur < x.mCur) : (mNode < x.mNode);
    }
    Boolean operator>(const Self& x) const  { return x < *this; }
    Boolean operator<=(const Self& x) const { return !(x < *this); }
    Boolean operator>=(const Self& x) const { return !(*this < x); }

    /** @maint
    *  Prepares to traverse new_node.  Sets everything except mCur, which
    *  should therefore be set by the caller immediately afterwards, based on
    *  mFirst and mLast.
    *  @endmaint
    */
    void SetNode(MapPointer newNode)
    {
        mNode = newNode;
        mFirst = *newNode;
        mLast = mFirst + DifferenceType(GetBufferSize());
    }
};

template <class Tp, class Ref, class Ptr>
inline DequeIterator<Tp, Ref, Ptr>
operator+(ptrdiff_t n, const DequeIterator<Tp, Ref, Ptr>& x)
{
    return x + n;
}

/// @maint Primary default version.  @endmaint
/**
 *  @maint
 *  Deque base class.  It has two purposes.  First, its constructor
 *  and destructor allocate (but don't initialize) storage.  This makes
 *  exception safety easier.  Second, the base class encapsulates all of
 *  the differences between SGI-style allocators and standard-conforming
 *  allocators.  There are two versions:  this ordinary one, and the
 *  space-saving specialization for instanceless allocators.
 *  @endmaint
*/
template <class Tp, class Alloc, Boolean isStatic>
class DequeAllocBase
{
public:
    typedef typename AllocTraits<Tp, Alloc>::AllocatorType AllocatorType;
    AllocatorType GetAllocator() const { return mNodeAllocator; }

    DequeAllocBase(const AllocatorType& a)
        : mNodeAllocator(a), mMapAllocator(a),
          mMap(0), mMapSize(0)
    {}

protected:
    typedef typename AllocTraits<Tp*, Alloc>::AllocatorType MapAllocatorType;

    AllocatorType mNodeAllocator;
    MapAllocatorType mMapAllocator;

    Tp* AllocateNode()
    {
        return mNodeAllocator.Allocate(__deque_buf_size(sizeof(Tp)));
    }
    void DeallocateNode(Tp* p)
    {
        mNodeAllocator.Deallocate(p, __deque_buf_size(sizeof(Tp)));
    }
    Tp** AllocateMap(size_t n)
    { return mMapAllocator.allocate(n); }
    void DeallocateMap(Tp** p, size_t n)
    { mMapAllocator.Deallocate(p, n); }

    Tp** mMap;
    size_t mMapSize;
};

/// Specialization for instanceless allocators.
template <class Tp, class Alloc>
class DequeAllocBase<Tp, Alloc, TRUE>
{
public:
    typedef typename AllocTraits<Tp, Alloc>::AllocatorType AllocatorType;
    AllocatorType GetAllocator() const { return AllocatorType(); }

    DequeAllocBase(const AllocatorType&) : mMap(0), mMapSize(0) {}

protected:
    typedef typename AllocTraits<Tp, Alloc>::AllocType NodeAllocType;
    typedef typename AllocTraits<Tp*, Alloc>::AllocType MapAllocType;

    Tp* AllocateNode()
    {
        return NodeAllocType::Allocate(__deque_buf_size(sizeof(Tp)));
    }
    void DeallocateNode(Tp* p)
    {
        NodeAllocType::Deallocate(p, __deque_buf_size(sizeof(Tp)));
    }
    Tp** AllocateMap(size_t n)
    { return MapAllocType::Allocate(n); }
    void DeallocateMap(Tp** p, size_t n)
    { MapAllocType::Deallocate(p, n); }

    Tp** mMap;
    size_t mMapSize;
};

/**
 *  @maint
 *  Deque base class.  Using _Alloc_traits in the instantiation of the parent
 *  class provides the compile-time dispatching mentioned in the parent's docs.
 *  This class provides the unified face for Deque's allocation.
 *
 *  Nothing in this class ever constructs or destroys an actual Tp element.
 *  (Deque handles that itself.)  Only/All memory management is performed here.
 *  @endmaint
*/
template <class Tp, class Alloc>
class DequeBase : public DequeAllocBase<Tp, Alloc, AllocTraits<Tp, Alloc>::S_instanceless>
{
public:
    typedef DequeAllocBase<Tp,Alloc,
             AllocTraits<Tp, Alloc>::S_instanceless> Base;
    typedef typename Base::AllocatorType           AllocatorType;
    typedef DequeIterator<Tp, Tp&, Tp*>             Iterator;
    typedef DequeIterator<Tp, const Tp&, const Tp*> ConstIterator;

    DequeBase(const AllocatorType& a, size_t numElements)
        : Base(a), mStart(), mFinish()
    { InitializeMap(numElements); }
    DequeBase(const AllocatorType& a)
        : Base(a), mStart(), mFinish() {}
    ~DequeBase();

protected:
    void InitializeMap(size_t);
    void CreateNodes(Tp** nstart, Tp** nfinish);
    void DestroyNodes(Tp** nstart, Tp** nfinish);
    enum { sInitialMapSize = 8 };

protected:
    using Base::mMap;
    using Base::mMapSize;
    using Base::AllocateNode;

    Iterator mStart;
    Iterator mFinish;
};


template <class Tp, class Alloc>
DequeBase<Tp, Alloc>::~DequeBase()
{
    if (mMap) {
        DestroyNodes(mStart.mNode, mFinish.mNode + 1);
        this->DeallocateMap(mMap, mMapSize);
    }
}

/**
 *  @maint
 *  @brief Layout storage.
 *  @param  num_elements  The count of T's for which to allocate space At first.
 *  @return   Nothing.
 *
 *  The initial underlying memory layout is a bit complicated...
 *  @endmaint
*/
template <class Tp, class Alloc>
void
DequeBase<Tp, Alloc>::InitializeMap(size_t numElements)
{
    size_t numNodes =
        numElements / __deque_buf_size(sizeof(Tp)) + 1;

    mMapSize = Max((size_t) sInitialMapSize, numNodes + 2);
    mMap = this->AllocateMap(mMapSize);

    Tp** nstart = mMap + (mMapSize - numNodes) / 2;
    Tp** nfinish = nstart + numNodes;

    try
    { CreateNodes(nstart, nfinish); }
    catch(...)
    {
        this->DeallocateMap(mMap, mMapSize);
        mMap = 0;
        mMapSize = 0;
        THROW_EXCEPTION_AGAIN;
    }

    mStart.SetNode(nstart);
    mFinish.SetNode(nfinish - 1);
    mStart.mCur = mStart.mFirst;
    mFinish.mCur = mFinish.mFirst +
        numElements % __deque_buf_size(sizeof(Tp));
}

template <class Tp, class Alloc>
void DequeBase<Tp,Alloc>::CreateNodes(Tp** nstart, Tp** nfinish)
{
    Tp** cur;
    try {
        for (cur = nstart; cur < nfinish; ++cur) {
            *cur = AllocateNode();
        }
    }
    catch(...)
    {
        DestroyNodes(nstart, cur);
        THROW_EXCEPTION_AGAIN;
    }
}

template <class Tp, class Alloc>
void
DequeBase<Tp,Alloc>::DestroyNodes(Tp** nstart, Tp** nfinish)
{
    for (Tp** n = nstart; n < nfinish; ++n) {
        this->DeallocateNode(*n);
    }
}


/**
 *  Placeholder:  see http://www.sgi.com/tech/stl/Deque.html for now.
 *
 *  In previous HP/SGI versions of Deque, there was an extra template parameter
 *  so users could control the node GetSize.  This extension turned out to violate
 *  the C++ standard (it can be detected using template template parameters),
 *  and it was removed.
 *
 *  @maint
 *  Here's how a Deque<Tp> manages memory.  Each Deque has 4 members:
 *
 *  - Tp**        mMap
 *  - size_t      mMapSize
 *  - Iterator    mStart, mFinish
 *
 *  map_size is At least 8.  map is an array of map_size pointers-to-"nodes".
 *
 *  A "node" has no specific type name as such, but it is referred to as
 *  "node" in this file.  It is a simple array-of-Tp.  If Tp is very large,
 *  there will be one Tp element per node (i.e., an "array" of one).
 *  For non-huge Tp's, node GetSize is inversely related to Tp GetSize:  the
 *  larger the Tp, the fewer Tp's will fit in a node.  The goal here is to
 *  keep the total GetSize of a node relatively small and constant over different
 *  Tp's, to improve allocator efficiency.
 *
 *  **** As I write this, the nodes are /not/ allocated using the high-speed
 *  memory pool.  There are 20 hours left in the year; perhaps I can fix
 *  this before 2002.
 *
 *  Not every Pointer in the map array will point to a node.  If the initial
 *  number of elements in the Deque is small, the /middle/ map pointers will
 *  be valid, and the ones At the edges will be unused.  This same situation
 *  will arise as the map grows:  available map pointers, if any, will be on
 *  the ends.  As new nodes are created, only a subset of the map's pointers
 *  need to be copied "outward".
 *
 *  Class invariants:
 * - For any nonsingular Iterator i:
 *    - i.node points to a member of the map array.  (Yes, you read that
 *      correctly:  i.node does not actually point to a node.)  The member of
 *      the map array is what actually points to the node.
 *    - i.first == *(i.node)    (This points to the node (first Tp element).)
 *    - i.last  == i.first + node_size
 *    - i.cur is a Pointer in the range [i.first, i.last).  NOTE:
 *      the implication of this is that i.cur is always a dereferenceable
 *      Pointer, even if i is a past-the-End Iterator.
 * - Start and Finish are always nonsingular iterators.  NOTE: this means that
 *   an IsEmpty Deque must have one node, a Deque with <N elements (where N is
 *   the node buffer GetSize) must have one node, a Deque with N through (2N-1)
 *   elements must have two nodes, etc.
 * - For every node other than start.node and finish.node, every element in the
 *   node is an initialized object.  If start.node == finish.node, then
 *   [start.cur, finish.cur) are initialized objects, and the elements outside
 *   that range are uninitialized storage.  Otherwise, [start.cur, start.last)
 *   and [finish.first, finish.cur) are initialized objects, and [start.first,
 *   start.cur) and [finish.cur, finish.last) are uninitialized storage.
 * - [map, map + map_size) is a valid, non-IsEmpty range.
 * - [start.node, finish.node] is a valid range contained within
 *   [map, map + map_size).
 * - A Pointer in the range [map, map + map_size) points to an allocated node
 *   if and only if the Pointer is in the range [start.node, finish.node].
 *
 *  Here's the magic:  nothing in Deque is "aware" of the discontiguous storage!
 *
 *  The memory setup and layout occurs in the parent, Base, and the Iterator
 *  class is entirely responsible for "leaping" from one node to the next.  All
 *  the implementation routines for Deque itself work only through the start
 *  and finish iterators.  This keeps the routines simple and sane, and we can
 *  use other standard algorithms as well.
 *
 *  @endmaint
*/
template <class Tp, class Alloc = Allocator<Tp> >
class Deque : protected DequeBase<Tp, Alloc>
            , public ElLightRefBase
{
    // concept requirements
    Concept_ClassRequires(Tp, SGIAssignableConcept)

    typedef DequeBase<Tp, Alloc> Base;

public:
    typedef Tp                                 ValueType;
    typedef ValueType*                        Pointer;
    typedef const ValueType*                  ConstPointer;
    typedef ValueType&                        Reference;
    typedef const ValueType&                  ConstReference;
    typedef size_t                             SizeType;
    typedef ptrdiff_t                          DifferenceType;

    typedef typename Base::AllocatorType AllocatorType;
    AllocatorType GetAllocator() const { return Base::GetAllocator(); }

    typedef typename Base::Iterator           Iterator;
    typedef typename Base::ConstIterator     ConstIterator;
    typedef _ETL ReverseIterator<ConstIterator>   ConstReverseIterator;
    typedef _ETL ReverseIterator<Iterator>         ReverseIterator;

protected:
    typedef Pointer* MapPointer;
    static size_t GetBufferSize() { return __deque_buf_size(sizeof(Tp)); }

    // Functions controlling memory layout, and nothing else.
    using Base::InitializeMap;
    using Base::CreateNodes;
    using Base::DestroyNodes;
    using Base::AllocateNode;
    using Base::DeallocateNode;
    using Base::AllocateMap;
    using Base::DeallocateMap;

    /** @maint
    *  A total of four data members accumulated down the heirarchy.  If the
    *  Alloc type requires separate instances, then two of them will also be
    *  included in each Deque.
    *  @endmaint
    */
    using Base::mMap;
    using Base::mMapSize;
    using Base::mStart;
    using Base::mFinish;

public:                         // Basic accessors
    Iterator Begin() { return mStart; }
    Iterator End() { return mFinish; }
    ConstIterator Begin() const { return mStart; }
    ConstIterator End() const { return mFinish; }

    ReverseIterator RBegin() { return ReverseIterator(mFinish); }
    ReverseIterator REnd() { return ReverseIterator(mStart); }
    ConstReverseIterator RBegin() const
    { return ConstReverseIterator(mFinish); }
    ConstReverseIterator REnd() const
    { return ConstReverseIterator(mStart); }

    Reference operator[](SizeType n)
    { return mStart[DifferenceType(n)]; }
    ConstReference operator[](SizeType n) const
    { return mStart[DifferenceType(n)]; }

    void RangeCheck(SizeType n) const
    {
        if (n >= this->GetSize()) {
            THROW_RANGE_ERROR("Deque");
        }
    }

    Reference At(SizeType n)
    { RangeCheck(n); return (*this)[n]; }
    ConstReference At(SizeType n) const
    { RangeCheck(n); return (*this)[n]; }

    Reference GetFront() { return *mStart; }
    Reference GetBack()
    {
        Iterator tmp = mFinish;
        --tmp;
        return *tmp;
    }
    ConstReference GetFront() const { return *mStart; }
    ConstReference GetBack() const
    {
        ConstIterator tmp = mFinish;
        --tmp;
        return *tmp;
    }

    SizeType GetSize() const { return mFinish - mStart; }
    SizeType GetMaxSize() const { return SizeType(-1); }
    Boolean IsEmpty() const { return mFinish == mStart; }

public:                         // Constructor, destructor.
    explicit Deque(const AllocatorType& a = AllocatorType())
        : Base(a, 0) {}
    Deque(const Deque& x) : Base(x.GetAllocator(), x.GetSize())
    { UninitializedCopy(x.Begin(), x.End(), mStart); }
    Deque(SizeType n, const ValueType& value,
        const AllocatorType& a = AllocatorType()) : Base(a, n)
    { FillInitialize(value); }

    explicit
    Deque(SizeType n)
        : Base(AllocatorType(), n)
    { FillInitialize(ValueType()); }

    // Check whether it's an integral type.  If so, it's not an Iterator.
    template<class InputIterator>
    Deque(InputIterator first, InputIterator last,
          const AllocatorType& a = AllocatorType())
    : Base(a)
    {
        typedef typename IsInteger<InputIterator>::Integral Integral;
        InitializeDispatch(first, last, Integral());
    }

    template<class Integer>
    void
    InitializeDispatch(Integer n, Integer x, TrueType)
    {
        InitializeMap(n);
        FillInitialize(x);
    }

    template<class InputIter>
    void
    InitializeDispatch(InputIter first, InputIter last, FalseType)
    {
        typedef typename IteratorTraits<InputIter>::IteratorCategory IterCategory;
        RangeInitialize(first, last, IterCategory());
    }

    ~Deque()
    { Destroy(mStart, mFinish); }

    Deque& operator= (const Deque& x)
    {
        const SizeType len = GetSize();
        if (&x != this) {
            if (len >= x.GetSize()) {
                Erase(Copy(x.Begin(), x.End(), mStart), mFinish);
            }
            else {
                ConstIterator mid = x.Begin() + DifferenceType(len);
                Copy(x.Begin(), mid, mStart);
                Insert(mFinish, mid, x.End());
            }
        }
        return *this;
    }

    void Swap(Deque& x)
    {
        _ETL Swap(mStart, x.mStart);
        _ETL Swap(mFinish, x.mFinish);
        _ETL Swap(mMap, x.mMap);
        _ETL Swap(mMapSize, x.mMapSize);
    }

public:
    // Assign(), a generalized assignment member function.  Two
    // versions: one that takes a count, and one that takes a range.
    // The range version is a member template, so we dispatch on whether
    // or not the type is an integer.

    void FillAssign(SizeType n, const Tp& val)
    {
        if (n > GetSize()) {
            Fill(Begin(), End(), val);
            Insert(End(), n - GetSize(), val);
        }
        else {
            Erase(Begin() + n, End());
            Fill(Begin(), End(), val);
        }
    }

    void
    Assign(SizeType n, const Tp& val)
    { FillAssign(n, val); }

    template<class InputIterator>
    void
    Assign(InputIterator first, InputIterator last)
    {
        typedef typename IsInteger<InputIterator>::Integral Integral;
        AssignDispatch(first, last, Integral());
    }

private:                        // helper functions for Assign()

  template<class Integer>
    void
    AssignDispatch(Integer n, Integer val, TrueType)
    { FillAssign(static_cast<SizeType>(n), static_cast<Tp>(val)); }

  template<class InputIterator>
    void
    AssignDispatch(InputIterator first, InputIterator last, FalseType)
    {
        typedef typename IteratorTraits<InputIterator>::IteratorCategory IterCategory;
        AssignAux(first, last, IterCategory());
    }

    template <class InputIterator>
    void AssignAux(InputIterator first, InputIterator last,
                     InputIteratorTag);

    template <class ForwardIterator>
    void AssignAux(ForwardIterator first, ForwardIterator last,
                     ForwardIteratorTag)
    {
        SizeType len = Distance(first, last);
        if (len > GetSize()) {
            ForwardIterator mid = first;
            Advance(mid, GetSize());
            Copy(first, mid, Begin());
            Insert(End(), mid, last);
        }
        else {
            Erase(Copy(first, last, Begin()), End());
        }
    }

public:                         // push_* and pop_*

    void
    PushBack(const ValueType& t)
    {
        if (mFinish.mCur != mFinish.mLast - 1) {
            Construct(mFinish.mCur, t);
            ++mFinish.mCur;
        }
        else {
            PushBackAux(t);
        }
    }

    void
    PushBack()
    {
    if (mFinish.mCur != mFinish.mLast - 1) {
        Construct(mFinish.mCur);
        ++mFinish.mCur;
    }
    else
        PushBackAux();
    }

    void
    PushFront(const ValueType& t)
    {
        if (mStart.mCur != mStart.mFirst) {
            Construct(mStart.mCur - 1, t);
            --mStart.mCur;
        }
        else {
            PushFrontAux(t);
        }
    }

    void
    PushFront()
    {
        if (mStart.mCur != mStart.mFirst) {
            Construct(mStart.mCur - 1);
            --mStart.mCur;
        }
        else {
            PushFrontAux();
        }
    }


    void
    PopBack()
    {
        if (mFinish.mCur != mFinish.mFirst) {
            --mFinish.mCur;
            Destroy(mFinish.mCur);
        }
        else {
            PopBackAux();
        }
    }

    void
    PopFront()
    {
        if (mStart.mCur != mStart.mLast - 1) {
            Destroy(mStart.mCur);
            ++mStart.mCur;
        }
        else {
            PopFrontAux();
        }
    }

public:                         // Insert

    Iterator
    Insert(Iterator position, const ValueType& x)
    {
        if (position.mCur == mStart.mCur) {
            PushFront(x);
            return mStart;
        }
        else if (position.mCur == mFinish.mCur) {
            PushBack(x);
            Iterator tmp = mFinish;
            --tmp;
            return tmp;
        }
        else {
            return InsertAux(position, x);
        }
    }

    Iterator
    Insert(Iterator position)
    { return Insert(position, ValueType()); }

    void
    Insert(Iterator pos, SizeType n, const ValueType& x)
    { FillInsert(pos, n, x); }

    void
    FillInsert(Iterator pos, SizeType n, const ValueType& x);

    // Check whether it's an integral type.  If so, it's not an Iterator.
    template<class InputIterator>
    void
    Insert(Iterator pos, InputIterator first, InputIterator last)
    {
        typedef typename IsInteger<InputIterator>::Integral Integral;
        InsertDispatch(pos, first, last, Integral());
    }

    template<class Integer>
    void
    InsertDispatch(Iterator pos, Integer n, Integer x, TrueType)
    { FillInsert(pos, static_cast<SizeType>(n), static_cast<ValueType>(x)); }

    template<class InputIterator>
    void
    InsertDispatch(Iterator pos,
                     InputIterator first, InputIterator last,
                     FalseType)
    {
        typedef typename IteratorTraits<InputIterator>::IteratorCategory IterCategory;
        Insert(pos, first, last, IterCategory());
    }

    void Resize(SizeType newSize, const ValueType& x)
    {
        const SizeType len = GetSize();
        if (newSize < len) {
            Erase(mStart + newSize, mFinish);
        }
        else {
            Insert(mFinish, newSize - len, x);
        }
    }

    void Resize(SizeType newSize) { Resize(newSize, ValueType()); }

public:                         // Erase
    Iterator Erase(Iterator pos)
    {
        Iterator next = pos;
        ++next;
        SizeType index = pos - mStart;
        if (index < (GetSize() >> 1)) {
            CopyBackward(mStart, pos, next);
            PopFront();
        }
        else {
            Copy(next, mFinish, pos);
            PopBack();
        }
        return mStart + index;
    }

    Iterator Erase(Iterator first, Iterator last);
    void Clear();

protected:                        // Internal construction/destruction

    void FillInitialize(const ValueType& value);

    template <class InputIterator>
    void RangeInitialize(InputIterator first, InputIterator last,
                        InputIteratorTag);

    template <class ForwardIterator>
    void RangeInitialize(ForwardIterator first, ForwardIterator last,
                        ForwardIteratorTag);

protected:                        // Internal push_* and pop_*

    void PushBackAux(const ValueType&);
    void PushBackAux();
    void PushFrontAux(const ValueType&);
    void PushFrontAux();
    void PopBackAux();
    void PopFrontAux();

protected:                        // Internal Insert functions

    template <class InputIterator>
    void Insert(Iterator pos, InputIterator first, InputIterator last,
              InputIteratorTag);

    template <class ForwardIterator>
    void Insert(Iterator pos,
              ForwardIterator first, ForwardIterator last,
              ForwardIteratorTag);

    Iterator InsertAux(Iterator pos, const ValueType& x);
    Iterator InsertAux(Iterator pos);
    void InsertAux(Iterator pos, SizeType n, const ValueType& x);

    template <class ForwardIterator>
    void InsertAux(Iterator pos,
                     ForwardIterator first, ForwardIterator last,
                     SizeType n);

    Iterator ReserveElementsAtFront(SizeType n)
    {
        SizeType vacancies = mStart.mCur - mStart.mFirst;
        if (n > vacancies) {
            NewElementsAtFront(n - vacancies);
        }
        return mStart - DifferenceType(n);
    }

    Iterator ReserveElementsAtBack(SizeType n)
    {
        SizeType vacancies = (mFinish.mLast - mFinish.mCur) - 1;
        if (n > vacancies) {
            NewElementsAtBack(n - vacancies);
        }
        return mFinish + DifferenceType(n);
    }

    void NewElementsAtFront(SizeType newElements);
    void NewElementsAtBack(SizeType newElements);

protected:                      // Allocation of mMap and nodes

    // Makes sure the mMap has space for new nodes.  Does not actually
    //  add the nodes.  Can invalidate mMap pointers.  (And consequently,
    //  Deque iterators.)

    void ReserveMapAtBack (SizeType nodesToAdd = 1)
    {
        if (nodesToAdd + 1 > mMapSize - (mFinish.mNode - mMap)) {
            ReallocateMap(nodesToAdd, FALSE);
        }
    }

    void ReserveMapAtFront (SizeType nodesToAdd = 1)
    {
        if (nodesToAdd > SizeType(mStart.mNode - mMap)) {
            ReallocateMap(nodesToAdd, TRUE);
        }
    }

    void ReallocateMap(SizeType nodesToAdd, Boolean addAtFront);
};

// Non-inline member functions

template <class Tp, class Alloc>
template <class InputIter>
void Deque<Tp, Alloc>::AssignAux(
    InputIter first, InputIter last, InputIteratorTag)
{
    Iterator cur = Begin();
    for (; first != last && cur != End(); ++cur, ++first)
    *cur = *first;
    if (first == last) {
        Erase(cur, End());
    }
    else {
        Insert(End(), first, last);
    }
}

template <class Tp, class Alloc>
void Deque<Tp, Alloc>::FillInsert(Iterator pos,
    SizeType n, const ValueType& x)
{
    if (pos.mCur == mStart.mCur) {
        Iterator newStart = ReserveElementsAtFront(n);
        try {
            UninitializedFill(newStart, mStart, x);
            mStart = newStart;
        }
        catch(...)
        {
            DestroyNodes(newStart.mNode, mStart.mNode);
            THROW_EXCEPTION_AGAIN;
        }
    }
    else if (pos.mCur == mFinish.mCur) {
        Iterator newFinish = ReserveElementsAtBack(n);
        try {
            UninitializedFill(mFinish, newFinish, x);
            mFinish = newFinish;
        }
        catch(...)
        {
            DestroyNodes(mFinish.mNode + 1, newFinish.mNode + 1);
            THROW_EXCEPTION_AGAIN;
        }
    }
    else {
        InsertAux(pos, n, x);
    }
}

template <class Tp, class Alloc>
typename Deque<Tp,Alloc>::Iterator
Deque<Tp, Alloc>::Erase(Iterator first, Iterator last)
{
    if (first == mStart && last == mFinish) {
        Clear();
        return mFinish;
    }
    else {
        DifferenceType n = last - first;
        DifferenceType elemsBefore = first - mStart;
        if (static_cast<SizeType>(elemsBefore) < (GetSize() - n) / 2) {
            CopyBackward(mStart, first, last);
            Iterator newStart = mStart + n;
            Destroy(mStart, newStart);
            DestroyNodes(mStart.mNode, newStart.mNode);
            mStart = newStart;
        }
        else {
            Copy(last, mFinish, first);
            Iterator newFinish = mFinish - n;
            Destroy(newFinish, mFinish);
            DestroyNodes(newFinish.mNode + 1, mFinish.mNode + 1);
            mFinish = newFinish;
        }
        return mStart + elemsBefore;
    }
}

template <class Tp, class Alloc>
void Deque<Tp, Alloc>::Clear()
{
    for (MapPointer node = mStart.mNode + 1;
       node < mFinish.mNode;
       ++node) {
        Destroy(*node, *node + GetBufferSize());
        DeallocateNode(*node);
    }

    if (mStart.mNode != mFinish.mNode) {
        Destroy(mStart.mCur, mStart.mLast);
        Destroy(mFinish.mFirst, mFinish.mCur);
        DeallocateNode(mFinish.mFirst);
    }
    else {
        Destroy(mStart.mCur, mFinish.mCur);
    }

    mFinish = mStart;
}

/**
 *  @maint
 *  @brief Fills the Deque with copies of value.
 *  @param  value  Initial value.
 *  @return   Nothing.
 *  @pre mStart and mFinish have already been initialized, but none of the
 *       Deque's elements have yet been constructed.
 *
 *  This function is called only when the user provides an explicit GetSize (with
 *  or without an explicit exemplar value).
 *  @endmaint
*/
template <class Tp, class Alloc>
void Deque<Tp, Alloc>::FillInitialize(const ValueType& value)
{
    MapPointer cur;
    try {
        for (cur = mStart.mNode; cur < mFinish.mNode; ++cur) {
            UninitializedFill(*cur, *cur + GetBufferSize(), value);
        }
        UninitializedFill(mFinish.mFirst, mFinish.mCur, value);
    }
    catch(...)
    {
        Destroy(mStart, Iterator(*cur, cur));
        THROW_EXCEPTION_AGAIN;
    }
}

/** @{
 *  @maint
 *  @brief Fills the Deque with whatever is in [first,last).
 *  @param  first  An input Iterator.
 *  @param  last  An input Iterator.
 *  @return   Nothing.
 *
 *  If the iterators are actually forward iterators (or better), then the
 *  memory layout can be done all at once.  Else we move forward using
 *  PushBack on each value from the Iterator.
 *  @endmaint
*/
template <class Tp, class Alloc> template <class InputIterator>
void Deque<Tp, Alloc>::RangeInitialize(InputIterator first,
                                            InputIterator last,
                                            InputIteratorTag)
{
    InitializeMap(0);
    try {
        for ( ; first != last; ++first) {
            PushBack(*first);
        }
    }
    catch(...)
    {
        Clear();
        THROW_EXCEPTION_AGAIN;
    }
}

template <class Tp, class Alloc> template <class ForwardIterator>
void Deque<Tp, Alloc>::RangeInitialize(ForwardIterator first,
                                           ForwardIterator last,
                                           ForwardIteratorTag)
{
    SizeType n = Distance(first, last);
    InitializeMap(n);

    MapPointer curNode;
    try {
        for (curNode = mStart.mNode;
             curNode < mFinish.mNode;
             ++curNode) {
            ForwardIterator mid = first;
            Advance(mid, GetBufferSize());
            UninitializedCopy(first, mid, *curNode);
            first = mid;
        }
        UninitializedCopy(first, last, mFinish.mFirst);
    }
    catch(...)
    {
        Destroy(mStart, Iterator(*curNode, curNode));
        THROW_EXCEPTION_AGAIN;
    }
}
/** @} */

// Called only if mFinish.mCur == mFinish.mLast - 1.
template <class Tp, class Alloc>
void
Deque<Tp,Alloc>::PushBackAux(const ValueType& t)
{
    ValueType tCopy = t;
    ReserveMapAtBack();
    *(mFinish.mNode + 1) = AllocateNode();
    try {
        Construct(mFinish.mCur, tCopy);
        mFinish.SetNode(mFinish.mNode + 1);
        mFinish.mCur = mFinish.mFirst;
    }
    catch(...)
    {
        DeallocateNode(*(mFinish.mNode + 1));
        THROW_EXCEPTION_AGAIN;
    }
}

// Called only if mFinish.mCur == mFinish.mLast - 1.
template <class Tp, class Alloc>
void
Deque<Tp, Alloc>::PushBackAux()
{
    ReserveMapAtBack();
    *(mFinish.mNode + 1) = AllocateNode();
    try {
        Construct(mFinish.mCur);
        mFinish.SetNode(mFinish.mNode + 1);
        mFinish.mCur = mFinish.mFirst;
    }
    catch(...)
    {
        DeallocateNode(*(mFinish.mNode + 1));
        THROW_EXCEPTION_AGAIN;
    }
}

// Called only if mStart.mCur == mStart.mFirst.
template <class Tp, class Alloc>
void
Deque<Tp, Alloc>::PushFrontAux(const ValueType& t)
{
    ValueType tCopy = t;
    ReserveMapAtFront();
    *(mStart.mNode - 1) = AllocateNode();
    try {
        mStart.SetNode(mStart.mNode - 1);
        mStart.mCur = mStart.mLast - 1;
        Construct(mStart.mCur, tCopy);
    }
    catch(...)
    {
        ++mStart;
        DeallocateNode(*(mStart.mNode - 1));
        THROW_EXCEPTION_AGAIN;
    }
}

// Called only if mStart.mCur == mStart.mFirst.
template <class Tp, class Alloc>
void
Deque<Tp, Alloc>::PushFrontAux()
{
    ReserveMapAtFront();
    *(mStart.mNode - 1) = AllocateNode();
    try {
        mStart.SetNode(mStart.mNode - 1);
        mStart.mCur = mStart.mLast - 1;
        Construct(mStart.mCur);
    }
    catch(...)
    {
        ++mStart;
        DeallocateNode(*(mStart.mNode - 1));
        THROW_EXCEPTION_AGAIN;
    }
}

// Called only if mFinish.mCur == mFinish.mFirst.
template <class Tp, class Alloc>
void Deque<Tp, Alloc>::PopBackAux()
{
    DeallocateNode(mFinish.mFirst);
    mFinish.SetNode(mFinish.mNode - 1);
    mFinish.mCur = mFinish.mLast - 1;
    Destroy(mFinish.mCur);
}

// Called only if mStart.mCur == mStart.mLast - 1.  Note that
// if the Deque has at least one element (a precondition for this member
// function), and if mStart.mCur == mStart.mLast, then the Deque
// must have at least two nodes.
template <class Tp, class Alloc>
void Deque<Tp,Alloc>::PopFrontAux()
{
    Destroy(mStart.mCur);
    DeallocateNode(mStart.mFirst);
    mStart.SetNode(mStart.mNode + 1);
    mStart.mCur = mStart.mFirst;
}

template <class Tp, class Alloc> template <class InputIterator>
void Deque<Tp, Alloc>::Insert(Iterator pos,
                               InputIterator first, InputIterator last,
                               InputIteratorTag)
{
    Copy(first, last, Inserter(*this, pos));
}

template <class Tp, class Alloc> template <class ForwardIterator>
void
Deque<Tp, Alloc>::Insert(Iterator pos,
                          ForwardIterator first, ForwardIterator last,
                          ForwardIteratorTag)
{
    SizeType n = Distance(first, last);
    if (pos.mCur == mStart.mCur) {
        Iterator newStart = ReserveElementsAtFront(n);
        try {
            UninitializedCopy(first, last, newStart);
            mStart = newStart;
        }
        catch(...)
        {
            DestroyNodes(newStart.mNode, mStart.mNode);
            THROW_EXCEPTION_AGAIN;
        }
    }
    else if (pos.mCur == mFinish.mCur) {
        Iterator newFinish = ReserveElementsAtBack(n);
        try {
            UninitializedCopy(first, last, mFinish);
            mFinish = newFinish;
        }
        catch(...)
        {
            DestroyNodes(mFinish.mNode + 1, newFinish.mNode + 1);
            THROW_EXCEPTION_AGAIN;
        }
    }
    else {
        InsertAux(pos, first, last, n);
    }
}

template <class Tp, class Alloc>
typename Deque<Tp, Alloc>::Iterator
Deque<Tp, Alloc>::InsertAux(Iterator pos, const ValueType& x)
{
    DifferenceType index = pos - mStart;
    ValueType xCopy = x;
    if (static_cast<SizeType>(index) < GetSize() / 2) {
        PushFront(GetFront());
        Iterator front1 = mStart;
        ++front1;
        Iterator front2 = front1;
        ++front2;
        pos = mStart + index;
        Iterator pos1 = pos;
        ++pos1;
        Copy(front2, pos1, front1);
    }
    else {
        PushBack(GetBack());
        Iterator back1 = mFinish;
        --back1;
        Iterator back2 = back1;
        --back2;
        pos = mStart + index;
        CopyBackward(pos, back2, back1);
    }
    *pos = xCopy;
    return pos;
}

template <class Tp, class Alloc>
typename Deque<Tp, Alloc>::Iterator
Deque<Tp, Alloc>::InsertAux(Iterator pos)
{
    DifferenceType index = pos - mStart;
    if (static_cast<SizeType>(index) < GetSize() / 2) {
        PushFront(GetFront());
        Iterator front1 = mStart;
        ++front1;
        Iterator front2 = front1;
        ++front2;
        pos = mStart + index;
        Iterator pos1 = pos;
        ++pos1;
        Copy(front2, pos1, front1);
    }
    else {
        PushBack(GetBack());
        Iterator back1 = mFinish;
        --back1;
        Iterator back2 = back1;
        --back2;
        pos = mStart + index;
        CopyBackward(pos, back2, back1);
    }
    *pos = ValueType();
    return pos;
}

template <class Tp, class Alloc>
void Deque<Tp, Alloc>::InsertAux(Iterator pos,
                                      SizeType n,
                                      const ValueType& x)
{
    const DifferenceType elemsBefore = pos - mStart;
    SizeType length = this->GetSize();
    ValueType xCopy = x;
    if (elemsBefore < DifferenceType(length / 2)) {
        Iterator newStart = ReserveElementsAtFront(n);
        Iterator oldStart = mStart;
        pos = mStart + elemsBefore;
        try {
            if (elemsBefore >= DifferenceType(n)) {
                Iterator startN = mStart + DifferenceType(n);
                UninitializedCopy(mStart, startN, newStart);
                mStart = newStart;
                Copy(startN, pos, oldStart);
                Fill(pos - DifferenceType(n), pos, xCopy);
            }
            else {
                UninitializedCopyFill(mStart, pos, newStart,
                                          mStart, xCopy);
                mStart = newStart;
                Fill(oldStart, pos, xCopy);
            }
        }
        catch(...)
        {
            DestroyNodes(newStart.mNode, mStart.mNode);
            THROW_EXCEPTION_AGAIN;
        }
    }
    else {
        Iterator newFinish = ReserveElementsAtBack(n);
        Iterator oldFinish = mFinish;
        const DifferenceType elemsAfter =
        DifferenceType(length) - elemsBefore;
        pos = mFinish - elemsAfter;
        try {
            if (elemsAfter > DifferenceType(n)) {
                Iterator FinishN = mFinish - DifferenceType(n);
                UninitializedCopy(FinishN, mFinish, mFinish);
                mFinish = newFinish;
                CopyBackward(pos, FinishN, oldFinish);
                Fill(pos, pos + DifferenceType(n), xCopy);
            }
            else {
                UninitializedFillCopy(mFinish, pos + DifferenceType(n),
                                          xCopy, pos, mFinish);
                mFinish = newFinish;
                Fill(pos, oldFinish, xCopy);
            }
        }
        catch(...)
        {
            DestroyNodes(mFinish.mNode + 1, newFinish.mNode + 1);
            THROW_EXCEPTION_AGAIN;
        }
    }
}

template <class Tp, class Alloc> template <class ForwardIterator>
void Deque<Tp, Alloc>::InsertAux(Iterator pos,
                                      ForwardIterator first,
                                      ForwardIterator last,
                                      SizeType n)
{
    const DifferenceType elemsBefore = pos - mStart;
    SizeType length = GetSize();
    if (static_cast<SizeType>(elemsBefore) < length / 2) {
        Iterator newStart = ReserveElementsAtFront(n);
        Iterator oldStart = mStart;
        pos = mStart + elemsBefore;
        try {
            if (elemsBefore >= DifferenceType(n)) {
                Iterator startN = mStart + DifferenceType(n);
                UninitializedCopy(mStart, startN, newStart);
                mStart = newStart;
                Copy(startN, pos, oldStart);
                Copy(first, last, pos - DifferenceType(n));
            }
            else {
                ForwardIterator mid = first;
                Advance(mid, DifferenceType(n) - elemsBefore);
                UninitializedCopyCopy(mStart, pos, first, mid,
                                          newStart);
                mStart = newStart;
                Copy(mid, last, oldStart);
            }
        }
        catch(...)
        {
            DestroyNodes(newStart.mNode, mStart.mNode);
            THROW_EXCEPTION_AGAIN;
        }
    }
    else {
        Iterator newFinish = ReserveElementsAtBack(n);
        Iterator oldFinish = mFinish;
        const DifferenceType elemsAfter =
        DifferenceType(length) - elemsBefore;
        pos = mFinish - elemsAfter;
        try {
            if (elemsAfter > DifferenceType(n)) {
                Iterator FinishN = mFinish - DifferenceType(n);
                UninitializedCopy(FinishN, mFinish, mFinish);
                mFinish = newFinish;
                CopyBackward(pos, FinishN, oldFinish);
                Copy(first, last, pos);
            }
            else {
                ForwardIterator mid = first;
                Advance(mid, elemsAfter);
                UninitializedCopyCopy(mid, last, pos, mFinish, mFinish);
                mFinish = newFinish;
                Copy(first, mid, pos);
            }
        }
        catch(...)
        {
            DestroyNodes(mFinish.mNode + 1, newFinish.mNode + 1);
            THROW_EXCEPTION_AGAIN;
        }
    }
}

template <class Tp, class Alloc>
void Deque<Tp, Alloc>::NewElementsAtFront(SizeType newElems)
{
    SizeType newNodes
            = (newElems + GetBufferSize() - 1) / GetBufferSize();
    ReserveMapAtFront(newNodes);
    SizeType i;
    try {
        for (i = 1; i <= newNodes; ++i) {
            *(mStart.mNode - i) = AllocateNode();
        }
    }
    catch(...) {
        for (SizeType j = 1; j < i; ++j) {
            DeallocateNode(*(mStart.mNode - j));
        }
        THROW_EXCEPTION_AGAIN;
    }
}

template <class Tp, class Alloc>
void Deque<Tp, Alloc>::NewElementsAtBack(SizeType newElems)
{
    SizeType newNodes
            = (newElems + GetBufferSize() - 1) / GetBufferSize();
    ReserveMapAtBack(newNodes);
    SizeType i;
    try {
        for (i = 1; i <= newNodes; ++i) {
            *(mFinish.mNode + i) = AllocateNode();
        }
    }
    catch(...) {
        for (SizeType j = 1; j < i; ++j) {
            DeallocateNode(*(mFinish.mNode + j));
        }
        THROW_EXCEPTION_AGAIN;
    }
}

template <class Tp, class Alloc>
void Deque<Tp, Alloc>::ReallocateMap(SizeType nodesToAdd,
                                          Boolean addAtFront)
{
    SizeType oldNumNodes = mFinish.mNode - mStart.mNode + 1;
    SizeType newNumNodes = oldNumNodes + nodesToAdd;

    MapPointer newNStart;
    if (mMapSize > 2 * newNumNodes) {
        newNStart = mMap + (mMapSize - newNumNodes) / 2
                 + (addAtFront ? nodesToAdd : 0);
        if (newNStart < mStart.mNode) {
            Copy(mStart.mNode, mFinish.mNode + 1, newNStart);
        }
        else {
            CopyBackward(mStart.mNode, mFinish.mNode + 1,
                    newNStart + oldNumNodes);
        }
    }
    else {
        SizeType newMapSize =
            mMapSize + Max(mMapSize, nodesToAdd) + 2;

        MapPointer newMap = AllocateMap(newMapSize);
        newNStart = newMap + (newMapSize - newNumNodes) / 2
                         + (addAtFront ? nodesToAdd : 0);
        Copy(mStart.mNode, mFinish.mNode + 1, newNStart);
        DeallocateMap(mMap, mMapSize);

        mMap = newMap;
        mMapSize = newMapSize;
    }

    mStart.SetNode(newNStart);
    mFinish.SetNode(newNStart + oldNumNodes - 1);
}


// Nonmember functions.

template <class Tp, class Alloc>
inline Boolean operator==(const Deque<Tp, Alloc>& x,
                       const Deque<Tp, Alloc>& y)
{
    return x.GetSize() == y.GetSize() &&
        Equal(x.Begin(), x.End(), y.Begin());
}

template <class Tp, class Alloc>
inline Boolean operator<(const Deque<Tp, Alloc>& x,
                      const Deque<Tp, Alloc>& y)
{
  return LexicographicalCompare(x.Begin(), x.End(),
                                 y.Begin(), y.End());
}

template <class Tp, class Alloc>
inline Boolean operator!=(const Deque<Tp, Alloc>& x,
                       const Deque<Tp, Alloc>& y)
{
  return !(x == y);
}

template <class Tp, class Alloc>
inline Boolean operator>(const Deque<Tp, Alloc>& x,
                      const Deque<Tp, Alloc>& y)
{
  return y < x;
}

template <class Tp, class Alloc>
inline Boolean operator<=(const Deque<Tp, Alloc>& x,
                       const Deque<Tp, Alloc>& y)
{
  return !(y < x);
}

template <class Tp, class Alloc>
inline Boolean operator>=(const Deque<Tp, Alloc>& x,
                       const Deque<Tp, Alloc>& y)
{
  return !(x < y);
}

template <class Tp, class Alloc>
inline void Swap(Deque<Tp, Alloc>& x, Deque<Tp, Alloc>& y)
{
    x.Swap(y);
}

_ETL_NAMESPACE_END

#endif //__ETL_DEQUE_H__
