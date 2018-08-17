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

#ifndef __ELASTOS_CORE_INTEGRAL_TO_STRING_H__
#define __ELASTOS_CORE_INTEGRAL_TO_STRING_H__

#include "elastos/core/Object.h"

namespace Elastos {
namespace Core {

class StringBuilder;

/*!
 * Converts integral types to strings. This class is public but hidden so that it can also be
 * used by java.util.Formatter to speed up %d. This class is in java.lang so that it can take
 * advantage of the package-private String constructor.
 *
 * The most important methods are appendInt/appendLong and intToString(int)/longToString(int).
 * The former are used in the implementation of StringBuilder, StringBuffer, and Formatter, while
 * the latter are used by Integer.toString and Long.toString.
 *
 * The append methods take AbstractStringBuilder rather than Appendable because the latter requires
 * CharSequences, while we only have raw char[]s. Since much of the savings come from not creating
 * any garbage, we can't afford temporary CharSequence instances.
 *
 * One day the performance advantage of the binary/hex/octal specializations will be small enough
 * that we can lose the duplication, but until then this class offers the full set.
 *
 * @hide
 */
class IntegralToString : public Object
{
public:
    /**
     * Equivalent to Integer.toString(i, radix).
     */
    ECO_PUBLIC static CARAPI_(String) ToString(Int32 i, Int32 radix = 10);

    /**
     * Equivalent to Long.toString(v, radix).
     */
    ECO_PUBLIC static CARAPI_(String) ToString(Int64 v, Int32 radix = 10);

    ECO_PUBLIC static CARAPI_(String) ToBinaryString(Int32 i);

    ECO_PUBLIC static CARAPI_(String) ToBinaryString(Int64 v);

    ECO_PUBLIC static CARAPI_(StringBuilder&) AppendByteAsHex(
            StringBuilder& sb, Byte b, Boolean upperCase = TRUE);

    ECO_PUBLIC static CARAPI_(String) ToHexString(Byte b, Boolean upperCase = TRUE);

    ECO_PUBLIC static CARAPI_(String) ToHexString(ArrayOf<Byte>& bytes, Boolean upperCase = TRUE);

    ECO_PUBLIC static CARAPI_(String) ToHexString(Int32 i, Boolean upperCase = TRUE, Int32 minWidth = 0);

    ECO_PUBLIC static CARAPI_(String) ToHexString(Int64 v, Boolean upperCase = TRUE);

    ECO_PUBLIC static CARAPI_(String) ToOctalString(Int32 i);

    ECO_PUBLIC static CARAPI_(String) ToOctalString(Int64 v);

private:
    /**
     * Returns the string representation of i and leaves sb alone if sb is null.
     * Returns null and appends the string representation of i to sb if sb is non-null.
     */
    static CARAPI_(String) ConvertInt32(Int32 i);


    /**
     * Returns the string representation of n and leaves sb alone if sb is null.
     * Returns null and appends the string representation of n to sb if sb is non-null.
     */
    static CARAPI_(String) ConvertInt64(Int64 n);

    /**
     * Inserts the unsigned decimal integer represented by n into the specified
     * character array starting at position cursor.  Returns the index after
     * the last character inserted (i.e., the value to pass in as cursor the
     * next time this method is called). Note that n is interpreted as a large
     * positive integer (not a negative integer) if its sign bit is set.
     */
    static CARAPI_(Int32) Int32IntoCharArray(ArrayOf<Byte>& buf, Int32 cursor, Int32 n);

private:
    static const Int32 TENS_LENGTH = 100;
    static const char TENS[TENS_LENGTH];

    static const Int32 ONES_LENGTH = 100;
    static const char ONES[ONES_LENGTH];

    static const Int32 MOD_10_TABLE_LENGTH = 16;
    static const char MOD_10_TABLE[MOD_10_TABLE_LENGTH];

    static const Int32 DIGITS_LENGTH = 36;
    static const char DIGITS[DIGITS_LENGTH];
    static const char UPPER_CASE_DIGITS[DIGITS_LENGTH];

    /**
     * These tables are used to special-case toString computation for
     * small values.  This serves three purposes: it reduces memory usage;
     * it increases performance for small values; and it decreases the
     * number of comparisons required to do the length computation.
     * Elements of this table are lazily initialized on first use.
     * No locking is necessary, i.e., we use the non-volatile, racy
     * single-check idiom.
     */
    static const Int32 SMALL_VALUES_LENGTH = 100;
    static AutoPtr<ArrayOf<String> > SMALL_NONNEGATIVE_VALUES;
    static AutoPtr<ArrayOf<String> > SMALL_NEGATIVE_VALUES;
};

} // namespace Core
} // namespace Elastos

#endif //__ELASTOS_CORE_INTEGRAL_TO_STRING_H__
