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

#ifndef __ETL_FUNCTION_H__
#define __ETL_FUNCTION_H__

#include "elastos/utility/etl/etl_def.h"

_ETL_NAMESPACE_BEGIN

// 20.3.1 base classes
/** @defgroup s20_3_1_base Functor Base Classes
 *  Function objects, or @e functors, are objects with an @c operator()
 *  defined and accessible.  They can be passed as arguments to algorithm
 *  templates and used in place of a function pointer.  Not only is the
 *  resulting expressiveness of the library increased, but the generated
 *  code can be more efficient than what you might write by hand.  When we
 *  refer to "functors," then, generally we include function pointers in
 *  the description as well.
 *
 *  Often, functors are only created as temporaries passed to algorithm
 *  calls, rather than being created as named variables.
 *
 *  Two examples taken from the standard itself follow.  To perform a
 *  by-element addition of two vectors @c a and @c b containing @c double,
 *  and put the result in @c a, use
 *  \code
 *  transform (a.begin(), a.end(), b.begin(), a.begin(), plus<double>());
 *  \endcode
 *  To negate every element in @c a, use
 *  \code
 *  transform(a.begin(), a.end(), a.begin(), negate<double>());
 *  \endcode
 *  The addition and negation functions will be inlined directly.
 *
 *  The standard functiors are derived from structs named @c UnaryFunction
 *  and @c BinaryFunction.  These two classes contain nothing but typedefs,
 *  to aid in generic (template) programming.  If you write your own
 *  functors, you might consider doing the same.
 *
 *  @{
*/
/**
 *  This is one of the @link s20_3_1_base functor base classes@endlink.
*/
template <class Arg, class Result>
struct UnaryFunction
{
    typedef Arg ArgumentType;   ///< @c ArgumentType is the type of the argument (no surprises here)
    typedef Result ResultType;  ///< @c ResultType is the return type
};

/**
 *  This is one of the @link s20_3_1_base functor base classes@endlink.
*/
template <class Arg1, class Arg2, class Result>
struct BinaryFunction
{
  typedef Arg1 FirstArgumentType;   ///< the type of the first argument (no surprises here)
  typedef Arg2 SecondArgumentType;  ///< the type of the second argument
  typedef Result ResultType;         ///< type of the return type
};
/** @}  */

// 20.3.2 arithmetic
/** @defgroup s20_3_2_arithmetic Arithmetic Classes
 *  Because basic math often needs to be done during an algorithm, the library
 *  provides functors for those operations.  See the documentation for
 *  @link s20_3_1_base the base classes@endlink for examples of their use.
 *
 *  @{
*/
/// One of the @link s20_3_2_arithmetic math functors@endlink.
template <class T>
struct Plus : public BinaryFunction<T,T,T>
{
    T operator()(const T& x, const T& y) const { return x + y; }
};

/// One of the @link s20_3_2_arithmetic math functors@endlink.
template <class T>
struct Minus : public BinaryFunction<T,T,T>
{
    T operator()(const T& x, const T& y) const { return x - y; }
};

/// One of the @link s20_3_2_arithmetic math functors@endlink.
template <class T>
struct Multiplies : public BinaryFunction<T,T,T>
{
    T operator()(const T& x, const T& y) const { return x * y; }
};

/// One of the @link s20_3_2_arithmetic math functors@endlink.
template <class T>
struct Divides : public BinaryFunction<T,T,T>
{
    T operator()(const T& x, const T& y) const { return x / y; }
};

/// One of the @link s20_3_2_arithmetic math functors@endlink.
template <class T>
struct Modulus : public BinaryFunction<T,T,T>
{
    T operator()(const T& x, const T& y) const { return x % y; }
};

/// One of the @link s20_3_2_arithmetic math functors@endlink.
template <class T>
struct Negate : public UnaryFunction<T,T>
{
    T operator()(const T& x) const { return -x; }
};
/** @}  */

// 20.3.3 comparisons
/** @defgroup s20_3_3_comparisons Comparison Classes
 *  The library provides six wrapper functors for all the basic comparisons
 *  in C++, like @c <.
 *
 *  @{
*/
/// One of the @link s20_3_3_comparisons comparison functors@endlink.
template <class T>
struct EqualTo : public BinaryFunction<T,T,Boolean>
{
    Boolean operator()(const T& x, const T& y) const { return x == y; }
};

