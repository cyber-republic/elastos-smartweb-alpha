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

#ifndef __ELASTOS_UTILITY_ARRAYS_H__
#define __ELASTOS_UTILITY_ARRAYS_H__

//#include "elastos/utility/AbstractList.h"
#include "Elastos.CoreLibrary.Utility.h"
#include "elastos/core/Object.h"
#include "elastos/core/StringBuilder.h"
#include "elastos/core/Math.h"
#include "elastos/utility/DualPivotQuicksort.h"
#include "elastos/utility/ComparableTimSort.h"
#include "elastos/utility/TimSort.h"
#include "elastos/utility/logging/Logger.h"

using Elastos::Core::IComparator;
using Elastos::Core::IComparable;
using Elastos::Core::StringBuilder;
using Elastos::Core::IArrayOf;
using Elastos::IO::ISerializable;
//using Elastos::Utility::Logging::Logger;

namespace Elastos {
namespace Utility {

class ECO_PUBLIC Arrays
{
private:
    // class ArrayList
    //     : public AbstractList
    //     , public ISerializable
    //     , public IRandomAccess
    // {
    // public:
    //     CAR_INTERFACE_DECL()

    //     ArrayList(
    //         /* [in] */ ArrayOf<IInterface *> * storage);

    //     CARAPI Contains(
    //         /* [in] */ IInterface * object,
    //         /* [out] */ Boolean* result);

    //     CARAPI Get(
    //         /* [in] */ Int32 location,
    //         /* [out] */ IInterface ** result);

    //     CARAPI IndexOf(
    //         /* [in] */ IInterface * object,
    //         /* [out] */ Int32* result);

    //     CARAPI LastIndexOf(
    //         /* [in] */ IInterface * object,
    //         /* [out] */ Int32* index);

    //     CARAPI Set(
    //         /* [in] */ Int32 location,
    //         /* [in] */ IInterface * object,
    //         /* [out] */ IInterface ** result);

    //     CARAPI GetSize(
    //         /* [out] */ Int32* size);

    //     CARAPI ToArray(
    //         /* [out] */ ArrayOf<IInterface *> ** outArray);

    //     CARAPI ToArray(
    //         /* [in] */ ArrayOf<IInterface *> * contents,
    //         /* [out] */ ArrayOf<IInterface *> ** outArray);

    // private:
    //     AutoPtr<ArrayOf<IInterface *> > mA;
    // };

public:
    template<typename T>
    static CARAPI FromList(
        /* [in] */ IList* inList,
        /* [out, callee] */ ArrayOf<T*> ** array);

    template<typename T>
    static CARAPI AsList(
        /* [in] */ ArrayOf<T> * array,
        /* [out] */ IList** outList);

    template<typename T>
    static CARAPI AsList(
        /* [in] */ const AutoPtr<ArrayOf<T> > & array,
        /* [out] */ IList** outList);

    // Notes: there is not implementation for converting ArrayOf<Boolean> to IList.
    //
    static CARAPI AsList(
        /* [in] */ ArrayOf<Byte> * array,
        /* [out] */ IList** outList);

    static CARAPI AsList(
        /* [in] */ ArrayOf<Char32> * array,
        /* [out] */ IList** outList);

    static CARAPI AsList(
        /* [in] */ ArrayOf<Int16> * array,
        /* [out] */ IList** outList);

    static CARAPI AsList(
        /* [in] */ ArrayOf<Int32> * array,
        /* [out] */ IList** outList);

    static CARAPI AsList(
        /* [in] */ ArrayOf<Int64> * array,
        /* [out] */ IList** outList);

    static CARAPI AsList(
        /* [in] */ ArrayOf<Float> * array,
        /* [out] */ IList** outList);

    static CARAPI AsList(
        /* [in] */ ArrayOf<Double> * array,
        /* [out] */ IList** outList);

    static CARAPI AsList(
        /* [in] */ ArrayOf<String> * array,
        /* [out] */ IList** outList);

    /**
     * Performs a binary search for {@code value} in the ascending sorted array {@code array},
     * in the range specified by fromIndex (inclusive) and toIndex (exclusive).
     * Searching in an unsorted array has an undefined result. It's also undefined which element
     * is found if there are multiple occurrences of the same element.
     *
     * @param array the sorted array to search.
     * @param startIndex the inclusive start index.
     * @param endIndex the exclusive start index.
     * @param value the element to find.
     * @return the non-negative index of the element, or a negative index which
     *         is {@code -index - 1} where the element would be inserted.
     * @throws IllegalArgumentException if {@code startIndex > endIndex}
     * @throws ArrayIndexOutOfBoundsException if {@code startIndex < 0 || endIndex > array.length}
     * @since 1.6
     */
    static CARAPI BinarySearch(
        /* [in] */ ArrayOf<String>* array,
        /* [in] */ Int32 startIndex,
        /* [in] */ Int32 endIndex,
        /* [in] */ const String& value,
        /* [out] */ Int32* index);

    static CARAPI BinarySearch(
        /* [in] */ const AutoPtr<ArrayOf<String> > & array,
        /* [in] */ Int32 startIndex,
        /* [in] */ Int32 endIndex,
        /* [in] */ const String& value,
        /* [out] */ Int32* index);

    /**
     * Performs a binary search for {@code value} in the ascending sorted array {@code array}.
     * Searching in an unsorted array has an undefined result. It's also undefined which element
     * is found if there are multiple occurrences of the same element.
     *
     * @param array the sorted array to search.
     * @param value the element to find.
     * @return the non-negative index of the element, or a negative index which
     *         is {@code -index - 1} where the element would be inserted.
     */
    static CARAPI BinarySearch(
        /* [in] */ ArrayOf<String>* array,
        /* [in] */ const String& value,
        /* [out] */ Int32* index);

    static CARAPI BinarySearch(
        /* [in] */ const AutoPtr<ArrayOf<String> > & array,
        /* [in] */ const String& value,
        /* [out] */ Int32* index);

    /**
     * Performs a binary search for {@code value} in the ascending sorted array {@code array},
     * in the range specified by fromIndex (inclusive) and toIndex (exclusive).
     * Searching in an unsorted array has an undefined result. It's also undefined which element
     * is found if there are multiple occurrences of the same element.
     *
     * @param array the sorted array to search.
     * @param startIndex the inclusive start index.
     * @param endIndex the exclusive start index.
     * @param value the element to find.
     * @return the non-negative index of the element, or a negative index which
     *         is {@code -index - 1} where the element would be inserted.
     * @throws IllegalArgumentException if {@code startIndex > endIndex}
     * @throws ArrayIndexOutOfBoundsException if {@code startIndex < 0 || endIndex > array.length}
     * @since 1.6
     */
    template<typename T>
    static CARAPI BinarySearch(
        /* [in] */ ArrayOf<T>* array,
        /* [in] */ Int32 startIndex,
        /* [in] */ Int32 endIndex,
        /* [in] */ T value,
        /* [out] */ Int32* index);

