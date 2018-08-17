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

#ifndef __ELASTOS_UTILITY_TIMEZONEGETTER_H__
#define __ELASTOS_UTILITY_TIMEZONEGETTER_H__

#include "Elastos.CoreLibrary.Utility.h"
#include "elastos/core/Object.h"

using Elastos::Utility::ITimeZoneGetter;

namespace Elastos {
namespace Utility {

class ECO_PUBLIC TimeZoneGetter
    : public Object
    , public ITimeZoneGetter
{
public:
    TimeZoneGetter();

    virtual ~TimeZoneGetter();

    CAR_INTERFACE_DECL()

    static CARAPI_(AutoPtr<ITimeZoneGetter>) GetInstance();

    static CARAPI SetInstance(
        /* [in] */ ITimeZoneGetter* getter);

    virtual CARAPI GetId(
        /* [out] */ String* string) = 0;

    CARAPI ToString(
        /* [out] */ String* str);
private:
    ECO_LOCAL static AutoPtr<ITimeZoneGetter> sInstance;
};

class DefaultTimeZoneGetter
    : public TimeZoneGetter
{
public:
    virtual CARAPI GetId(
        /* [out] */ String* string);

private:
    String mId;
};

}// namespace Utility
}// namespace Utility

#endif // __ELASTOS_UTILITY_TIMEZONEGETTER_H__
