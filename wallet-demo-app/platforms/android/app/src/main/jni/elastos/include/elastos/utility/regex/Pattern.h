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

#ifndef __ELASTOS_UTILITY_REGEX_REGEX_PATTERN_H__
#define __ELASTOS_UTILITY_REGEX_REGEX_PATTERN_H__

#include "Elastos.CoreLibrary.Utility.h"
#include <unicode/regex.h>
#include "elastos/core/Object.h"

using Elastos::Core::ICharSequence;
using Elastos::Core::Object;
using U_ICU_NAMESPACE::RegexPattern;

namespace Elastos {
namespace Utility {
namespace Regex {

class ECO_PUBLIC Pattern
    : public Object
    , public IPattern
{
public:
    Pattern();

    virtual ~Pattern();

    CAR_INTERFACE_DECL()

    CARAPI constructor(
        /* [in] */ const String& pattern,
        /* [in] */ Int32 flags);

    /**
     * Returns a {@link Matcher} for this pattern applied to the given {@code input}.
     * The {@code Matcher} can be used to match the {@code Pattern} against the
     * whole input, find occurrences of the {@code Pattern} in the input, or
     * replace parts of the input.
     */
    CARAPI Matcher(
        /* [in] */ const String& input,
        /* [out] */ IMatcher** matcher);

    CARAPI Matcher(
        /* [in] */ ICharSequence* input,
        /* [out] */ IMatcher** matcher);

    /**
     * Splits the given {@code input} at occurrences of this pattern.
     *
     * <p>If this pattern does not occur in the input, the result is an
     * array containing the input (converted from a {@code CharSequence} to
     * a {@code String}).
     *
     * <p>Otherwise, the {@code limit} parameter controls the contents of the
     * returned array as described below.
     *
     * @param limit
     *            Determines the maximum number of entries in the resulting
     *            array, and the treatment of trailing empty strings.
     *            <ul>
     *            <li>For n &gt; 0, the resulting array contains at most n
     *            entries. If this is fewer than the number of matches, the
     *            final entry will contain all remaining input.
     *            <li>For n &lt; 0, the length of the resulting array is
     *            exactly the number of occurrences of the {@code Pattern}
     *            plus one for the text after the final separator.
     *            All entries are included.
     *            <li>For n == 0, the result is as for n &lt; 0, except
     *            trailing empty strings will not be returned. (Note that
     *            the case where the input is itself an empty string is
     *            special, as described above, and the limit parameter does
     *            not apply there.)
     *            </ul>
     */
    CARAPI Split(
        /* [in] */ const String& input,
        /* [out, callee]*/ ArrayOf<String>** result);

    CARAPI Split(
        /* [in] */ ICharSequence* input,
        /* [out, callee]*/ ArrayOf<String>** result);

    /**
     * Equivalent to {@code split(input, 0)}.
     */
    CARAPI Split(
        /* [in] */ ICharSequence* input,
        /* [in] */ Int32 limit,
        /* [out, callee]*/ ArrayOf<String>** result);

    CARAPI Split(
        /* [in] */ const String& input,
        /* [in] */ Int32 limit,
        /* [out, callee]*/ ArrayOf<String>** result);

    /**
     * Returns the regular expression supplied to {@code compile}.
     */
    CARAPI GetPattern(
        /* [out] */ String* pattern);

    /**
     * Returns the flags supplied to {@code compile}.
     */
    CARAPI GetFlags(
        /* [out] */ Int32* flags);

    /**
     * Returns a compiled form of the given {@code regularExpression}, as modified by the
     * given {@code flags}. See the <a href="#flags">flags overview</a> for more on flags.
     *
     * @throws PatternSyntaxException if the regular expression is syntactically incorrect.
     *
     * @see #CANON_EQ
     * @see #CASE_INSENSITIVE
     * @see #COMMENTS
     * @see #DOTALL
     * @see #LITERAL
     * @see #MULTILINE
     * @see #UNICODE_CASE
     * @see #UNIX_LINES
     */
    static CARAPI Compile(
        /* [in] */ const String& regularExpression,
        /* [in] */ Int32 flags,
        /* [out] */ IPattern** obj);

    /**
     * Equivalent to {@code Pattern.compile(pattern, 0)}.
     */
    static CARAPI Compile(
        /* [in] */ const String& pattern,
        /* [out] */ IPattern** obj);

    /**
     * Tests whether the given {@code regularExpression} matches the given {@code input}.
     * Equivalent to {@code Pattern.compile(regularExpression).matcher(input).matches()}.
     * If the same regular expression is to be used for multiple operations, it may be more
     * efficient to reuse a compiled {@code Pattern}.
     *
     * @see Pattern#compile(java.lang.String, int)
     * @see Matcher#matches()
     */
    static CARAPI_(Boolean) Matches(
        /* [in] */ const String& regularExpression,
        /* [in] */ ICharSequence* input);

    static CARAPI_(Boolean) Matches(
        /* [in] */ const String& regularExpression,
        /* [in] */ const String& input);

    /**
     * Quotes the given {@code string} using "\Q" and "\E", so that all
     * meta-characters lose their special meaning. This method correctly
     * escapes embedded instances of "\Q" or "\E". If the entire result
     * is to be passed verbatim to {@link #compile}, it's usually clearer
     * to use the {@link #LITERAL} flag instead.
     */
    static CARAPI_(String) Quote(
        /* [in] */ const String& string);

private:
    CARAPI Compile();

    static CARAPI CompileImpl(
        /* [in] */ const String& regex,
        /* [in] */ Int32 flags,
        /* [out] */ RegexPattern** result);

public:
    RegexPattern* mNativePattern;

private:
    String mPattern;
    Int32 mFlags;
};

} // namespace Regex
} // namespace Utility
} // namespace Elastos

#endif //__ELASTOS_UTILITY_REGEX_REGEX_PATTERN_H__