/// One of the @link s20_3_3_comparisons comparison functors@endlink.
template <class T>
struct NotEqualTo : public BinaryFunction<T,T,Boolean>
{
    Boolean operator()(const T& x, const T& y) const { return x != y; }
};

/// One of the @link s20_3_3_comparisons comparison functors@endlink.
template <class T>
struct Greater : public BinaryFunction<T,T,Boolean>
{
    Boolean operator()(const T& x, const T& y) const { return x > y; }
};

/// One of the @link s20_3_3_comparisons comparison functors@endlink.
template <class T>
struct Less : public BinaryFunction<T,T,Boolean>
{
    Boolean operator()(const T& x, const T& y) const { return x < y; }
};

/// One of the @link s20_3_3_comparisons comparison functors@endlink.
template <class T>
struct GreaterEqual : public BinaryFunction<T,T,Boolean>
{
    Boolean operator()(const T& x, const T& y) const { return x >= y; }
};

/// One of the @link s20_3_3_comparisons comparison functors@endlink.
template <class T>
struct LessEqual : public BinaryFunction<T,T,Boolean>
{
    Boolean operator()(const T& x, const T& y) const { return x <= y; }
};
/** @}  */

// 20.3.4 logical operations
/** @defgroup s20_3_4_logical Boolean Operations Classes
 *  Here are wrapper functors for Boolean operations:  @c &&, @c ||, and @c !.
 *
 *  @{
*/
/// One of the @link s20_3_4_logical Boolean operations functors@endlink.
template <class T>
struct LogicalAnd : public BinaryFunction<T,T,Boolean>
{
    Boolean operator()(const T& x, const T& y) const { return x && y; }
};

/// One of the @link s20_3_4_logical Boolean operations functors@endlink.
template <class T>
struct LogicalOr : public BinaryFunction<T,T,Boolean>
{
    Boolean operator()(const T& x, const T& y) const { return x || y; }
};

/// One of the @link s20_3_4_logical Boolean operations functors@endlink.
template <class T>
struct LogicalNot : public UnaryFunction<T,Boolean>
{
    Boolean operator()(const T& x) const { return !x; }
};
/** @}  */

// 20.3.5 negators
/** @defgroup s20_3_5_negators Negators
 *  The functions @c not1 and @c not2 each take a predicate functor
 *  and return an instance of @c UnaryNegate or
 *  @c BinaryNegate, respectively.  These classes are functors whose
 *  @c operator() performs the stored predicate function and then returns
 *  the negation of the result.
 *
 *  For example, given a vector of integers and a trivial predicate,
 *  \code
 *  struct IntGreaterThanThree
 *    : public std::UnaryFunction<int, Boolean>
 *  {
 *      Boolean operator() (int x) { return x > 3; }
 *  };
 *
 *  std::find_if (v.begin(), v.end(), not1(IntGreaterThanThree()));
 *  \endcode
 *  The call to @c find_if will locate the first index (i) of @c v for which
 *  "!(v[i] > 3)" is true.
 *
 *  The not1/UnaryNegate combination works on predicates taking a single
 *  argument.  The not2/BinaryNegate combination works on predicates which
 *  take two arguments.
 *
 *  @{
*/
/// One of the @link s20_3_5_negators negation functors@endlink.
template <class Predicate>
class UnaryNegate : public UnaryFunction<typename Predicate::ArgumentType, Boolean>
{
protected:
    Predicate mPred;
public:
    explicit UnaryNegate(const Predicate& x) : mPred(x) {}
    Boolean operator()(const typename Predicate::ArgumentType& x) const
    {
        return !mPred(x);
    }
};

/// One of the @link s20_3_5_negators negation functors@endlink.
template <class Predicate>
inline UnaryNegate<Predicate> Not1(const Predicate& pred)
{
    return UnaryNegate<Predicate>(pred);
}

/// One of the @link s20_3_5_negators negation functors@endlink.
template <class Predicate>
class BinaryNegate  : public BinaryFunction<typename Predicate::FirstArgumentType,
        typename Predicate::SecondArgumentType, Boolean>
{
protected:
    Predicate mPred;
public:
    explicit BinaryNegate(const Predicate& x) : mPred(x) {}
    Boolean operator()(const typename Predicate::FirstArgumentType& x,
            const typename Predicate::SecondArgumentType& y) const
    {
        return !mPred(x, y);
    }
};

