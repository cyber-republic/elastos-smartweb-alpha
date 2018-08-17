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

#ifndef __ELASTOS_CORE_STRINGUTILS_H__
#define __ELASTOS_CORE_STRINGUTILS_H__

#include "Elastos.CoreLibrary.h"

using Elastos::Core::ICharSequence;
//using Elastos::Utility::ILocale;

namespace Elastos {
namespace Core {

class ECO_PUBLIC StringUtils
{
public:
    // From String without error code
    //
    static CARAPI_(Byte) ParseByte(
        /* [in] */ const String& input,
        /* [in] */ Int32 radix = 10,
        /* [in] */ Byte defValue = 0);

    static CARAPI_(Int16) ParseInt16(
        /* [in] */ const String& input,
        /* [in] */ Int32 radix = 10,
        /* [in] */ Int16 defValue = 0);

    static CARAPI_(Int32) ParseInt32(
        /* [in] */ const String& input,
        /* [in] */ Int32 radix = 10,
        /* [in] */ Int32 defValue = 0);

    static CARAPI_(Int64) ParseInt64(
        /* [in] */ const String& input,
        /* [in] */ Int32 radix = 10,
        /* [in] */ Int64 defValue = 0);

    static CARAPI_(Float) ParseFloat(
        /* [in] */ const String& input,
        /* [in] */ Float defValue = 0.0);

    static CARAPI_(Double) ParseDouble(
        /* [in] */ const String& input,
        /* [in] */ Double defValue = 0.0);

    static CARAPI_(Boolean) ParseBoolean(
        /* [in] */ const String& input);

    static CARAPI_(AutoPtr<ICharSequence>) ParseCharSequence(
        /* [in] */ const String& input);

    // From string with error code
    //
    static CARAPI Parse(
        /* [in] */ const String& input,
        /* [out] */ Byte* result);

    static CARAPI Parse(
        /* [in] */ const String& input,
        /* [out] */ Int16* result);

    static CARAPI Parse(
        /* [in] */ const String& input,
        /* [out] */ Int32* result);

    static CARAPI Parse(
        /* [in] */ const String& input,
        /* [out] */ Int64* result);

    static CARAPI Parse(
        /* [in] */ const String& input,
        /* [in] */ Int32 radix,
        /* [out] */ Byte* result);

    static CARAPI Parse(
        /* [in] */ const String& input,
        /* [in] */ Int32 radix,
        /* [out] */ Int16* result);

    static CARAPI Parse(
        /* [in] */ const String& input,
        /* [in] */ Int32 radix,
        /* [out] */ Int32* result);

    static CARAPI Parse(
        /* [in] */ const String& input,
        /* [in] */ Int32 radix,
        /* [out] */ Int64* result);

    static CARAPI Parse(
        /* [in] */ const String& input,
        /* [out] */ Float* result);

    static CARAPI Parse(
        /* [in] */ const String& input,
        /* [out] */ Double* result);

    // ToString
    //
    static CARAPI_(String) BooleanToString(
        /* [in] */ Boolean b);

    /**
     * Equivalent to Integer.toString(i, radix).
     */
    static CARAPI_(String) ToString(
        /* [in] */ Int32 i,
        /* [in] */ Int32 radix = 10);

    /**
     * Equivalent to Long.toString(v, radix).
     */
    static CARAPI_(String) ToString(
        /* [in] */ Int64 v,
        /* [in] */ Int32 radix = 10);

    static CARAPI_(String) ToBinaryString(
        /* [in] */ Int32 i);

    static CARAPI_(String) ToBinaryString(
        /* [in] */ Int64 v);

    static CARAPI_(String) ToHexString(
        /* [in] */ Byte b,
        /* [in] */ Boolean upperCase = TRUE);

    static CARAPI_(String) ToHexString(
        /* [in] */ ArrayOf<Byte>& bytes,
        /* [in] */ Boolean upperCase = TRUE);

    static CARAPI_(String) ToHexString(
        /* [in] */ Int32 i,
        /* [in] */ Boolean upperCase = TRUE,
        /* [in] */ Int32 minWidth = 0);

    static CARAPI_(String) ToHexString(
        /* [in] */ Int64 v,
        /* [in] */ Boolean upperCase = TRUE);

    static CARAPI_(String) ToHexString(
        /* [in] */ Float v);

    static CARAPI_(String) ToHexString(
        /* [in] */ Double v);

    static CARAPI_(String) ToOctalString(
        /* [in] */ Int32 i);

