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

#ifndef __ELASTOS_CORE_STRING_TO_INTEGRAL_H__
#define __ELASTOS_CORE_STRING_TO_INTEGRAL_H__

#include "elastos/core/Object.h"

namespace Elastos {
namespace Core {

class StringToIntegral : public Object
{
public:
    //=============================================================================
    //             Int16
    //=============================================================================
    /**
     * Parses the specified string and returns a {@code Short} instance if the
     * string can be decoded into a short value. The string may be an optional
     * minus sign "-" followed by a hexadecimal ("0x..." or "#..."), octal
     * ("0..."), or decimal ("...") representation of a short.
     *
     * @param string
     *            a string representation of a short value.
     * @return a {@code Short} containing the value represented by
     *         {@code string}.
     * @throws NumberFormatException
     *             if {@code string} cannot be parsed as a short value.
     */
    ECO_PUBLIC static CARAPI Decode(
        /* [in] */ const String& string,
        /* [out] */ Int16* result);

    /**
     * Parses the specified string as a byte value. The ASCII
     * character \u002d ('-') is recognized as the minus sign.
     *
     * @param string
     *            the string representation of a byte value.
     * @return the primitive byte value represented by {@code string}.
     * @throws NumberFormatException
     *             if {@code string} cannot be parsed as a byte value.
     */
    ECO_PUBLIC static CARAPI Parse(
        /* [in] */ const String& string,
        /* [out] */ Byte* result);

    /**
     * Parses the specified string as a signed byte value using the specified
     * radix. The ASCII character \u002d ('-') is recognized as the minus sign.
     *
     * @param string
     *            the string representation of a byte value.
     * @param radix
     *            the radix to use when parsing.
     * @return the primitive byte value represented by {@code string} using
     *         {@code radix}.
     * @throws NumberFormatException
     *             if {@code string} cannot be parsed as a byte value, or
     *             {@code radix < Character.MIN_RADIX ||
     *             radix > Character.MAX_RADIX}.
     */
    ECO_PUBLIC static CARAPI Parse(
        /* [in] */ const String& string,
        /* [in] */ Int32 radix,
        /* [out] */ Byte* result);

    /**
     * Parses the specified string as a signed decimal short value. The ASCII
     * character \u002d ('-') is recognized as the minus sign.
     *
     * @param string
     *            the string representation of a short value.
     * @return the primitive short value represented by {@code string}.
     * @throws NumberFormatException
     *             if {@code string} cannot be parsed as a short value.
     */
    ECO_PUBLIC static CARAPI Parse(
        /* [in] */ const String& string,
        /* [out] */ Int16* result);

    /**
     * Parses the specified string as a signed short value using the specified
     * radix. The ASCII character \u002d ('-') is recognized as the minus sign.
     *
     * @param string
     *            the string representation of a short value.
     * @param radix
     *            the radix to use when parsing.
     * @return the primitive short value represented by {@code string} using
     *         {@code radix}.
     * @throws NumberFormatException
     *             if {@code string} cannot be parsed as a short value, or
     *             {@code radix < Character.MIN_RADIX ||
     *             radix > Character.MAX_RADIX}.
     */
    ECO_PUBLIC static CARAPI Parse(
        /* [in] */ const String& string,
        /* [in] */ Int32 radix,
        /* [out] */ Int16* result);

    //=============================================================================
    //             Int32
    //=============================================================================
    /**
     * Parses the specified string and returns a {@code Integer} instance if the
     * string can be decoded into an integer value. The string may be an
     * optional minus sign "-" followed by a hexadecimal ("0x..." or "#..."),
     * octal ("0..."), or decimal ("...") representation of an integer.
     *
     * @param string
     *            a string representation of an integer value.
     * @return an {@code Integer} containing the value represented by
     *         {@code string}.
     * @throws NumberFormatException
     *             if {@code string} cannot be parsed as an integer value.
     */
    ECO_PUBLIC static CARAPI Decode(
        /* [in] */ const String& string,
        /* [out] */ Int32* result);

    /**
     * Parses the specified string as a signed decimal integer value. The ASCII
     * character \u002d ('-') is recognized as the minus sign.
     *
     * @param string
     *            the string representation of an integer value.
     * @return the primitive integer value represented by {@code string}.
     * @throws NumberFormatException
     *             if {@code string} cannot be parsed as an integer value.
     */
    ECO_PUBLIC static CARAPI Parse(
        /* [in] */ const String& string,
        /* [out] */ Int32* result);

    /**
     * Parses the specified string as a signed integer value using the specified
     * radix. The ASCII character \u002d ('-') is recognized as the minus sign.
     *
     * @param string
     *            the string representation of an integer value.
     * @param radix
     *            the radix to use when parsing.
     * @return the primitive integer value represented by {@code string} using
     *         {@code radix}.
     * @throws NumberFormatException
     *             if {@code string} cannot be parsed as an integer value,
     *             or {@code radix < Character.MIN_RADIX ||
     *             radix > Character.MAX_RADIX}.
     */
    ECO_PUBLIC static CARAPI Parse(
        /* [in] */ const String& string,
        /* [in] */ Int32 radix,
        /* [out] */ Int32* result);

    //=============================================================================
    //             Int64
    //=============================================================================
    /**
     * Parses the specified string and returns a {@code Long} instance if the
     * string can be decoded into a long value. The string may be an optional
     * minus sign "-" followed by a hexadecimal ("0x..." or "#..."), octal
     * ("0..."), or decimal ("...") representation of a long.
     *
     * @param string
     *            a string representation of a long value.
     * @return a {@code Long} containing the value represented by {@code string}.
     * @throws NumberFormatException
     *             if {@code string} cannot be parsed as a long value.
     */
    ECO_PUBLIC static CARAPI Decode(
        /* [in] */ const String& string,
        /* [out] */ Int64* result);

    /**
     * Parses the specified string as a signed decimal long value. The ASCII
     * character \u002d ('-') is recognized as the minus sign.
     *
     * @param string
     *            the string representation of a long value.
     * @return the primitive long value represented by {@code string}.
     * @throws NumberFormatException
     *             if {@code string} cannot be parsed as a long value.
     */
    ECO_PUBLIC static CARAPI Parse(
        /* [in] */ const String& string,
        /* [out] */ Int64* result);

    /**
     * Parses the specified string as a signed long value using the specified
     * radix. The ASCII character \u002d ('-') is recognized as the minus sign.
     *
     * @param string
     *            the string representation of a long value.
     * @param radix
     *            the radix to use when parsing.
     * @return the primitive long value represented by {@code string} using
     *         {@code radix}.
     * @throws NumberFormatException
     *             if {@code string} cannot be parsed as a long value, or
     *             {@code radix < Character.MIN_RADIX ||
     *             radix > Character.MAX_RADIX}.
     */
    ECO_PUBLIC static CARAPI Parse(
        /* [in] */ const String& string,
        /* [in] */ Int32 radix,
        /* [out] */ Int64* result);

    ECO_PUBLIC static CARAPI Parse(
        /* [in] */ const String& string,
        /* [in] */ Int32 offset,
        /* [in] */ Int32 radix,
        /* [in] */ Boolean negative,
        /* [out] */ Int64* result);

private:
    static CARAPI Parse(
        /* [in] */ const String& string,
        /* [in] */ Int32 offset,
        /* [in] */ Int32 radix,
        /* [in] */ Boolean negative,
        /* [out] */ Int32* result);

private:
    StringToIntegral();
    ~StringToIntegral();
};


} // namespace Core
} // namespace Elastos

#endif //__ELASTOS_CORE_STRING_TO_INTEGRAL_H__
