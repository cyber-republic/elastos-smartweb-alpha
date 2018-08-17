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

/** @file stl_heap.h
 *  This is an internal header file, included by other library headers.
 *  You should not attempt to use it directly.
 */

#ifndef __ETL_HEAP_H__
#define __ETL_HEAP_H__

_ETL_NAMESPACE_BEGIN

// Heap-manipulation functions: PushHeap, PopHeap, MakeHeap, SortHeap.

template<typename RandomAccessIterator, typename Distance, typename Tp>
void
__PushHeap(RandomAccessIterator first,
    Distance holeIndex, Distance topIndex, Tp value)
{
    Distance parent = (holeIndex - 1) / 2;
    while (holeIndex > topIndex && *(first + parent) < value) {
        *(first + holeIndex) = *(first + parent);
        holeIndex = parent;
        parent = (holeIndex - 1) / 2;
    }
    *(first + holeIndex) = value;
}

template<typename RandomAccessIterator>
inline void
PushHeap(RandomAccessIterator first, RandomAccessIterator last)
{
    typedef typename IteratorTraits<RandomAccessIterator>::ValueType
    _ValueType;
    typedef typename IteratorTraits<RandomAccessIterator>::DifferenceType
    _DistanceType;

    // concept requirements
    Concept_FunctionRequires(MutableRandomAccessIteratorConcept<
        RandomAccessIterator>)
    Concept_FunctionRequires(LessThanComparableConcept<_ValueType>)

    __PushHeap(first, _DistanceType((last - first) - 1), _DistanceType(0),
        _ValueType(*(last - 1)));
}

template<typename RandomAccessIterator, typename Distance, typename Tp,
    typename Compare>
void
__PushHeap(RandomAccessIterator first, Distance holeIndex,
    Distance topIndex, Tp value, Compare comp)
{
    Distance parent = (holeIndex - 1) / 2;
    while (holeIndex > topIndex && comp(*(first + parent), value)) {
        *(first + holeIndex) = *(first + parent);
        holeIndex = parent;
        parent = (holeIndex - 1) / 2;
    }
    *(first + holeIndex) = value;
}

template<typename RandomAccessIterator, typename Compare>
inline void
PushHeap(RandomAccessIterator first, RandomAccessIterator last,
      Compare comp)
{
    typedef typename IteratorTraits<RandomAccessIterator>::ValueType
    _ValueType;
    typedef typename IteratorTraits<RandomAccessIterator>::DifferenceType
    _DistanceType;

    // concept requirements
    Concept_FunctionRequires(MutableRandomAccessIteratorConcept<
        RandomAccessIterator>)

    __PushHeap(first, _DistanceType((last - first) - 1), _DistanceType(0),
        _ValueType(*(last - 1)), comp);
}

template<typename RandomAccessIterator, typename Distance, typename Tp>
void
__AdjustHeap(RandomAccessIterator first, Distance holeIndex,
      Distance len, Tp value)
{
    Distance topIndex = holeIndex;
    Distance secondChild = 2 * holeIndex + 2;
    while (secondChild < len) {
        if (*(first + secondChild) < *(first + (secondChild - 1))) {
            secondChild--;
        }
        *(first + holeIndex) = *(first + secondChild);
        holeIndex = secondChild;
        secondChild = 2 * (secondChild + 1);
    }
    if (secondChild == len) {
        *(first + holeIndex) = *(first + (secondChild - 1));
        holeIndex = secondChild - 1;
    }
    __PushHeap(first, holeIndex, topIndex, value);
}

template<typename RandomAccessIterator, typename Tp>
inline void
__PopHeap(RandomAccessIterator first, RandomAccessIterator last,
       RandomAccessIterator result, Tp value)
{
    typedef typename IteratorTraits<RandomAccessIterator>::DifferenceType Distance;
    *result = *first;
    __AdjustHeap(first, Distance(0), Distance(last - first), value);
}

template<typename RandomAccessIterator>
inline void
PopHeap(RandomAccessIterator first, RandomAccessIterator last)
{
    typedef typename IteratorTraits<RandomAccessIterator>::ValueType _ValueType;

    // concept requirements
    Concept_FunctionRequires(MutableRandomAccessIteratorConcept<
        RandomAccessIterator>)
    Concept_FunctionRequires(LessThanComparableConcept<_ValueType>)

    __PopHeap(first, last - 1, last - 1, _ValueType(*(last - 1)));
}

