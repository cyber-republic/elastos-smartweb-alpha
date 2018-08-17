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

#ifndef __ELASTOS_UTILITY_PROPERTIES_H__
#define __ELASTOS_UTILITY_PROPERTIES_H__

#include "elastos/utility/HashTable.h"

using Elastos::IO::IInputStream;
using Elastos::IO::IOutputStream;
using Elastos::IO::IPrintStream;
using Elastos::IO::IPrintWriter;
using Elastos::IO::IReader;
using Elastos::IO::IWriter;
using Elastos::Core::IAppendable;
using Elastos::Core::IStringBuilder;

namespace Elastos {
namespace Utility {

class ECO_PUBLIC Properties
    : public HashTable
    , public IProperties
{
public:
    CAR_INTERFACE_DECL()

    CARAPI GetProperty(
        /* [in] */ const String& name,
        /* [out] */ String* str);

    CARAPI GetProperty(
        /* [in] */ const String& name,
        /* [in] */ const String& defaultValue,
        /* [out] */ String* str);

    CARAPI List(
        /* [in] */ IPrintStream* outstream);

    CARAPI List(
        /* [in] */ IPrintWriter* outwriter);

    CARAPI Load(
        /* [in] */ IInputStream* instream);

    CARAPI Load(
        /* [in] */ IReader* inreader);

    CARAPI PropertyNames(
        /* [out] */ IEnumeration** names);

    CARAPI StringPropertyNames(
        /* [out] */ ISet** strNames);

    CARAPI Save(
        /* [in] */ IOutputStream* outstream,
        /* [in] */ const String& comment);

    CARAPI SetProperty(
        /* [in] */ const String& name,
        /* [in] */ const String& value ,
        /* [out] */ String* oldValue);

    CARAPI Store(
        /* [in] */ IOutputStream* outstream,
        /* [in] */ const String& comment);

    CARAPI Store(
        /* [in] */ IWriter* writer,
        /* [in] */ const String& comment);

    CARAPI LoadFromXML(
        /* [in] */ IInputStream* instream);

    CARAPI StoreToXML(
        /* [in] */ IOutputStream* os,
        /* [in] */ const String& comment);

    CARAPI StoreToXML(
        /* [in] */ IOutputStream* os,
        /* [in] */ const String& comment,
        /* [in] */ const String& encoding);

protected:
    Properties();

    CARAPI constructor(
        /* [in] */ Properties* properties);

private:
    ECO_LOCAL CARAPI_(void) DumpString(
        /* [in] */ IStringBuilder* buffer,
        /* [in] */ const String& string,
        /* [in] */ Boolean key);

    ECO_LOCAL CARAPI ListToAppendable(
        /* [in] */ IAppendable* out);

    ECO_LOCAL CARAPI SelectProperties(
        /* [in] */ IMap* selectProperties,
        /* [in] */ Boolean isStringOnly);

    ECO_LOCAL CARAPI_(String) SubstitutePredefinedEntries(
        /* [in] */ const String& s);

protected:
    /**
    * The default values for keys not found in this {@code Properties}
    * instance.
     */
    AutoPtr<Properties> mDefaults;

private:
    ECO_LOCAL static const String PROP_DTD_NAME;
    ECO_LOCAL static const String PROP_DTD;

    ECO_LOCAL static const Int32 NONE;
    ECO_LOCAL static const Int32 SLASH;
    ECO_LOCAL static const Int32 UNICODE;
    ECO_LOCAL static const Int32 CONTINUE;
    ECO_LOCAL static const Int32 KEY_DONE;
    ECO_LOCAL static const Int32 IGNORE;

    // private transient DocumentBuilder builder = null;
};

} // namespace Utility
} // namespace Elastos

#endif // __ELASTOS_UTILITY_PROPERTIES_H__
