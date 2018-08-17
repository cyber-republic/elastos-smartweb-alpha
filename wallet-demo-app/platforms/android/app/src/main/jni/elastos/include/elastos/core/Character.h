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

#ifndef __ELASTOS_CORE_CHARACTER_H__
#define __ELASTOS_CORE_CHARACTER_H__

#ifndef _android
#include "unicode/uchar.h"
#include "unicode/utypes.h"
#endif

#include "elastos/core/Object.h"

using Elastos::IO::ISerializable;
using Elastos::Core::IComparable;

namespace Elastos {
namespace Core {

/**
 * The wrapper for the primitive type {@code char}. This class also provides a
 * number of utility methods for working with characters.
 *
 * <p>Character data is kept up to date as Unicode evolves.
 * See the <a href="../util/Locale.html#locale_data">Locale data</a> section of
 * the {@code Locale} documentation for details of the Unicode versions implemented by current
 * and historical Android releases.
 *
 * <p>The Unicode specification, character tables, and other information are available at
 * <a href="http://www.unicode.org/">http://www.unicode.org/</a>.
 *
 * <p>Unicode characters are referred to as <i>code points</i>. The range of valid
 * code points is U+0000 to U+10FFFF. The <i>Basic Multilingual Plane (BMP)</i>
 * is the code point range U+0000 to U+FFFF. Characters above the BMP are
 * referred to as <i>Supplementary Characters</i>. On the Java platform, UTF-16
 * encoding and {@code char} pairs are used to represent code points in the
 * supplementary range. A pair of {@code char} values that represent a
 * supplementary character are made up of a <i>high surrogate</i> with a value
 * range of 0xD800 to 0xDBFF and a <i>low surrogate</i> with a value range of
 * 0xDC00 to 0xDFFF.
 * <p>
 * On the Java platform a {@code char} value represents either a single BMP code
 * point or a UTF-16 unit that's part of a surrogate pair. The {@code int} type
 * is used to represent all Unicode code points.
 *
 * <a name="unicode_categories"><h3>Unicode categories</h3></a>
 * <p>Here's a list of the Unicode character categories and the corresponding Java constant,
 * grouped semantically to provide a convenient overview. This table is also useful in
 * conjunction with {@code \p} and {@code \P} in {@link java.util.regex.Pattern regular expressions}.
 * <span class="datatable">
 * <style type="text/css">
 * .datatable td { padding-right: 20px; }
 * </style>
 * <p><table>
 * <tr> <td> Cn </td> <td> Unassigned </td>  <td>{@link #UNASSIGNED}</td> </tr>
 * <tr> <td> Cc </td> <td> Control </td>     <td>{@link #CONTROL}</td> </tr>
 * <tr> <td> Cf </td> <td> Format </td>      <td>{@link #FORMAT}</td> </tr>
 * <tr> <td> Cf </td> <td> Private use </td> <td>{@link #PRIVATE_USE}</td> </tr>
 * <tr> <td> Cf </td> <td> Surrogate </td>   <td>{@link #SURROGATE}</td> </tr>
 * <tr> <td><br></td> </tr>
 * <tr> <td> Lu </td> <td> Uppercase letter </td> <td>{@link #UPPERCASE_LETTER}</td> </tr>
 * <tr> <td> Ll </td> <td> Lowercase letter </td> <td>{@link #LOWERCASE_LETTER}</td> </tr>
 * <tr> <td> Lt </td> <td> Titlecase letter </td> <td>{@link #TITLECASE_LETTER}</td> </tr>
 * <tr> <td> Lm </td> <td> Modifier letter </td>  <td>{@link #MODIFIER_LETTER}</td> </tr>
 * <tr> <td> Lo </td> <td> Other letter </td>     <td>{@link #OTHER_LETTER}</td> </tr>
 * <tr> <td><br></td> </tr>
 * <tr> <td> Mn </td> <td> Non-spacing mark </td>       <td>{@link #NON_SPACING_MARK}</td> </tr>
 * <tr> <td> Me </td> <td> Enclosing mark </td>         <td>{@link #ENCLOSING_MARK}</td> </tr>
 * <tr> <td> Mc </td> <td> Combining spacing mark </td> <td>{@link #COMBINING_SPACING_MARK}</td> </tr>
 * <tr> <td><br></td> </tr>
 * <tr> <td> Nd </td> <td> Decimal digit number </td> <td>{@link #DECIMAL_DIGIT_NUMBER}</td> </tr>
 * <tr> <td> Nl </td> <td> Letter number </td>        <td>{@link #LETTER_NUMBER}</td> </tr>
 * <tr> <td> No </td> <td> Other number </td>         <td>{@link #OTHER_NUMBER}</td> </tr>
 * <tr> <td><br></td> </tr>
 * <tr> <td> Pd </td> <td> Dash punctuation </td>          <td>{@link #DASH_PUNCTUATION}</td> </tr>
 * <tr> <td> Ps </td> <td> Start punctuation </td>         <td>{@link #START_PUNCTUATION}</td> </tr>
 * <tr> <td> Pe </td> <td> End punctuation </td>           <td>{@link #END_PUNCTUATION}</td> </tr>
 * <tr> <td> Pc </td> <td> Connector punctuation </td>     <td>{@link #CONNECTOR_PUNCTUATION}</td> </tr>
 * <tr> <td> Pi </td> <td> Initial quote punctuation </td> <td>{@link #INITIAL_QUOTE_PUNCTUATION}</td> </tr>
 * <tr> <td> Pf </td> <td> Final quote punctuation </td>   <td>{@link #FINAL_QUOTE_PUNCTUATION}</td> </tr>
 * <tr> <td> Po </td> <td> Other punctuation </td>         <td>{@link #OTHER_PUNCTUATION}</td> </tr>
 * <tr> <td><br></td> </tr>
 * <tr> <td> Sm </td> <td> Math symbol </td>     <td>{@link #MATH_SYMBOL}</td> </tr>
 * <tr> <td> Sc </td> <td> Currency symbol </td> <td>{@link #CURRENCY_SYMBOL}</td> </tr>
 * <tr> <td> Sk </td> <td> Modifier symbol </td> <td>{@link #MODIFIER_SYMBOL}</td> </tr>
 * <tr> <td> So </td> <td> Other symbol </td>    <td>{@link #OTHER_SYMBOL}</td> </tr>
 * <tr> <td><br></td> </tr>
 * <tr> <td> Zs </td> <td> Space separator </td>     <td>{@link #SPACE_SEPARATOR}</td> </tr>
 * <tr> <td> Zl </td> <td> Line separator </td>      <td>{@link #LINE_SEPARATOR}</td> </tr>
 * <tr> <td> Zp </td> <td> Paragraph separator </td> <td>{@link #PARAGRAPH_SEPARATOR}</td> </tr>
 * </table>
 * </span>
 *
 * @since 1.0
 */
class ECO_PUBLIC Character
    : public Object
    , public ISerializable
    , public IComparable
{
public:
    /*
     * Represents a subset of the Unicode character set.
     */
    class Subset
        : public Object
    {
    public:
//        const Boolean equals(PInterface object);
//        const Int32 hashcode();
//        const String toString();

    protected:
        /**
         * Constructs a new {@code Subset}.
         *
         * @param string
         *            this subset's name.
         */
        Subset(
            /* [in]*/ const String& string);

        virtual ~Subset();

        CARAPI ToString(
            /* [out] */ String* str);

    private:
        String mName;
    };

    /**
     * Represents a block of Unicode characters, as defined by the Unicode 4.0.1
     * specification.
     *
     * @since 1.2
     */

    class UnicodeBlock
        : public Subset
    {
    public:
        UnicodeBlock(
            /* [in] */ const String& blockName,
            /* [in] */ Int32 start,
            /* [in] */ Int32 end);

        ~UnicodeBlock();

        /**
         * Retrieves the constant that corresponds to the specified block name.
         * The block names are defined by the Unicode 4.0.1 specification in the
         * {@code Blocks-4.0.1.txt} file.
         * <p>
         * Block names may be one of the following:
         * <ul>
         * <li>Canonical block name, as defined by the Unicode specification;
         * case-insensitive.</li>
         * <li>Canonical block name without any spaces, as defined by the
         * Unicode specification; case-insensitive.</li>
         * <li>{@code UnicodeBlock} constant identifier. This is determined by
         * uppercasing the canonical name and replacing all spaces and hyphens
         * with underscores.</li>
         * </ul>
         *
         * @param blockName
         *            the name of the block to retrieve.
         * @return the UnicodeBlock constant corresponding to {@code blockName}.
         * @throws NullPointerException
         *             if {@code blockName} is {@code null}.
         * @throws IllegalArgumentException
         *             if {@code blockName} is not a valid block name.
         * @since 1.5
         */
         static CARAPI_(AutoPtr<UnicodeBlock>) ForName(
            /* [in] */ const String& blockName);

        /**
         * Gets the constant for the Unicode block that contains the specified
         * character.
         *
         * @param c
         *            the character for which to get the {@code UnicodeBlock}
         *            constant.
         * @return the {@code UnicodeBlock} constant for the block that contains
         *         {@code c}, or {@code null} if {@code c} does not belong to
         *         any defined block.
         */
        static CARAPI_(AutoPtr<UnicodeBlock>) Of(
            /* [in] */ Char32 c);

    public:
        /**
         * The &quot;Surrogates Area&quot; Unicode Block.
         *
         * @deprecated As of Java 5, this block has been replaced by
         *             {@link #HIGH_SURROGATES},
         *             {@link #HIGH_PRIVATE_USE_SURROGATES} and
         *             {@link #LOW_SURROGATES}.
         * @Deprecated
         */

        static /*const*/ AutoPtr<UnicodeBlock> SURROGATES_AREA;

        /**
         * The &quot;Basic Latin&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> BASIC_LATIN;
        /**
         * The &quot;Latin-1 Supplement&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> LATIN_1_SUPPLEMENT;
        /**
         * The &quot;Latin Extended-A&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> LATIN_EXTENDED_A;
        /**
         * The &quot;Latin Extended-B&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> LATIN_EXTENDED_B;
        /**
         * The &quot;IPA Extensions&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> IPA_EXTENSIONS;
        /**
         * The &quot;Spacing Modifier Letters&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> SPACING_MODIFIER_LETTERS;
        /**
         * The &quot;Combining Diacritical Marks&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> COMBINING_DIACRITICAL_MARKS;
        /**
         * The &quot;Greek and Coptic&quot; Unicode Block. Previously referred
         * to as &quot;Greek&quot;.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> GREEK;
        /**
         * The &quot;Cyrillic&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> CYRILLIC;
        /**
         * The &quot;Cyrillic Supplement&quot; Unicode Block. Previously
         * referred to as &quot;Cyrillic Supplementary&quot;.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> CYRILLIC_SUPPLEMENTARY;
        /**
         * The &quot;Armenian&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> ARMENIAN;
        /**
         * The &quot;Hebrew&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> HEBREW;
        /**
         * The &quot;Arabic&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> ARABIC;
        /**
         * The &quot;Syriac&quot; Unicode Block.
         *
         * @since 1.4
         */
        static /*const*/ AutoPtr<UnicodeBlock> SYRIAC;
        /**
         * The &quot;Thaana&quot; Unicode Block.
         *
         * @since 1.4
         */
        static /*const*/ AutoPtr<UnicodeBlock> THAANA;
        /**
         * The &quot;Devanagari&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> DEVANAGARI;
        /**
         * The &quot;Bengali&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> BENGALI;
        /**
         * The &quot;Gurmukhi&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> GURMUKHI;
        /**
         * The &quot;Gujarati&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> GUJARATI;
        /**
         * The &quot;Oriya&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> ORIYA;
        /**
         * The &quot;Tamil&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> TAMIL;
        /**
         * The &quot;Telugu&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> TELUGU;
        /**
         * The &quot;Kannada&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> KANNADA;
        /**
         * The &quot;Malayalam&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> MALAYALAM;
        /**
         * The &quot;Sinhala&quot; Unicode Block.
         *
         * @since 1.4
         */
        static /*const*/ AutoPtr<UnicodeBlock> SINHALA;
        /**
         * The &quot;Thai&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> THAI;
        /**
         * The &quot;Lao&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> LAO;
        /**
         * The &quot;Tibetan&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> TIBETAN;
        /**
         * The &quot;Myanmar&quot; Unicode Block.
         *
         * @since 1.4
         */
        static /*const*/ AutoPtr<UnicodeBlock> MYANMAR;
        /**
         * The &quot;Georgian&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> GEORGIAN;
        /**
         * The &quot;Hangul Jamo&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> HANGUL_JAMO;
        /**
         * The &quot;Ethiopic&quot; Unicode Block.
         *
         * @since 1.4
         */
        static /*const*/ AutoPtr<UnicodeBlock> ETHIOPIC;
        /**
         * The &quot;Cherokee&quot; Unicode Block.
         *
         * @since 1.4
         */
        static /*const*/ AutoPtr<UnicodeBlock> CHEROKEE;
        /**
         * The &quot;Unified Canadian Aboriginal Syllabics&quot; Unicode Block.
         *
         * @since 1.4
         */
        static /*const*/ AutoPtr<UnicodeBlock> UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS;
        /**
         * The &quot;Ogham&quot; Unicode Block.
         *
         * @since 1.4
         */
        static /*const*/ AutoPtr<UnicodeBlock> OGHAM;
        /**
         * The &quot;Runic&quot; Unicode Block.
         *
         * @since 1.4
         */
        static /*const*/ AutoPtr<UnicodeBlock> RUNIC;
        /**
         * The &quot;Tagalog&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> TAGALOG;
        /**
         * The &quot;Hanunoo&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> HANUNOO;
        /**
         * The &quot;Buhid&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> BUHID;
        /**
         * The &quot;Tagbanwa&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> TAGBANWA;
        /**
         * The &quot;Khmer&quot; Unicode Block.
         *
         * @since 1.4
         */
        static /*const*/ AutoPtr<UnicodeBlock> KHMER;
        /**
         * The &quot;Mongolian&quot; Unicode Block.
         *
         * @since 1.4
         */
        static /*const*/ AutoPtr<UnicodeBlock> MONGOLIAN;
        /**
         * The &quot;Limbu&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> LIMBU;
        /**
         * The &quot;Tai Le&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> TAI_LE;
        /**
         * The &quot;Khmer Symbols&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> KHMER_SYMBOLS;
        /**
         * The &quot;Phonetic Extensions&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> PHONETIC_EXTENSIONS;
        /**
         * The &quot;Latin Extended Additional&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> LATIN_EXTENDED_ADDITIONAL;
        /**
         * The &quot;Greek Extended&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> GREEK_EXTENDED;
        /**
         * The &quot;General Punctuation&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> GENERAL_PUNCTUATION;
        /**
         * The &quot;Superscripts and Subscripts&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> SUPERSCRIPTS_AND_SUBSCRIPTS;
        /**
         * The &quot;Currency Symbols&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> CURRENCY_SYMBOLS;
        /**
         * The &quot;Combining Diacritical Marks for Symbols&quot; Unicode
         * Block. Previously referred to as &quot;Combining Marks for
         * Symbols&quot;.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> COMBINING_MARKS_FOR_SYMBOLS;
        /**
         * The &quot;Letterlike Symbols&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> LETTERLIKE_SYMBOLS;
        /**
         * The &quot;Number Forms&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> NUMBER_FORMS;
        /**
         * The &quot;Arrows&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> ARROWS;
        /**
         * The &quot;Mathematical Operators&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> MATHEMATICAL_OPERATORS;
        /**
         * The &quot;Miscellaneous Technical&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> MISCELLANEOUS_TECHNICAL;
        /**
         * The &quot;Control Pictures&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> CONTROL_PICTURES;
        /**
         * The &quot;Optical Character Recognition&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> OPTICAL_CHARACTER_RECOGNITION;
        /**
         * The &quot;Enclosed Alphanumerics&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> ENCLOSED_ALPHANUMERICS;
        /**
         * The &quot;Box Drawing&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> BOX_DRAWING;
        /**
         * The &quot;Block Elements&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> BLOCK_ELEMENTS;
        /**
         * The &quot;Geometric Shapes&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> GEOMETRIC_SHAPES;
        /**
         * The &quot;Miscellaneous Symbols&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> MISCELLANEOUS_SYMBOLS;
        /**
         * The &quot;Dingbats&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> DINGBATS;
        /**
         * The &quot;Miscellaneous Mathematical Symbols-A&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> MISCELLANEOUS_MATHEMATICAL_SYMBOLS_A;
        /**
         * The &quot;Supplemental Arrows-A&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> SUPPLEMENTAL_ARROWS_A;
        /**
         * The &quot;Braille Patterns&quot; Unicode Block.
         *
         * @since 1.4
         */
        static /*const*/ AutoPtr<UnicodeBlock> BRAILLE_PATTERNS;
        /**
         * The &quot;Supplemental Arrows-B&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> SUPPLEMENTAL_ARROWS_B;
        /**
         * The &quot;Miscellaneous Mathematical Symbols-B&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> MISCELLANEOUS_MATHEMATICAL_SYMBOLS_B;
        /**
         * The &quot;Supplemental Mathematical Operators&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> SUPPLEMENTAL_MATHEMATICAL_OPERATORS;
        /**
         * The &quot;Miscellaneous Symbols and Arrows&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> MISCELLANEOUS_SYMBOLS_AND_ARROWS;
        /**
         * The &quot;CJK Radicals Supplement&quot; Unicode Block.
         *
         * @since 1.4
         */
        static /*const*/ AutoPtr<UnicodeBlock> CJK_RADICALS_SUPPLEMENT;
        /**
         * The &quot;Kangxi Radicals&quot; Unicode Block.
         *
         * @since 1.4
         */
        static /*const*/ AutoPtr<UnicodeBlock> KANGXI_RADICALS;
        /**
         * The &quot;Ideographic Description Characters&quot; Unicode Block.
         *
         * @since 1.4
         */
        static /*const*/ AutoPtr<UnicodeBlock> IDEOGRAPHIC_DESCRIPTION_CHARACTERS;
        /**
         * The &quot;CJK Symbols and Punctuation&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> CJK_SYMBOLS_AND_PUNCTUATION;
        /**
         * The &quot;Hiragana&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> HIRAGANA;
        /**
         * The &quot;Katakana&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> KATAKANA;
        /**
         * The &quot;Bopomofo&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> BOPOMOFO;
        /**
         * The &quot;Hangul Compatibility Jamo&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> HANGUL_COMPATIBILITY_JAMO;
        /**
         * The &quot;Kanbun&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> KANBUN;
        /**
         * The &quot;Bopomofo Extended&quot; Unicode Block.
         *
         * @since 1.4
         */
        static /*const*/ AutoPtr<UnicodeBlock> BOPOMOFO_EXTENDED;
        /**
         * The &quot;Katakana Phonetic Extensions&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> KATAKANA_PHONETIC_EXTENSIONS;
        /**
         * The &quot;Enclosed CJK Letters and Months&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> ENCLOSED_CJK_LETTERS_AND_MONTHS;
        /**
         * The &quot;CJK Compatibility&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> CJK_COMPATIBILITY;
        /**
         * The &quot;CJK Unified Ideographs Extension A&quot; Unicode Block.
         *
         * @since 1.4
         */
        static /*const*/ AutoPtr<UnicodeBlock> CJK_UNIFIED_IDEOGRAPHS_EXTENSION_A;
        /**
         * The &quot;Yijing Hexagram Symbols&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> YIJING_HEXAGRAM_SYMBOLS;
        /**
         * The &quot;CJK Unified Ideographs&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> CJK_UNIFIED_IDEOGRAPHS;
        /**
         * The &quot;Yi Syllables&quot; Unicode Block.
         *
         * @since 1.4
         */
        static /*const*/ AutoPtr<UnicodeBlock> YI_SYLLABLES;
        /**
         * The &quot;Yi Radicals&quot; Unicode Block.
         *
         * @since 1.4
         */
        static /*const*/ AutoPtr<UnicodeBlock> YI_RADICALS;
        /**
         * The &quot;Hangul Syllables&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> HANGUL_SYLLABLES;
        /**
         * The &quot;High Surrogates&quot; Unicode Block. This block represents
         * code point values in the high surrogate range 0xD800 to 0xDB7F
         */
        static /*const*/ AutoPtr<UnicodeBlock> HIGH_SURROGATES;
        /**
         * The &quot;High Private Use Surrogates&quot; Unicode Block. This block
         * represents code point values in the high surrogate range 0xDB80 to
         * 0xDBFF
         */
        static /*const*/ AutoPtr<UnicodeBlock> HIGH_PRIVATE_USE_SURROGATES;
        /**
         * The &quot;Low Surrogates&quot; Unicode Block. This block represents
         * code point values in the low surrogate range 0xDC00 to 0xDFFF
         */
        static /*const*/ AutoPtr<UnicodeBlock> LOW_SURROGATES;
        /**
         * The &quot;Private Use Area&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> PRIVATE_USE_AREA;
        /**
         * The &quot;CJK Compatibility Ideographs&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> CJK_COMPATIBILITY_IDEOGRAPHS;
        /**
         * The &quot;Alphabetic Presentation Forms&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> ALPHABETIC_PRESENTATION_FORMS;
        /**
         * The &quot;Arabic Presentation Forms-A&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> ARABIC_PRESENTATION_FORMS_A;
        /**
         * The &quot;Variation Selectors&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> VARIATION_SELECTORS;
        /**
         * The &quot;Combining Half Marks&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> COMBINING_HALF_MARKS;
        /**
         * The &quot;CJK Compatibility Forms&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> CJK_COMPATIBILITY_FORMS;
        /**
         * The &quot;Small Form Variants&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> SMALL_FORM_VARIANTS;
        /**
         * The &quot;Arabic Presentation Forms-B&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> ARABIC_PRESENTATION_FORMS_B;
        /**
         * The &quot;Halfwidth and Fullwidth Forms&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> HALFWIDTH_AND_FULLWIDTH_FORMS;
        /**
         * The &quot;Specials&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> SPECIALS;
        /**
         * The &quot;Linear B Syllabary&quot; Unicode Block.
         *
         * @since 1.2
         */
        static /*const*/ AutoPtr<UnicodeBlock> LINEAR_B_SYLLABARY;
        /**
         * The &quot;Linear B Ideograms&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> LINEAR_B_IDEOGRAMS;
        /**
         * The &quot;Aegean Numbers&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> AEGEAN_NUMBERS;
        /**
         * The &quot;Old Italic&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> OLD_ITALIC;
        /**
         * The &quot;Gothic&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> GOTHIC;
        /**
         * The &quot;Ugaritic&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> UGARITIC;
        /**
         * The &quot;Deseret&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> DESERET;
        /**
         * The &quot;Shavian&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> SHAVIAN;
        /**
         * The &quot;Osmanya&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> OSMANYA;
        /**
         * The &quot;Cypriot Syllabary&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> CYPRIOT_SYLLABARY;
        /**
         * The &quot;Byzantine Musical Symbols&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> BYZANTINE_MUSICAL_SYMBOLS;
        /**
         * The &quot;Musical Symbols&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> MUSICAL_SYMBOLS;
        /**
         * The &quot;Tai Xuan Jing Symbols&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> TAI_XUAN_JING_SYMBOLS;
        /**
         * The &quot;Mathematical Alphanumeric Symbols&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> MATHEMATICAL_ALPHANUMERIC_SYMBOLS;
        /**
         * The &quot;CJK Unified Ideographs Extension B&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> CJK_UNIFIED_IDEOGRAPHS_EXTENSION_B;
        /**
         * The &quot;CJK Compatibility Ideographs Supplement&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> CJK_COMPATIBILITY_IDEOGRAPHS_SUPPLEMENT;
        /**
         * The &quot;Tags&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> TAGS;
        /**
         * The &quot;Variation Selectors Supplement&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> VARIATION_SELECTORS_SUPPLEMENT;
        /**
         * The &quot;Supplementary Private Use Area-A&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> SUPPLEMENTARY_PRIVATE_USE_AREA_A;
        /**
         * The &quot;Supplementary Private Use Area-B&quot; Unicode Block.
         *
         * @since 1.5
         */
        static /*const*/ AutoPtr<UnicodeBlock> SUPPLEMENTARY_PRIVATE_USE_AREA_B;

    private:
        ECO_LOCAL static void InitBlocks();

        ECO_LOCAL static AutoPtr<ArrayOf<UnicodeBlock*> > BLOCKS;// BLOCKS[126]
    };

public:
    /**
     * Indicates whether {@code codePoint} is a valid Unicode code point.
     *
     * @param codePoint
     *            the code point to test.
     * @return {@code true} if {@code codePoint} is a valid Unicode code point;
     *         {@code false} otherwise.
     * @since 1.5
     */
    static CARAPI_(Boolean) IsValidCodePoint(
        /* [in] */ Char32 c);

    /**
     * Calculates the number of {@code char} values required to represent the
     * specified Unicode code point. This method checks if the {@code codePoint}
     * is greater than or equal to {@code 0x10000}, in which case {@code 2} is
     * returned, otherwise {@code 1}. To test if the code point is valid, use
     * the {@link #isValidCodePoint(int)} method.
     *
     * @param codePoint
     *            the code point for which to calculate the number of required
     *            chars.
     * @return {@code 2} if {@code codePoint >= 0x10000}; {@code 1} otherwise.
     * @see #isValidCodePoint(int)
     * @see #isSupplementaryCodePoint(int)
     * @since 1.5
     */
    static CARAPI_(Int32) GetByteCount(
        /* [in] */ Char32 c);

    /**
     * Returns the code point at {@code index} in the specified array of
     * character units. If the unit at {@code index} is a high-surrogate unit,
     * {@code index + 1} is less than the length of the array and the unit at
     * {@code index + 1} is a low-surrogate unit, then the supplementary code
     * point represented by the pair is returned; otherwise the {@code char}
     * value at {@code index} is returned.
     *
     * @param seq
     *            the source array of {@code char} units.
     * @param index
     *            the position in {@code seq} from which to retrieve the code
     *            point.
     * @return the Unicode code point or {@code char} value at {@code index} in
     *         {@code seq}.
     * @throws NullPointerException
     *             if {@code seq} is {@code null}.
     * @throws IndexOutOfBoundsException
     *             if the {@code index} is negative or greater than or equal to
     *             the length of {@code seq}.
     * @since 1.5
     */
    static CARAPI GetCharAt(
        /* [in] */ const ArrayOf<Byte>& seq,
        /* [in] */ Int32 index,
        /* [out] */ Char32* c,
        /* [out] */ Int32* nextIndex = NULL);

    static CARAPI GetCharAt(
        /* [in] */ const String& seq,
        /* [in] */ Int32 index,
        /* [out] */ Char32* c,
        /* [out] */ Int32* nextIndex = NULL);

    /**
     * Returns the code point that precedes {@code index} in the specified
     * array of character units. If the unit at {@code index - 1} is a
     * low-surrogate unit, {@code index - 2} is not negative and the unit at
     * {@code index - 2} is a high-surrogate unit, then the supplementary code
     * point represented by the pair is returned; otherwise the {@code char}
     * value at {@code index - 1} is returned.
     *
     * @param seq
     *            the source array of {@code char} units.
     * @param index
     *            the position in {@code seq} following the code
     *            point that should be returned.
     * @return the Unicode code point or {@code char} value before {@code index}
     *         in {@code seq}.
     * @throws NullPointerException
     *             if {@code seq} is {@code null}.
     * @throws IndexOutOfBoundsException
     *             if the {@code index} is less than 1 or greater than the
     *             length of {@code seq}.
     * @since 1.5
     */
    static CARAPI GetCharBefore(
        /*[in]*/ const ArrayOf<Byte>& seq,
        /*[in]*/ Int32 index,
        /* [out] */ Char32* c);

    static CARAPI GetCharBefore(
        /*[in]*/ const String& seq,
        /*[in]*/ Int32 index,
        /* [out] */ Char32* c);

    /**
     * Converts the specified Unicode code point into a UTF-16 encoded sequence
     * and copies the value(s) into the char array {@code dst}, starting at
     * index {@code dstIndex}.
     *
     * @param codePoint
     *            the Unicode code point to encode.
     * @param dst
     *            the destination array to copy the encoded value into.
     * @param dstIndex
     *            the index in {@code dst} from where to start copying.
     * @return the number of {@code char} value units copied into {@code dst}.
     * @throws IllegalArgumentException
     *             if {@code codePoint} is not a valid Unicode code point.
     * @throws NullPointerException
     *             if {@code dst} is {@code null}.
     * @throws IndexOutOfBoundsException
     *             if {@code dstIndex} is negative, greater than or equal to
     *             {@code dst.length} or equals {@code dst.length - 1} when
     *             {@code codePoint} is a
     *             {@link #isSupplementaryCodePoint(int) supplementary code point}.
     * @since 1.5
     */
    static CARAPI ToChars(
        /*[in]*/ Char32 c,
        /*[in]*/ ArrayOf<Byte>& dst,
        /*[in]*/ Int32 dstIndex,
        /* [out] */ Int32* number);

    /**
     * Converts the specified Unicode code point into a UTF-16 encoded sequence
     * and returns it as a char array.
     *
     * @param codePoint
     *            the Unicode code point to encode.
     * @return the UTF-16 encoded char sequence. If {@code codePoint} is a
     *         {@link #isSupplementaryCodePoint(int) supplementary code point},
     *         then the returned array contains two characters, otherwise it
     *         contains just one character.
     * @throws IllegalArgumentException
     *             if {@code codePoint} is not a valid Unicode code point.
     * @since 1.5
     */
    static CARAPI ToChars(
        /*[in] */ Char32 c,
        /*[out, callee] */ ArrayOf<Byte>** seq);

    static CARAPI ToChars(
        /* [in] */ const ArrayOf<Char32>& src,
        /* [in] */ Int32 offset,
        /* [in] */ Int32 count,
        /* [out, callee] */ ArrayOf<Byte>** dst,
        /* [out] */ Int32* number);

    static CARAPI ToChar32s(
        /* [in] */ const String& src,
        /* [in] */ Int32 offset,
        /* [in] */ Int32 count,
        /* [in] */ ArrayOf<Char32>* dst,
        /* [in] */ Int32 dstOffset);

    /**
     * Counts the number of Unicode code points in the subsequence of the
     * specified char array, as delineated by {@code offset} and {@code count}.
     * Any surrogate values with missing pair values will be counted as one code
     * point.
     *
     * @param seq
     *            the char array to look through
     * @param offset
     *            the inclusive index to begin counting at.
     * @param count
     *            the number of {@code char} values to look through in
     *            {@code seq}.
     * @return the number of Unicode code points.
     * @throws NullPointerException
     *             if {@code seq} is {@code null}.
     * @throws IndexOutOfBoundsException
     *             if {@code offset < 0}, {@code count < 0} or if
     *             {@code offset + count} is greater than the length of
     *             {@code seq}.
     * @since 1.5
     */
    static CARAPI GetCharCount(
        /*[in]*/ const ArrayOf<Byte>& seq,
        /*[in]*/ Int32 offset,
        /*[in]*/ Int32 count,
        /* [out] */ Int32* number);

    static CARAPI GetCharCount(
        /*[in]*/ const String& seq,
        /*[in]*/ Int32 offset,
        /*[in]*/ Int32 count,
        /* [out] */ Int32* number);

   // /**
   //  * Returns the code point at {@code index} in the specified array of
   //  * character units. If the unit at {@code index} is a high-surrogate unit,
   //  * {@code index + 1} is less than the length of the array and the unit at
   //  * {@code index + 1} is a low-surrogate unit, then the supplementary code
   //  * point represented by the pair is returned; otherwise the {@code char}
   //  * value at {@code index} is returned.
   //  *
   //  * @param seq
   //  *            the source array of {@code char} units.
   //  * @param index
   //  *            the position in {@code seq} from which to retrieve the code
   //  *            point.
   //  * @return the Unicode code point or {@code char} value at {@code index} in
   //  *         {@code seq}.
   //  * @throws NullPointerException
   //  *             if {@code seq} is {@code null}.
   //  * @throws IndexOutOfBoundsException
   //  *             if the {@code index} is negative or greater than or equal to
   //  *             the length of {@code seq}.
   //  * @since 1.5
   //  */
   //  static CARAPI CodePointAt(
   //      /*[in]*/ ArrayOf<Char32>* seq,
   //      /*[in]*/ Int32 index,
   //      /* [out] */ Int32* code);

   //  /**
   //   * Returns the code point at {@code index} in the specified sequence of
   //   * character units. If the unit at {@code index} is a high-surrogate unit,
   //   * {@code index + 1} is less than the length of the sequence and the unit at
   //   * {@code index + 1} is a low-surrogate unit, then the supplementary code
   //   * point represented by the pair is returned; otherwise the {@code char}
   //   * value at {@code index} is returned.
   //   *
   //   * @param seq
   //   *            the source sequence of {@code char} units.
   //   * @param index
   //   *            the position in {@code seq} from which to retrieve the code
   //   *            point.
   //   * @return the Unicode code point or {@code char} value at {@code index} in
   //   *         {@code seq}.
   //   * @throws NullPointerException
   //   *             if {@code seq} is {@code null}.
   //   * @throws IndexOutOfBoundsException
   //   *             if the {@code index} is negative or greater than or equal to
   //   *             the length of {@code seq}.
   //   * @since 1.5
   //   */
   //  static CARAPI CodePointAt(
   //      /*[in]*/ ICharSequence* seq,
   //      /*[in]*/ Int32 index,
   //      /* [out] */ Int32* code);

   //  /**
   //   * Returns the code point at {@code index} in the specified array of
   //   * character units, where {@code index} has to be less than {@code limit}.
   //   * If the unit at {@code index} is a high-surrogate unit, {@code index + 1}
   //   * is less than {@code limit} and the unit at {@code index + 1} is a
   //   * low-surrogate unit, then the supplementary code point represented by the
   //   * pair is returned; otherwise the {@code char} value at {@code index} is
   //   * returned.
   //   *
   //   * @param seq
   //   *            the source array of {@code char} units.
   //   * @param index
   //   *            the position in {@code seq} from which to get the code point.
   //   * @param limit
   //   *            the index after the last unit in {@code seq} that can be used.
   //   * @return the Unicode code point or {@code char} value at {@code index} in
   //   *         {@code seq}.
   //   * @throws NullPointerException
   //   *             if {@code seq} is {@code null}.
   //   * @throws IndexOutOfBoundsException
   //   *             if {@code index < 0}, {@code index >= limit},
   //   *             {@code limit < 0} or if {@code limit} is greater than the
   //   *             length of {@code seq}.
   //   * @since 1.5
   //   */
   //  static CARAPI CodePointAt(
   //      /*[in]*/ ArrayOf<Char32>* seq,
   //      /*[in]*/ Int32 index,
   //      /*[in]*/ Int32 limit,
   //      /* [out] */ Int32* code);

   // /**
   //  * Converts a surrogate pair into a Unicode code point. This method assumes
   //  * that the pair are valid surrogates. If the pair are <i>not</i> valid
   //  * surrogates, then the result is indeterminate. The
   //  * {@link #isSurrogatePair(char, char)} method should be used prior to this
   //  * method to validate the pair.
   //  *
   //  * @param high
   //  *            the high surrogate unit.
   //  * @param low
   //  *            the low surrogate unit.
   //  * @return the Unicode code point corresponding to the surrogate unit pair.
   //  * @see #isSurrogatePair(char, char)
   //  * @since 1.5
   //  */
   // static CARAPI ToCodePoint(
   //     /*[in]*/ Char32 high,
   //     /*[in]*/ Char32 low,
   //     /* [out] */ Int32* value);

    /**
     * Determines the index in a subsequence of the specified character array
     * that is offset {@code codePointOffset} code points from {@code index}.
     * The subsequence is delineated by {@code start} and {@code count}.
     *
     * @param seq
     *            the character array to find the index in.
     * @param start
     *            the inclusive index that marks the beginning of the
     *            subsequence.
     * @param count
     *            the number of {@code char} values to include within the
     *            subsequence.
     * @param index
     *            the start index in the subsequence of the char array.
     * @param codePointOffset
     *            the number of code points to look backwards or forwards; may
     *            be a negative or positive value.
     * @return the index in {@code seq} that is {@code codePointOffset} code
     *         points away from {@code index}.
     * @throws NullPointerException
     *             if {@code seq} is {@code null}.
     * @throws IndexOutOfBoundsException
     *             if {@code start < 0}, {@code count < 0},
     *             {@code index < start}, {@code index > start + count},
     *             {@code start + count} is greater than the length of
     *             {@code seq}, or if there are not enough values in
     *             {@code seq} to skip {@code codePointOffset} code points
     *             forward or backward (if {@code codePointOffset} is
     *             negative) from {@code index}.
     * @since 1.5
     */
    static CARAPI GetOffsetByChars(
        /*[in]*/ const ArrayOf<Byte>& seq,
        /*[in]*/ Int32 start,
        /*[in]*/ Int32 count,
        /*[in]*/ Int32 index,
        /*[in]*/ Int32 charOffset,
        /* [out] */ Int32* offset);

    static CARAPI GetOffsetByChars(
        /*[in]*/ const String& seq,
        /*[in]*/ Int32 index,
        /*[in]*/ Int32 charOffset,
        /* [out] */ Int32* offset);

    /**
     * Convenience method to determine the value of the specified character
     * {@code c} in the supplied radix. The value of {@code radix} must be
     * between MIN_RADIX and MAX_RADIX.
     *
     * @param c
     *            the character to determine the value of.
     * @param radix
     *            the radix.
     * @return the value of {@code c} in {@code radix} if {@code radix} lies
     *         between {@link #MIN_RADIX} and {@link #MAX_RADIX}; -1 otherwise.
     */
    static CARAPI_(Int32) ToDigit(
        /* [in] */ Char32 c,
        /* [in] */ Int32 radix);

    /**
     * Returns the character which represents the specified digit in the
     * specified radix. The {@code radix} must be between {@code MIN_RADIX} and
     * {@code MAX_RADIX} inclusive; {@code digit} must not be negative and
     * smaller than {@code radix}. If any of these conditions does not hold, 0
     * is returned.
     *
     * @param digit
     *            the integer value.
     * @param radix
     *            the radix.
     * @return the character which represents the {@code digit} in the
     *         {@code radix}.
     */
    static CARAPI_(Char32) ForDigit(
        /* [in] */ Int32 digit,
        /* [in] */ Int32 radix);

    /**
     * Gets the numeric value of the specified Unicode character.
     *
     * @param c
     *            the Unicode character to get the numeric value of.
     * @return a non-negative numeric integer value if a numeric value for
     *         {@code c} exists, -1 if there is no numeric value for {@code c},
     *         -2 if the numeric value can not be represented with an integer.
     */
    static CARAPI_(Int32) GetNumericValue(
        /* [in] */ Char32 c);

    /**
     * Gets the general Unicode category of the specified character.
     *
     * @param c
     *            the character to get the category of.
     * @return the Unicode category of {@code c}.
     */
    static CARAPI_(Int32) GetType(
        /* [in] */ Char32 c);

    /**
     * Gets the Unicode directionality of the specified character.
     *
     * @param c
     *            the character to get the directionality of.
     * @return the Unicode directionality of {@code c}.
     */
    static CARAPI_(Byte) GetDirectionality(
        /* [in] */ Char32 c);

    /**
     * Indicates whether the specified character is mirrored.
     *
     * @param c
     *            the character to check.
     * @return {@code true} if {@code c} is mirrored; {@code false}
     *         otherwise.
     */
    static CARAPI_(Boolean) IsMirrored(
        /* [in] */ Char32 c);

    /**
     * Indicates whether the specified character is defined in the Unicode
     * specification.
     *
     * @param c
     *            the character to check.
     * @return {@code true} if the general Unicode category of the character is
     *         not {@code UNASSIGNED}; {@code false} otherwise.
     */
    static CARAPI_(Boolean) IsDefined(
        /* [in] */ Char32 c);

    /**
     * Indicates whether the specified character is a digit.
     *
     * @param c
     *            the character to check.
     * @return {@code true} if {@code c} is a digit; {@code false}
     *         otherwise.
     */
    static CARAPI_(Boolean) IsDigit(
        /* [in] */ Char32 c);

    /**
     * Indicates whether the specified character is ignorable in a Java or
     * Unicode identifier.
     *
     * @param c
     *            the character to check.
     * @return {@code true} if {@code c} is ignorable; {@code false} otherwise.
     */
    static CARAPI_(Boolean) IsIdentifierIgnorable(
        /* [in] */ Char32 c);

    /**
     * Indicates whether the specified character is an ISO control character.
     *
     * @param c
     *            the character to check.
     * @return {@code true} if {@code c} is an ISO control character;
     *         {@code false} otherwise.
     */
    static CARAPI_(Boolean) IsISOControl(
        /* [in] */ Char32 c);

    /**
     * Indicates whether the specified character is a valid part of a Java
     * identifier other than the first character.
     *
     * @param c
     *            the character to check.
     * @return {@code true} if {@code c} is valid as part of a Java identifier;
     *         {@code false} otherwise.
     */
    static CARAPI_(Boolean) IsCarIdentifierPart(
        /* [in] */ Char32 c);

    /**
     * Indicates whether the specified character is a valid first character for
     * a Java identifier.
     *
     * @param c
     *            the character to check.
     * @return {@code true} if {@code c} is a valid first character of a Java
     *         identifier; {@code false} otherwise.
     */
    static CARAPI_(Boolean) IsCarIdentifierStart(
        /* [in] */ Char32 c);

    /**
     * Indicates whether the specified character is a Java letter.
     *
     * @param c
     *            the character to check.
     * @return {@code true} if {@code c} is a Java letter; {@code false}
     *         otherwise.
     * @deprecated Use {@link #isJavaIdentifierStart(char)}
     */
    //@Deprecated
    static CARAPI_(Boolean) IsCarLetter(
        /* [in] */ Char32 c);

    /**
     * Indicates whether the specified character is a Java letter or digit
     * character.
     *
     * @param c
     *            the character to check.
     * @return {@code true} if {@code c} is a Java letter or digit;
     *         {@code false} otherwise.
     * @deprecated Use {@link #isJavaIdentifierPart(char)}
     */
    //@Deprecated
    static CARAPI_(Boolean) IsCarLetterOrDigit(
        /* [in] */ Char32 c);

    /**
     * Indicates whether the specified character is a letter.
     *
     * @param c
     *            the character to check.
     * @return {@code true} if {@code c} is a letter; {@code false} otherwise.
     */
    static CARAPI_(Boolean) IsLetter(
        /* [in] */ Char32 c);

    /**
     * Indicates whether the specified character is a letter or a digit.
     *
     * @param c
     *            the character to check.
     * @return {@code true} if {@code c} is a letter or a digit; {@code false}
     *         otherwise.
     */
    static CARAPI_(Boolean) IsLetterOrDigit(
        /* [in] */ Char32 c);

    /**
     * Indicates whether the specified character is a lower case letter.
     *
     * @param c
     *            the character to check.
     * @return {@code true} if {@code c} is a lower case letter; {@code false}
     *         otherwise.
     */
    static CARAPI_(Boolean) IsLowerCase(
        /* [in] */ Char32 c);

    /**
     * Indicates whether the specified character is a Java space.
     *
     * @param c
     *            the character to check.
     * @return {@code true} if {@code c} is a Java space; {@code false}
     *         otherwise.
     * @deprecated Use {@link #isWhitespace(char)}
     */
    //@Deprecated
    static CARAPI_(Boolean) IsSpace(
        /* [in] */ Char32 c);

    /**
     * Indicates whether the specified character is a Unicode space character.
     * That is, if it is a member of one of the Unicode categories Space
     * Separator, Line Separator, or Paragraph Separator.
     *
     * @param c
     *            the character to check.
     * @return {@code true} if {@code c} is a Unicode space character,
     *         {@code false} otherwise.
     */
    static CARAPI_(Boolean) IsSpaceChar(
        /* [in] */ Char32 c);

    /**
     * Indicates whether the specified character is a titlecase character.
     *
     * @param c
     *            the character to check.
     * @return {@code true} if {@code c} is a titlecase character, {@code false}
     *         otherwise.
     */
    static CARAPI_(Boolean) IsTitleCase(
        /* [in] */ Char32 c);

    /**
     * Indicates whether the specified character is a valid initial character
     * for a Unicode identifier.
     *
     * @param c
     *            the character to check.
     * @return {@code true} if {@code c} is a valid first character for a
     *         Unicode identifier; {@code false} otherwise.
     */
    static CARAPI_(Boolean) IsUnicodeIdentifierStart(
        /* [in] */ Char32 c);

    /**
     * Indicates whether the specified character is an upper case letter.
     *
     * @param c
     *            the character to check.
     * @return {@code true} if {@code c} is a upper case letter; {@code false}
     *         otherwise.
     */
    static CARAPI_(Boolean) IsUpperCase(
        /* [in] */ Char32 c);

    /**
     * Indicates whether the specified character is a whitespace character in
     * Java.
     *
     * @param c
     *            the character to check.
     * @return {@code true} if the supplied {@code c} is a whitespace character
     *         in Java; {@code false} otherwise.
     */
    static CARAPI_(Boolean) IsWhitespace(
        /* [in] */ Char32 c);

    /**
     * Indicates whether {@code ch} is a high- (or leading-) surrogate code unit
     * that is used for representing supplementary characters in UTF-16
     * encoding.
     *
     * @param ch
     *            the character to test.
     * @return {@code true} if {@code ch} is a high-surrogate code unit;
     *         {@code false} otherwise.
     * @see #isLowSurrogate(char)
     * @since 1.5
     */
    static CARAPI_(Boolean) IsHighSurrogate(
        /* [in] */ Char32 c);

    /**
     * Indicates whether {@code ch} is a low- (or trailing-) surrogate code unit
     * that is used for representing supplementary characters in UTF-16
     * encoding.
     *
     * @param ch
     *            the character to test.
     * @return {@code true} if {@code ch} is a low-surrogate code unit;
     *         {@code false} otherwise.
     * @see #isHighSurrogate(char)
     * @since 1.5
     */
    static CARAPI_(Boolean) IsLowSurrogate(
        /* [in] */ Char32 c);

    /**
     * Tests whether the given character is a high or low surrogate.
     * @since 1.7
     * @hide 1.7
     */
    static CARAPI_(Boolean) IsSurrogate(
        /* [in] */ Char32 c);

    /**
     * Indicates whether the specified character pair is a valid surrogate pair.
     *
     * @param high
     *            the high surrogate unit to test.
     * @param low
     *            the low surrogate unit to test.
     * @return {@code true} if {@code high} is a high-surrogate code unit and
     *         {@code low} is a low-surrogate code unit; {@code false}
     *         otherwise.
     * @see #isHighSurrogate(char)
     * @see #isLowSurrogate(char)
     * @since 1.5
     */
    static CARAPI_(Boolean) IsSurrogatePair(
        /* [in] */ Char32 high,
        /* [in] */ Char32 low);

    /**
     * Returns the lower case equivalent for the specified character if the
     * character is an upper case letter. Otherwise, the specified character is
     * returned unchanged.
     *
     * @param c
     *            the character
     * @return if {@code c} is an upper case character then its lower case
     *         counterpart, otherwise just {@code c}.
     */
    static CARAPI_(Char32) ToLowerCase(
        /* [in] */ Char32 c);

    /**
     * Returns the title case equivalent for the specified character if it
     * exists. Otherwise, the specified character is returned unchanged.
     *
     * @param c
     *            the character to convert.
     * @return the title case equivalent of {@code c} if it exists, otherwise
     *         {@code c}.
     */
    static CARAPI_(Char32) ToTitleCase(
        /*[in]*/ Char32 c);

    /**
     * Returns the upper case equivalent for the specified character if the
     * character is a lower case letter. Otherwise, the specified character is
     * returned unchanged.
     *
     * @param c
     *            the character to convert.
     * @return if {@code c} is a lower case character then its upper case
     *         counterpart, otherwise just {@code c}.
     */
    static CARAPI_(Char32) ToUpperCase(
        /* [in] */ Char32 c);

private:
    // prohibit 'new' operator
    ECO_LOCAL void* operator new(size_t cb);

    ECO_LOCAL Character() {}

    ECO_LOCAL Character& operator= (const Character& c) { return *this; }

    ECO_LOCAL Character(const Character& c) {}

    ECO_LOCAL static CARAPI_(Int32) ForNameImpl(
        /* [in] */ const String& blockName);

    ECO_LOCAL static CARAPI_(Int32) OfImpl(
        /* [in] */ Int32 codePoint);

    ECO_LOCAL static CARAPI_(Int32) DigitImpl(
        /* [in] */ Int32 codePoint,
        /* [in] */ Int32 radix);

    ECO_LOCAL static CARAPI_(Int32) GetNumericValueImpl(
        /* [in] */ Int32 codePoint);

    ECO_LOCAL static CARAPI_(Int32) GetTypeImpl(
        /* [in] */ Int32 codePoint);

    ECO_LOCAL static CARAPI_(Byte) GetDirectionalityImpl(
        /* [in] */ Int32 codePoint);

    ECO_LOCAL static CARAPI_(Boolean) IsMirroredImpl(
        /* [in] */ Int32 codePoint);

    ECO_LOCAL static CARAPI_(Boolean) IsDefinedImpl(
        /* [in] */ Int32 codePoint);

    ECO_LOCAL static CARAPI_(Boolean) IsDigitImpl(
        /* [in] */ Int32 codePoint);

    ECO_LOCAL static CARAPI_(Boolean) IsIdentifierIgnorableImpl(
        /* [in] */ Int32 codePoint);

    ECO_LOCAL static CARAPI_(Boolean) IsLetterImpl(
        /* [in] */ Int32 codePoint);

    ECO_LOCAL static CARAPI_(Boolean) IsLetterOrDigitImpl(
        /* [in] */ Int32 codePoint);

    ECO_LOCAL static CARAPI_(Boolean) IsLowerCaseImpl(
        /* [in] */ Int32 codePoint);

    ECO_LOCAL static CARAPI_(Boolean) IsSpaceCharImpl(
        /* [in] */ Int32 codePoint);

    ECO_LOCAL static CARAPI_(Boolean) IsTitleCaseImpl(
        /* [in] */ Int32 codePoint);

    ECO_LOCAL static CARAPI_(Boolean) IsUnicodeIdentifierPartImpl(
        /* [in] */ Int32 codePoint);

    ECO_LOCAL static CARAPI_(Boolean) IsUnicodeIdentifierStartImpl(
        /* [in] */ Int32 codePoint);

    ECO_LOCAL static CARAPI_(Boolean) IsUpperCaseImpl(
        /* [in] */ Int32 codePoint);

    ECO_LOCAL static CARAPI_(Boolean) IsWhitespaceImpl(
        /* [in] */ Int32 codePoint);

    ECO_LOCAL static CARAPI_(Int32) ToLowerCaseImpl(
        /* [in] */ Int32 codePoint);

    ECO_LOCAL static CARAPI_(Int32) ToTitleCaseImpl(
        /* [in] */ Int32 codePoint);

    ECO_LOCAL static CARAPI_(Int32) ToUpperCaseImpl(
        /* [in] */ Int32 codePoint);

    ECO_LOCAL static CARAPI_(Int32) GetCharAt(
        /* [in] */ const char* src,
        /* [in] */ Int32 srcLen,
        /* [in] */ Int32 index,
        /* [out] */ Int32* nextIndex);

    ECO_LOCAL static CARAPI_(Int32) GetCharAtInternal(
        /* [in] */ const char* cur,
        /* [out] */ Int32* numRead);

    // Write out the source character to <dstP>.
    ECO_LOCAL static CARAPI_(void) WriteUTFBytesToBuffer(
        /* [in] */ Byte* dstP,
        /* [in] */ Char32 srcChar,
        /* [in] */ Int32 bytes);

public:
    /**
     * The minimum radix used for conversions between characters and integers.
     */
    static const Int32 MIN_RADIX;

    /**
     * The maximum radix used for conversions between characters and integers.
     */
    static const Int32 MAX_RADIX;

    /**
     * Unicode category constant Cn.
     */
    static const Byte UNASSIGNED;

    /**
     * Unicode category constant Lu.
     */
    static const Byte UPPERCASE_LETTER;

    /**
     * Unicode category constant Ll.
     */
    static const Byte LOWERCASE_LETTER;

    /**
     * Unicode category constant Lt.
     */
    static const Byte TITLECASE_LETTER;

    /**
     * Unicode category constant Lm.
     */
    static const Byte MODIFIER_LETTER;

    /**
     * Unicode category constant Lo.
     */
    static const Byte OTHER_LETTER;

    /**
     * Unicode category constant Mn.
     */
    static const Byte NON_SPACING_MARK;

    /**
     * Unicode category constant Me.
     */
    static const Byte ENCLOSING_MARK;

    /**
     * Unicode category constant Mc.
     */
    static const Byte COMBINING_SPACING_MARK;

    /**
     * Unicode category constant Nd.
     */
    static const Byte DECIMAL_DIGIT_NUMBER;

    /**
     * Unicode category constant Nl.
     */
    static const Byte LETTER_NUMBER;

    /**
     * Unicode category constant No.
     */
    static const Byte OTHER_NUMBER;

    /**
     * Unicode category constant Zs.
     */
    static const Byte SPACE_SEPARATOR = 12;

    /**
     * Unicode category constant Zl.
     */
    static const Byte LINE_SEPARATOR = 13;

    /**
     * Unicode category constant Zp.
     */
    static const Byte PARAGRAPH_SEPARATOR = 14;

    /**
     * Unicode category constant Cc.
     */
    static const Byte CONTROL = 15;

    /**
     * Unicode category constant Cf.
     */
    static const Byte FORMAT = 16;

    /**
     * Unicode category constant Co.
     */
    static const Byte PRIVATE_USE;

    /**
     * Unicode category constant Cs.
     */
    static const Byte SURROGATE;

    /**
     * Unicode category constant Pd.
     */
    static const Byte DASH_PUNCTUATION;

    /**
     * Unicode category constant Ps.
     */
    static const Byte START_PUNCTUATION;

    /**
     * Unicode category constant Pe.
     */
    static const Byte END_PUNCTUATION;

    /**
     * Unicode category constant Pc.
     */
    static const Byte CONNECTOR_PUNCTUATION;

    /**
     * Unicode category constant Po.
     */
    static const Byte OTHER_PUNCTUATION;

    /**
     * Unicode category constant Sm.
     */
    static const Byte MATH_SYMBOL;

    /**
     * Unicode category constant Sc.
     */
    static const Byte CURRENCY_SYMBOL;

    /**
     * Unicode category constant Sk.
     */
    static const Byte MODIFIER_SYMBOL;

    /**
     * Unicode category constant So.
     */
    static const Byte OTHER_SYMBOL;

    /**
     * Unicode category constant Pi.
     *
     * @since 1.4
     */
    static const Byte INITIAL_QUOTE_PUNCTUATION;

    /**
     * Unicode category constant Pf.
     *
     * @since 1.4
     */
    static const Byte FINAL_QUOTE_PUNCTUATION;

    /**
     * Unicode bidirectional constant.
     *
     * @since 1.4
     */
    static const Byte DIRECTIONALITY_UNDEFINED;

    /**
     * Unicode bidirectional constant L.
     *
     * @since 1.4
     */
    static const Byte DIRECTIONALITY_LEFT_TO_RIGHT = 0;

    /**
     * Unicode bidirectional constant R.
     *
     * @since 1.4
     */
    static const Byte DIRECTIONALITY_RIGHT_TO_LEFT = 1;

    /**
     * Unicode bidirectional constant AL.
     *
     * @since 1.4
     */
    static const Byte DIRECTIONALITY_RIGHT_TO_LEFT_ARABIC = 2;

    /**
     * Unicode bidirectional constant EN.
     *
     * @since 1.4
     */
    static const Byte DIRECTIONALITY_EUROPEAN_NUMBER;

    /**
     * Unicode bidirectional constant ES.
     *
     * @since 1.4
     */
    static const Byte DIRECTIONALITY_EUROPEAN_NUMBER_SEPARATOR;

    /**
     * Unicode bidirectional constant ET.
     *
     * @since 1.4
     */
    static const Byte DIRECTIONALITY_EUROPEAN_NUMBER_TERMINATOR;

    /**
     * Unicode bidirectional constant AN.
     *
     * @since 1.4
     */
    static const Byte DIRECTIONALITY_ARABIC_NUMBER;

    /**
     * Unicode bidirectional constant CS.
     *
     * @since 1.4
     */
    static const Byte DIRECTIONALITY_COMMON_NUMBER_SEPARATOR;

    /**
     * Unicode bidirectional constant NSM.
     *
     * @since 1.4
     */
    static const Byte DIRECTIONALITY_NONSPACING_MARK;

    /**
     * Unicode bidirectional constant BN.
     *
     * @since 1.4
     */
    static const Byte DIRECTIONALITY_BOUNDARY_NEUTRAL = 9;

    /**
     * Unicode bidirectional constant B.
     *
     * @since 1.4
     */
    static const Byte DIRECTIONALITY_PARAGRAPH_SEPARATOR;

    /**
     * Unicode bidirectional constant S.
     *
     * @since 1.4
     */
    static const Byte DIRECTIONALITY_SEGMENT_SEPARATOR;

    /**
     * Unicode bidirectional constant WS.
     *
     * @since 1.4
     */
    static const Byte DIRECTIONALITY_WHITESPACE;

    /**
     * Unicode bidirectional constant ON.
     *
     * @since 1.4
     */
    static const Byte DIRECTIONALITY_OTHER_NEUTRALS;

    /**
     * Unicode bidirectional constant LRE.
     *
     * @since 1.4
     */
    static const Byte DIRECTIONALITY_LEFT_TO_RIGHT_EMBEDDING = 14;

    /**
     * Unicode bidirectional constant LRO.
     *
     * @since 1.4
     */
    static const Byte DIRECTIONALITY_LEFT_TO_RIGHT_OVERRIDE = 15;

    /**
     * Unicode bidirectional constant RLE.
     *
     * @since 1.4
     */
    static const Byte DIRECTIONALITY_RIGHT_TO_LEFT_EMBEDDING = 16;

    /**
     * Unicode bidirectional constant RLO.
     *
     * @since 1.4
     */
    static const Byte DIRECTIONALITY_RIGHT_TO_LEFT_OVERRIDE = 17;

    /**
     * Unicode bidirectional constant PDF.
     *
     * @since 1.4
     */
    static const Byte DIRECTIONALITY_POP_DIRECTIONAL_FORMAT = 18;

    static const UInt32 MIN_HIGH_SURROGATE;  //'\uD800';

    /**
     * The maximum value of a high surrogate or leading surrogate unit in UTF-16
     * encoding, {@code '\uDBFF'}.
     *
     * @since 1.5
     */
    static const UInt32 MAX_HIGH_SURROGATE;//'\uDBFF';

    /**
     * The minimum value of a low surrogate or trailing surrogate unit in UTF-16
     * encoding, {@code '\uDC00'}.
     *
     * @since 1.5
     */
    static const UInt32 MIN_LOW_SURROGATE;//'\uDC00';

    /**
     * The maximum value of a low surrogate or trailing surrogate unit in UTF-16
     * encoding, {@code '\uDFFF'}.
     *
     * @since 1.5
     */
    static const UInt32 MAX_LOW_SURROGATE;//'\uDFFF';

    /**
     * The minimum value of a surrogate unit in UTF-16 encoding, {@code '\uD800'}.
     *
     * @since 1.5
     */
    static const UInt32 MIN_SURROGATE;//'\uD800';

    /**
     * The maximum value of a surrogate unit in UTF-16 encoding, {@code '\uDFFF'}.
     *
     * @since 1.5
     */
    static const UInt32 MAX_SURROGATE;//'\uDFFF';

    /**
     * The minimum value of a supplementary code point, {@code U+010000}.
     *
     * @since 1.5
     */
    static const UInt32 MIN_SUPPLEMENTARY_CODE_POINT;

    /**
     * The minimum code point value, {@code U+0000}.
     *
     * @since 1.5
     */
    static const UInt32 MIN_CODE_POINT;

    /**
     * The maximum code point value, {@code U+10FFFF}.
     *
     * @since 1.5
     */
    static const UInt32 MAX_CODE_POINT;

    /**
     * The number of bits required to represent a {@code Character} value
     * unsigned form.
     *
     * @since 1.5
     */
    static const Int32 SIZE;

private:
    ECO_LOCAL static const Byte DIRECTIONALITY[];
};

} // namespace Core
} // namespace Elastos

#endif //__ELASTOS_CORE_CHARACTER_H__
