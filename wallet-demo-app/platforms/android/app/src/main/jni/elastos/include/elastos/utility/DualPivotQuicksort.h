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

#ifndef __ELASTOS_UTILITY_DUALPIVOTQUICKSORT_H__
#define __ELASTOS_UTILITY_DUALPIVOTQUICKSORT_H__

#include <elastos.h>

namespace Elastos{
namespace Utility{

class DualPivotQuicksort
{
public:
    /*
     * Sorting methods for 7 primitive types.
     */

    /**
     * Sorts the specified array into ascending numerical order.
     *
     * @param a the array to be sorted
     */
    ECO_PUBLIC static CARAPI Sort(
        /* [in] */ ArrayOf<Int32>* a);

    /**
     * Sorts the specified range of the array into ascending order. The range
     * to be sorted extends from the index {@code fromIndex}, inclusive, to
     * the index {@code toIndex}, exclusive. If {@code fromIndex == toIndex},
     * the range to be sorted is empty (and the call is a no-op).
     *
     * @param a the array to be sorted
     * @param fromIndex the index of the first element, inclusive, to be sorted
     * @param toIndex the index of the last element, exclusive, to be sorted
     * @throws IllegalArgumentException if {@code fromIndex > toIndex}
     * @throws ArrayIndexOutOfBoundsException
     *     if {@code fromIndex < 0} or {@code toIndex > a.length}
     */
    ECO_PUBLIC static CARAPI Sort(
        /* [in] */ ArrayOf<Int32>* a,
        /* [in] */ Int32 fromIndex,
        /* [in] */ Int32 toIndex);

    /**
     * Sorts the specified array into ascending numerical order.
     *
     * @param a the array to be sorted
     */
    ECO_PUBLIC static CARAPI Sort(
        /* [in] */ ArrayOf<Int64>* a);

    /**
     * Sorts the specified range of the array into ascending order. The range
     * to be sorted extends from the index {@code fromIndex}, inclusive, to
     * the index {@code toIndex}, exclusive. If {@code fromIndex == toIndex},
     * the range to be sorted is empty (and the call is a no-op).
     *
     * @param a the array to be sorted
     * @param fromIndex the index of the first element, inclusive, to be sorted
     * @param toIndex the index of the last element, exclusive, to be sorted
     * @throws IllegalArgumentException if {@code fromIndex > toIndex}
     * @throws ArrayIndexOutOfBoundsException
     *     if {@code fromIndex < 0} or {@code toIndex > a.length}
     */
    ECO_PUBLIC static CARAPI Sort(
        /* [in] */ ArrayOf<Int64>* a,
        /* [in] */ Int32 fromIndex,
        /* [in] */ Int32 toIndex);

    /**
     * Sorts the specified array into ascending numerical order.
     *
     * @param a the array to be sorted
     */
    ECO_PUBLIC static CARAPI Sort(
        /* [in] */ ArrayOf<Int16>* a);

    /**
     * Sorts the specified range of the array into ascending order. The range
     * to be sorted extends from the index {@code fromIndex}, inclusive, to
     * the index {@code toIndex}, exclusive. If {@code fromIndex == toIndex},
     * the range to be sorted is empty (and the call is a no-op).
     *
     * @param a the array to be sorted
     * @param fromIndex the index of the first element, inclusive, to be sorted
     * @param toIndex the index of the last element, exclusive, to be sorted
     * @throws IllegalArgumentException if {@code fromIndex > toIndex}
     * @throws ArrayIndexOutOfBoundsException
     *     if {@code fromIndex < 0} or {@code toIndex > a.length}
     */
    ECO_PUBLIC static CARAPI Sort(
        /* [in] */ ArrayOf<Int16>* a,
        /* [in] */ Int32 fromIndex,
        /* [in] */ Int32 toIndex);

    /**
     * Sorts the specified array into ascending numerical order.
     *
     * @param a the array to be sorted
     */
    ECO_PUBLIC static CARAPI Sort(
        /* [in] */ ArrayOf<Char32>* a);

