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

#ifndef __ETL_MULTIMAP_H__
#define __ETL_MULTIMAP_H__

#include "elastos/utility/etl/etl_def.h"
#include "elastos/utility/etl/ConceptCheck.h"
#include <elrefbase.h>

using Elastos::ElLightRefBase;

_ETL_NAMESPACE_BEGIN

// Forward declaration of operators < and ==, needed for friend declaration.
template <class Key, class T,
          class Compare = Less<Key>,
          class Alloc = Allocator<Pair<const Key, T> > >
class Multimap;

template <class Key, class T, class Compare, class Alloc>
inline Boolean operator==(const Multimap<Key,T,Compare,Alloc>& x,
                          const Multimap<Key,T,Compare,Alloc>& y);

template <class Key, class T, class Compare, class Alloc>
inline Boolean operator<(const Multimap<Key,T,Compare,Alloc>& x,
                         const Multimap<Key,T,Compare,Alloc>& y);

/**
 *  @brief A standard container made up of pairs (see std::pair in <utility>)
 *         which can be retrieved based on a key.
 *
 *  This is an associative container.  Values contained within it can be
 *  quickly retrieved through a key element. In contrast with a map a
 *  Multimap can have multiple duplicate keys.
*/
template <class Key, class T, class Compare, class Alloc>
class Multimap : public ElLightRefBase
{
    // concept requirements
    Concept_ClassRequires(T, SGIAssignableConcept)
    Concept_ClassRequires4(Compare, Boolean, Key, Key, BinaryFunctionConcept);

public:

// typedefs:

    typedef Key                 KeyType;
    typedef T                   DataType;
    typedef T                   MappedType;
    typedef Pair<const Key, T>  ValueType;
    typedef Compare             KeyCompare;

    class ValueCompare : public BinaryFunction<ValueType, ValueType, Boolean>
    {
        friend class Multimap<Key,T,Compare,Alloc>;
    protected:
        Compare comp;
        ValueCompare(Compare c) : comp(c) {}
    public:
        Boolean operator()(const ValueType& x, const ValueType& y) const
        {
            return comp(x.mFirst, y.mFirst);
        }
    };

private:
    typedef RBTree<KeyType, ValueType,
                   Select1st<ValueType>, KeyCompare, Alloc> RepType;
    RepType mTree;  // red-black tree representing Multimap
public:
    typedef typename RepType::Pointer Pointer;
    typedef typename RepType::ConstPointer ConstPointer;
    typedef typename RepType::Reference Reference;
    typedef typename RepType::ConstReference ConstReference;
    typedef typename RepType::Iterator Iterator;
    typedef typename RepType::ConstIterator ConstIterator;
    typedef typename RepType::ReverseIterator ReverseIterator;
    typedef typename RepType::ConstReverseIterator ConstReverseIterator;
    typedef typename RepType::SizeType SizeType;
    typedef typename RepType::DifferenceType DifferenceType;
    typedef typename RepType::AllocatorType AllocatorType;

// allocation/deallocation

    Multimap() : mTree(Compare(), AllocatorType()) { }
    explicit Multimap(const Compare& comp,
            const AllocatorType& a = AllocatorType()) : mTree(comp, a) { }

    template <class InputIterator>
    Multimap(InputIterator first, InputIterator last) : mTree(Compare(), AllocatorType())
    {
        mTree.InsertEqual(first, last);
    }

    template <class InputIterator>
    Multimap(InputIterator first, InputIterator last,
             const Compare& comp,
             const AllocatorType& a = AllocatorType()) : mTree(comp, a)
    {
        mTree.InsertEqual(first, last);
    }
    Multimap(const Multimap<Key,T,Compare,Alloc>& x) : mTree(x.mTree) { }

    Multimap<Key,T,Compare,Alloc>&
    operator=(const Multimap<Key,T,Compare,Alloc>& x)
    {
        mTree = x.mTree;
        return *this;
    }

    // accessors:

    KeyCompare KeyComp() const { return mTree.KeyComp(); }
    ValueCompare ValueComp() const { return ValueCompare(mTree.KeyComp()); }
    AllocatorType GetAllocator() const { return mTree.GetAllocator(); }

