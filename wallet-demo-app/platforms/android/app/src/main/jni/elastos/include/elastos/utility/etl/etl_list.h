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

#ifndef __ETL_LIST_H__
#define __ETL_LIST_H__

#include "elastos/utility/etl/etl_def.h"
#include "elastos/utility/etl/ConceptCheck.h"
#include <elrefbase.h>

using Elastos::ElLightRefBase;

_ETL_NAMESPACE_BEGIN

struct ListNodeBase
{
    ListNodeBase* mNext;
    ListNodeBase* mPrev;
};

template<typename T>
struct ListNode : public ListNodeBase
{
    T mData;
};

struct ListIteratorBase
{
    typedef size_t                      SizeType;
    typedef ptrdiff_t                   DifferenceType;
    typedef BidirectionalIteratorTag    IteratorCategory;

    ListNodeBase* mNode;

    ListIteratorBase(ListNodeBase* x) : mNode(x){}

    ListIteratorBase(){}

    void Incr() { mNode = mNode->mNext; }

    void Decr() { mNode = mNode->mPrev; }

    Boolean operator==(const ListIteratorBase& x) const
    {
        return mNode == x.mNode;
    }

    Boolean operator!=(const ListIteratorBase& x) const
    {
        return mNode != x.mNode;
    }
};

template<typename T, typename Ref, typename Ptr>
struct ListIterator : public ListIteratorBase
{
    typedef ListIterator<T, T&, T*>             Iterator;
    typedef ListIterator<T, const T&, const T*> ConstIterator;
    typedef ListIterator<T, Ref, Ptr>           Self;

    typedef T   ValueType;
    typedef Ptr Pointer;
    typedef Ref Reference;
    typedef ListNode<T> Node;

    ListIterator(Node* x) : ListIteratorBase(x) {}

    ListIterator() {}

    ListIterator(const Iterator& x) : ListIteratorBase(x.mNode) {}

    Reference operator*() const
    {
        return ((Node*)mNode)->mData;
    }

    Pointer operator->() const
    {
        return &(operator*());
    }

    Self& operator++()
    {
        this->Incr();
        return *this;
    }

    Self operator++(int)
    {
        Self tmp = *this;
        this->Incr();
        return tmp;
    }

    Self& operator--()
    {
        this->Decr();
        return *this;
    }

    Self operator--(int)
    {
        Self tmp = *this;
        this->Decr();
        return tmp;
    }
};

// Base class that encapsulates details of allocators.  Three cases:
// an ordinary standard-conforming allocator, a standard-conforming
// allocator with no non-static data, and an SGI-style allocator.
// This complexity is necessary only because we're worrying about backward
// compatibility and because we want to avoid wasting storage on an
// allocator instance if it isn't necessary.


// Base for general standard-conforming allocators.
template<typename T, typename Allocator, Boolean IsStatic>
class ListAllocBase
{
public:
    typedef typename AllocTraits<T, Allocator>::AllocatorType AllocatorType;

    AllocatorType GetAllocator() const
    {
        return mNodeAllocator;
    }

    ListAllocBase(const AllocatorType& a) : mNodeAllocator(a) {}

protected:
    ListNode<T>* GetNode()
    {
        return mNodeAllocator.Allocate(1);
    }

    void PutNode(ListNode<T>* p)
    {
        mNodeAllocator.Deallocate(p, 1);
    }

protected:
    typename AllocTraits<ListNode<T>, Allocator>::AllocatorType mNodeAllocator;

    ListNode<T>* mNode;
};

// Specialization for instanceless allocators.

template<typename T, typename Allocator>
class ListAllocBase<T, Allocator, true>
{
public:
    typedef typename AllocTraits<T, Allocator>::AllocatorType AllocatorType;

    AllocatorType GetAllocator() const
    {
        return AllocatorType();
    }

    ListAllocBase(const AllocatorType&) {}

protected:
    typedef typename AllocTraits<ListNode<T>, Allocator>::AllocType AllocType;