    template<typename T>
    static CARAPI BinarySearch(
        /* [in] */ const AutoPtr<ArrayOf<T> > & array,
        /* [in] */ Int32 startIndex,
        /* [in] */ Int32 endIndex,
        /* [in] */ T value,
        /* [out] */ Int32* index);

    /**
     * Performs a binary search for {@code value} in the ascending sorted array {@code array}.
     * Searching in an unsorted array has an undefined result. It's also undefined which element
     * is found if there are multiple occurrences of the same element.
     *
     * @param array the sorted array to search.
     * @param value the element to find.
     * @return the non-negative index of the element, or a negative index which
     *         is {@code -index - 1} where the element would be inserted.
     */
    template<typename T>
    static CARAPI BinarySearch(
        /* [in] */ ArrayOf<T>* array,
        /* [in] */ T value,
        /* [out] */ Int32* index);

    template<typename T>
    static CARAPI BinarySearch(
        /* [in] */ const AutoPtr<ArrayOf<T> > & array,
        /* [in] */ T value,
        /* [out] */ Int32* index);

    /**
     * Performs a binary search for {@code value} in the ascending sorted array {@code array},
     * in the range specified by fromIndex (inclusive) and toIndex (exclusive).
     * Searching in an unsorted array has an undefined result. It's also undefined which element
     * is found if there are multiple occurrences of the same element.
     *
     * @param array the sorted array to search.
     * @param startIndex the inclusive start index.
     * @param endIndex the exclusive start index.
     * @param value the element to find.
     * @return the non-negative index of the element, or a negative index which
     *         is {@code -index - 1} where the element would be inserted.
     * @throws ClassCastException
     *         if an element in the array or the search element does not
     *         implement {@code Comparable}, or cannot be compared to each other.
     * @throws IllegalArgumentException if {@code startIndex > endIndex}
     * @throws ArrayIndexOutOfBoundsException if {@code startIndex < 0 || endIndex > array.length}
     * @since 1.6
     */
    template<typename T>
    static CARAPI BinarySearch(
        /* [in] */ ArrayOf<T *> * array,
        /* [in] */ Int32 startIndex,
        /* [in] */ Int32 endIndex,
        /* [in] */ T * value,
        /* [out] */ Int32* index);

    template<typename T>
    static CARAPI BinarySearch(
        /* [in] */ const AutoPtr<ArrayOf<T *> > & array,
        /* [in] */ Int32 startIndex,
        /* [in] */ Int32 endIndex,
        /* [in] */ T * value,
        /* [out] */ Int32* index);

    /**
     * Performs a binary search for {@code value} in the ascending sorted array {@code array}.
     * Searching in an unsorted array has an undefined result. It's also undefined which element
     * is found if there are multiple occurrences of the same element.
     *
     * @param array the sorted array to search.
     * @param value the element to find.
     * @return the non-negative index of the element, or a negative index which
     *         is {@code -index - 1} where the element would be inserted.
     * @throws ClassCastException
     *         if an element in the array or the search element does not
     *         implement {@code Comparable}, or cannot be compared to each other.
     */
    template<typename T>
    static CARAPI BinarySearch(
        /* [in] */ ArrayOf<T *> * array,
        /* [in] */ T * value,
        /* [out] */ Int32* index);

    template<typename T>
    static CARAPI BinarySearch(
        /* [in] */ const AutoPtr<ArrayOf<T *> > & array,
        /* [in] */ T * value,
        /* [out] */ Int32* index);

    /**
     * Performs a binary search for {@code value} in the ascending sorted array {@code array},
     * in the range specified by fromIndex (inclusive) and toIndex (exclusive),
     * using {@code comparator} to compare elements.
     * Searching in an unsorted array has an undefined result. It's also undefined which element
     * is found if there are multiple occurrences of the same element.
     *
     * @param array the sorted array to search.
     * @param startIndex the inclusive start index.
     * @param endIndex the exclusive start index.
     * @param value the element to find.
     * @param comparator the {@code Comparator} used to compare the elements.
     * @return the non-negative index of the element, or a negative index which
     *         is {@code -index - 1} where the element would be inserted.
     * @throws ClassCastException
     *         if an element in the array or the search element does not
     *         implement {@code Comparable}, or cannot be compared to each other.
     * @throws IllegalArgumentException if {@code startIndex > endIndex}
     * @throws ArrayIndexOutOfBoundsException if {@code startIndex < 0 || endIndex > array.length}
     * @since 1.6
     */
    template<typename T>
    static CARAPI BinarySearch(
        /* [in] */ ArrayOf<T *> * array,
        /* [in] */ Int32 startIndex,
        /* [in] */ Int32 endIndex,
        /* [in] */ T * value,
        /* [in] */ IComparator* comparator,
        /* [out] */ Int32* index);

    template<typename T>
    static CARAPI BinarySearch(
        /* [in] */ const AutoPtr<ArrayOf<T *> > & array,
        /* [in] */ Int32 startIndex,
        /* [in] */ Int32 endIndex,
        /* [in] */ T * value,
        /* [in] */ IComparator* comparator,
        /* [out] */ Int32* index);

    /**
     * Performs a binary search for {@code value} in the ascending sorted array {@code array},
     * using {@code comparator} to compare elements.
     * Searching in an unsorted array has an undefined result. It's also undefined which element
     * is found if there are multiple occurrences of the same element.
     *
     * @param array the sorted array to search.
     * @param value the element to find.
     * @param comparator the {@code Comparator} used to compare the elements.
     * @return the non-negative index of the element, or a negative index which
     *         is {@code -index - 1} where the element would be inserted.
     * @throws ClassCastException
     *         if an element in the array or the search element does not
     *         implement {@code Comparable}, or cannot be compared to each other.
     */
    template<typename T>
    static CARAPI BinarySearch(
        /* [in] */ ArrayOf<T *> * array,
        /* [in] */ T * value,
        /* [in] */ IComparator* comparator,
        /* [out] */ Int32* index);

    template<typename T>
    static CARAPI BinarySearch(
        /* [in] */ const AutoPtr<ArrayOf<T *> > & array,
        /* [in] */ T * value,
        /* [in] */ IComparator* comparator,
        /* [out] */ Int32* index);

    /**
     * Fills the specified array with the specified element.
     *
     * @param array
     *            the {@code byte} array to fill.
     * @param value
     *            the {@code byte} element.
     */
    template<typename T>
    static CARAPI Fill(
        /* [in] */ ArrayOf<T>* array,
        /* [in] */ T value);

    template<typename T>
    static CARAPI Fill(
        /* [in] */ const AutoPtr<ArrayOf<T> > & array,
        /* [in] */ T value);

    /**
     * Fills the specified range in the array with the specified element.
     *
     * @param array
     *            the {@code byte} array to fill.
     * @param start
     *            the first index to fill.
     * @param end
     *            the last + 1 index to fill.
     * @param value
     *            the {@code byte} element.
     * @throws IllegalArgumentException
     *                if {@code start > end}.
     * @throws ArrayIndexOutOfBoundsException
     *                if {@code start < 0} or {@code end > array.length}.
     */
    template<typename T>
    static CARAPI Fill(
        /* [in] */ ArrayOf<T>* array,
        /* [in] */ Int32 start,
        /* [in] */ Int32 end,
        /* [in] */ T value);

