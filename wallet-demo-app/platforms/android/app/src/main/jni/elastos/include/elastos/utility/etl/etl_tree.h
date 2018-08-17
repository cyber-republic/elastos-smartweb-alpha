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

#ifndef __ETL_TREE_H__
#define __ETL_TREE_H__

#include "elastos/utility/etl/etl_def.h"
#include "elastos/utility/etl/etl_algobase.h"
#include "elastos/utility/etl/etl_alloc.h"
#include "elastos/utility/etl/etl_construct.h"
#include "elastos/utility/etl/etl_function.h"
#include <elrefbase.h>

using Elastos::ElLightRefBase;

_ETL_NAMESPACE_BEGIN

typedef Boolean RBTreeColorType;
ECO_PUBLIC extern const RBTreeColorType S_RBTreeRed; // FALSE
ECO_PUBLIC extern const RBTreeColorType S_RBTreeBlack; // TRUE

struct RBTreeNodeBase
{
    typedef RBTreeColorType ColorType;
    typedef RBTreeNodeBase* BasePtr;

    ColorType mColor;
    BasePtr mParent;
    BasePtr mLeft;
    BasePtr mRight;

    static BasePtr S_GetMinimum(BasePtr x)
    {
        while (x->mLeft != 0) x = x->mLeft;
        return x;
    }

    static BasePtr S_GetMaximum(BasePtr x)
    {
        while (x->mRight != 0) x = x->mRight;
        return x;
    }
};

template <class Value>
struct RBTreeNode : public RBTreeNodeBase
{
    typedef RBTreeNode<Value>* LinkType;
    Value mValueField;
};

struct RBTreeBaseIterator
{
    typedef RBTreeNodeBase::BasePtr BasePtr;
    typedef BidirectionalIteratorTag IteratorCategory;
    typedef ptrdiff_t DifferenceType;
    BasePtr mNode;

    void Increment()
    {
        if (mNode->mRight != 0) {
            mNode = mNode->mRight;
            while (mNode->mLeft != 0)
            mNode = mNode->mLeft;
        }
        else {
            BasePtr y = mNode->mParent;
            while (mNode == y->mRight) {
                mNode = y;
                y = y->mParent;
            }
            if (mNode->mRight != y) mNode = y;
      }
    }

    void Decrement()
    {
        if (mNode->mColor == S_RBTreeRed &&
                mNode->mParent->mParent == mNode) {
            mNode = mNode->mRight;
        }
        else if (mNode->mLeft != 0) {
            BasePtr y = mNode->mLeft;
            while (y->mRight != 0) y = y->mRight;
            mNode = y;
        }
        else {
            BasePtr y = mNode->mParent;
            while (mNode == y->mLeft) {
                mNode = y;
                y = y->mParent;
            }
            mNode = y;
        }
    }
};

template <class Value, class Ref, class Ptr>
struct RBTreeIterator : public RBTreeBaseIterator
{
    typedef Value ValueType;
    typedef Ref Reference;
    typedef Ptr Pointer;
    typedef RBTreeIterator<Value, Value&, Value*> Iterator;
    typedef RBTreeIterator<Value, const Value&, const Value*> ConstIterator;
    typedef RBTreeIterator<Value, Ref, Ptr> Self;
    typedef RBTreeNode<Value>* LinkType;

    RBTreeIterator() {}
    RBTreeIterator(LinkType x) { mNode = x; }
    RBTreeIterator(const Iterator& it) { mNode = it.mNode; }

    Reference operator*() const { return LinkType(mNode)->mValueField; }
    Pointer operator->() const { return &(operator*()); }

    Self& operator++() { Increment(); return *this; }
    Self operator++(int)
    {
        Self tmp = *this;
        Increment();
        return tmp;
    }

    Self& operator--() { Decrement(); return *this; }
    Self operator--(int)
    {
        Self tmp = *this;
        Decrement();
        return tmp;
    }
};

template <class Value, class Ref, class Ptr>
inline Boolean operator==(const RBTreeIterator<Value, Ref, Ptr>& x,
        const RBTreeIterator<Value, Ref, Ptr>& y)
{
    return x.mNode == y.mNode;
}

template <class Value>
inline Boolean operator==(const RBTreeIterator<Value, const Value&, const Value*>& x,
        const RBTreeIterator<Value, Value&, Value*>& y)
{
    return x.mNode == y.mNode;
}

template <class Value>
inline Boolean operator==(const RBTreeIterator<Value, Value&, Value*>& x,
        const RBTreeIterator<Value, const Value&, const Value*>& y)
{
    return x.mNode == y.mNode;
}

template <class Value, class Ref, class Ptr>
inline Boolean operator!=(const RBTreeIterator<Value, Ref, Ptr>& x,
        const RBTreeIterator<Value, Ref, Ptr>& y)
{
    return x.mNode != y.mNode;
}

template <class Value>
inline Boolean operator!=(const RBTreeIterator<Value, const Value&, const Value*>& x,
        const RBTreeIterator<Value, Value&, Value*>& y)
{
    return x.mNode != y.mNode;
}

template <class Value>
inline Boolean operator!=(const RBTreeIterator<Value, Value&, Value*>& x,
        const RBTreeIterator<Value, const Value&, const Value*>& y)
{
    return x.mNode != y.mNode;
}