    /**
     * Sorts the specified range of the array into ascending order. The range
     * to be sorted extends from the index {@code fromIndex}, inclusive, to
     * the index {@code toIndex}, exclusive. If {@code fromIndex == toIndex},
     * the range to be sorted is empty (and the call is a no-op).
     *
     * @param a the array to be sorted
     * @param fromIndex the index of the first element, inclusive, to be sorted
     * @param toIndex the index of the last element, exclusive, to be sorted
     * @throws IllegalArgumentException if {@code fromIndex > toIndex}
     * @throws ArrayIndexOutOfBoundsException
     *     if {@code fromIndex < 0} or {@code toIndex > a.length}
     */
    ECO_PUBLIC static CARAPI Sort(
        /* [in] */ ArrayOf<Char32>* a,
        /* [in] */ Int32 fromIndex,
        /* [in] */ Int32 toIndex);

    /**
     * Sorts the specified array into ascending numerical order.
     *
     * @param a the array to be sorted
     */
    ECO_PUBLIC static CARAPI Sort(
        /* [in] */ ArrayOf<Byte>* a);

    /**
     * Sorts the specified range of the array into ascending order. The range
     * to be sorted extends from the index {@code fromIndex}, inclusive, to
     * the index {@code toIndex}, exclusive. If {@code fromIndex == toIndex},
     * the range to be sorted is empty (and the call is a no-op).
     *
     * @param a the array to be sorted
     * @param fromIndex the index of the first element, inclusive, to be sorted
     * @param toIndex the index of the last element, exclusive, to be sorted
     * @throws IllegalArgumentException if {@code fromIndex > toIndex}
     * @throws ArrayIndexOutOfBoundsException
     *     if {@code fromIndex < 0} or {@code toIndex > a.length}
     */
    ECO_PUBLIC static CARAPI Sort(
        /* [in] */ ArrayOf<Byte>* a,
        /* [in] */ Int32 fromIndex,
        /* [in] */ Int32 toIndex);

    /**
     * Sorts the specified array into ascending numerical order.
     *
     * <p>The {@code <} relation does not provide a total order on all float
     * values: {@code -0.0f == 0.0f} is {@code true} and a {@code Float.NaN}
     * value compares neither less than, greater than, nor equal to any value,
     * even itself. This method uses the total order imposed by the method
     * {@link Float#compareTo}: {@code -0.0f} is treated as less than value
     * {@code 0.0f} and {@code Float.NaN} is considered greater than any
     * other value and all {@code Float.NaN} values are considered equal.
     *
     * @param a the array to be sorted
     */
    ECO_PUBLIC static CARAPI Sort(
        /* [in] */ ArrayOf<Float>* a);

    /**
     * Sorts the specified range of the array into ascending order. The range
     * to be sorted extends from the index {@code fromIndex}, inclusive, to
     * the index {@code toIndex}, exclusive. If {@code fromIndex == toIndex},
     * the range to be sorted is empty  and the call is a no-op).
     *
     * <p>The {@code <} relation does not provide a total order on all float
     * values: {@code -0.0f == 0.0f} is {@code true} and a {@code Float.NaN}
     * value compares neither less than, greater than, nor equal to any value,
     * even itself. This method uses the total order imposed by the method
     * {@link Float#compareTo}: {@code -0.0f} is treated as less than value
     * {@code 0.0f} and {@code Float.NaN} is considered greater than any
     * other value and all {@code Float.NaN} values are considered equal.
     *
     * @param a the array to be sorted
     * @param fromIndex the index of the first element, inclusive, to be sorted
     * @param toIndex the index of the last element, exclusive, to be sorted
     * @throws IllegalArgumentException if {@code fromIndex > toIndex}
     * @throws ArrayIndexOutOfBoundsException
     *     if {@code fromIndex < 0} or {@code toIndex > a.length}
     */
    ECO_PUBLIC static CARAPI Sort(
        /* [in] */ ArrayOf<Float>* a,
        /* [in] */ Int32 fromIndex,
        /* [in] */ Int32 toIndex);

