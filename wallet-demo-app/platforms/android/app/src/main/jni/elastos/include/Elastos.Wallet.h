#ifndef __CAR_ELASTOS_WALLET_H__
#define __CAR_ELASTOS_WALLET_H__

#ifndef _NO_INCLIST
#include "elastos.h"
using namespace Elastos;
#include "Elastos.CoreLibrary.h"

#endif // !_NO_INCLIST

#ifndef __UUNM_Elastos_Wallet_DEFINED__
#define __UUNM_Elastos_Wallet_DEFINED__
#define c_pElastos_WalletUunm "libElastos.Wallet.so"
#endif // __UUNM_Elastos_Wallet_DEFINED__

#ifndef __ECLSID_CMasterWalletManager_DEFINED__
#define __ECLSID_CMasterWalletManager_DEFINED__
static const _ELASTOS ClassID ECLSID_CMasterWalletManager = {
    {0xEF8E2352,0x058C,0xCF45,{0x40,0x00,0x4A,0x79,0xC3,0x82,0x20,0x3E}},
    (char *)c_pElastos_WalletUunm,
    0x95c7b3f9 };
#endif // __CLSID_CMasterWalletManager_DEFINED__

#ifndef __ECLSID_CMasterWalletManagerClassObject_DEFINED__
#define __ECLSID_CMasterWalletManagerClassObject_DEFINED__
static const _ELASTOS ClassID ECLSID_CMasterWalletManagerClassObject = {
    {0x2EFE2E51,0x058C,0xCF45,{0x40,0x00,0x4A,0x79,0xC3,0x82,0x20,0x3E}},
    (char *)c_pElastos_WalletUunm,
    0x95c7b3f9 };
#endif // __CLSID_CMasterWalletManagerClassObject_DEFINED__

#ifndef __EIID_ISubWalletListener_DEFINED__
#define __EIID_ISubWalletListener_DEFINED__
static const _ELASTOS InterfaceID EIID_ISubWalletListener = \
    {0x1B2B6710,0x8712,0x2097,{0xF9,0xBE,0xE8,0x5D,0xB1,0xF6,0x8D,0xC6}};
#endif // __IID_ISubWalletListener_DEFINED__

#ifndef __EIID_ISubWallet_DEFINED__
#define __EIID_ISubWallet_DEFINED__
static const _ELASTOS InterfaceID EIID_ISubWallet = \
    {0xAE26FD03,0x8712,0x2097,{0xF9,0xBE,0xE8,0xFD,0x43,0xE8,0xCD,0xAC}};
#endif // __IID_ISubWallet_DEFINED__

#ifndef __EIID_IMainchainSubWallet_DEFINED__
#define __EIID_IMainchainSubWallet_DEFINED__
static const _ELASTOS InterfaceID EIID_IMainchainSubWallet = \
    {0x6C3D2C42,0x8592,0xA13E,{0x24,0x72,0xC0,0x51,0x02,0x04,0xA0,0x94}};
#endif // __IID_IMainchainSubWallet_DEFINED__

#ifndef __EIID_ISidechainSubWallet_DEFINED__
#define __EIID_ISidechainSubWallet_DEFINED__
static const _ELASTOS InterfaceID EIID_ISidechainSubWallet = \
    {0xBDBE3E1F,0xC712,0xA89E,{0xB9,0x92,0x6C,0xCC,0xE1,0x25,0x48,0xBE}};
#endif // __IID_ISidechainSubWallet_DEFINED__

#ifndef __EIID_IIdChainSubWallet_DEFINED__
#define __EIID_IIdChainSubWallet_DEFINED__
static const _ELASTOS InterfaceID EIID_IIdChainSubWallet = \
    {0xA42B2548,0x9592,0x7D21,{0x38,0xE0,0x28,0x01,0x02,0x50,0xCA,0x1B}};
#endif // __IID_IIdChainSubWallet_DEFINED__

#ifndef __EIID_IMasterWallet_DEFINED__
#define __EIID_IMasterWallet_DEFINED__
static const _ELASTOS InterfaceID EIID_IMasterWallet = \
    {0x6B6E9646,0x0592,0xCF45,{0x40,0x00,0x4A,0x79,0xE3,0x47,0x15,0x2B}};