inline void
RBTreeRotateLeft(RBTreeNodeBase* x, RBTreeNodeBase*& root)
{
    RBTreeNodeBase* y = x->mRight;
    x->mRight = y->mLeft;
    if (y->mLeft !=0) y->mLeft->mParent = x;
    y->mParent = x->mParent;

    if (x == root) { root = y; }
    else if (x == x->mParent->mLeft) {
        x->mParent->mLeft = y;
    }
    else { x->mParent->mRight = y; }
    y->mLeft = x;
    x->mParent = y;
}

inline void
RBTreeRotateRight(RBTreeNodeBase* x, RBTreeNodeBase*& root)
{
    RBTreeNodeBase* y = x->mLeft;
    x->mLeft = y->mRight;
    if (y->mRight != 0) y->mRight->mParent = x;
    y->mParent = x->mParent;

    if (x == root) { root = y; }
    else if (x == x->mParent->mRight) {
        x->mParent->mRight = y;
    }
    else { x->mParent->mLeft = y; }
    y->mRight = x;
    x->mParent = y;
}

inline void
RBTreeRebalance(RBTreeNodeBase* x, RBTreeNodeBase*& root)
{
    x->mColor = S_RBTreeRed;
    while (x != root && x->mParent->mColor == S_RBTreeRed) {
        if (x->mParent == x->mParent->mParent->mLeft) {
            RBTreeNodeBase* y = x->mParent->mParent->mRight;
            if (y && y->mColor == S_RBTreeRed) {
                x->mParent->mColor = S_RBTreeBlack;
                y->mColor = S_RBTreeBlack;
                x->mParent->mParent->mColor = S_RBTreeRed;
                x = x->mParent->mParent;
            }
            else {
                if (x == x->mParent->mRight) {
                    x = x->mParent;
                    RBTreeRotateLeft(x, root);
                }
                x->mParent->mColor = S_RBTreeBlack;
                x->mParent->mParent->mColor = S_RBTreeRed;
                RBTreeRotateRight(x->mParent->mParent, root);
            }
        }
        else {
            RBTreeNodeBase* y = x->mParent->mParent->mLeft;
            if (y && y->mColor == S_RBTreeRed) {
                x->mParent->mColor = S_RBTreeBlack;
                y->mColor = S_RBTreeBlack;
                x->mParent->mParent->mColor = S_RBTreeRed;
                x = x->mParent->mParent;
            }
            else {
                if (x == x->mParent->mLeft) {
                    x = x->mParent;
                    RBTreeRotateRight(x, root);
                }
                x->mParent->mColor = S_RBTreeBlack;
                x->mParent->mParent->mColor = S_RBTreeRed;
                RBTreeRotateLeft(x->mParent->mParent, root);
            }
        }
    }
    root->mColor = S_RBTreeBlack;
}

inline RBTreeNodeBase*
RBTreeRebalanceForErase(RBTreeNodeBase* z,
                        RBTreeNodeBase*& root,
                        RBTreeNodeBase*& leftmost,
                        RBTreeNodeBase*& rightmost)
{
    RBTreeNodeBase* y = z;
    RBTreeNodeBase* x = 0;
    RBTreeNodeBase* xParent = 0;
    if (y->mLeft == 0) {     // z has at most one non-null child. y == z.
        x = y->mRight;     // x might be null.
    }
    else {
        if (y->mRight == 0) {  // z has exactly one non-null child. y == z.
            x = y->mLeft;    // x is not null.
        }
        else {                   // z has two non-null children.  Set y to
            y = y->mRight;   //   z's successor.  x might be null.
            while (y->mLeft != 0) y = y->mLeft;
            x = y->mRight;
        }
    }
    if (y != z) {          // relink y in place of z.  y is z's successor
        z->mLeft->mParent = y;
        y->mLeft = z->mLeft;
        if (y != z->mRight) {
            xParent = y->mParent;
            if (x) x->mParent = y->mParent;
            y->mParent->mLeft = x;      // y must be a child of mLeft
            y->mRight = z->mRight;
            z->mRight->mParent = y;
        }
        else {
            xParent = y;
        }
        if (root == z) {
            root = y;
        }
        else if (z->mParent->mLeft == z) {
            z->mParent->mLeft = y;
        }
        else {
            z->mParent->mRight = y;
        }
        y->mParent = z->mParent;
        _ETL Swap(y->mColor, z->mColor);
        y = z;
      // y now points to node to be actually deleted
    }
    else {                        // y == z
        xParent = y->mParent;
        if (x) x->mParent = y->mParent;
        if (root == z) {
            root = x;
        }
        else {
            if (z->mParent->mLeft == z) {
                z->mParent->mLeft = x;
            }
            else {
                z->mParent->mRight = x;
            }
        }
        if (leftmost == z) {
            if (z->mRight == 0) {       // z->mLeft must be null also
                leftmost = z->mParent;
            }
            // makes leftmost == mHeader if z == root
            else {
                leftmost = RBTreeNodeBase::S_GetMinimum(x);
            }
        }
        if (rightmost == z) {
            if (z->mLeft == 0) {        // z->mRight must be null also
                rightmost = z->mParent;
            }
            // makes rightmost == mHeader if z == root
            else {                      // x == z->mLeft
                rightmost = RBTreeNodeBase::S_GetMaximum(x);
            }
        }
    }
    if (y->mColor != S_RBTreeRed) {
        while (x != root && (x == 0 || x->mColor == S_RBTreeBlack)) {
            if (x == xParent->mLeft) {
                RBTreeNodeBase* w = xParent->mRight;
                if (w->mColor == S_RBTreeRed) {
                    w->mColor = S_RBTreeBlack;
                     xParent->mColor = S_RBTreeRed;
                    RBTreeRotateLeft(xParent, root);
                    w = xParent->mRight;
                }
                if ((w->mLeft == 0 ||
                     w->mLeft->mColor == S_RBTreeBlack) &&
                    (w->mRight == 0 ||
                     w->mRight->mColor == S_RBTreeBlack)) {
                    w->mColor = S_RBTreeRed;
                    x = xParent;
                    xParent = xParent->mParent;
                }
                else {
                    if (w->mRight == 0 ||
                        w->mRight->mColor == S_RBTreeBlack) {
                        if (w->mLeft) w->mLeft->mColor = S_RBTreeBlack;
                        w->mColor = S_RBTreeRed;
                        RBTreeRotateRight(w, root);
                        w = xParent->mRight;
                    }
                    w->mColor = xParent->mColor;
                    xParent->mColor = S_RBTreeBlack;
                    if (w->mRight) w->mRight->mColor = S_RBTreeBlack;
                    RBTreeRotateLeft(xParent, root);
                    break;
                }
            }
            else {                  // same as above, with mRight <-> mLeft.
                RBTreeNodeBase* w = xParent->mLeft;
                if (w->mColor == S_RBTreeRed) {
                    w->mColor = S_RBTreeBlack;
                    xParent->mColor = S_RBTreeRed;
                    RBTreeRotateRight(xParent, root);
                    w = xParent->mLeft;
                }
                if ((w->mRight == 0 ||
                     w->mRight->mColor == S_RBTreeBlack) &&
                    (w->mLeft == 0 ||
                     w->mLeft->mColor == S_RBTreeBlack)) {
                    w->mColor = S_RBTreeRed;
                    x = xParent;
                    xParent = xParent->mParent;
                }
                else {
                    if (w->mLeft == 0 ||
                        w->mLeft->mColor == S_RBTreeBlack) {
                        if (w->mRight) w->mRight->mColor = S_RBTreeBlack;
                        w->mColor = S_RBTreeRed;
                        RBTreeRotateLeft(w, root);
                        w = xParent->mLeft;
                    }
                    w->mColor = xParent->mColor;
                    xParent->mColor = S_RBTreeBlack;
                    if (w->mLeft) w->mLeft->mColor = S_RBTreeBlack;
                    RBTreeRotateRight(xParent, root);
                    break;
                }
            }
        }
        if (x) x->mColor = S_RBTreeBlack;
    }
    return y;
}

