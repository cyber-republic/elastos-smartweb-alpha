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

#ifndef __ETL_EXCEPTION_DEFINES_H__
#define __ETL_EXCEPTION_DEFINES_H__

#ifndef __EXCEPTIONS
    #define try         if (TRUE)
    #define catch(X)    if (FALSE)
    #define THROW_EXCEPTION_AGAIN
#else
    #define THROW_EXCEPTION_AGAIN throw
#endif

#endif //__ETL_EXCEPTION_DEFINES_H__
