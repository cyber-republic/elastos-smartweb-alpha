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

#ifndef __ELASTOS_CORE_STRING_TO_REAL_H__
#define __ELASTOS_CORE_STRING_TO_REAL_H__

#include "elastos/core/Object.h"

namespace Elastos {
namespace Core {

class StringToReal : public Object
{
private:
    class StringExponentPair : public Object
    {
    public:
        String mStr;
        Int64 mE;
        Boolean mNegative;

        // Flags for two special non-error failure cases.
        Boolean mInfinity;
        Boolean mZero;

        StringExponentPair();

        Float SpecialValue();
    };

public:
    //=============================================================================
    //             Float
    //=============================================================================
    /**
     * Parses the specified string as a float value.
     *
     * @param string
     *            the string representation of a float value.
     * @return the primitive float value represented by {@code string}.
     * @throws NumberFormatException
     *             if {@code string} can not be parsed as a float value.
     * @see #valueOf(String)
     * @since 1.2
     */
    ECO_PUBLIC static CARAPI Parse(
        /* [in] */ const String& string,
        /* [out] */ Float* result);

    //=============================================================================
    //             Double
    //=============================================================================
    /**
     * Returns the closest double value to the real number in the string.
     *
     * @param s
     *            the String that will be parsed to a floating point
     * @return the double closest to the real number
     *
     * @exception NumberFormatException
     *                if the String doesn't represent a double
     */
    ECO_PUBLIC static CARAPI Parse(
        /* [in] */ const String& string,
        /* [out] */ Double* result);

    /**
     * Takes a String and an integer exponent. The String should hold a positive
     * integer value (or zero). The exponent will be used to calculate the
     * floating point number by taking the positive integer the String
     * represents and multiplying by 10 raised to the power of the of the
     * exponent. Returns the closest double value to the real number, or Double.longBitsToDouble(-1).
     */
    ECO_PUBLIC static Double ParseDblImpl(
        /* [in] */ const String& s,
        /* [in] */ Int32 e);

    /**
     * Takes a String and an integer exponent. The String should hold a positive
     * integer value (or zero). The exponent will be used to calculate the
     * floating point number by taking the positive integer the String
     * represents and multiplying by 10 raised to the power of the of the
     * exponent. Returns the closest float value to the real number, or Float.intBitsToFloat(-1).
     */
    ECO_PUBLIC static Float ParseFltImpl(
        /* [in] */ const String& s,
        /* [in] */ Int32 e);

    /**
     * Returns a StringExponentPair containing a String with no leading or trailing white
     * space and trailing zeroes eliminated. The exponent of the
     * StringExponentPair will be used to calculate the floating point number by
     * taking the positive integer the String represents and multiplying by 10
     * raised to the power of the of the exponent.
     */
    ECO_PUBLIC static CARAPI InitialParse(
        /* [in] */ const String& s,
        /* [in] */ Int32 length,
        /* [in] */ Boolean isDouble,
        /* [out] */ StringExponentPair** pair);

    // Parses "+Nan", "NaN", "-Nan", "+Infinity", "Infinity", and "-Infinity", case-insensitively.
    ECO_PUBLIC static CARAPI ParseName(
        /* [in] */ const String& name,
        /* [in] */ Boolean isDouble,
        /* [out] */ Float* result);

private:
    StringToReal();
    ~StringToReal();
};


} // namespace Core
} // namespace Elastos

#endif //__ELASTOS_CORE_STRING_TO_REAL_H__