// Base class to encapsulate the differences between old SGI-style
// allocators and standard-conforming allocators.  In order to avoid
// having an IsEmpty base class, we arbitrarily move one of rb_tree's
// data members into the base class.

// Base for general standard-conforming allocators.
template <class T, class Alloc, Boolean S_instanceless>
class RBTreeAllocBase
{
public:
    typedef typename AllocTraits<T, Alloc>::AllocatorType AllocatorType;
    AllocatorType GetAllocator() const { return mNodeAllocator; }

    RBTreeAllocBase(const AllocatorType& a) : mNodeAllocator(a), mHeader(0) {}

protected:
    typename AllocTraits<RBTreeNode<T>, Alloc>::AllocatorType mNodeAllocator;
    RBTreeNode<T>* mHeader;

    RBTreeNode<T>* GetNode() { return mNodeAllocator.Allocate(1); }
    void PutNode(RBTreeNode<T>* p) { mNodeAllocator.Deallocate(p, 1); }
};

// Specialization for instanceless allocators.
template <class T, class Alloc>
class RBTreeAllocBase<T, Alloc, TRUE>
{
public:
    typedef typename AllocTraits<T, Alloc>::AllocatorType AllocatorType;
    AllocatorType GetAllocator() const { return AllocatorType(); }

    RBTreeAllocBase(const AllocatorType&) : mHeader(0) {}

protected:
    RBTreeNode<T>* mHeader;

    typedef typename AllocTraits<RBTreeNode<T>, Alloc>::AllocType AllocType;

    RBTreeNode<T>* GetNode() { return AllocType::Allocate(1); }
    void PutNode(RBTreeNode<T>* p) { AllocType::Deallocate(p, 1); }
};

template <class T, class Alloc>
struct RBTreeBase : public RBTreeAllocBase<T, Alloc, AllocTraits<T, Alloc>::S_instanceless>
{
    typedef RBTreeAllocBase<T, Alloc, AllocTraits<T, Alloc>::S_instanceless> Base;
    typedef typename Base::AllocatorType AllocatorType;

    RBTreeBase(const AllocatorType& a) : Base(a)
    {
        Base::mHeader = Base::GetNode();
    }
    ~RBTreeBase() { Base::PutNode(Base::mHeader); }
};

template <class Key, class Value, class KeyOfValue, class Compare,
          class Alloc = Allocator<Value> >