    /**
     * Sorts the specified array into ascending numerical order.
     *
     * <p>The {@code <} relation does not provide a total order on all double
     * values: {@code -0.0d == 0.0d} is {@code true} and a {@code Double.NaN}
     * value compares neither less than, greater than, nor equal to any value,
     * even itself. This method uses the total order imposed by the method
     * {@link Double#compareTo}: {@code -0.0d} is treated as less than value
     * {@code 0.0d} and {@code Double.NaN} is considered greater than any
     * other value and all {@code Double.NaN} values are considered equal.
     *
     * @param a the array to be sorted
     */
    ECO_PUBLIC static CARAPI Sort(
        /* [in] */ ArrayOf<Double>* a);

    /**
     * Sorts the specified range of the array into ascending order. The range
     * to be sorted extends from the index {@code fromIndex}, inclusive, to
     * the index {@code toIndex}, exclusive. If {@code fromIndex == toIndex},
     * the range to be sorted is empty (and the call is a no-op).
     *
     * <p>The {@code <} relation does not provide a total order on all double
     * values: {@code -0.0d == 0.0d} is {@code true} and a {@code Double.NaN}
     * value compares neither less than, greater than, nor equal to any value,
     * even itself. This method uses the total order imposed by the method
     * {@link Double#compareTo}: {@code -0.0d} is treated as less than value
     * {@code 0.0d} and {@code Double.NaN} is considered greater than any
     * other value and all {@code Double.NaN} values are considered equal.
     *
     * @param a the array to be sorted
     * @param fromIndex the index of the first element, inclusive, to be sorted
     * @param toIndex the index of the last element, exclusive, to be sorted
     * @throws IllegalArgumentException if {@code fromIndex > toIndex}
     * @throws ArrayIndexOutOfBoundsException
     *     if {@code fromIndex < 0} or {@code toIndex > a.length}
     */
    ECO_PUBLIC static CARAPI Sort(
        /* [in] */ ArrayOf<Double>* a,
        /* [in] */ Int32 fromIndex,
        /* [in] */ Int32 toIndex);

private:
    /**
     * Prevents instantiation.
     */
    DualPivotQuicksort();
    DualPivotQuicksort(const DualPivotQuicksort&);

    /**
     * Sorts the specified range of the array into ascending order. This
     * method differs from the public {@code sort} method in that the
     * {@code right} index is inclusive, and it does no range checking
     * on {@code left} or {@code right}.
     *
     * @param a the array to be sorted
     * @param left the index of the first element, inclusive, to be sorted
     * @param right the index of the last element, inclusive, to be sorted
     */
    static CARAPI DoSort(
        /* [in] */ ArrayOf<Int32>* a,
        /* [in] */ Int32 left,
        /* [in] */ Int32 right);

    /**
     * Sorts the specified range of the array into ascending order by the
     * Dual-Pivot Quicksort algorithm.
     *
     * @param a the array to be sorted
     * @param left the index of the first element, inclusive, to be sorted
     * @param right the index of the last element, inclusive, to be sorted
     */
    static CARAPI _DualPivotQuicksort(
        /* [in] */ ArrayOf<Int32>* a,
        /* [in] */ Int32 left,
        /* [in] */ Int32 right);

    /**
     * Sorts the specified range of the array into ascending order. This
     * method differs from the public {@code sort} method in that the
     * {@code right} index is inclusive, and it does no range checking on
     * {@code left} or {@code right}.
     *
     * @param a the array to be sorted
     * @param left the index of the first element, inclusive, to be sorted
     * @param right the index of the last element, inclusive, to be sorted
     */
    static CARAPI DoSort(
        /* [in] */ ArrayOf<Int64>* a,
        /* [in] */ Int32 left,
        /* [in] */ Int32 right);

    /**
     * Sorts the specified range of the array into ascending order by the
     * Dual-Pivot Quicksort algorithm.
     *
     * @param a the array to be sorted
     * @param left the index of the first element, inclusive, to be sorted
     * @param right the index of the last element, inclusive, to be sorted
     */
    static CARAPI _DualPivotQuicksort(
        /* [in] */ ArrayOf<Int64>* a,
        /* [in] */ Int32 left,
        /* [in] */ Int32 right);

