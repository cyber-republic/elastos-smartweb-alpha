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

#ifndef __ETL_ITERATOR_BASE_TYPES_H__
#define __ETL_ITERATOR_BASE_TYPES_H__

#include "elastos/utility/etl/etl_def.h"

_ETL_NAMESPACE_BEGIN

struct InputIteratorTag {};
struct OutputIteratorTag {};
struct ForwardIteratorTag : public InputIteratorTag {};
struct BidirectionalIteratorTag : public ForwardIteratorTag {};
struct RandomAccessIteratorTag : public BidirectionalIteratorTag {};

template <typename Category, typename T, typename Distance = ptrdiff_t,
        typename _Pointer = T*, typename _Reference = T&>
struct Iterator
{
    typedef Category    IteratorCategory;
    typedef T           ValueType;
    typedef Distance    DifferenceType;
    typedef _Pointer    Pointer;
    typedef _Reference  Reference;
};

template <typename Iterator>
struct IteratorTraits
{
    typedef typename Iterator::IteratorCategory IteratorCategory;
    typedef typename Iterator::ValueType        ValueType;
    typedef typename Iterator::DifferenceType   DifferenceType;
    typedef typename Iterator::Pointer          Pointer;
    typedef typename Iterator::Reference        Reference;
};

template <typename T>
struct IteratorTraits<T*>
{
    typedef RandomAccessIteratorTag IteratorCategory;
    typedef T                       ValueType;
    typedef ptrdiff_t               DifferenceType;
    typedef T*                      Pointer;
    typedef T&                      Reference;
};

template <typename T>
struct IteratorTraits<const T*>
{
    typedef RandomAccessIteratorTag IteratorCategory;
    typedef T                       ValueType;
    typedef ptrdiff_t               DifferenceType;
    typedef const T*                Pointer;
    typedef const T&                Reference;
};

template <typename Iterator>
inline typename IteratorTraits<Iterator>::IteratorCategory
IteratorCategory(const Iterator&)
{
    return typename IteratorTraits<Iterator>::IteratorCategory();
}

_ETL_NAMESPACE_END

#endif //__ETL_ITERATOR_BASE_TYPES_H__