class RBTree : protected RBTreeBase<Value, Alloc>
             , public ElLightRefBase
{
    typedef RBTreeBase<Value, Alloc> Base;
protected:
    typedef RBTreeNodeBase* BasePtr;
    typedef RBTreeNode<Value> _RBTreeNode;
    typedef RBTreeColorType ColorType;
public:
    typedef Key KeyType;
    typedef Value ValueType;
    typedef ValueType* Pointer;
    typedef const ValueType* ConstPointer;
    typedef ValueType& Reference;
    typedef const ValueType& ConstReference;
    typedef _RBTreeNode* LinkType;
    typedef size_t SizeType;
    typedef ptrdiff_t DifferenceType;

    typedef typename Base::AllocatorType AllocatorType;
    AllocatorType GetAllocator() const { return Base::GetAllocator(); }

protected:
    using Base::GetNode;
    using Base::PutNode;
    using Base::mHeader;

protected:

    LinkType
    CreateNode(const ValueType& x)
    {
        LinkType tmp = GetNode();
        try {
            Construct(&tmp->mValueField, x);
        }
        catch(...) {
	        PutNode(tmp);
	        THROW_EXCEPTION_AGAIN;
        }
        return tmp;
    }

    LinkType CloneNode(LinkType x)
    {
        LinkType tmp = CreateNode(x->mValueField);
        tmp->mColor = x->mColor;
        tmp->mLeft = 0;
        tmp->mRight = 0;
        return tmp;
    }

    void
    DestroyNode(LinkType p)
    {
        Destroy(&p->mValueField);
        PutNode(p);
    }

protected:
    SizeType mNodeCount; // keeps track of GetSize of tree
    Compare mKeyCompare;

    LinkType& GetRoot() const
    {
        return (LinkType&) mHeader->mParent;
    }
    LinkType& GetLeftmost() const
    {
        return (LinkType&) mHeader->mLeft;
    }
    LinkType& GetRightmost() const
    {
        return (LinkType&) mHeader->mRight;
    }

    static LinkType& S_GetLeft(LinkType x)
    {
        return (LinkType&)(x->mLeft);
    }
    static LinkType& S_GetRight(LinkType x)
    {
        return (LinkType&)(x->mRight);
    }
    static LinkType& S_GetParent(LinkType x)
    {
        return (LinkType&)(x->mParent);
    }
    static Reference S_GetValue(LinkType x)
    {
        return x->mValueField;
    }
    static const Key& S_GetKey(LinkType x)
    {
        return KeyOfValue()(S_GetValue(x));
    }
    static ColorType& S_GetColor(LinkType x)
    {
        return (ColorType&)(x->mColor);
    }

    static LinkType& S_GetLeft(BasePtr x)
    {
        return (LinkType&)(x->mLeft);
    }
    static LinkType& S_GetRight(BasePtr x)
    {
        return (LinkType&)(x->mRight);
    }
    static LinkType& S_GetParent(BasePtr x)
    {
        return (LinkType&)(x->mParent);
    }
    static Reference S_GetValue(BasePtr x)
    {
        return ((LinkType)x)->mValueField;
    }
    static const Key& S_GetKey(BasePtr x)
    {
        return KeyOfValue()(S_GetValue(LinkType(x)));
    }
    static ColorType& S_GetColor(BasePtr x)
    {
        return (ColorType&)(LinkType(x)->mColor);
    }

    static LinkType S_GetMinimum(LinkType x)
    {
        return (LinkType)  RBTreeNodeBase::S_GetMinimum(x);
    }

    static LinkType S_GetMaximum(LinkType x)
    {
        return (LinkType) RBTreeNodeBase::S_GetMaximum(x);
    }

public:
    typedef RBTreeIterator<ValueType, Reference, Pointer> Iterator;
    typedef RBTreeIterator<ValueType, ConstReference, ConstPointer> ConstIterator;

    typedef _ETL ReverseIterator<ConstIterator> ConstReverseIterator;
    typedef _ETL ReverseIterator<Iterator> ReverseIterator;

private:
    Iterator Insert(BasePtr x, BasePtr y, const ValueType& v);
    LinkType Copy(LinkType x, LinkType p);
    void Erase(LinkType x);

public:
                                // allocation/deallocation
    RBTree() :
            Base(AllocatorType()), mNodeCount(0), mKeyCompare()
    {
        EmptyInitialize();
    }

    RBTree(const Compare& comp) :
            Base(AllocatorType()), mNodeCount(0), mKeyCompare(comp)
    {
        EmptyInitialize();
    }

    RBTree(const Compare& comp, const AllocatorType& a) :
            Base(a), mNodeCount(0), mKeyCompare(comp)
    {
        EmptyInitialize();
    }

    RBTree(const RBTree<Key,Value,KeyOfValue,Compare,Alloc>& x) :
            Base(x.GetAllocator()), mNodeCount(0), mKeyCompare(x.mKeyCompare)
    {
        if (x.GetRoot() == 0) {
            EmptyInitialize();
        }
        else {
            S_GetColor(mHeader) = S_RBTreeRed;
            GetRoot() = Copy(x.GetRoot(), mHeader);
            GetLeftmost() = S_GetMinimum(GetRoot());
            GetRightmost() = S_GetMaximum(GetRoot());
        }
        mNodeCount = x.mNodeCount;
    }

    ~RBTree() { Clear(); }

    RBTree<Key,Value,KeyOfValue,Compare,Alloc>&
    operator=(const RBTree<Key,Value,KeyOfValue,Compare,Alloc>& x);

private:
    void EmptyInitialize()
    {
        S_GetColor(mHeader) = S_RBTreeRed; // used to distinguish header from
                                          // root, in Iterator.operator++
        GetRoot() = 0;
        GetLeftmost() = mHeader;
        GetRightmost() = mHeader;
    }

public:
                                // accessors:
    Compare KeyComp() const { return mKeyCompare; }
    Iterator Begin() { return GetLeftmost(); }
    ConstIterator Begin() const { return GetLeftmost(); }
    Iterator End() { return mHeader; }
    ConstIterator End() const { return mHeader; }
    ReverseIterator RBegin() { return ReverseIterator(End()); }
    ConstReverseIterator RBegin() const
    {
        return ConstReverseIterator(End());
    }
    ReverseIterator REnd() { return ReverseIterator(Begin()); }
    ConstReverseIterator REnd() const
    {
      return ConstReverseIterator(Begin());
    }
    Boolean IsEmpty() const { return mNodeCount == 0; }
    SizeType GetSize() const { return mNodeCount; }
    SizeType GetMaxSize() const { return SizeType(-1); }

    void Swap(RBTree<Key,Value,KeyOfValue,Compare,Alloc>& t)
    {
        _ETL Swap(mHeader, t.mHeader);
        _ETL Swap(mNodeCount, t.mNodeCount);
        _ETL Swap(mKeyCompare, t.mKeyCompare);
    }

public:
                                // insert/Erase
    Pair<Iterator,Boolean> InsertUnique(const ValueType& x);
    Iterator InsertEqual(const ValueType& x);

    Iterator InsertUnique(Iterator position, const ValueType& x);
    Iterator InsertEqual(Iterator position, const ValueType& x);

    template <class InputIterator>
    void InsertUnique(InputIterator first, InputIterator last);
    template <class InputIterator>
    void InsertEqual(InputIterator first, InputIterator last);

    void Erase(Iterator position);
    SizeType Erase(const KeyType& x);
    void Erase(Iterator first, Iterator last);
    void Erase(const KeyType* first, const KeyType* last);
    void Clear()
    {
        if (mNodeCount != 0) {
            Erase(GetRoot());
            GetLeftmost() = mHeader;
            GetRoot() = 0;
            GetRightmost() = mHeader;
            mNodeCount = 0;
        }
    }

public:
                                // set operations:
    Iterator Find(const KeyType& x);
    ConstIterator Find(const KeyType& x) const;
    SizeType GetCount(const KeyType& x) const;
    Iterator GetLowerBound(const KeyType& x);
    ConstIterator GetLowerBound(const KeyType& x) const;
    Iterator GetUpperBound(const KeyType& x);
    ConstIterator GetUpperBound(const KeyType& x) const;
    Pair<Iterator,Iterator> GetEqualRange(const KeyType& x);
    Pair<ConstIterator, ConstIterator> GetEqualRange(const KeyType& x) const;

public:
                                // Debugging.
    Boolean RBVerify() const;
};

