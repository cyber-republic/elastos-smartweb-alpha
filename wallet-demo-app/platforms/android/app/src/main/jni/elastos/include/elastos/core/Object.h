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

#ifndef __ELASTOS_CORE_OBJECT_H__
#define __ELASTOS_CORE_OBJECT_H__

#include "Elastos.CoreLibrary.Core.h"
#include "elastos/coredef.h"
#include "elastos/core/NativeThread.h"
#include "elastos/core/StringUtils.h"

using Elastos::Core::ISynchronize;
using Elastos::Core::NativeObject;

namespace Elastos {
namespace Core {

//====================================================================
// Object
//====================================================================
class ECO_PUBLIC Object
    : public ElRefBase
    , public IObject
    , public ISynchronize
    , public IWeakReferenceSource
{
public:
    CAR_INTERFACE_DECL()

    CAR_OBJECT_DECL()

    Object();

    virtual ~Object();

    CARAPI constructor();

    CARAPI GetClassInfo(
        /* [out] */ IInterface** clsInfo);

    CARAPI GetHashCode(
        /* [out] */ Int32* hashCode);

    CARAPI Equals(
        /* [in] */ IInterface* other,
        /* [out] */ Boolean* result);

    CARAPI ToString(
        /* [out] */ String* info);

    CARAPI Lock();

    CARAPI Unlock();

    /**
     * Causes a thread which is waiting on this object's monitor (by means of
     * calling one of the {@code wait()} methods) to be woken up. If more than
     * one thread is waiting, one of them is chosen at the discretion of the
     * virtual machine. The chosen thread will not run immediately. The thread
     * that called {@code notify()} has to release the object's monitor first.
     * Also, the chosen thread still has to compete against other threads that
     * try to synchronize on the same object.
     * <p>
     * This method can only be invoked by a thread which owns this object's
     * monitor. A thread becomes owner of an object's monitor
     * </p>
     * <ul>
     * <li>by executing a synchronized method of that object;</li>
     * <li>by executing the body of a {@code synchronized} statement that
     * synchronizes on the object;</li>
     * <li>by executing a synchronized static method if the object is of type
     * {@code Class}.</li>
     * </ul>
     *
     * @see #notifyAll
     * @see #wait()
     * @see #wait(long)
     * @see #wait(long,int)
     * @see java.lang.Thread
     */
    CARAPI Notify();

    /**
     * Causes all threads which are waiting on this object's monitor (by means
     * of calling one of the {@code wait()} methods) to be woken up. The threads
     * will not run immediately. The thread that called {@code notify()} has to
     * release the object's monitor first. Also, the threads still have to
     * compete against other threads that try to synchronize on the same object.
     * <p>
     * This method can only be invoked by a thread which owns this object's
     * monitor. A thread becomes owner of an object's monitor
     * </p>
     * <ul>
     * <li>by executing a synchronized method of that object;</li>
     * <li>by executing the body of a {@code synchronized} statement that
     * synchronizes on the object;</li>
     * <li>by executing a synchronized static method if the object is of type
     * {@code Class}.</li>
     * </ul>
     *
     * @throws IllegalMonitorStateException
     *             if the thread calling this method is not the owner of this
     *             object's monitor.
     * @see #notify
     * @see #wait()
     * @see #wait(long)
     * @see #wait(long,int)
     * @see java.lang.Thread
     */
    CARAPI NotifyAll();

    /**
     * Causes the calling thread to wait until another thread calls the {@code
     * notify()} or {@code notifyAll()} method of this object. This method can
     * only be invoked by a thread which owns this object's monitor; see
     * {@link #notify()} on how a thread can become the owner of a monitor.
     * <p>
     * A waiting thread can be sent {@code interrupt()} to cause it to
     * prematurely stop waiting, so {@code wait} should be called in a loop to
     * check that the condition that has been waited for has been met before
     * continuing.
     * </p>
     * <p>
     * While the thread waits, it gives up ownership of this object's monitor.
     * When it is notified (or interrupted), it re-acquires the monitor before
     * it starts running.
     * </p>
     *
     * @throws IllegalMonitorStateException
     *             if the thread calling this method is not the owner of this
     *             object's monitor.
     * @throws InterruptedException
     *             if another thread interrupts this thread while it is waiting.
     * @see #notify
     * @see #notifyAll
     * @see #wait(long)
     * @see #wait(long,int)
     * @see java.lang.Thread
     */
    CARAPI Wait();

    /**
     * Causes the calling thread to wait until another thread calls the {@code
     * notify()} or {@code notifyAll()} method of this object or until the
     * specified timeout expires. This method can only be invoked by a thread
     * which owns this object's monitor; see {@link #notify()} on how a thread
     * can become the owner of a monitor.
     * <p>
     * A waiting thread can be sent {@code interrupt()} to cause it to
     * prematurely stop waiting, so {@code wait} should be called in a loop to
     * check that the condition that has been waited for has been met before
     * continuing.
     * </p>
     * <p>
     * While the thread waits, it gives up ownership of this object's monitor.
     * When it is notified (or interrupted), it re-acquires the monitor before
     * it starts running.
     * </p>
     *
     * @param millis
     *            the maximum time to wait in milliseconds.
     * @throws IllegalArgumentException
     *             if {@code millis < 0}.
     * @throws IllegalMonitorStateException
     *             if the thread calling this method is not the owner of this
     *             object's monitor.
     * @throws InterruptedException
     *             if another thread interrupts this thread while it is waiting.
     * @see #notify
     * @see #notifyAll
     * @see #wait()
     * @see #wait(long,int)
     * @see java.lang.Thread
     */
    CARAPI Wait(
        /* [in] */ Int64 millis);

    /**
     * Causes the calling thread to wait until another thread calls the {@code
     * notify()} or {@code notifyAll()} method of this object or until the
     * specified timeout expires. This method can only be invoked by a thread
     * that owns this object's monitor; see {@link #notify()} on how a thread
     * can become the owner of a monitor.
     * <p>
     * A waiting thread can be sent {@code interrupt()} to cause it to
     * prematurely stop waiting, so {@code wait} should be called in a loop to
     * check that the condition that has been waited for has been met before
     * continuing.
     * </p>
     * <p>
     * While the thread waits, it gives up ownership of this object's monitor.
     * When it is notified (or interrupted), it re-acquires the monitor before
     * it starts running.
     * </p>
     *
     * @param millis
     *            the maximum time to wait in milliseconds.
     * @param nanos
     *            the fraction of a millisecond to wait, specified in
     *            nanoseconds.
     * @throws IllegalArgumentException
     *             if {@code millis < 0}, {@code nanos < 0} or {@code nanos >
     *             999999}.
     * @throws IllegalMonitorStateException
     *             if the thread calling this method is not the owner of this
     *             object's monitor.
     * @throws InterruptedException
     *             if another thread interrupts this thread while it is waiting.
     * @see #notify
     * @see #notifyAll
     * @see #wait()
     * @see #wait(long,int)
     * @see java.lang.Thread
     */
    CARAPI Wait(
        /* [in] */ Int64 millis,
        /* [in] */ Int32 nanos);

    CARAPI GetWeakReference(
        /* [out] */ IWeakReference** weakReference);

public:
    //================================================================
    // static methods
    //================================================================

    // GetHashCode()
    //
    template<typename T1>
    static CARAPI_(Int32) GetHashCode(
        /* [in] */ T1* obj);

    template<typename T1>
    static CARAPI_(Int32) GetHashCode(
        /* [in] */ const AutoPtr<T1>& obj);

    // ToString()
    //
    template<typename T1>
    static CARAPI_(String) ToString(
        /* [in] */ T1* obj);

    template<typename T1>
    static CARAPI_(String) ToString(
        /* [in] */ const AutoPtr<T1>& obj);

    // Equals()
    //
    template<typename T>
    static CARAPI_(Boolean) Equals(
        /* [in] */ T* lhs,
        /* [in] */ T* rhs);

    template<typename T1, typename T2>
    static CARAPI_(Boolean) Equals(
        /* [in] */ T1* lhs,
        /* [in] */ T2* rhs);

    template<typename T>
    static CARAPI_(Boolean) Equals(
        /* [in] */ const AutoPtr<T>& lhs,
        /* [in] */ const AutoPtr<T>& rhs);

    template<typename T1, typename T2>
    static CARAPI_(Boolean) Equals(
        /* [in] */ const AutoPtr<T1>& lhs,
        /* [in] */ T2* rhs);

    template<typename T1, typename T2>
    static CARAPI_(Boolean) Equals(
        /* [in] */ T1* lhs,
        /* [in] */ const AutoPtr<T2>& rhs);

    template<typename T1, typename T2>
    static CARAPI_(Boolean) Equals(
        /* [in] */ const AutoPtr<T1>& lhs,
        /* [in] */ const AutoPtr<T2>& rhs);

    static CARAPI_(AutoPtr<IClassInfo>) GetClassInfo(
        /* [in] */ IInterface* obj);

    static CARAPI_(AutoPtr<IClassLoader>) GetClassLoader(
        /* [in] */ IInterface* obj);

    static CARAPI_(String) GetClassName(
        /* [in] */ IInterface* obj);

    static CARAPI_(String) GetFullClassName(
        /* [in] */ IInterface* obj);

    static CARAPI_(String) GetNamespace(
        /* [in] */ IInterface* obj);

    static CARAPI_(AutoPtr<IModuleInfo>) GetModuleInfo(
        /* [in] */ IInterface* obj);

    static CARAPI_(String) GetModulePath(
        /* [in] */ IInterface* obj);

public:
    NativeObject mNativeObject;
    AutoPtr<IClassInfo> mClassInfo;
};

//====================================================================
// Implements
//====================================================================

// GetHashCode
//
template<typename T1>
Int32 Object::GetHashCode(
    /* [in] */ T1* obj)
{
    if (obj == NULL) {
        return 0;
    }

    IObject* o = (IObject*)obj->Probe(EIID_IObject);
    if (o == NULL) {
#ifdef _ELASTOS64
        return *(Int32 *)obj;
#else
        return (Int32)obj;
#endif
    }

    Int32 hashcode = 0;
    o->GetHashCode(&hashcode);
    return hashcode;
}

template<typename T1>
Int32 Object::GetHashCode(
    /* [in] */ const AutoPtr<T1>& obj)
{
    return GetHashCode(obj.Get());
}

// ToString
//
template<typename T1>
String Object::ToString(
    /* [in] */ T1* obj)
{
    if (obj == NULL) {
        return String(NULL);
    }

    IObject* o = (IObject*)obj->Probe(EIID_IObject);
    if (o == NULL) {
#ifdef _ELASTOS64
        return StringUtils::ToHexString((Int64)obj);
#else
        return StringUtils::ToHexString((Int32)obj);
#endif
    }

    String str;
    o->ToString(&str);
    return str;
}

template<typename T1>
String Object::ToString(
    /* [in] */ const AutoPtr<T1>& obj)
{
    return ToString(obj.Get());
}

// Equals
//
template<typename T>
Boolean Object::Equals(
    /* [in] */ T* lhs,
    /* [in] */ T* rhs)
{
    if (lhs == rhs) {
        return TRUE;
    }
    else if (lhs == NULL || rhs == NULL) {
        return FALSE;
    }

    IObject* obj = (IObject*)lhs->Probe(EIID_IObject);
    if (obj == NULL) {
        return FALSE;
    }
    Boolean isflag = FALSE;
    obj->Equals(rhs->Probe(EIID_IInterface), &isflag);
    return isflag;
}

template<typename T1, typename T2>
Boolean Object::Equals(
    /* [in] */ T1* lhs,
    /* [in] */ T2* rhs)
{
    if (lhs == NULL && rhs == NULL) {
        return TRUE;
    }
    else if (lhs == NULL || rhs == NULL) {
        return FALSE;
    }

    IObject* obj = (IObject*)lhs->Probe(EIID_IObject);
    if (obj == NULL) {
        return FALSE;
    }
    Boolean isflag = FALSE;
    obj->Equals(rhs->Probe(EIID_IInterface), &isflag);
    return isflag;
}

template<typename T1, typename T2>
Boolean Object::Equals(
    /* [in] */ const AutoPtr<T1>& lhs,
    /* [in] */ T2* rhs)
{
    return Equals(lhs.Get(), rhs);
}

template<typename T1, typename T2>
Boolean Object::Equals(
    /* [in] */ T1* lhs,
    /* [in] */ const AutoPtr<T2>& rhs)
{
    return Equals(lhs, rhs.Get());
}

template<typename T1, typename T2>
Boolean Object::Equals(
    /* [in] */ const AutoPtr<T1>& lhs,
    /* [in] */ const AutoPtr<T2>& rhs)
{
    return Equals(lhs.Get(), rhs.Get());
}

template<typename T>
Boolean Object::Equals(
    /* [in] */ const AutoPtr<T>& lhs,
    /* [in] */ const AutoPtr<T>& rhs)
{
    return Equals(lhs.Get(), rhs.Get());
}

} // namespace Core
} // namespace Elastos


using Elastos::Core::Object;

#ifndef TO_STRING_IMPL
#define TO_STRING_IMPL(className)                                                       \
    CARAPI ToString(                                                                    \
        /* [out] */ String* str)                                                        \
    {                                                                                   \
        VALIDATE_NOT_NULL(str)                                                          \
        String info("");                                                                \
        info.AppendFormat("Object[0x%08x], Class[%s]", this, className);                \
        *str = info;                                                                    \
        return NOERROR;                                                                 \
    }
#endif

#endif //__ELASTOS_CORE_OBJECT_H__
