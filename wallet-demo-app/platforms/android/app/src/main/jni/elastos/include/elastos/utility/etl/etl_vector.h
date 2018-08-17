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

#ifndef __ETL_VECTOR_H__
#define __ETL_VECTOR_H__

#include "elastos/utility/etl/etl_def.h"
#include "elastos/utility/etl/etl_iterator_base_funcs.h"
#include "elastos/utility/etl/etl_concept_check.h"
#include <elrefbase.h>

using Elastos::ElLightRefBase;

_ETL_NAMESPACE_BEGIN

template <typename T, typename Allocator, Boolean IsStatic>
class VectorAllocBase
{
public:
    typedef typename AllocTraits<T, Allocator>::AllocatorType AllocatorType;

    AllocatorType GetAllocator() const { return mDataAllocator; }

    VectorAllocBase(const AllocatorType& a) :
            mDataAllocator(a), mStart(NULL), mFinish(NULL), mEndOfStorage(NULL)
    {}

protected:
    AllocatorType   mDataAllocator;
    T*              mStart;
    T*              mFinish;
    T*              mEndOfStorage;

    T* Allocate(size_t n) { return mDataAllocator.Allocate(n); }

    void Deallocate(T* p, size_t n)
    {
        if (NULL != p) mDataAllocator.Deallocate(p, n);
    }
};

template <typename T, typename Allocator>
class VectorAllocBase<T, Allocator, TRUE>
{
public:
    typedef typename AllocTraits<T, Allocator>::AllocatorType AllocatorType;

    AllocatorType GetAllocator() const { return AllocatorType(); }

    VectorAllocBase(const AllocatorType&) :
            mStart(NULL), mFinish(NULL), mEndOfStorage(NULL)
    {}

protected:
    T*  mStart;
    T*  mFinish;
    T*  mEndOfStorage;

    typedef typename AllocTraits<T, Allocator>::AllocType AllocType;

    T* Allocate(size_t n) { return AllocType::Allocate(n); }

    void Deallocate(T* p, size_t n) { AllocType::Deallocate(p, n); }
};

template <typename T, typename Alloc>
struct VectorBase : public VectorAllocBase<T, Alloc, AllocTraits<T, Alloc>::S_instanceless>
{
    typedef VectorAllocBase<T, Alloc,
            AllocTraits<T, Alloc>::S_instanceless> Base;
    typedef typename Base::AllocatorType _AllocatoryType;

    VectorBase(const _AllocatoryType& a) : Base(a) {}

    VectorBase(size_t n, const _AllocatoryType& a) : Base(a)
    {
        Base::mStart = Base::Allocate(n);
        Base::mFinish = Base::mStart;
        Base::mEndOfStorage = Base::mStart + n;
    }

    ~VectorBase()
    {
        this->Deallocate(Base::mStart, Base::mEndOfStorage - Base::mStart);
    }
};