template <class Key, class Value, class KeyOfValue,
          class Compare, class Alloc>
inline Boolean
operator==(const RBTree<Key,Value,KeyOfValue,Compare,Alloc>& x,
           const RBTree<Key,Value,KeyOfValue,Compare,Alloc>& y)
{
    return x.GetSize() == y.GetSize() &&
            Equal(x.Begin(), x.End(), y.Begin());
}

template <class Key, class Value, class KeyOfValue,
          class Compare, class Alloc>
inline Boolean
operator<(const RBTree<Key,Value,KeyOfValue,Compare,Alloc>& x,
          const RBTree<Key,Value,KeyOfValue,Compare,Alloc>& y)
{
    return LexicographicalCompare(x.Begin(), x.End(),
                                  y.Begin(), y.End());
}

template <class Key, class Value, class KeyOfValue,
          class Compare, class Alloc>
inline Boolean
operator!=(const RBTree<Key,Value,KeyOfValue,Compare,Alloc>& x,
           const RBTree<Key,Value,KeyOfValue,Compare,Alloc>& y)
{
    return !(x == y);
}

template <class Key, class Value, class KeyOfValue,
          class Compare, class Alloc>
inline Boolean
operator>(const RBTree<Key,Value,KeyOfValue,Compare,Alloc>& x,
          const RBTree<Key,Value,KeyOfValue,Compare,Alloc>& y)
{
    return y < x;
}

template <class Key, class Value, class KeyOfValue,
          class Compare, class Alloc>
inline Boolean
operator<=(const RBTree<Key,Value,KeyOfValue,Compare,Alloc>& x,
           const RBTree<Key,Value,KeyOfValue,Compare,Alloc>& y)
{
    return !(y < x);
}

template <class Key, class Value, class KeyOfValue,
          class Compare, class Alloc>
inline Boolean
operator>=(const RBTree<Key,Value,KeyOfValue,Compare,Alloc>& x,
           const RBTree<Key,Value,KeyOfValue,Compare,Alloc>& y)
{
    return !(x < y);
}


template <class Key, class Value, class KeyOfValue,
          class Compare, class Alloc>
inline void
Swap(RBTree<Key,Value,KeyOfValue,Compare,Alloc>& x,
     RBTree<Key,Value,KeyOfValue,Compare,Alloc>& y)
{
    x.Swap(y);
}

template <class Key, class Value, class KeyOfValue,
          class Compare, class Alloc>
RBTree<Key,Value,KeyOfValue,Compare,Alloc>&
RBTree<Key,Value,KeyOfValue,Compare,Alloc>::
operator=(const RBTree<Key,Value,KeyOfValue,Compare,Alloc>& x)
{
    if (this != &x) {
                                // Note that Key may be a constant type.
        Clear();
        mNodeCount = 0;
        mKeyCompare = x.mKeyCompare;
        if (x.GetRoot() == 0) {
            GetRoot() = 0;
            GetLeftmost() = mHeader;
            GetRightmost() = mHeader;
        }
        else {
            GetRoot() = Copy(x.GetRoot(), mHeader);
            GetLeftmost() = S_GetMinimum(GetRoot());
            GetRightmost() = S_GetMaximum(GetRoot());
            mNodeCount = x.mNodeCount;
        }
    }
    return *this;
}

template <class Key, class Value, class KeyOfValue,
          class Compare, class Alloc>