#endif // __IID_IMasterWallet_DEFINED__

#ifndef __EIID_IMasterWalletManager_DEFINED__
#define __EIID_IMasterWalletManager_DEFINED__
static const _ELASTOS InterfaceID EIID_IMasterWalletManager = \
    {0xE3E9C259,0x0592,0xCF45,{0x40,0x00,0x4A,0x79,0xC3,0x82,0x20,0x3E}};
#endif // __IID_IMasterWalletManager_DEFINED__

#ifndef __EIID_ICMasterWalletManagerClassObject_DEFINED__
#define __EIID_ICMasterWalletManagerClassObject_DEFINED__
static const _ELASTOS InterfaceID EIID_ICMasterWalletManagerClassObject = \
    {0xA7D45E4C,0x0312,0x8A0B,{0x9E,0x81,0x00,0x94,0xF2,0x86,0x05,0x41}};
#endif // __IID_ICMasterWalletManagerClassObject_DEFINED__

interface ISubWalletListener;
interface ISubWallet;
interface IMainchainSubWallet;
interface ISidechainSubWallet;
interface IIdChainSubWallet;
interface IMasterWallet;
interface IMasterWalletManager;
interface ICMasterWalletManagerClassObject;





#ifdef __ELASTOS_WALLET_USER_TYPE_H__
#include "Elastos.Wallet_user_type.h"
#endif
ELAPI _Impl_AcquireCallbackHandler(PInterface pServerObj, _ELASTOS REIID iid, PInterface *ppHandler);
ELAPI _Impl_CheckClsId(PInterface pServerObj, const _ELASTOS ClassID* pClassid, PInterface *ppServerObj);