    template<typename T>
    static CARAPI Fill(
        /* [in] */ const AutoPtr<ArrayOf<T> > & array,
        /* [in] */ Int32 start,
        /* [in] */ Int32 end,
        /* [in] */ T value);

    /**
     * Returns a hash code based on the contents of the given array. For any two
     * {@code boolean} arrays {@code a} and {@code b}, if
     * {@code Arrays.equals(a, b)} returns {@code true}, it means
     * that the return value of {@code Arrays.hashCode(a)} equals {@code Arrays.hashCode(b)}.
     * <p>
     * The value returned by this method is the same value as the
     * {@link List#hashCode()} method which is invoked on a {@link List}
     * containing a sequence of {@link Boolean} instances representing the
     * elements of array in the same order. If the array is {@code null}, the return
     * value is 0.
     *
     * @param array
     *            the array whose hash code to compute.
     * @return the hash code for {@code array}.
     */
    template<typename T>
    static CARAPI_(Int32) GetHashCode(
        /* [in] */ ArrayOf<T>* array);

    template<typename T>
    static CARAPI_(Int32) GetHashCode(
        /* [in] */ const AutoPtr<ArrayOf<T> > & array);

    static CARAPI_(Int32) GetHashCode(
        /* [in] */ ArrayOf<Boolean>* array);

    static CARAPI_(Int32) GetHashCode(
        /* [in] */ ArrayOf<Int64>* array);

    static CARAPI_(Int32) GetHashCode(
        /* [in] */ ArrayOf<Float>* array);

    static CARAPI_(Int32) GetHashCode(
        /* [in] */ ArrayOf<Double>* array);

    template<typename T>
    static CARAPI_(Int32) GetHashCode(
        /* [in] */ ArrayOf<T *> * array);

    template<typename T>
    static CARAPI_(Int32) GetHashCode(
        /* [in] */ const AutoPtr<ArrayOf<T *> > & array);

    template<typename T>
    static CARAPI_(Int32) DeepGetHashCode(
        /* [in] */ ArrayOf<T *> * array);

    template<typename T>
    static CARAPI_(Int32) DeepGetHashCode(
        /* [in] */ T * element);

    template<typename T>
    static CARAPI_(Int32) DeepGetHashCode(
        /* [in] */ const AutoPtr<T> & element);

    /**
     * Compares the two arrays.
     *
     * @param array1
     *            the first {@code byte} array.
     * @param array2
     *            the second {@code byte} array.
     * @return {@code true} if both arrays are {@code null} or if the arrays have the
     *         same length and the elements at each index in the two arrays are
     *         equal, {@code false} otherwise.
     */
    template<typename T>
    static CARAPI_(Boolean) Equals(
        /* [in] */ ArrayOf<T>* array1,
        /* [in] */ ArrayOf<T>* array2);

    template<typename T>
    static CARAPI_(Boolean) Equals(
        /* [in] */ const AutoPtr<ArrayOf<T> > & array1,
        /* [in] */ const AutoPtr<ArrayOf<T> > & array2);

    static CARAPI_(Boolean) Equals(
        /* [in] */ ArrayOf<Float>* array1,
        /* [in] */ ArrayOf<Float>* array2);

    static CARAPI_(Boolean) Equals(
        /* [in] */ ArrayOf<Double>* array1,
        /* [in] */ ArrayOf<Double>* array2);

    template<typename T>
    static CARAPI_(Boolean) Equals(
        /* [in] */ ArrayOf<T *> * array1,
        /* [in] */ ArrayOf<T *> * array2);

    template<typename T>
    static CARAPI_(Boolean) Equals(
        /* [in] */ const AutoPtr<ArrayOf<T *> > & array1,
        /* [in] */ ArrayOf<T *> * array2);

    template<typename T>
    static CARAPI_(Boolean) Equals(
        /* [in] */ ArrayOf<T *> * array1,
        /* [in] */ const AutoPtr<ArrayOf<T *> > & array2);

    template<typename T>
    static CARAPI_(Boolean) Equals(
        /* [in] */ const AutoPtr<ArrayOf<T *> > & array1,
        /* [in] */ const AutoPtr<ArrayOf<T *> > & array2);

    template<typename T>
    static CARAPI_(Boolean) DeepEquals(
        /* [in] */ ArrayOf<T> * array1,
        /* [in] */ ArrayOf<T> * array2);

    template<typename T>
    static CARAPI_(Boolean) DeepEquals(
        /* [in] */ const AutoPtr<ArrayOf<T> > & array1,
        /* [in] */ const AutoPtr<ArrayOf<T> > & array2);

    template<typename T>
    static CARAPI_(Boolean) DeepEquals(
        /* [in] */ T * e1,
        /* [in] */ T * e2);

    template<typename T>
    static CARAPI_(Boolean) DeepEquals(
        /* [in] */ const AutoPtr<T> & e1,
        /* [in] */ T * e2);

    template<typename T>
    static CARAPI_(Boolean) DeepEquals(
        /* [in] */ T * e1,
        /* [in] */ const AutoPtr<T> & e2);

    template<typename T>
    static CARAPI_(Boolean) DeepEquals(
        /* [in] */ const AutoPtr<T> & e1,
        /* [in] */ const AutoPtr<T> & e2);

    template<typename T>
    static CARAPI Sort(
        /* [in] */ ArrayOf<T>* array);

    template<typename T>
    static CARAPI Sort(
        /* [in] */ const AutoPtr<ArrayOf<T> > & array);

    template<typename T>
    static CARAPI Sort(
        /* [in] */ ArrayOf<T>* array,
        /* [in] */ Int32 start,
        /* [in] */ Int32 end);

    template<typename T>
    static CARAPI Sort(
        /* [in] */ const AutoPtr<ArrayOf<T> > & array,
        /* [in] */ Int32 start,
        /* [in] */ Int32 end);

    template<typename T>
    static CARAPI Sort(
        /* [in] */ ArrayOf<T *> * array);

    template<typename T>
    static CARAPI Sort(
        /* [in] */ const AutoPtr<ArrayOf<T *> > & array);

    template<typename T>
    static CARAPI Sort(
        /* [in] */ ArrayOf<T *> * array,
        /* [in] */ Int32 start,
        /* [in] */ Int32 end);

    template<typename T>
    static CARAPI Sort(
        /* [in] */ const AutoPtr<ArrayOf<T *> > & array,
        /* [in] */ Int32 start,
        /* [in] */ Int32 end);

    template<typename T>
    static CARAPI Sort(
        /* [in] */ ArrayOf<T *> * array,
        /* [in] */ Int32 start,
        /* [in] */ Int32 end,
        /* [in] */ IComparator* comparator);

    template<typename T>
    static CARAPI Sort(
        /* [in] */ const AutoPtr<ArrayOf<T *> > & array,
        /* [in] */ Int32 start,
        /* [in] */ Int32 end,
        /* [in] */ IComparator* comparator);

    template<typename T>
    static CARAPI Sort(
        /* [in] */ ArrayOf<T *> * array,
        /* [in] */ IComparator* comparator);

