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

#ifndef __ELASTOS_CORE_ABSTRACTSTRINGBUILDER_H__
#define __ELASTOS_CORE_ABSTRACTSTRINGBUILDER_H__

#include "elastos/core/Object.h"

using Elastos::IO::ISerializable;

namespace Elastos {
namespace Core {

/**
 * A modifiable {@link CharSequence sequence of characters} for use in creating
 * and modifying Strings. This class is intended as a base class for
 * {@link StringBuffer} and {@link StringBuilder}.
 *
 * @see StringBuffer
 * @see StringBuilder
 * @since 1.5
 *
 */
class AbstractStringBuilder
    : public Object
    , public IAppendable
    , public ISerializable
    , public ICharSequence
{
public:
    CAR_INTERFACE_DECL()

protected:
    AbstractStringBuilder();

    AbstractStringBuilder(
        /* [in] */ Int32 capacity);

    AbstractStringBuilder(
        /* [in] */ const String& str);

    virtual ~AbstractStringBuilder();

    CARAPI SetLength(
        /* [in] */ Int32 length);

    ECO_PUBLIC CARAPI_(Int32) GetLength();

    ECO_PUBLIC CARAPI_(Int32) GetByteCount();

    ECO_PUBLIC CARAPI_(Int32) GetCapacity();

    CARAPI EnsureCapacity(
        /* [in] */ Int32 min);

    CARAPI EnlargeBuffer(
        /* [in] */ Int32 min);

    CARAPI TrimToSize();

    CARAPI SetCharAt(
        /* [in] */ Int32 index,
        /* [in] */ Char32 ch);

    CARAPI GetCharAt(
        /* [in] */ Int32 index,
        /* [out] */ Char32* result);

    CARAPI GetChars(
        /* [in] */ Int32 start,
        /* [in] */ Int32 end,
        /* [in] */ ArrayOf<Char32>* dst,
        /* [in] */ Int32 dstStart);

    CARAPI Substring(
        /* [in] */ Int32 start,
        /* [out] */ String* string);

    CARAPI Substring(
        /* [in] */ Int32 start,
        /* [in] */ Int32 end,
        /* [out] */ String* string);

    CARAPI SubSequence(
        /* [in] */ Int32 start,
        /* [in] */ Int32 end,
        /* [out] */ ICharSequence** seq);

    CARAPI IndexOf(
        /* [in] */ const String& string,
        /* [out] */ Int32* index);

    CARAPI IndexOf(
        /* [in] */ const String& string,
        /* [in] */ Int32 start,
        /* [out] */ Int32* index);

    CARAPI LastIndexOf(
        /* [in] */ const String& string,
        /* [out] */ Int32* index);

    CARAPI LastIndexOf(
        /* [in] */ const String& string,
        /* [in] */ Int32 start,
        /* [out] */ Int32* index);

    CARAPI AppendNULL();

    CARAPI Append(
        /* [in] */ char const* cstr);

    CARAPI Append(
        /* [in] */ Boolean b);

    CARAPI Append(
        /* [in] */ Int32 i);

    CARAPI Append(
        /* [in] */ Int64 l);

    CARAPI Append(
        /* [in] */ Float f);

    CARAPI Append(
        /* [in] */ Double d);

    CARAPI Append(
        /* [in] */ const ArrayOf<Char32>& chars);

    CARAPI Append(
        /* [in] */ const ArrayOf<Char32>& chars,
        /* [in] */ Int32 offset,
        /* [in] */ Int32 length);

    CARAPI AppendChar(
        /* [in] */ Char32 ch);

    CARAPI Append(
        /* [in] */ const String& string);

    CARAPI Append(
        /* [in] */ ICharSequence* csq);

    CARAPI Append(
        /* [in] */ ICharSequence* csq,
        /* [in] */ Int32 start,
        /* [in] */ Int32 end);

    CARAPI Append(
        /* [in] */ IInterface* obj);

    CARAPI Insert(
        /* [in] */ Int32 offset,
        /* [in] */ Boolean b);

    CARAPI Insert(
        /* [in] */ Int32 offset,
        /* [in] */ Int32 i);

    CARAPI Insert(
        /* [in] */ Int32 offset,
        /* [in] */ Int64 l);

    CARAPI Insert(
        /* [in] */ Int32 offset,
        /* [in] */ Float f);

    CARAPI Insert(
        /* [in] */ Int32 offset,
        /* [in] */ Double d);

    CARAPI InsertChar(
        /* [in] */ Int32 offset,
        /* [in] */ Char32 c);

    CARAPI Insert(
        /* [in] */ Int32 offset,
        /* [in] */ const ArrayOf<Char32>& chars);

    CARAPI Insert(
        /* [in] */ Int32 offset,
        /* [in] */ const ArrayOf<Char32>& chars,
        /* [in] */ Int32 start,
        /* [in] */ Int32 length);

    CARAPI Insert(
        /* [in] */ Int32 offset,
        /* [in] */ const String& str);

    CARAPI Insert(
        /* [in] */ Int32 offset,
        /* [in] */ ICharSequence* s);

    CARAPI Insert(
        /* [in] */ Int32 offset,
        /* [in] */ ICharSequence* s,
        /* [in] */ Int32 start,
        /* [in] */ Int32 end);

    CARAPI Insert(
        /* [in] */ Int32 offset,
        /* [in] */ IInterface* obj);

    CARAPI Replace(
        /* [in] */ Int32 start,
        /* [in] */ Int32 end,
        /* [in] */ const String& string);

    CARAPI Reverse();

    CARAPI Delete(
        /* [in] */ Int32 start,
        /* [in] */ Int32 end);

    CARAPI DeleteCharAt(
        /* [in] */ Int32 index);

    CARAPI ToASCIICaseString(
        /* [in] */ Boolean isUpperCase);

private:
    /**
     * @brief constracts AbstractStringBuilder with s.
     *
     * Constract a string buffer with a constant characters in it and the specified initial step.
     * @param s A constant character pointer argument ,it contains the initial contents of the string buffer.
     */
    CARAPI_(void) Init(
        /* [in] */ const char* s,
        /* [in] */ Int32 step);

    /**
     * @brief Increases the capacity of the string buffer.
     * @param size An integer value representing the size want to increase for the string buffer.
     */
    CARAPI_(void) Break(
        /* [in] */ Int32 size);

    CARAPI_(void) GenerateNewBuffer(
        /* [in] */ Int32 capacity);

    CARAPI_(void) DbgPrint();

    // see UTF8.cpp
    inline Boolean IsASCII(char c) { return !(c & ~0x7F); }

    inline Int32 UTF8SequenceLengthNonASCII(char b0)
    {
        if ((b0 & 0xC0) != 0xC0)
            return 0;
        if ((b0 & 0xE0) == 0xC0)
            return 2;
        if ((b0 & 0xF0) == 0xE0)
            return 3;
        if ((b0 & 0xF8) == 0xF0)
            return 4;
        return 0;
    }

    inline Int32 UTF8SequenceLength(char b0)
    {
        return IsASCII(b0) ? 1 : UTF8SequenceLengthNonASCII(b0);
    }

private:

    /**
     * @var mByteCount
     * @brief The number of bits used to represent the length of a StringBuffer object.
     */
    Int32   mByteCount;// length in java

    /**
     * @var mCharCount
     * @brief The number of unicode code point used to represent the length of a StringBuffer object.
     */
    Int32 mCharCount;
    volatile Boolean mIsCounted;

    /**
     * @var mString
     * @brief The character pointer used to contain a string value.
     */
    char*  mString;

    /**
     * @var mStep
     * @brief The Integer value used to define a step how long a string buffer would increase for one time.
     */
    Int32   mStep;

    /**
     * @var mCapacity
     * @brief Integer value used to define the capacity of a string buffer.
     */
    Int32   mCapacity;

    Boolean mShared;
};

} // namespace Core
} // namespace Elastos

#endif // __ELASTOS_CORE_ABSTRACTSTRINGBUILDER_H__