    /**
     *  Returns a read/write Iterator that points to the first pair in the
     *  Multimap.  Iteration is done in ascending order according to the keys.
    */
    Iterator Begin() { return mTree.Begin(); }

    /**
     *  Returns a read-only (constant) Iterator that points to the first pair
     *  in the Multimap.  Iteration is done in ascending order according to the
     *  keys.
    */
    ConstIterator Begin() const { return mTree.Begin(); }

    /**
     *  Returns a read/write Iterator that points one past the last pair in the
     *  Multimap.  Iteration is done in ascending order according to the keys.
    */
    Iterator End() { return mTree.End(); }

    /**
     *  Returns a read-only (constant) Iterator that points one past the last
     *  pair in the Multimap.  Iteration is done in ascending order according
     *  to the keys.
    */
    ConstIterator End() const { return mTree.End(); }

    /**
     *  Returns a read/write reverse Iterator that points to the last pair in
     *  the Multimap.  Iteration is done in descending order according to the
     *  keys.
    */
    ReverseIterator RBegin() { return mTree.RBegin(); }

    /**
     *  Returns a read-only (constant) reverse Iterator that points to the last
     *  pair in the Multimap.  Iteration is done in descending order according
     *  to the keys.
    */
    ConstReverseIterator RBegin() const { return mTree.RBegin(); }

    /**
     *  Returns a read/write reverse Iterator that points to one before the
     *  first pair in the Multimap.  Iteration is done in descending order
     *  according to the keys.
    */
    ReverseIterator REnd() { return mTree.REnd(); }

    /**
     *  Returns a read-only (constant) reverse Iterator that points to one
     *  before the first pair in the Multimap.  Iteration is done in descending
     *  order according to the keys.
    */
    ConstReverseIterator REnd() const { return mTree.REnd(); }

    /** Returns true if the map is IsEmpty.  (Thus Begin() would equal End().)  */
    Boolean IsEmpty() const { return mTree.IsEmpty(); }

    /** Returns the GetSize of the map.  */
    SizeType GetSize() const { return mTree.GetSize(); }

    /** Returns the maximum GetSize of the map.  */
    SizeType GetMaxSize() const { return mTree.GetMaxSize(); }

    void Swap(Multimap<Key,T,Compare,Alloc>& x) { mTree.Swap(x.mTree); }

    // insert/Erase
    /**
     *  @brief Inserts a std::pair into the Multimap.
     *  @param  x  Pair to be inserted (see std::make_pair for easy creation of
     *             pairs).
     *  @return An Iterator that points to the inserted (key,value) pair.
     *
     *  This function inserts a (key, value) pair into the Multimap.  Contrary
     *  to a std::map the Multimap does not rely on unique keys and thus a
     *  multiple pairs with the same key can be inserted.
    */
    Iterator insert(const ValueType& x) { return mTree.InsertEqual(x); }

    /**
     *  @brief Inserts a std::pair into the Multimap.
     *  @param  position  An Iterator that serves as a hint as to where the
     *                    pair should be inserted.
     *  @param  x  Pair to be inserted (see std::make_pair for easy creation of
     *             pairs).
     *  @return An Iterator that points to the inserted (key,value) pair.
     *
     *  This function inserts a (key, value) pair into the Multimap.  Contrary
     *  to a std::map the Multimap does not rely on unique keys and thus a
     *  multiple pairs with the same key can be inserted.
     *  Note that the first parameter is only a hint and can potentially
     *  improve the performance of the insertion process.  A bad hint would
     *  cause no gains in efficiency.
    */
    Iterator insert(Iterator position, const ValueType& x)
    {
        return mTree.InsertEqual(position, x);
    }

    /**
     *  @brief A template function that attemps to insert elements from
     *         another range (possibly another Multimap or standard container).
     *  @param  first  Iterator pointing to the start of the range to be
     *                 inserted.
     *  @param  last  Iterator pointing to the End of the range to be inserted.
    */
    template <class InputIterator>
    void insert(InputIterator first, InputIterator last)
    {
        mTree.InsertEqual(first, last);
    }