template <typename T, typename Alloc = Allocator<T> >
class Vector : protected VectorBase<T, Alloc>
             , public ElLightRefBase
{
    //concept requirements
    Concept_ClassRequires(T, SGIAssignableConcept)

private:
    typedef VectorBase<T, Alloc>    Base;
    typedef Vector<T, Alloc>        VectorType;

public:
    typedef T                   ValueType;
    typedef ValueType*          Pointer;
    typedef const ValueType*    ConstPointer;
    typedef NormalIterator<Pointer, VectorType>         Iterator;
    typedef NormalIterator<ConstPointer, VectorType>    ConstIterator;
    typedef ValueType&          Reference;
    typedef const ValueType&    ConstReference;
    typedef size_t              SizeType;
    typedef ptrdiff_t           DifferenceType;

    typedef typename Base::AllocatorType AllocatorType;
    AllocatorType GetAllocator() const { return Base::GetAllocator(); }

    typedef _ETL ReverseIterator<ConstIterator>  ConstReverseIterator;
    typedef _ETL ReverseIterator<Iterator>       ReverseIterator;

protected:
    using Base::Allocate;
    using Base::Deallocate;
    using Base::mStart;
    using Base::mFinish;
    using Base::mEndOfStorage;

protected:
    void InsertAux(Iterator position, const T& x);
    void InsertAux(Iterator position);

public:
    Iterator Begin() { return Iterator(mStart); }

    ConstIterator Begin() const { return ConstIterator(mStart); }

    Iterator End() { return Iterator(mFinish); }

    ConstIterator End() const { return ConstIterator(mFinish); }

    ReverseIterator RBegin() { return ReverseIterator(End()); }

    ConstReverseIterator RBegin() const { return ConstReverseIterator(End()); }

    ReverseIterator REnd() { return ReverseIterator(Begin()); }

    ConstReverseIterator REnd() const { return ConstReverseIterator(Begin()); }

    SizeType GetSize() const { return SizeType(End() - Begin()); }

    SizeType GetMaxSize() const { return SizeType(-1) / sizeof(T); }

    SizeType GetCapacity() const
    {
        return SizeType(ConstIterator(mEndOfStorage) - Begin());
    }

    Boolean IsEmpty() const { return Begin() == End(); }

    Reference operator[](SizeType n) { return *(Begin() + n); }

    ConstReference operator[](SizeType n) const { return *(Begin() + n); }

    void CheckRange(SizeType n) const
    {
        if (n >= this->GetSize()) {
            THROW_OUT_OF_RANGE("vector");
        }
    }

    Reference At(SizeType n)
    {
        CheckRange(n);
        return (*this)[n];
    }

    ConstReference At(SizeType n) const
    {
        CheckRange(n);
        return (*this)[n];
    }

    explicit Vector(const AllocatorType& a = AllocatorType()) :
            Base(a) {}

    Vector(SizeType n, const T& value, const AllocatorType& a = AllocatorType()) :
            Base(n, a)
    {
        mFinish = UninitializedFillN(mStart, n, value);
    }

    explicit Vector(SizeType n) : Base(n, AllocatorType())
    {
        mFinish = UninitializedFillN(mStart, n, T());
    }

    Vector(const Vector<T, Alloc>& x) : Base(x.GetSize(), x.GetAllocator())
    {
        mFinish = UninitializedCopy(x.Begin(), x.End(), mStart);
    }

    template <typename InputIterator>
    Vector(InputIterator first, InputIterator last,
            const AllocatorType& a = AllocatorType()) : Base(a)
    {
        typedef typename IsInteger<InputIterator>::Integral Integral;
        InitializeAux(first, last, Integral());
    }

    template <typename Integer>
    void InitializeAux(Integer n, Integer value, TrueType)
    {
        mStart = Allocate(n);
        mEndOfStorage = mStart + n;
        mFinish = UninitializedFillN(mStart, n, value);
    }

    template <typename InputIterator>
    void InitializeAux(InputIterator first, InputIterator last, FalseType)
    {
        typedef typename IteratorTraits<InputIterator>::IteratorCategory IteratorCategory;
        RangeInitialize(first, last, IteratorCategory());
    }

    ~Vector()
    {
        Destroy(mStart, mFinish);
    }

    Vector<T, Alloc>& operator=(const Vector<T, Alloc>& x);

    void Reserve(SizeType n)
    {
        if (GetCapacity() < n) {
            const SizeType oldSize = GetSize();
            Pointer tmp = AllocateAndCopy(n, mStart, mFinish);
            Destroy(mStart, mFinish);
            Deallocate(mStart, mEndOfStorage - mStart);
            mStart = tmp;
            mFinish = tmp + oldSize;
            mEndOfStorage = mStart + n;
        }
    }

    void Assign(SizeType n, const T& val) { FillAssign(n, val); }

    void FillAssign(SizeType n, const T& val);

    template <typename InputIterator>
    void Assign(InputIterator first, InputIterator last)
    {
        typedef typename IsInteger<InputIterator>::Integral Integral;
        AssignDispatch(first, last, Integral());
    }

    template <typename Integer>
    void AssignDispatch(Integer n, Integer val, TrueType)
    {
        FillAssign((SizeType)n, (T)val);
    }

    template <typename InputIterator>
    void AssignDispatch(InputIterator first, InputIterator last, FalseType)
    {
        typedef typename IteratorTraits<InputIterator>::IteratorCategory IteratorCategory;
        AssignAux(first, last, IteratorCategory());
    }

    template <typename InputIterator>
    void AssignAux(InputIterator first, InputIterator last, InputIteratorTag);

    template <typename ForwardIterator>
    void AssignAux(ForwardIterator first, ForwardIterator last, ForwardIteratorTag);

    /**
     *  Returns a read/write reference to the data at the first element of the
     *  vector.
    */
    Reference GetFront() { return *Begin(); }

    /**
     *  Returns a read-only (constant) reference to the data at the first
     *  element of the vector.
    */
    ConstReference GetFront() const { return *Begin(); }

    /**
     *  Returns a read/write reference to the data at the last element of the
     *  vector.
    */
    Reference GetBack() { return *(End() - 1); }

    /**
     *  Returns a read-only (constant) reference to the data at the first
     *  element of the vector.
    */
    ConstReference GetBack() const { return *(End() - 1); }

    /**
     *  @brief  Add data to the end of the vector.
     *  @param  x  Data to be added.
     *
     *  This is a typical stack operation.  The function creates an element at
     *  the end of the vector and assigns the given data to it.
     *  Due to the nature of a vector this operation can be done in constant
     *  time if the vector has preallocated space available.
    */
    void PushBack(const T& x)
    {
        if (mFinish != mEndOfStorage) {
            Construct(mFinish, x);
            ++mFinish;
        }
        else {
            InsertAux(End(), x);
        }
    }

    /**
     *  Add an element to the end of the vector.  The element is
     *  default-constructed.
    */
    void PushBack()
    {
        if (mFinish != mEndOfStorage) {
            Construct(mFinish);
            ++mFinish;
        }
        else {
            InsertAux(End());
        }
    }

    void Swap(Vector<T, Alloc>& x)
    {
        _ETL Swap(mStart, x.mStart);
        _ETL Swap(mFinish, x.mFinish);
        _ETL Swap(mEndOfStorage, x.mEndOfStorage);
    }

    /**
     *  @brief  Inserts given value into vector at specified element.
     *  @param  position  An iterator that points to the element where data
     *                    should be inserted.
     *  @param  x  Data to be inserted.
     *  @return  An iterator that points to the inserted data.
     *
     *  This function will insert the given value into the specified location.
     *  Note that this kind of operation could be expensive for a vector and if
     *  it is frequently used the user should consider using std::list.
    */
    Iterator Insert(Iterator position, const T& x)
    {
        SizeType n = position - Begin();
        if (mFinish != mEndOfStorage && position == End()) {
            Construct(mFinish, x);
            ++mFinish;
        }
        else {
            InsertAux(Iterator(position), x);
        }

        return Begin() + n;
    }

    /**
     *  @brief  Inserts an empty element into the vector.
     *  @param  position  An iterator that points to the element where empty
     *                    element should be inserted.
     *  @param  x  Data to be inserted.
     *  @return  An iterator that points to the inserted element.
     *
     *  This function will insert an empty element into the specified location.
     *  Note that this kind of operation could be expensive for a vector and if
     *  it is frequently used the user should consider using std::list.
    */
    Iterator Insert(Iterator position)
    {
        SizeType n = position - Begin();
        if (mFinish != mEndOfStorage && position == End()) {
            Construct(mFinish);
            ++mFinish;
        }
        else {
            InsertAux(Iterator(position));
        }

        return Begin() + n;
    }

    // Check whether it's an integral type.  If so, it's not an iterator.
    template <typename InputIterator>
    void Insert(Iterator position, InputIterator first, InputIterator last)
    {
        typedef typename IsInteger<InputIterator>::Integral Integral;
        InsertDispatch(position, first, last, Integral());
    }

    template <typename Integer>
    void InsertDispatch(Iterator position, Integer n, Integer val, TrueType)
    {
        FillInsert(position, static_cast<SizeType>(n), static_cast<T>(val));
    }

    template <typename InputIterator>
    void InsertDispatch(Iterator position,
            InputIterator first, InputIterator last, FalseType)
    {
        typedef typename IteratorTraits<InputIterator>::IteratorCategory IteratorCategory;
        RangeInsert(position, first, last, IteratorCategory());
    }

    /**
     *  @brief  Inserts a number of copies of given data into the vector.
     *  @param  position  An iterator that points to the element where data
     *                    should be inserted.
     *  @param  n  Amount of elements to be inserted.
     *  @param  x  Data to be inserted.
     *
     *  This function will insert a specified number of copies of the given data
     *  into the specified location.
     *
     *  Note that this kind of operation could be expensive for a vector and if
     *  it is frequently used the user should consider using std::list.
    */
    void Insert(Iterator position, SizeType n, const T& x)
    {
        FillInsert(position, n, x);
    }

    void FillInsert(Iterator position, SizeType n, const T& x);

    /**
     *  @brief  Removes last element from vector.
     *
     *  This is a typical stack operation. It allows us to shrink the vector by
     *  one.
     *
     *  Note that no data is returned and if last element's data is needed it
     *  should be retrieved before pop_back() is called.
    */
    void PopBack()
    {
        --mFinish;
        Destroy(mFinish);
    }

    /**
     *  @brief  Remove element at given position
     *  @param  position  Iterator pointing to element to be erased.
     *  @return  Doc Me! (Iterator pointing to new element at old location?)
     *
     *  This function will erase the element at the given position and thus
     *  shorten the vector by one.
     *
     *  Note This operation could be expensive and if it is frequently used the
     *  user should consider using std::list.  The user is also cautioned that
     *  this function only erases the element, and that if the element is itself
     *  a pointer, the pointed-to memory is not touched in any way.  Managing
     *  the pointer is the user's responsibilty.
    */
    Iterator Erase(Iterator position)
    {
        if (position + 1 != End()) {
            Copy(position + 1, End(), position);
        }
        --mFinish;
        Destroy(mFinish);
        return position;
    }

    /**
     *  @brief  Remove a range of elements from a vector.
     *  @param  first  Iterator pointing to the first element to be erased.
     *  @param  last  Iterator pointing to the last element to be erased.
     *  @return  Doc Me! (Iterator pointing to new element at old location?)
     *
     *  This function will erase the elements in the given range and shorten the
     *  vector accordingly.
     *
     *  Note This operation could be expensive and if it is frequently used the
     *  user should consider using std::list.  The user is also cautioned that
     *  this function only erases the elements, and that if the elements
     *  themselves are pointers, the pointed-to memory is not touched in any
     *  way.  Managing the pointer is the user's responsibilty.
    */
    Iterator Erase(Iterator first, Iterator last)
    {
        Iterator i(Copy(last, End(), first));
        Destroy(i, End());
        mFinish = mFinish - (last - first);
        return first;
    }

    /**
     *  @brief  Resizes the vector to the specified number of elements.
     *  @param  new_size  Number of elements the vector should contain.
     *  @param  x  Data with which new elements should be populated.
     *
     *  This function will resize the vector to the specified number of
     *  elements.  If the number is smaller than the vector's current size the
     *  vector is truncated, otherwise the vector is extended and new elements
     *  are populated with given data.
    */
    void Resize(SizeType newSize, const T& x)
    {
        if (newSize < GetSize()) {
            Erase(Begin() + newSize, End());
        }
        else {
            Insert(End(), newSize - GetSize(), x);
        }
    }

    /**
     *  @brief  Resizes the vector to the specified number of elements.
     *  @param  new_size  Number of elements the vector should contain.
     *
     *  This function will resize the vector to the specified number of
     *  elements.  If the number is smaller than the vector's current size the
     *  vector is truncated, otherwise the vector is extended and new elements
     *  are left uninitialized.
    */
    void Resize(SizeType newSize) { Resize(newSize, T()); }

    /**
     *  Erases all elements in vector.  Note that this function only erases the
     *  elements, and that if the elements themselves are pointers, the
     *  pointed-to memory is not touched in any way.  Managing the pointer is
     *  the user's responsibilty.
    */
    void Clear() { Erase(Begin(), End()); }

protected:
    template <typename ForwardIterator>
    Pointer AllocateAndCopy(SizeType n, ForwardIterator first, ForwardIterator last)
    {
        Pointer result = Allocate(n);
        try {
            UninitializedCopy(first, last, result);
            return result;
        }
        catch(...) {
            Deallocate(result, n);
            THROW_EXCEPTION_AGAIN;
        }
    }

    template <typename InputIterator>
    void RangeInitialize(InputIterator first, InputIterator last, InputIteratorTag)
    {
        for (; first != last; ++first) {
            PushBack(*first);
        }
    }

    // This function is only called by the constructor.
    template <typename ForwardIterator>
    void RangeInitialize(ForwardIterator first, ForwardIterator last, ForwardIteratorTag)
    {
        SizeType n = Distance(first, last);
        mStart = Allocate(n);
        mEndOfStorage = mStart + n;
        mFinish = UninitializedCopy(first, last, mStart);
    }

    template <typename InputIterator>
    void RangeInsert(Iterator position,
            InputIterator first, InputIterator last, InputIteratorTag);

    template <typename ForwardIterator>
    void RangeInsert(Iterator position,
            ForwardIterator first, ForwardIterator last, ForwardIteratorTag);
};

