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

#ifndef __ETL_HASH_FUN_H__
#define __ETL_HASH_FUN_H__

#include "elastos/utility/etl/etl_def.h"

_ETL_NAMESPACE_BEGIN

template <class Key>
struct Hash { };

inline size_t HashString(const char* s)
{
    unsigned long h = 0;
    if (s != NULL) {
        for ( ; *s; ++s) {
            h = 5*h + *s;
        }
    }
    return size_t(h);
}

template<> struct Hash<char*>
{
    size_t operator()(const char* s) const { return HashString(s); }
};

template<> struct Hash<const char*>
{
    size_t operator()(const char* s) const { return HashString(s); }
};

template<> struct Hash<String>
{
    size_t operator()(String s) const { return s.GetHashCode(); }
};

template<> struct Hash<char>
{
    size_t operator()(char x) const { return x; }
};

template<> struct Hash<unsigned char>
{
    size_t operator()(unsigned char x) const { return x; }
};

template<> struct Hash<signed char>
{
    size_t operator()(unsigned char x) const { return x; }
};

template<> struct Hash<short>
{
    size_t operator()(short x) const { return x; }
};

template<> struct Hash<unsigned short>
{
    size_t operator()(unsigned short x) const { return x; }
};

template<> struct Hash<int>
{
    size_t operator()(int x) const { return x; }
};

template<> struct Hash<unsigned int>
{
    size_t operator()(unsigned int x) const { return x; }
};

#if (!defined(_ELASTOS64))
template<> struct Hash<long>
{
    size_t operator()(long x) const { return x; }
};
#endif

template<> struct Hash<unsigned long>
{
    size_t operator()(unsigned long x) const { return x; }
};

template<> struct Hash<Int64>
{
    size_t operator()(Int64 x) const { return x; }
};

_ETL_NAMESPACE_END


#endif //__ETL_HASH_FUN_H__
