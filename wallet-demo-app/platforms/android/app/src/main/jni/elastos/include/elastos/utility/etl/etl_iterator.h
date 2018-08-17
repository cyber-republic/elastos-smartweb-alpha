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

#ifndef __ETL_ITERATOR_H__
#define __ETL_ITERATOR_H__

#include "elastos/utility/etl/etl_def.h"

_ETL_NAMESPACE_BEGIN

// 24.4.1 Reverse iterators
/**
 *  "Bidirectional and random access iterators have corresponding reverse
 *  %iterator adaptors that iterate through the data structure in the
 *  opposite direction.  They have the same signatures as the corresponding
 *  iterators.  The fundamental relation between a reverse %iterator and its
 *  corresponding %iterator @c i is established by the identity:
 *  @code
 *      &*(reverse_iterator(i)) == &*(i - 1)
 *  @endcode
 *
 *  This mapping is dictated by the fact that while there is always a
 *  pointer past the end of an array, there might not be a valid pointer
 *  before the beginning of an array." [24.4.1]/1,2
 *
 *  Reverse iterators can be tricky and surprising at first.  Their
 *  semantics make sense, however, and the trickiness is a side effect of
 *  the requirement that the iterators must be safe.
*/
template <typename _Iterator>
class ReverseIterator : public Iterator<typename IteratorTraits<_Iterator>::IteratorCategory,
        typename IteratorTraits<_Iterator>::ValueType,
        typename IteratorTraits<_Iterator>::DifferenceType,
        typename IteratorTraits<_Iterator>::Pointer,
        typename IteratorTraits<_Iterator>::Reference>
{
protected:
    _Iterator mCurrent;

public:
    typedef _Iterator    IteratorType;
    typedef typename IteratorTraits<_Iterator>::DifferenceType   DifferenceType;
    typedef typename IteratorTraits<_Iterator>::Reference        Reference;
    typedef typename IteratorTraits<_Iterator>::Pointer          Pointer;

public:
    /**
     *  The default constructor gives an undefined state to this %iterator.
    */
    ReverseIterator() {}

    /**
     *  This %iterator will move in the opposite direction that @p x does.
    */
    explicit ReverseIterator(IteratorType x) : mCurrent(x) {}

    /**
     *  The copy constructor is normal.
    */
    ReverseIterator(const ReverseIterator& x) : mCurrent(x.mCurrent) {}

    /**
     *  A reverse_iterator across other types can be copied in the normal
     *  fashion.
    */
    template <typename _Iter>
    ReverseIterator(const ReverseIterator<_Iter>& x) : mCurrent(x.GetBase()) {}

    /**
     *  @return  @c current, the %iterator used for underlying work.
    */
    IteratorType GetBase() const { return mCurrent; }

    /**
     *  @return  TODO
     *
     *  @doctodo
    */
    Reference operator*() const
    {
        _Iterator tmp = mCurrent;
        return *--tmp;
    }

    /**
     *  @return  TODO
     *
     *  @doctodo
    */
    Pointer operator->() const { return &(operator*()); }

    /**
     *  @return  TODO
     *
     *  @doctodo
    */
    ReverseIterator& operator++()
    {
        --mCurrent;
        return *this;
    }

    /**
     *  @return  TODO
     *
     *  @doctodo
    */
    ReverseIterator operator++(int)
    {
        ReverseIterator tmp = *this;
        --mCurrent;
        return tmp;
    }

    /**
     *  @return  TODO
     *
     *  @doctodo
    */
    ReverseIterator& operator--()
    {
        ++mCurrent;
        return *this;
    }

    /**
     *  @return  TODO
     *
     *  @doctodo
    */
    ReverseIterator operator--(int)
    {
        ReverseIterator tmp = *this;
        ++mCurrent;
        return tmp;
    }


    /**
     *  @return  TODO
     *
     *  @doctodo
    */
    ReverseIterator operator+(DifferenceType n) const
    {
        return ReverseIterator(mCurrent - n);
    }

    /**
     *  @return  TODO
     *
     *  @doctodo
    */
    ReverseIterator& operator+=(DifferenceType n)
    {
        mCurrent -= n;
        return *this;
    }

    /**
     *  @return  TODO
     *
     *  @doctodo
    */
    ReverseIterator operator-(DifferenceType n) const
    {
        return ReverseIterator(mCurrent + n);
    }

    /**
     *  @return  TODO
     *
     *  @doctodo
    */
    ReverseIterator& operator-=(DifferenceType n)
    {
        mCurrent += n;
        return *this;
    }

    /**
     *  @return  TODO
     *
     *  @doctodo
    */
    Reference operator[](DifferenceType n) const
    {
        return *(*this + n);
    }
};