    ListNode<T>* GetNode()
    {
        return AllocType::Allocate(1);
    }

    void PutNode(ListNode<T>* p)
    {
        AllocType::Deallocate(p, 1);
    }

protected:
    ListNode<T>* mNode;
};

template<typename T, typename Alloc>
class ListBase : public ListAllocBase<T, Alloc, AllocTraits<T, Alloc>::S_instanceless>
{
public:
    typedef ListAllocBase<T, Alloc, AllocTraits<T, Alloc>::S_instanceless> Base;
    typedef typename Base::AllocatorType AllocatorType;

    ListBase(const AllocatorType& a) : Base(a)
    {
        Base::mNode = Base::GetNode();
        Base::mNode->mNext = Base::mNode;
        Base::mNode->mPrev = Base::mNode;
    }

    ~ListBase()
    {
        Clear();
        Base::PutNode(Base::mNode);
    }

    void Clear();
};

template<typename T, typename Alloc = Allocator<T> >
class List : protected ListBase<T, Alloc>
           , public ElLightRefBase
{
    // concept requirements
    Concept_ClassRequires(T, SGIAssignableConcept)

    typedef ListBase<T, Alloc> Base;
protected:
    typedef void* VoidPointer;

public:
    typedef T                   ValueType;
    typedef ValueType*          Pointer;
    typedef const ValueType*    ConstPointer;
    typedef ValueType&          Reference;
    typedef const ValueType&    ConstReference;
    typedef ListNode<T>         Node;
    typedef size_t              SizeType;
    typedef ptrdiff_t           DifferenceType;

    typedef typename Base::AllocatorType AllocatorType;

    typedef ListIterator<T, T&, T*>             Iterator;
    typedef ListIterator<T, const T&, const T*> ConstIterator;

    typedef _ETL ReverseIterator<ConstIterator>      ConstReverseIterator;
    typedef _ETL ReverseIterator<Iterator>           ReverseIterator;

protected:
    using Base::mNode;
    using Base::PutNode;
    using Base::GetNode;

protected:
    Node* CreateNode(const T& x)
    {
        Node* p = GetNode();
        try {
            Construct(&p->mData, x);
        }
        catch(...)
        {
            PutNode(p);
            THROW_EXCEPTION_AGAIN;
        }
        return p;
    }

    Node* CreateNode()
    {
        Node* p = GetNode();
        try {
            Construct(&p->mData);
        }
        catch(...)
        {
            PutNode(p);
            THROW_EXCEPTION_AGAIN;
        }
        return p;
    }

public:
    AllocatorType GetAllocator() const
    {
        return Base::GetAllocator();
    }

    explicit List(const AllocatorType& a = AllocatorType()) : Base(a) {}

    Iterator Begin()
    {
        return static_cast<Node*>(mNode->mNext);
    }

    ConstIterator Begin() const
    {
        return static_cast<Node*>(mNode->mNext);
    }

    Iterator End()
    {
        return mNode;
    }

    ConstIterator End() const
    {
        return mNode;
    }

    ReverseIterator RBegin()
    {
        return ReverseIterator(End());
    }

    ConstReverseIterator RBegin() const
    {
        return ConstReverseIterator(End());
    }

    ReverseIterator REnd()
    {
        return ReverseIterator(Begin());
    }

    ConstReverseIterator REnd() const
    {
        return ConstReverseIterator(Begin());
    }

    Boolean IsEmpty() const
    {
        return mNode->mNext == mNode;
    }

    SizeType GetSize() const
    {
        return Distance(Begin(), End());
    }

    SizeType GetMaxSize() const
    {
        return SizeType(-1);
    }

    Reference GetFront()
    {
        return *Begin();
    }

    ConstReference GetFront() const
    {
        return *Begin();
    }

    Reference GetBack()
    {
        return *(--End());
    }

    ConstReference GetBack() const
    {
        return *(--End());
    }

    Reference operator[](SizeType n)
    {
        Iterator next = Begin();
        for (; n > 0 && next != End(); --n) ++next;
        return *next;
    }

    ConstReference operator[](SizeType n) const
    {
        ConstIterator next = Begin();
        for (; n > 0 && next != End(); --n) ++next;
        return *next;
    }

    void Swap(List<T, Alloc>& x)
    {
        _ETL Swap(mNode, x.mNode);
    }

    Iterator Insert(Iterator position, const T& x)
    {
        Node* tmp = CreateNode(x);
        tmp->mNext = position.mNode;
        tmp->mPrev = position.mNode->mPrev;
        position.mNode->mPrev->mNext = tmp;
        position.mNode->mPrev = tmp;
        return tmp;
    }

    Iterator Insert(Iterator position)
    {
        return Insert(position, T());
    }

    Iterator Insert(SizeType n, const T& x)
    {
        Iterator next = Begin();
        for (; n > 0 && next != End(); --n) ++next;
        return Insert(next, x);
    }

    Iterator Insert(SizeType n)
    {
        return Insert(n, T());
    }

    // Check whether it's an integral type.  If so, it's not an Iterator.
    template<typename Integer>
    void InsertDispatch(Iterator pos, Integer n, Integer x, TrueType)
    {
        FillInsert(pos, (SizeType)n, (T)x);
    }

    template<typename InputIterator>
    void InsertDispatch(Iterator pos, InputIterator first, InputIterator last, FalseType);

    template<typename InputIterator>
    void Insert(Iterator pos, InputIterator first, InputIterator last)
    {
        typedef typename IsInteger<InputIterator>::Integral Integral;
        InsertDispatch(pos, first, last, Integral());
    }

    void Insert(Iterator pos, SizeType n, const T& x)
    {
        FillInsert(pos, n, x);
    }

    void FillInsert(Iterator pos, SizeType n, const T& x);

    void PushFront(const T& x)
    {
        Insert(Begin(), x);
    }

    void PushFront()
    {
        Insert(Begin());
    }

    void PushBack(const T& x)
    {
        Insert(End(), x);
    }

    void PushBack()
    {
        Insert(End());
    }

    Iterator Erase(Iterator position)
    {
        ListNodeBase* nextNode = position.mNode->mNext;
        ListNodeBase* prevNode = position.mNode->mPrev;
        Node* n = static_cast<Node*>(position.mNode);
        prevNode->mNext = nextNode;
        nextNode->mPrev = prevNode;
        Destroy(&n->mData);
        PutNode(n);
        return Iterator(static_cast<Node*>(nextNode));
    }

    Iterator Erase(Iterator first, Iterator last);

    void Clear()
    {
        Base::Clear();
    }

    void Resize(SizeType newSize, const T& x);

    void Resize(SizeType newSize)
    {
        this->Resize(newSize, T());
    }

    void PopFront()
    {
        Erase(Begin());
    }

    void PopBack()
    {
        Iterator tmp = End();
        Erase(--tmp);
    }

    List(SizeType n, const T& value, const AllocatorType& a = AllocatorType()) : Base(a)
    {
        Insert(Begin(), n, value);
    }

    explicit List(SizeType n) : Base(AllocatorType())
    {
        Insert(Begin(), n, T());
    }

    // We don't need any dispatching tricks here, because Insert does all of
    // that anyway.
    template<typename InputIterator>
    List(InputIterator first, InputIterator last,
            const AllocatorType& a = AllocatorType()) : Base(a)
    {
        Insert(Begin(), first, last);
    }

    List(const List<T, Alloc>& x) : Base(x.GetAllocator())
    {
        Insert(Begin(), x.Begin(), x.End());
    }

    ~List() {}

    List<T, Alloc>& operator=(const List<T, Alloc>& x);

public:
    // assign(), a generalized assignment member function.  Two
    // versions: one that takes a count, and one that takes a range.
    // The range version is a member template, so we dispatch on whether
    // or not the type is an integer.

    void Assign(SizeType n, const T& val)
    {
        FillAssign(n, val);
    }

    void FillAssign(SizeType n, const T& val);

    template<typename InputIterator>
    void Assign(InputIterator first, InputIterator last)
    {
        typedef typename IsInteger<InputIterator>::Integral Integral;
        AssignDispatch(first, last, Integral());
    }

    template<typename Integer>
    void AssignDispatch(Integer n, Integer val, TrueType)
    {
        FillAssign((SizeType)n, (T)val);
    }

    template<typename InputIterator>
    void AssignDispatch(InputIterator first, InputIterator last, FalseType);

protected:
    void Transfer(Iterator position, Iterator first, Iterator last)
    {
        if (position != last) {
            // Remove [first, last) from its old position.
            last.mNode->mPrev->mNext     = position.mNode;
            first.mNode->mPrev->mNext    = last.mNode;
            position.mNode->mPrev->mNext = first.mNode;

            // Splice [first, last) into its new position.
            ListNodeBase* tmp      = position.mNode->mPrev;
            position.mNode->mPrev = last.mNode->mPrev;
            last.mNode->mPrev     = first.mNode->mPrev;
            first.mNode->mPrev    = tmp;
        }
    }

public:
    void Splice(Iterator position, List& x)
    {
        if (!x.IsEmpty()) this->Transfer(position, x.Begin(), x.End());
    }

    void Splice(Iterator position, List&, Iterator i)
    {
        Iterator j = i;
        ++j;
        if (position == i || position == j) return;
        this->Transfer(position, i, j);
    }

    void Splice(Iterator position, List&, Iterator first, Iterator last)
    {
        if (first != last) this->Transfer(position, first, last);
    }

    void Remove(const T& value);

    void Remove(SizeType n);

    void Unique();

    void Merge(List& x);

    void Reverse();

    void Sort();

    template<typename Predicate>
    void RemoveIf(Predicate);

    template<typename BinaryPredicate>
    void Unique(BinaryPredicate);

    template<typename StrictWeakOrdering>
    void Merge(List&, StrictWeakOrdering);

    template<typename StrictWeakOrdering>
    void Sort(StrictWeakOrdering);
};

