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

#ifndef __ETL_ALLOC_H__
#define __ETL_ALLOC_H__

#include "elastos/utility/etl/etl_def.h"

_ETL_NAMESPACE_BEGIN

/**
 *  @maint
 *  A new-based allocator, as required by the standard.  Allocation and
 *  deallocation forward to global new and delete.  "SGI" style, minus
 *  reallocate().
 *  @endmaint
 *  (See @link Allocators allocators info @endlink for more.)
*/
class NewAlloc
{
public:
    static void* Allocate(size_t n) { return ::operator new(n); }

    static void Deallocate(void* p, size_t) { return ::operator delete(p); }
};

/**
 *  @maint
 *  A malloc-based allocator.  Typically slower than the
 *  __default_alloc_template (below).  Typically thread-safe and more
 *  storage efficient.  The template argument is unused and is only present
 *  to permit multiple instantiations (but see __default_alloc_template
 *  for caveats).  "SGI" style, plus __set_malloc_handler for OOM conditions.
 *  @endmaint
 *  (See @link Allocators allocators info @endlink for more.)
*/
template <int inst>
class MallocAllocTemplate
{
private:
    //oom: out of memory.
    static void* OomMalloc(size_t);
    static void* OomRealloc(void*, size_t);
    static void (* MallocAllocOomHandler)();

public:
    static void* Allocate(size_t n)
    {
        void* result = malloc(n);
        if (NULL == result) result = OomMalloc(n);
        return result;
    }

    static void Deallocate(void* p, size_t)
    {
        free(p);
    }

    static void* Reallocate(void* p, size_t /*oldSize*/, size_t newSize)
    {
        void* result = realloc(p, newSize);
        if (NULL == result) result = OomRealloc(p, newSize);
        return result;
    }

    static void (* SetMallocHandler(void (*f)()))()
    {
        void (*old)() = MallocAllocOomHandler;
        MallocAllocOomHandler = f;
        return old;
    }
};

// malloc_alloc out-of-memory handling
template <int inst>
void (* MallocAllocTemplate<inst>::MallocAllocOomHandler)() = NULL;

template <int inst>
void* MallocAllocTemplate<inst>::OomMalloc(size_t n)
{
    void (*MyMallocHandler)();
    void* result;

    for (;;) {
        MyMallocHandler = MallocAllocOomHandler;
        if (NULL == MyMallocHandler) { THROW_BAD_ALLOC(); }
        (*MyMallocHandler)();
        result = malloc(n);
        if (result) return result;
    }
}

template <int inst>
void* MallocAllocTemplate<inst>::OomRealloc(void* p, size_t n)
{
    void (*MyMallocHandler)();
    void* result;

    for (;;) {
        MyMallocHandler = MallocAllocOomHandler;
        if (NULL == MyMallocHandler) { THROW_BAD_ALLOC(); }
        (*MyMallocHandler)();
        result = realloc(p, n);
        if (result) return result;
    }
}


// Determines the underlying allocator choice for the node allocator.
#ifdef __USE_MALLOC
  typedef MallocAllocTemplate<0>    MemInterface;
#else
  typedef NewAlloc                  MemInterface;
#endif


/**
 *  @maint
 *  This is used primarily (only?) in _Alloc_traits and other places to
 *  help provide the _Alloc_type typedef.
 *
 *  This is neither "standard"-conforming nor "SGI".  The _Alloc parameter
 *  must be "SGI" style.
 *  @endmaint
 *  (See @link Allocators allocators info @endlink for more.)
*/
template <typename T, typename Alloc>
class SimpleAlloc
{
public:
    static T* Allocate(size_t n)
    {
        return 0 == n? 0 : (T*)Alloc::Allocate(n * sizeof(T));
    }

    static T* Allocate()
    {
        return (T*)Alloc::Allocate(sizeof(T));
    }

    static void Deallocate(T* p, size_t n)
    {
        if (0 != n) Alloc::Deallocate(p, n * sizeof(T));
    }

    static void Deallocate(T* p)
    {
        Alloc::Deallocate(p, sizeof(T));
    }
};