template <typename T, typename Alloc>
inline Boolean operator==(
        const Vector<T, Alloc>& x, const Vector<T, Alloc>& y)
{
    return x.GetSize() == y.GetSize() &&
            Equal(x.Begin(), x.End(), y.Begin());
}

template <typename T, typename Alloc>
inline Boolean operator<(
        const Vector<T, Alloc>& x, const Vector<T, Alloc>& y)
{
    return LexicographicalCompare(x.Begin(), x.End(), y.Begin(), y.End());
}

template <typename T, typename Alloc>
inline void Swap(Vector<T, Alloc>& x, Vector<T, Alloc>& y)
{
    x.Swap(y);
}

template <typename T, typename Alloc>
inline Boolean operator!=(
        const Vector<T, Alloc>& x, const Vector<T, Alloc>& y)
{
    return !(x == y);
}

template <typename T, typename Alloc>
inline Boolean operator>(
        const Vector<T, Alloc>& x, const Vector<T, Alloc>& y)
{
    return y < x;
}

template <typename T, typename Alloc>
inline Boolean operator<=(
        const Vector<T, Alloc>& x, const Vector<T, Alloc>& y)
{
    return !(y < x);
}

template <typename T, typename Alloc>
inline Boolean operator>=(
        const Vector<T, Alloc>& x, const Vector<T, Alloc>& y)
{
    return !(x < y);
}

