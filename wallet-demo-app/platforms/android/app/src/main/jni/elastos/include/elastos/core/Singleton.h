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

#ifndef __ELASTOS_CORE_SINGLETON_H__
#define __ELASTOS_CORE_SINGLETON_H__

#include "elastos/core/Object.h"
#include "elspinlock.h"

namespace Elastos {
namespace Core {

class ECO_PUBLIC Singleton : public Object
{
public:
    Singleton();

    virtual ~Singleton();

    CARAPI_(UInt32) AddRef();

    CARAPI_(UInt32) Release();

    virtual CARAPI_(void) OnLastStrongRef(
        /* [in] */ const void* id) = 0;

protected:
    virtual CARAPI_(SpinLock&) GetSelfSpinLock() = 0;
};

} // namespace Core
} // namespace Elastos


using Elastos::Core::Singleton;


#endif //__ELASTOS_CORE_SINGLETON_H__
