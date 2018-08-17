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

#ifndef __ELASTOS_CORE_HASH_H__
#define __ELASTOS_CORE_HASH_H__

#include "elastos/core/Object.h"

//
// Elastos.Core
//
#ifdef HASH_FOR_CORE
#include <Elastos.CoreLibrary.Core.h>
DEFINE_OBJECT_HASH_FUNC_FOR(Elastos::Core::IInteger32)
#endif

//
// Elastos.Text
//
#ifdef HASH_FOR_TEXT
#include <Elastos.CoreLibrary.Text.h>
DEFINE_OBJECT_HASH_FUNC_FOR(Elastos::Text::IAttributedCharacterIteratorAttribute)
#endif

//
// Elastos.Utility
//
#ifdef HASH_FOR_UTILITY
#include <Elastos.CoreLibrary.Utility.h>
DEFINE_OBJECT_HASH_FUNC_FOR(Elastos::Utility::ILocale)
#endif

#endif // __ELASTOS_CORE_HASH_H__