template<typename T, typename Alloc>
inline Boolean
operator==(const List<T,Alloc>& x, const List<T,Alloc>& y)
{
    typedef typename List<T,Alloc>::ConstIterator ConstIterator;
    ConstIterator end1 = x.End();
    ConstIterator end2 = y.End();

    ConstIterator i1 = x.Begin();
    ConstIterator i2 = y.Begin();
    while (i1 != end1 && i2 != end2 && *i1 == *i2) {
        ++i1;
        ++i2;
    }
    return i1 == end1 && i2 == end2;
}

template<typename T, typename Alloc>
inline Boolean
operator<(const List<T,Alloc>& x, const List<T,Alloc>& y)
{
    return LexicographicalCompare(x.Begin(), x.End(),
                                  y.Begin(), y.End());
}

template<typename T, typename Alloc>
inline Boolean
operator!=(const List<T,Alloc>& x, const List<T,Alloc>& y)
{
    return !(x == y);
}

template<typename T, typename Alloc>
inline Boolean
operator>(const List<T,Alloc>& x, const List<T,Alloc>& y)
{
    return y < x;
}

template<typename T, typename Alloc>
inline Boolean
operator<=(const List<T,Alloc>& x, const List<T,Alloc>& y)
{
    return !(y < x);
}

template<typename T, typename Alloc>
inline Boolean
operator>=(const List<T,Alloc>& x, const List<T,Alloc>& y)
{
    return !(x < y);
}

