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

#ifndef __ELASTOS_CORE_NATIVETHREAD_H__
#define __ELASTOS_CORE_NATIVETHREAD_H__

#include "Elastos.CoreLibrary.h"
#include <pthread.h>

namespace Elastos {
namespace Core {

typedef struct NativeObject
{
    /*
     * A word containing either a "thin" lock or a "fat" monitor.  See
     * the comments in Sync.c for a description of its layout.
     */
    size_t      mLock;
    Int64       mObjectObj;
} NativeObject;

struct Monitor;

/*
 * Current status; these map to JDWP constants, so don't rearrange them.
 * (If you do alter this, update the strings in dvmDumpThread and the
 * conversion table in VMThread.java.)
 *
 * Note that "suspended" is orthogonal to these values (so says JDWP).
 */
typedef enum NativeThreadStatus
{
    NTHREAD_UNDEFINED    = -1,       /* makes enum compatible with int32_t */

    /* these match up with JDWP values */
    NTHREAD_ZOMBIE       = 0,        /* TERMINATED */
    NTHREAD_RUNNING      = 1,        /* RUNNABLE or running now */
    NTHREAD_TIMED_WAIT   = 2,        /* TIMED_WAITING in Object.wait() */
    NTHREAD_MONITOR      = 3,        /* BLOCKED on a monitor */
    NTHREAD_WAIT         = 4,        /* WAITING in Object.wait() */
    /* non-JDWP states */
    NTHREAD_INITIALIZING = 5,        /* allocated, not yet running */
    NTHREAD_STARTING     = 6,        /* started, not yet on thread list */
    NTHREAD_NATIVE       = 7,        /* off in a JNI native method */
    NTHREAD_VMWAIT       = 8,        /* waiting on a VM resource */
    NTHREAD_SUSPENDED    = 9,        /* suspended, usually by GC or debugger */
} NativeThreadStatus;

/* thread priorities, from java.lang.Thread */
enum {
   NTHREAD_MIN_PRIORITY     = 1,
   NTHREAD_NORM_PRIORITY    = 5,
   NTHREAD_MAX_PRIORITY     = 10,
};

/* reserve this many bytes for handling StackOverflowError */
#define STACK_OVERFLOW_RESERVE  768

#define kMinStackSize       (512 + STACK_OVERFLOW_RESERVE)
#define kDefaultStackSize   (256 * 1024)   /*adjust to 256k, the last 4k maybe as guard buffer[android:three 4K pages] */
#define kMaxStackSize       (512 * 1024 + STACK_OVERFLOW_RESERVE)

#define kMaxThreadId        ((1 << 16) - 1)
#define kMainThreadId       1

/*
 * Initialize a Lock to the proper starting value.
 * This is necessary for thin locking.
 */
#define NATIVE_LOCK_INITIAL_THIN_VALUE (0)
#define NATIVE_LOCK_INIT(lock) \
    do { *(lock) = NATIVE_LOCK_INITIAL_THIN_VALUE; } while (0)

struct NativeAttachArgs
{
    Int32        mVersion;    /* must be >= JNI_VERSION_1_2 */
    String       mName;       /* NULL or name of thread as modified UTF-8 str */
    Int64        mGroup;      /* global ref of a ThreadGroup object, or NULL */
};
typedef struct NativeAttachArgs NativeAttachArgs;

/*
 * Our per-thread data.
 *
 * These are allocated on the system heap.
 */
typedef struct NativeThread
{
    /* small unique integer; useful for "thin" locks and debug messages */
    UInt32 mThreadId;

    /*
     * Thread's current status.  Can only be changed by the thread itself
     * (i.e. don't mess with this from other threads).
     */
    volatile NativeThreadStatus mStatus;

    /*
     * This is the number of times the thread has been suspended.  When the
     * count drops to zero, the thread resumes.
     *
     * "dbgSuspendCount" is the portion of the suspend count that the
     * debugger is responsible for.  This has to be tracked separately so
     * that we can recover correctly if the debugger abruptly disconnects
     * (suspendCount -= dbgSuspendCount).  The debugger should not be able
     * to resume GC-suspended threads, because we ignore the debugger while
     * a GC is in progress.
     *
     * Both of these are guarded by gDvm.threadSuspendCountLock.
     *
     * (We could store both of these in the same 32-bit, using 16-bit
     * halves, to make atomic ops possible.  In practice, you only need
     * to read suspendCount, and we need to hold a mutex when making
     * changes, so there's no need to merge them.  Note the non-debug
     * component will rarely be other than 1 or 0 -- not sure it's even
     * possible with the way mutexes are currently used.)
     */
    Int32 mSuspendCount;
    // int         dbgSuspendCount;

    /* thread handle, as reported by pthread_self() */
    pthread_t mHandle;

    /* thread ID, only useful under Linux */
    pid_t mSystemTid;

    /* start (high addr) of interp stack (subtract size to get malloc addr) */
    // u1*         interpStackStart;

    /* current limit of stack; flexes for StackOverflowError */
    // const u1*   interpStackEnd;

    /* interpreter stack size; our stacks are fixed-length */
    Int32 mStackSize;
    // bool        stackOverflowed;

    /* FP of bottom-most (currently executing) stack frame on interp stack */
    // void*       curFrame;

    /* current exception, or NULL if nothing pending */
    // Object*     exception;

    /* the java/lang/Thread that we are associated with */
    Int64 mThreadObj;

    /* the JNIEnv pointer associated with this thread */
    // JNIEnv*     jniEnv;

    /* internal reference tracking */
    // ReferenceTable  internalLocalRefTable;

// #if defined(WITH_JIT)
    /*
     * Whether the current top VM frame is in the interpreter or JIT cache:
     *   NULL    : in the interpreter
     *   non-NULL: entry address of the JIT'ed code (the actual value doesn't
     *             matter)
     */
//     void*       inJitCodeCache;
// #if defined(WITH_SELF_VERIFICATION)
    /* Buffer for register state during self verification */
//     struct ShadowSpace* shadowSpace;
// #endif
// #endif

    /* JNI local reference tracking */
// #ifdef USE_INDIRECT_REF
//     IndirectRefTable jniLocalRefTable;
// #else
//     ReferenceTable  jniLocalRefTable;
// #endif

    /* JNI native monitor reference tracking (initialized on first use) */
    // ReferenceTable  jniMonitorRefTable;

    /* hack to make JNI_OnLoad work right */
    // Object*     classLoaderOverride;

    /* mutex to guard the interrupted and the waitMonitor members */
    pthread_mutex_t mWaitMutex;

    /* pointer to the monitor lock we're currently waiting on */
    /* guarded by waitMutex */
    /* TODO: consider changing this to Object* for better JDWP interaction */
    struct Monitor* mWaitMonitor;

    /* thread "interrupted" status; stays raised until queried or thrown */
    /* guarded by waitMutex */
    Boolean mInterrupted;

    /* links to the next thread in the wait set this thread is part of */
    struct NativeThread* mWaitNext;

    /* object to sleep on while we are waiting for a monitor */
    pthread_cond_t mWaitCond;

    /*
     * Set to true when the thread is in the process of throwing an
     * OutOfMemoryError.
     */
    // bool        throwingOOME;

    /* links to rest of thread list; grab global lock before traversing */
    struct NativeThread* mPrev;
    struct NativeThread* mNext;

    /* used by threadExitCheck when a thread exits without detaching */
    Int32         mThreadExitCheckCount;

    /* JDWP invoke-during-breakpoint support */
    // DebugInvokeReq  invokeReq;

// #ifdef WITH_MONITOR_TRACKING
    /* objects locked by this thread; most recent is at head of list */
    // struct LockedObjectData* pLockedObjects;
// #endif

#ifdef WITH_ALLOC_LIMITS
    /* allocation limit, for Debug.setAllocationLimit() regression testing */
    Int32 mAllocLimit;
#endif

    /* base time for per-thread CPU timing (used by method profiling) */
    Boolean mCpuClockBaseSet;
    UInt64 mCpuClockBase;

    /* memory allocation profiling state */
    // AllocProfState allocProf;

// #ifdef WITH_JNI_STACK_CHECK
    // u4          stackCrc;
// #endif

// #if WITH_EXTRA_GC_CHECKS > 1
    /* PC, saved on every instruction; redundant with StackSaveArea */
    // const u2*   currentPc2;
// #endif
} NativeThread;

/* start point for an internal thread; mimics pthread args */
typedef void* (*InternalThreadStartFunc)(void* arg);

/* args for internal thread creation */
struct InternalStartArgs
{
    /* inputs */
    InternalThreadStartFunc mFunc;
    void* mFuncArg;
    char* mName;
    Int32 mGroup;
    Boolean mIsDaemon;
    /* result */
    volatile NativeThread** mThread;
    volatile Int32* mCreateStatus;
};

/* utility function to get the tid */
ELAPI_(pid_t) NativeGetSysThreadId();

/*
 * Finish preparing the main thread, allocating some objects to represent
 * it.  As part of doing so, we finish initializing Thread and ThreadGroup.
 * This will execute some interpreted code (e.g. class initializers).
 */
ELAPI_(Boolean) NativePrepMainThread();

/*
 * Get our Thread* from TLS.
 *
 * Returns NULL if this isn't a thread that the VM is aware of.
 */
ELAPI_(NativeThread*) NativeThreadSelf();

/*
 * Initialize thread list and main thread's environment.  We need to set
 * up some basic stuff so that dvmThreadSelf() will work when we start
 * loading classes (e.g. to check for exceptions).
 */
ELAPI_(Boolean) NativeThreadStartup();

/* grab the thread list global lock */
ELAPI_(void) NativeLockThreadList(
    /* [in] */ NativeThread* self);

/* release the thread list global lock */
ELAPI_(void) NativeUnlockThreadList();

/*
 * Used when changing thread state.  Threads may only change their own.
 * The "self" argument, which may be NULL, is accepted as an optimization.
 *
 * If you're calling this before waiting on a resource (e.g. THREAD_WAIT
 * or THREAD_MONITOR), do so in the same function as the wait -- this records
 * the current stack depth for the GC.
 *
 * If you're changing to THREAD_RUNNING, this will check for suspension.
 *
 * Returns the old status.
 */
ELAPI_(NativeThreadStatus) NativeChangeStatus(
    /* [in] */ NativeThread* self,
    /* [in] */ NativeThreadStatus newStatus);

/*
 * Initialize a mutex.
 */
inline void NativeInitMutex(
    /* [in] */ pthread_mutex_t* mutex)
{
#ifdef CHECK_MUTEX
    pthread_mutexattr_t attr;
    int cc;

    pthread_mutexattr_init(&attr);
    cc = pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK_NP);
    assert(cc == 0);
    pthread_mutex_init(mutex, &attr);
    pthread_mutexattr_destroy(&attr);
#else
    pthread_mutex_init(mutex, NULL);       // default=PTHREAD_MUTEX_FAST_NP
#endif
}

/*
 * Grab a plain mutex.
 */
inline void NativeLockMutex(
    /* [in] */ pthread_mutex_t* mutex)
{
    Int32 cc __attribute__ ((__unused__)) = pthread_mutex_lock(mutex);
    assert(cc == 0);
}

/*
 * Try grabbing a plain mutex.  Returns 0 if successful.
 */
inline Int32 NativeTryLockMutex(
    /* [in] */ pthread_mutex_t* mutex)
{
    Int32 cc = pthread_mutex_trylock(mutex);
    assert(cc == 0 || cc == 16/*EBUSY*/);
    return cc;
}

/*
 * Unlock pthread mutex.
 */
inline void NativeUnlockMutex(
    /* [in] */ pthread_mutex_t* mutex)
{
    Int32 cc __attribute__ ((__unused__)) = pthread_mutex_unlock(mutex);
    assert(cc == 0);
}

/*
 * Create a thread as a result of java.lang.Thread.start().
 */
ELAPI_(Boolean) NativeCreateThread(
    /* [in] */ Int64 threadObj,
    /* [in] */ Int32 reqStackSize);

/*
 * Create an internal VM thread, for things like JDWP and finalizers.
 *
 * The easiest way to do this is create a new thread and then use the
 * JNI AttachCurrentThread implementation.
 *
 * This does not return until after the new thread has begun executing.
 */
ELAPI_(Boolean) NativeCreateInternalThread(
    /* [in] */ pthread_t* handle,
    /* [in] */ const char* name,
    /* [in] */ InternalThreadStartFunc func,
    /* [in] */ void* funcArg);

ELAPI NativeAttachCurrentThread(
    /* [in] */ const NativeAttachArgs* args,
    /* [in] */ Boolean isDaemon,
    /* [out] */ IThread** thread);

ELAPI_(void) NativeDetachCurrentThread();

/*
 * Get the "main" or "system" thread group.
 */
AutoPtr<IThreadGroup> NativeGetMainThreadGroup();
AutoPtr<IThreadGroup> NativeGetSystemThreadGroup();

/*
 * Given a VMThread object, return the associated Thread*.
 *
 * NOTE: if the thread detaches, the struct Thread will disappear, and
 * we will be touching invalid data.  For safety, lock the thread list
 * before calling this.
 */
ELAPI_(NativeThread*) NativeGetThreadFromThreadObject(
    /* [in] */ Int64 threadObj);

/*
 * Update the priority value of the underlying pthread.
 */
ELAPI_(void) NativeChangeThreadPriority(
    /* [in] */ NativeThread* thread,
    /* [in] */ Int32 newPriority);

ELAPI_(Int32) NativeGetCount();

/*
 * Implements monitorenter for "synchronized" stuff.
 *
 * This does not fail or throw an exception (unless deadlock prediction
 * is enabled and set to "err" mode).
 */
ELAPI NativeLockObject(
    /* [in] */ NativeObject *obj);

/*
 * Implements monitorexit for "synchronized" stuff.
 *
 * On failure, throws an exception and returns "false".
 */
ELAPI NativeUnlockObject(
    /* [in] */ NativeObject *obj);

/*
 * Object.wait().  Also called for class init.
 */
ELAPI NativeObjectWait(
    /* [in] */ NativeObject* obj,
    /* [in] */ Int64 msec,
    /* [in] */ Int32 nsec,
    /* [in] */ Boolean interruptShouldThrow);

/*
 * Object.notify().
 */
ELAPI NativeObjectNotify(
    /* [in] */ NativeObject *obj);

/*
 * Object.notifyAll().
 */
ELAPI NativeObjectNotifyAll(
    /* [in] */ NativeObject *obj);

/*
 * Implement java.lang.Thread.interrupt().
 */
ELAPI_(void) NativeThreadInterrupt(
    /* [in] */ NativeThread* thread);

/*
 * This implements java.lang.Thread.sleep(long msec, int nsec).
 *
 * The sleep is interruptible by other threads, which means we can't just
 * plop into an OS sleep call.  (We probably could if we wanted to send
 * signals around and rely on EINTR, but that's inefficient and relies
 * on native code respecting our signal mask.)
 *
 * We have to do all of this stuff for Object.wait() as well, so it's
 * easiest to just sleep on a private Monitor.
 *
 * It appears that we want sleep(0,0) to go through the motions of sleeping
 * for a very short duration, rather than just returning.
 */
ELAPI NativeThreadSleep(
    /* [in] */ Int64 msec,
    /* [in] */ Int32 nsec);

} // namespace Core
} // namespace Elastos

#endif //__ELASTOS_CORE_NATIVETHREAD_H__