    /**
     * Sorts the specified range of the array into ascending order. This
     * method differs from the public {@code sort} method in that the
     * {@code right} index is inclusive, and it does no range checking on
     * {@code left} or {@code right}.
     *
     * @param a the array to be sorted
     * @param left the index of the first element, inclusive, to be sorted
     * @param right the index of the last element, inclusive, to be sorted
     */
    static CARAPI DoSort(
        /* [in] */ ArrayOf<Int16>* a,
        /* [in] */ Int32 left,
        /* [in] */ Int32 right);

    /**
     * Sorts the specified range of the array into ascending order by the
     * Dual-Pivot Quicksort algorithm.
     *
     * @param a the array to be sorted
     * @param left the index of the first element, inclusive, to be sorted
     * @param right the index of the last element, inclusive, to be sorted
     */
    static CARAPI _DualPivotQuicksort(
        /* [in] */ ArrayOf<Int16>* a,
        /* [in] */ Int32 left,
        /* [in] */ Int32 right);

    /**
     * Sorts the specified range of the array into ascending order. This
     * method differs from the public {@code sort} method in that the
     * {@code right} index is inclusive, and it does no range checking on
     * {@code left} or {@code right}.
     *
     * @param a the array to be sorted
     * @param left the index of the first element, inclusive, to be sorted
     * @param right the index of the last element, inclusive, to be sorted
     */
    static CARAPI DoSort(
        /* [in] */ ArrayOf<Char32>* a,
        /* [in] */ Int32 left,
        /* [in] */ Int32 right);

    /**
     * Sorts the specified range of the array into ascending order by the
     * Dual-Pivot Quicksort algorithm.
     *
     * @param a the array to be sorted
     * @param left the index of the first element, inclusive, to be sorted
     * @param right the index of the last element, inclusive, to be sorted
     */
    static CARAPI _DualPivotQuicksort(
        /* [in] */ ArrayOf<Char32>* a,
        /* [in] */ Int32 left,
        /* [in] */ Int32 right);

    /**
     * Sorts the specified range of the array into ascending order. This
     * method differs from the public {@code sort} method in that the
     * {@code right} index is inclusive, and it does no range checking on
     * {@code left} or {@code right}.
     *
     * @param a the array to be sorted
     * @param left the index of the first element, inclusive, to be sorted
     * @param right the index of the last element, inclusive, to be sorted
     */
    static CARAPI DoSort(
        /* [in] */ ArrayOf<Byte>* a,
        /* [in] */ Int32 left,
        /* [in] */ Int32 right);

    /**
     * Sorts the specified range of the array into ascending order by the
     * Dual-Pivot Quicksort algorithm.
     *
     * @param a the array to be sorted
     * @param left the index of the first element, inclusive, to be sorted
     * @param right the index of the last element, inclusive, to be sorted
     */
    static CARAPI _DualPivotQuicksort(
        /* [in] */ ArrayOf<Byte>* a,
        /* [in] */ Int32 left,
        /* [in] */ Int32 right);

    /**
     * Sorts the specified range of the array into ascending order. The
     * sort is done in three phases to avoid expensive comparisons in the
     * inner loop. The comparisons would be expensive due to anomalies
     * associated with negative zero {@code -0.0f} and {@code Float.NaN}.
     *
     * @param a the array to be sorted
     * @param left the index of the first element, inclusive, to be sorted
     * @param right the index of the last element, inclusive, to be sorted
     */
    static CARAPI SortNegZeroAndNaN(
        /* [in] */ ArrayOf<Float>* a,
        /* [in] */ Int32 left,
        /* [in] */ Int32 right);

    /**
     * Returns the index of some zero element in the specified range via
     * binary search. The range is assumed to be sorted, and must contain
     * at least one zero.
     *
     * @param a the array to be searched
     * @param low the index of the first element, inclusive, to be searched
     * @param high the index of the last element, inclusive, to be searched
     */
    static CARAPI_(Int32) FindAnyZero(
        /* [in] */ ArrayOf<Float>* a,
        /* [in] */ Int32 low,
        /* [in] */ Int32 high);