template<typename T, typename Alloc>
inline void Swap(List<T, Alloc>& x, List<T, Alloc>& y)
{
    x.Swap(y);
}

// move these to stl_list.tcc

template<typename T, typename Alloc>
void ListBase<T,Alloc>::Clear()
{
    ListNode<T>* cur = static_cast<ListNode<T>*>(Base::mNode->mNext);
    while (cur != Base::mNode) {
        ListNode<T>* tmp = cur;
        cur = static_cast<ListNode<T>*>(cur->mNext);
        Destroy(&tmp->mData);
        this->PutNode(tmp);
    }
    Base::mNode->mNext = Base::mNode;
    Base::mNode->mPrev = Base::mNode;
}

template<typename T, typename Alloc>
template <typename InputIterator>
void List<T, Alloc>::InsertDispatch(Iterator position,
        InputIterator first, InputIterator last, FalseType)
{
    for ( ; first != last; ++first) {
        Insert(position, *first);
    }

}

template<typename T, typename Alloc>
void List<T, Alloc>::FillInsert(Iterator position, SizeType n, const T& x)
{
    for ( ; n > 0; --n) {
        Insert(position, x);
    }
}

template<typename T, typename Alloc>
typename List<T,Alloc>::Iterator
List<T, Alloc>::Erase(Iterator first, Iterator last)
{
    while (first != last) {
        Erase(first++);
    }
    return last;
}

