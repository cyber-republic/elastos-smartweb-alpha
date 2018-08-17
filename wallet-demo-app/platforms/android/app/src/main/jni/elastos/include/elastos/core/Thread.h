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

#ifndef __ELASTOS_CORE_THREAD_H__
#define __ELASTOS_CORE_THREAD_H__

#include "elastos/core/Runnable.h"
#include "elastos/core/NativeThread.h"
#include "elastos/utility/etl/List.h"

// using Elastos::Utility::IList;
using Elastos::Core::Runnable;
using Elastos::Utility::Etl::List;

namespace Elastos {
namespace Core {

enum {
    /*
     * ***********************************************
     * ** Keep in sync with android.os.Process.java **
     * ***********************************************
     *
     * This maps directly to the "nice" priorites we use in Android.
     * A thread priority should be chosen inverse-proportinally to
     * the amount of work the thread is expected to do. The more work
     * a thread will do, the less favorable priority it should get so that
     * it doesn't starve the system. Threads not behaving properly might
     * be "punished" by the kernel.
     * Use the levels below when appropriate. Intermediate values are
     * acceptable, preferably use the {MORE|LESS}_FAVORABLE constants below.
     */
    ELASTOS_PRIORITY_LOWEST         =  19,

    /* use for background tasks */
    ELASTOS_PRIORITY_BACKGROUND     =  10,

    /* most threads run at normal priority */
    ELASTOS_PRIORITY_NORMAL         =   0,

    /* threads currently running a UI that the user is interacting with */
    ELASTOS_PRIORITY_FOREGROUND     =  -2,

    /* the main UI thread has a slightly more favorable priority */
    ELASTOS_PRIORITY_DISPLAY        =  -4,

    /* ui service treads might want to run at a urgent display (uncommon) */
    ELASTOS_PRIORITY_URGENT_DISPLAY =  -8,

    /* all normal audio threads */
    ELASTOS_PRIORITY_AUDIO          = -16,

    /* service audio threads (uncommon) */
    ELASTOS_PRIORITY_URGENT_AUDIO   = -19,

    /* should never be used in practice. regular process might not
     * be allowed to use this level */
    ELASTOS_PRIORITY_HIGHEST        = -20,