    /**
     * Sorts the specified range of the array into ascending order. This
     * method differs from the public {@code sort} method in three ways:
     * {@code right} index is inclusive, it does no range checking on
     * {@code left} or {@code right}, and it does not handle negative
     * zeros or NaNs in the array.
     *
     * @param a the array to be sorted, which must not contain -0.0f or NaN
     * @param left the index of the first element, inclusive, to be sorted
     * @param right the index of the last element, inclusive, to be sorted
     */
    static CARAPI DoSort(
        /* [in] */ ArrayOf<Float>* a,
        /* [in] */ Int32 left,
        /* [in] */ Int32 right);

    /**
     * Sorts the specified range of the array into ascending order by the
     * Dual-Pivot Quicksort algorithm.
     *
     * @param a the array to be sorted
     * @param left the index of the first element, inclusive, to be sorted
     * @param right the index of the last element, inclusive, to be sorted
     */
    static CARAPI _DualPivotQuicksort(
        /* [in] */ ArrayOf<Float>* a,
        /* [in] */ Int32 left,
        /* [in] */ Int32 right);

    /**
     * Sorts the specified range of the array into ascending order. The
     * sort is done in three phases to avoid expensive comparisons in the
     * inner loop. The comparisons would be expensive due to anomalies
     * associated with negative zero {@code -0.0d} and {@code Double.NaN}.
     *
     * @param a the array to be sorted
     * @param left the index of the first element, inclusive, to be sorted
     * @param right the index of the last element, inclusive, to be sorted
     */
    static CARAPI SortNegZeroAndNaN(
        /* [in] */ ArrayOf<Double>* a,
        /* [in] */ Int32 left,
        /* [in] */ Int32 right);

    /**
     * Returns the index of some zero element in the specified range via
     * binary search. The range is assumed to be sorted, and must contain
     * at least one zero.
     *
     * @param a the array to be searched
     * @param low the index of the first element, inclusive, to be searched
     * @param high the index of the last element, inclusive, to be searched
     */
    static CARAPI_(Int32) FindAnyZero(
        /* [in] */ ArrayOf<Double>* a,
        /* [in] */ Int32 low,
        /* [in] */ Int32 high);

    /**
     * Sorts the specified range of the array into ascending order. This
     * method differs from the public {@code sort} method in three ways:
     * {@code right} index is inclusive, it does no range checking on
     * {@code left} or {@code right}, and it does not handle negative
     * zeros or NaNs in the array.
     *
     * @param a the array to be sorted, which must not contain -0.0d and NaN
     * @param left the index of the first element, inclusive, to be sorted
     * @param right the index of the last element, inclusive, to be sorted
     */
    static CARAPI DoSort(
        /* [in] */ ArrayOf<Double>* a,
        /* [in] */ Int32 left,
        /* [in] */ Int32 right);

    /**
     * Sorts the specified range of the array into ascending order by the
     * Dual-Pivot Quicksort algorithm.
     *
     * @param a the array to be sorted
     * @param left the index of the first element, inclusive, to be sorted
     * @param right the index of the last element, inclusive, to be sorted
     */
    static CARAPI _DualPivotQuicksort(
        /* [in] */ ArrayOf<Double>* a,
        /* [in] */ Int32 left,
        /* [in] */ Int32 right);

private:
    /**
     * If the length of an array to be sorted is less than this
     * constant, insertion sort is used in preference to Quicksort.
     */
    static const Int32 INSERTION_SORT_THRESHOLD;

    /**
     * If the length of a byte array to be sorted is greater than
     * this constant, counting sort is used in preference to Quicksort.
     */
    static const Int32 COUNTING_SORT_THRESHOLD_FOR_BYTE;

    /**
     * If the length of a short or char array to be sorted is greater
     * than this constant, counting sort is used in preference to Quicksort.
     */
    static const Int32 COUNTING_SORT_THRESHOLD_FOR_SHORT_OR_CHAR;

    /** The number of distinct short values. */
    static const Int32 NUM_SHORT_VALUES;

    /** The number of distinct char values. */
    static const Int32 NUM_CHAR_VALUES;

    /** The number of distinct byte values. */
    static const Int32 NUM_BYTE_VALUES;
};

} // namespace Utility
} // namespace Elastos

#endif //__ELASTOS_UTILITY_DUALPIVOTQUICKSORT_H__