/// One of the @link s20_3_5_negators negation functors@endlink.
template <class Predicate>
inline BinaryNegate<Predicate> Not2(const Predicate& pred)
{
    return BinaryNegate<Predicate>(pred);
}
/** @}  */

// 20.3.6 binders
/** @defgroup s20_3_6_binder Binder Classes
 *  Binders turn functions/functors with two arguments into functors with
 *  a single argument, storing an argument to be applied later.  For
 *  example, an variable @c B of type @c Binder1st is constructed from a functor
 *  @c f and an argument @c x.  Later, B's @c operator() is called with a
 *  single argument @c y.  The return value is the value of @c f(x,y).
 *  @c B can be "called" with various arguments (y1, y2, ...) and will in
 *  turn call @c f(x,y1), @c f(x,y2), ...
 *
 *  The function @c bind1st is provided to save some typing.  It takes the
 *  function and an argument as parameters, and returns an instance of
 *  @c Binder1st.
 *
 *  The type @c Binder2nd and its creator function @c bind2nd do the same
 *  thing, but the stored argument is passed as the second parameter instead
 *  of the first, e.g., @c bind2nd(std::minus<float>,1.3) will create a
 *  functor whose @c operator() accepts a floating-point number, subtracts
 *  1.3 from it, and returns the result.  (If @c bind1st had been used,
 *  the functor would perform "1.3 - x" instead.
 *
 *  Creator-wrapper functions like @c bind1st are intended to be used in
 *  calling algorithms.  Their return values will be temporary objects.
 *  (The goal is to not require you to type names like
 *  @c std::Binder1st<std::plus<int>> for declaring a variable to hold the
 *  return value from @c bind1st(std::plus<int>,5).
 *
 *  These become more useful when combined with the composition functions.
 *
 *  @{
*/
/// One of the @link s20_3_6_binder binder functors@endlink.
template <class Operation>
class Binder1st :
        public UnaryFunction<typename Operation::SecondArgumentType,
                             typename Operation::ResultType>
{
protected:
    Operation mOp;
    typename Operation::FirstArgumentType mValue;

public:
    Binder1st(const Operation& x,
            const typename Operation::FirstArgumentType& y) : mOp(x), mValue(y) {}

    typename Operation::ResultType
    operator()(const typename Operation::SecondArgumentType& x) const
    {
        return mOp(mValue, x);
    }

#ifdef _GLIBCPP_RESOLVE_LIB_DEFECTS
    //109.  Missing binders for non-const sequence elements
    typename Operation::ResultType
    operator()(typename Operation::SecondArgumentType& x) const
    {
        return mOp(mValue, x);
    }
#endif
};

/// One of the @link s20_3_6_binder binder functors@endlink.
template <class Operation, class T>
inline Binder1st<Operation> Bind1st(const Operation& fn, const T& x)
{
    typedef typename Operation::FirstArgumentType Arg1Type;
    return Binder1st<Operation>(fn, Arg1Type(x));
}

/// One of the @link s20_3_6_binder binder functors@endlink.
template <class Operation>
class Binder2nd :
        public UnaryFunction<typename Operation::FirstArgumentType,
                             typename Operation::ResultType>
{
protected:
    Operation mOp;
    typename Operation::SecondArgumentType mValue;

public:
    Binder2nd(const Operation& x,
              const typename Operation::SecondArgumentType& y) : mOp(x), mValue(y) {}

    typename Operation::ResultType
    operator()(const typename Operation::FirstArgumentType& x) const
    {
        return mOp(x, mValue);
    }

#ifdef _GLIBCPP_RESOLVE_LIB_DEFECTS
    //109.  Missing binders for non-const sequence elements
    typename Operation::ResultType
    operator()(typename Operation::FirstArgumentType& x) const
    {
        return mOp(x, mValue);
    }
#endif
};

/// One of the @link s20_3_6_binder binder functors@endlink.
template <class Operation, class T>
inline Binder2nd<Operation> Bind2nd(const Operation& fn, const T& x)
{
    typedef typename Operation::SecondArgumentType Arg2Type;
    return Binder2nd<Operation>(fn, Arg2Type(x));
}
/** @}  */

