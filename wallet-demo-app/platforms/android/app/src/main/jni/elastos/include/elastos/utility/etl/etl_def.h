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

#ifndef __ETL_DEF_H__
#define __ETL_DEF_H__

#include <eltypes.h>

#if !defined(_PTRDIFF_T_) && !defined(_PTRDIFF_T)
#define _PTRDIFF_T_
#define _PTRDIFF_T
typedef int ptrdiff_t;
#endif

#define _ETL_NO_COLON           Elastos::Utility::Etl
#define _ETL                    Elastos::Utility::Etl::
#define _ETL_NAMESPACE_BEGIN    namespace Elastos { namespace Utility { namespace Etl {
#define _ETL_NAMESPACE_END      } } }

#endif //__ETL_DEF_H__
