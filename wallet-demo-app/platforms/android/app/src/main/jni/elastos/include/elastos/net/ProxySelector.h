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

#ifndef __ELASTOS_NET_PROXYSELECTOR_H__
#define __ELASTOS_NET_PROXYSELECTOR_H__

#include "Elastos.CoreLibrary.Net.h"
#include "elastos/core/Object.h"
#include "elastos/utility/etl/List.h"

using Elastos::Core::Object;
using Elastos::Utility::IList;
using Elastos::Utility::Etl::List;
using Elastos::Net::INetPermission;

namespace Elastos {
namespace Net {

class ECO_PUBLIC ProxySelector
    : public Object
    , public IProxySelector
{
public:
    CAR_INTERFACE_DECL()

    ProxySelector();

    virtual ~ProxySelector();

    static CARAPI GetDefault(
        /* [out] */ IProxySelector** defaultSelector);

    static CARAPI SetDefault(
        /* [in] */ IProxySelector* selector);

    virtual CARAPI Select(
        /* [in] */ IURI* uri,
        /* [out] */ IList** container) = 0;

    virtual CARAPI ConnectFailed(
        /* [in] */ IURI* uri,
        /* [in] */ ISocketAddress* sa,
        /* [in] */ ECode ec) = 0;

private:
    ECO_LOCAL static AutoPtr<IProxySelector> sDefaultSelector;
};

} // namespace Net
} // namespace Elastos

#endif //__ELASTOS_NET_ProxySelector_H__