template<typename T, typename Alloc>
void List<T, Alloc>::Resize(SizeType newSize, const T& x)
{
    Iterator i = Begin();
    SizeType len = 0;
    for ( ; i != End() && len < newSize; ++i, ++len);
    if (len == newSize) {
        Erase(i, End());
    }
    else {                          // i == End()
        Insert(End(), newSize - len, x);
    }
}

template<typename T, typename Alloc>
List<T, Alloc>& List<T, Alloc>::operator=(const List<T, Alloc>& x)
{
    if (this != &x) {
        Iterator first1 = Begin();
        Iterator last1 = End();
        ConstIterator first2 = x.Begin();
        ConstIterator last2 = x.End();
        while (first1 != last1 && first2 != last2) {
            *first1++ = *first2++;
        }
        if (first2 == last2) {
            Erase(first1, last1);
        }
        else {
            Insert(last1, first2, last2);
        }
    }
    return *this;
}

template<typename T, typename Alloc>
void List<T, Alloc>::FillAssign(SizeType n, const T& val)
{
    Iterator i = Begin();
    for ( ; i != End() && n > 0; ++i, --n) {
        *i = val;
    }
    if (n > 0) {
        Insert(End(), n, val);
    }
    else {
        Erase(i, End());
    }
}

template<typename T, typename Alloc>
template <typename InputIterator>
void List<T, Alloc>::AssignDispatch(InputIterator first2, InputIterator last2, FalseType)
{
    Iterator first1 = Begin();
    Iterator last1 = End();
    for ( ; first1 != last1 && first2 != last2; ++first1, ++first2) {
        *first1 = *first2;
    }
    if (first2 == last2) {
        Erase(first1, last1);
    }
    else {
        Insert(last1, first2, last2);
    }
}

template<typename T, typename Alloc>
void List<T, Alloc>::Remove(const T& value)
{
    Iterator first = Begin();
    Iterator last = End();
    while (first != last) {
        Iterator next = first;
        ++next;
        if (*first == value) Erase(first);
        first = next;
    }
}

template<typename T, typename Alloc>
void List<T, Alloc>::Remove(SizeType n)
{
    Iterator next = Begin();
    for (; n > 0 && next != End(); --n) ++next;
    if (next != End()) Erase(next);
}

template<typename T, typename Alloc>
void List<T, Alloc>::Unique()
{
    Iterator first = Begin();
    Iterator last = End();
    if (first == last) return;
    Iterator next = first;
    while (++next != last) {
        if (*first == *next) {
            Erase(next);
        }
        else {
            first = next;
        }
        next = first;
    }
}