typename RBTree<Key,Value,KeyOfValue,Compare,Alloc>::Iterator
RBTree<Key,Value,KeyOfValue,Compare,Alloc>::
Insert(BasePtr __x, BasePtr __y, const Value& v)
{
    LinkType x = (LinkType) __x;
    LinkType y = (LinkType) __y;
    LinkType z;

    if (y == mHeader || x != 0 ||
            mKeyCompare(KeyOfValue()(v), S_GetKey(y))) {
        z = CreateNode(v);
        S_GetLeft(y) = z;               // also makes GetLeftmost() = z
                                        //    when y == mHeader
        if (y == mHeader) {
            GetRoot() = z;
            GetRightmost() = z;
        }
        else if (y == GetLeftmost()) {
            GetLeftmost() = z;   // maintain GetLeftmost() pointing to min node
        }
    }
    else {
        z = CreateNode(v);
        S_GetRight(y) = z;
        if (y == GetRightmost()) {
            GetRightmost() = z;  // maintain GetRightmost() pointing to max node
        }
    }
    S_GetParent(z) = y;
    S_GetLeft(z) = 0;
    S_GetRight(z) = 0;
    RBTreeRebalance(z, mHeader->mParent);
    ++mNodeCount;
    return Iterator(z);
}

template <class Key, class Value, class KeyOfValue,
          class Compare, class Alloc>
typename RBTree<Key,Value,KeyOfValue,Compare,Alloc>::Iterator
RBTree<Key,Value,KeyOfValue,Compare,Alloc>::
InsertEqual(const Value& v)
{
    LinkType y = mHeader;
    LinkType x = GetRoot();
    while (x != 0) {
        y = x;
        x = mKeyCompare(KeyOfValue()(v), S_GetKey(x)) ?
                S_GetLeft(x) : S_GetRight(x);
    }
    return Insert(x, y, v);
}


template <class Key, class Value, class KeyOfValue,
          class Compare, class Alloc>
Pair<typename RBTree<Key,Value,KeyOfValue,Compare,Alloc>::Iterator, Boolean>
RBTree<Key,Value,KeyOfValue,Compare,Alloc>::
InsertUnique(const Value& v)
{
    LinkType y = mHeader;
    LinkType x = GetRoot();
    Boolean comp = TRUE;
    while (x != 0) {
        y = x;
        comp = mKeyCompare(KeyOfValue()(v), S_GetKey(x));
        x = comp ? S_GetLeft(x) : S_GetRight(x);
    }
    Iterator j = Iterator(y);
    if (comp) {
        if (j == Begin()) {
            return Pair<Iterator,Boolean>(Insert(x, y, v), TRUE);
        }
        else {
            --j;
        }
    }
    if (mKeyCompare(S_GetKey(j.mNode), KeyOfValue()(v))) {
        return Pair<Iterator,Boolean>(Insert(x, y, v), TRUE);
    }
    return Pair<Iterator,Boolean>(j, FALSE);
}


template <class Key, class Val, class KeyOfValue,
          class Compare, class Alloc>
typename RBTree<Key, Val, KeyOfValue, Compare, Alloc>::Iterator
RBTree<Key, Val, KeyOfValue, Compare, Alloc>::
InsertUnique(Iterator position, const Val& v)
{
    if (position.mNode == mHeader->mLeft) { // Begin()
        if (GetSize() > 0 &&
            mKeyCompare(KeyOfValue()(v), S_GetKey(position.mNode))) {
            return Insert(position.mNode, position.mNode, v);
        }
        // first argument just needs to be non-null
        else {
            return InsertUnique(v).mFirst;
        }
    }
    else if (position.mNode == mHeader) { // End()
        if (mKeyCompare(S_GetKey(GetRightmost()), KeyOfValue()(v))) {
            return Insert(0, GetRightmost(), v);
        }
        else {
            return InsertUnique(v).mFirst;
        }
    }
    else {
        Iterator before = position;
        --before;
        if (mKeyCompare(S_GetKey(before.mNode), KeyOfValue()(v))
                && mKeyCompare(KeyOfValue()(v), S_GetKey(position.mNode))) {
            if (S_GetRight(before.mNode) == 0) {
                return Insert(0, before.mNode, v);
            }
            else {
                return Insert(position.mNode, position.mNode, v);
            }
        // first argument just needs to be non-null
        } else {
            return InsertUnique(v).mFirst;
        }
    }
}

template <class Key, class Val, class KeyOfValue,
          class Compare, class Alloc>
typename RBTree<Key,Val,KeyOfValue,Compare,Alloc>::Iterator
RBTree<Key,Val,KeyOfValue,Compare,Alloc>::
InsertEqual(Iterator position, const Val& v)
{
    if (position.mNode == mHeader->mLeft) { // Begin()
        if (GetSize() > 0 &&
	        !mKeyCompare(S_GetKey(position.mNode), KeyOfValue()(v))) {
            return Insert(position.mNode, position.mNode, v);
        }
        // first argument just needs to be non-null
        else {
            return InsertEqual(v);
        }
    }
    else if (position.mNode == mHeader) {// End()
        if (!mKeyCompare(KeyOfValue()(v), S_GetKey(GetRightmost()))) {
            return Insert(0, GetRightmost(), v);
        }
        else {
            return InsertEqual(v);
        }
    }
    else {
        Iterator before = position;
        --before;
        if (!mKeyCompare(KeyOfValue()(v), S_GetKey(before.mNode))
                && !mKeyCompare(S_GetKey(position.mNode), KeyOfValue()(v))) {
            if (S_GetRight(before.mNode) == 0) {
                return Insert(0, before.mNode, v);
            }
            else {
                return Insert(position.mNode, position.mNode, v);
            }
        // first argument just needs to be non-null
        }
        else {
            return InsertEqual(v);
        }
    }
}