template <typename T, typename Alloc>
Vector<T, Alloc>& Vector<T, Alloc>::operator=(
            const Vector<T, Alloc>& x)
{
    if (&x != this) {
        const SizeType xlen = x.GetSize();
        if (xlen > GetCapacity()) {
            Pointer tmp = AllocateAndCopy(xlen, x.Begin(), x.End());
            Destroy(mStart, mFinish);
            Deallocate(mStart, mEndOfStorage - mStart);
            mStart = tmp;
            mEndOfStorage = mStart + xlen;
        }
        else if (GetSize() >= xlen) {
            Iterator i(Copy(x.Begin(), x.End(), Begin()));
            Destroy(i, End());
        }
        else {
            Copy(x.Begin(), x.Begin() + GetSize(), mStart);
            UninitializedCopy(x.Begin() + GetSize(), x.End(), mFinish);
        }
        mFinish = mStart + xlen;
    }
    return *this;
}

template <typename T, typename Alloc>
void Vector<T, Alloc>::FillAssign(size_t n, const ValueType& val)
{
    if (n > GetCapacity()) {
        Vector<T, Alloc> tmp(n, val, GetAllocator());
        tmp.Swap(*this);
    }
    else if (n > GetSize()) {
        Fill(Begin(), End(), val);
        mFinish = UninitializedFillN(mFinish, n - GetSize(), val);
    }
    else {
        Erase(FillN(Begin(), n, val), End());
    }
}

