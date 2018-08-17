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

#ifndef __ELASTOS_CORE_HEXSTRINGPARSER_H__
#define __ELASTOS_CORE_HEXSTRINGPARSER_H__

#include "elastos/core/Object.h"

using Elastos::Utility::Regex::IPattern;

namespace Elastos {
namespace Core {

class HexStringParser : public Object
{
public:
    /*
     * Parses the hex string to a double number.
     */
    ECO_PUBLIC static CARAPI Parse(
        /* [in] */ const String& hexString,
        /* [out] */ Double* result);

    /*
     * Parses the hex string to a float number.
     */
    ECO_PUBLIC static CARAPI Parse(
        /* [in] */ const String& hexString,
        /* [out] */ Float* result);

private:
    HexStringParser(
        /* [in] */ Int32 exponentWidth,
        /* [in] */ Int32 mantissaWidth);

    ~HexStringParser();

    CARAPI Parse(
        /* [in] */ const String& hexString,
        /* [in] */ Boolean isDouble,
        /* [out] */ Int64* result);

    /*
     * Parses the sign field.
     */
    CARAPI_(void) ParseHexSign(
        /* [in] */ const String& signStr);

    /*
     * Parses the exponent field.
     */
    CARAPI_(void) ParseExponent(
        /* [in] */ const String& signStr);

    /*
     * Parses the mantissa field.
     */
    CARAPI_(void) ParseMantissa(
        /* [in] */ const String& signStr);

    CARAPI_(void) SetInfinite();

    CARAPI_(void) SetZero();

    /*
     * Sets the exponent variable to Long.MAX_VALUE or -Long.MAX_VALUE if
     * overflow or underflow happens.
     */
    CARAPI_(void) CheckedAddExponent(
        /* [in] */ Int64 offset);

    CARAPI_(void) ProcessNormalNumber();

    CARAPI_(void) ProcessSubNormalNumber();

    /*
     * Adjusts the mantissa to desired width for further analysis.
     */
    CARAPI_(void) FitMantissaInDesiredWidth(
        /* [in] */ Int32 desiredWidth);

    /*
     * Stores the discarded bits to abandonedNumber.
     */
    CARAPI_(void) DiscardTrailingBits(
        /* [in] */ Int64 num);

    /*
     * The value is rounded up or down to the nearest infinitely precise result.
     * If the value is exactly halfway between two infinitely precise results,
     * then it should be rounded up to the nearest infinitely precise even.
     */
    CARAPI_(void) Round();

    /*
     * Returns the normalized significand after removing the leading zeros.
     */
    CARAPI_(String) GetNormalizedSignificand(
        /* [in] */ const String& strIntegerPart,
        /* [in] */ const String& strDecimalPart);

    /*
     * Calculates the offset between the normalized number and unnormalized
     * number. In a normalized representation, significand is represented by the
     * characters "0x1." followed by a lowercase hexadecimal representation of
     * the rest of the significand as a fraction.
     */
    CARAPI_(Int32) GetOffset(
        /* [in] */ const String& strIntegerPart,
        /* [in] */ const String& strDecimalPart);

    CARAPI_(Int32) CountBitsLength(
        /* [in] */ Int64 value);

private:

    static const Int32 DOUBLE_EXPONENT_WIDTH;// = 11;

    static const Int32 DOUBLE_MANTISSA_WIDTH;// = 52;

    static const Int32 FLOAT_EXPONENT_WIDTH;// = 8;

    static const Int32 FLOAT_MANTISSA_WIDTH;// = 23;

    static const Int32 HEX_RADIX;// = 16;

    static const Int32 MAX_SIGNIFICANT_LENGTH;// = 15;

    static const String HEX_SIGNIFICANT;// = "0[xX](\\p{XDigit}+\\.?|\\p{XDigit}*\\.\\p{XDigit}+)";

    static const String BINARY_EXPONENT;// = "[pP]([+-]?\\d+)";

    static const String FLOAT_TYPE_SUFFIX;// = "[fFdD]?";

    static const String HEX_PATTERN;// = "[\\x00-\\x20]*([+-]?)" + HEX_SIGNIFICANT
            //+ BINARY_EXPONENT + FLOAT_TYPE_SUFFIX + "[\\x00-\\x20]*";

   static AutoPtr<IPattern> PATTERN;// = Pattern.compile(HEX_PATTERN);

private:
    Int32 EXPONENT_WIDTH;
    Int32 MANTISSA_WIDTH;
    Int64 EXPONENT_BASE;
    Int64 MAX_EXPONENT;
    Int64 MIN_EXPONENT;
    Int64 MANTISSA_MASK;

    Int64 mSign;

    Int64 mExponent;

    Int64 mMantissa;

    String mAbandonedNumber;//="";

};

} // namespace Core
} // namespace Elastos

#endif //__ELASTOS_CORE_HEXSTRINGPARSER_H__
