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

#ifndef __ELASTOS_ETL_ECONCEPTCHECK_H__
#define __ELASTOS_ETL_ECONCEPTCHECK_H__

// All places in libstdc++-v3 where these are used, or /might/ be used, or
// don't need to be used, or perhaps /should/ be used, are commented with
// "concept requirements" (and maybe some more text).  So grep like crazy
// if you're looking for additional places to use these.

// Concept-checking code is off by default unless users turn it on via
// configure options or editing c++config.h.

#include "elastos/utility/etl/etl_def.h"
#include "elastos/utility/etl/etl_concept_check.h"

// Note that the obvious and elegant approach of
//
//#define glibcpp_function_requires(C) boost::function_requires< boost::C >()
//
// won't work due to concept templates with more than one parameter, e.g.,
// BinaryPredicateConcept.  The preprocessor tries to split things up on
// the commas in the template argument list.  We can't use an inner pair of
// parenthesis to hide the commas, because "boost::(Temp<Foo,Bar>)" isn't
// a valid instantiation pattern.  Thus, we steal a feature from C99.

#define Concept_FunctionRequires(...)                                 \
            _ETL __function_requires<_ETL __VA_ARGS__>();
#define Concept_ClassRequires(a,C)                                  \
            _ELASTOS_CLASS_REQUIRES(a, _ETL_NO_COLON, C);
#define Concept_ClassRequires2(a,b,C)                              \
            _ELASTOS_CLASS_REQUIRES2(a, b, _ETL_NO_COLON, C);
#define Concept_ClassRequires3(a,b,c,C)                           \
            _ELASTOS_CLASS_REQUIRES3(a, b, c, _ETL_NO_COLON, C);
#define Concept_ClassRequires4(a,b,c,d,C)                        \
            _ELASTOS_CLASS_REQUIRES4(a, b, c, d, _ETL_NO_COLON, C);


#endif //__ELASTOS_ETL_ECONCEPTCHECK_H__
