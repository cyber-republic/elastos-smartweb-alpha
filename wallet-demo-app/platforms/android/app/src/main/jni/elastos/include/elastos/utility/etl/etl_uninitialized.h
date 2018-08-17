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

#ifndef __ETL_UNINITIALIZED_H__
#define __ETL_UNINITIALIZED_H__

#include "elastos/utility/etl/etl_def.h"
#include "elastos/utility/etl/etl_exception_defines.h"

_ETL_NAMESPACE_BEGIN

template <typename InputIterator, typename ForwardIterator>
inline ForwardIterator UninitializedCopyAux(
        InputIterator first, InputIterator last, ForwardIterator result, TrueType)
{
    return Copy(first, last, result);
}

template <typename InputIterator, typename ForwardIterator>
ForwardIterator UninitializedCopyAux(
        InputIterator first, InputIterator last, ForwardIterator result, FalseType)
{
    ForwardIterator current = result;
    try {
        for (; first != last; ++first, ++current) {
            Construct(&*current, *first);
        }
        return current;
    }
    catch(...) {
        Destroy(result, current);
        THROW_EXCEPTION_AGAIN;
    }
}

template <typename InputIterator, typename ForwardIterator>
inline ForwardIterator UninitializedCopy(
        InputIterator first, InputIterator last, ForwardIterator result)
{
    typedef typename IteratorTraits<InputIterator>::ValueType ValueType;
    typedef typename TypeTraits<ValueType>::IsPODType IsPOD;
    return UninitializedCopyAux(first, last, result, IsPOD());
}

inline char* UninitializedCopy(
        const char* first, const char* last, char* result)
{
    memmove(result, first, last - first);
    return result + (last - first);
}

template <typename ForwardIterator, typename T>
inline void UninitializedFillAux(
        ForwardIterator first, ForwardIterator last, const T& x, TrueType)
{
    Fill(first, last, x);
}

template <typename ForwardIterator, typename T>
void UninitializedFillAux(
        ForwardIterator first, ForwardIterator last, const T& x, FalseType)
{
    ForwardIterator current = first;
    try {
        for(; current != last; ++current) {
            Construct(&*current, x);
        }
    }
    catch(...) {
        Destroy(first, current);
        THROW_EXCEPTION_AGAIN;
    }
}

template <typename ForwardIterator, typename T>
inline void UninitializedFill(
        ForwardIterator first, ForwardIterator last, const T& x)
{
    typedef typename IteratorTraits<ForwardIterator>::ValueType ValueType;
    typedef typename TypeTraits<ValueType>::IsPODType IsPOD;
    UninitializedFillAux(first, last, x, IsPOD());
}

template <typename ForwardIterator, typename Size, typename T>
inline ForwardIterator UninitializedFillNAux(
        ForwardIterator first, Size n, const T& x, TrueType)
{
    return FillN(first, n, x);
}

template <typename ForwardIterator, typename Size, typename T>
inline ForwardIterator UninitializedFillNAux(
        ForwardIterator first, Size n, const T& x, FalseType)
{
    ForwardIterator current = first;
    try {
        for (; n > 0; --n, ++current) {
            Construct(&*current, x);
        }
        return current;
    }
    catch(...){
        Destroy(first, current);
        THROW_EXCEPTION_AGAIN;
    }
}

template <typename ForwardIterator, typename Size, typename T>
inline ForwardIterator UninitializedFillN(
        ForwardIterator first, Size n, const T& x)
{
    typedef typename IteratorTraits<ForwardIterator>::ValueType ValueType;
    typedef typename TypeTraits<ValueType>::IsPODType IsPOD;
    return UninitializedFillNAux(first, n, x, IsPOD());
}

template <typename InputIterator1, typename InputIterator2, typename ForwardIterator>
inline ForwardIterator UninitializedCopyCopy(
        InputIterator1 first1, InputIterator1 last1,
        InputIterator2 first2, InputIterator2 last2, ForwardIterator result)
{
    ForwardIterator middle = UninitializedCopy(first1, last1, result);
    try {
        return UninitializedCopy(first2, last2, middle);
    }
    catch(...) {
        Destroy(result, middle);
        THROW_EXCEPTION_AGAIN;
    }
}

template <typename ForwardIterator, typename T, typename InputIterator>
inline ForwardIterator UninitializedFillCopy(
        ForwardIterator result, ForwardIterator middle, const T& x,
        InputIterator first, InputIterator last)
{
    UninitializedFill(result, middle, x);
    try {
        return UninitializedCopy(first, last, middle);
    }
    catch(...) {
        Destroy(result, middle);
        THROW_EXCEPTION_AGAIN;
    }
}

template <typename InputIterator, typename ForwardIterator, typename T>
inline void UninitializedCopyFill(
        InputIterator first1, InputIterator last1,
        ForwardIterator first2, ForwardIterator last2, const T& x)
{
    ForwardIterator middle2 = UninitializedCopy(first1, last1, first2);
    try {
        UninitializedFill(middle2, last2, x);
    }
    catch(...) {
        Destroy(first2, middle2);
        THROW_EXCEPTION_AGAIN;
    }
}


_ETL_NAMESPACE_END

#endif //__ETL_UNINITIALIZED_H__