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

#ifndef __ELASTOS_NET_SOCKET_H__
#define __ELASTOS_NET_SOCKET_H__

#include "Elastos.CoreLibrary.IO.h"
#include "Elastos.CoreLibrary.Net.h"
#include "elastos/core/Object.h"

using Elastos::Core::Object;
using Elastos::IO::ICloseable;
using Elastos::IO::IInputStream;
using Elastos::IO::IOutputStream;
using Elastos::IO::IFileDescriptor;
using Elastos::IO::Channels::ISocketChannel;

namespace Elastos {
namespace Net {

class ECO_PUBLIC Socket
    : public Object
    , public ISocket
    , public ICloseable
{
public:
    CAR_INTERFACE_DECL()

    Socket();

    CARAPI constructor();

    CARAPI constructor(
        /* [in] */ IProxy* proxy);

    CARAPI constructor(
        /* [in] */ const String& dstName,
        /* [in] */ Int32 dstPort);

    CARAPI constructor(
        /* [in] */ const String& dstName,
        /* [in] */ Int32 dstPort,
        /* [in] */ IInetAddress* localAddress,
        /* [in] */ Int32 localPort);

    CARAPI constructor(
        /* [in] */ const String& hostName,
        /* [in] */ Int32 port,
        /* [in] */ Boolean streaming);

    CARAPI constructor(
        /* [in] */ IInetAddress* dstAddress,
        /* [in] */ Int32 dstPort);

    CARAPI constructor(
        /* [in] */ IInetAddress* dstAddress,
        /* [in] */ Int32 dstPort,
        /* [in] */ IInetAddress* localAddress,
        /* [in] */ Int32 localPort);

    CARAPI constructor(
        /* [in] */ IInetAddress* addr,
        /* [in] */ Int32 port,
        /* [in] */ Boolean streaming);

    CARAPI Close();

    CARAPI OnClose();

    CARAPI GetInetAddress(
        /* [out] */ IInetAddress** address);

    CARAPI GetInputStream(
        /* [out] */ IInputStream** is);

    CARAPI GetKeepAlive(
        /* [out] */ Boolean* keepAlive);

    CARAPI GetLocalAddress(
        /* [out] */ IInetAddress** address);

    CARAPI GetLocalPort(
        /* [out] */ Int32* localPort);

    CARAPI GetOutputStream(
        /* [out] */ IOutputStream** os);

    CARAPI GetPort(
        /* [out] */ Int32* port);

    CARAPI GetSoLinger(
        /* [out] */ Int32* value);

    CARAPI GetReceiveBufferSize(
        /* [out] */ Int32* size);

    CARAPI GetSendBufferSize(
        /* [out] */ Int32* size);

    CARAPI GetSoTimeout(
        /* [out] */ Int32* timeout);

    CARAPI GetTcpNoDelay(
        /* [out] */ Boolean* noDelay);

    CARAPI SetKeepAlive(
        /* [in] */ Boolean keepAlive);

    static CARAPI SetSocketImplFactory(
        /* [in] */ ISocketImplFactory* fac);

    CARAPI SetSendBufferSize(
        /* [in] */ Int32 size);

    CARAPI SetReceiveBufferSize(
        /* [in] */ Int32 size);

    CARAPI SetSoLinger(
        /* [in] */ Boolean on,
        /* [in] */ Int32 timeout);

    CARAPI SetSoTimeout(
        /* [in] */ Int32 timeout);

    CARAPI SetTcpNoDelay(
        /* [in] */ Boolean on);

    CARAPI ToString(
        /* [out] */ String* str);

    CARAPI ShutdownInput();

    CARAPI ShutdownOutput();

    CARAPI GetLocalSocketAddress(
        /* [out] */ ISocketAddress** address);

    CARAPI GetRemoteSocketAddress(
        /* [out] */ ISocketAddress** address);

    CARAPI IsBound(
        /* [out] */ Boolean* isBound);

    CARAPI IsConnected(
        /* [out] */ Boolean* isConnected);

    CARAPI IsClosed(
        /* [out] */ Boolean* isClosed);

    CARAPI Bind(
        /* [in] */ ISocketAddress* localAddr);

    CARAPI OnBind(
        /* [in] */ IInetAddress* localAddress,
        /* [in] */ Int32 localPort);

    CARAPI Connect(
        /* [in] */ ISocketAddress* remoteAddr);

    CARAPI Connect(
        /* [in] */ ISocketAddress* remoteAddr,
        /* [in] */ Int32 timeout);

    CARAPI OnConnect(
        /* [in] */ ISocketAddress* remoteAddr,
        /* [in] */ Int32 timeout);

    CARAPI IsInputShutdown(
        /* [out] */ Boolean* isInputShutdown);

    CARAPI IsOutputShutdown(
        /* [out] */ Boolean* isOutputShutdown);

    CARAPI SetReuseAddress(
        /* [in] */ Boolean reuse);

    CARAPI GetReuseAddress(
        /* [out] */ Boolean* reuse);

    CARAPI SetOOBInline(
        /* [in] */ Boolean oobinline);

    CARAPI GetOOBInline(
        /* [out] */ Boolean* oobinline);

    CARAPI SetTrafficClass(
        /* [in] */ Int32 value);

    CARAPI GetTrafficClass(
        /* [out] */ Int32* value);

    CARAPI SendUrgentData(
        /* [in] */ Int32 value);

    CARAPI_(void) Accepted();

    CARAPI GetChannel(
        /* [out] */ ISocketChannel** channel);

    CARAPI GetFileDescriptor(
        /* [out] */ IFileDescriptor** fd);

    CARAPI SetPerformancePreferences(
        /* [in] */ Int32 connectionTime,
        /* [in] */ Int32 latency,
        /* [in] */ Int32 bandwidth);

    CARAPI_(void) SetIsCreated(
        /* [in] */ Boolean value)
    {
        mIsCreated = value;
    }

private:
    CARAPI TryAllAddresses(
        /* [in] */ const String& dstName,
        /* [in] */ Int32 dstPort,
        /* [in] */ IInetAddress* localAddress,
        /* [in] */ Int32 localPort,
        /* [in] */ Boolean streaming);

    CARAPI CheckDestination(
        /* [in] */ IInetAddress* destAddr,
        /* [in] */ Int32 dstPort);

    CARAPI StartupSocket(
        /* [in] */ IInetAddress* dstAddress,
        /* [in] */ Int32 dstPort,
        /* [in] */ IInetAddress* localAddress,
        /* [in] */ Int32 localPort,
        /* [in] */ Boolean streaming);

    CARAPI_(Boolean) UsingSocks();

    CARAPI CheckOpenAndCreate(
        /* [in] */ Boolean create);

    CARAPI_(void) CacheLocalAddress();

public:
    AutoPtr<ISocketImpl> mImpl;

private:
    static AutoPtr<ISocketImplFactory> sFactory;
    static Object sLock;

    AutoPtr<IProxy> mProxy;

    volatile Boolean mIsCreated;
    Boolean mIsBound;
    Boolean mIsConnected;
    Boolean mIsClosed;
    Boolean mIsInputShutdown;
    Boolean mIsOutputShutdown;

    AutoPtr<IInetAddress> mLocalAddress;
    Object mConnectLock;
};

} // namespace Net
} // namespace Elastos

#endif //__ELASTOS_NET_SOCKET_H__
