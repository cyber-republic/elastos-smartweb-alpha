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

#ifndef __ETL_BLOCKINGQUEUE_H__
#define __ETL_BLOCKINGQUEUE_H__

#include "elastos/utility/etl/etl_queue.h"
#include <pthread.h>

_ETL_NAMESPACE_BEGIN

template <class Tp,
          class Sequence = Deque<Tp> >
class BlockingQueue;

template <class Tp, class Seq>
inline Boolean operator==(const BlockingQueue<Tp, Seq>&, const BlockingQueue<Tp, Seq>&);

template <class Tp, class Seq>
inline Boolean operator<(const BlockingQueue<Tp, Seq>&, const BlockingQueue<Tp, Seq>&);

template <class Tp, class Sequence>
class BlockingQueue : public ElLightRefBase
{

private:
    pthread_mutex_t mWaitMutex;
    pthread_cond_t mWaitCond;
};

_ETL_NAMESPACE_END

#endif //__ETL_BLOCKINGQUEUE_H__
