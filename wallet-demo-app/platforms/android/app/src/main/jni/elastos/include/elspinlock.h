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

#ifndef __ELASTOS_ELSPINLOCK_H__
#define __ELASTOS_ELSPINLOCK_H__

#include <elatypes.h>
#include <elaatomics.h>
#include <unistd.h>

_ELASTOS_NAMESPACE_BEGIN

class SpinLock
{
public:
    SpinLock() : mLocked(FALSE) {}

    void Lock();

    void Unlock();

    Boolean TryLock();

private:
    Int32 mLocked;
};

CAR_INLINE void SpinLock::Lock()
{
    while (atomic_swap(TRUE, &mLocked)) {
        while (mLocked) usleep(1);
    }
}

CAR_INLINE void SpinLock::Unlock()
{
    atomic_swap(FALSE, &mLocked);
}

CAR_INLINE _ELASTOS Boolean SpinLock::TryLock()
{
    return !atomic_swap(TRUE, &mLocked);
}

_ELASTOS_NAMESPACE_END

#endif //__ELASTOS_ELSPINLOCK_H__
