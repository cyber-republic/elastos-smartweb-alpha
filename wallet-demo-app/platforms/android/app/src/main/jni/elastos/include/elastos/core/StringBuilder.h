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

#ifndef __ELASTOS_CORE_STRINGBUILDER_H__
#define __ELASTOS_CORE_STRINGBUILDER_H__

#include "elastos/core/AbstractStringBuilder.h"

namespace Elastos {
namespace Core {

class StringBuffer;

/**
 * A modifiable {@link CharSequence sequence of characters} for use in creating
 * strings. This class is intended as a direct replacement of
 * {@link StringBuffer} for non-concurrent use; unlike {@code StringBuffer} this
 * class is not synchronized.
 *
 * <p>For particularly complex string-building needs, consider {@link java.util.Formatter}.
 *
 * <p>The majority of the modification methods on this class return {@code
 * this} so that method calls can be chained together. For example:
 * {@code new StringBuilder("a").append("b").append("c").toString()}.
 *
 * @see CharSequence
 * @see Appendable
 * @see StringBuffer
 * @see String
 * @see String#format
 * @since 1.5
 */
class ECO_PUBLIC StringBuilder
    : public AbstractStringBuilder
    , public IStringBuilder
{
public:
    CAR_INTERFACE_DECL()

    /**
     * Constructs an instance with an initial capacity of {@code 16}.
     *
     * @see #capacity()
     */
    StringBuilder();

    /**
     * Constructs an instance with the specified capacity.
     *
     * @param capacity
     *            the initial capacity to use.
     * @throws NegativeArraySizeException
     *             if the specified {@code capacity} is negative.
     * @see #capacity()
     */
    StringBuilder(
        /* [in] */ Int32 capacity);

    /**
     * Constructs an instance that's initialized with the contents of the
     * specified {@code String}. The capacity of the new builder will be the
     * length of the {@code String} plus 16.
     *
     * @param str
     *            the {@code String} to copy into the builder.
     * @throws NullPointerException
     *            if {@code str} is {@code null}.
     */
    StringBuilder(
        /* [in] */ const String& str);

    StringBuilder(
        /* [in] */ const char* str);

    virtual ~StringBuilder();

    CARAPI ToASCIILowerCase();

    CARAPI ToASCIIUpperCase();

    CARAPI Reset();

    /**
     * The current length based on unicode character.
     *
     * @return the number of characters contained in this instance.
     */
    CARAPI GetLength(
        /* [out] */ Int32* length);

    using AbstractStringBuilder::GetLength;

    /**
     * The number of bytes.
     *
     * @return the number of bytes contained in this instance.
     */
    CARAPI GetByteCount(
        /* [out] */ Int32* byteLength);

    using AbstractStringBuilder::GetByteCount;

    /**
     * Returns the number of bytes that can be held without growing.
     *
     * @return the capacity
     * @see #ensureCapacity
     * @see #length
     */
    CARAPI GetCapacity(
        /* [out] */ Int32* capacity);

    using AbstractStringBuilder::GetCapacity;

    /**
     * Ensures that this object has a minimum capacity available before
     * requiring the internal buffer to be enlarged. The general policy of this
     * method is that if the {@code minimumCapacity} is larger than the current
     * {@link #capacity()}, then the capacity will be increased to the largest
     * value of either the {@code minimumCapacity} or the current capacity
     * multiplied by two plus two. Although this is the general policy, there is
     * no guarantee that the capacity will change.
     *
     * @param min
     *            the new minimum capacity to set.
     */
    CARAPI EnsureCapacity(
        /* [in] */ Int32 min);

    /**
     * Trims off any extra capacity beyond the current length. Note, this method
     * is NOT guaranteed to change the capacity of this object.
     *
     * @since 1.5
     */
    CARAPI TrimToSize();

    /**
     * Sets the character at the {@code index} base on unicode.
     *
     * @param index
     *            the zero-based index of the unicode character to replace.
     * @param ch
     *            the character to set.
     * @throws IndexOutOfBoundsException
     *             if {@code index} is negative or greater than or equal to the
     *             current {@link #length()}.
     */
    CARAPI SetCharAt(
        /* [in] */ Int32 index,
        /* [in] */ Char32 ch);

    /**
     * Retrieves the Unicode code point value at the {@code index}.
     *
     * @param index
     *            the index to the {@code char} code unit.
     * @return the Unicode code point value.
     * @throws IndexOutOfBoundsException
     *             if {@code index} is negative or greater than or equal to
     *             {@link #length()}.
     * @see Character
     * @see Character#codePointAt(char[], int, int)
     * @since 1.5
     */
    CARAPI GetCharAt(
        /* [in] */ Int32 index,
        /* [out] */ Char32* c);

    CARAPI_(Char32) GetCharAt(
        /* [in] */ Int32 index);

    /**
     * Copies the requested sequence of characters into {@code dst} passed
     * starting at {@code dst}.
     *
     * @param start
     *            the inclusive start index of the unicode characters to copy.
     * @param end
     *            the exclusive end index of the unicode characters to copy.
     * @param dst
     *            the {@code char[]} to copy the characters to.
     * @param dstStart
     *            the inclusive start index of {@code dst} to begin copying to.
     * @throws IndexOutOfBoundsException
     *             if the {@code start} is negative, the {@code dstStart} is
     *             negative, the {@code start} is greater than {@code end}, the
     *             {@code end} is greater than the current {@link #length()} or
     *             {@code dstStart + end - begin} is greater than
     *             {@code dst.length}.
     */
    CARAPI GetChars(
        /* [in] */ Int32 start,
        /* [in] */ Int32 end,
        /* [in, out] */ ArrayOf<Char32>* dst,
        /* [in] */ Int32 dstStart);

    /**
     * Sets the current length to a new value. If the new length is larger than
     * the current length, then the new characters at the end of this object
     * will contain the {@code char} value of {@code \u0000}.
     *
     * @param length
     *            the new length of this StringBuffer.
     * @exception IndexOutOfBoundsException
     *                if {@code length < 0}.
     * @see #length
     */
    CARAPI SetLength(
        /* [in] */ Int32 length);

    /**
     * Returns the String value of the subsequence from the {@code start} index
     * to the current end.
     *
     * @param start
     *            the inclusive start index to begin the subsequence.
     * @return a String containing the subsequence.
     * @throws StringIndexOutOfBoundsException
     *             if {@code start} is negative or greater than the current
     *             {@link #length()}.
     */
    CARAPI Substring(
        /* [in] */ Int32 start,
        /* [out] */ String* str);

    /**
     * Returns the String value of the subsequence from the {@code start} index
     * to the {@code end} index.
     *
     * @param start
     *            the inclusive start index to begin the subsequence.
     * @param end
     *            the exclusive end index to end the subsequence.
     * @return a String containing the subsequence.
     * @throws StringIndexOutOfBoundsException
     *             if {@code start} is negative, greater than {@code end} or if
     *             {@code end} is greater than the current {@link #length()}.
     */
    CARAPI Substring(
        /* [in] */ Int32 start,
        /* [in] */ Int32 end,
        /* [out] */ String* str);

    /**
     * Returns a {@code CharSequence} of the subsequence from the {@code start}
     * index to the {@code end} index.
     *
     * @param start
     *            the inclusive start index to begin the subsequence.
     * @param end
     *            the exclusive end index to end the subsequence.
     * @return a CharSequence containing the subsequence.
     * @throws IndexOutOfBoundsException
     *             if {@code start} is negative, greater than {@code end} or if
     *             {@code end} is greater than the current {@link #length()}.
     * @since 1.4
     */
    CARAPI SubSequence(
        /* [in] */ Int32 start,
        /* [in] */ Int32 end,
        /* [out] */ ICharSequence** seq);

    /**
     * Searches for the first index of the specified character. The search for
     * the character starts at the beginning and moves towards the end.
     *
     * @param string
     *            the string to find.
     * @return the index of the specified character, -1 if the character isn't
     *         found.
     * @see #lastIndexOf(String)
     * @since 1.4
     */
    CARAPI IndexOf(
        /* [in] */ const String& string,
        /* [out] */ Int32* index);

    /**
     * Searches for the index of the specified character. The search for the
     * character starts at the specified offset and moves towards the end.
     *
     * @param subString
     *            the string to find.
     * @param start
     *            the starting offset.
     * @return the index of the specified character, -1 if the character isn't
     *         found
     * @see #lastIndexOf(String,int)
     * @since 1.4
     */
    CARAPI IndexOf(
        /* [in] */ const String& subString,
        /* [in] */ Int32 start,
        /* [out] */ Int32* index);

    /**
     * Searches for the last index of the specified character. The search for
     * the character starts at the end and moves towards the beginning.
     *
     * @param string
     *            the string to find.
     * @return the index of the specified character, -1 if the character isn't
     *         found.
     * @throws NullPointerException
     *             if {@code string} is {@code null}.
     * @see String#lastIndexOf(java.lang.String)
     * @since 1.4
     */
    CARAPI LastIndexOf(
        /* [in] */ const String& string,
        /* [out] */ Int32* index);

    /**
     * Searches for the index of the specified character. The search for the
     * character starts at the specified offset and moves towards the beginning.
     *
     * @param subString
     *            the string to find.
     * @param start
     *            the starting offset.
     * @return the index of the specified character, -1 if the character isn't
     *         found.
     * @throws NullPointerException
     *             if {@code subString} is {@code null}.
     * @see String#lastIndexOf(String,int)
     * @since 1.4
     */
    CARAPI LastIndexOf(
        /* [in] */ const String& subString,
        /* [in] */ Int32 start,
        /* [out] */ Int32* index);

    CARAPI AppendNULL();

    CARAPI Append(
        /* [in] */ const char* str);

    /**
     * Adds the string representation of the specified boolean to the end of
     * this StringBuffer.
     * <p>
     * If the argument is {@code true} the string {@code "true"} is appended,
     * otherwise the string {@code "false"} is appended.
     *
     * @param b
     *            the boolean to append.
     * @return this StringBuffer.
     * @see String#valueOf(boolean)
     */
    CARAPI Append(
        /* [in] */ Boolean b);

    /**
     * Adds the string representation of the specified integer to the end of
     * this StringBuffer.
     *
     * @param i
     *            the integer to append.
     * @return this StringBuffer.
     * @see String#valueOf(int)
     */
    CARAPI Append(
        /* [in] */ Int32 i);

    /**
     * Adds the string representation of the specified long to the end of this
     * StringBuffer.
     *
     * @param l
     *            the long to append.
     * @return this StringBuffer.
     * @see String#valueOf(long)
     */
    CARAPI Append(
        /* [in] */ Int64 l);

    /**
     * Adds the string representation of the specified float to the end of this
     * StringBuffer.
     *
     * @param f
     *            the float to append.
     * @return this StringBuffer.
     * @see String#valueOf(float)
     */
    CARAPI Append(
        /* [in] */ Float f);

    /**
     * Adds the string representation of the specified double to the end of this
     * StringBuffer.
     *
     * @param d
     *            the double to append.
     * @return this StringBuffer.
     * @see String#valueOf(double)
     */
    CARAPI Append(
        /* [in] */ Double d);

    /**
     * Adds the specified character to the end of this buffer.
     *
     * @param ch
     *            the character to append.
     * @return this StringBuffer.
     * @see String#valueOf(char)
     */
    CARAPI AppendChar(
        /* [in] */ Char32 c);

    /**
     * Adds the string representation of the specified object to the end of this
     * StringBuffer.
     * <p>
     * If the specified object is {@code null} the string {@code "null"} is
     * appended, otherwise the objects {@code toString} is used to get its
     * string representation.
     *
     * @param obj
     *            the object to append (may be null).
     * @return this StringBuffer.
     * @see String#valueOf(Object)
     */
    CARAPI Append(
        /* [in] */ IInterface* obj);

    CARAPI Append(
        /* [in] */ IObject* obj);

    /**
     * Adds the specified string to the end of this buffer.
     * <p>
     * If the specified string is {@code null} the string {@code "null"} is
     * appended, otherwise the contents of the specified string is appended.
     *
     * @param string
     *            the string to append (may be null).
     * @return this StringBuffer.
     */
    CARAPI Append(
        /* [in] */ const String& str);

    /**
     * Adds the specified StringBuffer to the end of this buffer.
     * <p>
     * If the specified StringBuffer is {@code null} the string {@code "null"}
     * is appended, otherwise the contents of the specified StringBuffer is
     * appended.
     *
     * @param sb
     *            the StringBuffer to append (may be null).
     * @return this StringBuffer.
     *
     * @since 1.4
     */
    CARAPI Append(
        /* [in] */ IStringBuffer* sb);

    /**
     * Adds the specified StringBuilder to the end of this buffer.
     * <p>
     * If the specified StringBuilder is {@code null} the string {@code "null"}
     * is appended, otherwise the contents of the specified StringBuilder is
     * appended.
     *
     * @param sb
     *            the StringBuilder to append (may be null).
     * @return this StringBuffer.
     *
     * @since 1.4
     */
    CARAPI Append(
        /* [in] */ IStringBuilder* sb);

    /**
     * Adds the character array to the end of this buffer.
     *
     * @param chars
     *            the character array to append.
     * @return this StringBuffer.
     * @throws NullPointerException
     *            if {@code chars} is {@code null}.
     */
    CARAPI Append(
        /* [in] */ const ArrayOf<Char32>& chars);

    /**
     * Adds the specified sequence of characters to the end of this buffer.
     *
     * @param chars
     *            the character array to append.
     * @param start
     *            the starting offset.
     * @param length
     *            the number of characters.
     * @return this StringBuffer.
     * @throws ArrayIndexOutOfBoundsException
     *             if {@code length < 0} , {@code start < 0} or {@code start +
     *             length > chars.length}.
     * @throws NullPointerException
     *            if {@code chars} is {@code null}.
     */
    CARAPI Append(
        /* [in] */ const ArrayOf<Char32>& chars,
        /* [in] */ Int32 start,
        /* [in] */ Int32 length);

    /**
     * Appends the specified CharSequence to this buffer.
     * <p>
     * If the specified CharSequence is {@code null} the string {@code "null"}
     * is appended, otherwise the contents of the specified CharSequence is
     * appended.
     *
     * @param s
     *            the CharSequence to append.
     * @return this StringBuffer.
     * @since 1.5
     */
    CARAPI Append(
        /* [in] */ ICharSequence* csq);

    /**
     * Appends the specified subsequence of the CharSequence to this buffer.
     * <p>
     * If the specified CharSequence is {@code null}, then the string {@code
     * "null"} is used to extract a subsequence.
     *
     * @param s
     *            the CharSequence to append.
     * @param start
     *            the inclusive start index.
     * @param end
     *            the exclusive end index.
     * @return this StringBuffer.
     * @throws IndexOutOfBoundsException
     *             if {@code start} or {@code end} are negative, {@code start}
     *             is greater than {@code end} or {@code end} is greater than
     *             the length of {@code s}.
     * @since 1.5
     */
    CARAPI Append(
        /* [in] */ ICharSequence* csq,
        /* [in] */ Int32 start,
        /* [in] */ Int32 end);

    /**
     * Inserts the string representation of the specified boolean into this
     * buffer at the specified offset.
     *
     * @param index
     *            the index at which to insert.
     * @param b
     *            the boolean to insert.
     * @return this buffer.
     * @throws StringIndexOutOfBoundsException
     *             if {@code index < 0} or {@code index > length()}.
     */
    CARAPI Insert(
        /* [in] */ Int32 offset,
        /* [in] */ Boolean b);

    /**
     * Inserts the string representation of the specified integer into this
     * buffer at the specified offset.
     *
     * @param index
     *            the index at which to insert.
     * @param i
     *            the integer to insert.
     * @return this buffer.
     * @throws StringIndexOutOfBoundsException
     *             if {@code index < 0} or {@code index > length()}.
     */
    CARAPI Insert(
        /* [in] */ Int32 offset,
        /* [in] */ Int32 i);

    /**
     * Inserts the string representation of the specified long into this buffer
     * at the specified offset.
     *
     * @param index
     *            the index at which to insert.
     * @param l
     *            the long to insert.
     * @return this buffer.
     * @throws StringIndexOutOfBoundsException
     *             if {@code index < 0} or {@code index > length()}.
     */
    CARAPI Insert(
        /* [in] */ Int32 offset,
        /* [in] */ Int64 l);

    /**
     * Inserts the string representation of the specified into this buffer
     * double at the specified offset.
     *
     * @param index
     *            the index at which to insert.
     * @param d
     *            the double to insert.
     * @return this buffer.
     * @throws StringIndexOutOfBoundsException
     *             if {@code index < 0} or {@code index > length()}.
     */
    CARAPI Insert(
        /* [in] */ Int32 offset,
        /* [in] */ Double d);

    /**
     * Inserts the string representation of the specified float into this buffer
     * at the specified offset.
     *
     * @param index
     *            the index at which to insert.
     * @param f
     *            the float to insert.
     * @return this buffer.
     * @throws StringIndexOutOfBoundsException
     *             if {@code index < 0} or {@code index > length()}.
     */
    CARAPI Insert(
        /* [in] */ Int32 offset,
        /* [in] */ Float f);


    /**
     * Inserts the character into this buffer at the specified offset.
     *
     * @param index
     *            the index at which to insert.
     * @param ch
     *            the character to insert.
     * @return this buffer.
     * @throws ArrayIndexOutOfBoundsException
     *             if {@code index < 0} or {@code index > length()}.
     */
    CARAPI InsertChar(
        /* [in] */ Int32 offset,
        /* [in] */ Char32 c);

    /**
     * Inserts the string representation of the specified object into this
     * buffer at the specified offset.
     * <p>
     * If the specified object is {@code null}, the string {@code "null"} is
     * inserted, otherwise the objects {@code toString} method is used to get
     * its string representation.
     *
     * @param index
     *            the index at which to insert.
     * @param obj
     *            the object to insert (may be null).
     * @return this buffer.
     * @throws StringIndexOutOfBoundsException
     *             if {@code index < 0} or {@code index > length()}.
     */
    CARAPI Insert(
        /* [in] */ Int32 offset,
        /* [in] */ IInterface* obj);

    /**
     * Inserts the string into this buffer at the specified offset.
     * <p>
     * If the specified string is {@code null}, the string {@code "null"} is
     * inserted, otherwise the contents of the string is inserted.
     *
     * @param index
     *            the index at which to insert.
     * @param string
     *            the string to insert (may be null).
     * @return this buffer.
     * @throws StringIndexOutOfBoundsException
     *             if {@code index < 0} or {@code index > length()}.
     */
    CARAPI Insert(
        /* [in] */ Int32 offset,
        /* [in] */ const String& str);

    /**
     * Inserts the character array into this buffer at the specified offset.
     *
     * @param index
     *            the index at which to insert.
     * @param chars
     *            the character array to insert.
     * @return this buffer.
     * @throws StringIndexOutOfBoundsException
     *             if {@code index < 0} or {@code index > length()}.
     * @throws NullPointerException
     *            if {@code chars} is {@code null}.
     */
    CARAPI Insert(
        /* [in] */ Int32 offset,
        /* [in] */ const ArrayOf<Char32>& chars);

    /**
     * Inserts the specified subsequence of characters into this buffer at the
     * specified index.
     *
     * @param index
     *            the index at which to insert.
     * @param chars
     *            the character array to insert.
     * @param start
     *            the starting offset.
     * @param length
     *            the number of characters.
     * @return this buffer.
     * @throws NullPointerException
     *             if {@code chars} is {@code null}.
     * @throws StringIndexOutOfBoundsException
     *             if {@code length < 0}, {@code start < 0}, {@code start +
     *             length > chars.length}, {@code index < 0} or {@code index >
     *             length()}
     */
    CARAPI Insert(
        /* [in] */ Int32 offset,
        /* [in] */ const ArrayOf<Char32>& chars,
        /* [in] */ Int32 start,
        /* [in] */ Int32 length);

    /**
     * Inserts the specified CharSequence into this buffer at the specified
     * index.
     * <p>
     * If the specified CharSequence is {@code null}, the string {@code "null"}
     * is inserted, otherwise the contents of the CharSequence.
     *
     * @param index
     *            The index at which to insert.
     * @param s
     *            The char sequence to insert.
     * @return this buffer.
     * @throws IndexOutOfBoundsException
     *             if {@code index < 0} or {@code index > length()}.
     * @since 1.5
     */
    CARAPI Insert(
        /* [in] */ Int32 offset,
        /* [in] */ ICharSequence* s);

    /**
     * Inserts the specified subsequence into this buffer at the specified
     * index.
     * <p>
     * If the specified CharSequence is {@code null}, the string {@code "null"}
     * is inserted, otherwise the contents of the CharSequence.
     *
     * @param index
     *            The index at which to insert.
     * @param s
     *            The char sequence to insert.
     * @param start
     *            The inclusive start index in the char sequence.
     * @param end
     *            The exclusive end index in the char sequence.
     * @return this buffer.
     * @throws IndexOutOfBoundsException
     *             if {@code index} is negative or greater than the current
     *             length, {@code start} or {@code end} are negative, {@code
     *             start} is greater than {@code end} or {@code end} is greater
     *             than the length of {@code s}.
     * @since 1.5
     */
    CARAPI Insert(
        /* [in] */ Int32 offset,
        /* [in] */ ICharSequence* s,
        /* [in] */ Int32 start,
        /* [in] */ Int32 end);

    /**
     * Replaces the characters in the specified range with the contents of the
     * specified string.
     *
     * @param start
     *            the inclusive begin index.
     * @param end
     *            the exclusive end index.
     * @param string
     *            the string that will replace the contents in the range.
     * @return this buffer.
     * @throws StringIndexOutOfBoundsException
     *             if {@code start} or {@code end} are negative, {@code start}
     *             is greater than {@code end} or {@code end} is greater than
     *             the length of {@code s}.
     */
    CARAPI Replace(
        /* [in] */ Int32 start,
        /* [in] */ Int32 end,
        /* [in] */ const String& string);

    /**
     * Reverses the order of characters in this buffer.
     *
     * @return this buffer.
     */
    CARAPI Reverse();

    /**
     * Deletes the character at the specified offset.
     *
     * @param location
     *            the offset of the character to delete.
     * @return this StringBuffer.
     * @throws StringIndexOutOfBoundsException
     *             if {@code location < 0} or {@code location >= length()}
     */
    CARAPI DeleteCharAt(
        /* [in] */ Int32 location);

    /**
     * Deletes a range of characters.
     *
     * @param start
     *            the offset of the first character.
     * @param end
     *            the offset one past the last character.
     * @return this StringBuffer.
     * @throws StringIndexOutOfBoundsException
     *             if {@code start < 0}, {@code start > end} or {@code end >
     *             length()}.
     */
    CARAPI Delete(
        /* [in] */ Int32 start,
        /* [in] */ Int32 end);

    /**
     * Returns the contents of this builder.
     *
     * @return the string representation of the data in this builder.
     */
    CARAPI ToString(
        /* [out] */ String* str);

    CARAPI_(String) ToString();

    CARAPI_(AutoPtr<ICharSequence>) ToCharSequence();

    CARAPI_(String) Substring(
        /* [in] */ Int32 start);

    CARAPI_(String) Substring(
        /* [in] */ Int32 start,
        /* [in] */ Int32 end);

public:
    StringBuilder& operator+=(const Boolean);
    StringBuilder& operator+=(const char);
    StringBuilder& operator+=(const Char32);
    StringBuilder& operator+=(const Int32);
    StringBuilder& operator+=(const Int64);
    StringBuilder& operator+=(const Float);
    StringBuilder& operator+=(const Double);
    StringBuilder& operator+=(const char*);
    StringBuilder& operator+=(const String&);
    StringBuilder& operator+=(StringBuffer&);
    StringBuilder& operator+=(StringBuilder&);
    StringBuilder& operator+=(IInterface*);
    StringBuilder& operator+=(IObject*);

private:
    ECO_LOCAL StringBuilder(const StringBuilder&);
    ECO_LOCAL StringBuilder& operator=(const StringBuilder&);
};

} // namespace Core
} // namespace Elastos

#endif //__ELASTOS_CORE_STRINGBUILDER_H__
