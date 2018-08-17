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

#ifndef __ELASTOS_CORE_AUTOLOCK_H__
#define __ELASTOS_CORE_AUTOLOCK_H__

#include "elastos/core/Object.h"

using Elastos::Core::EIID_ISynchronize;

namespace Elastos {
namespace Core {

class AutoLock
{
public:
    AutoLock(
        /* [in] */ ISynchronize * obj)
        : mLocked(TRUE)
    {
        assert(obj != NULL);
        mSyncObj = obj;
        ASSERT_SUCCEEDED(mSyncObj->Lock());
    }

    AutoLock(
        /* [in] */ IInterface * obj)
        : mLocked(TRUE)
    {
        assert(obj != NULL);
        mSyncObj = (ISynchronize *)obj->Probe(EIID_ISynchronize);
        assert(mSyncObj != NULL);
        ASSERT_SUCCEEDED(mSyncObj->Lock());
    }

    AutoLock(
        /* [in] */ IObject * obj)
        : mLocked(TRUE)
    {
        assert(obj != NULL);
        mSyncObj = (ISynchronize *)obj->Probe(EIID_ISynchronize);
        assert(mSyncObj != NULL);
        ASSERT_SUCCEEDED(mSyncObj->Lock());
    }

    AutoLock(
        /* [in] */ Object * obj)
        : mLocked(TRUE)
    {
        mSyncObj = (ISynchronize *)obj->Probe(EIID_ISynchronize);
        assert(mSyncObj != NULL);
        ASSERT_SUCCEEDED(mSyncObj->Lock());
    }

    AutoLock(
        /* [in] */ Object & obj)
        : mLocked(TRUE)
    {
        mSyncObj = (ISynchronize *)obj.Probe(EIID_ISynchronize);
        assert(mSyncObj != NULL);
        ASSERT_SUCCEEDED(mSyncObj->Lock());
    }

    ~AutoLock()
    {
        assert(mSyncObj != NULL);
        ASSERT_SUCCEEDED(mSyncObj->Unlock());
    }

    // report the state of locking when used as a boolean
    inline operator Boolean () const
    {
        return mLocked;
    }

    // unlock
    inline void SetUnlock()
    {
        mLocked = FALSE;
    }

private:
    AutoLock(const AutoLock&);

private:
    ISynchronize* mSyncObj;
    Boolean mLocked;
};

} // namespace Core
} // namespace Elastos

using Elastos::Core::AutoLock;

#endif //__ELASTOS_CORE_AUTOLOCK_H__