// 20.3.7 adaptors pointers functions
/** @defgroup s20_3_7_adaptors Adaptors for pointers to functions
 *  The advantage of function objects over pointers to functions is that
 *  the objects in the standard library declare nested typedefs describing
 *  their argument and result types with uniform names (e.g., @c result_type
 *  from the base classes @c UnaryFunction and @c BinaryFunction).
 *  Sometimes those typedefs are required, not just optional.
 *
 *  Adaptors are provided to turn pointers to unary (single-argument) and
 *  binary (double-argument) functions into function objects.  The long-winded
 *  functor @c PointerToUnaryFunction is constructed with a function
 *  pointer @c f, and its @c operator() called with argument @c x returns
 *  @c f(x).  The functor @c PointerToBinaryFunction does the same thing,
 *  but with a double-argument @c f and @c operator().
 *
 *  The function @c ptr_fun takes a pointer-to-function @c f and constructs
 *  an instance of the appropriate functor.
 *
 *  @{
*/
/// One of the @link s20_3_7_adaptors adaptors for function pointers@endlink.
template <class Arg, class Result>
class PointerToUnaryFunction : public UnaryFunction<Arg, Result>
{
protected:
    Result (*mPtr)(Arg);
public:
    PointerToUnaryFunction() {}
    explicit PointerToUnaryFunction(Result (*x)(Arg)) : mPtr(x) {}
    Result operator()(Arg x) const { return mPtr(x); }
};

/// One of the @link s20_3_7_adaptors adaptors for function pointers@endlink.
template <class Arg, class Result>
inline PointerToUnaryFunction<Arg, Result> PtrFun(Result (*x)(Arg))
{
    return PointerToUnaryFunction<Arg, Result>(x);
}

/// One of the @link s20_3_7_adaptors adaptors for function pointers@endlink.
template <class Arg1, class Arg2, class Result>
class PointerToBinaryFunction :
        public BinaryFunction<Arg1,Arg2,Result>
{
protected:
    Result (*mPtr)(Arg1, Arg2);
public:
    PointerToBinaryFunction() {}
    explicit PointerToBinaryFunction(Result (*x)(Arg1, Arg2)) : mPtr(x) {}
    Result operator()(Arg1 x, Arg2 y) const
    {
        return mPtr(x, y);
    }
};

/// One of the @link s20_3_7_adaptors adaptors for function pointers@endlink.
template <class Arg1, class Arg2, class Result>
inline PointerToBinaryFunction<Arg1,Arg2,Result> PtrFun(Result (*x)(Arg1, Arg2))
{
    return PointerToBinaryFunction<Arg1,Arg2,Result>(x);
}
/** @}  */

template <class T>
struct Identity : public UnaryFunction<T,T>
{
    T& operator()(T& x) const { return x; }
    const T& operator()(const T& x) const { return x; }
};

template <class Pair>
struct Select1st : public UnaryFunction<Pair, typename Pair::FirstType>
{
    typename Pair::FirstType& operator()(Pair& x) const
    {
        return x.mFirst;
    }
    const typename Pair::FirstType& operator()(const Pair& x) const
    {
        return x.mFirst;
    }
};

template <class Pair>
struct Select2nd : public UnaryFunction<Pair, typename Pair::SecondType>
{
    typename Pair::SecondType& operator()(Pair& x) const
    {
        return x.mSecond;
    }
    const typename Pair::SecondType& operator()(const Pair& x) const
    {
        return x.mSecond;
    }
};

// 20.3.8 adaptors pointers members
/** @defgroup s20_3_8_memadaptors Adaptors for pointers to members
 *  There are a total of 16 = 2^4 function objects in this family.
 *   (1) Member functions taking no arguments vs member functions taking
 *        one argument.
 *   (2) Call through pointer vs call through reference.
 *   (3) Member function with void return type vs member function with
 *       non-void return type.
 *   (4) Const vs non-const member function.
 *
 *  Note that choice (3) is nothing more than a workaround: according
 *   to the draft, compilers should handle void and non-void the same way.
 *   This feature is not yet widely implemented, though.  You can only use
 *   member functions returning void if your compiler supports partial
 *   specialization.
 *
 *  All of this complexity is in the function objects themselves.  You can
 *   ignore it by using the helper function MemFun and MemFunRef,
 *   which create whichever type of adaptor is appropriate.
 *
 *  @{
*/
/// One of the @link s20_3_8_memadaptors adaptors for member pointers@endlink.
template <class Ret, class T>
class MemFun_t : public UnaryFunction<T*,Ret>
{
public:
    explicit MemFun_t(Ret (T::*pf)()) : mF(pf) {}
    Ret operator()(T* p) const { return (p->*mF)(); }
private:
    Ret (T::*mF)();
};