//@{
/**
 *  @param  x  A %reverse_iterator.
 *  @param  y  A %reverse_iterator.
 *  @return  A simple bool.
 *
 *  Reverse iterators forward many operations to their underlying base()
 *  iterators.  Others are implemented in terms of one another.
 *
*/
template <typename Iterator>
inline Boolean operator==(const ReverseIterator<Iterator>& x,
        const ReverseIterator<Iterator>& y)
{
    return x.GetBase() == y.GetBase();
}

template <typename Iterator>
inline Boolean operator<(const ReverseIterator<Iterator>& x,
        const ReverseIterator<Iterator>& y)
{
    return y.GetBase() < x.GetBase();
}

template <typename Iterator>
inline Boolean operator!=(const ReverseIterator<Iterator>& x,
        const ReverseIterator<Iterator>& y)
{
    return !(x == y);
}

template <typename Iterator>
inline Boolean operator>(const ReverseIterator<Iterator>& x,
        const ReverseIterator<Iterator>& y)
{
    return y < x;
}

template <typename Iterator>
inline Boolean operator<=(const ReverseIterator<Iterator>& x,
        const ReverseIterator<Iterator>& y)
{
    return !(y < x);
}

template <typename Iterator>
inline Boolean operator>=(const ReverseIterator<Iterator>& x,
        const ReverseIterator<Iterator>& y)
{
    return !(x < y);
}

template <typename Iterator>
inline typename ReverseIterator<Iterator>::DifferenceType
operator-(const ReverseIterator<Iterator>& x, const ReverseIterator<Iterator>& y)
{
    return y.GetBase() - x.GetBase();
}

template <typename Iterator>
inline ReverseIterator<Iterator> operator+(
        typename ReverseIterator<Iterator>::DifferenceType n,
        const ReverseIterator<Iterator>& x)
{
    return ReverseIterator<Iterator>(x.GetBase() - n);
}
//@}

// 24.4.2.2.1 back_insert_iterator
/**
 *  These are output iterators, constructed from a container-of-T.
 *  Assigning a T to the iterator appends it to the container using
 *  push_back.
 *
 *  Tip:  Using the back_inserter function to create these iterators can
 *  save typing.
*/
template <typename Container>
class BackInsertIterator : public Iterator<OutputIteratorTag, void, void, void, void>
{
protected:
    Container* mContainer;

public:
    // A nested typedef for the type of whatever container you used.
    typedef Container   ContainerType;

    // The only way to create this %iterator is with a container.
    explicit BackInsertIterator(Container& x) : mContainer(&x) {}

    /**
     *  @param  value  An instance of whatever type
     *                 container_type::const_reference is; presumably a
     *                 reference-to-const T for container<T>.
     *  @return  This %iterator, for chained operations.
     *
     *  This kind of %iterator doesn't really have a "position" in the
     *  container (you can think of the position as being permanently at
     *  the end, if you like).  Assigning a value to the %iterator will
     *  always append the value to the end of the container.
    */
    BackInsertIterator& operator=(typename Container::ConstReference value)
    {
        mContainer->PushBack(value);
        return *this;
    }

    // Simply returns *this.
    BackInsertIterator& operator*() { return *this; }

    // Simply returns *this.  (This %iterator does not "move".)
    BackInsertIterator& operator++() { return *this; }

    // Simply returns *this.  (This %iterator does not "move".)
    BackInsertIterator operator++(int) { return *this; }
};

/**
 *  @param  x  A container of arbitrary type.
 *  @return  An instance of back_insert_iterator working on @p x.
 *
 *  This wrapper function helps in creating back_insert_iterator instances.
 *  Typing the name of the %iterator requires knowing the precise full
 *  type of the container, which can be tedious and impedes generic
 *  programming.  Using this function lets you take advantage of automatic
 *  template parameter deduction, making the compiler match the correct
 *  types for you.
*/
template <typename Container>
inline BackInsertIterator<Container> BackInserter(Container& x)
{
    return BackInsertIterator<Container>(x);
}


/**
 *  These are output iterators, constructed from a container-of-T.
 *  Assigning a T to the iterator prepends it to the container using
 *  push_front.
 *
 *  Tip:  Using the front_inserter function to create these iterators can
 *  save typing.
*/
template <typename Container>
class FrontInsertIterator : public Iterator<OutputIteratorTag, void, void, void, void>
{
protected:
    Container* mContainer;

public:
    // A nested typedef for the type of whatever container you used.
    typedef Container   ContainerType;

