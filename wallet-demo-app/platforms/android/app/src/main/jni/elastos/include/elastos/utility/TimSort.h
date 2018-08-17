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

#ifndef __ELASTOS_UTILITY_TIMSORT_H__
#define __ELASTOS_UTILITY_TIMSORT_H__

#include "elastos/core/Object.h"
#include "elastos/core/Math.h"
#include "elastos/utility/ComparableTimSort.h"
//#include <cutils/log.h>

using Elastos::Core::IComparator;
using Elastos::Core::IComparable;

namespace Elastos {
namespace Utility {

template <typename T>
class TimSort
    : public Object
{
public:
    /*
     * The next two methods (which are package private and static) constitute
     * the entire API of this class.  Each of these methods obeys the contract
     * of the public method with the same signature in java.util.Arrays.
     */

    static CARAPI Sort(
        /* [in] */ ArrayOf<T*>* a,
        /* [in] */ IComparator* c);

    static CARAPI Sort(
        /* [in] */ ArrayOf<T*>* a,
        /* [in] */ Int32 lo,
        /* [in] */ Int32 hi,
        /* [in] */ IComparator* c);

private:
    /**
     * Creates a TimSort instance to maintain the state of an ongoing sort.
     *
     * @param a the array to be sorted
     */
    TimSort(
        /* [in] */ ArrayOf<T*>* a,
        /* [in] */ IComparator* c);

    /**
     * Sorts the specified portion of the specified array using a binary
     * insertion sort.  This is the best method for sorting small numbers
     * of elements.  It requires O(n log n) compares, but O(n^2) data
     * movement (worst case).
     *
     * If the initial part of the specified range is already sorted,
     * this method can take advantage of it: the method assumes that the
     * elements from index {@code lo}, inclusive, to {@code start},
     * exclusive are already sorted.
     *
     * @param a the array in which a range is to be sorted
     * @param lo the index of the first element in the range to be sorted
     * @param hi the index after the last element in the range to be sorted
     * @param start the index of the first element in the range that is
     *        not already known to be sorted (@code lo <= start <= hi}
     */
    // @SuppressWarnings("fallthrough")
    static CARAPI BinarySort(
        /* [in] */ ArrayOf<T*>* a,
        /* [in] */ Int32 lo,
        /* [in] */ Int32 hi,
        /* [in] */ Int32 start,
        /* [in] */ IComparator* c);

    /**
     * Returns the length of the run beginning at the specified position in
     * the specified array and reverses the run if it is descending (ensuring
     * that the run will always be ascending when the method returns).
     *
     * A run is the longest ascending sequence with:
     *
     *    a[lo] <= a[lo + 1] <= a[lo + 2] <= ...
     *
     * or the longest descending sequence with:
     *
     *    a[lo] >  a[lo + 1] >  a[lo + 2] >  ...
     *
     * For its intended use in a stable mergesort, the strictness of the
     * definition of "descending" is needed so that the call can safely
     * reverse a descending sequence without violating stability.
     *
     * @param a the array in which a run is to be counted and possibly reversed
     * @param lo index of the first element in the run
     * @param hi index after the last element that may be contained in the run.
              It is required that @code{lo < hi}.
     * @return  the length of the run beginning at the specified position in
     *          the specified array
     */
    // @SuppressWarnings("unchecked")
    static CARAPI_(Int32) CountRunAndMakeAscending(
        /* [in] */ ArrayOf<T*>* a,
        /* [in] */ Int32 lo,
        /* [in] */ Int32 hi,
        /* [in] */ IComparator* c);

    /**
     * Reverse the specified range of the specified array.
     *
     * @param a the array in which a range is to be reversed
     * @param lo the index of the first element in the range to be reversed
     * @param hi the index after the last element in the range to be reversed
     */
    static CARAPI ReverseRange(
        /* [in] */ ArrayOf<T*>* a,
        /* [in] */ Int32 lo,
        /* [in] */ Int32 hi);

    /**
     * Returns the minimum acceptable run length for an array of the specified
     * length. Natural runs shorter than this will be extended with
     * {@link #binarySort}.
     *
     * Roughly speaking, the computation is:
     *
     *  If n < MIN_MERGE, return n (it's too small to bother with fancy stuff).
     *  Else if n is an exact power of 2, return MIN_MERGE/2.
     *  Else return an int k, MIN_MERGE/2 <= k <= MIN_MERGE, such that n/k
     *   is close to, but strictly less than, an exact power of 2.
     *
     * For the rationale, see listsort.txt.
     *
     * @param n the length of the array to be sorted
     * @return the length of the minimum run to be merged
     */
    static CARAPI_(Int32) MinRunLength(
        /* [in] */ Int32 n);

    /**
     * Pushes the specified run onto the pending-run stack.
     *
     * @param runBase index of the first element in the run
     * @param runLen  the number of elements in the run
     */
    CARAPI PushRun(
        /* [in] */ Int32 runBase,
        /* [in] */ Int32 runLen);

    /**
     * Examines the stack of runs waiting to be merged and merges adjacent runs
     * until the stack invariants are reestablished:
     *
     *     1. runLen[i - 3] > runLen[i - 2] + runLen[i - 1]
     *     2. runLen[i - 2] > runLen[i - 1]
     *
     * This method is called each time a new run is pushed onto the stack,
     * so the invariants are guaranteed to hold for i < stackSize upon
     * entry to the method.
     */
    CARAPI MergeCollapse();

    /**
     * Merges all runs on the stack until only one remains.  This method is
     * called once, to complete the sort.
     */
    CARAPI MergeForceCollapse();

    /**
     * Merges the two runs at stack indices i and i+1.  Run i must be
     * the penultimate or antepenultimate run on the stack.  In other words,
     * i must be equal to stackSize-2 or stackSize-3.
     *
     * @param i stack index of the first of the two runs to merge
     */
    // @SuppressWarnings("unchecked")
    CARAPI MergeAt(
        /* [in] */ Int32 i);

    /**
     * Locates the position at which to insert the specified key into the
     * specified sorted range; if the range contains an element equal to key,
     * returns the index of the leftmost equal element.
     *
     * @param key the key whose insertion point to search for
     * @param a the array in which to search
     * @param base the index of the first element in the range
     * @param len the length of the range; must be > 0
     * @param hint the index at which to begin the search, 0 <= hint < n.
     *     The closer hint is to the result, the faster this method will run.
     * @return the int k,  0 <= k <= n such that a[b + k - 1] < key <= a[b + k],
     *    pretending that a[b - 1] is minus infinity and a[b + n] is infinity.
     *    In other words, key belongs at index b + k; or in other words,
     *    the first k elements of a should precede key, and the last n - k
     *    should follow it.
     */
    static CARAPI_(Int32) GallopLeft(
        /* [in] */ T* key,
        /* [in] */ ArrayOf<T*>* a,
        /* [in] */ Int32 base,
        /* [in] */ Int32 len,
        /* [in] */ Int32 hint,
        /* [in] */ IComparator* c);

    /**
     * Like gallopLeft, except that if the range contains an element equal to
     * key, gallopRight returns the index after the rightmost equal element.
     *
     * @param key the key whose insertion point to search for
     * @param a the array in which to search
     * @param base the index of the first element in the range
     * @param len the length of the range; must be > 0
     * @param hint the index at which to begin the search, 0 <= hint < n.
     *     The closer hint is to the result, the faster this method will run.
     * @return the int k,  0 <= k <= n such that a[b + k - 1] <= key < a[b + k]
     */
    static CARAPI_(Int32) GallopRight(
        /* [in] */ T* key,
        /* [in] */ ArrayOf<T*>* a,
        /* [in] */ Int32 base,
        /* [in] */ Int32 len,
        /* [in] */ Int32 hint,
        /* [in] */ IComparator* c);

    /**
     * Merges two adjacent runs in place, in a stable fashion.  The first
     * element of the first run must be greater than the first element of the
     * second run (a[base1] > a[base2]), and the last element of the first run
     * (a[base1 + len1-1]) must be greater than all elements of the second run.
     *
     * For performance, this method should be called only when len1 <= len2;
     * its twin, mergeHi should be called if len1 >= len2.  (Either method
     * may be called if len1 == len2.)
     *
     * @param base1 index of first element in first run to be merged
     * @param len1  length of first run to be merged (must be > 0)
     * @param base2 index of first element in second run to be merged
     *        (must be aBase + aLen)
     * @param len2  length of second run to be merged (must be > 0)
     */
    CARAPI MergeLo(
        /* [in] */ Int32 base1,
        /* [in] */ Int32 len1,
        /* [in] */ Int32 base2,
        /* [in] */ Int32 len2);

    /**
     * Like mergeLo, except that this method should be called only if
     * len1 >= len2; mergeLo should be called if len1 <= len2.  (Either method
     * may be called if len1 == len2.)
     *
     * @param base1 index of first element in first run to be merged
     * @param len1  length of first run to be merged (must be > 0)
     * @param base2 index of first element in second run to be merged
     *        (must be aBase + aLen)
     * @param len2  length of second run to be merged (must be > 0)
     */
    // @SuppressWarnings("unchecked")
    CARAPI MergeHi(
        /* [in] */ Int32 base1,
        /* [in] */ Int32 len1,
        /* [in] */ Int32 base2,
        /* [in] */ Int32 len2);

    /**
     * Ensures that the external array tmp has at least the specified
     * number of elements, increasing its size if necessary.  The size
     * increases exponentially to ensure amortized linear time complexity.
     *
     * @param minCapacity the minimum required capacity of the tmp array
     * @return tmp, whether or not it grew
     */
    CARAPI_(AutoPtr< ArrayOf<T*> >) EnsureCapacity(
        /* [in] */ Int32 minCapacity);

private:
    /**
     * This is the minimum sized sequence that will be merged.  Shorter
     * sequences will be lengthened by calling binarySort.  If the entire
     * array is less than this length, no merges will be performed.
     *
     * This constant should be a power of two.  It was 64 in Tim Peter's C
     * implementation, but 32 was empirically determined to work better in
     * this implementation.  In the unlikely event that you set this constant
     * to be a number that's not a power of two, you'll need to change the
     * {@link #minRunLength} computation.
     *
     * If you decrease this constant, you must change the stackLen
     * computation in the TimSort constructor, or you risk an
     * ArrayOutOfBounds exception.  See listsort.txt for a discussion
     * of the minimum stack length required as a function of the length
     * of the array being sorted and the minimum merge sequence length.
     */
    static const Int32 MIN_MERGE;// = 32;

    /**
     * When we get into galloping mode, we stay there until both runs win less
     * often than MIN_GALLOP consecutive times.
     */
    static const Int32 MIN_GALLOP;// = 7;

    /**
     * Maximum initial size of tmp array, which is used for merging.  The array
     * can grow to accommodate demand.
     *
     * Unlike Tim's original C version, we do not allocate this much storage
     * when sorting smaller arrays.  This change was required for performance.
     */
    static const Int32 INITIAL_TMP_STORAGE_LENGTH;// = 256;

    /**
     * Asserts have been placed in if-statements for performace. To enable them,
     * set this field to true and enable them in VM with a command line flag.
     * If you modify this class, please do test the asserts!
     */
    static const Boolean DEBUG;// = FALSE;

private:
    /**
     * The array being sorted.
     */
    AutoPtr< ArrayOf<T*> > mA;

    /**
     * The comparator for this sort.
     */
    AutoPtr<IComparator> mC;

    /**
     * This controls when we get *into* galloping mode.  It is initialized
     * to MIN_GALLOP.  The mergeLo and mergeHi methods nudge it higher for
     * random data, and lower for highly structured data.
     */
    Int32 mMinGallop; // = MIN_GALLOP;

    /**
     * Temp storage for merges.
     */
    AutoPtr< ArrayOf<T*> > mTmp;

    /**
     * A stack of pending runs yet to be merged.  Run i starts at
     * address base[i] and extends for len[i] elements.  It's always
     * true (so long as the indices are in bounds) that:
     *
     *     runBase[i] + runLen[i] == runBase[i + 1]
     *
     * so we could cut the storage for this, but it's a minor amount,
     * and keeping all the info explicit simplifies the code.
     */
    Int32 mStackSize; // = 0;  // Number of pending runs on stack
    AutoPtr< ArrayOf<Int32> > mRunBase;
    AutoPtr< ArrayOf<Int32> > mRunLen;
};

//================================================================================
template <typename T>
const Int32 TimSort<T>::MIN_MERGE = 32;

template <typename T>
const Int32 TimSort<T>::MIN_GALLOP = 7;

template <typename T>
const Int32 TimSort<T>::INITIAL_TMP_STORAGE_LENGTH = 256;

template <typename T>
const Boolean TimSort<T>::DEBUG = TRUE;

template <typename T>
TimSort<T>::TimSort(
    /* [in] */ ArrayOf<T*>* a,
    /* [in] */ IComparator* c)
    : mMinGallop(MIN_GALLOP)
    , mStackSize(0)
{
    mA = a;
    mC = c;

    // Allocate temp storage (which may be increased later if necessary)
    Int32 len = mA->GetLength();
    // @SuppressWarnings({"unchecked", "UnnecessaryLocalVariable"})
    AutoPtr< ArrayOf<T*> > newArray = ArrayOf<T*>::Alloc(
        len < 2 * INITIAL_TMP_STORAGE_LENGTH ? (UInt32)len >> 1 : INITIAL_TMP_STORAGE_LENGTH);
    mTmp = newArray;

    /*
     * Allocate runs-to-be-merged stack (which cannot be expanded).  The
     * stack length requirements are described in listsort.txt.  The C
     * version always uses the same stack length (85), but this was
     * measured to be too expensive when sorting "mid-sized" arrays (e.g.,
     * 100 elements) in Java.  Therefore, we use smaller (but sufficiently
     * large) stack lengths for smaller arrays.  The "magic numbers" in the
     * computation below must be changed if MIN_MERGE is decreased.  See
     * the MIN_MERGE declaration above for more information.
     */
    Int32 stackLen = (len <    120  ?  5 :
                    len <   1542  ? 10 :
                    len < 119151  ? 19 : 40);
    mRunBase = ArrayOf<Int32>::Alloc(stackLen);
    mRunLen = ArrayOf<Int32>::Alloc(stackLen);
}

template <typename T>
ECode TimSort<T>::Sort(
    /* [in] */ ArrayOf<T*>* a,
    /* [in] */ IComparator* c)
{
    return Sort(a, 0, a->GetLength(), c);
}

template <typename T>
ECode TimSort<T>::Sort(
    /* [in] */ ArrayOf<T*>* a,
    /* [in] */ Int32 lo,
    /* [in] */ Int32 hi,
    /* [in] */ IComparator* c)
{
    if (c == NULL) {
        return ComparableTimSort<T>::Sort(a, lo, hi);
    }

    if (lo < 0 || hi > a->GetLength()) {
        //ALOGE("Arrays::CheckStartAndEnd: E_ARRAY_INDEX_OUT_OF_BOUNDS_EXCEPTION: len: %d, start: %d, end: %d",
        //    a->GetLength(), lo, hi);
        return E_ARRAY_INDEX_OUT_OF_BOUNDS_EXCEPTION;
    }
    if (lo > hi) {
        //ALOGE("Arrays::CheckStartAndEnd: E_ILLEGAL_ARGUMENT_EXCEPTION: len: %d, start: %d, end: %d",
        //    a->GetLength(), lo, hi);
        return E_ILLEGAL_ARGUMENT_EXCEPTION;
    }

    Int32 nRemaining  = hi - lo;
    if (nRemaining < 2)
        return NOERROR;  // Arrays of size 0 and 1 are always sorted

    // If array is small, do a "mini-TimSort" with no merges
    if (nRemaining < MIN_MERGE) {
        Int32 initRunLen = CountRunAndMakeAscending(a, lo, hi, c);
        BinarySort(a, lo, hi, lo + initRunLen, c);
        return NOERROR;
    }

    /**
     * March over the array once, left to right, finding natural runs,
     * extending short natural runs to minRun elements, and merging runs
     * to maintain stack invariant.
     */
    AutoPtr<TimSort> ts = new TimSort(a, c);
    Int32 minRun = MinRunLength(nRemaining);
    do {
        // Identify next run
        Int32 runLen = CountRunAndMakeAscending(a, lo, hi, c);

        // If run is short, extend to min(minRun, nRemaining)
        if (runLen < minRun) {
            Int32 force = nRemaining <= minRun ? nRemaining : minRun;
            BinarySort(a, lo, lo + force, lo + runLen, c);
            runLen = force;
        }

        // Push run onto pending-run stack, and maybe merge
        ts->PushRun(lo, runLen);
        ts->MergeCollapse();

        // Advance to find next run
        lo += runLen;
        nRemaining -= runLen;
    } while (nRemaining != 0);

    // Merge all remaining runs to complete sort
    if (DEBUG) {
        assert(lo == hi);
    }
    ts->MergeForceCollapse();
    if (DEBUG) {
        assert(ts->mStackSize == 1);
    }

    return NOERROR;
}

template <typename T>
ECode TimSort<T>::BinarySort(
    /* [in] */ ArrayOf<T*>* a,
    /* [in] */ Int32 lo,
    /* [in] */ Int32 hi,
    /* [in] */ Int32 start,
    /* [in] */ IComparator* c)
{
    if (DEBUG) {
        assert(lo <= start && start <= hi);
    }
    if (start == lo) {
        start++;
    }

    for ( ; start < hi; start++) {
        AutoPtr<T> pivot = (*a)[start];

        // Set left (and right) to the index where a[start] (pivot) belongs
        Int32 left = lo;
        Int32 right = start;
        if (DEBUG) {
            assert(left <= right);
        }
        /*
         * Invariants:
         *   pivot >= all in [lo, left).
         *   pivot <  all in [right, start).
         */
        while (left < right) {
            Int32 mid = (UInt32)(left + right) >> 1;
            Int32 isflag = 0;
            if (c->Compare(TO_IINTERFACE(pivot), TO_IINTERFACE((*a)[mid]), &isflag), isflag < 0) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        if (DEBUG) {
            assert(left == right);
        }

        /*
         * The invariants still hold: pivot >= all in [lo, left) and
         * pivot < all in [left, start), so pivot belongs at left.  Note
         * that if there are elements equal to pivot, left points to the
         * first slot after them -- that's why this sort is stable.
         * Slide elements over to make room for pivot.
         */
        Int32 n = start - left;  // The number of elements to move
        // Switch is just an optimization for arraycopy in default case
        switch(n) {
            case 2:
                a->Set(left + 2, (*a)[left + 1]);
            case 1:
                a->Set(left + 1, (*a)[left]);
                break;
            default:
                a->Copy(left +1, a, left, n);
        }
        a->Set(left, pivot);
    }
    return NOERROR;
}

template <typename T>
Int32 TimSort<T>::CountRunAndMakeAscending(
    /* [in] */ ArrayOf<T*>* a,
    /* [in] */ Int32 lo,
    /* [in] */ Int32 hi,
    /* [in] */ IComparator* c)
{
    if (DEBUG) {
        assert(lo < hi);
    }
    Int32 runHi = lo + 1;
    if (runHi == hi)
        return 1;

    // Find end of run, and reverse range if descending
    Int32 isflag = 0;
    c->Compare(TO_IINTERFACE((*a)[runHi]), TO_IINTERFACE((*a)[lo]), &isflag);
    runHi++;
    if (isflag < 0) { // Descending
        while(runHi < hi && (c->Compare(TO_IINTERFACE((*a)[runHi]), TO_IINTERFACE((*a)[runHi - 1]), &isflag), isflag < 0))
            runHi++;
        ReverseRange(a, lo, runHi);
    }
    else {                              // Ascending
        while (runHi < hi && (c->Compare(TO_IINTERFACE((*a)[runHi]), TO_IINTERFACE((*a)[runHi - 1]), &isflag), isflag >= 0))
            runHi++;
    }

    return runHi - lo;
}

template <typename T>
ECode TimSort<T>::ReverseRange(
    /* [in] */ ArrayOf<T*>* a,
    /* [in] */ Int32 lo,
    /* [in] */ Int32 hi)
{
    hi--;
    while (lo < hi) {
        AutoPtr<T> t = (*a)[lo];
        a->Set(lo++, (*a)[hi]);
        a->Set(hi--, t);
    }
    return NOERROR;
}

template <typename T>
Int32 TimSort<T>::MinRunLength(
    /* [in] */ Int32 n)
{
    if (DEBUG) {
        assert(n >= 0);
    }
    Int32 r = 0;      // Becomes 1 if any 1 bits are shifted off
    while (n >= MIN_MERGE) {
        r |= (n & 1);
        n >>= 1;
    }
    return n + r;
}

template <typename T>
ECode TimSort<T>::PushRun(
    /* [in] */ Int32 runBase,
    /* [in] */ Int32 runLen)
{
    (*mRunBase)[mStackSize] = runBase;
    (*mRunLen)[mStackSize] = runLen;
    mStackSize++;
    return NOERROR;
}

template <typename T>
ECode TimSort<T>::MergeCollapse()
{
    while (mStackSize > 1) {
        Int32 n = mStackSize - 2;
        if (n > 0 && (*mRunLen)[n-1] <= (*mRunLen)[n] + (*mRunLen)[n+1]) {
            if ((*mRunLen)[n - 1] < (*mRunLen)[n + 1]) {
                n--;
            }
            MergeAt(n);
        }
        else if ((*mRunLen)[n] <= (*mRunLen)[n + 1]) {
            MergeAt(n);
        }
        else {
            break; // Invariant is established
        }
    }
    return NOERROR;
}

template <typename T>
ECode TimSort<T>::MergeForceCollapse()
{
    while (mStackSize > 1) {
        Int32 n = mStackSize - 2;
        if (n > 0 && (*mRunLen)[n - 1] < (*mRunLen)[n + 1]) {
            n--;
        }
        MergeAt(n);
    }
    return NOERROR;
}

template <typename T>
ECode TimSort<T>::MergeAt(
    /* [in] */ Int32 i)
{
    if (DEBUG) {
        assert(mStackSize >= 2);
    }
    if (DEBUG) {
        assert(i >= 0);
    }
    if (DEBUG) {
        assert(i == (mStackSize - 2) || (i == mStackSize) - 3);
    }

    Int32 base1 = (*mRunBase)[i];
    Int32 len1 = (*mRunLen)[i];
    Int32 base2 = (*mRunBase)[i + 1];
    Int32 len2 = (*mRunLen)[i + 1];
    if (DEBUG) {
        assert(len1 > 0 && len2 > 0);
    }
    if (DEBUG) {
        assert((base1 + len1) == base2);
    }

    /*
     * Record the length of the combined runs; if i is the 3rd-last
     * run now, also slide over the last run (which isn't involved
     * in this merge).  The current run (i+1) goes away in any case.
     */
    (*mRunLen)[i] = len1 + len2;
    if (i == mStackSize - 3) {
        (*mRunBase)[i + 1] = (*mRunBase)[i + 2];
        (*mRunLen)[i + 1] = (*mRunLen)[i + 2];
    }
    mStackSize--;

    /*
     * Find where the first element of run2 goes in run1. Prior elements
     * in run1 can be ignored (because they're already in place).
     */
    Int32 k = GallopRight((*mA)[base2], mA, base1, len1, 0, mC);
    if (DEBUG) {
        assert(k >= 0);
    }
    base1 += k;
    len1 -= k;
    if (len1 == 0) {
        return NOERROR;
    }

    /*
     * Find where the last element of run1 goes in run2. Subsequent elements
     * in run2 can be ignored (because they're already in place).
     */
    len2 = GallopLeft((*mA)[base1 + len1 - 1], mA, base2, len2, len2 - 1, mC);
    if (DEBUG) {
        assert(len2 >= 0);
    }
    if (len2 == 0) {
        return NOERROR;
    }

    // Merge remaining runs, using tmp array with min(len1, len2) elements
    if (len1 <= len2) {
        MergeLo(base1, len1, base2, len2);
    }
    else {
        MergeHi(base1, len1, base2, len2);
    }
    return NOERROR;
}

template <typename T>
Int32 TimSort<T>::GallopLeft(
    /* [in] */ T* key,
    /* [in] */ ArrayOf<T*>* a,
    /* [in] */ Int32 base,
    /* [in] */ Int32 len,
    /* [in] */ Int32 hint,
    /* [in] */ IComparator* c)
{
    if (DEBUG) {
        assert(len > 0 && hint >= 0 && hint < len);
    }
    Int32 lastOfs = 0;
    Int32 ofs = 1;
    Int32 isflag = 0;
    if (c->Compare(TO_IINTERFACE(key), TO_IINTERFACE((*a)[base + hint]), &isflag), isflag > 0) {
        // Gallop right until a[base+hint+lastOfs] < key <= a[base+hint+ofs]
        Int32 maxOfs = len - hint;
        while (ofs < maxOfs && (c->Compare(TO_IINTERFACE(key), TO_IINTERFACE((*a)[base + hint + ofs]), &isflag), isflag > 0)) {
            lastOfs = ofs;
            ofs = (ofs * 2) + 1;
            if (ofs <= 0) {  // int overflow
                ofs = maxOfs;
            }
        }
        if (ofs > maxOfs) {
            ofs = maxOfs;
        }

        // Make offsets relative to base
        lastOfs += hint;
        ofs += hint;
    }
    else { // key <= a[base + hint]
        // Gallop left until a[base+hint-ofs] < key <= a[base+hint-lastOfs]
        const Int32 maxOfs = hint + 1;
        while (ofs < maxOfs && (c->Compare(TO_IINTERFACE(key), TO_IINTERFACE((*a)[base + hint - ofs]), &isflag), isflag <= 0)) {
            lastOfs = ofs;
            ofs = (ofs * 2) + 1;
            if (ofs <= 0) {  // int overflow
                ofs = maxOfs;
            }
        }
        if (ofs > maxOfs) {
            ofs = maxOfs;
        }

        // Make offsets relative to base
        Int32 tmp = lastOfs;
        lastOfs = hint - ofs;
        ofs = hint - tmp;
    }
    if (DEBUG) {
        assert(-1 <= lastOfs && lastOfs < ofs && ofs <= len);
    }

    /*
     * Now a[base+lastOfs] < key <= a[base+ofs], so key belongs somewhere
     * to the right of lastOfs but no farther right than ofs.  Do a binary
     * search, with invariant a[base + lastOfs - 1] < key <= a[base + ofs].
     */
    lastOfs++;
    while (lastOfs < ofs) {
        Int32 m = lastOfs + (UInt32(ofs - lastOfs) >> 1);

        if (c->Compare(TO_IINTERFACE(key), TO_IINTERFACE((*a)[base + m]), &isflag), isflag > 0) {
            lastOfs = m + 1;  // a[base + m] < key
        }
        else {
            ofs = m;          // key <= a[base + m]
        }
    }
    if (DEBUG) {
        assert(lastOfs == ofs);    // so a[base + ofs - 1] < key <= a[base + ofs]
    }
    return ofs;
}

template <typename T>
Int32 TimSort<T>::GallopRight(
    /* [in] */ T* key,
    /* [in] */ ArrayOf<T*>* a,
    /* [in] */ Int32 base,
    /* [in] */ Int32 len,
    /* [in] */ Int32 hint,
    /* [in] */ IComparator* c)
{
    if (DEBUG) {
        assert(len > 0 && hint >= 0 && hint < len);
    }

    Int32 ofs = 1;
    Int32 lastOfs = 0;
    Int32 isflag = 0;
    if (c->Compare(TO_IINTERFACE(key), TO_IINTERFACE((*a)[base + hint]), &isflag), isflag < 0) {
        // Gallop left until a[b+hint - ofs] <= key < a[b+hint - lastOfs]
        Int32 maxOfs = hint + 1;
        while (ofs < maxOfs && (c->Compare(TO_IINTERFACE(key), TO_IINTERFACE((*a)[base + hint - ofs]), &isflag), isflag < 0)) {
            lastOfs = ofs;
            ofs = (ofs * 2) + 1;
            if (ofs <= 0) {   // int overflow
                ofs = maxOfs;
            }
        }
        if (ofs > maxOfs) {
            ofs = maxOfs;
        }

        // Make offsets relative to b
        Int32 tmp = lastOfs;
        lastOfs = hint - ofs;
        ofs = hint - tmp;
    }
    else { // a[b + hint] <= key
        // Gallop right until a[b+hint + lastOfs] <= key < a[b+hint + ofs]
        Int32 maxOfs = len - hint;
        while (ofs < maxOfs && (c->Compare(TO_IINTERFACE(key), TO_IINTERFACE((*a)[base + hint + ofs]), &isflag), isflag >= 0)) {
            lastOfs = ofs;
            ofs = (ofs * 2) + 1;
            if (ofs <= 0) {  // int overflow
                ofs = maxOfs;
            }
        }
        if (ofs > maxOfs) {
            ofs = maxOfs;
        }

        // Make offsets relative to b
        lastOfs += hint;
        ofs += hint;
    }
    if (DEBUG) {
        assert(-1 <= lastOfs && lastOfs < ofs && ofs <= len);
    }

    /*
     * Now a[b + lastOfs] <= key < a[b + ofs], so key belongs somewhere to
     * the right of lastOfs but no farther right than ofs.  Do a binary
     * search, with invariant a[b + lastOfs - 1] <= key < a[b + ofs].
     */
    lastOfs++;
    while (lastOfs < ofs) {
        Int32 m = lastOfs + (UInt32(ofs - lastOfs) >> 1);

        if (c->Compare(TO_IINTERFACE(key), TO_IINTERFACE((*a)[base + m]), &isflag), isflag < 0) {
            ofs = m;          // key < a[b + m]
        }
        else {
            lastOfs = m + 1;  // a[b + m] <= key
        }
    }
    if (DEBUG) {
        assert(lastOfs == ofs);    // so a[b + ofs - 1] <= key < a[b + ofs]
    }
    return ofs;
}

template <typename T>
ECode TimSort<T>::MergeLo(
    /* [in] */ Int32 base1,
    /* [in] */ Int32 len1,
    /* [in] */ Int32 base2,
    /* [in] */ Int32 len2)
{
    if (DEBUG) {
        assert(len1 > 0 && len2 > 0 && (base1 + len1) == base2);
    }

    // Copy first run into temp array
    AutoPtr< ArrayOf<T*> > a = mA; // For performance
    AutoPtr< ArrayOf<T*> > tmp = EnsureCapacity(len1);
    tmp->Copy(0, a, base1, len1);

    Int32 cursor1 = 0;       // Indexes into tmp array
    Int32 cursor2 = base2;   // Indexes int a
    Int32 dest = base1;      // Indexes int a

    // Move first element of second run and deal with degenerate cases
    a->Set(dest++, (*a)[cursor2++]);
    if (--len2 == 0) {
        a->Copy(dest, tmp, cursor1, len1);
        return NOERROR;
    }
    if (len1 == 1) {
        a->Copy(dest, a, cursor2, len2);
        a->Set(dest + len2, (*tmp)[cursor1]); // Last elt of run 1 to end of merge
        return NOERROR;
    }

    AutoPtr<IComparator> c = mC;  // Use local variable for performance
    Int32 minGallop = mMinGallop;    //  "    "       "     "      "

    while (TRUE) {
        Int32 count1 = 0; // Number of times in a row that first run won
        Int32 count2 = 0; // Number of times in a row that second run won

        /*
         * Do the straightforward thing until (if ever) one run starts
         * winning consistently.
         */
        do {
            if (DEBUG) {
                assert(len1 > 1 && len2 > 0);
            }
            Int32 isflag = 0;
            if (c->Compare(TO_IINTERFACE((*a)[cursor2]), TO_IINTERFACE((*tmp)[cursor1]), &isflag), isflag < 0) {
                a->Set(dest++, (*a)[cursor2++]);
                count2++;
                count1 = 0;
                if (--len2 == 0)
                    goto outer;
            }
            else {
                a->Set(dest++, (*tmp)[cursor1++]);
                count1++;
                count2 = 0;
                if (--len1 == 1)
                    goto outer;
            }
        } while ((count1 | count2) < minGallop);

        /*
         * One run is winning so consistently that galloping may be a
         * huge win. So try that, and continue galloping until (if ever)
         * neither run appears to be winning consistently anymore.
         */
        do {
            if (DEBUG) {
                assert(len1 > 1 && len2 > 0);
            }
            count1 = GallopRight((*a)[cursor2], tmp, cursor1, len1, 0, c);
            if (count1 != 0) {
                a->Copy(dest, tmp, cursor1,count1);
                dest += count1;
                cursor1 += count1;
                len1 -= count1;
                if (len1 <= 1) // len1 == 1 || len1 == 0
                    goto outer;
            }
            a->Set(dest++, (*a)[cursor2++]);
            if (--len2 == 0)
                goto outer;

            count2 = GallopLeft((*tmp)[cursor1], a, cursor2, len2, 0, c);
            if (count2 != 0) {
                a->Copy(dest, a, cursor2, count2);
                dest += count2;
                cursor2 += count2;
                len2 -= count2;
                if (len2 == 0)
                    goto outer;
            }
            a->Set(dest++, (*tmp)[cursor1++]);
            if (--len1 == 1) {
                goto outer;
            }
            minGallop--;
        } while (count1 >= MIN_GALLOP || count2 >= MIN_GALLOP);
        if (minGallop < 0)
            minGallop = 0;
        minGallop += 2;  // Penalize for leaving gallop mode
    }  // End of "outer" loop

outer:
    mMinGallop = minGallop < 1 ? 1 : minGallop;  // Write back to field

    if (len1 == 1) {
        if (DEBUG) {
            assert(len2 > 0);
        }
        a->Copy(dest, a, cursor2, len2);
        a->Set(dest + len2, (*tmp)[cursor1]); //  Last elt of run 1 to end of merge
    }
    else if (len1 == 0) {
        // throw new IllegalArgumentException(
        //     "Comparison method violates its general contract!");
        return E_ILLEGAL_ARGUMENT_EXCEPTION;
    }
    else {
        if (DEBUG) {
            assert(len2 == 0);
        }
        if (DEBUG) {
            assert(len1 > 1);
        }
        a->Copy(dest, tmp, cursor1, len1);
    }
    return NOERROR;
}

template <typename T>
ECode TimSort<T>::MergeHi(
    /* [in] */ Int32 base1,
    /* [in] */ Int32 len1,
    /* [in] */ Int32 base2,
    /* [in] */ Int32 len2)
{
    if (DEBUG) {
        assert(len1 > 0 && len2 > 0 && (base1 + len1) == base2);
    }

    // Copy second run into temp array
    AutoPtr< ArrayOf<T*> > a = mA; // For performance
    AutoPtr< ArrayOf<T*> > tmp = EnsureCapacity(len2);
    tmp->Copy(0, a, base2, len2);

    Int32 cursor1 = base1 + len1 - 1;  // Indexes into a
    Int32 cursor2 = len2 - 1;          // Indexes into tmp array
    Int32 dest = base2 + len2 - 1;     // Indexes into a

    // Move last element of first run and deal with degenerate cases
    a->Set(dest--, (*a)[cursor1--]);
    if (--len1 == 0) {
        a->Copy(dest - (len2 - 1), tmp, 0, len2);
        return NOERROR;
    }
    if (len2 == 1) {
        dest -= len1;
        cursor1 -= len1;
        a->Copy(dest + 1, a, cursor1 + 1, len1);
        a->Set(dest, (*tmp)[cursor2]);
        return NOERROR;
    }

    AutoPtr<IComparator> c = mC;  // Use local variable for performance
    Int32 minGallop = mMinGallop;    //  "    "       "     "      "

    while (TRUE) {
        Int32 count1 = 0; // Number of times in a row that first run won
        Int32 count2 = 0; // Number of times in a row that second run won

        /*
         * Do the straightforward thing until (if ever) one run
         * appears to win consistently.
         */
        do {
            if (DEBUG) {
                assert(len1 > 0 && len2 > 1);
            }
            Int32 isflag = 0;
            if (c->Compare(TO_IINTERFACE((*tmp)[cursor2]), TO_IINTERFACE((*a)[cursor1]), &isflag), isflag < 0) {
                a->Set(dest--, (*a)[cursor1--]);
                count1++;
                count2 = 0;
                if (--len1 == 0)
                    goto outer;
            }
            else {
                a->Set(dest--, (*tmp)[cursor2--]);
                count2++;
                count1 = 0;
                if (--len2 == 1)
                    goto outer;
            }
        } while ((count1 | count2) < minGallop);

        /*
         * One run is winning so consistently that galloping may be a
         * huge win. So try that, and continue galloping until (if ever)
         * neither run appears to be winning consistently anymore.
         */
        do {
            if (DEBUG) {
                assert(len1 > 0 && len2 > 1);
            }
            count1 = len1 - GallopRight((*tmp)[cursor2], a, base1, len1, len1 - 1, c);
            if (count1 != 0) {
                dest -= count1;
                cursor1 -= count1;
                len1 -= count1;
                a->Copy(dest + 1, a, cursor1 + 1, count1);
                if (len1 == 0)
                    goto outer;
            }
            a->Set(dest--, (*tmp)[cursor2--]);
            if (--len2 == 1)
                goto outer;

            count2 = len2 - GallopLeft((*a)[cursor1], tmp, 0, len2, len2 - 1, c);
            if (count2 != 0) {
                dest -= count2;
                cursor2 -= count2;
                len2 -= count2;
                a->Copy(dest + 1, tmp, cursor2 + 1, count2);
                if (len2 <= 1)  // len2 == 1 || len2 == 0
                    goto outer;
            }
            a->Set(dest--, (*a)[cursor1--]);
            if (--len1 == 0)
                goto outer;
            minGallop--;
        } while (count1 >= MIN_GALLOP || count2 >= MIN_GALLOP);
        if (minGallop < 0)
            minGallop = 0;
        minGallop += 2;  // Penalize for leaving gallop mode
    }  // End of "outer" loop

outer:
    mMinGallop = minGallop < 1 ? 1 : minGallop;  // Write back to field

    if (len2 == 1) {
        if (DEBUG) {
            assert(len1 > 0);
        }
        dest -= len1;
        cursor1 -= len1;
        a->Copy(dest + 1, a, cursor1 + 1, len1);
        a->Set(dest, (*tmp)[cursor2]);  // Move first elt of run2 to front of merge
    }
    else if (len2 == 0) {
        // throw new IllegalArgumentException(
        //     "Comparison method violates its general contract!");
        return E_ILLEGAL_ARGUMENT_EXCEPTION;
    }
    else {
        if (DEBUG) {
            assert(len1 == 0);
        }
        if (DEBUG) {
            assert(len2 > 0);
        }
        a->Copy(dest - (len2 - 1), tmp, 0, len2);
    }
    return NOERROR;
}

template <typename T>
AutoPtr< ArrayOf<T*> > TimSort<T>::EnsureCapacity(
    /* [in] */ Int32 minCapacity)
{
    if (mTmp->GetLength() < minCapacity) {
        // Compute smallest power of 2 > minCapacity
        Int32 newSize = minCapacity;
        newSize |= newSize >> 1;
        newSize |= newSize >> 2;
        newSize |= newSize >> 4;
        newSize |= newSize >> 8;
        newSize |= newSize >> 16;
        newSize++;

        if (newSize < 0) {// Not bloody likely!
            newSize = minCapacity;
        }
        else {
            newSize = Elastos::Core::Math::Min(newSize, (UInt32)mA->GetLength() >> 1);
        }

        // @SuppressWarnings({"unchecked", "UnnecessaryLocalVariable"})
        AutoPtr< ArrayOf<T*> > newArray = ArrayOf<T*>::Alloc(newSize);
        mTmp = newArray;
    }
    return mTmp;
}

} // namespace Utility
} // namespace Elastos

#endif // __ELASTOS_UTILITY_TIMSORT_H__