    ELASTOS_PRIORITY_DEFAULT        = ELASTOS_PRIORITY_NORMAL,
    ELASTOS_PRIORITY_MORE_FAVORABLE = -1,
    ELASTOS_PRIORITY_LESS_FAVORABLE = +1,
};

struct NativeThread;
class ThreadGroup;

class ECO_PUBLIC Thread
    : public Runnable
    , public IThread
{
private:
    /** Park states */
    class ECO_LOCAL ParkState
    {
    public:
        /** park state indicating unparked */
        static const Int32 UNPARKED = 1;

        /** park state indicating preemptively unparked */
        static const Int32 PREEMPTIVELY_UNPARKED = 2;

        /** park state indicating parked */
        static const Int32 PARKED = 3;
    };

public:
    CAR_INTERFACE_DECL()

    TO_STRING_IMPL("Thread")

    Thread();

    virtual ~Thread();

    /**
     * Constructs a new {@code Thread} with no {@code Runnable} object and a
     * newly generated name. The new {@code Thread} will belong to the same
     * {@code ThreadGroup} as the {@code Thread} calling this constructor.
     *
     * @see java.lang.ThreadGroup
     * @see java.lang.Runnable
     */
    CARAPI constructor();

    /**
     * Constructs a new {@code Thread} with a {@code Runnable} object and a
     * newly generated name. The new {@code Thread} will belong to the same
     * {@code ThreadGroup} as the {@code Thread} calling this constructor.
     *
     * @param runnable
     *            a {@code Runnable} whose method <code>run</code> will be
     *            executed by the new {@code Thread}
     *
     * @see java.lang.ThreadGroup
     * @see java.lang.Runnable
     */
    CARAPI constructor(
        /* [in] */ IRunnable* runnable);

    /**
     * Constructs a new {@code Thread} with a {@code Runnable} object and name
     * provided. The new {@code Thread} will belong to the same {@code
     * ThreadGroup} as the {@code Thread} calling this constructor.
     *
     * @param runnable
     *            a {@code Runnable} whose method <code>run</code> will be
     *            executed by the new {@code Thread}
     * @param threadName
     *            the name for the {@code Thread} being created
     *
     * @see java.lang.ThreadGroup
     * @see java.lang.Runnable
     */
    CARAPI constructor(
        /* [in] */ IRunnable* runnable,
        /* [in] */ const String& threadName);

    /**
     * Constructs a new {@code Thread} with no {@code Runnable} object and the
     * name provided. The new {@code Thread} will belong to the same {@code
     * ThreadGroup} as the {@code Thread} calling this constructor.
     *
     * @param threadName
     *            the name for the {@code Thread} being created
     *
     * @see java.lang.ThreadGroup
     * @see java.lang.Runnable
     *
     */
    CARAPI constructor(
        /* [in] */ const String& threadName);

    /**
     * Constructs a new {@code Thread} with a {@code Runnable} object and a
     * newly generated name. The new {@code Thread} will belong to the {@code
     * ThreadGroup} passed as parameter.
     *
     * @param group
     *            {@code ThreadGroup} to which the new {@code Thread} will
     *            belong
     * @param runnable
     *            a {@code Runnable} whose method <code>run</code> will be
     *            executed by the new {@code Thread}
     * @throws SecurityException
     *             if <code>group.checkAccess()</code> fails with a
     *             SecurityException
     * @throws IllegalThreadStateException
     *             if <code>group.destroy()</code> has already been done
     * @see java.lang.ThreadGroup
     * @see java.lang.Runnable
     * @see java.lang.SecurityException
     * @see java.lang.SecurityManager
     */
    CARAPI constructor(
        /* [in] */ IThreadGroup* group,
        /* [in] */ IRunnable* runnable);

    /**
     * Constructs a new {@code Thread} with a {@code Runnable} object, the given
     * name and belonging to the {@code ThreadGroup} passed as parameter.
     *
     * @param group
     *            ThreadGroup to which the new {@code Thread} will belong
     * @param runnable
     *            a {@code Runnable} whose method <code>run</code> will be
     *            executed by the new {@code Thread}
     * @param threadName
     *            the name for the {@code Thread} being created
     * @throws SecurityException
     *             if <code>group.checkAccess()</code> fails with a
     *             SecurityException
     * @throws IllegalThreadStateException
     *             if <code>group.destroy()</code> has already been done
     * @see java.lang.ThreadGroup
     * @see java.lang.Runnable
     * @see java.lang.SecurityException
     * @see java.lang.SecurityManager
     */
    CARAPI constructor(
        /* [in] */ IThreadGroup* group,
        /* [in] */ IRunnable* runnable,
        /* [in] */ const String& threadName);

    /**
     * Constructs a new {@code Thread} with no {@code Runnable} object, the
     * given name and belonging to the {@code ThreadGroup} passed as parameter.
     *
     * @param group
     *            {@code ThreadGroup} to which the new {@code Thread} will belong
     * @param threadName
     *            the name for the {@code Thread} being created
     * @throws SecurityException
     *             if <code>group.checkAccess()</code> fails with a
     *             SecurityException
     * @throws IllegalThreadStateException
     *             if <code>group.destroy()</code> has already been done
     * @see java.lang.ThreadGroup
     * @see java.lang.Runnable
     * @see java.lang.SecurityException
     * @see java.lang.SecurityManager
     */
    CARAPI constructor(
        /* [in] */ IThreadGroup* group,
        /* [in] */ const String& threadName);

    /**
     * Constructs a new {@code Thread} with a {@code Runnable} object, the given
     * name and belonging to the {@code ThreadGroup} passed as parameter.
     *
     * @param group
     *            {@code ThreadGroup} to which the new {@code Thread} will
     *            belong
     * @param runnable
     *            a {@code Runnable} whose method <code>run</code> will be
     *            executed by the new {@code Thread}
     * @param threadName
     *            the name for the {@code Thread} being created
     * @param stackSize
     *            a stack size for the new {@code Thread}. This has a highly
     *            platform-dependent interpretation. It may even be ignored
     *            completely.
     * @throws SecurityException
     *             if <code>group.checkAccess()</code> fails with a
     *             SecurityException
     * @throws IllegalThreadStateException
     *             if <code>group.destroy()</code> has already been done
     * @see java.lang.ThreadGroup
     * @see java.lang.Runnable
     * @see java.lang.SecurityException
     * @see java.lang.SecurityManager
     */
    CARAPI constructor(
        /* [in] */ IThreadGroup* group,
        /* [in] */ IRunnable* runnable,
        /* [in] */ const String& threadName,
        /* [in] */ Int64 stackSize);

    /**
     * Package-scope method invoked by Dalvik VM to create "internal"
     * threads or attach threads created externally.
     *
     * Don't call Thread.currentThread(), since there may not be such
     * a thing (e.g. for Main).
     */
    CARAPI constructor(
        /* [in] */ IThreadGroup* group,
        /* [in] */ const String& name,
        /* [in] */ Int32 priority,
        /* [in] */ Boolean daemon);

    /**
     * Returns the number of active {@code Thread}s in the running {@code
     * Thread}'s group and its subgroups.
     *
     * @return the number of {@code Thread}s
     */
    static CARAPI_(Int32) GetActiveCount();

    /**
     * Is used for operations that require approval from a SecurityManager. If
     * there's none installed, this method is a no-op. If there's a
     * SecurityManager installed, {@link SecurityManager#checkAccess(Thread)} is
     * called for that SecurityManager.
     *
     * @throws SecurityException
     *             if a SecurityManager is installed and it does not allow
     *             access to the Thread.
     *
     * @see java.lang.SecurityException
     * @see java.lang.SecurityManager
     */
    CARAPI CheckAccess();

    /**
     * Returns the number of stack frames in this thread.
     *
     * @return Number of stack frames
     * @deprecated The results of this call were never well defined. To make
     *             things worse, it would depend on whether the Thread was
     *             suspended or not, and suspend was deprecated too.
     */
    //@Deprecated
    CARAPI CountStackFrames(
        /* [out] */ Int32* number);

    /**
     * Returns the Thread of the caller, that is, the current Thread.
     *
     * @return the current Thread.
     */
    static CARAPI_(AutoPtr<IThread>) GetCurrentThread();

    /**
     * Destroys the receiver without any monitor cleanup.
     *
     * @deprecated Not implemented.
     */
    //@Deprecated
    CARAPI Destroy();

    /**
     * Prints to the standard error stream a text representation of the current
     * stack for this Thread.
     *
     * @see Throwable#printStackTrace()
     */
    static CARAPI_(void) DumpStack();

    /**
     * Copies an array with all Threads which are in the same ThreadGroup as the
     * receiver - and subgroups - into the array <code>threads</code> passed as
     * parameter. If the array passed as parameter is too small no exception is
     * thrown - the extra elements are simply not copied.
     *
     * @param threads
     *            array into which the Threads will be copied
     * @return How many Threads were copied over
     * @throws SecurityException
     *             if the installed SecurityManager fails
     *             {@link SecurityManager#checkAccess(Thread)}
     * @see java.lang.SecurityException
     * @see java.lang.SecurityManager
     */
    static CARAPI Enumerate(
        /* [out] */ ArrayOf<IThread*>* threads,
        /* [out] */ Int32* number);

    /**
     * <p>
     * Returns the stack traces of all the currently live threads and puts them
     * into the given map.
     * </p>
     *
     * @return A Map of current Threads to StackTraceElement arrays.
     * @throws SecurityException
     *             if the current SecurityManager fails the
     *             {@link SecurityManager#checkPermission(java.security.Permission)}
     *             call.
     */
//    static CARAPI_(HashMap<AutoPtr<IThread>, StackTraceElement[]>) GetAllStackTraces();

    /**
     * Returns the default exception handler that's executed when uncaught
     * exception terminates a thread.
     *
     * @return an {@link UncaughtExceptionHandler} or <code>null</code> if
     *         none exists.
     */
    static CARAPI_(AutoPtr<IThreadUncaughtExceptionHandler>) GetDefaultUncaughtExceptionHandler();

    /**
     * Returns the context ClassLoader for this Thread.
     *
     * @return ClassLoader The context ClassLoader
     * @see java.lang.ClassLoader
     * @see #getContextClassLoader()
     */
    CARAPI GetContextClassLoader(
        /* [out] */ IClassLoader** outload);

    /**
     * Returns the thread's identifier. The ID is a positive <code>long</code>
     * generated on thread creation, is unique to the thread, and doesn't change
     * during the lifetime of the thread; the ID may be reused after the thread
     * has been terminated.
     *
     * @return the thread's ID.
     */
    CARAPI GetId(
        /* [out] */ Int64* id);

    /**
     * Returns the name of the Thread.
     *
     * @return the Thread's name
     */
    CARAPI GetName(
        /* [out] */ String* name);

    /**
     * Returns the priority of the Thread.
     *
     * @return the Thread's priority
     * @see Thread#setPriority
     */
    CARAPI GetPriority(
        /* [out] */ Int32* priority);

    /**
     * Returns the a stack trace representing the current execution state of
     * this Thread.
     * <p>
     * The <code>RuntimePermission("getStackTrace")</code> is checked before
     * returning a result.
     * </p>
     *
     * @return an array of StackTraceElements.
     * @throws SecurityException
     *             if the current SecurityManager fails the
     *             {@link SecurityManager#checkPermission(java.security.Permission)}
     *             call.
     */
//        public StackTraceElement[] getStackTrace()

    /**
     * Returns the current state of the Thread. This method is useful for
     * monitoring purposes.
     *
     * @return a {@link State} value.
     */
    CARAPI GetState(
        /* [out] */ ThreadState* state);

    /**
     * Returns the ThreadGroup to which this Thread belongs.
     *
     * @return the Thread's ThreadGroup
     */
    CARAPI GetThreadGroup(
        /* [out] */ IThreadGroup** group);

    /**
     * Returns the thread's uncaught exception handler. If not explicitly set,
     * then the ThreadGroup's handler is returned. If the thread is terminated,
     * then <code>null</code> is returned.
     *
     * @return an {@link UncaughtExceptionHandler} instance or {@code null}.
     */
    CARAPI GetUncaughtExceptionHandler(
        /* [out] */ IThreadUncaughtExceptionHandler** handler);

    /**
     * Posts an interrupt request to this {@code Thread}. Unless the caller is
     * the {@link #currentThread()}, the method {@code checkAccess()} is called
     * for the installed {@code SecurityManager}, if any. This may result in a
     * {@code SecurityException} being thrown. The further behavior depends on
     * the state of this {@code Thread}:
     * <ul>
     * <li>
     * {@code Thread}s blocked in one of {@code Object}'s {@code wait()} methods
     * or one of {@code Thread}'s {@code join()} or {@code sleep()} methods will
     * be woken up, their interrupt status will be cleared, and they receive an
     * {@link InterruptedException}.
     * <li>
     * {@code Thread}s blocked in an I/O operation of an
     * {@link java.nio.channels.InterruptibleChannel} will have their interrupt
     * status set and receive an
     * {@link java.nio.channels.ClosedByInterruptException}. Also, the channel
     * will be closed.
     * <li>
     * {@code Thread}s blocked in a {@link java.nio.channels.Selector} will have
     * their interrupt status set and return immediately. They don't receive an
     * exception in this case.
     * <ul>
     *
     * @throws SecurityException
     *             if <code>checkAccess()</code> fails with a SecurityException
     * @see java.lang.SecurityException
     * @see java.lang.SecurityManager
     * @see Thread#interrupted
     * @see Thread#isInterrupted
     */
    CARAPI Interrupt();

    /**
     * Returns a <code>boolean</code> indicating whether the current Thread (
     * <code>currentThread()</code>) has a pending interrupt request (<code>
     * true</code>) or not (<code>false</code>). It also has the side-effect of
     * clearing the flag.
     *
     * @return a <code>boolean</code> indicating the interrupt status
     * @see Thread#currentThread
     * @see Thread#interrupt
     * @see Thread#isInterrupted
     */
    static CARAPI_(Boolean) Interrupted();

    /**
     * Returns <code>true</code> if the receiver has already been started and
     * still runs code (hasn't died yet). Returns <code>false</code> either if
     * the receiver hasn't been started yet or if it has already started and run
     * to completion and died.
     *
     * @return a <code>boolean</code> indicating the liveness of the Thread
     * @see Thread#start
     */
    CARAPI IsAlive(
        /* [out] */ Boolean* isAlive);

    /**
     * Returns a <code>boolean</code> indicating whether the receiver is a
     * daemon Thread (<code>true</code>) or not (<code>false</code>) A
     * daemon Thread only runs as long as there are non-daemon Threads running.
     * When the last non-daemon Thread ends, the whole program ends no matter if
     * it had daemon Threads still running or not.
     *
     * @return a <code>boolean</code> indicating whether the Thread is a daemon
     * @see Thread#setDaemon
     */
    CARAPI IsDaemon(
        /* [out] */ Boolean* isDaemon);

    /**
     * Returns a <code>boolean</code> indicating whether the receiver has a
     * pending interrupt request (<code>true</code>) or not (
     * <code>false</code>)
     *
     * @return a <code>boolean</code> indicating the interrupt status
     * @see Thread#interrupt
     * @see Thread#interrupted
     */
    CARAPI IsInterrupted(
        /* [out] */ Boolean* isInterrupted);

    /**
     * Blocks the current Thread (<code>Thread.currentThread()</code>) until
     * the receiver finishes its execution and dies.
     *
     * @throws InterruptedException if <code>interrupt()</code> was called for
     *         the receiver while it was in the <code>join()</code> call
     * @see Object#notifyAll
     * @see java.lang.ThreadDeath
     */
    CARAPI Join();

    /**
     * Blocks the current Thread (<code>Thread.currentThread()</code>) until
     * the receiver finishes its execution and dies or the specified timeout
     * expires, whatever happens first.
     *
     * @param millis The maximum time to wait (in milliseconds).
     * @throws InterruptedException if <code>interrupt()</code> was called for
     *         the receiver while it was in the <code>join()</code> call
     * @see Object#notifyAll
     * @see java.lang.ThreadDeath
     */
    CARAPI Join(
        /* [in] */ Int64 millis);

    /**
     * Blocks the current Thread (<code>Thread.currentThread()</code>) until
     * the receiver finishes its execution and dies or the specified timeout
     * expires, whatever happens first.
     *
     * @param millis The maximum time to wait (in milliseconds).
     * @param nanos Extra nanosecond precision
     * @throws InterruptedException if <code>interrupt()</code> was called for
     *         the receiver while it was in the <code>join()</code> call
     * @see Object#notifyAll
     * @see java.lang.ThreadDeath
     */
    CARAPI Join(
        /* [in] */ Int64 millis,
        /* [in] */ Int32 nanos);

    /**
     * Resumes a suspended Thread. This is a no-op if the receiver was never
     * suspended, or suspended and already resumed. If the receiver is
     * suspended, however, makes it resume to the point where it was when it was
     * suspended.
     *
     * @throws SecurityException
     *             if <code>checkAccess()</code> fails with a SecurityException
     * @see Thread#suspend()
     * @deprecated Used with deprecated method {@link Thread#suspend}
     */
    //@Deprecated
    CARAPI Resume();

    /**
     * Set the context ClassLoader for the receiver.
     * <p>
     * The <code>RuntimePermission("setContextClassLoader")</code>
     * is checked prior to setting the handler.
     * </p>
     *
     * @param cl The context ClassLoader
     * @throws SecurityException if the current SecurityManager fails the
     *         checkPermission call.
     * @see java.lang.ClassLoader
     * @see #getContextClassLoader()
     */
    CARAPI SetContextClassLoader(
        /* [in] */ IClassLoader* cl);

    /**
     * Set if the receiver is a daemon Thread or not. This can only be done
     * before the Thread starts running.
     *
     * @param isDaemon
     *            indicates whether the Thread should be daemon or not
     * @throws SecurityException
     *             if <code>checkAccess()</code> fails with a SecurityException
     * @see Thread#isDaemon
     */
    CARAPI SetDaemon(
        /* [in] */ Boolean isDaemon);

    /**
     * <p>
     * Sets the default uncaught exception handler. This handler is invoked in
     * case any Thread dies due to an unhandled exception.
     * </p>
     * <p>
     * The <code>RuntimePermission("setDefaultUncaughtExceptionHandler")</code>
     * is checked prior to setting the handler.
     * </p>
     *
     * @param handler
     *            The handler to set or <code>null</code>.
     * @throws SecurityException
     *             if the current SecurityManager fails the checkPermission
     *             call.
     */
    static CARAPI_(void) SetDefaultUncaughtExceptionHandler(
        /* [in] */ IThreadUncaughtExceptionHandler* handler);

    /**
     * Sets the name of the Thread.
     *
     * @param threadName the new name for the Thread
     * @throws SecurityException if <code>checkAccess()</code> fails with a
     *         SecurityException
     * @see Thread#getName
     */
    CARAPI SetName(
        /* [in] */ const String& threadName);

    /**
     * Sets the priority of the Thread. Note that the final priority set may not
     * be the parameter that was passed - it will depend on the receiver's
     * ThreadGroup. The priority cannot be set to be higher than the receiver's
     * ThreadGroup's maxPriority().
     *
     * @param priority
     *            new priority for the Thread
     * @throws SecurityException
     *             if <code>checkAccess()</code> fails with a SecurityException
     * @throws IllegalArgumentException
     *             if the new priority is greater than Thread.MAX_PRIORITY or
     *             less than Thread.MIN_PRIORITY
     * @see Thread#getPriority
     */
    CARAPI SetPriority(
        /* [in] */ Int32 priority);

    /**
     * Causes the thread which sent this message to sleep for the given interval
     * of time (given in milliseconds). The precision is not guaranteed - the
     * Thread may sleep more or less than requested.
     *
     * @param time
     *            The time to sleep in milliseconds.
     * @throws InterruptedException
     *             if <code>interrupt()</code> was called for this Thread while
     *             it was sleeping
     * @see Thread#interrupt()
     */
    static CARAPI Sleep(
        /* [in] */ Int64 time);

    /**
     * Causes the thread which sent this message to sleep for the given interval
     * of time (given in milliseconds and nanoseconds). The precision is not
     * guaranteed - the Thread may sleep more or less than requested.
     *
     * @param millis
     *            The time to sleep in milliseconds.
     * @param nanos
     *            Extra nanosecond precision
     * @throws InterruptedException
     *             if <code>interrupt()</code> was called for this Thread while
     *             it was sleeping
     * @see Thread#interrupt()
     */
    static CARAPI Sleep(
        /* [in] */ Int64 millis,
        /* [in] */ Int32 nanos);

    /**
     * <p>
     * Sets the uncaught exception handler. This handler is invoked in case this
     * Thread dies due to an unhandled exception.
     * </p>
     *
     * @param handler
     *            The handler to set or <code>null</code>.
     */
    CARAPI SetUncaughtExceptionHandler(
        /* [in] */ IThreadUncaughtExceptionHandler* handler);

    /**
     * Starts the new Thread of execution. The <code>run()</code> method of
     * the receiver will be called by the receiver Thread itself (and not the
     * Thread calling <code>start()</code>).
     *
     * @throws IllegalThreadStateException if the Thread has been started before
     *
     * @see Thread#run
     */
    CARAPI Start();

    /**
     * Requests the receiver Thread to stop and throw ThreadDeath. The Thread is
     * resumed if it was suspended and awakened if it was sleeping, so that it
     * can proceed to throw ThreadDeath.
     *
     * @throws SecurityException if <code>checkAccess()</code> fails with a
     *         SecurityException
     * @deprecated because stopping a thread in this manner is unsafe and can
     * leave your application and the VM in an unpredictable state.
     */
    //@Deprecated
    CARAPI Stop();

    /**
     * Requests the receiver Thread to stop and throw the
     * <code>throwable()</code>. The Thread is resumed if it was suspended
     * and awakened if it was sleeping, so that it can proceed to throw the
     * <code>throwable()</code>.
     *
     * @param throwable Throwable object to be thrown by the Thread
     * @throws SecurityException if <code>checkAccess()</code> fails with a
     *         SecurityException
     * @throws NullPointerException if <code>throwable()</code> is
     *         <code>null</code>
     * @deprecated because stopping a thread in this manner is unsafe and can
     * leave your application and the VM in an unpredictable state.
     */
    //@Deprecated
//        public final synchronized void stop(Throwable throwable)

    /**
     * Suspends this Thread. This is a no-op if the receiver is suspended. If
     * the receiver <code>isAlive()</code> however, suspended it until <code>
     * resume()</code> is sent to it. Suspend requests are not queued, which
     * means that N requests are equivalent to just one - only one resume
     * request is needed in this case.
     *
     * @throws SecurityException
     *             if <code>checkAccess()</code> fails with a SecurityException
     * @see Thread#resume()
     * @deprecated May cause deadlocks.
     */
    //@Deprecated
    CARAPI Suspend();

    /**
     * Causes the calling Thread to yield execution time to another Thread that
     * is ready to run. The actual scheduling is implementation-dependent.
     */
    static CARAPI_(void) Yield();

    /**
     * Indicates whether the current Thread has a monitor lock on the specified
     * object.
     *
     * @param object the object to test for the monitor lock
     * @return true if the current thread has a monitor lock on the specified
     *         object; false otherwise
     */
    static CARAPI_(Boolean) HoldsLock(
        /* [in] */ Object* object);

    /**
     * Unparks this thread. This unblocks the thread it if it was
     * previously parked, or indicates that the thread is "preemptively
     * unparked" if it wasn't already parked. The latter means that the
     * next time the thread is told to park, it will merely clear its
     * latent park bit and carry on without blocking.
     *
     * <p>See {@link java.util.concurrent.locks.LockSupport} for more
     * in-depth information of the behavior of this method.</p>
     *
     * @hide for Unsafe
     */
    CARAPI Unpark();

    /**
     * Parks the current thread for a particular number of nanoseconds, or
     * indefinitely. If not indefinitely, this method unparks the thread
     * after the given number of nanoseconds if no other thread unparks it
     * first. If the thread has been "preemptively unparked," this method
     * cancels that unparking and returns immediately. This method may
     * also return spuriously (that is, without the thread being told to
     * unpark and without the indicated amount of time elapsing).
     *
     * <p>See {@link java.util.concurrent.locks.LockSupport} for more
     * in-depth information of the behavior of this method.</p>
     *
     * <p>This method must only be called when <code>this</code> is the current
     * thread.
     *
     * @param nanos number of nanoseconds to park for or <code>0</code>
     * to park indefinitely
     * @throws IllegalArgumentException thrown if <code>nanos &lt; 0</code>
     *
     * @hide for Unsafe
     */
    CARAPI ParkFor(
        /* [in] */ Int64 nanos);

    /**
     * Parks the current thread until the specified system time. This
     * method attempts to unpark the current thread immediately after
     * <code>System.currentTimeMillis()</code> reaches the specified
     * value, if no other thread unparks it first. If the thread has
     * been "preemptively unparked," this method cancels that
     * unparking and returns immediately. This method may also return
     * spuriously (that is, without the thread being told to unpark
     * and without the indicated amount of time elapsing).
     *
     * <p>See {@link java.util.concurrent.locks.LockSupport} for more
     * in-depth information of the behavior of this method.</p>
     *
     * <p>This method must only be called when <code>this</code> is the
     * current thread.
     *
     * @param time the time after which the thread should be unparked,
     * in absolute milliseconds-since-the-epoch
     *
     * @hide for Unsafe
     */
    CARAPI ParkUntil(
        /* [in] */ Int64 time);

    /**
     * Calls the <code>run()</code> method of the Runnable object the receiver
     * holds. If no Runnable is set, does nothing.
     *
     * @see Thread#start
     */
    CARAPI Run();

    static CARAPI Attach(
        /* [out] */ IThread** thread);

    static CARAPI Attach(
        /* [in] */ const String& name,
        /* [out] */ IThread** thread);

    CARAPI Detach();

    /**
     * Adds a runnable to be invoked upon interruption. If this thread has
     * already been interrupted, the runnable will be invoked immediately. The
     * action should be idempotent as it may be invoked multiple times for a
     * single interruption.
     *
     * <p>Each call to this method must be matched with a corresponding call to
     * {@link #popInterruptAction$}.
     *
     * @hide used by NIO
     */
    CARAPI PushInterruptAction(
        /* [in] */ IRunnable* interruptAction);

    /**
     * Removes {@code interruptAction} so it is not invoked upon interruption.
     *
     * @param interruptAction the pushed action, used to check that the call
     *     stack is correctly nested.
     *
     * @hide used by NIO
     */
    CARAPI PopInterruptAction(
        /* [in] */ IRunnable* interruptAction);

private:
    /**
     * Initializes a new, existing Thread object with a runnable object,
     * the given name and belonging to the ThreadGroup passed as parameter.
     * This is the method that the several public constructors delegate their
     * work to.
     *
     * @param group ThreadGroup to which the new Thread will belong
     * @param runnable a java.lang.Runnable whose method <code>run</code> will
     *        be executed by the new Thread
     * @param threadName Name for the Thread being created
     * @param stackSize Platform dependent stack size
     * @throws SecurityException if <code>group.checkAccess()</code> fails
     *         with a SecurityException
     * @throws IllegalThreadStateException if <code>group.destroy()</code> has
     *         already been done
     * @see java.lang.ThreadGroup
     * @see java.lang.Runnable
     * @see java.lang.SecurityException
     * @see java.lang.SecurityManager
     */
    ECO_LOCAL CARAPI Create(
        /* [in] */ IThreadGroup* group,
        /* [in] */ IRunnable* runnable,
        /* [in] */ const String& threadName,
        /* [in] */ Int64 stackSize);

    ECO_LOCAL static CARAPI_(AutoPtr<IThread>) NativeGetCurrentThread();

    ECO_LOCAL CARAPI_(Boolean) NativeHoldsLock(
        /* [in] */ Object* object);

    ECO_LOCAL CARAPI_(Int32) NativeGetState();

    /*
     * void interrupt()
     *
     * Interrupt a thread that is waiting (or is about to wait) on a monitor.
     */
    ECO_LOCAL CARAPI_(void) NativeInterrupt();

    ECO_LOCAL CARAPI_(Boolean) NativeIsInterrupted();

    /*
     * void nameChanged(String newName)
     *
     * The name of the target thread has changed.  We may need to alert DDMS.
     */
    ECO_LOCAL CARAPI_(void) NativeNameChanged(
        /* [in] */ const String& threadName);

    /*
     * void setPriority(int newPriority)
     *
     * Alter the priority of the specified thread.  "newPriority" will range
     * from Thread.MIN_PRIORITY to Thread.MAX_PRIORITY (1-10), with "normal"
     * threads at Thread.NORM_PRIORITY (5).
     */
    ECO_LOCAL CARAPI_(void) NativeSetPriority(
        /* [in] */ Int32 priority);

    /**
     * Stops the Thread, passing it a Throwable (which might be ThreadDeath).
     */
    //@SuppressWarnings("ThrowableInstanceNeverThrown")
    ECO_LOCAL CARAPI_(void) NativeStop();

    /**
     * Suspends the Thread.
     */
    //@SuppressWarnings("ThrowableInstanceNeverThrown")
    ECO_LOCAL CARAPI_(void) NativeSuspend();

    ECO_LOCAL static CARAPI_(void) NativeYield();

public:
    static const ThreadState STATE_MAP[];
    /*volatile*/ String mName;
    /*volatile*/ Int32 mPriority;
    NativeThread* mNativeThread;
    /* volatile */ AutoPtr<IThreadGroup> mGroup;
    /**
     * Holds the class loader for this Thread, in case there is one.
     */
    AutoPtr<IClassLoader> mContextClassLoader;

    /** Looked up reflectively and used by java.util.concurrent.locks.LockSupport. */
    AutoPtr<IInterface> mParkBlocker;

protected:
    /* some of these are accessed directly by the VM; do not rename them */
    // volatile VMThread vmThread;
    /* volatile */ Boolean mDaemon;
    /* volatile */ Int64 mStackSize;
    AutoPtr<IRunnable> mTarget;

    /**
     * Normal thread local values.
     */
    // ThreadLocal.Values localValues;

    /**
     * Inheritable thread local values.
     */
    // ThreadLocal.Values inheritableValues;

    /**
     * Reflects whether this Thread has already been started. A Thread
     * can only be started once (no recycling). Also, we need it to deduce
     * the proper Thread status.
     */
    Boolean mHasBeenStarted;

private:
    ECO_LOCAL static const Int32 NANOS_PER_MILLI;

    /**
     * Holds the thread's ID. We simply count upwards, so
     * each Thread has a unique ID.
     */
    Int64 mId;

    /** Callbacks to run on interruption. */
    //RT-TODO
    // AutoPtr<IList> mInterruptActions;
    List< AutoPtr<IInterface> > mInterruptActions;
    Object mInterruptActionsLock;

    /**
     * Holds the handler for uncaught exceptions in this Thread,
     * in case there is one.
     */
    AutoPtr<IThreadUncaughtExceptionHandler> mUncaughtHandler;

    /**
     * Holds the default handler for uncaught exceptions, in case there is one.
     */
    ECO_LOCAL static AutoPtr<IThreadUncaughtExceptionHandler> sDefaultUncaughtHandler;

    /** the park state of the thread */
    Int32 mParkState;

    /**
     * The synchronization object responsible for this thread's join/sleep/park operations.
     */
    //Object mLock;

#if defined(_DEBUG)
     Boolean mIsConstructed;
#endif
};

} // namespace Core
} // namespace Elastos

#endif //__ELASTOS_CORE_THREAD_H__