    // The only way to create this %iterator is with a container.
    explicit FrontInsertIterator(Container& x) : mContainer(&x) {}

    /**
     *  @param  value  An instance of whatever type
     *                 container_type::const_reference is; presumably a
     *                 reference-to-const T for container<T>.
     *  @return  This %iterator, for chained operations.
     *
     *  This kind of %iterator doesn't really have a "position" in the
     *  container (you can think of the position as being permanently at
     *  the front, if you like).  Assigning a value to the %iterator will
     *  always prepend the value to the front of the container.
    */
    FrontInsertIterator& operator=(typename Container::ConstReference value)
    {
        mContainer->PushFront(value);
        return *this;
    }

    // Simply returns *this.
    FrontInsertIterator& operator*() { return *this; }

    /// Simply returns *this.  (This %iterator does not "move".)
    FrontInsertIterator& operator++() { return *this; }

    /// Simply returns *this.  (This %iterator does not "move".)
    FrontInsertIterator operator++(int) { return *this; }
};

/**
 *  @param  x  A container of arbitrary type.
 *  @return  An instance of front_insert_iterator working on @p x.
 *
 *  This wrapper function helps in creating front_insert_iterator instances.
 *  Typing the name of the %iterator requires knowing the precise full
 *  type of the container, which can be tedious and impedes generic
 *  programming.  Using this function lets you take advantage of automatic
 *  template parameter deduction, making the compiler match the correct
 *  types for you.
*/
template <typename Container>
inline FrontInsertIterator<Container> FrontInserter(Container& x)
{
    return FrontInsertIterator<Container>(x);
}


/**
 *  These are output iterators, constructed from a container-of-T.
 *  Assigning a T to the iterator inserts it in the container at the
 *  %iterator's position, rather than overwriting the value at that
 *  position.
 *
 *  (Sequences will actually insert a @e copy of the value before the
 *  %iterator's position.)
 *
 *  Tip:  Using the inserter function to create these iterators can
 *  save typing.
*/
template <typename Container>
class InsertIterator : public Iterator<OutputIteratorTag, void, void, void, void>
{
protected:
    Container* mContainer;
    typename Container::Iterator mIterator;

public:
    // A nested typedef for the type of whatever container you used.
    typedef Container       ContainerType;

    /**
     *  The only way to create this %iterator is with a container and an
     *  initial position (a normal %iterator into the container).
    */
    InsertIterator(Container& x, typename Container::Iterator i) :
            mContainer(&x), mIterator(i) {}

    /**
     *  @param  value  An instance of whatever type
     *                 container_type::const_reference is; presumably a
     *                 reference-to-const T for container<T>.
     *  @return  This %iterator, for chained operations.
     *
     *  This kind of %iterator maintains its own position in the
     *  container.  Assigning a value to the %iterator will insert the
     *  value into the container at the place before the %iterator.
     *
     *  The position is maintained such that subsequent assignments will
     *  insert values immediately after one another.  For example,
     *  @code
     *     // vector v contains A and Z
     *
     *     insert_iterator i (v, ++v.begin());
     *     i = 1;
     *     i = 2;
     *     i = 3;
     *
     *     // vector v contains A, 1, 2, 3, and Z
     *  @endcode
    */
    InsertIterator& operator=(const typename Container::ConstReference value)
    {
        mIterator = mContainer->Insert(mIterator, value);
        ++mIterator;
        return *this;
    }

    // Simply returns *this.
    InsertIterator& operator*() { return *this; }

    // Simply returns *this.  (This %iterator does not "move".)
    InsertIterator& operator++() { return *this; }

    // Simply returns *this.  (This %iterator does not "move".)
    InsertIterator& operator++(int) { return *this; }
};

/**
 *  @param  x  A container of arbitrary type.
 *  @return  An instance of insert_iterator working on @p x.
 *
 *  This wrapper function helps in creating insert_iterator instances.
 *  Typing the name of the %iterator requires knowing the precise full
 *  type of the container, which can be tedious and impedes generic
 *  programming.  Using this function lets you take advantage of automatic
 *  template parameter deduction, making the compiler match the correct
 *  types for you.
*/
template <typename Container, typename Iterator>
inline InsertIterator<Container> Inserter(Container& x, Iterator i)
{
    return InsertIterator<Container>(x, typename Container::Iterator(i));
}


