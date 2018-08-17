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

#ifndef __ELASTOS_UTILITY_STRINGPOOL_H__
#define __ELASTOS_UTILITY_STRINGPOOL_H__

#include "Elastos.CoreLibrary.h"
#include "elastos/core/Object.h"

using Elastos::Core::Object;

namespace Elastos {
namespace Utility {

/**
 * A pool of string instances. Unlike the {@link String#intern() VM's
 * interned strings}, this pool provides no guarantee of reference equality.
 * It is intended only to save allocations. This class is not thread safe.
 */
class ECO_PUBLIC StringPool
    : public Object
{
public:
    StringPool();

    /**
     * Returns a string equal to {@code new String(array, start, length)}.
     */
    CARAPI_(String) Get(
        /* [in] */ ArrayOf<Char32>* array,
        /* [in] */ Int32 start,
        /* [in] */ Int32 length);

private:
    static CARAPI_(Boolean) ContentEquals(
        /* [in] */ const String& s,
        /* [in] */ ArrayOf<Char32>* chars,
        /* [in] */ Int32 start,
        /* [in] */ Int32 length);

private:
    AutoPtr<ArrayOf<String> > mPool;// new String[512];
};

} // namespace Utility
} // namespace Elastos

#endif //__ELASTOS_UTILITY_STRINGPOOL_H__