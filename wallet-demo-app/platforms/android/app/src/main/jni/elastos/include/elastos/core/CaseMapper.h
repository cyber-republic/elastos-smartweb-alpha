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

#ifndef __ELASTOS_CORE_CASEMAPPER_H__
#define __ELASTOS_CORE_CASEMAPPER_H__

#include "elastos/core/Object.h"
#include <pthread.h>

using Elastos::Utility::ILocale;
using Libcore::ICU::ITransliterator;

namespace Elastos {
namespace Core {

/**
 * Performs case operations as described by http://unicode.org/reports/tr21/tr21-5.html.
 */
class ECO_PUBLIC CaseMapper
{
public:
    /**
     * Implements String.toLowerCase. We need 's' so that we can return the original String instance
     * if nothing changes. We need 'value', 'offset', and 'count' because they're not otherwise
     * accessible.
     */
    static CARAPI_(String) ToLowerCase(
        /* [in] */ ILocale* locale,
        /* [in] */ const String& s,
        /* [in] */ ArrayOf<Char32>* value,
        /* [in] */ Int32 offset,
        /* [in] */ Int32 count);

    static CARAPI_(String) ToUpperCase(
        /* [in] */ ILocale* locale,
        /* [in] */ const String& s,
        /* [in] */ ArrayOf<Char32>* value,
        /* [in] */ Int32 offset,
        /* [in] */ Int32 count);
private:
    /**
     * True if 'index' is preceded by a sequence consisting of a cased letter and a case-ignorable
     * sequence, and 'index' is not followed by a sequence consisting of an ignorable sequence and
     * then a cased letter.
     */
    ECO_LOCAL static CARAPI_(Boolean) IsFinalSigma(
        /* [in] */ ArrayOf<Char32>* value,
        /* [in] */ Int32 offset,
        /* [in] */ Int32 count,
        /* [in] */ Int32 index);

    /**
     * Return the index of the specified character into the upperValues table.
     * The upperValues table contains three entries at each position. These
     * three characters are the upper case conversion. If only two characters
     * are used, the third character in the table is \u0000.
     * @return the index into the upperValues table, or -1
     */
    ECO_LOCAL static CARAPI_(Int32) UpperIndex(
        /* [in] */ Int32 ch);

    ECO_LOCAL static AutoPtr<ITransliterator> GetEL_UPPER();

private:
    ECO_LOCAL CaseMapper();
    ECO_LOCAL CaseMapper(const CaseMapper&);

public:
    static pthread_key_t sTlsKey;

private:
    ECO_LOCAL static pthread_once_t sTlsKeyOnce;
    // static final ThreadLocal<Transliterator> EL_UPPER

    ECO_LOCAL static const Char32 sUpperValues[306];
    ECO_LOCAL static const Char32 sUpperValues2[173];

    ECO_LOCAL static const Char32 LATIN_CAPITAL_I_WITH_DOT;// = '\u0130';
    ECO_LOCAL static const Char32 GREEK_CAPITAL_SIGMA;// = '\u03a3';
    ECO_LOCAL static const Char32 GREEK_SMALL_FINAL_SIGMA;// = '\u03c2';
};

} // namespace Core
} // namespace Elastos

#endif //__ELASTOS_CORE_CASEMAPPER_H__