    template<typename T>
    static CARAPI Sort(
        /* [in] */ const AutoPtr<ArrayOf<T *> > & array,
        /* [in] */ IComparator* comparator);

    template<typename T>
    static CARAPI_(String) ToString(
        /* [in] */ ArrayOf<T> * array);

    template<typename T>
    static CARAPI_(String) ToString(
        /* [in] */ const AutoPtr<ArrayOf<T> > & array);

    static CARAPI_(String) ToString(
        /* [in] */ ArrayOf<Char32> * array);

    template<typename T>
    static CARAPI_(String) DeepToString(
        /* [in] */ ArrayOf<T *> * array);

    template<typename T>
    static CARAPI_(String) DeepToString(
        /* [in] */ const AutoPtr<ArrayOf<T *> > & array);

    template<typename T>
    static CARAPI CopyOf(
        /* [in] */ ArrayOf<T> * original,
        /* [in] */ Int32 newLength,
        /* [out, callee] */ ArrayOf<T> ** result);

    template<typename T>
    static CARAPI CopyOf(
        /* [in] */ const AutoPtr<ArrayOf<T> > & original,
        /* [in] */ Int32 newLength,
        /* [out, callee] */ ArrayOf<T> ** result);

    template<typename T>
    static CARAPI CopyOfRange(
        /* [in] */ ArrayOf<T> * original,
        /* [in] */ Int32 start,
        /* [in] */ Int32 end,
        /* [out, callee] */ ArrayOf<T> ** result);

    template<typename T>
    static CARAPI CopyOfRange(
        /* [in] */ const AutoPtr<ArrayOf<T> > & original,
        /* [in] */ Int32 start,
        /* [in] */ Int32 end,
        /* [out, callee] */ ArrayOf<T> ** result);

    template<typename T, typename U>
    static CARAPI CopyOf(
        /* [in] */ ArrayOf<T> * original,
        /* [in] */ Int32 newLength,
        /* [out, callee] */ ArrayOf<U> ** result);

    template<typename T, typename U>
    static CARAPI CopyOf(
        /* [in] */ const AutoPtr<ArrayOf<T> > & original,
        /* [in] */ Int32 newLength,
        /* [out, callee] */ ArrayOf<U> ** result);

    template<typename T, typename U>
    static CARAPI CopyOfRange(
        /* [in] */ ArrayOf<T> * original,
        /* [in] */ Int32 start,
        /* [in] */ Int32 end,
        /* [out, callee] */ ArrayOf<U> ** result);

    template<typename T, typename U>
    static CARAPI CopyOfRange(
        /* [in] */ const AutoPtr<ArrayOf<T> > & original,
        /* [in] */ Int32 start,
        /* [in] */ Int32 end,
        /* [out, callee] */ ArrayOf<U> ** result);

public:
    static CARAPI CheckStartAndEnd(
        /* [in] */ Int32 len,
        /* [in] */ Int32 start,
        /* [in] */ Int32 end);

    static CARAPI CheckOffsetAndCount(
        /* [in] */ Int32 arrayLength,
        /* [in] */ Int32 offset,
        /* [in] */ Int32 count);

private:
    static CARAPI_(AutoPtr<IList>) CreateArrayList(
        /* [in] */ Int32 length);

    static CARAPI CheckBinarySearchBounds(
        /* [in] */ Int32 startIndex,
        /* [in] */ Int32 endIndex,
        /* [in] */ Int32 length);

    template<typename T>
    ECO_LOCAL static CARAPI DeepToString(
        /* [in] */ T * obj,
        /* [in] */ ArrayOf<T*> * origArrays,
        /* [in] */ StringBuilder& sb);

    template<typename T>
    ECO_LOCAL static CARAPI_(Boolean) DeepToStringContains(
        /* [in] */ ArrayOf<T *> * origArray,
        /* [in] */ T * obj);

    template<typename T>
    ECO_LOCAL static CARAPI DeepToString(
        /* [in] */ T * obj,
        /* [in] */ IArrayOf * origArrays,
        /* [in] */ StringBuilder& sb);

    template<typename T>
    ECO_LOCAL static CARAPI_(Boolean) DeepToStringContains(
        /* [in] */ IArrayOf * origArray,
        /* [in] */ T * obj);

    ECO_LOCAL static CARAPI DeepToString(
        /* [in] */ IInterface * obj,
        /* [in] */ IArrayOf * origArray,
        /* [in] */ StringBuilder& sb);

