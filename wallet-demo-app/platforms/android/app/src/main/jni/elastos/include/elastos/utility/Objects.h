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

#ifndef __ELASTOS_UTILITY_OBJECTS_H__
#define __ELASTOS_UTILITY_OBJECTS_H__

#include "elastos/core/Object.h"

using Elastos::Core::IComparator;
using Elastos::Core::IArrayOf;

namespace Elastos {
namespace Utility {

/**
 * Utility methods for objects.
 * @since 1.7
 */
class Objects {
public:
    /**
     * Returns 0 if {@code a == b}, or {@code c.compare(a, b)} otherwise.
     * That is, this makes {@code c} null-safe.
     */
    template<typename T>
    static CARAPI_(Int32) Compare(
        /* [in] */ T* a,
        /* [in] */ T* b,
        /* [in] */ IComparator* c);

    template<typename T>
    static CARAPI_(Int32) Compare(
        /* [in] */ const AutoPtr<T>& a,
        /* [in] */ const AutoPtr<T>& b,
        /* [in] */ IComparator* c);

    /**
     * Returns true if both arguments are null,
     * the result of {@link Arrays#equals} if both arguments are primitive arrays,
     * the result of {@link Arrays#deepEquals} if both arguments are arrays of reference types,
     * and the result of {@link #equals} otherwise.
     */
    template<typename T>
    static CARAPI_(Boolean) DeepEquals(
        /* [in] */ T* a,
        /* [in] */ T* b);

    template<typename T>
    static CARAPI_(Boolean) DeepEquals(
        /* [in] */ const AutoPtr<T>& a,
        /* [in] */ const AutoPtr<T>& b);

    /**
     * Null-safe equivalent of {@code a.equals(b)}.
     */
    template<typename T>
    static CARAPI_(Boolean) Equals(
        /* [in] */ T* a,
        /* [in] */ T* b);

    template<typename T>
    static CARAPI_(Boolean) Equals(
        /* [in] */ const AutoPtr<T>& a,
        /* [in] */ const AutoPtr<T>& b);

    /**
     * Returns 0 for null or {@code o.hashCode()}.
     */
    template<typename T>
    static CARAPI_(Int32) GetHashCode(
        /* [in] */ T* a);

    template<typename T>
    static CARAPI_(Int32) GetHashCode(
        /* [in] */ const AutoPtr<T>& a);

    /**
     * Returns {@code o} if non-null, or throws {@code NullPointerException}.
     */
    template<typename T>
    static CARAPI RequireNonNull(
        /* [in] */ T* a);

    template<typename T>
    static CARAPI RequireNonNull(
        /* [in] */ const AutoPtr<T>& a);

    /**
     * Returns "null" for null or {@code o.toString()}.
     */
    template<typename T>
    static CARAPI_(String) ToString(
        /* [in] */ T* a);

    template<typename T>
    static CARAPI_(String) ToString(
        /* [in] */ const AutoPtr<T>& a);

    /**
     * Returns {@code nullString} for null or {@code o.toString()}.
     */
    template<typename T>
    static CARAPI_(String) ToString(
        /* [in] */ T* a,
        /* [in] */ const String& nullString);

    template<typename T>
    static CARAPI_(String) ToString(
        /* [in] */ const AutoPtr<T>& a,
        /* [in] */ const String& nullString);

private:
    Objects();
    Objects(const Objects&);
};

//=============================================================

template<typename T>
Int32 Objects::Compare(
    /* [in] */ T* a,
    /* [in] */ T* b,
    /* [in] */ IComparator* c)
{
    assert(c != NULL);
    return c->Compare(TO_IINTERFACE(a), TO_IINTERFACE(b));
}

template<typename T>
Int32 Objects::Compare(
    /* [in] */ const AutoPtr<T>& a,
    /* [in] */ const AutoPtr<T>& b,
    /* [in] */ IComparator* c)
{
    return Objects::Compare(a.Get(), b.Get(), c);
}

template<typename T>
Boolean Objects::DeepEquals(
    /* [in] */ T* a,
    /* [in] */ T* b)
{
    if (a == NULL || b == NULL) {
        return a == b;
    }

    Boolean result = FALSE;
    if (IArrayOf::Probe(a) != NULL && IArrayOf::Probe(b) != NULL) {
        a->DeepEquals(IArrayOf::Probe(b), &result);
        return result;
    }

    return Object::Equals(a, b);
}

template<typename T>
Boolean Objects::DeepEquals(
    /* [in] */ const AutoPtr<T>& a,
    /* [in] */ const AutoPtr<T>& b)
{
    return Objects::DeepEquals(a.Get(), b.Get());
}

template<typename T>
Boolean Objects::Equals(
    /* [in] */ T* a,
    /* [in] */ T* b)
{
    return a == NULL ? b == NULL : Object::Equals(a, b);
}

template<typename T>
Boolean Objects::Equals(
    /* [in] */ const AutoPtr<T>& a,
    /* [in] */ const AutoPtr<T>& b)
{
    return Objects::Equals(a.Get(), b.Get());
}

template<typename T>
Int32 Objects::GetHashCode(
    /* [in] */ T* a)
{
    return (a == NULL) ? 0 : Object::GetHashCode(a);
}

template<typename T>
Int32 Objects::GetHashCode(
    /* [in] */ const AutoPtr<T>& a)
{
    return Objects::GetHashCode(a.Get());
}

template<typename T>
ECode Objects::RequireNonNull(
    /* [in] */ T* a)
{
    if (a == NULL) {
        return E_NULL_POINTER_EXCEPTION;
    }
    return NOERROR;
}

template<typename T>
ECode Objects::RequireNonNull(
    /* [in] */ const AutoPtr<T>& a)
{
    return Objects::RequireNonNull(a.Get());
}

template<typename T>
String Objects::ToString(
    /* [in] */ T* a)
{
    return (a == NULL) ? String("NULL") : Object::ToString(a);
}

template<typename T>
String Objects::ToString(
    /* [in] */ const AutoPtr<T>& a)
{
    return Objects::ToString(a.Get());
}

template<typename T>
String Objects::ToString(
    /* [in] */ T* a,
    /* [in] */ const String& nullString)
{
    return (a == NULL) ? nullString : Object::ToString(a);
}

template<typename T>
String Objects::ToString(
    /* [in] */ const AutoPtr<T>& a,
    /* [in] */ const String& nullString)
{
    return Objects::ToString(a.Get(), nullString);
}


} // namespace Utility
} // namespace Elastos

#endif //__ELASTOS_UTILITY_OBJECTS_H__