/**
 *  @maint
 *  An adaptor for an underlying allocator (_Alloc) to check the size
 *  arguments for debugging.  Errors are reported using assert; these
 *  checks can be disabled via NDEBUG, but the space penalty is still
 *  paid, therefore it is far better to just use the underlying allocator
 *  by itelf when no checking is desired.
 *
 *  "There is some evidence that this can confuse Purify." - SGI comment
 *
 *  This adaptor is "SGI" style.  The _Alloc parameter must also be "SGI".
 *  @endmaint
 *  (See @link Allocators allocators info @endlink for more.)
*/
template <typename Alloc>
class DebugAlloc
{
private:
    enum { extra = 8 }; // Size of space used to store size.  Note that this
                         // must be large enough to preserve alignment.

public:
    static void* Allocate(size_t n)
    {
        Byte* result = (Byte*)Alloc::Allocate(n + (Int32)extra);
        *(size_t*)result = n;
        return result + (Int32)extra;
    }

    static void Deallocate(void* p, size_t n)
    {
        Byte* realp = (Byte*)p - (Int32)extra;
        assert(*(size_t*)realp == n);
        Alloc::Deallocate(realp, n + (Int32)extra);
    }

    static void* Reallocate(void* p, size_t oldSize, size_t newSize)
    {
        Byte* realp = (Byte*)p - (Int32)extra;
        assert(*(size_t*)realp == oldSize);
        Byte* result = (Byte*)Alloc::Reallocate(realp,
                oldSize + (Int32)extra, newSize + (Int32)extra);
        *(size_t*)result = newSize;
        return result + (Int32)extra;
    }
};


#ifdef __USE_MALLOC

typedef MemInterface    Alloc;
typedef MemInterface    SingleClientAlloc;

#else


/**
 *  @maint
 *  Default node allocator.  "SGI" style.  Uses __mem_interface for its
 *  underlying requests (and makes as few requests as possible).
 *  **** Currently __mem_interface is always __new_alloc, never __malloc*.
 *
 *  Important implementation properties:
 *  1. If the clients request an object of size > _MAX_BYTES, the resulting
 *     object will be obtained directly from the underlying __mem_interface.
 *  2. In all other cases, we allocate an object of size exactly
 *     _S_round_up(requested_size).  Thus the client has enough size
 *     information that we can return the object to the proper free list
 *     without permanently losing part of the object.
 *
 *  The first template parameter specifies whether more than one thread may
 *  use this allocator.  It is safe to allocate an object from one instance
 *  of a default_alloc and deallocate it with another one.  This effectively
 *  transfers its ownership to the second one.  This may have undesirable
 *  effects on reference locality.
 *
 *  The second parameter is unused and serves only to allow the creation of
 *  multiple default_alloc instances.  Note that containers built on different
 *  allocator instances have different types, limiting the utility of this
 *  approach.  If you do not wish to share the free lists with the main
 *  default_alloc instance, instantiate this with a non-zero __inst.
 *
 *  @endmaint
 *  (See @link Allocators allocators info @endlink for more.)
*/

#endif /* ! __USE_MALLOC */


/**
 *  This is a "standard" allocator, as per [20.4].  The private _Alloc is
 *  "SGI" style.  (See comments at the top of stl_alloc.h.)
 *
 *  The underlying allocator behaves as follows.
 *  - if __USE_MALLOC then
 *    - thread safety depends on malloc and is entirely out of our hands
 *    - __malloc_alloc_template is used for memory requests
 *  - else (the default)
 *    - __default_alloc_template is used via two typedefs
 *    - "__single_client_alloc" typedef does no locking for threads
 *    - "__alloc" typedef is threadsafe via the locks
 *    - __new_alloc is used for memory requests
 *
 *  (See @link Allocators allocators info @endlink for more.)
*/
template <typename T>
class Allocator
{
public:
    typedef Alloc       _Alloc;      // The underlying allocator.

    typedef size_t      SizeType;
    typedef ptrdiff_t   DifferenceType;
    typedef T*          Pointer;
    typedef const T*    ConstPointer;
    typedef T&          Reference;
    typedef const T&    ConstReference;
    typedef T           ValueType;

    template <typename T1>
    struct Rebind
    {
        typedef Allocator<T1> Other;
    };

    Allocator() throw() {}
    Allocator(const Allocator&) throw() {}
    template <typename T1> Allocator(const Allocator<T1>&) throw() {}
    ~Allocator() throw() {}

    Pointer Address(Reference x) const { return &x; }
    ConstPointer Address(ConstReference x) const { return &x; }

    // __n is permitted to be 0.  The C++ standard says nothing about what
    // the return value is when __n == 0.
    T* Allocate(SizeType n, const void* = NULL)
    {
        return n != 0 ? static_cast<T*>(_Alloc::Allocate(n * sizeof(T))) : 0;
    }