template <class Key, class Val, class KoV, class Cmp, class Alloc>
  template<class II>
void RBTree<Key,Val,KoV,Cmp,Alloc>::
InsertEqual(II first, II last)
{
    for ( ; first != last; ++first) {
        InsertEqual(*first);
    }
}

template <class Key, class Val, class KoV, class Cmp, class Alloc>
  template<class II>
void RBTree<Key,Val,KoV,Cmp,Alloc>::
InsertUnique(II first, II last)
{
    for ( ; first != last; ++first) {
        InsertUnique(*first);
    }
}

template <class Key, class Value, class KeyOfValue,
          class Compare, class Alloc>
inline void RBTree<Key,Value,KeyOfValue,Compare,Alloc>::
Erase(Iterator position)
{
    LinkType y =
        (LinkType) RBTreeRebalanceForErase(position.mNode,
                                           mHeader->mParent,
                                           mHeader->mLeft,
                                           mHeader->mRight);
    DestroyNode(y);
    --mNodeCount;
}

template <class Key, class Value, class KeyOfValue,
          class Compare, class Alloc>
typename RBTree<Key,Value,KeyOfValue,Compare,Alloc>::SizeType
RBTree<Key,Value,KeyOfValue,Compare,Alloc>::Erase(const Key& x)
{
    Pair<Iterator,Iterator> p = GetEqualRange(x);
    SizeType n = Distance(p.mFirst, p.mSecond);
    Erase(p.mFirst, p.mSecond);
    return n;
}

template <class Key, class Val, class KoV, class Compare, class Alloc>
typename RBTree<Key, Val, KoV, Compare, Alloc>::LinkType
RBTree<Key,Val,KoV,Compare,Alloc>::
Copy(LinkType x, LinkType p)
{
                        // structural copy.  x and p must be non-null.
    LinkType top = CloneNode(x);
    top->mParent = p;

    try {
        if (x->mRight) {
            top->mRight = Copy(S_GetRight(x), top);
        }
        p = top;
        x = S_GetLeft(x);

        while (x != 0) {
            LinkType y = CloneNode(x);
            p->mLeft = y;
            y->mParent = p;
            if (x->mRight) {
                y->mRight = Copy(S_GetRight(x), y);
            }
            p = y;
            x = S_GetLeft(x);
        }
    }
    catch(...) {
        Erase(top);
        THROW_EXCEPTION_AGAIN;
    }
    return top;
}

template <class Key, class Value, class KeyOfValue,
          class Compare, class Alloc>
void RBTree<Key,Value,KeyOfValue,Compare,Alloc>::
Erase(LinkType x)
{
                              // erase without rebalancing
    while (x != 0) {
        Erase(S_GetRight(x));
        LinkType y = S_GetLeft(x);
        DestroyNode(x);
        x = y;
    }
}

template <class Key, class Value, class KeyOfValue,
          class Compare, class Alloc>
void RBTree<Key,Value,KeyOfValue,Compare,Alloc>::
Erase(Iterator first, Iterator last)
{
    if (first == Begin() && last == End()) {
        Clear();
    }
    else {
        while (first != last) Erase(first++);
    }
}

template <class Key, class Value, class KeyOfValue,
          class Compare, class Alloc>
void RBTree<Key,Value,KeyOfValue,Compare,Alloc>::
Erase(const Key* first, const Key* last)
{
    while (first != last) Erase(*first++);
}

template <class Key, class Value, class KeyOfValue,
          class Compare, class Alloc>
typename RBTree<Key,Value,KeyOfValue,Compare,Alloc>::Iterator
RBTree<Key,Value,KeyOfValue,Compare,Alloc>::Find(const Key& k)
{
    LinkType y = mHeader;      // Last node which is not less than k.
    LinkType x = GetRoot();      // Current node.

    while (x != 0) {
        if (!mKeyCompare(S_GetKey(x), k)) {
            y = x, x = S_GetLeft(x);
        }
        else {
            x = S_GetRight(x);
        }
    }

    Iterator j = Iterator(y);
    return (j == End() || mKeyCompare(k, S_GetKey(j.mNode))) ? End() : j;
}

template <class Key, class Value, class KeyOfValue,
          class Compare, class Alloc>
typename RBTree<Key,Value,KeyOfValue,Compare,Alloc>::ConstIterator
RBTree<Key,Value,KeyOfValue,Compare,Alloc>::Find(const Key& k) const
{
    LinkType y = mHeader; /* Last node which is not less than k. */
    LinkType x = GetRoot(); /* Current node. */

    while (x != 0) {
        if (!mKeyCompare(S_GetKey(x), k)) {
            y = x, x = S_GetLeft(x);
        }
        else {
            x = S_GetRight(x);
        }
    }
    ConstIterator j = ConstIterator(y);
    return (j == End() || mKeyCompare(k, S_GetKey(j.mNode))) ? End() : j;
}

template <class Key, class Value, class KeyOfValue,
          class Compare, class Alloc>
typename RBTree<Key,Value,KeyOfValue,Compare,Alloc>::SizeType
RBTree<Key,Value,KeyOfValue,Compare,Alloc>::
GetCount(const Key& k) const
{
    Pair<ConstIterator, ConstIterator> p = GetEqualRange(k);
    SizeType n = Distance(p.mFirst, p.mSecond);
    return n;
}

