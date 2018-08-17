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

#ifndef __ELASTOS_CORE_MUTEX_H__
#define __ELASTOS_CORE_MUTEX_H__

#include <pthread.h>
#ifdef _win32
#include <sys/types.h>
#endif
#include <elastos.h>

namespace Elastos {
namespace Core {

/*!
 @brief Simple mutex class.The implementation is system-dependent.The mutex must be unlocked
 by the thread that locked it.  They are not recursive, i.e. the same thread can't lock it
 multiple times.

 A mutex (short for mutual exclusion) is a way of communicating among threads or processes
 that are executing asynchronously of one another. This communication is usually used to
 coordinate the activities of multiple threads or processes, typically by controlling access
 to a shared resource by locking and unlocking the resource. To solve this x,y coordinate
 update problem, the update thread sets a mutex indicating that the data structure is in use
 before performing the update. It would clear the mutex after both coordinates had been processed.

 @since
 @sa
*/
class Mutex
{
public:
    enum {
        PRIVATE = 0,   /*!< define the value @a 0 as the private mark.*/
        SHARED = 1     /*!< define the value @a 1 as the shared mark.*/
    };
/*!
 @brief Initializes a new instances of the @a Mutex class with default properties.

 @since
 @sa
*/
    Mutex();
/*!
 @brief Initializes a new instances of the @a Mutex class named @a name.

  It is not supportive to a named @a Mutex instance temporarily.its effect is
  now the same as constructor @a Mutex().
 @param name the name of the mutual exclusion instance.

 @since
 @sa Mutex()
*/
    Mutex(const char* name);
/*!
 @brief Initializes a new instances of the @a Mutex class with specified properties.

 if @a type is @a SHARED,create a shared Mutex instance,which supports communicating
 among threads;
 if @a type is @a PRIVATE,create a private Mutex instance,which supports processes
 that are executing asynchronously of one another.
 @param type the @a Mutex instance's owner, @a PRIVATE or @a SHARED.
 @param name the name of the mutual exclusion instance.here initializes it to be null.
 @since
 @sa
*/
    Mutex(Int32 type, const char* name = NULL);

/*!
 @brief the destructor of @a Mutex instance.

 when the accessing thread doesn't need to access the resource but to leave,it must call
 this method to release the resource associated with the @a Mutex instance.
 @since
 @sa
*/
    ~Mutex();

/*!
 @brief this method is called to lock the @a Mutex instance for some specified resource.

 if the specified resource has been locked by another process,then the current process would
 wait until it can enter into this resource.the system must ensure that only one thread could
 lock the resource successfully at one time.

 @return
 @since
 @sa
*/
    CARAPI_(Int32) Lock();
/*!
 @brief this method is called to unlock the @a Mutex instance for some specified resource.

 when the current thread finishes its operation on the resource,this method is called to
 release the mutual exclusion scope,so as to make the other thread lock this scope.
 @return
 @since
 @sa
*/
    CARAPI_(Int32) Unlock();
/*!
 @brief this method is called to trying to lock the @a Mutex instance for the specified resource
 if possible.according to the return value,the user can justify the scope is locked or not.
 @return returns 0 on success, error otherwise.
 @since
 @sa
*/
    CARAPI_(Int32) TryLock();
/*!
 @brief AutoLock is the inner class of the @a MUtex.Uses it to manage the mutex automatically.
 It'll be locked when @a AutoLock is constructed and released when @a AutoLock goes out of scope.

 @since
 @sa
*/
    class AutoLock
    {
    public:
/*!
   @brief create a @a AutoLock instance,as a result of this constructing, the @a Mutex instance
   is locked.
   @param mutex reference of the @a Mutex instance to be locked automatically.
   @since
   @sa
*/
        inline AutoLock(Mutex& mutex) : mLock(mutex)  { mLock.Lock(); }
/*!
   @brief create a @a AutoLock instance,as a result of this constructing, the @a Mutex instance
   is locked.
   @param mutex pointer of the @a Mutex instance to be locked automatically.
   @since
   @sa
*/
        inline AutoLock(Mutex* mutex) : mLock(*mutex) { mLock.Lock(); }
/*!
   @brief  the destructor of @a AutoLock instance.when an AutoLock instance goes out of its scope,
   this method is called to unlock the @a Mutex instance.
*/
        inline ~AutoLock() { mLock.Unlock(); }
    private:
/*!
   @brief a reference to a @a Mutex instance.
*/
        Mutex& mLock;
    };

private:
/*!
   @brief a private copied constructor of @a Mutex.a @a Mutex cannot be copied
   except a friend class of the @a Mutex class.
   @param   a reference to the @a Mutex.
   @since
   @sa
*/
    Mutex(const Mutex&);
/*!
   @brief the comparision between two @a Mutex instance,test if they are equaled.
   @param   a reference to the @a Mutex.
   @since
   @sa
*/
    Mutex& operator = (const Mutex&);

public:
/*!
   @brief a mutual exclusion thread.
*/
    pthread_mutex_t mMutex;
};

#ifdef _apple
#define PTHREAD_MUTEX_ERRORCHECK_NP PTHREAD_MUTEX_ERRORCHECK
#endif

inline Mutex::Mutex()
{
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK_NP);
    pthread_mutex_init(&mMutex, &attr);
    pthread_mutexattr_destroy(&attr);
}

inline Mutex::Mutex(const char* name)
{
    pthread_mutex_init(&mMutex, NULL);
}

inline Mutex::Mutex(Int32 type, const char* name)
{
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK_NP);
    if (type == SHARED) {
        pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);
    }
    pthread_mutex_init(&mMutex, &attr);
    pthread_mutexattr_destroy(&attr);
}

inline Mutex::~Mutex()
{
    pthread_mutex_destroy(&mMutex);
}

inline Int32 Mutex::Lock()
{
    return pthread_mutex_lock(&mMutex);
}

inline Int32 Mutex::Unlock()
{
    return pthread_mutex_unlock(&mMutex);
}

inline Int32 Mutex::TryLock()
{
    return pthread_mutex_trylock(&mMutex);
}

} // namespace Core
} // namespace Elastos

#endif //__ELASTOS_CORE_MUTEX_H__