    // __p is not permitted to be a null pointer.
    void Deallocate(Pointer p, SizeType n)
    {
        _Alloc::Deallocate(p, n * sizeof(T));
    }

    SizeType MaxSize() const throw()
    {
        return size_t(-1) / sizeof(T);
    }

    void Construct(Pointer p, const T& val) { new(p) T(val); }
    void Destroy(Pointer p) { p->~T(); }
};

template<>
class Allocator<void>
{
public:
    typedef size_t      SizeType;
    typedef ptrdiff_t   DifferenceType;
    typedef void*       Pointer;
    typedef const void* ConstPointer;
    typedef void        ValueType;

    template <typename T1>
    struct Rebind
    {
        typedef Allocator<T1> Other;
    };
};

template <typename T1, typename T2>
inline Boolean operator==(const Allocator<T1>&, const Allocator<T2>&)
{
    return TRUE;
}

template <typename T1, typename T2>
inline Boolean operator!=(const Allocator<T1>&, const Allocator<T2>&)
{
    return FALSE;
}


//@{
/** Comparison operators for all of the predifined SGI-style allocators.
 *  This ensures that __allocator<malloc_alloc> (for example) will work
 *  correctly.  As required, all allocators compare equal.
*/
template <Int32 inst>
inline Boolean operator==(
        const MallocAllocTemplate<inst>&, const MallocAllocTemplate<inst>&)
{
    return TRUE;
}

template <Int32 inst>
inline Boolean operator!=(
        const MallocAllocTemplate<inst>&, const MallocAllocTemplate<inst>&)
{
    return FALSE;
}

template <typename Alloc>
inline Boolean operator==(
        const DebugAlloc<Alloc>&, const DebugAlloc<Alloc>&)
{
    return TRUE;
}

template <typename Alloc>
inline Boolean operator!=(
        const DebugAlloc<Alloc>&, const DebugAlloc<Alloc>&)
{
    return FALSE;
}
//@}

/**
 *  @maint
 *  Another allocator adaptor:  _Alloc_traits.  This serves two purposes.
 *  First, make it possible to write containers that can use either "SGI"
 *  style allocators or "standard" allocators.  Second, provide a mechanism
 *  so that containers can query whether or not the allocator has distinct
 *  instances.  If not, the container can avoid wasting a word of memory to
 *  store an empty object.  For examples of use, see stl_vector.h, etc, or
 *  any of the other classes derived from this one.
 *
 *  This adaptor uses partial specialization.  The general case of
 *  _Alloc_traits<_Tp, _Alloc> assumes that _Alloc is a
 *  standard-conforming allocator, possibly with non-equal instances and
 *  non-static members.  (It still behaves correctly even if _Alloc has
 *  static member and if all instances are equal.  Refinements affect
 *  performance, not correctness.)
 *
 *  There are always two members:  allocator_type, which is a standard-
 *  conforming allocator type for allocating objects of type _Tp, and
 *  _S_instanceless, a static const member of type bool.  If
 *  _S_instanceless is true, this means that there is no difference
 *  between any two instances of type allocator_type.  Furthermore, if
 *  _S_instanceless is true, then _Alloc_traits has one additional
 *  member:  _Alloc_type.  This type encapsulates allocation and
 *  deallocation of objects of type _Tp through a static interface; it
 *  has two member functions, whose signatures are
 *
 *  -  static _Tp* allocate(size_t)
 *  -  static void deallocate(_Tp*, size_t)
 *
 *  The size_t parameters are "standard" style (see top of stl_alloc.h) in
 *  that they take counts, not sizes.
 *
 *  @endmaint
 *  (See @link Allocators allocators info @endlink for more.)
*/
//@{
// The fully general version.
template <typename T, typename Allocator>
struct AllocTraits
{
    static const Boolean S_instanceless = FALSE;
    typedef typename Allocator::template Rebind<T>::Other AllocatorType;
};

template <typename T, typename Allocator>
const Boolean AllocTraits<T, Allocator>::S_instanceless;


/// The version for the default allocator.
template <typename T, typename T1>
struct AllocTraits<T, Allocator<T1> >
{
    static const Boolean S_instanceless = TRUE;
    typedef SimpleAlloc<T, Alloc> AllocType;
    typedef Allocator<T> AllocatorType;
};
//@}


_ETL_NAMESPACE_END

#endif //__ETL_ALLOC_H__