    ECO_LOCAL static CARAPI_(Boolean) DeepToStringContains(
        /* [in] */ IArrayOf * origArray,
        /* [in] */ IInterface * obj);

private:
    ECO_LOCAL Arrays();
    ECO_LOCAL Arrays(const Arrays&);
};

//=========================================================================
// template methods implementation
//=========================================================================

template<typename T>
ECode Arrays::FromList(
    /* [in] */ IList* list,
    /* [out, callee] */ ArrayOf<T*> ** array)
{
    VALIDATE_NOT_NULL(array)
    *array = NULL;
    VALIDATE_NOT_NULL(list)

    Int32 size;
    list->GetSize(&size);
    AutoPtr<ArrayOf<T*> > temp = ArrayOf<T*>::Alloc(size);
    if (size > 0) {
        AutoPtr<IIterator> it;
        list->GetIterator((IIterator**)&it);
        Boolean hasNext;
        Int32 i = 0;
        while (it->HasNext(&hasNext), hasNext) {
            AutoPtr<IInterface> obj;
            it->GetNext((IInterface**)&obj);
            temp->Set(i++, T::Probe(obj));
        }
    }

    *array = temp;
    REFCOUNT_ADD(*array)
    return NOERROR;
}

template<typename T>
ECode Arrays::AsList(
    /* [in] */ ArrayOf<T> * array,
    /* [out] */ IList** outList)
{
    VALIDATE_NOT_NULL(outList)
    *outList = NULL;

    if (array) {
        AutoPtr<IList> l = CreateArrayList(array->GetLength());
        for (Int32 i = 0; i < array->GetLength(); ++i) {
            l->Add(i, TO_IINTERFACE((*array)[i]));
        }

        *outList = l;
        REFCOUNT_ADD(*outList)
    }

    return NOERROR;
}

template<typename T>
ECode Arrays::AsList(
    /* [in] */ const AutoPtr<ArrayOf<T> > & array,
    /* [out] */ IList** outList)
{
    return AsList(array.Get(), outList);
}

template<typename T>
ECode Arrays::BinarySearch(
    /* [in] */ ArrayOf<T>* array,
    /* [in] */ Int32 startIndex,
    /* [in] */ Int32 endIndex,
    /* [in] */ T value,
    /* [out] */ Int32* index)
{
    VALIDATE_NOT_NULL(index)
    *index = -1;
    assert(array != NULL);
    VALIDATE_NOT_NULL(array)

    ECode ec = CheckBinarySearchBounds(startIndex, endIndex, array->GetLength());
    if (FAILED(ec)) {
        printf("Arrays", "BinarySearch: error %08x, startIndex: %d, endIndex: %d, array length: %d",
            ec, startIndex, endIndex, array->GetLength());
        return ec;
    }

    Int32 lo = startIndex;
    Int32 hi = endIndex - 1;
    Int32 mid;

    T midVal;
    while (lo <= hi) {
        mid = (UInt32(lo + hi)) >> 1;
        midVal = (*array)[mid];

        if (midVal < value) {
            lo = mid + 1;
        }
        else if (midVal > value) {
            hi = mid - 1;
        }
        else {
            *index = mid;  // value found
            return NOERROR;
        }
    }
    *index = ~lo;  // value not present
    return NOERROR;
}

template<typename T>
ECode Arrays::BinarySearch(
    /* [in] */ ArrayOf<T>* array,
    /* [in] */ T value,
    /* [out] */ Int32* index)
{
    VALIDATE_NOT_NULL(index)
    *index = -1;
    assert(array != NULL);
    VALIDATE_NOT_NULL(array)

    return BinarySearch(array, 0, array->GetLength(), value, index);
}

template<typename T>
ECode Arrays::BinarySearch(
    /* [in] */ const AutoPtr<ArrayOf<T> > & array,
    /* [in] */ Int32 startIndex,
    /* [in] */ Int32 endIndex,
    /* [in] */ T value,
    /* [out] */ Int32* index)
{
    return BinarySearch(array.Get(), startIndex, endIndex, value, index);
}

template<typename T>
ECode Arrays::BinarySearch(
    /* [in] */ const AutoPtr<ArrayOf<T> > & array,
    /* [in] */ T value,
    /* [out] */ Int32* index)
{
    return BinarySearch(array.Get(), value, index);
}

template<typename T>
ECode Arrays::BinarySearch(
    /* [in] */ ArrayOf<T *> * array,
    /* [in] */ Int32 startIndex,
    /* [in] */ Int32 endIndex,
    /* [in] */ T * value,
    /* [out] */ Int32* index)
{
    VALIDATE_NOT_NULL(index)
    *index = -1;
    assert(array != NULL);
    VALIDATE_NOT_NULL(array)

    ECode ec = CheckBinarySearchBounds(startIndex, endIndex, array->GetLength());
    if (FAILED(ec)) {
        printf("Arrays", "BinarySearch: error %08x, startIndex: %d, endIndex: %d, array length: %d",
            ec, startIndex, endIndex, array->GetLength());
        return ec;
    }

    Int32 lo = startIndex;
    Int32 hi = endIndex - 1;
    Int32 mid, midValCmp;
    IComparable* comp;
    while (lo <= hi) {
        mid = (UInt32(lo + hi)) >> 1;
        comp = IComparable::Probe((*array)[mid]);
        if (comp == NULL) {
            printf("Arrays", "BinarySearch: object at %d does not implement IComparable.", mid);
        }
        assert(comp != NULL);
        comp->CompareTo(TO_IINTERFACE(value), &midValCmp);

        if (midValCmp < 0) {
            lo = mid + 1;
        }
        else if (midValCmp > 0) {
            hi = mid - 1;
        }
        else {
            *index = mid;  // value found
            return NOERROR;
        }
    }
    *index = ~lo;  // value not present
    return NOERROR;
}

template<typename T>
ECode Arrays::BinarySearch(
    /* [in] */ const AutoPtr<ArrayOf<T *> > & array,
    /* [in] */ Int32 startIndex,
    /* [in] */ Int32 endIndex,
    /* [in] */ T * value,
    /* [out] */ Int32* index)
{
    return BinarySearch(array.Get(), startIndex, endIndex, value, index);
}

template<typename T>
ECode Arrays::BinarySearch(
    /* [in] */ ArrayOf<T *> * array,
    /* [in] */ T * value,
    /* [out] */ Int32* index)
{
    VALIDATE_NOT_NULL(index)
    *index = -1;
    assert(array != NULL);
    VALIDATE_NOT_NULL(array)

    return BinarySearch(array, 0, array->GetLength(), value, index);
}

template<typename T>
ECode Arrays::BinarySearch(
    /* [in] */ const AutoPtr<ArrayOf<T *> > & array,
    /* [in] */ T * value,
    /* [out] */ Int32* index)
{
    VALIDATE_NOT_NULL(index)
    *index = -1;
    assert(array != NULL);
    VALIDATE_NOT_NULL(array)

    return BinarySearch(array.Get(), 0, array->GetLength(), value, index);
}

template<typename T>
ECode Arrays::BinarySearch(
    /* [in] */ ArrayOf<T *> * array,
    /* [in] */ Int32 startIndex,
    /* [in] */ Int32 endIndex,
    /* [in] */ T* value,
    /* [in] */ IComparator* comparator,
    /* [out] */ Int32* index)
{
    VALIDATE_NOT_NULL(index)
    *index = -1;
    assert(array != NULL);
    VALIDATE_NOT_NULL(array)

    if (comparator == NULL) {
        return BinarySearch(array, startIndex, endIndex, value, index);
    }

    FAIL_RETURN(CheckBinarySearchBounds(startIndex, endIndex, array->GetLength()));
    Int32 lo = startIndex;
    Int32 hi = endIndex - 1;
    Int32 mid, midValCmp;

    while (lo <= hi) {
        mid = (UInt32(lo + hi)) >> 1;
        comparator->Compare(TO_IINTERFACE((*array)[mid]), value, &midValCmp);

        if (midValCmp < 0) {
            lo = mid + 1;
        }
        else if (midValCmp > 0) {
            hi = mid - 1;
        }
        else {
            *index = mid;  // value found
            return NOERROR;
        }
    }
    *index = ~lo;  // value not present
    return NOERROR;
}

template<typename T>
ECode Arrays::BinarySearch(
    /* [in] */ const AutoPtr<ArrayOf<T *> > & array,
    /* [in] */ Int32 startIndex,
    /* [in] */ Int32 endIndex,
    /* [in] */ T* value,
    /* [in] */ IComparator* comparator,
    /* [out] */ Int32* index)
{
    return BinarySearch(array.Get(), startIndex, endIndex, value, comparator, index);
}

template<typename T>
ECode Arrays::BinarySearch(
    /* [in] */ ArrayOf<T *> * array,
    /* [in] */ T* value,
    /* [in] */ IComparator* comparator,
    /* [out] */ Int32* index)
{
    VALIDATE_NOT_NULL(index)
    *index = -1;
    assert(array != NULL);
    VALIDATE_NOT_NULL(array)

    return BinarySearch(array, 0, array->GetLength(), value, comparator, index);
}

template<typename T>
ECode Arrays::BinarySearch(
    /* [in] */ const AutoPtr<ArrayOf<T *> > & array,
    /* [in] */ T* value,
    /* [in] */ IComparator* comparator,
    /* [out] */ Int32* index)
{
    VALIDATE_NOT_NULL(index)
    *index = -1;
    assert(array != NULL);
    VALIDATE_NOT_NULL(array)

    return BinarySearch(array.Get(), 0, array->GetLength(), value, comparator, index);
}

template<typename T>
ECode Arrays::Fill(
    /* [in] */ ArrayOf<T>* array,
    /* [in] */ Int32 start,
    /* [in] */ Int32 end,
    /* [in] */ T value)
{
    assert(array != NULL);
    VALIDATE_NOT_NULL(array);

    FAIL_RETURN(CheckStartAndEnd(array->GetLength(), start, end));
    for (Int32 i = start; i < end; i++) {
        array->Set(i, value);
    }
    return NOERROR;
}

template<typename T>
ECode Arrays::Fill(
    /* [in] */ ArrayOf<T>* array,
    /* [in] */ T value)
{
    assert(array != NULL);
    VALIDATE_NOT_NULL(array);

    for (Int32 i = 0; i < array->GetLength(); i++) {
        array->Set(i, value);
    }
    return NOERROR;
}

template<typename T>
ECode Arrays::Fill(
    /* [in] */ const AutoPtr<ArrayOf<T> > & array,
    /* [in] */ Int32 start,
    /* [in] */ Int32 end,
    /* [in] */ T value)
{
    return Fill(array.Get(), start, end, value);
}

template<typename T>
ECode Arrays::Fill(
    /* [in] */ const AutoPtr<ArrayOf<T> > & array,
    /* [in] */ T value)
{
    return Fill(array.Get(), value);
}

template<typename T>
Int32 Arrays::GetHashCode(
    /* [in] */ ArrayOf<T>* array)
{
    if (array == NULL) {
        return 0;
    }

    Int32 hashCode = 1;
    for (Int32 i = 0; i < array->GetLength(); i++) {
        hashCode = 31 * hashCode + (Int32)(*array)[i];
    }
    return hashCode;
}

template<typename T>
Int32 Arrays::GetHashCode(
    /* [in] */ const AutoPtr<ArrayOf<T> > & array)
{
    return GetHashCode(array.Get());
}

template<typename T>
Int32 Arrays::GetHashCode(
    /* [in] */ ArrayOf<T *> * array)
{
    if (array == NULL) {
        return 0;
    }

    Int32 hashCode = 1;
    T* element;
    for (Int32 i = 0; i < array->GetLength(); i++) {
        element = (*array)[i];
        hashCode = 31 * hashCode + Object::GetHashCode(element);
    }
    return hashCode;
}

template<typename T>
Int32 Arrays::GetHashCode(
    /* [in] */ const AutoPtr<ArrayOf<T *> > & array)
{
    return GetHashCode(array.Get());
}

template<typename T>
Int32 Arrays::DeepGetHashCode(
    /* [in] */ ArrayOf<T *> * array)
{
    if (array == NULL) {
        return 0;
    }

    Int32 hashCode = 1, elementHashCode;
    for (Int32 i = 0; i < array->GetLength(); i++) {
        elementHashCode = DeepGetHashCode((*array)[i]);
        hashCode = 31 * hashCode + elementHashCode;
    }
    return hashCode;
}

template<typename T>
Int32 Arrays::DeepGetHashCode(
    /* [in] */ T* element)
{
    if (element == NULL) {
        return 0;
    }

    if (IArrayOf::Probe(element) == NULL) {
        return Object::GetHashCode(element);
    }

    /*
     * element is an array
     */
    Int32 length;
    AutoPtr<IArrayOf> array = IArrayOf::Probe(element);
    array->GetLength(&length);

    Int32 hashCode = 1, elementHashCode;
    for (Int32 i = 0; i < length; ++i) {
        AutoPtr<IInterface> object;
        array->Get(i, (IInterface**)&object);
        elementHashCode = DeepGetHashCode(object.Get());
        hashCode = 31 * hashCode + elementHashCode;
    }
    return hashCode;
}

template<typename T>
Int32 Arrays::DeepGetHashCode(
    /* [in] */ const AutoPtr<T> & element)
{
    return DeepGetHashCode(element.Get());
}

template<typename T>
Boolean Arrays::Equals(
    /* [in] */ ArrayOf<T>* array1,
    /* [in] */ ArrayOf<T>* array2)
{
    if (array1 == array2) {
        return TRUE;
    }

    if (array1 == NULL || array2 == NULL || array1->GetLength() != array2->GetLength()) {
        return FALSE;
    }

    for (Int32 i = 0; i < array1->GetLength(); i++) {
        if ((*array1)[i] != (*array2)[i]) {
            return FALSE;
        }
    }

    return TRUE;
}

template<typename T>
Boolean Arrays::Equals(
    /* [in] */ const AutoPtr<ArrayOf<T> > & array1,
    /* [in] */ const AutoPtr<ArrayOf<T> > & array2)
{
    return Equals(array1.Get(), array2.Get());
}

template<typename T>
Boolean Arrays::DeepEquals(
    /* [in] */ ArrayOf<T> * array1,
    /* [in] */ ArrayOf<T> * array2)
{
    if (array1 == array2) {
        return TRUE;
    }
    if (array1 == NULL || array2 == NULL || array1->GetLength() != array2->GetLength()) {
        return FALSE;
    }

    for (Int32 i = 0; i < array1->GetLength(); i++) {
        if (!DeepEquals(TO_IINTERFACE((*array1)[i]), TO_IINTERFACE((*array2)[i]))) {
            return FALSE;
        }
    }
    return TRUE;
}

template<typename T>
Boolean Arrays::DeepEquals(
    /* [in] */ const AutoPtr<ArrayOf<T> > & array1,
    /* [in] */ const AutoPtr<ArrayOf<T> > & array2)
{
    return DeepEquals(array1.Get(), array2.Get());
}

template<typename T>
Boolean Arrays::Equals(
    /* [in] */ ArrayOf<T *> * array1,
    /* [in] */ ArrayOf<T *> * array2)
{
    if (array1 == array2) {
        return TRUE;
    }
    if (array1 == NULL || array2 == NULL || array1->GetLength() != array2->GetLength()) {
        return FALSE;
    }

    T *e1, *e2;
    for (Int32 i = 0; i < array1->GetLength(); i++) {
        e1 = (*array1)[i];
        e2 = (*array2)[i];
        if (!(e1 == NULL ? e2 == NULL : Object::Equals(e1, e2))) {
            return FALSE;
        }
    }
    return TRUE;
}

template<typename T>
Boolean Arrays::Equals(
    /* [in] */ const AutoPtr<ArrayOf<T *> > & array1,
    /* [in] */ ArrayOf<T *> * array2)
{
    return Equals(array1.Get(), array2);
}

template<typename T>
Boolean Arrays::Equals(
    /* [in] */ ArrayOf<T *> * array1,
    /* [in] */ const AutoPtr<ArrayOf<T *> > & array2)
{
    return Equals(array1, array2.Get());
}

template<typename T>
Boolean Arrays::Equals(
    /* [in] */ const AutoPtr<ArrayOf<T *> > & array1,
    /* [in] */ const AutoPtr<ArrayOf<T *> > & array2)
{
    return Equals(array1.Get(), array2.Get());
}

template<typename T>
Boolean Arrays::DeepEquals(
    /* [in] */ T* e1,
    /* [in] */ T* e2)
{
    if (e1 == NULL && e2 == NULL) {
        return TRUE;
    }

    if (e1 == NULL || e2 == NULL) {
        return FALSE;
    }

    if (e1->Probe(EIID_IInterface) == e2->Probe(EIID_IInterface)) {
        return TRUE;
    }

    if (IArrayOf::Probe(e1) == NULL || IArrayOf::Probe(e2) == NULL) {
        return Object::Equals(e1, e2);
    }

    /*
     * compare as arrays
     */
    AutoPtr<IArrayOf> a1 = IArrayOf::Probe(e1);
    AutoPtr<IArrayOf> a2 = IArrayOf::Probe(e2);

    Int32 len1, len2;
    a1->GetLength(&len1);
    a2->GetLength(&len2);
    if (len1 != len2) {
        return FALSE;
    }

    for (Int32 i = 0; i < len1; ++i) {
        AutoPtr<IInterface> o1, o2;
        a1->Get(i, (IInterface**)&o1);
        a2->Get(i, (IInterface**)&o2);

        if (DeepEquals(o1, o2) == FALSE) {
            return FALSE;
        }
    }

    return TRUE;
}

template<typename T>
Boolean Arrays::DeepEquals(
    /* [in] */ const AutoPtr<T> & e1,
    /* [in] */ T* e2)
{
    return Arrays::DeepEquals(e1.Get(), e2);
}

template<typename T>
Boolean Arrays::DeepEquals(
    /* [in] */ T* e1,
    /* [in] */ const AutoPtr<T> & e2)
{
    return Arrays::DeepEquals(e1, e2.Get());
}

template<typename T>
Boolean Arrays::DeepEquals(
    /* [in] */ const AutoPtr<T> & e1,
    /* [in] */ const AutoPtr<T> & e2)
{
    return Arrays::DeepEquals(e1.Get(), e2.Get());
}

template<typename T>
ECode Arrays::Sort(
    /* [in] */ ArrayOf<T> * array)
{
    return DualPivotQuicksort::Sort(array);
}

template<typename T>
ECode Arrays::Sort(
    /* [in] */ const AutoPtr<ArrayOf<T> > & array)
{
    return DualPivotQuicksort::Sort(array.Get());
}

template<typename T>
ECode Arrays::Sort(
    /* [in] */ ArrayOf<T> * array,
    /* [in] */ Int32 start,
    /* [in] */ Int32 end)
{
    return DualPivotQuicksort::Sort(array, start, end);
}

template<typename T>
ECode Arrays::Sort(
    /* [in] */ const AutoPtr<ArrayOf<T> > & array,
    /* [in] */ Int32 start,
    /* [in] */ Int32 end)
{
    return DualPivotQuicksort::Sort(array.Get(), start, end);
}

template<typename T>
ECode Arrays::Sort(
    /* [in] */ ArrayOf<T *> * array)
{
    return ComparableTimSort<T>::Sort(array);
}

template<typename T>
ECode Arrays::Sort(
    /* [in] */ const AutoPtr<ArrayOf<T *> >& array)
{
    return ComparableTimSort<T>::Sort(array.Get());
}

template<typename T>
ECode Arrays::Sort(
    /* [in] */ ArrayOf<T *> * array,
    /* [in] */ Int32 start,
    /* [in] */ Int32 end)
{
    return ComparableTimSort<T>::Sort(array, start, end);
}

template<typename T>
ECode Arrays::Sort(
    /* [in] */ const AutoPtr<ArrayOf<T *> >& array,
    /* [in] */ Int32 start,
    /* [in] */ Int32 end)
{
    return ComparableTimSort<T>::Sort(array.Get(), start, end);
}

template<typename T>
ECode Arrays::Sort(
    /* [in] */ ArrayOf<T *> * array,
    /* [in] */ Int32 start,
    /* [in] */ Int32 end,
    /* [in] */ IComparator* comparator)
{
    return TimSort<T>::Sort(array, start, end, comparator);
}

template<typename T>
ECode Arrays::Sort(
    /* [in] */ const AutoPtr<ArrayOf<T *> >& array,
    /* [in] */ Int32 start,
    /* [in] */ Int32 end,
    /* [in] */ IComparator* comparator)
{
    return TimSort<T>::Sort(array.Get(), start, end, comparator);
}

template<typename T>
ECode Arrays::Sort(
    /* [in] */ ArrayOf<T *> * array,
    /* [in] */ IComparator* comparator)
{
    return TimSort<T>::Sort(array, comparator);
}

template<typename T>
ECode Arrays::Sort(
    /* [in] */ const AutoPtr<ArrayOf<T *> >& array,
    /* [in] */ IComparator* comparator)
{
    return TimSort<T>::Sort(array.Get(), comparator);
}

template<typename T>
String Arrays::ToString(
    /* [in] */ ArrayOf<T>* array)
{
    if (array == NULL) {
        return String("NULL");
    }

    if (array->GetLength() == 0) {
        return String("[]");
    }

    StringBuilder sb(array->GetLength() * 7);
    sb.AppendChar('[');
    sb.Append((*array)[0]);
    for (Int32 i = 1; i < array->GetLength(); i++) {
        sb.Append(", ");
        sb.Append((*array)[i]);
    }
    sb.AppendChar(']');
    return sb.ToString();
}

template<typename T>
String Arrays::ToString(
    /* [in] */ const AutoPtr<ArrayOf<T> > & array)
{
    return ToString(array.Get());
}

template<typename T>
Boolean Arrays::DeepToStringContains(
    /* [in] */ IArrayOf * origArray,
    /* [in] */ T * obj)
{
    if (origArray == NULL) {
        return FALSE;
    }

    IInterface * object = TO_IINTERFACE(obj);
    Int32 length;
    origArray->GetLength(&length);
    for (Int32 i = 0; i < length; ++i) {
        AutoPtr<IInterface> element;
        origArray->Get(i, (IInterface**)&element);
        if (element.Get() == object) {
            return TRUE;
        }
    }

    return FALSE;
}

template<typename T>
ECode Arrays::DeepToString(
    /* [in] */ T * obj,
    /* [in] */ IArrayOf * origArray,
    /* [in] */ StringBuilder& sb)
{
    IArrayOf* array = IArrayOf::Probe(obj);
    if (array == NULL) {
        String info = Object::ToString(obj);
        sb.Append(info);
        return NOERROR;
    }

    if (DeepToStringContains(origArray, obj)) {
        sb.Append("[...]");
    }
    else {
        sb.AppendChar('[');
        Int32 length;
        array->GetLength(&length);
        for (Int32 i = 0; i < length; ++i) {
            if (i != 0)  sb += ", ";
            AutoPtr<IInterface> element;
            array->Get(i, (IInterface**)&element);
            DeepToString(element.Get(), origArray, sb);
        }
        sb.AppendChar(']');
    }

    return NOERROR;
}

template<typename T>
Boolean Arrays::DeepToStringContains(
    /* [in] */ ArrayOf<T *> * origArray,
    /* [in] */ T* array)
{
    if (origArray == NULL || origArray->GetLength() == 0) {
        return FALSE;
    }

    for (Int32 i = 0; i < origArray->GetLength(); ++i) {
        if (TO_IINTERFACE((*origArray)[i]) == array) {
            return TRUE;
        }
    }
    return FALSE;
}

template<typename T>
ECode Arrays::DeepToString(
    /* [in] */ T * obj,
    /* [in] */ ArrayOf<T*> * origArray,
    /* [in] */ StringBuilder& sb)
{
    IArrayOf* array = IArrayOf::Probe(obj);
    if (array == NULL) {
        String info = Object::ToString(obj);
        sb.Append(info);
        return NOERROR;
    }

    if (DeepToStringContains(origArray, obj)) {
        sb.Append("[...]");
    }
    else {
        sb.AppendChar('[');
        Int32 length;
        array->GetLength(&length);
        for (Int32 i = 0; i < length; ++i) {
            if (i != 0)  sb += ", ";
            AutoPtr<IInterface> element;
            array->Get(i, (IInterface**)&element);
            DeepToString(element.Get(), origArray, sb);
        }
        sb.AppendChar(']');
    }

    return NOERROR;
}

template<typename T>
String Arrays::DeepToString(
    /* [in] */ ArrayOf<T *> * array)
{
    // Special case null to prevent NPE
    if (array == NULL) {
        return String("NULL");
    }

    // delegate this to the recursive method
    StringBuilder sb(array->GetLength() * 9);
    sb.AppendChar('[');
    for (Int32 i = 0; i < array->GetLength(); ++i) {
        if (i != 0)  sb += ", ";
        DeepToString((*array)[i], array, sb);
    }
    sb.AppendChar(']');
    return sb.ToString();
}

template<typename T>
String Arrays::DeepToString(
    /* [in] */ const AutoPtr<ArrayOf<T *> > & array)
{
    return DeepToString(array.Get());
}

template<typename T>
ECode Arrays::CopyOfRange(
    /* [in] */ ArrayOf<T> * original,
    /* [in] */ Int32 start,
    /* [in] */ Int32 end,
    /* [out, callee] */ ArrayOf<T> ** result)
{
    VALIDATE_NOT_NULL(result)
    *result = NULL;
    assert(original);
    VALIDATE_NOT_NULL(original)

    if (start > end) {
        printf("Arrays", "CopyOfRange: error, E_ILLEGAL_ARGUMENT_EXCEPTION, start %d, end %d", start, end);
        return E_ILLEGAL_ARGUMENT_EXCEPTION;
    }

    Int32 originalLength = original->GetLength();
    if (start < 0 || start > originalLength) {
        printf("Arrays", "CopyOfRange: error, E_ARRAY_INDEX_OUT_OF_BOUNDS_EXCEPTION, start %d, originalLength %d",
            start, originalLength);
        return E_ARRAY_INDEX_OUT_OF_BOUNDS_EXCEPTION;
    }

    Int32 resultLength = end - start;
    Int32 copyLength = Elastos::Core::Math::Min(resultLength, originalLength - start);
    AutoPtr<ArrayOf<T> > array = ArrayOf<T>::Alloc(resultLength);
    array->Copy(original, start, copyLength);
    *result = array;
    REFCOUNT_ADD(*result)
    return NOERROR;
}

template<typename T>
ECode Arrays::CopyOf(
    /* [in] */ ArrayOf<T> * original,
    /* [in] */ Int32 newLength,
    /* [out, callee] */ ArrayOf<T> ** result)
{
    if (newLength < 0) {
        printf("Arrays", "CopyOf: error, E_NAGATIVE_ARRAY_SIZE_EXCEPTION, newLength %d", newLength);
        return E_NAGATIVE_ARRAY_SIZE_EXCEPTION;
    }

    return CopyOfRange(original, 0, newLength, result);
}

template<typename T>
ECode Arrays::CopyOfRange(
    /* [in] */ const AutoPtr<ArrayOf<T> > & original,
    /* [in] */ Int32 start,
    /* [in] */ Int32 end,
    /* [out, callee] */ ArrayOf<T> ** result)
{
    return CopyOfRange(original.Get(), start, end, result);
}

template<typename T>
ECode Arrays::CopyOf(
    /* [in] */ const AutoPtr<ArrayOf<T> > & original,
    /* [in] */ Int32 newLength,
    /* [out, callee] */ ArrayOf<T> ** result)
{
    return CopyOf(original.Get(), newLength, result);
}

template<typename T, typename U>
ECode Arrays::CopyOfRange(
    /* [in] */ ArrayOf<T> * original,
    /* [in] */ Int32 start,
    /* [in] */ Int32 end,
    /* [out, callee] */ ArrayOf<U> ** result)
{
    VALIDATE_NOT_NULL(result)
    *result = NULL;
    assert(original);
    VALIDATE_NOT_NULL(original)

    if (start > end) {
        printf("Arrays", "CopyOfRange: error, E_ILLEGAL_ARGUMENT_EXCEPTION, start %d, end %d", start, end);
        return E_ILLEGAL_ARGUMENT_EXCEPTION;
    }

    Int32 originalLength = original->GetLength();
    if (start < 0 || start > originalLength) {
        printf("Arrays", "CopyOfRange: error, E_ARRAY_INDEX_OUT_OF_BOUNDS_EXCEPTION, start %d, originalLength %d",
            start, originalLength);
        return E_ARRAY_INDEX_OUT_OF_BOUNDS_EXCEPTION;
    }

    Int32 resultLength = end - start;
    Int32 copyLength = Elastos::Core::Math::Min(resultLength, originalLength - start);
    AutoPtr<ArrayOf<U> > array = ArrayOf<U>::Alloc(resultLength);
    for (Int32 i = 0; i < original->GetLength(); ++i) {
        array->Set(i, (U)(*original)[i]); // TODO: only work with primitives
    }

    *result = result;
    REFCOUNT_ADD(*result)
    return NOERROR;
}

template<typename T, typename U>
ECode Arrays::CopyOf(
    /* [in] */ ArrayOf<T> * original,
    /* [in] */ Int32 newLength,
    /* [out, callee] */ ArrayOf<U> ** result)
{
    if (newLength < 0) {
        printf("Arrays", "CopyOf: error, E_NAGATIVE_ARRAY_SIZE_EXCEPTION, newLength %d", newLength);
        return E_NAGATIVE_ARRAY_SIZE_EXCEPTION;
    }

    return CopyOfRange(original, 0, newLength, result);
}

template<typename T, typename U>
ECode Arrays::CopyOfRange(
    /* [in] */ const AutoPtr<ArrayOf<T> > & original,
    /* [in] */ Int32 start,
    /* [in] */ Int32 end,
    /* [out, callee] */ ArrayOf<U> ** result)
{
    return CopyOfRange(original.Get(), start, end, result);
}

template<typename T, typename U>
ECode Arrays::CopyOf(
    /* [in] */ const AutoPtr<ArrayOf<T> > & original,
    /* [in] */ Int32 newLength,
    /* [out, callee] */ ArrayOf<U> ** result)
{
    return CopyOf(original, newLength, result);
}


} // namespace Utility
} // namespace Elastos

#endif // __ELASTOS_UTILITY_ARRAYS_H__