    static CARAPI_(String) ToOctalString(
        /* [in] */ Int64 v);

    static CARAPI_(String) ToString(
        /* [in] */ Double d);

    static CARAPI_(String) ToString(
        /* [in] */ Float f);

    static CARAPI Split(
        /* [in] */ const String& input,
        /* [in] */ const String& regularExpression,
        /* [out, callee] */ ArrayOf<String>** array);

    static CARAPI Split(
        /* [in] */ const String& input,
        /* [in] */ const String& regularExpression,
        /* [in] */ Int32 limit,
        /* [out, callee] */ ArrayOf<String>** array);

    static CARAPI ReplaceFirst(
        /* [in] */ const String& input,
        /* [in] */ const String& regularExpression,
        /* [in] */ const String& replacement,
        /* [out] */ String* result);

    static CARAPI ReplaceAll(
        /* [in] */ const String& input,
        /* [in] */ const String& regularExpression,
        /* [in] */ const String& replacement,
        /* [out] */ String* result);

    static CARAPI Matches(
        /* [in] */ const String& input,
        /* [in] */ const String& regularExpression,
        /* [out] */ Boolean* result);

    static CARAPI Split(
        /* [in] */ const String& input,
        /* [in] */ const char* regularExpression,
        /* [out, callee] */ ArrayOf<String>** array);

    static CARAPI Split(
        /* [in] */ const String& input,
        /* [in] */ const char* regularExpression,
        /* [in] */ Int32 limit,
        /* [out, callee] */ ArrayOf<String>** array);

    static CARAPI ReplaceFirst(
        /* [in] */ const String& input,
        /* [in] */ const char* regularExpression,
        /* [in] */ const char* replacement,
        /* [out] */ String* result);

    static CARAPI ReplaceAll(
        /* [in] */ const String& input,
        /* [in] */ const char* regularExpression,
        /* [in] */ const char* replacement,
        /* [out] */ String* result);

    static CARAPI Replace(
        /* [in] */ const String& input,
        /* [in] */ const char* target,
        /* [in] */ const char* replacement,
        /* [out] */ String* result);

    static CARAPI Matches(
        /* [in] */ const String& input,
        /* [in] */ const char* regularExpression,
        /* [out] */ Boolean* result);

    static CARAPI ParsePositiveInt64(
        /* [in] */ const String& input,
        /* [out] */ Int64* result);

    static CARAPI ParsePositiveInt64(
        /* [in] */ const String& input,
        /* [in] */ const Int32 radix,
        /* [out] */ Int64* result);

    /**
     * Returns a localized formatted string, using the supplied format and arguments,
     * using the user's default locale.
     *
     * <p>If you're formatting a string other than for human
     * consumption, you should use the {@code format(Locale, String, Object...)}
     * overload and supply {@code Locale.US}. See
     * "<a href="../util/Locale.html#default_locale">Be wary of the default locale</a>".
     *
     * @param format the format string (see {@link java.util.Formatter#format})
     * @param args
     *            the list of arguments passed to the formatter. If there are
     *            more arguments than required by {@code format},
     *            additional arguments are ignored.
     * @return the formatted string.
     * @throws NullPointerException if {@code format == null}
     * @throws java.util.IllegalFormatException
     *             if the format is invalid.
     * @since 1.5
     */
    static CARAPI_(String) Format(
        /* [in] */ const String& format,
        /* [in] */ ArrayOf<IInterface*>* args);


    /**
     * Returns a formatted string, using the supplied format and arguments,
     * localized to the given locale.
     *
     * @param locale
     *            the locale to apply; {@code null} value means no localization.
     * @param format the format string (see {@link java.util.Formatter#format})
     * @param args
     *            the list of arguments passed to the formatter. If there are
     *            more arguments than required by {@code format},
     *            additional arguments are ignored.
     * @return the formatted string.
     * @throws NullPointerException if {@code format == null}
     * @throws java.util.IllegalFormatException
     *             if the format is invalid.
     * @since 1.5
     */
    //static CARAPI_(String) Format(
    //    /* [in] */ ILocale* locale,
    //    /* [in] */ const String& format,
    //    /* [in] */ ArrayOf<IInterface*>* args);

private:
    ECO_LOCAL StringUtils();
    ECO_LOCAL ~StringUtils();
};

} // namespace Core
} // namespace Elastos

#endif // __ELASTOS_CORE_STRINGUTILS_H__