template <typename T, typename Alloc> template <typename InputIterator>
void Vector<T, Alloc>::AssignAux(
        InputIterator first, InputIterator last, InputIteratorTag)
{
    Iterator current(Begin());
    for (; first != last && current != End(); ++current, ++first) {
        *current = *first;
    }
    if (first == last) {
        Erase(current, End());
    }
    else {
        Insert(End(), first, last);
    }
}

template <typename T, typename Alloc> template <typename ForwardIterator>
void Vector<T, Alloc>::AssignAux(
        ForwardIterator first, ForwardIterator last, ForwardIteratorTag)
{
    SizeType len = Distance(first, last);

    if (len > GetCapacity()) {
        Pointer tmp(AllocateAndCopy(len, first, last));
        Destroy(mStart, mFinish);
        Deallocate(mStart, mEndOfStorage - mStart);
        mStart = tmp;
        mEndOfStorage = mFinish = mStart + len;
    }
    else if (GetSize() >= len) {
        Iterator newFinish(Copy(first, last, mStart));
        Destroy(newFinish, End());
        mFinish = newFinish.GetBase();
    }
    else {
        ForwardIterator middle = first;
        Advance(middle, GetSize());
        Copy(first, middle, mStart);
        mFinish = UninitializedCopy(middle, last, mFinish);
    }
}

