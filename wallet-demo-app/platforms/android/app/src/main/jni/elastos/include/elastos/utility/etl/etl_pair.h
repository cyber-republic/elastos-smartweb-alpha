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

#ifndef __ETL_PAIR_H__
#define __ETL_PAIR_H__

#include "elastos/utility/etl/etl_def.h"
#include <elrefbase.h>

using Elastos::ElLightRefBase;

_ETL_NAMESPACE_BEGIN


/// pair holds two objects of arbitrary type.
template <typename T1, typename T2>
struct Pair : public ElLightRefBase
{
    typedef T1 FirstType;    ///<  @c first_type is the first bound type
    typedef T2 SecondType;   ///<  @c second_type is the second bound type

    T1 mFirst;                 ///< @c first is a copy of the first object
    T2 mSecond;                ///< @c second is a copy of the second object

#ifdef _ETL_CONST_CONSTRUCTOR_BUG
    //265.  std::pair::pair() effects overly restrictive
    /** The default constructor creates @c first and @c second using their
    *  respective default constructors.  */
    Pair() : mFirst(), mSecond() {}
#else
    Pair() : mFirst(T1()), mSecond(T2()) {}
#endif
    /** Two objects may be passed to a @c pair constructor to be copied.  */
    Pair(const T1& a, const T2& b) : mFirst(a), mSecond(b) {}

    /** There is also a templated copy ctor for the @c pair class itself.  */
    template <typename U1, typename U2>
    Pair(const Pair<U1, U2>& p) : mFirst(p.mFirst), mSecond(p.mSecond) {}
};

// Two pairs of the same type are equal iff their members are equal.
template <typename T1, typename T2>
inline Boolean operator==(const Pair<T1, T2>& x, const Pair<T1, T2>& y)
{
    return x.mFirst == y.mFirst && x.mSecond == y.mSecond;
}

// http://gcc.gnu.org/onlinedocs/libstdc++/20_util/howto.html#pairlt
template <typename T1, typename T2>
inline Boolean operator<(const Pair<T1, T2>& x, const Pair<T1, T2>& y)
{
    return x.mFirst < y.mFirst || (!(y.mFirst < x.mFirst) && x.mSecond < y.mSecond);
}

// Uses @c operator== to find the result.
template <typename T1, typename T2>
inline Boolean operator!=(const Pair<T1, T2>& x, const Pair<T1, T2>& y)
{
    return !(x == y);
}

// Uses @c operator< to find the result.
template <typename T1, typename T2>
inline Boolean operator>(const Pair<T1, T2>& x, const Pair<T1, T2>& y)
{
    return y < x;
}

// Uses @c operator< to find the result.
template <typename T1, typename T2>
inline Boolean operator<=(const Pair<T1, T2>& x, const Pair<T1, T2>& y)
{
    return !(y < x);
}

// Uses @c operator< to find the result.
template <typename T1, typename T2>
inline Boolean operator>=(const Pair<T1, T2>& x, const Pair<T1, T2>& y)
{
    return !(x < y);
}

/**
 *  @brief A convenience wrapper for creating a pair from two objects.
 *  @param  x  The first object.
 *  @param  y  The second object.
 *  @return   A newly-constructed pair<> object of the appropriate type.
 *
 *  The standard requires that the objects be passed by reference-to-const,
 *  but LWG issue #181 says they should be passed by const value.  We follow
 *  the LWG by default.
*/
template <typename T1, typename T2>
#ifdef _GLIBCPP_RESOLVE_LIB_DEFECTS
//181.  make_pair() unintended behavior
inline Pair<T1, T2> MakePair(T1 x, T2 y)
#else
inline Pair<T1, T2> MakePair(const T1& x, const T2& y)
#endif
{
    return Pair<T1, T2>(x, y);
}


_ETL_NAMESPACE_END

#endif //__ETL_PAIR_H__
