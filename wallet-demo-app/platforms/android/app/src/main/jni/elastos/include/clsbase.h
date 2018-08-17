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

#ifndef __CLSBASE_H__
#define __CLSBASE_H__

#include <stdint.h>
#include <elatypes.h>
#include <string.h>
#include <clsdef.h>

#if defined(_arm) && defined(__GNUC__) && (__GNUC__ >= 4) || defined(_MSVC)
#define ALIGN_BOUND 8
#else
#ifdef _ELASTOS64
    #define ALIGN_BOUND 8
#else
    #define ALIGN_BOUND 4
#endif
#endif

inline int RoundUp4(int n)
{
    return ((n) + 4 - 1) & ~(4 - 1);
}

inline int RoundUp8(int n)
{
    return ((n) + 8 - 1) & ~(8 - 1);
}

#ifdef _ELASTOS64
    // round up to multiple of 8 bytes
    #define DST_ROUNDUP(n)     (((n) + 8 - 1) & ~(8 - 1))
#else
    // round up to multiple of 4 bytes
    #define DST_ROUNDUP(n)     (((n) + 4 - 1) & ~(4 - 1))
#endif

extern int sCLSErrorNumber;
extern char sCLSErrorName[];
extern char sCLSErrorMessage[];

#define _Return(ret) return ret

#define _ReturnOK(ret)                  \
{                                       \
    sCLSErrorNumber = CLS_NoError;      \
    return ret;                         \
}

#define _ReturnError(err)                   \
{                                           \
    sCLSErrorNumber = err;                  \
    strcpy(sCLSErrorName, #err);           \
    return err;                             \
}

extern void ExtraMessage(
    /* [in] */ const char*,
    /* [in] */ const char* s2 = NULL,
    /* [in] */ const char* s3 = NULL,
    /* [in] */ const char* s4 = NULL);

#endif // __CLSBASE_H__
