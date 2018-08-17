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

#ifndef __STD_EFUNCTEXCEPT_H__
#define __STD_EFUNCTEXCEPT_H__

#include "elastos/utility/etl/etl_exception_defines.h"
#include <stdlib.h>

#ifdef _GUNC

namespace std
{
    // Helper for exception objects in <except>
    void __throw_bad_exception(void);
#define THROW_BAD_EXCEPTION() __throw_bad_exception()

    // Helper for exception objects in <new>
    void __throw_bad_alloc(void);
#define THROW_BAD_ALLOC() __throw_bad_alloc()

    // Helper for exception objects in <typeinfo>
    void __throw_bad_cast(void);
#define THROW_BAD_CAST() __throw_bad_cast()

    void __throw_bad_typeid(void);
#define THROW_BAD_TYPEID() __throw_bad_typeid()

    // Helpers for exception objects in <stdexcept>
    void __throw_logic_error(const char* s);
#define THROW_LOGIC_ERROR(s) __throw_logic_error(s)

    void __throw_domain_error(const char* s);
#define THROW_DOMAIN_ERROR(s) __throw_domain_error(s)

    void __throw_invalid_argument(const char* s);
#define THROW_INVALID_ARGUMENT(s) __throw_invalid_argument(s)

    void __throw_length_error(const char* s);
#define THROW_LENGTH_ERROR(s) __throw_length_error(s)

    void __throw_out_of_range(const char* s);
#define THROW_OUT_OF_RANGE(s) __throw_out_of_range(s)

    void __throw_runtime_error(const char* s);
#define THROW_RUNTIME_ERROR(s) __throw_runtime_error(s)

    void __throw_range_error(const char* s);
#define THROW_RANGE_ERROR(s) __throw_range_error(s)

    void __throw_overflow_error(const char* s);
#define THROW_OVERFLOW_ERROR(s) __throw_overflow_error(s)

    void __throw_underflow_error(const char* s);
#define THROW_UNDERFLOW_ERROR(s) __throw_underflow_error(s)

    // Helpers for exception objects in basic_ios
    void __throw_ios_failure(const char* s);
#define THROW_IOS_FAILURE(s) __throw_ios_failure(s)
} // namespace std

#else //_MSVC

#define THROW_BAD_EXCEPTION() abort()

#define THROW_BAD_ALLOC() abort()

#define THROW_BAD_CAST() abort()

#define THROW_BAD_TYPEID() abort()

#define THROW_LOGIC_ERROR(s) abort()

#define THROW_DOMAIN_ERROR(s) abort()

#define THROW_INVALID_ARGUMENT(s) abort()

#define THROW_LENGTH_ERROR(s) abort()

#define THROW_OUT_OF_RANGE(s) abort()

#define THROW_RUNTIME_ERROR(s) abort()

#define THROW_RANGE_ERROR(s) abort()

#define THROW_OVERFLOW_ERROR(s) abort()

#define THROW_UNDERFLOW_ERROR(s) abort()

#define THROW_IOS_FAILURE(s) abort()


#endif




#endif //__STD_EFUNCTEXCEPT_H__