template <class Key, class Value, class KeyOfValue,
          class Compare, class Alloc>
typename RBTree<Key,Value,KeyOfValue,Compare,Alloc>::Iterator
RBTree<Key,Value,KeyOfValue,Compare,Alloc>::
GetLowerBound(const Key& k)
{
    LinkType y = mHeader; /* Last node which is not less than k. */
    LinkType x = GetRoot(); /* Current node. */

    while (x != 0) {
        if (!mKeyCompare(S_GetKey(x), k)) {
            y = x, x = S_GetLeft(x);
        }
        else {
            x = S_GetRight(x);
        }
    }

    return Iterator(y);
}

template <class Key, class Value, class KeyOfValue,
          class Compare, class Alloc>
typename RBTree<Key,Value,KeyOfValue,Compare,Alloc>::ConstIterator
RBTree<Key,Value,KeyOfValue,Compare,Alloc>::
GetLowerBound(const Key& k) const
{
    LinkType y = mHeader; /* Last node which is not less than k. */
    LinkType x = GetRoot(); /* Current node. */

    while (x != 0) {
        if (!mKeyCompare(S_GetKey(x), k)) {
            y = x, x = S_GetLeft(x);
        }
        else {
            x = S_GetRight(x);
        }
    }

    return ConstIterator(y);
}

template <class Key, class Value, class KeyOfValue,
          class Compare, class Alloc>
typename RBTree<Key,Value,KeyOfValue,Compare,Alloc>::Iterator
RBTree<Key,Value,KeyOfValue,Compare,Alloc>::
GetUpperBound(const Key& k)
{
    LinkType y = mHeader; /* Last node which is greater than k. */
    LinkType x = GetRoot(); /* Current node. */

    while (x != 0) {
        if (mKeyCompare(k, S_GetKey(x))) {
            y = x, x = S_GetLeft(x);
        }
        else {
            x = S_GetRight(x);
        }
    }

    return Iterator(y);
}

template <class Key, class Value, class KeyOfValue,
          class Compare, class Alloc>
typename RBTree<Key,Value,KeyOfValue,Compare,Alloc>::ConstIterator
RBTree<Key,Value,KeyOfValue,Compare,Alloc>::
GetUpperBound(const Key& k) const
{
    LinkType y = mHeader; /* Last node which is greater than k. */
    LinkType x = GetRoot(); /* Current node. */

    while (x != 0) {
        if (mKeyCompare(k, S_GetKey(x))) {
            y = x, x = S_GetLeft(x);
        }
        else {
            x = S_GetRight(x);
        }
    }

     return ConstIterator(y);
}

template <class Key, class Value, class KeyOfValue,
          class Compare, class Alloc>
inline
Pair<typename RBTree<Key,Value,KeyOfValue,Compare,Alloc>::Iterator,
     typename RBTree<Key,Value,KeyOfValue,Compare,Alloc>::Iterator>
RBTree<Key,Value,KeyOfValue,Compare,Alloc>::
GetEqualRange(const Key& k)
{
    return Pair<Iterator, Iterator>(GetLowerBound(k), GetUpperBound(k));
}

template <class Key, class Value, class KoV, class Compare, class Alloc>
inline
Pair<typename RBTree<Key, Value, KoV, Compare, Alloc>::ConstIterator,
     typename RBTree<Key, Value, KoV, Compare, Alloc>::ConstIterator>
RBTree<Key, Value, KoV, Compare, Alloc>::
GetEqualRange(const Key& k) const
{
    return Pair<ConstIterator,ConstIterator>(GetLowerBound(k),
                                             GetUpperBound(k));
}

inline int
GetBlackCount(RBTreeNodeBase* node, RBTreeNodeBase* root)
{
    if (node == 0) return 0;
    int sum = 0;
    do {
        if (node->mColor == S_RBTreeBlack) ++sum;

        if (node == root) break;

        node = node->mParent;
    } while (1);
    return sum;
}

template <class Key, class Value, class KeyOfValue,
          class Compare, class Alloc>
Boolean RBTree<Key,Value,KeyOfValue,Compare,Alloc>::RBVerify() const
{
    if (mNodeCount == 0 || Begin() == End()) {
        return mNodeCount == 0 && Begin() == End() &&
                mHeader->mLeft == mHeader && mHeader->mRight == mHeader;
    }

    int len = GetBlackCount(GetLeftmost(), GetRoot());
    for (ConstIterator it = Begin(); it != End(); ++it) {
        LinkType x = (LinkType) it.mNode;
        LinkType l = S_GetLeft(x);
        LinkType r = S_GetRight(x);

        if (x->mColor == S_RBTreeRed) {
          if ((l && l->mColor == S_RBTreeRed) ||
              (r && r->mColor == S_RBTreeRed)) return FALSE;
        }

        if (l && mKeyCompare(S_GetKey(x), S_GetKey(l))) return FALSE;

        if (r && mKeyCompare(S_GetKey(r), S_GetKey(x))) return FALSE;

        if (!l && !r && GetBlackCount(x, GetRoot()) != len) return FALSE;
    }

    if (GetLeftmost() != RBTreeNodeBase::S_GetMinimum(GetRoot())) return FALSE;

    if (GetRightmost() != RBTreeNodeBase::S_GetMaximum(GetRoot())) return FALSE;

    return TRUE;
}

_ETL_NAMESPACE_END

#endif //__ETL_TREE_H__
