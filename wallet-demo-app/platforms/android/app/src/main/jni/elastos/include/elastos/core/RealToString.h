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

#ifndef __ELASTOS_CORE_REAL_TO_STRING_H__
#define __ELASTOS_CORE_REAL_TO_STRING_H__

#include "elastos/core/Object.h"

namespace Elastos {
namespace Core {

class StringBuilder;

class RealToString : public Object
{
public:
    ECO_PUBLIC static RealToString* GetInstance();

    ECO_PUBLIC CARAPI_(String) ToString(Double d);
    ECO_PUBLIC CARAPI_(String) Convert(Double inputNumber);

    ECO_PUBLIC CARAPI_(String) ToString(Float f);
    ECO_PUBLIC CARAPI_(String) Convert(Float inputNumber);

private:
    RealToString();

    void FreeFormatExponential(StringBuilder& sb, Boolean positive);
    void FreeFormat(StringBuilder& sb, Boolean positive);

    void BigIntDigitGenerator(Int64 f, Int32 e,
            Boolean isDenormalized, Int32 p);

    void LongDigitGenerator(Int64 f, Int32 e,
            Boolean isDenormalized, Boolean mantissaIsZero, Int32 p);

private:
    //static Double InvLogOfTenBaseTwo;// = Math.log(2.0) / Math.log(10.0);

    Int32 mFirstK;

    /**
     * An array of decimal digits, filled by longDigitGenerator or bigIntDigitGenerator.
     */
    static const Int32 DIGITS_LENGTH = 64;
    Int32 mDigits[DIGITS_LENGTH];

    /**
     * Number of valid entries in 'digits'.
     */
    Int32 mDigitCount;
};

} // namespace Core
} // namespace Elastos

#endif //__ELASTOS_CORE_REAL_TO_STRING_H__