// This iterator adapter is 'normal' in the sense that it does not
// change the semantics of any of the operators of its iterator
// parameter.  Its primary purpose is to convert an iterator that is
// not a class, e.g. a pointer, into an iterator that is a class.
// The _Container parameter exists solely so that different containers
// using this template can instantiate different types, even if the
// _Iterator parameter is the same.
template <typename _Iterator, typename Container>
class NormalIterator : public Iterator<typename IteratorTraits<_Iterator>::IteratorCategory,
        typename IteratorTraits<_Iterator>::ValueType,
        typename IteratorTraits<_Iterator>::DifferenceType,
        typename IteratorTraits<_Iterator>::Pointer,
        typename IteratorTraits<_Iterator>::Reference>
{
protected:
    _Iterator mCurrent;

public:
    typedef typename IteratorTraits<_Iterator>::DifferenceType   DifferenceType;
    typedef typename IteratorTraits<_Iterator>::Reference        Reference;
    typedef typename IteratorTraits<_Iterator>::Pointer          Pointer;

    NormalIterator() : mCurrent(_Iterator()) {}

    explicit
    NormalIterator(const _Iterator& i) : mCurrent(i) {}

    // Allow iterator to const_iterator conversion
    template <typename _Iter>
    inline NormalIterator(const NormalIterator<_Iter, Container>& i) :
            mCurrent(i.GetBase()) {}

    // Forward iterator requirements
    Reference
    operator*() const { return *mCurrent; }

    Reference
    operator->() const { return mCurrent; }

    NormalIterator&
    operator++() { ++mCurrent; return *this; }

    NormalIterator
    operator++(int) { return NormalIterator(mCurrent++); }

    // Bidirectional iterator requirements
    NormalIterator&
    operator--() { --mCurrent; return *this; }

    NormalIterator
    operator--(int) { return NormalIterator(mCurrent--); }

    // Random access iterator requirements
    Reference
    operator[](const DifferenceType& n) const
    { return mCurrent[n]; }

    NormalIterator&
    operator+=(const DifferenceType& n)
    { mCurrent += n; return *this; }

    NormalIterator
    operator+(const DifferenceType& n)const
    { return NormalIterator(mCurrent + n); }

    NormalIterator&
    operator-=(const DifferenceType& n)
    { mCurrent -= n; return *this; }

    NormalIterator
    operator-(const DifferenceType& n) const
    { return NormalIterator(mCurrent - n); }

    DifferenceType
    operator-(const NormalIterator& i) const
    { return mCurrent - i.mCurrent; }

    const _Iterator& GetBase() const {return mCurrent; }
};


// Forward iterator requirements
template <typename IteratorL, typename IteratorR, typename Container>
inline Boolean
operator==(const NormalIterator<IteratorL, Container>& lhs,
           const NormalIterator<IteratorR, Container>& rhs)
{
    return lhs.GetBase() == rhs.GetBase();
}

template <typename IteratorL, typename IteratorR, typename Container>
inline Boolean
operator!=(const NormalIterator<IteratorL, Container>& lhs,
           const NormalIterator<IteratorR, Container>& rhs)
{
    return !(lhs == rhs);
}

// Random access iterator requirements
template <typename IteratorL, typename IteratorR, typename Container>
inline Boolean
operator<(const NormalIterator<IteratorL, Container>& lhs,
          const NormalIterator<IteratorR, Container>& rhs)
{
    return lhs.GetBase() < rhs.GetBase();
}

template <typename IteratorL, typename IteratorR, typename Container>
inline Boolean
operator>(const NormalIterator<IteratorL, Container>& lhs,
          const NormalIterator<IteratorR, Container>& rhs)
{
    return rhs < lhs;
}

template <typename IteratorL, typename IteratorR, typename Container>
inline Boolean
operator<=(const NormalIterator<IteratorL, Container>& lhs,
           const NormalIterator<IteratorR, Container>& rhs)
{
    return !(rhs < lhs);
}

template <typename IteratorL, typename IteratorR, typename Container>
inline Boolean
operator>=(const NormalIterator<IteratorL, Container>& lhs,
           const NormalIterator<IteratorR, Container>& rhs)
{
    return !(lhs < rhs);
}

template <typename Iterator, typename Container>
inline NormalIterator<Iterator, Container>
operator+(typename NormalIterator<Iterator, Container>::DifferenceType n,
        const NormalIterator<Iterator, Container>& i)
{
    return NormalIterator<Iterator, Container>(i.GetBase() + n);
}


_ETL_NAMESPACE_END

#endif //__ETL_ITERATOR_H__