    /**
     *  @brief Erases an element from a Multimap.
     *  @param  position  An Iterator pointing to the element to be erased.
     *
     *  This function erases an element, pointed to by the given Iterator, from
     *  a mutlimap.  Note that this function only erases the element, and that
     *  if the element is itself a Pointer, the pointed-to memory is not
     *  touched in any way.  Managing the Pointer is the user's responsibilty.
    */
    void Erase(Iterator position) { mTree.Erase(position); }

    /**
     *  @brief Erases an element according to the provided key.
     *  @param  x  Key of element to be erased.
     *  @return  Doc me! (Number of elements erased?)
     *
     *  This function erases all elements, located by the given key, from a
     *  Multimap.
     *  Note that this function only erases the element, and that if
     *  the element is itself a Pointer, the pointed-to memory is not touched
     *  in any way.  Managing the Pointer is the user's responsibilty.
    */
    SizeType Erase(const KeyType& x) { return mTree.Erase(x); }

    /**
     *  @brief Erases a [first,last) range of elements from a Multimap.
     *  @param  first  Iterator pointing to the start of the range to be erased.
     *  @param  last  Iterator pointing to the End of the range to be erased.
     *
     *  This function erases a sequence of elements from a Multimap.
     *  Note that this function only erases the elements, and that if
     *  the elements themselves are pointers, the pointed-to memory is not
     *  touched in any way.  Managing the Pointer is the user's responsibilty.
    */
    void Erase(Iterator first, Iterator last)
    {
        mTree.Erase(first, last);
    }

    /** Erases all elements in a Multimap.  Note that this function only erases
     *  the elements, and that if the elements themselves are pointers, the
     *  pointed-to memory is not touched in any way.  Managing the Pointer is
     *  the user's responsibilty.
    */
    void Clear() { mTree.Clear(); }

    // Multimap operations:

    /**
     *  @brief Tries to locate an element in a Multimap.
     *  @param  x  Key of (key, value) pair to be located.
     *  @return  Iterator pointing to sought-after (first matching?) element,
     *           or End() if not found.
     *
     *  This function takes a key and tries to locate the element with which
     *  the key matches.  If successful the function returns an Iterator
     *  pointing to the sought after pair. If unsuccessful it returns the
     *  one past the End ( End() ) Iterator.
    */
    Iterator Find(const KeyType& x) { return mTree.Find(x); }

    /**
     *  @brief Tries to locate an element in a Multimap.
     *  @param  x  Key of (key, value) pair to be located.
     *  @return  Read-only (constant) Iterator pointing to sought-after (first
     *           matching?) element, or End() if not found.
     *
     *  This function takes a key and tries to locate the element with which
     *  the key matches.  If successful the function returns a constant Iterator
     *  pointing to the sought after pair. If unsuccessful it returns the
     *  one past the End ( End() ) Iterator.
    */
    ConstIterator Find(const KeyType& x) const { return mTree.Find(x); }

    /**
     *  @brief Finds the number of elements with given key.
     *  @param  x  Key of (key, value) pairs to be located.
     *  @return Number of elements with specified key.
    */
    SizeType GetCount(const KeyType& x) const { return mTree.GetCount(x); }

    /**
     *  @brief Finds the beginning of a subsequence matching given key.
     *  @param  x  Key of (key, value) pair to be located.
     *  @return  Iterator pointing to first element matching given key, or
     *           End() if not found.
     *
     *  This function returns the first element of a subsequence of elements
     *  that matches the given key.  If unsuccessful it returns an Iterator
     *  pointing to the first element that has a greater value than given key
     *  or End() if no such element exists.
    */
    Iterator GetLowerBound(const KeyType& x) { return mTree.GetLowerBound(x); }

    /**
     *  @brief Finds the beginning of a subsequence matching given key.
     *  @param  x  Key of (key, value) pair to be located.
     *  @return  Read-only (constant) Iterator pointing to first element
     *           matching given key, or End() if not found.
     *
     *  This function returns the first element of a subsequence of elements
     *  that matches the given key.  If unsuccessful the Iterator will point
     *  to the next greatest element or, if no such greater element exists, to
     *  End().
    */
    ConstIterator GetLowerBound(const KeyType& x) const
    {
        return mTree.GetLowerBound(x);
    }

    /**
     *  @brief Finds the End of a subsequence matching given key.
     *  @param  x  Key of (key, value) pair to be located.
     *  @return Iterator pointing to last element matching given key.
    */
    Iterator GetUpperBound(const KeyType& x) {return mTree.GetUpperBound(x); }

