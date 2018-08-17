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

#ifndef __ELASTOS_UTILITY_CONCURRENT_FUTURETASK_H__
#define __ELASTOS_UTILITY_CONCURRENT_FUTURETASK_H__

#include "Elastos.CoreLibrary.Utility.Concurrent.h"
#include "elastos/core/Thread.h"

using Elastos::Core::Runnable;
using Elastos::Core::IThread;
using Elastos::Core::Object;
using Elastos::Core::Thread;

namespace Elastos {
namespace Utility {
namespace Concurrent {

class ECO_PUBLIC FutureTask
    : public Runnable
    , public IRunnableFuture
{
public:
    CAR_INTERFACE_DECL()

    FutureTask();

    /**
     * Creates a {@code FutureTask} that will, upon running, execute the
     * given {@code Callable}.
     *
     * @param  callable the callable task
     * @throws NullPointerException if the callable is null
     */
    FutureTask(
        /* [in] */ ICallable* callable);

    /**
     * Creates a {@code FutureTask} that will, upon running, execute the
     * given {@code Runnable}, and arrange that {@code get} will return the
     * given result on successful completion.
     *
     * @param runnable the runnable task
     * @param result the result to return on successful completion. If
     * you don't need a particular result, consider using
     * constructions of the form:
     * {@code Future<?> f = new FutureTask<Void>(runnable, null)}
     * @throws NullPointerException if the runnable is null
     */
    FutureTask(
        /* [in] */ IRunnable* runnable,
        /* [in] */ IInterface* result);

    virtual ~FutureTask();

    CARAPI constructor(
        /* [in] */ ICallable* callable);

    CARAPI constructor(
        /* [in] */ IRunnable* runnable,
        /* [in] */ IInterface* result);

    virtual CARAPI IsCancelled(
        /* [out] */ Boolean* isCancelled);

    virtual CARAPI IsDone(
        /* [out] */ Boolean* isDone);

    virtual CARAPI Cancel(
        /* [in] */ Boolean mayInterruptIfRunning,
        /* [out] */ Boolean* result);

    virtual CARAPI Get(
        /* [out] */ IInterface** result);

    virtual CARAPI Get(
        /* [in] */ Int64 timeout,
        /* [in] */ ITimeUnit* unit,
        /* [out] */ IInterface** result);

    virtual CARAPI Run();


    /**
     * Sets the result of this future to the given value unless
     * this future has already been set or has been cancelled.
     *
     * <p>This method is invoked internally by the {@link #run} method
     * upon successful completion of the computation.
     *
     * @param v the value
     */
    virtual CARAPI_(void) Set(
        /* [in] */ IInterface* v);

    /**
     * Causes this future to report an {@link ExecutionException}
     * with the given throwable as its cause, unless this future has
     * already been set or has been cancelled.
     *
     * <p>This method is invoked internally by the {@link #run} method
     * upon failure of the computation.
     *
     * @param t the cause of failure
     */
    virtual CARAPI_(void) SetException(
        /* [in] */ ECode ec);

    /**
     * Protected method invoked when this task transitions to state
     * {@code isDone} (whether normally or via cancellation). The
     * default implementation does nothing.  Subclasses may override
     * this method to invoke completion callbacks or perform
     * bookkeeping. Note that you can query status inside the
     * implementation of this method to determine whether this task
     * has been cancelled.
     */
    virtual CARAPI_(void) Done();

    /**
     * Executes the computation without setting its result, and then
     * resets this future to initial state, failing to do so if the
     * computation encounters an exception or is cancelled.  This is
     * designed for use with tasks that intrinsically execute more
     * than once.
     *
     * @return true if successfully run and reset
     */
    virtual CARAPI_(Boolean) RunAndReset();

private:
    /**
     * Simple linked list nodes to record waiting threads in a Treiber
     * stack.  See other classes such as Phaser and SynchronousQueue
     * for more detailed explanation.
     */
    class ECO_LOCAL WaitNode
        : public Object
    {
    public:
        WaitNode()
        {
            mThread = Thread::GetCurrentThread();
        }

    public:
        AutoPtr<IThread> mThread;
        AutoPtr<IInterface> mNext;
    };

private:
    /**
     * Returns result or throws exception for completed task.
     *
     * @param s completed state value
     */
    ECO_LOCAL CARAPI Report(
        /* [in] */ Int32 s,
        /* [out] */ IInterface** result);

    /**
     * Ensures that any interrupt from a possible cancel(true) is only
     * delivered to a task while in run or runAndReset.
     */
    ECO_LOCAL CARAPI_(void) HandlePossibleCancellationInterrupt(
        /* [in] */ Int32 s);

    /**
     * Removes and signals all waiting threads, invokes done(), and
     * nulls out callable.
     */
    ECO_LOCAL CARAPI_(void) FinishCompletion();

    /**
     * Awaits completion or aborts on interrupt or timeout.
     *
     * @param timed true if use timed waits
     * @param nanos time to wait, if timed
     * @return state upon completion
     */
    ECO_LOCAL CARAPI AwaitDone(
        /* [in] */ Boolean timed,
        /* [in] */ Int64 nanos,
        /* [out] */ Int32* state);

    /**
     * Tries to unlink a timed-out or interrupted wait node to avoid
     * accumulating garbage.  Internal nodes are simply unspliced
     * without CAS since it is harmless if they are traversed anyway
     * by releasers.  To avoid effects of unsplicing from already
     * removed nodes, the list is retraversed in case of an apparent
     * race.  This is slow when there are a lot of nodes, but we don't
     * expect lists to be long enough to outweigh higher-overhead
     * schemes.
     */
    ECO_LOCAL CARAPI_(void) RemoveWaiter(
        /* [in] */ WaitNode* node);

private:
    /*
     * Revision notes: This differs from previous versions of this
     * class that relied on AbstractQueuedSynchronizer, mainly to
     * avoid surprising users about retaining interrupt status during
     * cancellation races. Sync control in the current design relies
     * on a "state" field updated via CAS to track completion, along
     * with a simple Treiber stack to hold waiting threads.
     *
     * Style note: As usual, we bypass overhead of using
     * AtomicXFieldUpdaters and instead directly use Unsafe intrinsics.
     */

    /**
     * The run state of this task, initially NEW.  The run state
     * transitions to a terminal state only in methods set,
     * setException, and cancel.  During completion, state may take on
     * transient values of COMPLETING (while outcome is being set) or
     * INTERRUPTING (only while interrupting the runner to satisfy a
     * cancel(true)). Transitions from these intermediate to final
     * states use cheaper ordered/lazy writes because values are unique
     * and cannot be further modified.
     *
     * Possible state transitions:
     * NEW -> COMPLETING -> NORMAL
     * NEW -> COMPLETING -> EXCEPTIONAL
     * NEW -> CANCELLED
     * NEW -> INTERRUPTING -> INTERRUPTED
     */
    Int32 mState;
    ECO_LOCAL static const Int32 NEW;
    ECO_LOCAL static const Int32 COMPLETING;
    ECO_LOCAL static const Int32 NORMAL;
    ECO_LOCAL static const Int32 EXCEPTIONAL;
    ECO_LOCAL static const Int32 CANCELLED;
    ECO_LOCAL static const Int32 INTERRUPTING;
    ECO_LOCAL static const Int32 INTERRUPTED;

    /** The underlying callable; nulled out after running */
    AutoPtr<ICallable> mCallable;
    /** The result to return or exception to throw from get() */
    AutoPtr<IInterface> mOutcome; // non-volatile, protected by state reads/writes
    /** The thread running the callable; CASed during run() */
    AutoPtr<IThread> mRunner;
    /** Treiber stack of waiting threads */
    AutoPtr<IInterface> mWaiters;
};

} // namespace Concurrent
} // namespace Utility
} // namespace Elastos

#endif //__ELASTOS_UTILITY_CONCURRENT_FUTURETASK_H__