template <typename T, typename Alloc>
void Vector<T, Alloc>::InsertAux(Iterator position, const T& x)
{
    if (mFinish != mEndOfStorage) {
        Construct(mFinish, *(mFinish - 1));
        ++mFinish;
        T xCopy = x;
        CopyBackward(position, Iterator(mFinish - 2), Iterator(mFinish - 1));
        *position = xCopy;
    }
    else {
        const SizeType oldSize = GetSize();
        const SizeType len = oldSize != 0 ? 2 * oldSize : 1;
        Iterator newStart(Allocate(len));
        Iterator newFinish(newStart);
        try {
            newFinish = UninitializedCopy(Iterator(mStart), position, newStart);
            Construct(newFinish.GetBase(), x);
            ++newFinish;
            newFinish = UninitializedCopy(position, Iterator(mFinish), newFinish);
        }
        catch(...) {
            Destroy(newStart, newFinish);
            Deallocate(newStart.GetBase(), len);
            THROW_EXCEPTION_AGAIN;
        }
        Destroy(Begin(), End());
        Deallocate(mStart, mEndOfStorage - mStart);
        mStart = newStart.GetBase();
        mFinish = newFinish.GetBase();
        mEndOfStorage = newStart.GetBase() + len;
    }
}

template <typename T, typename Alloc>
void Vector<T, Alloc>::InsertAux(Iterator position)
{
    if (mFinish != mEndOfStorage) {
        Construct(mFinish, *(mFinish - 1));
        ++mFinish;
        CopyBackward(position, Iterator(mFinish - 2), Iterator(mFinish - 1));
        *position = T();
    }
    else {
        const SizeType oldSize = GetSize();
        const SizeType len = oldSize != 0 ? 2 *oldSize : 1;
        Pointer newStart = Allocate(len);
        Pointer newFinish = newStart;
        try {
            newFinish = UninitializedCopy(
                    Iterator(mStart), position, newStart);
            Construct(newFinish);
            ++newFinish;
            newFinish = UninitializedCopy(
                    position, Iterator(mFinish), newFinish);
        }
        catch(...) {
            Destroy(newStart, newFinish);
            Deallocate(newStart, len);
            THROW_EXCEPTION_AGAIN;
        }
        Destroy(Begin(), End());
        Deallocate(mStart, mEndOfStorage - mStart);
        mStart = newStart;
        mFinish = newFinish;
        mEndOfStorage = newStart + len;
    }
}

