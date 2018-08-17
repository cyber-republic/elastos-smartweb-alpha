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

#ifndef __ETL_CONSTRUCT_H__
#define __ETL_CONSTRUCT_H__

#include "elastos/utility/etl/etl_def.h"
#include "elastos/utility/etl/etl_type_traits.h"
#include <new>

_ETL_NAMESPACE_BEGIN


/**
 * @maint
 * Constructs an object in existing memory by invoking an allocated
 * object's constructor with an initializer.
 * @endmaint
 */
template <typename T1, typename T2>
inline void Construct(T1* p, const T2& value)
{
    new (static_cast<void*>(p)) T1(value);
}

/**
 * @maint
 * Constructs an object in existing memory by invoking an allocated
 * object's default constructor (no initializers).
 * @endmaint
 */
template <typename T1>
inline void Construct(T1* p)
{
    new (static_cast<void*>(p)) T1();
}

/**
 * @maint
 * Destroy the object pointed to by a pointer type.
 * @endmaint
 */
template <typename T>
inline void Destroy(T* pointer)
{
    pointer->~T();
}

/**
 * @maint
 * Destroy a range of objects with nontrivial destructors.
 *
 * This is a helper function used only by _Destroy().
 * @endmaint
 */
template <typename ForwardIterator>
inline void DestroyAux(ForwardIterator first, ForwardIterator last, FalseType)
{
    for (; first != last; ++first) {
        Destroy(&*first);
    }
}

/**
 * @maint
 * Destroy a range of objects with trivial destructors.  Since the destructors
 * are trivial, there's nothing to do and hopefully this function will be
 * entirely optimized away.
 *
 * This is a helper function used only by _Destroy().
 * @endmaint
 */
template <typename ForwardIterator>
inline void DestroyAux(ForwardIterator, ForwardIterator, TrueType)
{}

/**
 * @maint
 * Destroy a range of objects.  If the value_type of the object has
 * a trivial destructor, the compiler should optimize all of this
 * away, otherwise the objects' destructors must be invoked.
 * @endmaint
 */
template <typename ForwardIterator>
inline void Destroy(ForwardIterator first, ForwardIterator last)
{
    typedef typename IteratorTraits<ForwardIterator>::ValueType ValueType;
    typedef typename TypeTraits<ValueType>::HasTrivialDestructor HasTrivialDestructor;

    DestroyAux(first, last, HasTrivialDestructor());
}


_ETL_NAMESPACE_END

#endif //__ETL_CONSTRUCT_H__