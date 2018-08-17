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

#ifndef __ELASTOS_ASM_H__
#define __ELASTOS_ASM_H__

#if defined(_mips) || (__GNUC__ >= 4)
#define C_SYMBOL(symbol)    symbol
#define C_PREFIX
#else
#define C_SYMBOL(symbol)    _##symbol
#define C_PREFIX            "_"
#endif

#define CODEINIT    .text.init
#define DATAINIT    .data.init

#endif //__ELASTOS_ASM_H__
