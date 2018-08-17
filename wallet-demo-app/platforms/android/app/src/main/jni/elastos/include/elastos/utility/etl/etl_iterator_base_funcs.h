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

#ifndef __ETL_ITERATOR_BASE_FUNCS_H__
#define __ETL_ITERATOR_BASE_FUNCS_H__

#include "elastos/utility/etl/etl_def.h"
#include "elastos/utility/etl/ConceptCheck.h"

_ETL_NAMESPACE_BEGIN

template <typename InputIterator>
inline typename IteratorTraits<InputIterator>::DifferenceType
__Distance(InputIterator first, InputIterator last, InputIteratorTag)
{
    //concept requirements
    Concept_FunctionRequires(InputIteratorConcept<InputIterator>)

    typename IteratorTraits<InputIterator>::DifferenceType n = 0;
    while (first != last) {
        ++first;
        ++n;
    }
    return n;
}

template <typename RandomAccessIterator>
inline typename IteratorTraits<RandomAccessIterator>::DifferenceType
__Distance(RandomAccessIterator first, RandomAccessIterator last, RandomAccessIteratorTag)
{
    //concept requirements
    Concept_FunctionRequires(RandomAccessIteratorConcept<RandomAccessIterator>)
    return last - first;
}


/**
 *  @brief A generalization of pointer arithmetic.
 *  @param  first  An input iterator.
 *  @param  last  An input iterator.
 *  @return  The distance between them.
 *
 *  Returns @c n such that first + n == last.  This requires that @p last
 *  must be reachable from @p first.  Note that @c n may be negative.
 *
 *  For random access iterators, this uses their @c + and @c - operations
 *  and are constant time.  For other %iterator classes they are linear time.
*/
template <typename InputIterator>
inline typename IteratorTraits<InputIterator>::DifferenceType
Distance(InputIterator first, InputIterator last)
{
    return __Distance(first, last, IteratorCategory(first));
}


template <typename InputIterator, typename Distance>
inline void __Advance(InputIterator& i, Distance n, InputIteratorTag)
{
    //conept requirements
    Concept_FunctionRequires(InputIteratorConcept<InputIterator>)
    while(n--) ++i;
}

template <typename BidirectionalIterator, typename Distance>
inline void __Advance(BidirectionalIterator& i, Distance n, BidirectionalIteratorTag)
{
    //concept requirements
    Concept_FunctionRequires(BidirectionalIteratorConcept<BidirectionalIterator>)

    if (n > 0) {
        while (n--) ++i;
    }
    else {
        while (n++) --i;
    }
}

template <typename RandomAccessIterator, typename Distance>
inline void __Advance(RandomAccessIterator& i, Distance n, RandomAccessIteratorTag)
{
    //concept requirements
    Concept_FunctionRequires(RandomAccessIteratorConcept<RandomAccessIterator>)
    i += n;
}

/**
 *  @brief A generalization of pointer arithmetic.
 *  @param  i  An input iterator.
 *  @param  n  The "delta" by which to change @p i.
 *  @return  Nothing.
 *
 *  This increments @p i by @p n.  For bidirectional and random access
 *  iterators, @p n may be negative, in which case @p i is decremented.
 *
 *  For random access iterators, this uses their @c + and @c - operations
 *  and are constant time.  For other %iterator classes they are linear time.
*/
template <typename InputIterator, typename Distance>
inline void Advance(InputIterator& i, Distance n)
{
    __Advance(i, n, IteratorCategory(i));
}

_ETL_NAMESPACE_END

#endif //__ETL_ITERATOR_BASE_FUNCS_H__