    /**
     *  @brief Finds the End of a subsequence matching given key.
     *  @param  x  Key of (key, value) pair to be located.
     *  @return  Read-only (constant) Iterator pointing to last element matching
     *           given key.
    */
    ConstIterator GetUpperBound(const KeyType& x) const
    {
        return mTree.GetUpperBound(x);
    }

    /**
     *  @brief Finds a subsequence matching given key.
     *  @param  x  Key of (key, value) pairs to be located.
     *  @return  Pair of iterators that possibly points to the subsequence
     *           matching given key.
     *
     *  This function improves on lower_bound() and upper_bound() by giving a more
     *  elegant and efficient solution.  It returns a pair of which the first
     *  element possibly points to the first element matching the given key
     *  and the second element possibly points to the last element matching the
     *  given key.  If unsuccessful the first element of the returned pair will
     *  contain an Iterator pointing to the next greatest element or, if no such
     *  greater element exists, to End().
    */
    Pair<Iterator,Iterator> GetEqualRange(const KeyType& x)
    {
        return mTree.GetEqualRange(x);
    }

    /**
     *  @brief Finds a subsequence matching given key.
     *  @param  x  Key of (key, value) pairs to be located.
     *  @return  Pair of read-only (constant) iterators that possibly points to
     *           the subsequence matching given key.
     *
     *  This function improves on lower_bound() and upper_bound() by giving a more
     *  elegant and efficient solution.  It returns a pair of which the first
     *  element possibly points to the first element matching the given key
     *  and the second element possibly points to the last element matching the
     *  given key.  If unsuccessful the first element of the returned pair will
     *  contain an Iterator pointing to the next greatest element or, if no such
     *  a greater element exists, to End().
    */
    Pair<ConstIterator,ConstIterator> GetEqualRange(const KeyType& x) const
    {
        return mTree.GetEqualRange(x);
    }

    template <class K1, class T1, class C1, class A1>
    friend Boolean operator== (const Multimap<K1, T1, C1, A1>&,
                               const Multimap<K1, T1, C1, A1>&);
    template <class K1, class T1, class C1, class A1>
    friend Boolean operator< (const Multimap<K1, T1, C1, A1>&,
                              const Multimap<K1, T1, C1, A1>&);
};

template <class Key, class Tp, class Compare, class Alloc>
inline Boolean operator==(const Multimap<Key,Tp,Compare,Alloc>& x,
                          const Multimap<Key,Tp,Compare,Alloc>& y)
{
    return x.mTree == y.mTree;
}

template <class Key, class Tp, class Compare, class Alloc>
inline Boolean operator<(const Multimap<Key,Tp,Compare,Alloc>& x,
                         const Multimap<Key,Tp,Compare,Alloc>& y)
{
    return x.mTree < y.mTree;
}

template <class Key, class Tp, class Compare, class Alloc>
inline Boolean operator!=(const Multimap<Key,Tp,Compare,Alloc>& x,
                          const Multimap<Key,Tp,Compare,Alloc>& y)
{
    return !(x == y);
}

template <class Key, class Tp, class Compare, class Alloc>
inline Boolean operator>(const Multimap<Key,Tp,Compare,Alloc>& x,
                         const Multimap<Key,Tp,Compare,Alloc>& y)
{
    return y < x;
}

template <class Key, class Tp, class Compare, class Alloc>
inline Boolean operator<=(const Multimap<Key,Tp,Compare,Alloc>& x,
                          const Multimap<Key,Tp,Compare,Alloc>& y)
{
    return !(y < x);
}

template <class Key, class Tp, class Compare, class Alloc>
inline Boolean operator>=(const Multimap<Key,Tp,Compare,Alloc>& x,
                          const Multimap<Key,Tp,Compare,Alloc>& y)
{
    return !(x < y);
}

template <class Key, class Tp, class Compare, class Alloc>
inline void Swap(Multimap<Key,Tp,Compare,Alloc>& x,
                 Multimap<Key,Tp,Compare,Alloc>& y)
{
    x.Swap(y);
}

_ETL_NAMESPACE_END

#endif // __ETL_MULTIMAP_H__
