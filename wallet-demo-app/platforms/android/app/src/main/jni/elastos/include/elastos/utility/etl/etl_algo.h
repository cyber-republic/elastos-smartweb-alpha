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

#ifndef __ETL_ALGO_H__
#define __ETL_ALGO_H__

#include "elastos/utility/etl/etl_def.h"
#include "elastos/utility/etl/etl_heap.h"

_ETL_NAMESPACE_BEGIN


/**
 *  @maint
 *  This is an overload used by find() for the Input Iterator case.
 *  @endmaint
*/
template<typename InputIterator, typename T>
inline InputIterator
Find(InputIterator first, InputIterator last, const T& val, InputIteratorTag)
{
    while (first != last && !(*first == val)) {
        ++first;
    }

    return first;
}

/**
 *  @maint
 *  This is an overload used by find() for the RAI case.
 *  @endmaint
*/
template<typename RandomAccessIterator, typename T>
RandomAccessIterator
Find(RandomAccessIterator first, RandomAccessIterator last, const T& val, RandomAccessIteratorTag)
{
    typename IteratorTraits<RandomAccessIterator>::DifferenceType \
            tripCount = (last - first) >> 2;

    for ( ; tripCount > 0 ; --tripCount) {
        if (*first == val) return first;
        ++first;

        if (*first == val) return first;
        ++first;

        if (*first == val) return first;
        ++first;

        if (*first == val) return first;
        ++first;
    }

    switch(last - first) {
    case 3:
        if (*first == val) return first;
        ++first;
    case 2:
        if (*first == val) return first;
        ++first;
    case 1:
        if (*first == val) return first;
        ++first;
    case 0:
    default:
        return last;
    }
}

/**
 *  @brief Find the first occurrence of a value in a sequence.
 *  @param  first  An input iterator.
 *  @param  last   An input iterator.
 *  @param  val    The value to find.
 *  @return   The first iterator @c i in the range @p [first,last)
 *  such that @c *i == @p val, or @p last if no such iterator exists.
*/
template<typename InputIterator, typename T>
inline InputIterator
Find(InputIterator first, InputIterator last, const T& val)
{
    // concept requirements
    Concept_FunctionRequires(InputIteratorConcept<InputIterator>)
    Concept_FunctionRequires(EqualOpConcept<
            typename IteratorTraits<InputIterator>::ValueType, T>)

    return Find(first, last, val, IteratorCategory(first));
}

// Binary search (GetLowerBound, upper_bound, equal_range, binary_search).

template<typename ForwardIterator, typename T>
ForwardIterator
GetLowerBound(ForwardIterator first, ForwardIterator last, const T& val)
{
    typedef typename IteratorTraits<ForwardIterator>::ValueType ValueType;
    typedef typename IteratorTraits<ForwardIterator>::DifferenceType DistanceType;

    // concept requirements
    // Note that these are slightly stricter than those of the 4-argument
    // version, defined next.  The difference is in the strictness of the
    // comparison operations... so for looser checking, define your own
    // comparison function, as was intended.
    Concept_FunctionRequires(ForwardIteratorConcept<ForwardIterator>)
    Concept_FunctionRequires(SameTypeConcept<T, ValueType>)
    Concept_FunctionRequires(LessThanComparableConcept<T>)

    DistanceType len = Distance(first, last);
    DistanceType half;
    ForwardIterator middle;

    while (len > 0) {
        half = len >> 1;
        middle = first;
        Advance(middle, half);
        if (*middle < val) {
            first = middle;
            ++first;
            len = len - half - 1;
        }
        else len = half;
    }
    return first;
}

template<typename ForwardIterator, typename T, typename Compare>
ForwardIterator
GetLowerBound(ForwardIterator first, ForwardIterator last,
        const T& val, Compare comp)
{
    typedef typename IteratorTraits<ForwardIterator>::ValueType ValueType;
    typedef typename IteratorTraits<ForwardIterator>::DifferenceType DistanceType;

    // concept requirements
    Concept_FunctionRequires(ForwardIteratorConcept<ForwardIterator>)
    Concept_FunctionRequires(BinaryPredicateConcept<Compare, ValueType, T>)

    DistanceType len = Distance(first, last);
    DistanceType half;
    ForwardIterator middle;

    while (len > 0) {
        half = len >> 1;
        middle = first;
        Advance(middle, half);
        if (comp(*middle, val)) {
            first = middle;
            ++first;
            len = len - half - 1;
        }
        else len = half;
    }
    return first;
}


_ETL_NAMESPACE_END

#endif //__ETL_ALGO_H__
