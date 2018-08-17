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

#ifndef __ETL_ALGOBASE_H__
#define __ETL_ALGOBASE_H__

#include "elastos/utility/etl/etl_pair.h"
#include "elastos/utility/etl/etl_type_traits.h"
#include "elastos/utility/etl/etl_iterator_base_types.h"
#include "elastos/utility/etl/etl_iterator_base_funcs.h"
#include "elastos/utility/etl/etl_iterator.h"
#include "elastos/utility/etl/ConceptCheck.h"


_ETL_NAMESPACE_BEGIN


// swap and iter_swap

/**
 *  @brief Swaps the contents of two iterators.
 *  @param  a  An iterator.
 *  @param  b  Another iterator.
 *  @return   Nothing.
 *
 *  This function swaps the values pointed to by two iterators, not the
 *  iterators themselves.
*/
template<typename ForwardIterator1, typename ForwardIterator2>
inline void
IterSwap(ForwardIterator1 a, ForwardIterator2 b)
{
    typedef typename IteratorTraits<ForwardIterator1>::ValueType ValueType1;
    typedef typename IteratorTraits<ForwardIterator2>::ValueType ValueType2;

    // concept requirements
    Concept_FunctionRequires(MutableForwardIteratorConcept<ForwardIterator1>)
    Concept_FunctionRequires(MutableForwardIteratorConcept<ForwardIterator2>)
    Concept_FunctionRequires(ConvertibleConcept<ValueType1, ValueType2>)
    Concept_FunctionRequires(ConvertibleConcept<ValueType2, ValueType1>)

    ValueType1 tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 *  @brief Swaps two values.
 *  @param  a  A thing of arbitrary type.
 *  @param  b  Another thing of arbitrary type.
 *  @return   Nothing.
 *
 *  This is the simple classic generic implementation.  It will work on
 *  any type which has a copy constructor and an assignment operator.
*/
template<typename T>
inline void
Swap(T& a, T& b)
{
    // concept requirements
    Concept_FunctionRequires(SGIAssignableConcept<T>)

    T tmp = a;
    a = b;
    b = tmp;
}

//--------------------------------------------------
// min and max

#undef Min
#undef Max

/**
 *  @brief This does what you think it does.
 *  @param  a  A thing of arbitrary type.
 *  @param  b  Another thing of arbitrary type.
 *  @return   The lesser of the parameters.
 *
 *  This is the simple classic generic implementation.  It will work on
 *  temporary expressions, since they are only evaluated once, unlike a
 *  preprocessor macro.
*/
template<typename T>
inline const T&
Min(const T& a, const T& b)
{
    // concept requirements
    Concept_FunctionRequires(LessThanComparableConcept<T>)
    //return b < a ? b : a;
    if (b < a) return b;
    return a;
}

/**
 *  @brief This does what you think it does.
 *  @param  a  A thing of arbitrary type.
 *  @param  b  Another thing of arbitrary type.
 *  @return   The greater of the parameters.
 *
 *  This is the simple classic generic implementation.  It will work on
 *  temporary expressions, since they are only evaluated once, unlike a
 *  preprocessor macro.
*/
template<typename T>
inline const T&
Max(const T& a, const T& b)
{
    // concept requirements
    Concept_FunctionRequires(LessThanComparableConcept<T>)
    //return  a < b ? b : a;
    if (a < b) return b;
    return a;
}

/**
 *  @brief This does what you think it does.
 *  @param  a  A thing of arbitrary type.
 *  @param  b  Another thing of arbitrary type.
 *  @param  comp  A @link s20_3_3_comparisons comparison functor@endlink.
 *  @return   The lesser of the parameters.
 *
 *  This will work on temporary expressions, since they are only evaluated
 *  once, unlike a preprocessor macro.
*/
template<typename T, typename Compare>
inline const T&
Min(const T& a, const T& b, Compare comp)
{
    //return comp(b, a) ? b : a;
    if (comp(b, a)) return b;
    return a;
}

/**
 *  @brief This does what you think it does.
 *  @param  a  A thing of arbitrary type.
 *  @param  b  Another thing of arbitrary type.
 *  @param  comp  A @link s20_3_3_comparisons comparison functor@endlink.
 *  @return   The greater of the parameters.
 *
 *  This will work on temporary expressions, since they are only evaluated
 *  once, unlike a preprocessor macro.
*/
template<typename T, typename Compare>
inline const T&
Max(const T& a, const T& b, Compare comp)
{
    //return comp(a, b) ? b : a;
    if (comp(a, b)) return b;
    return a;
}


//--------------------------------------
// Copy

// All of these auxiliary functions serve two purposes.  (1) Replace
// calls to copy with memmove whenever possible.  (Memmove, not memcpy,
// because the input and output ranges are permitted to overlap.)
// (2) If we're using random access iterators, then write the loop as
// a for loop with an explicit count.

template <typename InputIterator, typename OutputIterator>
inline OutputIterator Copy(
        InputIterator first, InputIterator last, OutputIterator result, InputIteratorTag)
{
    for (; first != last; ++result, ++first) {
        *result = *first;
    }
    return result;
}

template <typename RandomAccessIterator, typename OutputIterator>
inline OutputIterator Copy(
        RandomAccessIterator first, RandomAccessIterator last,
        OutputIterator result, RandomAccessIteratorTag)
{
    typedef typename IteratorTraits<RandomAccessIterator>::DifferenceType Distance;
    for (Distance n = last - first; n > 0; --n) {
        *result = *first;
        ++first;
        ++result;
    }
    return result;
}

template <typename T>
inline T* CopyTrivial(const T* first, const T* last, T* result)
{
    memmove(result, first, sizeof(T) * (last - first));
    return result + (last - first);
}

template <typename InputIterator, typename OutputIterator>
inline OutputIterator CopyAux2(
        InputIterator first, InputIterator last, OutputIterator result, FalseType)
{
    return Copy(first, last, result, IteratorCategory(first));
}

template <typename InputIterator, typename OutputIterator>
inline OutputIterator CopyAux2(
        InputIterator first, InputIterator last, OutputIterator result, TrueType)
{
    return Copy(first, last, result, IteratorCategory(first));
}

template <typename T>
inline T* CopyAux2(T* first, T* last, T* result, TrueType)
{
    return CopyTrivial(first, last, result);
}

template <typename T>
inline T* CopyAux2(const T* first, const T* last, T* result, TrueType)
{
    return CopyTrivial(first, last, result);
}

template <typename InputIterator, typename OutputIterator>
inline OutputIterator CopyNi2(
        InputIterator first, InputIterator last, OutputIterator result, TrueType)
{
    typedef typename IteratorTraits<InputIterator>::ValueType ValueType;
    typedef typename TypeTraits<ValueType>::HasTrivialAssignmentOperator Trivial;
    return OutputIterator(CopyAux2(first, last, result.GetBase(), Trivial()));
}

template <typename InputIterator, typename OutputIterator>
inline OutputIterator CopyNi2(
        InputIterator first, InputIterator last, OutputIterator result, FalseType)
{
    typedef typename IteratorTraits<InputIterator>::ValueType ValueType;
    typedef typename TypeTraits<ValueType>::HasTrivialAssignmentOperator Trivial;
    return CopyAux2(first, last, result, Trivial());
}

template <typename InputIterator, typename OutputIterator>
inline OutputIterator CopyNi1(
        InputIterator first, InputIterator last, OutputIterator result, TrueType)
{
    typedef typename IsNormalIterator<OutputIterator>::Normal Normal;
    return CopyNi2(first.GetBase(), last.GetBase(), result, Normal());
}

template <typename InputIterator, typename OutputIterator>
inline OutputIterator CopyNi1(
        InputIterator first, InputIterator last, OutputIterator result, FalseType)
{
    typedef typename IsNormalIterator<OutputIterator>::Normal Normal;
    return CopyNi2(first, last, result, Normal());
}

template <typename InputIterator, typename OutputIterator>
inline OutputIterator Copy(
        InputIterator first, InputIterator last, OutputIterator result)
{
    //concept requirements
    Concept_FunctionRequires(InputIteratorConcept<InputIterator>)
    Concept_FunctionRequires(OutputIteratorConcept<OutputIterator,
            typename IteratorTraits<InputIterator>::ValueType>)

    typedef typename IsNormalIterator<InputIterator>::Normal Normal;
    return CopyNi1(first, last, result, Normal());
}


//--------------------------------------------------
// copy_backward

template<typename BidirectionalIterator1, typename BidirectionalIterator2>
inline BidirectionalIterator2
CopyBackward(BidirectionalIterator1 first, BidirectionalIterator1 last,
        BidirectionalIterator2 result, BidirectionalIteratorTag)
{
    while (first != last) {
        *--result = *--last;
    }

    return result;
}

template<typename RandomAccessIterator, typename BidirectionalIterator>
inline BidirectionalIterator
CopyBackward(RandomAccessIterator first, RandomAccessIterator last,
        BidirectionalIterator result, RandomAccessIteratorTag)
{
    typename IteratorTraits<RandomAccessIterator>::DifferenceType n;
    for (n = last - first; n > 0; --n) {
        *--result = *--last;
    }

    return result;
}


// This dispatch class is a workaround for compilers that do not
// have partial ordering of function templates.  All we're doing is
// creating a specialization so that we can turn a call to copy_backward
// into a memmove whenever possible.

template<typename BidirectionalIterator1, typename BidirectionalIterator2,
         typename BoolType>
struct CopyBackwardDispatch
{
    static BidirectionalIterator2
    Copy(BidirectionalIterator1 first, BidirectionalIterator1 last,
            BidirectionalIterator2 result)
    {
        return CopyBackward(first, last, result, IteratorCategory(first));
    }
};

template<typename T>
struct CopyBackwardDispatch<T*, T*, TrueType>
{
    static T*
    Copy(const T* first, const T* last, T* result)
    {
        const ptrdiff_t num = last - first;
        memmove(result - num, first, sizeof(T) * num);
        return result - num;
    }
};

template<typename T>
struct CopyBackwardDispatch<const T*, T*, TrueType>
{
    static T*
    Copy(const T* first, const T* last, T* result)
    {
	    return  CopyBackwardDispatch<T*, T*, TrueType>::Copy(first, last, result);
    }
};

template<typename BI1, typename BI2>
inline BI2
CopyBackwardAux(BI1 first, BI1 last, BI2 result)
{
    typedef typename TypeTraits<typename IteratorTraits<BI2>::ValueType>
            ::HasTrivialAssignmentOperator Trivial;
    return CopyBackwardDispatch<BI1, BI2, Trivial>::Copy(first, last, result);
}

template <typename BI1, typename BI2>
inline BI2
CopyBackwardOutputNormalIterator(BI1 first, BI1 last, BI2 result, TrueType)
{
    return BI2(CopyBackwardAux(first, last, result.GetBase()));
}

template <typename BI1, typename BI2>
inline BI2
CopyBackwardOutputNormalIterator(BI1 first, BI1 last, BI2 result, FalseType)
{
    return CopyBackwardAux(first, last, result);
}

template <typename BI1, typename BI2>
inline BI2
CopyBackwardInputNormalIterator(BI1 first, BI1 last, BI2 result, TrueType)
{
    typedef typename IsNormalIterator<BI2>::Normal Normal;
    return CopyBackwardOutputNormalIterator(first.GetBase(), last.GetBase(),
            result, Normal());
}

template <typename BI1, typename BI2>
inline BI2
CopyBackwardInputNormalIterator(BI1 first, BI1 last, BI2 result, FalseType)
{
    typedef typename IsNormalIterator<BI2>::Normal Normal;
    return CopyBackwardOutputNormalIterator(first, last, result, Normal());
}

/**
 *  @brief Copies the range [first,last) into result.
 *  @param  first  An input iterator.
 *  @param  last   An input iterator.
 *  @param  result An output iterator.
 *  @return   result - (first - last)
 *
 *  The function has the same effect as copy, but starts at the end of the
 *  range and works its way to the start, returning the start of the result.
 *  This inline function will boil down to a call to @c memmove whenever
 *  possible.  Failing that, if random access iterators are passed, then the
 *  loop count will be known (and therefore a candidate for compiler
 *  optimizations such as unrolling).
*/
template <typename BI1, typename BI2>
inline BI2
CopyBackward(BI1 first, BI1 last, BI2 result)
{
    // concept requirements
    Concept_FunctionRequires(BidirectionalIteratorConcept<BI1>)
    Concept_FunctionRequires(MutableBidirectionalIteratorConcept<BI2>)
    Concept_FunctionRequires(ConvertibleConcept<
            typename IteratorTraits<BI1>::ValueType,
            typename IteratorTraits<BI2>::ValueType>)

    typedef typename IsNormalIterator<BI1>::Normal Normal;
    return CopyBackwardInputNormalIterator(first, last, result, Normal());
}


//--------------------------------------------------
// fill and fill_n

/**
 *  @brief Fills the range [first,last) with copies of value.
 *  @param  first  A forward iterator.
 *  @param  last   A forward iterator.
 *  @param  value  A reference-to-const of arbitrary type.
 *  @return   Nothing.
 *
 *  This function fills a range with copies of the same value.  For one-byte
 *  types filling contiguous areas of memory, this becomes an inline call to
 *  @c memset.
*/
template<typename ForwardIterator, typename T>
void
Fill(ForwardIterator first, ForwardIterator last, const T& value)
{
    // concept requirements
    Concept_FunctionRequires(MutableForwardIteratorConcept<ForwardIterator>)

    for ( ; first != last; ++first) {
        *first = value;
    }
}

/**
 *  @brief Fills the range [first,first+n) with copies of value.
 *  @param  first  An output iterator.
 *  @param  n      The count of copies to perform.
 *  @param  value  A reference-to-const of arbitrary type.
 *  @return   The iterator at first+n.
 *
 *  This function fills a range with copies of the same value.  For one-byte
 *  types filling contiguous areas of memory, this becomes an inline call to
 *  @c memset.
*/
template<typename OutputIterator, typename Size, typename T>
OutputIterator
FillN(OutputIterator first, Size n, const T& value)
{
    // concept requirements
    Concept_FunctionRequires(OutputIteratorConcept<OutputIterator, T>)

    for ( ; n > 0; --n, ++first) {
        *first = value;
    }
    return first;
}

// Specialization: for one-byte types we can use memset.

inline void
Fill(unsigned char* first, unsigned char* last, const unsigned char& c)
{
    unsigned char tmp = c;
    memset(first, tmp, last - first);
}

inline void
Fill(signed char* first, signed char* last, const signed char& c)
{
    signed char tmp = c;
    memset(first, static_cast<unsigned char>(tmp), last - first);
}

inline void
Fill(char* first, char* last, const char& c)
{
    char tmp = c;
    memset(first, static_cast<unsigned char>(tmp), last - first);
}

template<typename Size>
inline unsigned char*
FillN(unsigned char* first, Size n, const unsigned char& c)
{
    Fill(first, first + n, c);
    return first + n;
}

template<typename Size>
inline signed char*
FillN(char* first, Size n, const signed char& c)
{
    Fill(first, first + n, c);
    return first + n;
}

template<typename Size>
inline char*
FillN(char* first, Size n, const char& c)
{
    Fill(first, first + n, c);
    return first + n;
}


//--------------------------------------------------
// equal and mismatch

/**
 *  @brief Finds the places in ranges which don't match.
 *  @param  first1  An input iterator.
 *  @param  last1   An input iterator.
 *  @param  first2  An input iterator.
 *  @return   A pair of iterators pointing to the first mismatch.
 *
 *  This compares the elements of two ranges using @c == and returns a pair
 *  of iterators.  The first iterator points into the first range, the
 *  second iterator points into the second range, and the elements pointed
 *  to by the iterators are not equal.
*/
template<typename InputIterator1, typename InputIterator2>
Pair<InputIterator1, InputIterator2>
Mismatch(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
{
    // concept requirements
    Concept_FunctionRequires(InputIteratorConcept<InputIterator1>)
    Concept_FunctionRequires(InputIteratorConcept<InputIterator2>)
    Concept_FunctionRequires(EqualityComparableConcept<
            typename IteratorTraits<InputIterator1>::ValueType>)
    Concept_FunctionRequires(EqualityComparableConcept<
            typename IteratorTraits<InputIterator2>::ValueType>)

    while (first1 != last1 && *first1 == *first2) {
        ++first1;
        ++first2;
    }
    return Pair<InputIterator1, InputIterator2>(first1, first2);
}

/**
 *  @brief Finds the places in ranges which don't match.
 *  @param  first1  An input iterator.
 *  @param  last1   An input iterator.
 *  @param  first2  An input iterator.
 *  @param  binary_pred  A binary predicate @link s20_3_1_base functor@endlink.
 *  @return   A pair of iterators pointing to the first mismatch.
 *
 *  This compares the elements of two ranges using the binary_pred
 *  parameter, and returns a pair
 *  of iterators.  The first iterator points into the first range, the
 *  second iterator points into the second range, and the elements pointed
 *  to by the iterators are not equal.
*/
template<typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
Pair<InputIterator1, InputIterator2>
Mismatch(InputIterator1 first1, InputIterator1 last1,
        InputIterator2 first2, BinaryPredicate binaryPred)
{
    // concept requirements
    Concept_FunctionRequires(InputIteratorConcept<InputIterator1>)
    Concept_FunctionRequires(InputIteratorConcept<InputIterator2>)

    while (first1 != last1 && binaryPred(*first1, *first2)) {
        ++first1;
        ++first2;
    }
    return Pair<InputIterator1, InputIterator2>(first1, first2);
}

/**
 *  @brief Tests a range for element-wise equality.
 *  @param  first1  An input iterator.
 *  @param  last1   An input iterator.
 *  @param  first2  An input iterator.
 *  @return   A boolean true or false.
 *
 *  This compares the elements of two ranges using @c == and returns true or
 *  false depending on whether all of the corresponding elements of the
 *  ranges are equal.
*/
template<typename InputIterator1, typename InputIterator2>
inline Boolean
Equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
{
    // concept requirements
    Concept_FunctionRequires(InputIteratorConcept<InputIterator1>)
    Concept_FunctionRequires(InputIteratorConcept<InputIterator2>)
    Concept_FunctionRequires(EqualOpConcept<
            typename IteratorTraits<InputIterator1>::ValueType,
            typename IteratorTraits<InputIterator2>::ValueType>)

    for ( ; first1 != last1; ++first1, ++first2) {
        if (!(*first1 == *first2)) return FALSE;
    }
    return TRUE;
}

/**
 *  @brief Tests a range for element-wise equality.
 *  @param  first1  An input iterator.
 *  @param  last1   An input iterator.
 *  @param  first2  An input iterator.
 *  @param  binary_pred  A binary predicate @link s20_3_1_base functor@endlink.
 *  @return   A boolean true or false.
 *
 *  This compares the elements of two ranges using the binary_pred
 *  parameter, and returns true or
 *  false depending on whether all of the corresponding elements of the
 *  ranges are equal.
*/
template<typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
inline Boolean
Equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate binaryPred)
{
    // concept requirements
    Concept_FunctionRequires(InputIteratorConcept<InputIterator1>)
    Concept_FunctionRequires(InputIteratorConcept<InputIterator2>)

    for ( ; first1 != last1; ++first1, ++first2) {
        if (!binaryPred(*first1, *first2)) return FALSE;
    }
    return TRUE;
}

//--------------------------------------------------
// lexicographical_compare

/**
 *  @brief Performs "dictionary" comparison on ranges.
 *  @param  first1  An input iterator.
 *  @param  last1   An input iterator.
 *  @param  first2  An input iterator.
 *  @param  last2   An input iterator.
 *  @return   A boolean true or false.
 *
 *  "Returns true if the sequence of elements defined by the range
 *  [first1,last1) is lexicographically less than the sequence of elements
 *  defined by the range [first2,last2).  Returns false otherwise."
 *  (Quoted from [25.3.8]/1.)  If the iterators are all character pointers,
 *  then this is an inline call to @c memcmp.
*/
template<typename InputIterator1, typename InputIterator2>
Boolean
LexicographicalCompare(InputIterator1 first1, InputIterator1 last1,
        InputIterator2 first2, InputIterator2 last2)
{
    // concept requirements
    Concept_FunctionRequires(InputIteratorConcept<InputIterator1>)
    Concept_FunctionRequires(InputIteratorConcept<InputIterator2>)
    Concept_FunctionRequires(LessThanComparableConcept<
            typename IteratorTraits<InputIterator1>::ValueType>)
    Concept_FunctionRequires(LessThanComparableConcept<
            typename IteratorTraits<InputIterator2>::ValueType>)

    for ( ; first1 != last1 && first2 != last2; ++first1, ++first2) {
        if (*first1 < *first2) return TRUE;
        if (*first2 < *first1) return FALSE;
    }
    return first1 == last1 && first2 != last2;
}

/**
 *  @brief Performs "dictionary" comparison on ranges.
 *  @param  first1  An input iterator.
 *  @param  last1   An input iterator.
 *  @param  first2  An input iterator.
 *  @param  last2   An input iterator.
 *  @param  comp  A @link s20_3_3_comparisons comparison functor@endlink.
 *  @return   A boolean true or false.
 *
 *  The same as the four-parameter @c lexigraphical_compare, but uses the
 *  comp parameter instead of @c <.
*/
template<typename InputIterator1, typename InputIterator2, typename Compare>
Boolean
LexicographicalCompare(InputIterator1 first1, InputIterator1 last1,
        InputIterator2 first2, InputIterator2 last2, Compare comp)
{
    // concept requirements
    Concept_FunctionRequires(InputIteratorConcept<InputIterator1>)
    Concept_FunctionRequires(InputIteratorConcept<InputIterator2>)

    for ( ; first1 != last1 && first2 != last2; ++first1, ++first2) {
        if (comp(*first1, *first2)) return TRUE;
        if (comp(*first2, *first1)) return FALSE;
    }
    return first1 == last1 && first2 != last2;
}

inline Boolean
LexicographicalCompare(const unsigned char* first1, const unsigned char* last1,
        const unsigned char* first2, const unsigned char* last2)
{
    const size_t len1 = last1 - first1;
    const size_t len2 = last2 - first2;
    const int result = memcmp(first1, first2, Min(len1, len2));
    return result != 0 ? result < 0 : len1 < len2;
}

inline Boolean
LexicographicalCompare(const char* first1, const char* last1,
        const char* first2, const char* last2)
{
//#if CHAR_MAX == SCHAR_MAX
//    return LexicographicalCompare((const signed char*) first1,
//            (const signed char*) last1,
//            (const signed char*) first2,
//            (const signed char*) last2);
//#else /* CHAR_MAX == SCHAR_MAX */
    return LexicographicalCompare((const unsigned char*) first1,
            (const unsigned char*) last1,
            (const unsigned char*) first2,
            (const unsigned char*) last2);
//#endif /* CHAR_MAX == SCHAR_MAX */
}

_ETL_NAMESPACE_END

#endif //__ETL_ALGOBASE_H__