template <typename T, typename Alloc>
void Vector<T, Alloc>::FillInsert(Iterator position, SizeType n, const T& x)
{
    if (n != 0) {
        if (SizeType(mEndOfStorage - mFinish) >= n) {
            T xCopy = x;
            const SizeType elemsAfter = End() - position;
            Iterator oldFinish(mFinish);
            if (elemsAfter > n) {
                UninitializedCopy(mFinish - n, mFinish, mFinish);
                mFinish += n;
                CopyBackward(position, oldFinish - n, oldFinish);
                Fill(position, position + n, xCopy);
            }
            else {
                UninitializedFillN(mFinish, n - elemsAfter, xCopy);
                mFinish += n - elemsAfter;
                UninitializedCopy(position, oldFinish, mFinish);
                mFinish += elemsAfter;
                Fill(position, oldFinish, xCopy);
            }
        }
        else {
            const SizeType oldSize = GetSize();
            const SizeType len = oldSize + Max(oldSize, n);
            Iterator newStart(Allocate(len));
            Iterator newFinish(newStart);
            try {
                newFinish = UninitializedCopy(Begin(), position, newStart);
                newFinish = UninitializedFillN(newFinish, n, x);
                newFinish = UninitializedCopy(position, End(), newFinish);
            }
            catch(...) {
                Destroy(newStart, newFinish);
                Deallocate(newStart.GetBase(), len);
                THROW_EXCEPTION_AGAIN;
            }
            Destroy(mStart, mFinish);
            Deallocate(mStart, mEndOfStorage - mStart);
            mStart = newStart.GetBase();
            mFinish = newFinish.GetBase();
            mEndOfStorage = newStart.GetBase() + len;
        }
    }
}

template <typename T, typename Alloc> template <typename InputIterator>
void Vector<T, Alloc>::RangeInsert(
        Iterator position, InputIterator first, InputIterator last, InputIteratorTag)
{
    for (; first != last; ++first) {
        position = Insert(position, *first);
        ++position;
    }
}

template <typename T, typename Alloc> template <typename ForwardIterator>
void Vector<T, Alloc>::RangeInsert(
        Iterator position, ForwardIterator first, ForwardIterator last, ForwardIteratorTag)
{
    if (first != last) {
        SizeType n = Distance(first, last);
        if (SizeType(mEndOfStorage - mFinish) >= n) {
            const SizeType elemsAfter = End() - position;
            Iterator oldFinish(mFinish);
            if (elemsAfter > n) {
                UninitializedCopy(mFinish - n, mFinish, mFinish);
                mFinish += n;
                CopyBackward(position, oldFinish - n, oldFinish);
                Copy(first, last, position);
            }
            else {
                ForwardIterator middle = first;
                Advance(middle, elemsAfter);
                UninitializedCopy(middle, last, mFinish);
                mFinish += n - elemsAfter;
                UninitializedCopy(position, oldFinish, mFinish);
                mFinish += elemsAfter;
                Copy(first, middle, position);
            }
        }
        else {
            const SizeType oldSize = GetSize();
            const SizeType len = oldSize + Max(oldSize, n);
            Iterator newStart(Allocate(len));
            Iterator newFinish(newStart);
            try {
                newFinish = UninitializedCopy(
                        Iterator(mStart), position, newStart);
                newFinish = UninitializedCopy(first, last, newFinish);
                newFinish = UninitializedCopy(
                        position, Iterator(mFinish), newFinish);
            }
            catch(...) {
                Destroy(newStart, newFinish);
                Deallocate(newStart.GetBase(), len);
                THROW_EXCEPTION_AGAIN;
            }
            Destroy(mStart, mFinish);
            Deallocate(mStart, mEndOfStorage - mStart);
            mStart = newStart.GetBase();
            mFinish = newFinish.GetBase();
            mEndOfStorage = newStart.GetBase() + len;
        }
    }
}

_ETL_NAMESPACE_END

#endif //__ETL_VECTOR_H__