CAR_INTERFACE("1B2B6710-8712-2097-F9BE-E85DB1F68DC6")
ISubWalletListener : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISubWalletListener*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISubWalletListener*)pObj->Probe(EIID_ISubWalletListener);
    }

    static CARAPI_(ISubWalletListener*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISubWalletListener*)pObj->Probe(EIID_ISubWalletListener);
    }

    static CARAPI_(ISubWalletListener*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI OnTransactionStatusChanged(
        /* [in] */ const _ELASTOS String& txid,
        /* [in] */ const _ELASTOS String& status,
        /* [in] */ const _ELASTOS String& desc,
        /* [in] */ _ELASTOS Int32 confirms) = 0;

    virtual CARAPI OnBlockSyncStarted() = 0;

    virtual CARAPI OnBlockHeightIncreased(
        /* [in] */ _ELASTOS Int32 currentBlockHeight,
        /* [in] */ _ELASTOS Double progress) = 0;

    virtual CARAPI OnBlockSyncStopped() = 0;

};
CAR_INTERFACE("AE26FD03-8712-2097-F9BE-E8FD43E8CDAC")
ISubWallet : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISubWallet*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISubWallet*)pObj->Probe(EIID_ISubWallet);
    }

    static CARAPI_(ISubWallet*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISubWallet*)pObj->Probe(EIID_ISubWallet);
    }

    static CARAPI_(ISubWallet*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetChainId(
        /* [out] */ _ELASTOS String * id) = 0;

    virtual CARAPI GetBalanceInfo(
        /* [out] */ _ELASTOS String * balanceInfoJson) = 0;

    virtual CARAPI GetBalance(
        /* [out] */ _ELASTOS Int64 * balance) = 0;

    virtual CARAPI CreateAddress(
        /* [out] */ _ELASTOS String * address) = 0;

    virtual CARAPI GetAllAddress(
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 count,
        /* [out] */ _ELASTOS String * addressesJson) = 0;

    virtual CARAPI GetBalanceWithAddress(
        /* [in] */ const _ELASTOS String& address,
        /* [out] */ _ELASTOS Int64 * balance) = 0;

    virtual CARAPI AddCallback(
        /* [in] */ ISubWalletListener * subCallback) = 0;

    virtual CARAPI RemoveCallback(
        /* [in] */ ISubWalletListener * subCallback) = 0;

    virtual CARAPI CreateTransaction(
        /* [in] */ const _ELASTOS String& fromAddress,
        /* [in] */ const _ELASTOS String& toAddress,
        /* [in] */ _ELASTOS Int64 amount,
        /* [in] */ const _ELASTOS String& memo,
        /* [in] */ const _ELASTOS String& remark,
        /* [out] */ _ELASTOS String * txidJson) = 0;

    virtual CARAPI CreateMultiSignAddress(
        /* [in] */ const _ELASTOS String& multiPublicKeyJson,
        /* [in] */ _ELASTOS Int32 totalSignNum,
        /* [in] */ _ELASTOS Int32 requiredSignNum,
        /* [out] */ _ELASTOS String * multiSignAddress) = 0;

    virtual CARAPI CreateMultiSignTransaction(
        /* [in] */ const _ELASTOS String& fromAddress,
        /* [in] */ const _ELASTOS String& toAddress,
        /* [in] */ _ELASTOS Int64 amount,
        /* [in] */ const _ELASTOS String& memo,
        /* [out] */ _ELASTOS String * transactionJson) = 0;

    virtual CARAPI SendRawTransaction(
        /* [in] */ const _ELASTOS String& transactionJson,
        /* [in] */ _ELASTOS Int64 fee,
        /* [in] */ const _ELASTOS String& payPassword,
        /* [out] */ _ELASTOS String * txidJson) = 0;

    virtual CARAPI GetAllTransaction(
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 count,
        /* [in] */ const _ELASTOS String& addressOrTxid,
        /* [out] */ _ELASTOS String * transactionListJson) = 0;

    virtual CARAPI Sign(
        /* [in] */ const _ELASTOS String& message,
        /* [in] */ const _ELASTOS String& payPassword,
        /* [out] */ _ELASTOS String * signature) = 0;

    virtual CARAPI CheckSign(
        /* [in] */ const _ELASTOS String& address,
        /* [in] */ const _ELASTOS String& message,
        /* [in] */ const _ELASTOS String& signature,
        /* [out] */ _ELASTOS String * resultJson) = 0;

    virtual CARAPI CalculateTransactionFee(
        /* [in] */ const _ELASTOS String& rawTransaction,
        /* [in] */ _ELASTOS Int64 feePerKb,
        /* [out] */ _ELASTOS Int64 * fee) = 0;

};
CAR_INTERFACE("6C3D2C42-8592-A13E-2472-C0510204A094")
IMainchainSubWallet : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IMainchainSubWallet*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMainchainSubWallet*)pObj->Probe(EIID_IMainchainSubWallet);
    }

    static CARAPI_(IMainchainSubWallet*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMainchainSubWallet*)pObj->Probe(EIID_IMainchainSubWallet);
    }

    static CARAPI_(IMainchainSubWallet*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateDepositTransaction(
        /* [in] */ const _ELASTOS String& fromAddress,
        /* [in] */ const _ELASTOS String& toAddress,
        /* [in] */ _ELASTOS Int64 amount,
        /* [in] */ const _ELASTOS String& sidechainAccountsJson,
        /* [in] */ const _ELASTOS String& sidechainAmountsJson,
        /* [in] */ const _ELASTOS String& sidechainIndexsJson,
        /* [in] */ const _ELASTOS String& memo,
        /* [in] */ const _ELASTOS String& remark,
        /* [out] */ _ELASTOS String * txidJson) = 0;

};
CAR_INTERFACE("BDBE3E1F-C712-A89E-B992-6CCCE12548BE")
ISidechainSubWallet : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISidechainSubWallet*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISidechainSubWallet*)pObj->Probe(EIID_ISidechainSubWallet);
    }

    static CARAPI_(ISidechainSubWallet*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISidechainSubWallet*)pObj->Probe(EIID_ISidechainSubWallet);
    }

    static CARAPI_(ISidechainSubWallet*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateWithdrawTransaction(
        /* [in] */ const _ELASTOS String& fromAddress,
        /* [in] */ const _ELASTOS String& toAddress,
        /* [in] */ _ELASTOS Int64 amount,
        /* [in] */ const _ELASTOS String& mainchainAccountsJson,
        /* [in] */ const _ELASTOS String& mainchainAmountsJson,
        /* [in] */ const _ELASTOS String& mainchainIndexsJson,
        /* [in] */ const _ELASTOS String& memo,
        /* [in] */ const _ELASTOS String& remark,
        /* [out] */ _ELASTOS String * txidJson) = 0;

    virtual CARAPI GetGenesisAddress(
        /* [out] */ _ELASTOS String * address) = 0;

};
CAR_INTERFACE("A42B2548-9592-7D21-38E0-28010250CA1B")
IIdChainSubWallet : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IIdChainSubWallet*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IIdChainSubWallet*)pObj->Probe(EIID_IIdChainSubWallet);
    }

    static CARAPI_(IIdChainSubWallet*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IIdChainSubWallet*)pObj->Probe(EIID_IIdChainSubWallet);
    }

    static CARAPI_(IIdChainSubWallet*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateIdTransaction(
        /* [in] */ const _ELASTOS String& fromAddress,
        /* [in] */ const _ELASTOS String& payloadJson,
        /* [in] */ const _ELASTOS String& programJson,
        /* [in] */ const _ELASTOS String& memo,
        /* [in] */ const _ELASTOS String& remark,
        /* [out] */ _ELASTOS String * result) = 0;

};
CAR_INTERFACE("6B6E9646-0592-CF45-4000-4A79E347152B")
IMasterWallet : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IMasterWallet*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMasterWallet*)pObj->Probe(EIID_IMasterWallet);
    }

    static CARAPI_(IMasterWallet*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMasterWallet*)pObj->Probe(EIID_IMasterWallet);
    }

    static CARAPI_(IMasterWallet*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetId(
        /* [out] */ _ELASTOS String * id) = 0;

    virtual CARAPI GetAllSubWallets(
        /* [out, callee] */ _ELASTOS ArrayOf<ISubWallet *> ** subWallets) = 0;

    virtual CARAPI CreateSubWallet(
        /* [in] */ const _ELASTOS String& chainID,
        /* [in] */ const _ELASTOS String& payPassword,
        /* [in] */ _ELASTOS Boolean singleAddress,
        /* [in] */ _ELASTOS Int64 feePerKb,
        /* [out] */ ISubWallet ** subWallet) = 0;

    virtual CARAPI RecoverSubWallet(
        /* [in] */ const _ELASTOS String& chainID,
        /* [in] */ const _ELASTOS String& payPassword,
        /* [in] */ _ELASTOS Boolean singleAddress,
        /* [in] */ _ELASTOS Int32 limitGap,
        /* [in] */ _ELASTOS Int64 feePerKb,
        /* [out] */ ISubWallet ** subWallet) = 0;

    virtual CARAPI DestroyWallet(
        /* [in] */ ISubWallet * wallet) = 0;

    virtual CARAPI GetPublicKey(
        /* [out] */ _ELASTOS String * publicKey) = 0;

    virtual CARAPI Sign(
        /* [in] */ const _ELASTOS String& message,
        /* [in] */ const _ELASTOS String& payPassword,
        /* [out] */ _ELASTOS String * result) = 0;

    virtual CARAPI CheckSign(
        /* [in] */ const _ELASTOS String& publicKey,
        /* [in] */ const _ELASTOS String& message,
        /* [in] */ const _ELASTOS String& signature,
        /* [out] */ _ELASTOS String * resultJson) = 0;

    virtual CARAPI IsAddressValid(
        /* [in] */ const _ELASTOS String& address,
        /* [out] */ _ELASTOS Boolean * valid) = 0;

    virtual CARAPI GetSupportedChains(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** supportedChains) = 0;

    virtual CARAPI ChangePassword(
        /* [in] */ const _ELASTOS String& oldPassword,
        /* [in] */ const _ELASTOS String& newPassword) = 0;

};
CAR_INTERFACE("E3E9C259-0592-CF45-4000-4A79C382203E")
IMasterWalletManager : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IMasterWalletManager*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMasterWalletManager*)pObj->Probe(EIID_IMasterWalletManager);
    }

    static CARAPI_(IMasterWalletManager*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMasterWalletManager*)pObj->Probe(EIID_IMasterWalletManager);
    }

    static CARAPI_(IMasterWalletManager*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateMasterWallet(
        /* [in] */ const _ELASTOS String& masterWalletId,
        /* [in] */ const _ELASTOS String& mnemonic,
        /* [in] */ const _ELASTOS String& phrasePassword,
        /* [in] */ const _ELASTOS String& payPassword,
        /* [in] */ const _ELASTOS String& language,
        /* [out] */ IMasterWallet ** masterWallet) = 0;

    virtual CARAPI GetAllMasterWallets(
        /* [out, callee] */ _ELASTOS ArrayOf<IMasterWallet *> ** wallets) = 0;

    virtual CARAPI DestroyWallet(
        /* [in] */ const _ELASTOS String& masterWalletId) = 0;

    virtual CARAPI ImportWalletWithKeystore(
        /* [in] */ const _ELASTOS String& masterWalletId,
        /* [in] */ const _ELASTOS String& keystoreContent,
        /* [in] */ const _ELASTOS String& backupPassword,
        /* [in] */ const _ELASTOS String& payPassword,
        /* [in] */ const _ELASTOS String& phrasePassword,
        /* [out] */ IMasterWallet ** masterWallet) = 0;

    virtual CARAPI ImportWalletWithMnemonic(
        /* [in] */ const _ELASTOS String& masterWalletId,
        /* [in] */ const _ELASTOS String& mnemonic,
        /* [in] */ const _ELASTOS String& phrasePassword,
        /* [in] */ const _ELASTOS String& payPassword,
        /* [in] */ const _ELASTOS String& language,
        /* [out] */ IMasterWallet ** masterWallet) = 0;

    virtual CARAPI ExportWalletWithKeystore(
        /* [in] */ IMasterWallet * masterWallet,
        /* [in] */ const _ELASTOS String& backupPassword,
        /* [in] */ const _ELASTOS String& payPassword,
        /* [out] */ _ELASTOS String * keystoreContent) = 0;

    virtual CARAPI ExportWalletWithMnemonic(
        /* [in] */ IMasterWallet * masterWallet,
        /* [in] */ const _ELASTOS String& payPassword,
        /* [out] */ _ELASTOS String * mnemonic) = 0;

    virtual CARAPI GenerateMnemonic(
        /* [in] */ const _ELASTOS String& language,
        /* [out] */ _ELASTOS String * mnemonic) = 0;

    virtual CARAPI SaveConfigs() = 0;

};
CAR_INTERFACE("A7D45E4C-0312-8A0B-9E81-0094F2860541")
ICMasterWalletManagerClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICMasterWalletManagerClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICMasterWalletManagerClassObject*)pObj->Probe(EIID_ICMasterWalletManagerClassObject);
    }

    static CARAPI_(ICMasterWalletManagerClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICMasterWalletManagerClassObject*)pObj->Probe(EIID_ICMasterWalletManagerClassObject);
    }

    static CARAPI_(ICMasterWalletManagerClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithRootPath(
        /* [in] */ const _ELASTOS String& rootPath,
        /* [out] */ IInterface ** newObj) = 0;

};
#ifndef _INSIDE_ELASTOS_WALLET_
class CMasterWalletManager
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& rootPath,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICMasterWalletManagerClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CMasterWalletManager, RGM_SAME_DOMAIN,
                EIID_ICMasterWalletManagerClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithRootPath(rootPath, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& rootPath,
        /* [out] */ IMasterWalletManager** __IMasterWalletManager)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(rootPath, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMasterWalletManager = (IMasterWalletManager*)__pNewObj->Probe(EIID_IMasterWalletManager);
        if (*__IMasterWalletManager) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& rootPath,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(rootPath, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& rootPath,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(rootPath, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& rootPath,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(rootPath, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
#endif // _INSIDE_ELASTOS_WALLET_


#endif // __CAR_ELASTOS_WALLET_H__