/// One of the @link s20_3_8_memadaptors adaptors for member pointers@endlink.
template <class Ret, class T>
class ConstMemFun_t : public UnaryFunction<const T*,Ret>
{
public:
    explicit ConstMemFun_t(Ret (T::*pf)() const) : mF(pf) {}
    Ret operator()(const T* p) const { return (p->*mF)(); }
private:
    Ret (T::*mF)() const;
};

/// One of the @link s20_3_8_memadaptors adaptors for member pointers@endlink.
template <class Ret, class T>
class MemFunRef_t : public UnaryFunction<T,Ret>
{
public:
    explicit MemFunRef_t(Ret (T::*pf)()) : mF(pf) {}
    Ret operator()(T& r) const { return (r.*mF)(); }
private:
    Ret (T::*mF)();
};

/// One of the @link s20_3_8_memadaptors adaptors for member pointers@endlink.
template <class Ret, class T>
class ConstMemFunRef_t : public UnaryFunction<T,Ret>
{
public:
    explicit ConstMemFunRef_t(Ret (T::*pf)() const) : mF(pf) {}
    Ret operator()(const T& r) const { return (r.*mF)(); }
private:
    Ret (T::*mF)() const;
};

/// One of the @link s20_3_8_memadaptors adaptors for member pointers@endlink.
template <class Ret, class T, class Arg>
class MemFun1_t : public BinaryFunction<T*,Arg,Ret>
{
public:
    explicit MemFun1_t(Ret (T::*pf)(Arg)) : mF(pf) {}
    Ret operator()(T* p, Arg x) const { return (p->*mF)(x); }
private:
    Ret (T::*mF)(Arg);
};

/// One of the @link s20_3_8_memadaptors adaptors for member pointers@endlink.
template <class Ret, class T, class Arg>
class ConstMemFun1_t : public BinaryFunction<const T*,Arg,Ret>
{
public:
    explicit ConstMemFun1_t(Ret (T::*pf)(Arg) const) : mF(pf) {}
    Ret operator()(const T* p, Arg x) const { return (p->*mF)(x); }
private:
    Ret (T::*mF)(Arg) const;
};

/// One of the @link s20_3_8_memadaptors adaptors for member pointers@endlink.
template <class Ret, class T, class Arg>
class MemFun1Ref_t : public BinaryFunction<T,Arg,Ret>
{
public:
    explicit MemFun1Ref_t(Ret (T::*pf)(Arg)) : mF(pf) {}
    Ret operator()(T& r, Arg x) const { return (r.*mF)(x); }
private:
    Ret (T::*mF)(Arg);
};

/// One of the @link s20_3_8_memadaptors adaptors for member pointers@endlink.
template <class Ret, class T, class Arg>
class ConstMemFun1Ref_t : public BinaryFunction<T,Arg,Ret>
{
public:
    explicit ConstMemFun1Ref_t(Ret (T::*pf)(Arg) const) : mF(pf) {}
    Ret operator()(const T& r, Arg x) const { return (r.*mF)(x); }
private:
    Ret (T::*mF)(Arg) const;
};

/// One of the @link s20_3_8_memadaptors adaptors for member pointers@endlink.
template <class T>
class MemFun_t<void, T> : public UnaryFunction<T*,void>
{
public:
    explicit MemFun_t(void (T::*pf)()) : mF(pf) {}
    void operator()(T* p) const { (p->*mF)(); }
private:
    void (T::*mF)();
};

/// One of the @link s20_3_8_memadaptors adaptors for member pointers@endlink.
template <class T>
class ConstMemFun_t<void, T> : public UnaryFunction<const T*,void>
{
public:
    explicit ConstMemFun_t(void (T::*pf)() const) : mF(pf) {}
    void operator()(const T* p) const { (p->*mF)(); }
private:
    void (T::*mF)() const;
};

