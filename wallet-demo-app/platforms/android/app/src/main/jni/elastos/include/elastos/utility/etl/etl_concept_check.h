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

#ifndef __ELASTOS_CONCEPT_CHECK_H__
#define __ELASTOS_CONCEPT_CHECK_H__

#include "elastos/utility/etl/etl_def.h"
#include "elastos/utility/etl/etl_iterator_base_types.h"

_ETL_NAMESPACE_BEGIN

template <typename T>
void __sink_unused_warning(T) {}

// When the C-C code is in use, we would like this function to do as little
// as possible at runtime, use as few resources as possible, and hopefully
// be elided out of existence... hmmm.
template <typename Concept>
inline void __function_requires()
{
    void (Concept::*x)() = &Concept::Constraints;
    __sink_unused_warning(x);
}

// No definition: if this is referenced, there's a problem with
// the instantiating type not being one of the required integer types.
// Unfortunately, this results in a link-time error, not a compile-time error.
void __error_type_must_be_an_integer_type();
void __error_type_must_be_an_unsigned_integer_type();
void __error_type_must_be_a_signed_integer_type();

// ??? Should the "concept_checking*" structs begin with more than _ ?
#define _ELASTOS_CLASS_REQUIRES(_type_var, _ns, _concept) \
    typedef void (_ns::_concept <_type_var>::* _func##_type_var##_concept)(); \
    template <_func##_type_var##_concept _Tp1> \
    struct _concept_checking##_type_var##_concept { }; \
    typedef _concept_checking##_type_var##_concept< \
            &_ns::_concept <_type_var>::Constraints> \
    _concept_checking_typedef##_type_var##_concept

#define _ELASTOS_CLASS_REQUIRES2(_type_var1, _type_var2, _ns, _concept) \
    typedef void (_ns::_concept <_type_var1,_type_var2>::* _func##_type_var1##_type_var2##_concept)(); \
    template <_func##_type_var1##_type_var2##_concept _Tp1> \
    struct _concept_checking##_type_var1##_type_var2##_concept { }; \
    typedef _concept_checking##_type_var1##_type_var2##_concept< \
            &_ns::_concept <_type_var1,_type_var2>::Constraints> \
    _concept_checking_typedef##_type_var1##_type_var2##_concept

#define _ELASTOS_CLASS_REQUIRES3(_type_var1, _type_var2, _type_var3, _ns, _concept) \
    typedef void (_ns::_concept <_type_var1,_type_var2,_type_var3>::* _func##_type_var1##_type_var2##_type_var3##_concept)(); \
    template <_func##_type_var1##_type_var2##_type_var3##_concept _Tp1> \
    struct _concept_checking##_type_var1##_type_var2##_type_var3##_concept { }; \
    typedef _concept_checking##_type_var1##_type_var2##_type_var3##_concept< \
            &_ns::_concept <_type_var1,_type_var2,_type_var3>::Constraints>  \
    _concept_checking_typedef##_type_var1##_type_var2##_type_var3##_concept

#define _ELASTOS_CLASS_REQUIRES4(_type_var1, _type_var2, _type_var3, _type_var4, _ns, _concept) \
    typedef void (_ns::_concept <_type_var1,_type_var2,_type_var3,_type_var4>::* _func##_type_var1##_type_var2##_type_var3##_type_var4##_concept)(); \
    template <_func##_type_var1##_type_var2##_type_var3##_type_var4##_concept _Tp1> \
    struct _concept_checking##_type_var1##_type_var2##_type_var3##_type_var4##_concept { }; \
    typedef _concept_checking##_type_var1##_type_var2##_type_var3##_type_var4##_concept< \
            &_ns::_concept <_type_var1,_type_var2,_type_var3,_type_var4>::Constraints> \
    _concept_checking_typedef##_type_var1##_type_var2##_type_var3##_type_var4##_concept


template <typename T1, typename T2>
struct _Aux_require_same { };

template <typename T>
struct _Aux_require_same<T, T> { typedef T Type; };

template <typename T1, typename T2>
struct SameTypeConcept
{
    void Constraints() {
//        typedef typename _Aux_require_same<T1, T2>::Type Required;
    }
};

template <typename T>
struct IntegerConcept {
    void Constraints() {
        __error_type_must_be_an_integer_type();
    }
};

template <> struct IntegerConcept<short> { void Constraints() {} };
template <> struct IntegerConcept<unsigned short> { void Constraints(){} };
template <> struct IntegerConcept<int> { void Constraints() {} };
template <> struct IntegerConcept<unsigned int> { void Constraints() {} };
template <> struct IntegerConcept<long> { void Constraints() {} };
template <> struct IntegerConcept<unsigned long> { void Constraints() {} };
template <> struct IntegerConcept<long long> { void Constraints() {} };
template <> struct IntegerConcept<unsigned long long> { void Constraints() {} };

template <typename T>
struct SignedIntegerConcept {
    void Constraints() {
        __error_type_must_be_a_signed_integer_type();
    }
};

template <> struct SignedIntegerConcept<short> { void Constraints() {} };
template <> struct SignedIntegerConcept<int> { void Constraints() {} };
template <> struct SignedIntegerConcept<long> { void Constraints() {} };
template <> struct SignedIntegerConcept<long long> { void Constraints(){}};

template <typename T>
struct UnsignedIntegerConcept {
    void Constraints() {
        __error_type_must_be_an_unsigned_integer_type();
    }
};

template <> struct UnsignedIntegerConcept<unsigned short>
  { void Constraints() {} };
template <> struct UnsignedIntegerConcept<unsigned int>
  { void Constraints() {} };
template <> struct UnsignedIntegerConcept<unsigned long>
  { void Constraints() {} };
template <> struct UnsignedIntegerConcept<unsigned long long>
  { void Constraints() {} };

//===========================================================================
// Basic Concepts

template <typename T>
struct DefaultConstructibleConcept
{
    void Constraints() {
        T a = T();                // require default constructor and copy constructor.
        __sink_unused_warning(a);
    }
};

template <typename T>
struct AssignableConcept
{
    void Constraints() {
        mA = mB;                        // require assignment operator
        ConstConstraints(mA);
    }

    void ConstConstraints(const T& b) {
        mA = b;                   // const required for argument to assignment
    }

    T mA;
    T mB;
};

template <typename T>
struct CopyConstructibleConcept
{
    void Constraints() {
        T a(mB);                     // require copy constructor
        T* ptr = &a;      // require address of operator
        ConstConstraints(a);
        __sink_unused_warning(ptr);
    }

    void ConstConstraints(const T& a) {
        T c(a);           // require const copy constructor
        const T* ptr = &a; // require const address of operator
        __sink_unused_warning(c);
        __sink_unused_warning(ptr);
    }

    T mB;
};

// The SGI STL version of Assignable requires copy constructor and operator=
template <typename T>
struct SGIAssignableConcept
{
    void Constraints() {
        T b(mA);
        mA = mB;                        // require assignment operator
        ConstConstraints(mA);
        __sink_unused_warning(b);
    }

    void ConstConstraints(const T& b) {
        T c(b);
        mA = b;              // const required for argument to assignment
        __sink_unused_warning(c);
    }

    T mA;
    T mB;
};

template <typename From, typename To>
struct ConvertibleConcept
{
    void Constraints() {
        To y = mX;
        __sink_unused_warning(y);
    }

    From mX;
};

// The C++ standard requirements for many concepts talk about return
// types that must be "convertible to bool".  The problem with this
// requirement is that it leaves the door open for evil proxies that
// define things like operator|| with strange return types.  Two
// possible solutions are:
// 1) require the return type to be exactly bool
// 2) stay with convertible to bool, and also
//    specify stuff about all the logical operators.
// For now we just test for convertible to bool.
template <typename T>
void __aux_require_boolean_expr(const T& t) {
    Boolean x = t;
    __sink_unused_warning(x);
}

// FIXME
template <typename T>
struct EqualityComparableConcept
{
    void Constraints() {
        __aux_require_boolean_expr(mA == mB);
        __aux_require_boolean_expr(mA != mB);
    }

    T mA, mB;
};

template <typename T>
struct LessThanComparableConcept
{
    void Constraints() {
        __aux_require_boolean_expr(mA < mB);
    }

    T mA, mB;
};

// This is equivalent to SGI STL's LessThanComparable.
template <typename T>
struct ComparableConcept
{
    void Constraints() {
        __aux_require_boolean_expr(mA < mB);
        __aux_require_boolean_expr(mA > mB);
        __aux_require_boolean_expr(mA <= mB);
        __aux_require_boolean_expr(mA >= mB);
    }

    T mA, mB;
};

#define _ELASTOS_DEFINE_BINARY_PREDICATE_OP_CONSTRAINT(OP,NAME) \
    template <typename First, typename Second> \
    struct NAME { \
        void Constraints() { (void)__Constraints(); } \
        Boolean __Constraints() {  \
            return  mA OP mB; \
        } \
        First mA; \
        Second mB; \
    }

#define _ELASTOS_DEFINE_BINARY_OPERATOR_CONSTRAINT(OP,NAME) \
    template <typename Ret, typename First, typename Second> \
    struct NAME { \
        void Constraints() { (void)__Constraints(); } \
        Ret __Constraints() {  \
            return mA OP mB; \
        } \
        First mA; \
        Second mB; \
    }

_ELASTOS_DEFINE_BINARY_PREDICATE_OP_CONSTRAINT(==, EqualOpConcept);
_ELASTOS_DEFINE_BINARY_PREDICATE_OP_CONSTRAINT(!=, NotEqualOpConcept);
_ELASTOS_DEFINE_BINARY_PREDICATE_OP_CONSTRAINT(<, LessThanOpConcept);
_ELASTOS_DEFINE_BINARY_PREDICATE_OP_CONSTRAINT(<=, LessEqualOpConcept);
_ELASTOS_DEFINE_BINARY_PREDICATE_OP_CONSTRAINT(>, GreaterThanOpConcept);
_ELASTOS_DEFINE_BINARY_PREDICATE_OP_CONSTRAINT(>=, GreaterEqualOpConcept);

_ELASTOS_DEFINE_BINARY_OPERATOR_CONSTRAINT(+, PlusOpConcept);
_ELASTOS_DEFINE_BINARY_OPERATOR_CONSTRAINT(*, TimesOpConcept);
_ELASTOS_DEFINE_BINARY_OPERATOR_CONSTRAINT(/, DivideOpConcept);
_ELASTOS_DEFINE_BINARY_OPERATOR_CONSTRAINT(-, SubtractOpConcept);
_ELASTOS_DEFINE_BINARY_OPERATOR_CONSTRAINT(%, ModOpConcept);

#undef _ELASTOS_DEFINE_BINARY_PREDICATE_OP_CONSTRAINT
#undef _ELASTOS_DEFINE_BINARY_OPERATOR_CONSTRAINT

//===========================================================================
// Function Object Concepts

template <typename Func, typename Return>
struct GeneratorConcept
{
    void Constraints() {
        const Return& r = mF();// require operator() member function
        __sink_unused_warning(r);
    }

    Func mF;
};

template <typename Func>
struct GeneratorConcept<Func,void>
{
    void Constraints() {
        mF();                            // require operator() member function
    }

    Func mF;
};

template <typename Func, typename Return, typename Arg>
struct UnaryFunctionConcept
{
    void Constraints() {
        mR = mF(mArg);                  // require operator()
    }

    Func mF;
    Arg mArg;
    Return mR;
};

template <typename Func, typename Arg>
struct UnaryFunctionConcept<Func, void, Arg> {
    void Constraints() {
        mF(mArg);                       // require operator()
    }

    Func mF;
    Arg mArg;
};

template <typename Func, typename Return, typename First, typename Second>
struct BinaryFunctionConcept
{
    void Constraints() {
        mR = mF(mFirst, mSecond);     // require operator()
    }

    Func mF;
    First mFirst;
    Second mSecond;
    Return mR;
};

template <typename Func, typename First, typename Second>
struct BinaryFunctionConcept<Func, void, First, Second>
{
    void Constraints() {
        mF(mFirst, mSecond);           // require operator()
    }

    Func mF;
    First mFirst;
    Second mSecond;
};

template <typename Func, typename Arg>
struct UnaryPredicateConcept
{
    void Constraints() {
        __aux_require_boolean_expr(mF(mArg)); // require op() returning bool
    }

    Func mF;
    Arg mArg;
};

template <typename Func, typename First, typename Second>
struct BinaryPredicateConcept
{
    void Constraints() {
        __aux_require_boolean_expr(mF(mFirst, mSecond)); // require op() returning bool
    }

    Func mF;
    First mFirst;
    Second mSecond;
};

// use this when functor is used inside a container class like std::set
template <typename Func, typename First, typename Second>
struct ConstBinaryPredicateConcept {
    void Constraints() {
        ConstConstraints(mF);
    }
    void ConstConstraints(const Func& fun) {
        __function_requires<BinaryPredicateConcept<Func, First, Second> >();
        // operator() must be a const member function
        __aux_require_boolean_expr(fun(mFirst, mSecond));
    }

    Func mF;
    First mFirst;
    Second mSecond;
};

//===========================================================================
// Iterator Concepts

template <typename T>
struct TrivialIteratorConcept
{
    void Constraints() {
        __function_requires<DefaultConstructibleConcept<T> >();
        __function_requires<AssignableConcept<T> >();
        __function_requires<EqualityComparableConcept<T> >();
//      typedef typename std::iterator_traits<_Tp>::value_type _V;
        (void)*mI;                       // require dereference operator
    }

    T mI;
};

template <typename T>
struct MutableTrivialIteratorConcept
{
    void Constraints() {
        __function_requires<TrivialIteratorConcept<T> >();
        *mI = *mJ;                      // require dereference and assignment
    }

    T mI, mJ;
};

template <typename T>
struct InputIteratorConcept
{
    void Constraints() {
        __function_requires<TrivialIteratorConcept<T> >();
        // require iterator_traits typedef's
#if 0
        typedef typename _ETL IteratorTraits<T>::DifferenceType D;
//      __function_requires< _SignedIntegerConcept<_D> >();
        typedef typename _ETL IteratorTraits<T>::Reference R;
        typedef typename _ETL IteratorTraits<T>::Pointer Pt;
        typedef typename _ETL IteratorTraits<T>::IteratorCategory Cat;
#endif
        __function_requires<ConvertibleConcept<
                typename _ETL IteratorTraits<T>::IteratorCategory,
                _ETL InputIteratorTag> >();
        ++mI;                            // require preincrement operator
        mI++;                            // require postincrement operator
    }

    T mI;
};

template <typename T, typename ValueT>
struct OutputIteratorConcept
{
    void Constraints() {
        __function_requires<AssignableConcept<T> >();
        ++mI;                            // require preincrement operator
        mI++;                            // require postincrement operator
        *mI++ = mT;                      // require postincrement and assignment
    }

    T mI;
    ValueT mT;
};

template <typename T>
struct ForwardIteratorConcept
{
    void Constraints() {
        __function_requires<InputIteratorConcept<T> >();
        __function_requires<ConvertibleConcept<
                typename _ETL IteratorTraits<T>::IteratorCategory,
                _ETL ForwardIteratorTag> >();
        typedef typename _ETL IteratorTraits<T>::Reference R;
        R r = *mI;
        __sink_unused_warning(r);
    }

    T mI;
};

template <typename T>
struct MutableForwardIteratorConcept
{
    void Constraints() {
        __function_requires<ForwardIteratorConcept<T> >();
        *mI++ = *mI;                    // require postincrement and assignment
    }

    T mI;
};

template <typename T>
struct BidirectionalIteratorConcept
{
    void Constraints() {
        __function_requires<ForwardIteratorConcept<T> >();
        __function_requires<ConvertibleConcept<
                typename _ETL IteratorTraits<T>::IteratorCategory,
                _ETL BidirectionalIteratorTag> >();
        --mI;                            // require predecrement operator
        mI--;                            // require postdecrement operator
    }

    T mI;
};

template <typename T>
struct MutableBidirectionalIteratorConcept
{
    void Constraints() {
        __function_requires<BidirectionalIteratorConcept<T> >();
        __function_requires<MutableForwardIteratorConcept<T> >();
        *mI-- = *mI;                    // require postdecrement and assignment
    }

    T mI;
};

template <typename T>
struct RandomAccessIteratorConcept
{
    void Constraints() {
        __function_requires<BidirectionalIteratorConcept<T> >();
        __function_requires<ComparableConcept<T> >();
        __function_requires<ConvertibleConcept<
                typename _ETL IteratorTraits<T>::IteratorCategory,
                _ETL RandomAccessIteratorTag> >();
        // ??? We don't use _R, are we just checking for "referenceability"?
//        typedef typename _ETL IteratorTraits<T>::Reference R;

        mI += mN;                       // require assignment addition operator
        mI = mI + mN; mI = mN + mI;     // require addition with difference type
        mI -= mN;                       // require assignment subtraction op
        mI = mI - mN;                   // require subtraction with
                                        //            difference type
        mN = mI - mJ;                   // require difference operator
        (void)mI[mN];                   // require element access operator
    }

    T mA, mB;
    T mI, mJ;
    typename _ETL IteratorTraits<T>::DifferenceType mN;
};

template <typename T>
struct MutableRandomAccessIteratorConcept
{
    void Constraints() {
        __function_requires<RandomAccessIteratorConcept<T> >();
        __function_requires<MutableBidirectionalIteratorConcept<T> >();
        mI[mN] = *mI;                  // require element access and assignment
    }

    T mI;
    typename _ETL IteratorTraits<T>::DifferenceType mN;
};

//===========================================================================
// Container Concepts

template <typename Container>
struct ContainerConcept
{
    typedef typename Container::ValueType       ValueType;
    typedef typename Container::DifferenceType  DifferenceType;
    typedef typename Container::SizeType        SizeType;
    typedef typename Container::ConstReference  ConstReference;
    typedef typename Container::ConstPointer    ConstPointer;
    typedef typename Container::ConstIterator   ConstIterator;

    void Constraints() {
        __function_requires<InputIteratorConcept<ConstIterator> >();
        __function_requires<AssignableConcept<Container> >();
        const Container c;
        mI = c.Begin();
        mI = c.End();
        mN = c.GetSize();
        mN = c.GetMaxSize();
        mB = c.IsEmpty();
    }

    Boolean mB;
    ConstIterator mI;
    SizeType mN;
};

template <typename Container>
struct MutableContainerConcept
{
    typedef typename Container::ValueType   ValueType;
    typedef typename Container::Reference   Reference;
    typedef typename Container::Iterator    Iterator;
    typedef typename Container::Pointer     Pointer;

    void Constraints() {
        __function_requires<ContainerConcept<Container> >();
        __function_requires<AssignableConcept<ValueType> >();
        __function_requires<InputIteratorConcept<Iterator> >();

        mI = mC.Begin();
        mI = mC.End();
        mC.Swap(mC2);
    }

    Iterator mI;
    Container mC, mC2;
};

template <typename ForwardContainer>
struct ForwardContainerConcept
{
    void Constraints() {
        __function_requires<ContainerConcept<ForwardContainer> >();
        typedef typename ForwardContainer::ConstIterator ConstIterator;
        __function_requires<ForwardIteratorConcept<ConstIterator> >();
    }
};

template <typename ForwardContainer>
struct MutableForwardContainerConcept
{
    void Constraints() {
        __function_requires<ForwardContainerConcept<ForwardContainer> >();
        __function_requires<MutableContainerConcept<ForwardContainer> >();
        typedef typename ForwardContainer::Iterator Iterator;
        __function_requires<MutableForwardIteratorConcept<Iterator> >();
    }
};

template <typename ReversibleContainer>
struct ReversibleContainerConcept
{
    typedef typename ReversibleContainer::ConstIterator         ConstIterator;
    typedef typename ReversibleContainer::ConstReverseIterator  ConstReverseIterator;

    void Constraints() {
        __function_requires<ForwardContainerConcept<ReversibleContainer> >();
        __function_requires<BidirectionalIteratorConcept<ConstIterator> >();
        __function_requires<BidirectionalIteratorConcept<ConstReverseIterator> >();

        const ReversibleContainer c;
        ConstReverseIterator i = c.RBegin();
        i = c.REnd();
    }
};

template <typename ReversibleContainer>
struct MutableReversibleContainerConcept
{
    typedef typename ReversibleContainer::Iterator          Iterator;
    typedef typename ReversibleContainer::ReverseIterator   ReverseIterator;

    void Constraints() {
        __function_requires<ReversibleContainerConcept<ReversibleContainer> >();
        __function_requires<MutableForwardContainerConcept<ReversibleContainer> >();
        __function_requires<MutableBidirectionalIteratorConcept<Iterator> >();
        __function_requires<MutableBidirectionalIteratorConcept<ReverseIterator> >();

        ReverseIterator i = mC.RBegin();
        i = mC.REnd();
    }

    ReversibleContainer mC;
};

template <typename RandomAccessContainer>
struct RandomAccessContainerConcept
{
    typedef typename RandomAccessContainer::SizeType                SizeType;
    typedef typename RandomAccessContainer::ConstReference          ConstReference;
    typedef typename RandomAccessContainer::ConstIterator           ConstIterator;
    typedef typename RandomAccessContainer::ConstReverseIterator    ConstReverseIterator;

    void Constraints() {
        __function_requires<ReversibleContainerConcept<RandomAccessContainer> >();
        __function_requires<RandomAccessIteratorConcept<ConstIterator> >();
        __function_requires<RandomAccessIteratorConcept<ConstReverseIterator> >();

        const RandomAccessContainer c;
        ConstReference r = c[mN];
        __sink_unused_warning(r);
    }

    SizeType mN;
};

template <typename RandomAccessContainer>
struct MutableRandomAccessContainerConcept
{
    typedef typename RandomAccessContainer::SizeType        SizeType;
    typedef typename RandomAccessContainer::Reference       Reference;
    typedef typename RandomAccessContainer::Iterator        Iterator;
    typedef typename RandomAccessContainer::ReverseIterator ReverseIterator;

    void Constraints() {
        __function_requires<RandomAccessContainerConcept<RandomAccessContainer> >();
        __function_requires<MutableReversibleContainerConcept<RandomAccessContainer> >();
        __function_requires<MutableRandomAccessIteratorConcept<Iterator> >();
        __function_requires<MutableRandomAccessIteratorConcept<ReverseIterator> >();

        Reference r = mC[mI];
        __sink_unused_warning(r);
    }

    SizeType mI;
    RandomAccessContainer mC;
};

// A Sequence is inherently mutable
template <typename Sequence>
struct SequenceConcept
{
    typedef typename Sequence::Reference        Reference;
    typedef typename Sequence::ConstReference   ConstReference;

    void Constraints() {
        // Matt Austern's book puts DefaultConstructible here, the C++
        // standard places it in Container
        //    function_requires< DefaultConstructible<Sequence> >();
        __function_requires<MutableForwardContainerConcept<Sequence> >();
        __function_requires<DefaultConstructibleConcept<Sequence> >();

        Sequence c(mN), c2(mN, mT), c3(mFirst, mLast);

        c.Insert(mP, mT);
        c.Insert(mP, mN, mT);
        c.Insert(mP, mFirst, mLast);

        c.Erase(mP);
        c.Erase(mP, mQ);

        Reference r = c.GetFront();

        ConstConstraints(c);
        __sink_unused_warning(c2);
        __sink_unused_warning(c3);
        __sink_unused_warning(r);
    }

    void ConstConstraints(const Sequence& c) {
        ConstReference r = c.GetFront();
        __sink_unused_warning(r);
    }

    typename Sequence::ValueType mT;
    typename Sequence::SizeType mN;
    typename Sequence::ValueType *mFirst, *mLast;
    typename Sequence::Iterator mP, mQ;
};

template <typename FrontInsertionSequence>
struct FrontInsertionSequenceConcept
{
    void Constraints() {
        __function_requires<SequenceConcept<FrontInsertionSequence> >();

        mC.PushFront(mT);
        mC.PopFront();
    }

    FrontInsertionSequence mC;
    typename FrontInsertionSequence::ValueType mT;
};

template <typename BackInsertionSequence>
struct BackInsertionSequenceConcept
{
    typedef typename BackInsertionSequence::Reference       Reference;
    typedef typename BackInsertionSequence::ConstReference  ConstReference;

    void Constraints() {
        __function_requires<SequenceConcept<BackInsertionSequence> >();

        mC.PushBack(mT);
        mC.PopBack();
        Reference r = mC.GetBack();
        __sink_unused_warning(r);
    }

    void ConstConstraints(const BackInsertionSequence& c) {
        ConstReference r = c.GetBack();
        __sink_unused_warning(r);
    };

    BackInsertionSequence mC;
    typename BackInsertionSequence::ValueType mT;
};

template <typename AssociativeContainer>
struct AssociativeContainerConcept
{
    void Constraints() {
        __function_requires<ForwardContainerConcept<AssociativeContainer> >();
        __function_requires<DefaultConstructibleConcept<AssociativeContainer> >();

        mI = mC.Find(mK);
        mR = mC.EqualRange(mK);
        mC.Erase(mK);
        mC.Erase(mI);
        mC.Erase(mR.first, mR.second);
        ConstConstraints(mC);
    }

    void ConstConstraints(const AssociativeContainer& c) {
        mCi = c.Find(mK);
        mN = c.GetCount(mK);
        mCr = c.EqualRange(mK);
    }

    typedef typename AssociativeContainer::Iterator Iterator;
    typedef typename AssociativeContainer::ConstIterator ConstIterator;

    AssociativeContainer mC;
    Iterator mI;
    _ETL Pair<Iterator,Iterator> mR;
    ConstIterator mCi;
    _ETL Pair<ConstIterator, ConstIterator> mCr;
    typename AssociativeContainer::KeyType mK;
    typename AssociativeContainer::SizeType mN;
};

template <typename UniqueAssociativeContainer>
struct UniqueAssociativeContainerConcept
{
    void Constraints() {
        __function_requires<AssociativeContainerConcept<UniqueAssociativeContainer> >();

        UniqueAssociativeContainer c(mFirst, mLast);

        mPosFlag = c.Insert(mT);
        c.Insert(mFirst, mLast);
    }

    _ETL Pair<typename UniqueAssociativeContainer::Iterator, Boolean> mPosFlag;
    typename UniqueAssociativeContainer::ValueType mT;
    typename UniqueAssociativeContainer::ValueType *mFirst, *mLast;
};

template <typename MultipleAssociativeContainer>
struct MultipleAssociativeContainerConcept
{
    void Constraints() {
        __function_requires<AssociativeContainerConcept<MultipleAssociativeContainer> >();

        MultipleAssociativeContainer c(mFirst, mLast);

        mPos = c.Insert(mT);
        c.Insert(mFirst, mLast);
        __sink_unused_warning(mPos);
    }

    typename MultipleAssociativeContainer::Iterator mPos;
    typename MultipleAssociativeContainer::ValueType mT;
    typename MultipleAssociativeContainer::ValueType *mFirst, *mLast;
};

template <typename SimpleAssociativeContainer>
struct SimpleAssociativeContainerConcept
{
    void Constraints() {
        __function_requires<AssociativeContainerConcept<SimpleAssociativeContainer> >();
//        typedef typename SimpleAssociativeContainer::KeyType KeyType;
//        typedef typename SimpleAssociativeContainer::ValueType ValueType;
//        typedef typename _Aux_require_same<KeyType, ValueType>::Type Requqired;
    }
};

template <typename SimpleAssociativeContainer>
struct PairAssociativeContainerConcept
{
    void Constraints() {
        __function_requires<AssociativeContainerConcept<SimpleAssociativeContainer> >();
//        typedef typename SimpleAssociativeContainer::KeyType KeyType;
//        typedef typename SimpleAssociativeContainer::ValueType ValueType;
//        typedef typename SimpleAssociativeContainer::MappedType MappedType;
//        typedef _ETL Pair<const KeyType, MappedType> RequiredValueType;
//        typedef typename _Aux_require_same<ValueType, RequiredValueType>::Type Required;
    }
};

template <typename SortedAssociativeContainer>
struct SortedAssociativeContainerConcept
{
    void Constraints() {
        __function_requires<AssociativeContainerConcept<SortedAssociativeContainer> >();
        __function_requires<ReversibleContainerConcept<SortedAssociativeContainer> >();

        SortedAssociativeContainer c(mKc),
                                   c2(mFirst, mLast),
                                   c3(mFirst, mLast, mKc);

        mP = c.GetUpperBound(mK);
        mP = c.GetLowerBound(mK);
        mR = c.EqualRange(mK);

        c.Insert(mP, mT);
        __sink_unused_warning(c2);
        __sink_unused_warning(c3);
    }

    void ConstConstraints(const SortedAssociativeContainer& c) {
        mKc = c.KeyComp();
        mVc = c.ValueComp();

        mCp = c.GetUpperBound(mK);
        mCp = c.GetLowerBound(mK);
        mCp = c.EqualRange(mK);
    }

    typename SortedAssociativeContainer::KeyCompare mKc;
    typename SortedAssociativeContainer::ValueCompare mVc;
    typename SortedAssociativeContainer::ValueType mT;
    typename SortedAssociativeContainer::KeyType mK;
    typedef typename SortedAssociativeContainer::Iterator Iterator;
    typedef typename SortedAssociativeContainer::ConstIterator ConstIterator;

    Iterator mP;
    ConstIterator mCp;
    _ETL Pair<Iterator,Iterator> mR;
    _ETL Pair<ConstIterator,ConstIterator> mCr;
    typename SortedAssociativeContainer::ValueType *mFirst, *mLast;
};

  // HashedAssociativeContainer

_ETL_NAMESPACE_END

#endif //__ELASTOS_CONCEPT_CHECK_H__