template<typename T, typename Alloc>
void List<T, Alloc>::Merge(List<T, Alloc>& x)
{
    Iterator first1 = Begin();
    Iterator last1 = End();
    Iterator first2 = x.Begin();
    Iterator last2 = x.End();
    while (first1 != last1 && first2 != last2) {
        if (*first2 < *first1) {
            Iterator next = first2;
            Transfer(first1, first2, ++next);
            first2 = next;
        }
        else {
            ++first1;
        }
    }
    if (first2 != last2) Transfer(last1, first2, last2);
}

inline void ListBaseReverse(ListNodeBase* p)
{
    ListNodeBase* tmp = p;
    do {
        _ETL Swap(tmp->mNext, tmp->mPrev);
        tmp = tmp->mPrev;     // Old next node is now prev.
    } while (tmp != p);
}

template<typename T, typename Alloc>
inline void List<T, Alloc>::Reverse()
{
    ListBaseReverse(this->mNode);
}

template<typename T, typename Alloc>
void List<T, Alloc>::Sort()
{
    // Do nothing if the list has length 0 or 1.
    if (mNode->mNext != mNode && mNode->mNext->mNext != mNode) {
        List<T, Alloc> carry;
        List<T, Alloc> counter[64];
        int fill = 0;
        while (!IsEmpty()) {
            carry.Splice(carry.Begin(), *this, Begin());
            int i = 0;
            while(i < fill && !counter[i].IsEmpty()) {
                counter[i].Merge(carry);
                carry.Swap(counter[i++]);
            }
            carry.Swap(counter[i]);
            if (i == fill) ++fill;
        }

        for (int i = 1; i < fill; ++i) {
            counter[i].Merge(counter[i-1]);
        }
        Swap(counter[fill-1]);
    }
}

template<typename T, typename Alloc>
template <typename Predicate>
void List<T, Alloc>::RemoveIf(Predicate pred)
{
    Iterator first = Begin();
    Iterator last = End();
    while (first != last) {
        Iterator next = first;
        ++next;
        if (pred(*first)) Erase(first);
        first = next;
    }
}

template<typename T, typename Alloc>
template <typename BinaryPredicate>
void List<T, Alloc>::Unique(BinaryPredicate binaryPred)
{
    Iterator first = Begin();
    Iterator last = End();
    if (first == last) return;
    Iterator next = first;
    while (++next != last) {
        if (binaryPred(*first, *next)) {
            Erase(next);
        }
        else {
            first = next;
        }
        next = first;
    }
}

template<typename T, typename Alloc>
template <typename StrictWeakOrdering>
void List<T, Alloc>::Merge(List<T, Alloc>& x, StrictWeakOrdering comp)
{
    Iterator first1 = Begin();
    Iterator last1 = End();
    Iterator first2 = x.Begin();
    Iterator last2 = x.End();
    while (first1 != last1 && first2 != last2) {
        if (comp(*first2, *first1)) {
            Iterator next = first2;
            Transfer(first1, first2, ++next);
            first2 = next;
        }
        else {
            ++first1;
        }
    }
    if (first2 != last2) Transfer(last1, first2, last2);
}

template<typename T, typename Alloc>
template <typename StrictWeakOrdering>
void List<T, Alloc>::Sort(StrictWeakOrdering comp)
{
    // Do nothing if the list has length 0 or 1.
    if (mNode->mNext != mNode && mNode->mNext->mNext != mNode) {
        List<T, Alloc> carry;
        List<T, Alloc> counter[64];
        int fill = 0;
        while (!IsEmpty()) {
            carry.Splice(carry.Begin(), *this, Begin());
            int i = 0;
            while(i < fill && !counter[i].IsEmpty()) {
                counter[i].Merge(carry, comp);
                carry.Swap(counter[i++]);
            }
            carry.Swap(counter[i]);
            if (i == fill) ++fill;
        }

        for (int i = 1; i < fill; ++i) {
            counter[i].Merge(counter[i-1], comp);
        }
        Swap(counter[fill-1]);
    }
}

_ETL_NAMESPACE_END

#endif //__ETL_LIST_H__