/// One of the @link s20_3_8_memadaptors adaptors for member pointers@endlink.
template <class T>
class MemFunRef_t<void, T> : public UnaryFunction<T,void>
{
public:
    explicit MemFunRef_t(void (T::*pf)()) : mF(pf) {}
    void operator()(T& r) const { (r.*mF)(); }
private:
    void (T::*mF)();
};

/// One of the @link s20_3_8_memadaptors adaptors for member pointers@endlink.
template <class T>
class ConstMemFunRef_t<void, T> : public UnaryFunction<T,void>
{
public:
    explicit ConstMemFunRef_t(void (T::*pf)() const) : mF(pf) {}
    void operator()(const T& r) const { (r.*mF)(); }
private:
    void (T::*mF)() const;
};

/// One of the @link s20_3_8_memadaptors adaptors for member pointers@endlink.
template <class T, class Arg>
class MemFun1_t<void, T, Arg> : public BinaryFunction<T*,Arg,void>
{
public:
    explicit MemFun1_t(void (T::*pf)(Arg)) : mF(pf) {}
    void operator()(T* p, Arg x) const { (p->*mF)(x); }
private:
    void (T::*mF)(Arg);
};

/// One of the @link s20_3_8_memadaptors adaptors for member pointers@endlink.
template <class T, class Arg>
class ConstMemFun1_t<void, T, Arg> : public BinaryFunction<const T*,Arg,void>
{
public:
    explicit ConstMemFun1_t(void (T::*pf)(Arg) const) : mF(pf) {}
    void operator()(const T* p, Arg x) const { (p->*mF)(x); }
private:
    void (T::*mF)(Arg) const;
};

/// One of the @link s20_3_8_memadaptors adaptors for member pointers@endlink.
template <class T, class Arg>
class MemFun1Ref_t<void, T, Arg> : public BinaryFunction<T,Arg,void>
{
public:
    explicit MemFun1Ref_t(void (T::*pf)(Arg)) : mF(pf) {}
    void operator()(T& r, Arg x) const { (r.*mF)(x); }
private:
    void (T::*mF)(Arg);
};

/// One of the @link s20_3_8_memadaptors adaptors for member pointers@endlink.
template <class T, class Arg>
class ConstMemFun1Ref_t<void, T, Arg> : public BinaryFunction<T,Arg,void>
{
public:
    explicit ConstMemFun1Ref_t(void (T::*pf)(Arg) const) : mF(pf) {}
    void operator()(const T& r, Arg x) const { (r.*mF)(x); }
private:
    void (T::*mF)(Arg) const;
};


// Mem_fun adaptor helper functions.  There are only two:
// MemFun and MemFunRef.

template <class Ret, class T>
inline MemFun_t<Ret,T> MemFun(Ret (T::*f)())
{
    return MemFun_t<Ret,T>(f);
}

template <class Ret, class T>
inline ConstMemFun_t<Ret,T> MemFun(Ret (T::*f)() const)
{
    return ConstMemFun_t<Ret,T>(f);
}

template <class Ret, class T>
inline MemFunRef_t<Ret,T> MemFunRef(Ret (T::*f)())
{
    return MemFunRef_t<Ret,T>(f);
}

template <class Ret, class T>
inline ConstMemFunRef_t<Ret,T> MemFunRef(Ret (T::*f)() const)
{
    return ConstMemFunRef_t<Ret,T>(f);
}

template <class Ret, class T, class Arg>
inline MemFun1_t<Ret,T,Arg> MemFun(Ret (T::*f)(Arg))
{
    return MemFun1_t<Ret,T,Arg>(f);
}

template <class Ret, class T, class Arg>
inline ConstMemFun1_t<Ret,T,Arg> MemFun(Ret (T::*f)(Arg) const)
{
    return ConstMemFun1_t<Ret,T,Arg>(f);
}

template <class Ret, class T, class Arg>
inline MemFun1Ref_t<Ret,T,Arg> MemFunRef(Ret (T::*f)(Arg))
{
    return MemFun1Ref_t<Ret,T,Arg>(f);
}

template <class Ret, class T, class Arg>
inline ConstMemFun1Ref_t<Ret,T,Arg> MemFunRef(Ret (T::*f)(Arg) const)
{
    return ConstMemFun1Ref_t<Ret,T,Arg>(f);
}

/** @}  */

_ETL_NAMESPACE_END

#endif //__ETL_FUNCTION_H__
