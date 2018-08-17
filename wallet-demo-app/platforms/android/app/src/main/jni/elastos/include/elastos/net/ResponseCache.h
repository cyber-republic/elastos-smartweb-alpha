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

#ifndef __ELASTOS_NET_RESPONSECACHE_H__
#define __ELASTOS_NET_RESPONSECACHE_H__

#include "Elastos.CoreLibrary.Net.h"
#include "elastos/core/Object.h"

using Elastos::Core::Object;
using Elastos::Utility::IMap;

namespace Elastos {
namespace Net {

class ECO_PUBLIC ResponseCache
    : public Object
    , public IResponseCache
{
public:
    CAR_INTERFACE_DECL()

    ResponseCache();

    virtual ~ResponseCache();

    /**
     * Returns the system's default response cache, or null.
     */
    static CARAPI GetDefault(
        /* [out] */ IResponseCache** responseCache);

    /**
     * Sets the system's default response cache. Use null to remove the response cache.
     */
    static CARAPI SetDefault(
        /* [in] */ IResponseCache* responseCache);

    virtual CARAPI Get(
        /* [in] */ IURI* uri,
        /* [in] */ const String& requestMethod,
        /* [in] */ IMap* requestHeaders,
        /* [out] */ ICacheResponse** cache) = 0;

    virtual CARAPI Put(
        /* [in] */ IURI* uri,
        /* [in] */ IURLConnection* conn,
        /* [out] */ ICacheRequest** cache) = 0;

private:
    ECO_LOCAL static AutoPtr<IResponseCache> sDefaultResponseCache;
};

} // namespace Net
} // namespace Elastos

#endif //__ELASTOS_NET_RESPONSECACHE_H__
