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

#ifndef __ETL_TYPE_TRAITS_H__
#define __ETL_TYPE_TRAITS_H__

#include "elastos/utility/etl/etl_def.h"

_ETL_NAMESPACE_BEGIN

struct TrueType {};
struct FalseType {};

template <typename T>
struct TypeTraits
{
    typedef TrueType    ThisDummyMemberMustBeFirst;
    typedef FalseType   HasTrivialDefaultConstructor;
    typedef FalseType   HasTrivialCopyConstructor;
    typedef FalseType   HasTrivialAssignmentOperator;
    typedef FalseType   HasTrivialDestructor;
    typedef FalseType   IsPODType;
};

template <>
struct TypeTraits<Boolean>
{
    typedef TrueType    HasTrivialDefaultConstructor;
    typedef TrueType    HasTrivialCopyConstructor;
    typedef TrueType    HasTrivialAssignmentOperator;
    typedef TrueType    HasTrivialDestructor;
    typedef TrueType    IsPODType;
};

template <>
struct TypeTraits<Char16>
{
    typedef TrueType    HasTrivialDefaultConstructor;
    typedef TrueType    HasTrivialCopyConstructor;
    typedef TrueType    HasTrivialAssignmentOperator;
    typedef TrueType    HasTrivialDestructor;
    typedef TrueType    IsPODType;
};

template <>
struct TypeTraits<Char32>
{
    typedef TrueType    HasTrivialDefaultConstructor;
    typedef TrueType    HasTrivialCopyConstructor;
    typedef TrueType    HasTrivialAssignmentOperator;
    typedef TrueType    HasTrivialDestructor;
    typedef TrueType    IsPODType;
};

template <>
struct TypeTraits<Int16>
{
    typedef TrueType    HasTrivialDefaultConstructor;
    typedef TrueType    HasTrivialCopyConstructor;
    typedef TrueType    HasTrivialAssignmentOperator;
    typedef TrueType    HasTrivialDestructor;
    typedef TrueType    IsPODType;
};

template <>
struct TypeTraits<Int32>
{
    typedef TrueType    HasTrivialDefaultConstructor;
    typedef TrueType    HasTrivialCopyConstructor;
    typedef TrueType    HasTrivialAssignmentOperator;
    typedef TrueType    HasTrivialDestructor;
    typedef TrueType    IsPODType;
};

template <>
struct TypeTraits<Int64>
{
    typedef TrueType    HasTrivialDefaultConstructor;
    typedef TrueType    HasTrivialCopyConstructor;
    typedef TrueType    HasTrivialAssignmentOperator;
    typedef TrueType    HasTrivialDestructor;
    typedef TrueType    IsPODType;
};

template <>
struct TypeTraits<Float>
{
    typedef TrueType    HasTrivialDefaultConstructor;
    typedef TrueType    HasTrivialCopyConstructor;
    typedef TrueType    HasTrivialAssignmentOperator;
    typedef TrueType    HasTrivialDestructor;
    typedef TrueType    IsPODType;
};

template <>
struct TypeTraits<Double>
{
    typedef TrueType    HasTrivialDefaultConstructor;
    typedef TrueType    HasTrivialCopyConstructor;
    typedef TrueType    HasTrivialAssignmentOperator;
    typedef TrueType    HasTrivialDestructor;
    typedef TrueType    IsPODType;
};

template <typename T>
struct TypeTraits<T*>
{
    typedef TrueType    HasTrivialDefaultConstructor;
    typedef TrueType    HasTrivialCopyConstructor;
    typedef TrueType    HasTrivialAssignmentOperator;
    typedef TrueType    HasTrivialDestructor;
    typedef TrueType    IsPODType;
};

// The following could be written in terms of numeric_limits.
// We're doing it separately to reduce the number of dependencies.

template <typename T>
struct IsInteger
{
    typedef FalseType Integral;
};

template<>
struct IsInteger<bool>
{
    typedef TrueType Integral;
};

template<>
struct IsInteger<char>
{
    typedef TrueType Integral;
};

template<>
struct IsInteger<signed char>
{
    typedef TrueType Integral;
};

template<>
struct IsInteger<unsigned char>
{
    typedef TrueType Integral;
};

template<>
struct IsInteger<short>
{
    typedef TrueType Integral;
};

template<>
struct IsInteger<unsigned short>
{
    typedef TrueType Integral;
};

template<>
struct IsInteger<int>
{
    typedef TrueType Integral;
};

template<>
struct IsInteger<unsigned int>
{
    typedef TrueType Integral;
};

template<>
struct IsInteger<long>
{
    typedef TrueType Integral;
};

template<>
struct IsInteger<unsigned long>
{
    typedef TrueType Integral;
};

template<>
struct IsInteger<long long>
{
    typedef TrueType Integral;
};

template<>
struct IsInteger<unsigned long long>
{
    typedef TrueType Integral;
};

template<typename T>
struct IsNormalIterator
{
    typedef FalseType Normal;
};

// Forward declaration hack, should really include this from somewhere.
template<typename Iterator, typename Container> class NormalIterator;

template<typename Iterator, typename Container>
struct IsNormalIterator<NormalIterator<Iterator, Container> >
{
    typedef TrueType Normal;
};

_ETL_NAMESPACE_END

#endif //__ETL_TYPE_TRAITS_H__