template<typename RandomAccessIterator, typename Distance,
   typename Tp, typename Compare>
void
__AdjustHeap(RandomAccessIterator first, Distance holeIndex,
      Distance len, Tp value, Compare comp)
{
    Distance topIndex = holeIndex;
    Distance secondChild = 2 * holeIndex + 2;
    while (secondChild < len) {
        if (comp(*(first + secondChild), *(first + (secondChild - 1)))) {
            secondChild--;
        }
        *(first + holeIndex) = *(first + secondChild);
        holeIndex = secondChild;
        secondChild = 2 * (secondChild + 1);
    }
    if (secondChild == len) {
        *(first + holeIndex) = *(first + (secondChild - 1));
        holeIndex = secondChild - 1;
    }
    __PushHeap(first, holeIndex, topIndex, value, comp);
}

template<typename RandomAccessIterator, typename Tp, typename Compare>
inline void
__PopHeap(RandomAccessIterator first, RandomAccessIterator last,
       RandomAccessIterator result, Tp value, Compare comp)
{
    typedef typename IteratorTraits<RandomAccessIterator>::DifferenceType Distance;
    *result = *first;
    __AdjustHeap(first, Distance(0), Distance(last - first),
        value, comp);
}

template<typename RandomAccessIterator, typename Compare>
inline void
PopHeap(RandomAccessIterator first,
     RandomAccessIterator last, Compare comp)
{
    // concept requirements
    Concept_FunctionRequires(MutableRandomAccessIteratorConcept<
        RandomAccessIterator>)

    typedef typename IteratorTraits<RandomAccessIterator>::ValueType _ValueType;
    __PopHeap(first, last - 1, last - 1, _ValueType(*(last - 1)), comp);
}

template<typename RandomAccessIterator>
void
MakeHeap(RandomAccessIterator first, RandomAccessIterator last)
{
    typedef typename IteratorTraits<RandomAccessIterator>::ValueType
    _ValueType;
    typedef typename IteratorTraits<RandomAccessIterator>::DifferenceType
    _DistanceType;

    // concept requirements
    Concept_FunctionRequires(MutableRandomAccessIteratorConcept<
        RandomAccessIterator>)
    Concept_FunctionRequires(LessThanComparableConcept<_ValueType>)

    if (last - first < 2) return;
    _DistanceType len = last - first;
    _DistanceType parent = (len - 2)/2;

    while (TRUE) {
        __AdjustHeap(first, parent, len, _ValueType(*(first + parent)));
        if (parent == 0) return;
        parent--;
    }
}

template<typename RandomAccessIterator, typename Compare>
inline void
MakeHeap(RandomAccessIterator first, RandomAccessIterator last,
      Compare comp)
{
    typedef typename IteratorTraits<RandomAccessIterator>::ValueType
    _ValueType;
    typedef typename IteratorTraits<RandomAccessIterator>::DifferenceType
    _DistanceType;

    // concept requirements
    Concept_FunctionRequires(MutableRandomAccessIteratorConcept<
        RandomAccessIterator>)

    if (last - first < 2) return;
    _DistanceType len = last - first;
    _DistanceType parent = (len - 2)/2;

    while (TRUE) {
        __AdjustHeap(first, parent, len,
                  _ValueType(*(first + parent)), comp);
        if (parent == 0) return;
        parent--;
    }
}

template<typename RandomAccessIterator>
void
SortHeap(RandomAccessIterator first, RandomAccessIterator last)
{
    // concept requirements
    Concept_FunctionRequires(MutableRandomAccessIteratorConcept<
        RandomAccessIterator>)
    Concept_FunctionRequires(LessThanComparableConcept<
        typename IteratorTraits<RandomAccessIterator>::ValueType>)

    while (last - first > 1) {
        PopHeap(first, last--);
    }
}

template<typename RandomAccessIterator, typename Compare>
void
SortHeap(RandomAccessIterator first, RandomAccessIterator last,
      Compare comp)
{
    // concept requirements
    Concept_FunctionRequires(MutableRandomAccessIteratorConcept<
        RandomAccessIterator>)

    while (last - first > 1) {
        PopHeap(first, last--, comp);
    }
}

_ETL_NAMESPACE_END

#endif //__ETL_HEAP_H__
