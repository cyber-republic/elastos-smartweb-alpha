#ifndef __Elastos_CoreLibrary_Utility_h__
#define __Elastos_CoreLibrary_Utility_h__

#include "Elastos.CoreLibrary.h"

ELAPI _Impl_AcquireCallbackHandler(PInterface pServerObj, _ELASTOS REIID iid, PInterface *ppHandler);
ELAPI _Impl_CheckClsId(PInterface pServerObj, const _ELASTOS ClassID* pClassid, PInterface *ppServerObj);

namespace Elastos {
namespace Utility {
CAR_INTERFACE("939BD644-82D2-6A8C-7E38-2829C3C60F0F")
IBitSet : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IBitSet*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBitSet*)pObj->Probe(EIID_IBitSet);
    }

    static CARAPI_(IBitSet*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBitSet*)pObj->Probe(EIID_IBitSet);
    }

    static CARAPI_(IBitSet*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI Get(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI Get(
        /* [in] */ _ELASTOS Int32 fromIndex,
        /* [in] */ _ELASTOS Int32 toIndex,
        /* [out] */ Elastos::Utility::IBitSet ** bs) = 0;

    virtual CARAPI Set(
        /* [in] */ _ELASTOS Int32 index) = 0;

    virtual CARAPI Set(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Boolean state) = 0;

    virtual CARAPI Set(
        /* [in] */ _ELASTOS Int32 fromIndex,
        /* [in] */ _ELASTOS Int32 toIndex) = 0;

    virtual CARAPI Set(
        /* [in] */ _ELASTOS Int32 fromIndex,
        /* [in] */ _ELASTOS Int32 toIndex,
        /* [in] */ _ELASTOS Boolean state) = 0;

    virtual CARAPI Clear(
        /* [in] */ _ELASTOS Int32 index) = 0;

    virtual CARAPI Clear(
        /* [in] */ _ELASTOS Int32 fromIndex,
        /* [in] */ _ELASTOS Int32 toIndex) = 0;

    virtual CARAPI Clear() = 0;

    virtual CARAPI Flip(
        /* [in] */ _ELASTOS Int32 index) = 0;

    virtual CARAPI Flip(
        /* [in] */ _ELASTOS Int32 fromIndex,
        /* [in] */ _ELASTOS Int32 toIndex) = 0;

    virtual CARAPI Intersects(
        /* [in] */ Elastos::Utility::IBitSet * bs,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI And(
        /* [in] */ Elastos::Utility::IBitSet * bs) = 0;

    virtual CARAPI AndNot(
        /* [in] */ Elastos::Utility::IBitSet * bs) = 0;

    virtual CARAPI Or(
        /* [in] */ Elastos::Utility::IBitSet * bs) = 0;

    virtual CARAPI Xor(
        /* [in] */ Elastos::Utility::IBitSet * bs) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI GetLength(
        /* [out] */ _ELASTOS Int32 * len) = 0;

    virtual CARAPI NextSetBit(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Int32 * next) = 0;

    virtual CARAPI NextClearBit(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Int32 * next) = 0;

    virtual CARAPI PreviousSetBit(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Int32 * previous) = 0;

    virtual CARAPI PreviousClearBit(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Int32 * previous) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Cardinality(
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI ToArray(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Int64> ** int64Arr) = 0;

    virtual CARAPI ToArray(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** byteArr) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * obj,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * value) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("E3582C0C-C2D2-1CDE-7A47-E83BA3F5EFBC")
IBitSetHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IBitSetHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBitSetHelper*)pObj->Probe(EIID_IBitSetHelper);
    }

    static CARAPI_(IBitSetHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBitSetHelper*)pObj->Probe(EIID_IBitSetHelper);
    }

    static CARAPI_(IBitSetHelper*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI ValueOf(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int64> * int64Arr,
        /* [out] */ Elastos::Utility::IBitSet ** bs) = 0;

    virtual CARAPI ValueOf(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * byteArr,
        /* [out] */ Elastos::Utility::IBitSet ** bs) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("AE45CF41-8352-3F46-1C94-9461E38787CF")
IDate : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDate*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDate*)pObj->Probe(EIID_IDate);
    }

    static CARAPI_(IDate*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDate*)pObj->Probe(EIID_IDate);
    }

    static CARAPI_(IDate*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI IsAfter(
        /* [in] */ Elastos::Utility::IDate * date,
        /* [out] */ _ELASTOS Boolean * isAfter) = 0;

    virtual CARAPI IsBefore(
        /* [in] */ Elastos::Utility::IDate * date,
        /* [out] */ _ELASTOS Boolean * isBefore) = 0;

    virtual CARAPI GetDate(
        /* [out] */ _ELASTOS Int32 * date) = 0;

    virtual CARAPI GetDay(
        /* [out] */ _ELASTOS Int32 * day) = 0;

    virtual CARAPI GetHours(
        /* [out] */ _ELASTOS Int32 * hours) = 0;

    virtual CARAPI GetMinutes(
        /* [out] */ _ELASTOS Int32 * minutes) = 0;

    virtual CARAPI GetMonth(
        /* [out] */ _ELASTOS Int32 * month) = 0;

    virtual CARAPI GetSeconds(
        /* [out] */ _ELASTOS Int32 * seconds) = 0;

    virtual CARAPI GetTime(
        /* [out] */ _ELASTOS Int64 * time) = 0;

    virtual CARAPI GetTimezoneOffset(
        /* [out] */ _ELASTOS Int32 * timezoneOffset) = 0;

    virtual CARAPI GetYear(
        /* [out] */ _ELASTOS Int32 * year) = 0;

    virtual CARAPI SetDate(
        /* [in] */ _ELASTOS Int32 day) = 0;

    virtual CARAPI SetHours(
        /* [in] */ _ELASTOS Int32 hour) = 0;

    virtual CARAPI SetMinutes(
        /* [in] */ _ELASTOS Int32 minute) = 0;

    virtual CARAPI SetMonth(
        /* [in] */ _ELASTOS Int32 month) = 0;

    virtual CARAPI SetSeconds(
        /* [in] */ _ELASTOS Int32 second) = 0;

    virtual CARAPI SetTime(
        /* [in] */ _ELASTOS Int64 milliseconds) = 0;

    virtual CARAPI SetYear(
        /* [in] */ _ELASTOS Int32 year) = 0;

    virtual CARAPI ToGMTString(
        /* [out] */ _ELASTOS String * gmtStr) = 0;

    virtual CARAPI ToLocaleString(
        /* [out] */ _ELASTOS String * localeStr) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * localeStr) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("8DFB2436-A652-2808-5ECC-B8FFA3BD8D1B")
IDateHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDateHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDateHelper*)pObj->Probe(EIID_IDateHelper);
    }

    static CARAPI_(IDateHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDateHelper*)pObj->Probe(EIID_IDateHelper);
    }

    static CARAPI_(IDateHelper*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI Parse(
        /* [in] */ const _ELASTOS String& string,
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI UTC(
        /* [in] */ _ELASTOS Int32 year,
        /* [in] */ _ELASTOS Int32 month,
        /* [in] */ _ELASTOS Int32 day,
        /* [in] */ _ELASTOS Int32 hour,
        /* [in] */ _ELASTOS Int32 minute,
        /* [in] */ _ELASTOS Int32 second,
        /* [out] */ _ELASTOS Int64 * value) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("FAC0254C-8492-7ACC-7E38-2829C3C60F0F")
IIterable : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IIterable*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IIterable*)pObj->Probe(EIID_IIterable);
    }

    static CARAPI_(IIterable*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IIterable*)pObj->Probe(EIID_IIterable);
    }

    static CARAPI_(IIterable*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetIterator(
        /* [out] */ Elastos::Utility::IIterator ** it) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("1D3BAE54-1152-AF97-26FE-705052868D1F")
ICollection : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICollection*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICollection*)pObj->Probe(EIID_ICollection);
    }

    static CARAPI_(ICollection*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICollection*)pObj->Probe(EIID_ICollection);
    }

    static CARAPI_(ICollection*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetIterator(
        /* [out] */ Elastos::Utility::IIterator ** it) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI Clear() = 0;

    virtual CARAPI Contains(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ContainsAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI ToArray(
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** array) = 0;

    virtual CARAPI ToArray(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * inArray,
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** outArray) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("04E5FF5E-0552-3F8B-1C94-9461E38787CF")
IList : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IList*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IList*)pObj->Probe(EIID_IList);
    }

    static CARAPI_(IList*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IList*)pObj->Probe(EIID_IList);
    }

    static CARAPI_(IList*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI Add(
        /* [in] */ _ELASTOS Int32 location,
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI AddAll(
        /* [in] */ _ELASTOS Int32 location,
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI AddAll(
        /* [in] */ _ELASTOS Int32 location,
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI Get(
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ IInterface ** object) = 0;

    virtual CARAPI IndexOf(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI LastIndexOf(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI GetListIterator(
        /* [out] */ Elastos::Utility::IListIterator ** it) = 0;

    virtual CARAPI GetListIterator(
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ Elastos::Utility::IListIterator ** it) = 0;

    virtual CARAPI Remove(
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ IInterface ** object) = 0;

    virtual CARAPI Remove(
        /* [in] */ _ELASTOS Int32 location) = 0;

    virtual CARAPI Set(
        /* [in] */ _ELASTOS Int32 location,
        /* [in] */ IInterface * object,
        /* [out] */ IInterface ** prevObject) = 0;

    virtual CARAPI Set(
        /* [in] */ _ELASTOS Int32 location,
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI GetSubList(
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ Elastos::Utility::IList ** subList) = 0;

    virtual CARAPI GetIterator(
        /* [out] */ Elastos::Utility::IIterator ** it) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI Clear() = 0;

    virtual CARAPI Contains(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ContainsAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI ToArray(
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** array) = 0;

    virtual CARAPI ToArray(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * inArray,
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** outArray) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("E550FB30-C752-ED1F-6DDC-9061E387871B")
ILocale : public IInterface
{
    static const _ELASTOS Char32 PRIVATE_USE_EXTENSION = 'x';
    static const _ELASTOS Char32 UNICODE_LOCALE_EXTENSION = 'u';
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ILocale*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILocale*)pObj->Probe(EIID_ILocale);
    }

    static CARAPI_(ILocale*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILocale*)pObj->Probe(EIID_ILocale);
    }

    static CARAPI_(ILocale*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetCountry(
        /* [out] */ _ELASTOS String * country) = 0;

    virtual CARAPI GetDisplayCountry(
        /* [out] */ _ELASTOS String * country) = 0;

    virtual CARAPI GetDisplayCountry(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ _ELASTOS String * country) = 0;

    virtual CARAPI GetDisplayLanguage(
        /* [out] */ _ELASTOS String * language) = 0;

    virtual CARAPI GetDisplayLanguage(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ _ELASTOS String * language) = 0;

    virtual CARAPI GetDisplayName(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI GetDisplayName(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI GetDisplayVariant(
        /* [out] */ _ELASTOS String * displayVariant) = 0;

    virtual CARAPI GetScript(
        /* [out] */ _ELASTOS String * script) = 0;

    virtual CARAPI GetDisplayScript(
        /* [out] */ _ELASTOS String * script) = 0;

    virtual CARAPI GetDisplayScript(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ _ELASTOS String * script) = 0;

    virtual CARAPI ToLanguageTag(
        /* [out] */ _ELASTOS String * tag) = 0;

    virtual CARAPI GetExtensionKeys(
        /* [out] */ Elastos::Utility::ISet ** keys) = 0;

    virtual CARAPI GetExtension(
        /* [in] */ _ELASTOS Char32 extensionKey,
        /* [out] */ _ELASTOS String * extension) = 0;

    virtual CARAPI GetUnicodeLocaleType(
        /* [in] */ const _ELASTOS String& keyWord,
        /* [out] */ _ELASTOS String * type) = 0;

    virtual CARAPI GetUnicodeLocaleAttributes(
        /* [out] */ Elastos::Utility::ISet ** keys) = 0;

    virtual CARAPI GetUnicodeLocaleKeys(
        /* [out] */ Elastos::Utility::ISet ** keys) = 0;

    virtual CARAPI GetDisplayVariant(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ _ELASTOS String * displayVariant) = 0;

    virtual CARAPI GetISO3Country(
        /* [out] */ _ELASTOS String * country) = 0;

    virtual CARAPI GetISO3Language(
        /* [out] */ _ELASTOS String * language) = 0;

    virtual CARAPI GetLanguage(
        /* [out] */ _ELASTOS String * language) = 0;

    virtual CARAPI GetVariant(
        /* [out] */ _ELASTOS String * variant) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * o,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI Clone(
        /* [out] */ IInterface ** obj) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * value) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("E5E9C82D-9B12-3FFB-DADB-B821C3C60F0F")
IBuilder : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IBuilder*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBuilder*)pObj->Probe(EIID_IBuilder);
    }

    static CARAPI_(IBuilder*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBuilder*)pObj->Probe(EIID_IBuilder);
    }

    static CARAPI_(IBuilder*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI SetLanguage(
        /* [in] */ const _ELASTOS String& language) = 0;

    virtual CARAPI SetLanguageTag(
        /* [in] */ const _ELASTOS String& languageTag) = 0;

    virtual CARAPI SetRegion(
        /* [in] */ const _ELASTOS String& region) = 0;

    virtual CARAPI SetVariant(
        /* [in] */ const _ELASTOS String& variant) = 0;

    virtual CARAPI SetScript(
        /* [in] */ const _ELASTOS String& script) = 0;

    virtual CARAPI SetLocale(
        /* [in] */ Elastos::Utility::ILocale * locale) = 0;

    virtual CARAPI AddUnicodeLocaleAttribute(
        /* [in] */ const _ELASTOS String& attribute) = 0;

    virtual CARAPI RemoveUnicodeLocaleAttribute(
        /* [in] */ const _ELASTOS String& attribute) = 0;

    virtual CARAPI SetExtension(
        /* [in] */ _ELASTOS Char32 key,
        /* [in] */ const _ELASTOS String& value) = 0;

    virtual CARAPI ClearExtensions() = 0;

    virtual CARAPI SetUnicodeLocaleKeyword(
        /* [in] */ const _ELASTOS String& key,
        /* [in] */ const _ELASTOS String& type) = 0;

    virtual CARAPI Clear() = 0;

    virtual CARAPI Build(
        /* [out] */ Elastos::Utility::ILocale ** locale) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("7DA4F937-C752-2808-5ECC-B8FFA3BD8D1B")
ILocaleHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ILocaleHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILocaleHelper*)pObj->Probe(EIID_ILocaleHelper);
    }

    static CARAPI_(ILocaleHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILocaleHelper*)pObj->Probe(EIID_ILocaleHelper);
    }

    static CARAPI_(ILocaleHelper*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI ForLanguageTag(
        /* [in] */ const _ELASTOS String& languageTag,
        /* [out] */ Elastos::Utility::ILocale ** locale) = 0;

    virtual CARAPI GetAvailableLocales(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Utility::ILocale *> ** locales) = 0;

    virtual CARAPI GetDefault(
        /* [out] */ Elastos::Utility::ILocale ** defaultLocale) = 0;

    virtual CARAPI GetLocale(
        /* [in] */ const _ELASTOS String& localeName,
        /* [out] */ Elastos::Utility::ILocale ** locale) = 0;

    virtual CARAPI GetISOCountries(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** codes) = 0;

    virtual CARAPI GetISOLanguages(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** codes) = 0;

    virtual CARAPI SetDefault(
        /* [in] */ Elastos::Utility::ILocale * locale) = 0;

    virtual CARAPI GetCANADA(
        /* [out] */ Elastos::Utility::ILocale ** locale) = 0;

    virtual CARAPI GetCANADA_FRENCH(
        /* [out] */ Elastos::Utility::ILocale ** locale) = 0;

    virtual CARAPI GetCHINA(
        /* [out] */ Elastos::Utility::ILocale ** locale) = 0;

    virtual CARAPI GetCHINESE(
        /* [out] */ Elastos::Utility::ILocale ** locale) = 0;

    virtual CARAPI GetENGLISH(
        /* [out] */ Elastos::Utility::ILocale ** locale) = 0;

    virtual CARAPI GetFRANCE(
        /* [out] */ Elastos::Utility::ILocale ** locale) = 0;

    virtual CARAPI GetFRENCH(
        /* [out] */ Elastos::Utility::ILocale ** locale) = 0;

    virtual CARAPI GetGERMAN(
        /* [out] */ Elastos::Utility::ILocale ** locale) = 0;

    virtual CARAPI GetGERMANY(
        /* [out] */ Elastos::Utility::ILocale ** locale) = 0;

    virtual CARAPI GetITALIAN(
        /* [out] */ Elastos::Utility::ILocale ** locale) = 0;

    virtual CARAPI GetITALY(
        /* [out] */ Elastos::Utility::ILocale ** locale) = 0;

    virtual CARAPI GetJAPAN(
        /* [out] */ Elastos::Utility::ILocale ** locale) = 0;

    virtual CARAPI GetJAPANESE(
        /* [out] */ Elastos::Utility::ILocale ** locale) = 0;

    virtual CARAPI GetKOREA(
        /* [out] */ Elastos::Utility::ILocale ** locale) = 0;

    virtual CARAPI GetKOREAN(
        /* [out] */ Elastos::Utility::ILocale ** locale) = 0;

    virtual CARAPI GetPRC(
        /* [out] */ Elastos::Utility::ILocale ** locale) = 0;

    virtual CARAPI GetROOT(
        /* [out] */ Elastos::Utility::ILocale ** locale) = 0;

    virtual CARAPI GetSIMPLIFIED_CHINESE(
        /* [out] */ Elastos::Utility::ILocale ** locale) = 0;

    virtual CARAPI GetTAIWAN(
        /* [out] */ Elastos::Utility::ILocale ** locale) = 0;

    virtual CARAPI GetTRADITIONAL_CHINESE(
        /* [out] */ Elastos::Utility::ILocale ** locale) = 0;

    virtual CARAPI GetUK(
        /* [out] */ Elastos::Utility::ILocale ** locale) = 0;

    virtual CARAPI GetUS(
        /* [out] */ Elastos::Utility::ILocale ** locale) = 0;

    virtual CARAPI AdjustLanguageCode(
        /* [in] */ const _ELASTOS String& languageCode,
        /* [out] */ _ELASTOS String * result) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("C9B3CE3F-4752-F736-7FB4-B77143868D1F")
ILocaleBuilder : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ILocaleBuilder*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILocaleBuilder*)pObj->Probe(EIID_ILocaleBuilder);
    }

    static CARAPI_(ILocaleBuilder*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILocaleBuilder*)pObj->Probe(EIID_ILocaleBuilder);
    }

    static CARAPI_(ILocaleBuilder*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI SetLanguage(
        /* [in] */ const _ELASTOS String& language) = 0;

    virtual CARAPI SetLanguageTag(
        /* [in] */ const _ELASTOS String& tag) = 0;

    virtual CARAPI SetRegion(
        /* [in] */ const _ELASTOS String& region) = 0;

    virtual CARAPI SetVariant(
        /* [in] */ const _ELASTOS String& variant) = 0;

    virtual CARAPI SetScript(
        /* [in] */ const _ELASTOS String& script) = 0;

    virtual CARAPI SetLocale(
        /* [in] */ Elastos::Utility::ILocale * locale) = 0;

    virtual CARAPI AddUnicodeLocaleAttribute(
        /* [in] */ const _ELASTOS String& attribute) = 0;

    virtual CARAPI RemoveUnicodeLocaleAttribute(
        /* [in] */ const _ELASTOS String& attribute) = 0;

    virtual CARAPI SetExtension(
        /* [in] */ _ELASTOS Char32 key,
        /* [in] */ const _ELASTOS String& value) = 0;

    virtual CARAPI ClearExtensions() = 0;

    virtual CARAPI SetUnicodeLocaleKeyword(
        /* [in] */ const _ELASTOS String& key,
        /* [in] */ const _ELASTOS String& type) = 0;

    virtual CARAPI Clear() = 0;

    virtual CARAPI Build(
        /* [out] */ Elastos::Utility::ILocale ** locale) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("6594412B-4B52-3F62-DADB-B821C3C60F0F")
IMapEntry : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IMapEntry*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMapEntry*)pObj->Probe(EIID_IMapEntry);
    }

    static CARAPI_(IMapEntry*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMapEntry*)pObj->Probe(EIID_IMapEntry);
    }

    static CARAPI_(IMapEntry*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI Equals(
        /* [in] */ IInterface * entry,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetKey(
        /* [out] */ IInterface ** key) = 0;

    virtual CARAPI GetValue(
        /* [out] */ IInterface ** value) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI SetValue(
        /* [in] */ IInterface * valueReplacer,
        /* [out] */ IInterface ** valueReplacee) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("12388912-4592-BFCE-F392-F62DDBBF77B3")
IMap : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IMap*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMap*)pObj->Probe(EIID_IMap);
    }

    static CARAPI_(IMap*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMap*)pObj->Probe(EIID_IMap);
    }

    static CARAPI_(IMap*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI Clear() = 0;

    virtual CARAPI ContainsKey(
        /* [in] */ IInterface * key,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ContainsValue(
        /* [in] */ IInterface * value,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetEntrySet(
        /* [out] */ Elastos::Utility::ISet ** entries) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Get(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** value) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetKeySet(
        /* [out] */ Elastos::Utility::ISet ** keySet) = 0;

    virtual CARAPI Put(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * value,
        /* [out] */ IInterface ** oldValue) = 0;

    virtual CARAPI Put(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI PutAll(
        /* [in] */ Elastos::Utility::IMap * map) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** value) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * key) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI GetValues(
        /* [out] */ Elastos::Utility::ICollection ** value) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("566E8D36-BA12-3F96-DADB-B821C3C60F0F")
IHashMap : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IHashMap*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IHashMap*)pObj->Probe(EIID_IHashMap);
    }

    static CARAPI_(IHashMap*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IHashMap*)pObj->Probe(EIID_IHashMap);
    }

    static CARAPI_(IHashMap*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI Clear() = 0;

    virtual CARAPI ContainsKey(
        /* [in] */ IInterface * key,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ContainsValue(
        /* [in] */ IInterface * value,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetEntrySet(
        /* [out] */ Elastos::Utility::ISet ** entries) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Get(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** value) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetKeySet(
        /* [out] */ Elastos::Utility::ISet ** keySet) = 0;

    virtual CARAPI Put(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * value,
        /* [out] */ IInterface ** oldValue) = 0;

    virtual CARAPI Put(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI PutAll(
        /* [in] */ Elastos::Utility::IMap * map) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** value) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * key) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI GetValues(
        /* [out] */ Elastos::Utility::ICollection ** value) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("9F16AB21-3A12-3FCD-DADB-B821C3C60F0F")
IHashSet : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IHashSet*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IHashSet*)pObj->Probe(EIID_IHashSet);
    }

    static CARAPI_(IHashSet*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IHashSet*)pObj->Probe(EIID_IHashSet);
    }

    static CARAPI_(IHashSet*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetIterator(
        /* [out] */ Elastos::Utility::IIterator ** it) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI Clear() = 0;

    virtual CARAPI Contains(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ContainsAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI ToArray(
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** array) = 0;

    virtual CARAPI ToArray(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * inArray,
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** outArray) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("79CF3A27-B192-24FB-E0FF-686FE3860C1B")
IEnumeration : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IEnumeration*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IEnumeration*)pObj->Probe(EIID_IEnumeration);
    }

    static CARAPI_(IEnumeration*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IEnumeration*)pObj->Probe(EIID_IEnumeration);
    }

    static CARAPI_(IEnumeration*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI HasMoreElements(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetNextElement(
        /* [out] */ IInterface ** inter) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("F4E4A13E-BA12-3FDE-DADB-B821C3C60F0F")
IHashTable : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IHashTable*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IHashTable*)pObj->Probe(EIID_IHashTable);
    }

    static CARAPI_(IHashTable*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IHashTable*)pObj->Probe(EIID_IHashTable);
    }

    static CARAPI_(IHashTable*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetElements(
        /* [out] */ Elastos::Utility::IEnumeration ** enm) = 0;

    virtual CARAPI Get(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI GetKeys(
        /* [out] */ Elastos::Utility::IEnumeration ** enm) = 0;

    virtual CARAPI Put(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * value,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI Put(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * key) = 0;

    virtual CARAPI Clear() = 0;

    virtual CARAPI ContainsKey(
        /* [in] */ IInterface * key,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ContainsValue(
        /* [in] */ IInterface * value,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetEntrySet(
        /* [out] */ Elastos::Utility::ISet ** entries) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetKeySet(
        /* [out] */ Elastos::Utility::ISet ** keySet) = 0;

    virtual CARAPI PutAll(
        /* [in] */ Elastos::Utility::IMap * map) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI GetValues(
        /* [out] */ Elastos::Utility::ICollection ** value) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("BEB8953D-3C52-3114-6EB0-B8C1035DCB1F")
IIdentityHashMap : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IIdentityHashMap*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IIdentityHashMap*)pObj->Probe(EIID_IIdentityHashMap);
    }

    static CARAPI_(IIdentityHashMap*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IIdentityHashMap*)pObj->Probe(EIID_IIdentityHashMap);
    }

    static CARAPI_(IIdentityHashMap*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI Clear() = 0;

    virtual CARAPI ContainsKey(
        /* [in] */ IInterface * key,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ContainsValue(
        /* [in] */ IInterface * value,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetEntrySet(
        /* [out] */ Elastos::Utility::ISet ** entries) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Get(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** value) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetKeySet(
        /* [out] */ Elastos::Utility::ISet ** keySet) = 0;

    virtual CARAPI Put(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * value,
        /* [out] */ IInterface ** oldValue) = 0;

    virtual CARAPI Put(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI PutAll(
        /* [in] */ Elastos::Utility::IMap * map) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** value) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * key) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI GetValues(
        /* [out] */ Elastos::Utility::ICollection ** value) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("D6109C31-4612-E8FD-5AFE-686FE3860C1B")
ILinkedHashMap : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ILinkedHashMap*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILinkedHashMap*)pObj->Probe(EIID_ILinkedHashMap);
    }

    static CARAPI_(ILinkedHashMap*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILinkedHashMap*)pObj->Probe(EIID_ILinkedHashMap);
    }

    static CARAPI_(ILinkedHashMap*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetEldest(
        /* [out] */ Elastos::Utility::IMapEntry ** outent) = 0;

    virtual CARAPI Clear() = 0;

    virtual CARAPI ContainsKey(
        /* [in] */ IInterface * key,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ContainsValue(
        /* [in] */ IInterface * value,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetEntrySet(
        /* [out] */ Elastos::Utility::ISet ** entries) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Get(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** value) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetKeySet(
        /* [out] */ Elastos::Utility::ISet ** keySet) = 0;

    virtual CARAPI Put(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * value,
        /* [out] */ IInterface ** oldValue) = 0;

    virtual CARAPI Put(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI PutAll(
        /* [in] */ Elastos::Utility::IMap * map) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** value) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * key) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI GetValues(
        /* [out] */ Elastos::Utility::ICollection ** value) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("7EDDB133-4612-E8FD-34FF-686FE3860C1B")
ILinkedHashSet : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ILinkedHashSet*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILinkedHashSet*)pObj->Probe(EIID_ILinkedHashSet);
    }

    static CARAPI_(ILinkedHashSet*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILinkedHashSet*)pObj->Probe(EIID_ILinkedHashSet);
    }

    static CARAPI_(ILinkedHashSet*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetIterator(
        /* [out] */ Elastos::Utility::IIterator ** it) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI Clear() = 0;

    virtual CARAPI Contains(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ContainsAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI ToArray(
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** array) = 0;

    virtual CARAPI ToArray(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * inArray,
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** outArray) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("096EFE38-4612-1AFD-7FB4-B77143868D1F")
ILinkedList : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ILinkedList*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILinkedList*)pObj->Probe(EIID_ILinkedList);
    }

    static CARAPI_(ILinkedList*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILinkedList*)pObj->Probe(EIID_ILinkedList);
    }

    static CARAPI_(ILinkedList*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI AddFirst(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI AddLast(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI GetDescendingIterator(
        /* [out] */ Elastos::Utility::IIterator ** iterator) = 0;

    virtual CARAPI GetElement(
        /* [out] */ IInterface ** object) = 0;

    virtual CARAPI GetFirst(
        /* [out] */ IInterface ** object) = 0;

    virtual CARAPI GetLast(
        /* [out] */ IInterface ** object) = 0;

    virtual CARAPI Offer(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI OfferFirst(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI OfferLast(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Peek(
        /* [out] */ IInterface ** object) = 0;

    virtual CARAPI PeekFirst(
        /* [out] */ IInterface ** object) = 0;

    virtual CARAPI PeekLast(
        /* [out] */ IInterface ** object) = 0;

    virtual CARAPI Poll(
        /* [out] */ IInterface ** object) = 0;

    virtual CARAPI PollFirst(
        /* [out] */ IInterface ** object) = 0;

    virtual CARAPI PollLast(
        /* [out] */ IInterface ** object) = 0;

    virtual CARAPI Pop(
        /* [out] */ IInterface ** object) = 0;

    virtual CARAPI Push(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI Remove(
        /* [out] */ IInterface ** object) = 0;

    virtual CARAPI RemoveFirst(
        /* [out] */ IInterface ** object) = 0;

    virtual CARAPI RemoveFirstOccurrence(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI RemoveLast(
        /* [out] */ IInterface ** object) = 0;

    virtual CARAPI RemoveLastOccurrence(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Add(
        /* [in] */ _ELASTOS Int32 location,
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI AddAll(
        /* [in] */ _ELASTOS Int32 location,
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI AddAll(
        /* [in] */ _ELASTOS Int32 location,
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI Get(
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ IInterface ** object) = 0;

    virtual CARAPI IndexOf(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI LastIndexOf(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI GetListIterator(
        /* [out] */ Elastos::Utility::IListIterator ** it) = 0;

    virtual CARAPI GetListIterator(
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ Elastos::Utility::IListIterator ** it) = 0;

    virtual CARAPI Remove(
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ IInterface ** object) = 0;

    virtual CARAPI Remove(
        /* [in] */ _ELASTOS Int32 location) = 0;

    virtual CARAPI Set(
        /* [in] */ _ELASTOS Int32 location,
        /* [in] */ IInterface * object,
        /* [out] */ IInterface ** prevObject) = 0;

    virtual CARAPI Set(
        /* [in] */ _ELASTOS Int32 location,
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI GetSubList(
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ Elastos::Utility::IList ** subList) = 0;

    virtual CARAPI GetIterator(
        /* [out] */ Elastos::Utility::IIterator ** it) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI Clear() = 0;

    virtual CARAPI Contains(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ContainsAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI ToArray(
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** array) = 0;

    virtual CARAPI ToArray(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * inArray,
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** outArray) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("06135141-9292-1357-11FD-705052868D1F")
IDictionary : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDictionary*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDictionary*)pObj->Probe(EIID_IDictionary);
    }

    static CARAPI_(IDictionary*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDictionary*)pObj->Probe(EIID_IDictionary);
    }

    static CARAPI_(IDictionary*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetElements(
        /* [out] */ Elastos::Utility::IEnumeration ** enm) = 0;

    virtual CARAPI Get(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetKeys(
        /* [out] */ Elastos::Utility::IEnumeration ** enm) = 0;

    virtual CARAPI Put(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * value,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI Put(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * key) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * value) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("3071515F-0412-F1BC-F40A-62F02746AC1A")
IGregorianCalendar : public IInterface
{
    static const _ELASTOS Int32 BC = 0;
    static const _ELASTOS Int32 AD = 1;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IGregorianCalendar*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IGregorianCalendar*)pObj->Probe(EIID_IGregorianCalendar);
    }

    static CARAPI_(IGregorianCalendar*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IGregorianCalendar*)pObj->Probe(EIID_IGregorianCalendar);
    }

    static CARAPI_(IGregorianCalendar*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI IsLeapYear(
        /* [in] */ _ELASTOS Int32 year,
        /* [out] */ _ELASTOS Boolean * isLeap) = 0;

    virtual CARAPI SetGregorianChange(
        /* [in] */ Elastos::Utility::IDate * date) = 0;

    virtual CARAPI GetGregorianChange(
        /* [out] */ Elastos::Utility::IDate ** date) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("56C12E4E-8492-8FCC-AEFE-705052868D1F")
IIterator : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IIterator*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IIterator*)pObj->Probe(EIID_IIterator);
    }

    static CARAPI_(IIterator*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IIterator*)pObj->Probe(EIID_IIterator);
    }

    static CARAPI_(IIterator*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI HasNext(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetNext(
        /* [out] */ IInterface ** object) = 0;

    virtual CARAPI Remove() = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("33C9564B-0552-128B-323F-BAFAC3414919")
IListIterator : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IListIterator*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IListIterator*)pObj->Probe(EIID_IListIterator);
    }

    static CARAPI_(IListIterator*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IListIterator*)pObj->Probe(EIID_IListIterator);
    }

    static CARAPI_(IListIterator*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI Add(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI HasPrevious(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetNextIndex(
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI GetPrevious(
        /* [out] */ IInterface ** object) = 0;

    virtual CARAPI GetPreviousIndex(
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI Set(
        /* [in] */ IInterface * object) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("3927C01D-8692-38A3-FA3B-2F69DFB2FD7B")
IQueue : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IQueue*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IQueue*)pObj->Probe(EIID_IQueue);
    }

    static CARAPI_(IQueue*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IQueue*)pObj->Probe(EIID_IQueue);
    }

    static CARAPI_(IQueue*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI Offer(
        /* [in] */ IInterface * e,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Remove(
        /* [out] */ IInterface ** e) = 0;

    virtual CARAPI Poll(
        /* [out] */ IInterface ** e) = 0;

    virtual CARAPI GetElement(
        /* [out] */ IInterface ** e) = 0;

    virtual CARAPI Peek(
        /* [out] */ IInterface ** e) = 0;

    virtual CARAPI GetIterator(
        /* [out] */ Elastos::Utility::IIterator ** it) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI Clear() = 0;

    virtual CARAPI Contains(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ContainsAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI ToArray(
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** array) = 0;

    virtual CARAPI ToArray(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * inArray,
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** outArray) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("7CB8FE4B-91D2-3FB9-1C94-9461E38787CF")
IDeque : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDeque*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDeque*)pObj->Probe(EIID_IDeque);
    }

    static CARAPI_(IDeque*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDeque*)pObj->Probe(EIID_IDeque);
    }

    static CARAPI_(IDeque*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI AddFirst(
        /* [in] */ IInterface * e) = 0;

    virtual CARAPI AddLast(
        /* [in] */ IInterface * e) = 0;

    virtual CARAPI OfferFirst(
        /* [in] */ IInterface * e,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI OfferLast(
        /* [in] */ IInterface * e,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI RemoveFirst(
        /* [out] */ IInterface ** e) = 0;

    virtual CARAPI RemoveLast(
        /* [out] */ IInterface ** e) = 0;

    virtual CARAPI PollFirst(
        /* [out] */ IInterface ** e) = 0;

    virtual CARAPI PollLast(
        /* [out] */ IInterface ** e) = 0;

    virtual CARAPI GetFirst(
        /* [out] */ IInterface ** e) = 0;

    virtual CARAPI GetLast(
        /* [out] */ IInterface ** e) = 0;

    virtual CARAPI PeekFirst(
        /* [out] */ IInterface ** e) = 0;

    virtual CARAPI PeekLast(
        /* [out] */ IInterface ** e) = 0;

    virtual CARAPI RemoveFirstOccurrence(
        /* [in] */ IInterface * o,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI RemoveLastOccurrence(
        /* [in] */ IInterface * o,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI Push(
        /* [in] */ IInterface * e) = 0;

    virtual CARAPI Pop(
        /* [out] */ IInterface ** e) = 0;

    virtual CARAPI GetDescendingIterator(
        /* [out] */ Elastos::Utility::IIterator ** iterator) = 0;

    virtual CARAPI Offer(
        /* [in] */ IInterface * e,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Remove(
        /* [out] */ IInterface ** e) = 0;

    virtual CARAPI Poll(
        /* [out] */ IInterface ** e) = 0;

    virtual CARAPI GetElement(
        /* [out] */ IInterface ** e) = 0;

    virtual CARAPI Peek(
        /* [out] */ IInterface ** e) = 0;

    virtual CARAPI GetIterator(
        /* [out] */ Elastos::Utility::IIterator ** it) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI Clear() = 0;

    virtual CARAPI Contains(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ContainsAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI ToArray(
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** array) = 0;

    virtual CARAPI ToArray(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * inArray,
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** outArray) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("9D9D9131-0812-2414-5CA0-6BF9A3BD8D1B")
IWeakHashMap : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IWeakHashMap*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IWeakHashMap*)pObj->Probe(EIID_IWeakHashMap);
    }

    static CARAPI_(IWeakHashMap*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IWeakHashMap*)pObj->Probe(EIID_IWeakHashMap);
    }

    static CARAPI_(IWeakHashMap*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI Clear() = 0;

    virtual CARAPI ContainsKey(
        /* [in] */ IInterface * key,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ContainsValue(
        /* [in] */ IInterface * value,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetEntrySet(
        /* [out] */ Elastos::Utility::ISet ** entries) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Get(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** value) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetKeySet(
        /* [out] */ Elastos::Utility::ISet ** keySet) = 0;

    virtual CARAPI Put(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * value,
        /* [out] */ IInterface ** oldValue) = 0;

    virtual CARAPI Put(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI PutAll(
        /* [in] */ Elastos::Utility::IMap * map) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** value) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * key) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI GetValues(
        /* [out] */ Elastos::Utility::ICollection ** value) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("0E78FB1B-5752-A8A3-45CE-BFF392F62DDB")
ITreeMap : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ITreeMap*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITreeMap*)pObj->Probe(EIID_ITreeMap);
    }

    static CARAPI_(ITreeMap*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITreeMap*)pObj->Probe(EIID_ITreeMap);
    }

    static CARAPI_(ITreeMap*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetLowerEntry(
        /* [in] */ IInterface * key,
        /* [out] */ Elastos::Utility::IMapEntry ** outent) = 0;

    virtual CARAPI GetLowerKey(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI GetFloorEntry(
        /* [in] */ IInterface * key,
        /* [out] */ Elastos::Utility::IMapEntry ** outent) = 0;

    virtual CARAPI GetFloorKey(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI GetCeilingEntry(
        /* [in] */ IInterface * key,
        /* [out] */ Elastos::Utility::IMapEntry ** outent) = 0;

    virtual CARAPI GetCeilingKey(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI GetHigherEntry(
        /* [in] */ IInterface * key,
        /* [out] */ Elastos::Utility::IMapEntry ** outent) = 0;

    virtual CARAPI GetHigherKey(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI GetFirstEntry(
        /* [out] */ Elastos::Utility::IMapEntry ** outent) = 0;

    virtual CARAPI GetLastEntry(
        /* [out] */ Elastos::Utility::IMapEntry ** outent) = 0;

    virtual CARAPI PollFirstEntry(
        /* [out] */ Elastos::Utility::IMapEntry ** outent) = 0;

    virtual CARAPI PollLastEntry(
        /* [out] */ Elastos::Utility::IMapEntry ** outent) = 0;

    virtual CARAPI GetDescendingMap(
        /* [out] */ Elastos::Utility::INavigableMap ** outnav) = 0;

    virtual CARAPI GetNavigableKeySet(
        /* [out] */ Elastos::Utility::INavigableSet ** outnav) = 0;

    virtual CARAPI GetDescendingKeySet(
        /* [out] */ Elastos::Utility::INavigableSet ** outnav) = 0;

    virtual CARAPI GetSubMap(
        /* [in] */ IInterface * fromKey,
        /* [in] */ _ELASTOS Boolean fromInclusive,
        /* [in] */ IInterface * toKey,
        /* [in] */ _ELASTOS Boolean toInclusive,
        /* [out] */ Elastos::Utility::INavigableMap ** outnav) = 0;

    virtual CARAPI GetHeadMap(
        /* [in] */ IInterface * toKey,
        /* [in] */ _ELASTOS Boolean inclusive,
        /* [out] */ Elastos::Utility::INavigableMap ** outnav) = 0;

    virtual CARAPI GetTailMap(
        /* [in] */ IInterface * fromKey,
        /* [in] */ _ELASTOS Boolean inclusive,
        /* [out] */ Elastos::Utility::INavigableMap ** outnav) = 0;

    virtual CARAPI GetSubMap(
        /* [in] */ IInterface * fromKey,
        /* [in] */ IInterface * toKey,
        /* [out] */ Elastos::Utility::ISortedMap ** res) = 0;

    virtual CARAPI GetHeadMap(
        /* [in] */ IInterface * toKey,
        /* [out] */ Elastos::Utility::ISortedMap ** res) = 0;

    virtual CARAPI GetTailMap(
        /* [in] */ IInterface * fromKey,
        /* [out] */ Elastos::Utility::ISortedMap ** res) = 0;

    virtual CARAPI GetComparator(
        /* [out] */ Elastos::Core::IComparator ** comp) = 0;

    virtual CARAPI GetFirstKey(
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI GetLastKey(
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI Clear() = 0;

    virtual CARAPI ContainsKey(
        /* [in] */ IInterface * key,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ContainsValue(
        /* [in] */ IInterface * value,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetEntrySet(
        /* [out] */ Elastos::Utility::ISet ** entries) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Get(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** value) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetKeySet(
        /* [out] */ Elastos::Utility::ISet ** keySet) = 0;

    virtual CARAPI Put(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * value,
        /* [out] */ IInterface ** oldValue) = 0;

    virtual CARAPI Put(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI PutAll(
        /* [in] */ Elastos::Utility::IMap * map) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** value) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * key) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI GetValues(
        /* [out] */ Elastos::Utility::ICollection ** value) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("F1E0FD5D-1C52-6A63-7E38-2829C3C60F0F")
ITreeSet : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ITreeSet*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITreeSet*)pObj->Probe(EIID_ITreeSet);
    }

    static CARAPI_(ITreeSet*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITreeSet*)pObj->Probe(EIID_ITreeSet);
    }

    static CARAPI_(ITreeSet*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetLower(
        /* [in] */ IInterface * e,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI GetFloor(
        /* [in] */ IInterface * e,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI GetCeiling(
        /* [in] */ IInterface * e,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI GetHigher(
        /* [in] */ IInterface * e,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI PollFirst(
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI PollLast(
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI GetDescendingSet(
        /* [out] */ Elastos::Utility::INavigableSet ** outnav) = 0;

    virtual CARAPI GetDescendingIterator(
        /* [out] */ Elastos::Utility::IIterator ** outiter) = 0;

    virtual CARAPI GetSubSet(
        /* [in] */ IInterface * fromElement,
        /* [in] */ _ELASTOS Boolean fromInclusive,
        /* [in] */ IInterface * toElement,
        /* [in] */ _ELASTOS Boolean toInclusive,
        /* [out] */ Elastos::Utility::INavigableSet ** outnav) = 0;

    virtual CARAPI GetHeadSet(
        /* [in] */ IInterface * toElement,
        /* [in] */ _ELASTOS Boolean inclusive,
        /* [out] */ Elastos::Utility::INavigableSet ** outnav) = 0;

    virtual CARAPI GetTailSet(
        /* [in] */ IInterface * fromElement,
        /* [in] */ _ELASTOS Boolean inclusive,
        /* [out] */ Elastos::Utility::INavigableSet ** outnav) = 0;

    virtual CARAPI GetComparator(
        /* [out] */ Elastos::Core::IComparator ** outcom) = 0;

    virtual CARAPI GetFirst(
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI GetHeadSet(
        /* [in] */ IInterface * end,
        /* [out] */ Elastos::Utility::ISortedSet ** outsort) = 0;

    virtual CARAPI GetLast(
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI GetSubSet(
        /* [in] */ IInterface * start,
        /* [in] */ IInterface * end,
        /* [out] */ Elastos::Utility::ISortedSet ** outsort) = 0;

    virtual CARAPI GetTailSet(
        /* [in] */ IInterface * start,
        /* [out] */ Elastos::Utility::ISortedSet ** outsort) = 0;

    virtual CARAPI GetIterator(
        /* [out] */ Elastos::Utility::IIterator ** it) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI Clear() = 0;

    virtual CARAPI Contains(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ContainsAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI ToArray(
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** array) = 0;

    virtual CARAPI ToArray(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * inArray,
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** outArray) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("86171E48-06D2-B641-6028-F014ED878392")
IRandomAccess : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IRandomAccess*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRandomAccess*)pObj->Probe(EIID_IRandomAccess);
    }

    static CARAPI_(IRandomAccess*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRandomAccess*)pObj->Probe(EIID_IRandomAccess);
    }

    static CARAPI_(IRandomAccess*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("39EF771A-8312-35D7-1A9B-FCEFBCA47DCB")
ICurrency : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICurrency*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICurrency*)pObj->Probe(EIID_ICurrency);
    }

    static CARAPI_(ICurrency*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICurrency*)pObj->Probe(EIID_ICurrency);
    }

    static CARAPI_(ICurrency*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetCurrencyCode(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetDisplayName(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetDisplayName(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetSymbol(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetSymbol(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetDefaultFractionDigits(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("6CC84C1B-8312-35D7-1A9B-7C84BE335AFF")
ICurrencyHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICurrencyHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICurrencyHelper*)pObj->Probe(EIID_ICurrencyHelper);
    }

    static CARAPI_(ICurrencyHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICurrencyHelper*)pObj->Probe(EIID_ICurrencyHelper);
    }

    static CARAPI_(ICurrencyHelper*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetInstance(
        /* [in] */ const _ELASTOS String& currencyCode,
        /* [out] */ Elastos::Utility::ICurrency ** outcur) = 0;

    virtual CARAPI GetInstance(
        /* [in] */ Elastos::Utility::ILocale * locale,
        /* [out] */ Elastos::Utility::ICurrency ** outcur) = 0;

    virtual CARAPI GetAvailableCurrencies(
        /* [out] */ Elastos::Utility::ISet ** currencies) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("A4038D1B-E792-CD49-EFBC-A47DCBF6EFDD")
IUUID : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IUUID*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IUUID*)pObj->Probe(EIID_IUUID);
    }

    static CARAPI_(IUUID*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IUUID*)pObj->Probe(EIID_IUUID);
    }

    static CARAPI_(IUUID*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetLeastSignificantBits(
        /* [out] */ _ELASTOS Int64 * leastSigBits) = 0;

    virtual CARAPI GetMostSignificantBits(
        /* [out] */ _ELASTOS Int64 * mostSigBits) = 0;

    virtual CARAPI Version(
        /* [out] */ _ELASTOS Int32 * v) = 0;

    virtual CARAPI Variant(
        /* [out] */ _ELASTOS Int32 * variant) = 0;

    virtual CARAPI Timestamp(
        /* [out] */ _ELASTOS Int64 * timeStamp) = 0;

    virtual CARAPI ClockSequence(
        /* [out] */ _ELASTOS Int32 * clockSequence) = 0;

    virtual CARAPI Node(
        /* [out] */ _ELASTOS Int64 * node) = 0;

    virtual CARAPI CompareTo(
        /* [in] */ IInterface * other,
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * obj,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hash) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("D8DD4109-E792-4D49-84BE-335AFFCE4BDA")
IUUIDHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IUUIDHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IUUIDHelper*)pObj->Probe(EIID_IUUIDHelper);
    }

    static CARAPI_(IUUIDHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IUUIDHelper*)pObj->Probe(EIID_IUUIDHelper);
    }

    static CARAPI_(IUUIDHelper*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI RandomUUID(
        /* [out] */ Elastos::Utility::IUUID ** uuid) = 0;

    virtual CARAPI NameUUIDFromBytes(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Byte> * name,
        /* [out] */ Elastos::Utility::IUUID ** uuid) = 0;

    virtual CARAPI FromString(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Utility::IUUID ** uuid) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("25A1FC25-1612-3F8D-DADB-B821C3C60F0F")
IArrayList : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IArrayList*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IArrayList*)pObj->Probe(EIID_IArrayList);
    }

    static CARAPI_(IArrayList*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IArrayList*)pObj->Probe(EIID_IArrayList);
    }

    static CARAPI_(IArrayList*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI EnsureCapacity(
        /* [in] */ _ELASTOS Int32 minimumCapacity) = 0;

    virtual CARAPI TrimToSize() = 0;

    virtual CARAPI Add(
        /* [in] */ _ELASTOS Int32 location,
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI AddAll(
        /* [in] */ _ELASTOS Int32 location,
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI AddAll(
        /* [in] */ _ELASTOS Int32 location,
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI Get(
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ IInterface ** object) = 0;

    virtual CARAPI IndexOf(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI LastIndexOf(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI GetListIterator(
        /* [out] */ Elastos::Utility::IListIterator ** it) = 0;

    virtual CARAPI GetListIterator(
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ Elastos::Utility::IListIterator ** it) = 0;

    virtual CARAPI Remove(
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ IInterface ** object) = 0;

    virtual CARAPI Remove(
        /* [in] */ _ELASTOS Int32 location) = 0;

    virtual CARAPI Set(
        /* [in] */ _ELASTOS Int32 location,
        /* [in] */ IInterface * object,
        /* [out] */ IInterface ** prevObject) = 0;

    virtual CARAPI Set(
        /* [in] */ _ELASTOS Int32 location,
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI GetSubList(
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ Elastos::Utility::IList ** subList) = 0;

    virtual CARAPI GetIterator(
        /* [out] */ Elastos::Utility::IIterator ** it) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI Clear() = 0;

    virtual CARAPI Contains(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ContainsAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI ToArray(
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** array) = 0;

    virtual CARAPI ToArray(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * inArray,
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** outArray) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("A44C225E-83D2-39AB-61EB-796052858D1F")
IFormattableFlags : public IInterface
{
    static const _ELASTOS Int32 LEFT_JUSTIFY = 1;
    static const _ELASTOS Int32 UPPERCASE = 2;
    static const _ELASTOS Int32 ALTERNATE = 4;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFormattableFlags*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFormattableFlags*)pObj->Probe(EIID_IFormattableFlags);
    }

    static CARAPI_(IFormattableFlags*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFormattableFlags*)pObj->Probe(EIID_IFormattableFlags);
    }

    static CARAPI_(IFormattableFlags*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("2B044C44-83D2-39AB-613F-FBE1A0A40C1B")
IFormatter : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFormatter*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFormatter*)pObj->Probe(EIID_IFormatter);
    }

    static CARAPI_(IFormatter*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFormatter*)pObj->Probe(EIID_IFormatter);
    }

    static CARAPI_(IFormatter*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI Format(
        /* [in] */ const _ELASTOS String& format,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * args) = 0;

    virtual CARAPI Format(
        /* [in] */ Elastos::Utility::ILocale * l,
        /* [in] */ const _ELASTOS String& format,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * args) = 0;

    virtual CARAPI GetLocale(
        /* [out] */ Elastos::Utility::ILocale ** outlocale) = 0;

    virtual CARAPI GetOut(
        /* [out] */ Elastos::Core::IAppendable ** outapp) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetIoException() = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("9C142552-83D2-39AB-61EB-F9E1A0A40C1B")
IFormattable : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFormattable*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFormattable*)pObj->Probe(EIID_IFormattable);
    }

    static CARAPI_(IFormattable*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFormattable*)pObj->Probe(EIID_IFormattable);
    }

    static CARAPI_(IFormattable*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI FormatTo(
        /* [in] */ Elastos::Utility::IFormatter * formatter,
        /* [in] */ _ELASTOS Int32 flags,
        /* [in] */ _ELASTOS Int32 width,
        /* [in] */ _ELASTOS Int32 precision) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("0E63AE51-8292-91BE-8ECC-FDE1A0A40C1B")
IArrayDeque : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IArrayDeque*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IArrayDeque*)pObj->Probe(EIID_IArrayDeque);
    }

    static CARAPI_(IArrayDeque*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IArrayDeque*)pObj->Probe(EIID_IArrayDeque);
    }

    static CARAPI_(IArrayDeque*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetIterator(
        /* [out] */ Elastos::Utility::IIterator ** it) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI Clear() = 0;

    virtual CARAPI Contains(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ContainsAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI ToArray(
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** array) = 0;

    virtual CARAPI ToArray(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * inArray,
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** outArray) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("C3441F2A-B312-F78C-7FB4-B77143868D1F")
IEventListener : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IEventListener*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IEventListener*)pObj->Probe(EIID_IEventListener);
    }

    static CARAPI_(IEventListener*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IEventListener*)pObj->Probe(EIID_IEventListener);
    }

    static CARAPI_(IEventListener*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("A3D52F2D-B312-F78C-33D4-90B183C78FF6")
IEventListenerProxy : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IEventListenerProxy*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IEventListenerProxy*)pObj->Probe(EIID_IEventListenerProxy);
    }

    static CARAPI_(IEventListenerProxy*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IEventListenerProxy*)pObj->Probe(EIID_IEventListenerProxy);
    }

    static CARAPI_(IEventListenerProxy*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetListener(
        /* [out] */ Elastos::Utility::IEventListener ** evl) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("71F1262C-3312-3FA3-DADB-B821C3C60F0F")
IEventObject : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IEventObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IEventObject*)pObj->Probe(EIID_IEventObject);
    }

    static CARAPI_(IEventObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IEventObject*)pObj->Probe(EIID_IEventObject);
    }

    static CARAPI_(IEventObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetSource(
        /* [out] */ IInterface ** outface) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("EE89CE31-8712-37FC-F4B7-FCD1DEC60D19")
ISortedMap : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISortedMap*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISortedMap*)pObj->Probe(EIID_ISortedMap);
    }

    static CARAPI_(ISortedMap*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISortedMap*)pObj->Probe(EIID_ISortedMap);
    }

    static CARAPI_(ISortedMap*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetComparator(
        /* [out] */ Elastos::Core::IComparator ** comp) = 0;

    virtual CARAPI GetFirstKey(
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI GetHeadMap(
        /* [in] */ IInterface * endKey,
        /* [out] */ Elastos::Utility::ISortedMap ** sortmap) = 0;

    virtual CARAPI GetLastKey(
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI GetSubMap(
        /* [in] */ IInterface * startKey,
        /* [in] */ IInterface * endKey,
        /* [out] */ Elastos::Utility::ISortedMap ** sortmap) = 0;

    virtual CARAPI GetTailMap(
        /* [in] */ IInterface * startKey,
        /* [out] */ Elastos::Utility::ISortedMap ** sortmap) = 0;

    virtual CARAPI Clear() = 0;

    virtual CARAPI ContainsKey(
        /* [in] */ IInterface * key,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ContainsValue(
        /* [in] */ IInterface * value,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetEntrySet(
        /* [out] */ Elastos::Utility::ISet ** entries) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Get(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** value) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetKeySet(
        /* [out] */ Elastos::Utility::ISet ** keySet) = 0;

    virtual CARAPI Put(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * value,
        /* [out] */ IInterface ** oldValue) = 0;

    virtual CARAPI Put(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI PutAll(
        /* [in] */ Elastos::Utility::IMap * map) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** value) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * key) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI GetValues(
        /* [out] */ Elastos::Utility::ICollection ** value) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("023DF65C-9752-E6DF-2C59-2031E3878392")
INavigableMap : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INavigableMap*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INavigableMap*)pObj->Probe(EIID_INavigableMap);
    }

    static CARAPI_(INavigableMap*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INavigableMap*)pObj->Probe(EIID_INavigableMap);
    }

    static CARAPI_(INavigableMap*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetLowerEntry(
        /* [in] */ IInterface * key,
        /* [out] */ Elastos::Utility::IMapEntry ** outent) = 0;

    virtual CARAPI GetLowerKey(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI GetFloorEntry(
        /* [in] */ IInterface * key,
        /* [out] */ Elastos::Utility::IMapEntry ** outent) = 0;

    virtual CARAPI GetFloorKey(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI GetCeilingEntry(
        /* [in] */ IInterface * key,
        /* [out] */ Elastos::Utility::IMapEntry ** outent) = 0;

    virtual CARAPI GetCeilingKey(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI GetHigherEntry(
        /* [in] */ IInterface * key,
        /* [out] */ Elastos::Utility::IMapEntry ** outent) = 0;

    virtual CARAPI GetHigherKey(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI GetFirstEntry(
        /* [out] */ Elastos::Utility::IMapEntry ** outent) = 0;

    virtual CARAPI GetLastEntry(
        /* [out] */ Elastos::Utility::IMapEntry ** outent) = 0;

    virtual CARAPI PollFirstEntry(
        /* [out] */ Elastos::Utility::IMapEntry ** outent) = 0;

    virtual CARAPI PollLastEntry(
        /* [out] */ Elastos::Utility::IMapEntry ** outent) = 0;

    virtual CARAPI GetDescendingMap(
        /* [out] */ Elastos::Utility::INavigableMap ** outnav) = 0;

    virtual CARAPI GetNavigableKeySet(
        /* [out] */ Elastos::Utility::INavigableSet ** outnav) = 0;

    virtual CARAPI GetDescendingKeySet(
        /* [out] */ Elastos::Utility::INavigableSet ** outnav) = 0;

    virtual CARAPI GetSubMap(
        /* [in] */ IInterface * fromKey,
        /* [in] */ _ELASTOS Boolean fromInclusive,
        /* [in] */ IInterface * toKey,
        /* [in] */ _ELASTOS Boolean toInclusive,
        /* [out] */ Elastos::Utility::INavigableMap ** outnav) = 0;

    virtual CARAPI GetHeadMap(
        /* [in] */ IInterface * toKey,
        /* [in] */ _ELASTOS Boolean inclusive,
        /* [out] */ Elastos::Utility::INavigableMap ** outnav) = 0;

    virtual CARAPI GetTailMap(
        /* [in] */ IInterface * fromKey,
        /* [in] */ _ELASTOS Boolean inclusive,
        /* [out] */ Elastos::Utility::INavigableMap ** outnav) = 0;

    virtual CARAPI GetSubMap(
        /* [in] */ IInterface * fromKey,
        /* [in] */ IInterface * toKey,
        /* [out] */ Elastos::Utility::ISortedMap ** res) = 0;

    virtual CARAPI GetHeadMap(
        /* [in] */ IInterface * toKey,
        /* [out] */ Elastos::Utility::ISortedMap ** res) = 0;

    virtual CARAPI GetTailMap(
        /* [in] */ IInterface * fromKey,
        /* [out] */ Elastos::Utility::ISortedMap ** res) = 0;

    virtual CARAPI GetComparator(
        /* [out] */ Elastos::Core::IComparator ** comp) = 0;

    virtual CARAPI GetFirstKey(
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI GetLastKey(
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI Clear() = 0;

    virtual CARAPI ContainsKey(
        /* [in] */ IInterface * key,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ContainsValue(
        /* [in] */ IInterface * value,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetEntrySet(
        /* [out] */ Elastos::Utility::ISet ** entries) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Get(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** value) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetKeySet(
        /* [out] */ Elastos::Utility::ISet ** keySet) = 0;

    virtual CARAPI Put(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * value,
        /* [out] */ IInterface ** oldValue) = 0;

    virtual CARAPI Put(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI PutAll(
        /* [in] */ Elastos::Utility::IMap * map) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** value) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * key) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI GetValues(
        /* [out] */ Elastos::Utility::ICollection ** value) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("5AE0A748-9A92-0E1F-4ACA-B0F1C3C36796")
ISet : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISet*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISet*)pObj->Probe(EIID_ISet);
    }

    static CARAPI_(ISet*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISet*)pObj->Probe(EIID_ISet);
    }

    static CARAPI_(ISet*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetIterator(
        /* [out] */ Elastos::Utility::IIterator ** it) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI Clear() = 0;

    virtual CARAPI Contains(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ContainsAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI ToArray(
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** array) = 0;

    virtual CARAPI ToArray(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * inArray,
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** outArray) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("BDD5E652-8712-9AAB-4FA8-F9E1A0A40C1B")
ISortedSet : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISortedSet*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISortedSet*)pObj->Probe(EIID_ISortedSet);
    }

    static CARAPI_(ISortedSet*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISortedSet*)pObj->Probe(EIID_ISortedSet);
    }

    static CARAPI_(ISortedSet*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetComparator(
        /* [out] */ Elastos::Core::IComparator ** outcom) = 0;

    virtual CARAPI GetFirst(
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI GetHeadSet(
        /* [in] */ IInterface * end,
        /* [out] */ Elastos::Utility::ISortedSet ** outsort) = 0;

    virtual CARAPI GetLast(
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI GetSubSet(
        /* [in] */ IInterface * start,
        /* [in] */ IInterface * end,
        /* [out] */ Elastos::Utility::ISortedSet ** outsort) = 0;

    virtual CARAPI GetTailSet(
        /* [in] */ IInterface * start,
        /* [out] */ Elastos::Utility::ISortedSet ** outsort) = 0;

    virtual CARAPI GetIterator(
        /* [out] */ Elastos::Utility::IIterator ** it) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI Clear() = 0;

    virtual CARAPI Contains(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ContainsAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI ToArray(
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** array) = 0;

    virtual CARAPI ToArray(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * inArray,
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** outArray) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("5ED5F746-9752-E6DF-2CA9-F9E1A0A40C1B")
INavigableSet : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INavigableSet*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INavigableSet*)pObj->Probe(EIID_INavigableSet);
    }

    static CARAPI_(INavigableSet*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INavigableSet*)pObj->Probe(EIID_INavigableSet);
    }

    static CARAPI_(INavigableSet*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetLower(
        /* [in] */ IInterface * e,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI GetFloor(
        /* [in] */ IInterface * e,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI GetCeiling(
        /* [in] */ IInterface * e,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI GetHigher(
        /* [in] */ IInterface * e,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI PollFirst(
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI PollLast(
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI GetDescendingSet(
        /* [out] */ Elastos::Utility::INavigableSet ** outnav) = 0;

    virtual CARAPI GetDescendingIterator(
        /* [out] */ Elastos::Utility::IIterator ** outiter) = 0;

    virtual CARAPI GetSubSet(
        /* [in] */ IInterface * fromElement,
        /* [in] */ _ELASTOS Boolean fromInclusive,
        /* [in] */ IInterface * toElement,
        /* [in] */ _ELASTOS Boolean toInclusive,
        /* [out] */ Elastos::Utility::INavigableSet ** outnav) = 0;

    virtual CARAPI GetHeadSet(
        /* [in] */ IInterface * toElement,
        /* [in] */ _ELASTOS Boolean inclusive,
        /* [out] */ Elastos::Utility::INavigableSet ** outnav) = 0;

    virtual CARAPI GetTailSet(
        /* [in] */ IInterface * fromElement,
        /* [in] */ _ELASTOS Boolean inclusive,
        /* [out] */ Elastos::Utility::INavigableSet ** outnav) = 0;

    virtual CARAPI GetComparator(
        /* [out] */ Elastos::Core::IComparator ** outcom) = 0;

    virtual CARAPI GetFirst(
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI GetHeadSet(
        /* [in] */ IInterface * end,
        /* [out] */ Elastos::Utility::ISortedSet ** outsort) = 0;

    virtual CARAPI GetLast(
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI GetSubSet(
        /* [in] */ IInterface * start,
        /* [in] */ IInterface * end,
        /* [out] */ Elastos::Utility::ISortedSet ** outsort) = 0;

    virtual CARAPI GetTailSet(
        /* [in] */ IInterface * start,
        /* [out] */ Elastos::Utility::ISortedSet ** outsort) = 0;

    virtual CARAPI GetIterator(
        /* [out] */ Elastos::Utility::IIterator ** it) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI Clear() = 0;

    virtual CARAPI Contains(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ContainsAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI ToArray(
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** array) = 0;

    virtual CARAPI ToArray(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * inArray,
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** outArray) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("FCA72017-5612-68DA-9DA3-F5EFBCA47DCB")
IObserver : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IObserver*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IObserver*)pObj->Probe(EIID_IObserver);
    }

    static CARAPI_(IObserver*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IObserver*)pObj->Probe(EIID_IObserver);
    }

    static CARAPI_(IObserver*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI Update(
        /* [in] */ Elastos::Utility::IObservable * observable,
        /* [in] */ IInterface * data) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("DAEF905C-8612-8312-6BF4-B6F4C3414919")
IObservable : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IObservable*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IObservable*)pObj->Probe(EIID_IObservable);
    }

    static CARAPI_(IObservable*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IObservable*)pObj->Probe(EIID_IObservable);
    }

    static CARAPI_(IObservable*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI AddObserver(
        /* [in] */ Elastos::Utility::IObserver * observer) = 0;

    virtual CARAPI CountObservers(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI DeleteObserver(
        /* [in] */ Elastos::Utility::IObserver * observer) = 0;

    virtual CARAPI DeleteObservers() = 0;

    virtual CARAPI HasChanged(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI NotifyObservers() = 0;

    virtual CARAPI NotifyObservers(
        /* [in] */ IInterface * data) = 0;

    virtual CARAPI ClearChanged() = 0;

    virtual CARAPI SetChanged() = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("328BD53A-5AD2-380D-50E0-40F1A3BD8D1B")
IPriorityQueue : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPriorityQueue*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPriorityQueue*)pObj->Probe(EIID_IPriorityQueue);
    }

    static CARAPI_(IPriorityQueue*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPriorityQueue*)pObj->Probe(EIID_IPriorityQueue);
    }

    static CARAPI_(IPriorityQueue*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetComparator(
        /* [out] */ Elastos::Core::IComparator ** outcom) = 0;

    virtual CARAPI Offer(
        /* [in] */ IInterface * e,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Remove(
        /* [out] */ IInterface ** e) = 0;

    virtual CARAPI Poll(
        /* [out] */ IInterface ** e) = 0;

    virtual CARAPI GetElement(
        /* [out] */ IInterface ** e) = 0;

    virtual CARAPI Peek(
        /* [out] */ IInterface ** e) = 0;

    virtual CARAPI GetIterator(
        /* [out] */ Elastos::Utility::IIterator ** it) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI Clear() = 0;

    virtual CARAPI Contains(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ContainsAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI ToArray(
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** array) = 0;

    virtual CARAPI ToArray(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * inArray,
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** outArray) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("165ABD33-3192-3FCD-DADB-B821C3C60F0F")
IEnumSet : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IEnumSet*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IEnumSet*)pObj->Probe(EIID_IEnumSet);
    }

    static CARAPI_(IEnumSet*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IEnumSet*)pObj->Probe(EIID_IEnumSet);
    }

    static CARAPI_(IEnumSet*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI Complement() = 0;

    virtual CARAPI SetRange(
        /* [in] */ IInterface * start,
        /* [in] */ IInterface * end) = 0;

    virtual CARAPI GetIterator(
        /* [out] */ Elastos::Utility::IIterator ** it) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI Clear() = 0;

    virtual CARAPI Contains(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ContainsAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI ToArray(
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** array) = 0;

    virtual CARAPI ToArray(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * inArray,
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** outArray) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("2E46533A-3192-11CD-50BC-9871FF477B1B")
IEnumSetHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IEnumSetHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IEnumSetHelper*)pObj->Probe(EIID_IEnumSetHelper);
    }

    static CARAPI_(IEnumSetHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IEnumSetHelper*)pObj->Probe(EIID_IEnumSetHelper);
    }

    static CARAPI_(IEnumSetHelper*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI NoneOf(
        /* [in] */ const _ELASTOS InterfaceID & type,
        /* [out] */ Elastos::Utility::IEnumSet ** res) = 0;

    virtual CARAPI AllOf(
        /* [in] */ const _ELASTOS InterfaceID & type,
        /* [out] */ Elastos::Utility::IEnumSet ** res) = 0;

    virtual CARAPI CopyOf(
        /* [in] */ Elastos::Utility::IEnumSet * s,
        /* [out] */ Elastos::Utility::IEnumSet ** res) = 0;

    virtual CARAPI CopyOf(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::IEnumSet ** set) = 0;

    virtual CARAPI ComplementOf(
        /* [in] */ Elastos::Utility::IEnumSet * s,
        /* [out] */ Elastos::Utility::IEnumSet ** res) = 0;

    virtual CARAPI Of(
        /* [in] */ IInterface * i,
        /* [out] */ Elastos::Utility::IEnumSet ** res) = 0;

    virtual CARAPI Of(
        /* [in] */ IInterface * i1,
        /* [in] */ IInterface * i2,
        /* [out] */ Elastos::Utility::IEnumSet ** res) = 0;

    virtual CARAPI Of(
        /* [in] */ IInterface * i1,
        /* [in] */ IInterface * i2,
        /* [in] */ IInterface * i3,
        /* [out] */ Elastos::Utility::IEnumSet ** res) = 0;

    virtual CARAPI Of(
        /* [in] */ IInterface * i1,
        /* [in] */ IInterface * i2,
        /* [in] */ IInterface * i3,
        /* [in] */ IInterface * i4,
        /* [out] */ Elastos::Utility::IEnumSet ** res) = 0;

    virtual CARAPI Of(
        /* [in] */ IInterface * i1,
        /* [in] */ IInterface * i2,
        /* [in] */ IInterface * i3,
        /* [in] */ IInterface * i4,
        /* [in] */ IInterface * i5,
        /* [out] */ Elastos::Utility::IEnumSet ** res) = 0;

    virtual CARAPI Of(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * array,
        /* [out] */ Elastos::Utility::IEnumSet ** res) = 0;

    virtual CARAPI Range(
        /* [in] */ IInterface * start,
        /* [in] */ IInterface * end,
        /* [out] */ Elastos::Utility::IEnumSet ** set) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("0AFBD03D-0452-2A1C-5018-D3FCA3BD8D1B")
IHugeEnumSet : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IHugeEnumSet*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IHugeEnumSet*)pObj->Probe(EIID_IHugeEnumSet);
    }

    static CARAPI_(IHugeEnumSet*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IHugeEnumSet*)pObj->Probe(EIID_IHugeEnumSet);
    }

    static CARAPI_(IHugeEnumSet*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetEnums(
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** arrays) = 0;

    virtual CARAPI GetBits(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Int64> ** arrays) = 0;

    virtual CARAPI Complement() = 0;

    virtual CARAPI SetRange(
        /* [in] */ IInterface * start,
        /* [in] */ IInterface * end) = 0;

    virtual CARAPI GetIterator(
        /* [out] */ Elastos::Utility::IIterator ** it) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI Clear() = 0;

    virtual CARAPI Contains(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ContainsAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI ToArray(
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** array) = 0;

    virtual CARAPI ToArray(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * inArray,
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** outArray) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("FF02D02C-4D92-C616-34FF-686FE3860C1B")
IMiniEnumSet : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IMiniEnumSet*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMiniEnumSet*)pObj->Probe(EIID_IMiniEnumSet);
    }

    static CARAPI_(IMiniEnumSet*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMiniEnumSet*)pObj->Probe(EIID_IMiniEnumSet);
    }

    static CARAPI_(IMiniEnumSet*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetEnums(
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** arrays) = 0;

    virtual CARAPI GetBits(
        /* [out] */ _ELASTOS Int64 * bits) = 0;

    virtual CARAPI Complement() = 0;

    virtual CARAPI SetRange(
        /* [in] */ IInterface * start,
        /* [in] */ IInterface * end) = 0;

    virtual CARAPI GetIterator(
        /* [out] */ Elastos::Utility::IIterator ** it) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI Clear() = 0;

    virtual CARAPI Contains(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ContainsAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI ToArray(
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** array) = 0;

    virtual CARAPI ToArray(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * inArray,
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** outArray) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("E5AB2D34-6652-F78E-7FB4-B77143868D1F")
IServiceLoader : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IServiceLoader*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IServiceLoader*)pObj->Probe(EIID_IServiceLoader);
    }

    static CARAPI_(IServiceLoader*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IServiceLoader*)pObj->Probe(EIID_IServiceLoader);
    }

    static CARAPI_(IServiceLoader*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI Reload() = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("D7BE5034-6652-F78E-23A0-7831E3FE8FF6")
IServiceLoaderHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IServiceLoaderHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IServiceLoaderHelper*)pObj->Probe(EIID_IServiceLoaderHelper);
    }

    static CARAPI_(IServiceLoaderHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IServiceLoaderHelper*)pObj->Probe(EIID_IServiceLoaderHelper);
    }

    virtual CARAPI Load(
        /* [in] */ IInterface * service,
        /* [in] */ Elastos::Core::IClassLoader * classLoader,
        /* [out] */ Elastos::Utility::IServiceLoader ** outser) = 0;

    virtual CARAPI Load(
        /* [in] */ IInterface * service,
        /* [out] */ Elastos::Utility::IServiceLoader ** outser) = 0;

    virtual CARAPI LoadInstalled(
        /* [in] */ IInterface * service,
        /* [out] */ Elastos::Utility::IServiceLoader ** outser) = 0;

    virtual CARAPI LoadFromSystemProperty(
        /* [in] */ IInterface * service,
        /* [out] */ IInterface ** outface) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("B9DBFE48-07D2-5762-7F38-2829C3C60F0F")
IVector : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IVector*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IVector*)pObj->Probe(EIID_IVector);
    }

    static CARAPI_(IVector*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IVector*)pObj->Probe(EIID_IVector);
    }

    static CARAPI_(IVector*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI AddElement(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI GetCapacity(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI CopyInto(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * elements) = 0;

    virtual CARAPI ElementAt(
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI GetElements(
        /* [out] */ Elastos::Utility::IEnumeration ** enu) = 0;

    virtual CARAPI EnsureCapacity(
        /* [in] */ _ELASTOS Int32 minimumCapacity) = 0;

    virtual CARAPI FirstElement(
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI IndexOf(
        /* [in] */ IInterface * object,
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI InsertElementAt(
        /* [in] */ IInterface * object,
        /* [in] */ _ELASTOS Int32 location) = 0;

    virtual CARAPI LastElement(
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI LastIndexOf(
        /* [in] */ IInterface * object,
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI RemoveAllElements() = 0;

    virtual CARAPI RemoveElement(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI RemoveElement(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI RemoveElementAt(
        /* [in] */ _ELASTOS Int32 location) = 0;

    virtual CARAPI SetElementAt(
        /* [in] */ IInterface * object,
        /* [in] */ _ELASTOS Int32 location) = 0;

    virtual CARAPI SetSize(
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI TrimToSize() = 0;

    virtual CARAPI Add(
        /* [in] */ _ELASTOS Int32 location,
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI AddAll(
        /* [in] */ _ELASTOS Int32 location,
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI AddAll(
        /* [in] */ _ELASTOS Int32 location,
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI Get(
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ IInterface ** object) = 0;

    virtual CARAPI IndexOf(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI LastIndexOf(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI GetListIterator(
        /* [out] */ Elastos::Utility::IListIterator ** it) = 0;

    virtual CARAPI GetListIterator(
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ Elastos::Utility::IListIterator ** it) = 0;

    virtual CARAPI Remove(
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ IInterface ** object) = 0;

    virtual CARAPI Remove(
        /* [in] */ _ELASTOS Int32 location) = 0;

    virtual CARAPI Set(
        /* [in] */ _ELASTOS Int32 location,
        /* [in] */ IInterface * object,
        /* [out] */ IInterface ** prevObject) = 0;

    virtual CARAPI Set(
        /* [in] */ _ELASTOS Int32 location,
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI GetSubList(
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ Elastos::Utility::IList ** subList) = 0;

    virtual CARAPI GetIterator(
        /* [out] */ Elastos::Utility::IIterator ** it) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI Clear() = 0;

    virtual CARAPI Contains(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ContainsAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI ToArray(
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** array) = 0;

    virtual CARAPI ToArray(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * inArray,
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** outArray) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("B52BFA1B-7712-A693-FB3B-2F69DFB2FD7B")
IStack : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IStack*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStack*)pObj->Probe(EIID_IStack);
    }

    static CARAPI_(IStack*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStack*)pObj->Probe(EIID_IStack);
    }

    static CARAPI_(IStack*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI Peek(
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI Pop(
        /* [out] */ IInterface ** outface) = 0;

    virtual CARAPI Push(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI Search(
        /* [in] */ IInterface * o,
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI Add(
        /* [in] */ _ELASTOS Int32 location,
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI AddAll(
        /* [in] */ _ELASTOS Int32 location,
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI AddAll(
        /* [in] */ _ELASTOS Int32 location,
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI Get(
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ IInterface ** object) = 0;

    virtual CARAPI IndexOf(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI LastIndexOf(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI GetListIterator(
        /* [out] */ Elastos::Utility::IListIterator ** it) = 0;

    virtual CARAPI GetListIterator(
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ Elastos::Utility::IListIterator ** it) = 0;

    virtual CARAPI Remove(
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ IInterface ** object) = 0;

    virtual CARAPI Remove(
        /* [in] */ _ELASTOS Int32 location) = 0;

    virtual CARAPI Set(
        /* [in] */ _ELASTOS Int32 location,
        /* [in] */ IInterface * object,
        /* [out] */ IInterface ** prevObject) = 0;

    virtual CARAPI Set(
        /* [in] */ _ELASTOS Int32 location,
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI GetSubList(
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ Elastos::Utility::IList ** subList) = 0;

    virtual CARAPI GetIterator(
        /* [out] */ Elastos::Utility::IIterator ** it) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI Clear() = 0;

    virtual CARAPI Contains(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ContainsAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI ToArray(
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** array) = 0;

    virtual CARAPI ToArray(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * inArray,
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** outArray) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("7970515F-9AD2-2E37-9875-ACF1C3414919")
IStringTokenizer : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IStringTokenizer*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStringTokenizer*)pObj->Probe(EIID_IStringTokenizer);
    }

    static CARAPI_(IStringTokenizer*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStringTokenizer*)pObj->Probe(EIID_IStringTokenizer);
    }

    static CARAPI_(IStringTokenizer*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CountTokens(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI HasMoreTokens(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetNextToken(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetNextToken(
        /* [in] */ const _ELASTOS String& delims,
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("717FFC31-8792-3618-48A4-408145E38FF6")
IUnsafeArrayList : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IUnsafeArrayList*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IUnsafeArrayList*)pObj->Probe(EIID_IUnsafeArrayList);
    }

    static CARAPI_(IUnsafeArrayList*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IUnsafeArrayList*)pObj->Probe(EIID_IUnsafeArrayList);
    }

    static CARAPI_(IUnsafeArrayList*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetArrays(
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** array) = 0;

    virtual CARAPI Add(
        /* [in] */ _ELASTOS Int32 location,
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Add(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI AddAll(
        /* [in] */ _ELASTOS Int32 location,
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI AddAll(
        /* [in] */ _ELASTOS Int32 location,
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI Get(
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ IInterface ** object) = 0;

    virtual CARAPI IndexOf(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI LastIndexOf(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI GetListIterator(
        /* [out] */ Elastos::Utility::IListIterator ** it) = 0;

    virtual CARAPI GetListIterator(
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ Elastos::Utility::IListIterator ** it) = 0;

    virtual CARAPI Remove(
        /* [in] */ _ELASTOS Int32 location,
        /* [out] */ IInterface ** object) = 0;

    virtual CARAPI Remove(
        /* [in] */ _ELASTOS Int32 location) = 0;

    virtual CARAPI Set(
        /* [in] */ _ELASTOS Int32 location,
        /* [in] */ IInterface * object,
        /* [out] */ IInterface ** prevObject) = 0;

    virtual CARAPI Set(
        /* [in] */ _ELASTOS Int32 location,
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI GetSubList(
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ Elastos::Utility::IList ** subList) = 0;

    virtual CARAPI GetIterator(
        /* [out] */ Elastos::Utility::IIterator ** it) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI Clear() = 0;

    virtual CARAPI Contains(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ContainsAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RemoveAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ _ELASTOS Boolean * modified) = 0;

    virtual CARAPI RetainAll(
        /* [in] */ Elastos::Utility::ICollection * collection) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI ToArray(
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** array) = 0;

    virtual CARAPI ToArray(
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * inArray,
        /* [out, callee] */ _ELASTOS ArrayOf<IInterface *> ** outArray) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("259A244C-0652-61BE-FDF2-C8F08CA78DC5")
IPropertyPermission : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPropertyPermission*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPropertyPermission*)pObj->Probe(EIID_IPropertyPermission);
    }

    static CARAPI_(IPropertyPermission*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPropertyPermission*)pObj->Probe(EIID_IPropertyPermission);
    }

    static CARAPI_(IPropertyPermission*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("C7922358-1A52-35DF-0617-8101F6EEE91F")
IReverseComparator : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IReverseComparator*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IReverseComparator*)pObj->Probe(EIID_IReverseComparator);
    }

    static CARAPI_(IReverseComparator*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IReverseComparator*)pObj->Probe(EIID_IReverseComparator);
    }

    static CARAPI_(IReverseComparator*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("F5322458-1A52-35DF-0617-8101F6EE6901")
IReverseComparator2 : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IReverseComparator2*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IReverseComparator2*)pObj->Probe(EIID_IReverseComparator2);
    }

    static CARAPI_(IReverseComparator2*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IReverseComparator2*)pObj->Probe(EIID_IReverseComparator2);
    }

    static CARAPI_(IReverseComparator2*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("D1C6F946-1152-AF97-26DA-F8E1A0A40C1B")
ICollections : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICollections*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICollections*)pObj->Probe(EIID_ICollections);
    }

    static CARAPI_(ICollections*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICollections*)pObj->Probe(EIID_ICollections);
    }

    static CARAPI_(ICollections*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI BinarySearch(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI BinarySearch(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ IInterface * object,
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI Copy(
        /* [in] */ Elastos::Utility::IList * destination,
        /* [in] */ Elastos::Utility::IList * source) = 0;

    virtual CARAPI Enumeration(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Utility::IEnumeration ** result) = 0;

    virtual CARAPI Fill(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ IInterface * object) = 0;

    virtual CARAPI Max(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ PInterface * result) = 0;

    virtual CARAPI Max(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ PInterface * result) = 0;

    virtual CARAPI Min(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ PInterface * result) = 0;

    virtual CARAPI Min(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ PInterface * result) = 0;

    virtual CARAPI NCopies(
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ IInterface * object,
        /* [out] */ Elastos::Utility::IList ** result) = 0;

    virtual CARAPI Reverse(
        /* [in] */ Elastos::Utility::IList * list) = 0;

    virtual CARAPI ReverseOrder(
        /* [out] */ Elastos::Core::IComparator ** result) = 0;

    virtual CARAPI ReverseOrder(
        /* [in] */ Elastos::Core::IComparator * c,
        /* [out] */ Elastos::Core::IComparator ** result) = 0;

    virtual CARAPI Shuffle(
        /* [in] */ Elastos::Utility::IList * list) = 0;

    virtual CARAPI Singleton(
        /* [in] */ IInterface * object,
        /* [out] */ Elastos::Utility::ISet ** result) = 0;

    virtual CARAPI SingletonList(
        /* [in] */ IInterface * object,
        /* [out] */ Elastos::Utility::IList ** result) = 0;

    virtual CARAPI SingletonMap(
        /* [in] */ PInterface key,
        /* [in] */ PInterface value,
        /* [out] */ Elastos::Utility::IMap ** result) = 0;

    virtual CARAPI Sort(
        /* [in] */ Elastos::Utility::IList * list) = 0;

    virtual CARAPI Sort(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ Elastos::Core::IComparator * comparator) = 0;

    virtual CARAPI Swap(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ _ELASTOS Int32 index1,
        /* [in] */ _ELASTOS Int32 index2) = 0;

    virtual CARAPI ReplaceAll(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ IInterface * obj,
        /* [in] */ IInterface * obj2,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Rotate(
        /* [in] */ Elastos::Utility::IList * lst,
        /* [in] */ _ELASTOS Int32 dist) = 0;

    virtual CARAPI IndexOfSubList(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ Elastos::Utility::IList * sublist,
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI LastIndexOfSubList(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ Elastos::Utility::IList * sublist,
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI List(
        /* [in] */ Elastos::Utility::IEnumeration * enumeration,
        /* [out] */ Elastos::Utility::IArrayList ** result) = 0;

    virtual CARAPI SynchronizedCollection(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Utility::ICollection ** result) = 0;

    virtual CARAPI SynchronizedList(
        /* [in] */ Elastos::Utility::IList * list,
        /* [out] */ Elastos::Utility::IList ** result) = 0;

    virtual CARAPI SynchronizedMap(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ Elastos::Utility::IMap ** result) = 0;

    virtual CARAPI SynchronizedSet(
        /* [in] */ Elastos::Utility::ISet * set,
        /* [out] */ Elastos::Utility::ISet ** result) = 0;

    virtual CARAPI SynchronizedSortedMap(
        /* [in] */ Elastos::Utility::ISortedMap * map,
        /* [out] */ Elastos::Utility::ISortedMap ** result) = 0;

    virtual CARAPI SynchronizedSortedSet(
        /* [in] */ Elastos::Utility::ISortedSet * set,
        /* [out] */ Elastos::Utility::ISortedSet ** result) = 0;

    virtual CARAPI UnmodifiableCollection(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Utility::ICollection ** result) = 0;

    virtual CARAPI UnmodifiableList(
        /* [in] */ Elastos::Utility::IList * list,
        /* [out] */ Elastos::Utility::IList ** result) = 0;

    virtual CARAPI UnmodifiableMap(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ Elastos::Utility::IMap ** result) = 0;

    virtual CARAPI UnmodifiableSet(
        /* [in] */ Elastos::Utility::ISet * set,
        /* [out] */ Elastos::Utility::ISet ** result) = 0;

    virtual CARAPI UnmodifiableSortedMap(
        /* [in] */ Elastos::Utility::ISortedMap * map,
        /* [out] */ Elastos::Utility::ISortedMap ** result) = 0;

    virtual CARAPI UnmodifiableSortedSet(
        /* [in] */ Elastos::Utility::ISortedSet * set,
        /* [out] */ Elastos::Utility::ISortedSet ** result) = 0;

    virtual CARAPI Frequency(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [in] */ IInterface * o,
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI GetEmptyList(
        /* [out] */ Elastos::Utility::IList ** result) = 0;

    virtual CARAPI GetEmptySet(
        /* [out] */ Elastos::Utility::ISet ** result) = 0;

    virtual CARAPI GetEmptyMap(
        /* [out] */ Elastos::Utility::IMap ** result) = 0;

    virtual CARAPI GetEmptyEnumeration(
        /* [out] */ Elastos::Utility::IEnumeration ** result) = 0;

    virtual CARAPI GetEmptyIterator(
        /* [out] */ Elastos::Utility::IIterator ** result) = 0;

    virtual CARAPI GetEmptyListIterator(
        /* [out] */ Elastos::Utility::IListIterator ** result) = 0;

    virtual CARAPI CheckedCollection(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [in] */ const _ELASTOS InterfaceID & type,
        /* [out] */ Elastos::Utility::ICollection ** result) = 0;

    virtual CARAPI CheckedMap(
        /* [in] */ Elastos::Utility::IMap * m,
        /* [in] */ const _ELASTOS InterfaceID & keyType,
        /* [in] */ const _ELASTOS InterfaceID & valueType,
        /* [out] */ Elastos::Utility::IMap ** result) = 0;

    virtual CARAPI CheckedList(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ const _ELASTOS InterfaceID & type,
        /* [out] */ Elastos::Utility::IList ** result) = 0;

    virtual CARAPI CheckedSet(
        /* [in] */ Elastos::Utility::ISet * s,
        /* [in] */ const _ELASTOS InterfaceID & type,
        /* [out] */ Elastos::Utility::ISet ** result) = 0;

    virtual CARAPI CheckedSortedMap(
        /* [in] */ Elastos::Utility::ISortedMap * m,
        /* [in] */ const _ELASTOS InterfaceID & keyType,
        /* [in] */ const _ELASTOS InterfaceID & valueType,
        /* [out] */ Elastos::Utility::ISortedMap ** result) = 0;

    virtual CARAPI CheckedSortedSet(
        /* [in] */ Elastos::Utility::ISortedSet * s,
        /* [in] */ const _ELASTOS InterfaceID & type,
        /* [out] */ Elastos::Utility::ISortedSet ** result) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * a,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI AddAll(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * a) = 0;

    virtual CARAPI Disjoint(
        /* [in] */ Elastos::Utility::ICollection * c1,
        /* [in] */ Elastos::Utility::ICollection * c2,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI CheckType(
        /* [in] */ IInterface * obj,
        /* [in] */ const _ELASTOS InterfaceID & type) = 0;

    virtual CARAPI SetFromMap(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ Elastos::Utility::ISet ** result) = 0;

    virtual CARAPI AsLifoQueue(
        /* [in] */ Elastos::Utility::IDeque * deque,
        /* [out] */ Elastos::Utility::IQueue ** result) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("575C8D32-B192-3F96-DADB-B821C3C60F0F")
IEnumMap : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IEnumMap*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IEnumMap*)pObj->Probe(EIID_IEnumMap);
    }

    static CARAPI_(IEnumMap*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IEnumMap*)pObj->Probe(EIID_IEnumMap);
    }

    static CARAPI_(IEnumMap*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI Clear() = 0;

    virtual CARAPI ContainsKey(
        /* [in] */ IInterface * key,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI ContainsValue(
        /* [in] */ IInterface * value,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetEntrySet(
        /* [out] */ Elastos::Utility::ISet ** entries) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * object,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Get(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** value) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * hashCode) = 0;

    virtual CARAPI IsEmpty(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetKeySet(
        /* [out] */ Elastos::Utility::ISet ** keySet) = 0;

    virtual CARAPI Put(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * value,
        /* [out] */ IInterface ** oldValue) = 0;

    virtual CARAPI Put(
        /* [in] */ IInterface * key,
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI PutAll(
        /* [in] */ Elastos::Utility::IMap * map) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * key,
        /* [out] */ IInterface ** value) = 0;

    virtual CARAPI Remove(
        /* [in] */ IInterface * key) = 0;

    virtual CARAPI GetSize(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI GetValues(
        /* [out] */ Elastos::Utility::ICollection ** value) = 0;

};
}
}

namespace Elastos {
namespace Utility {
namespace Regex {
CAR_INTERFACE("74BC4736-CB92-3FC3-DADB-B821C3C60F0F")
IMatchResult : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IMatchResult*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMatchResult*)pObj->Probe(EIID_IMatchResult);
    }

    static CARAPI_(IMatchResult*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMatchResult*)pObj->Probe(EIID_IMatchResult);
    }

    static CARAPI_(IMatchResult*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI End(
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI End(
        /* [in] */ _ELASTOS Int32 group,
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI Group(
        /* [out] */ _ELASTOS String * text) = 0;

    virtual CARAPI Group(
        /* [in] */ _ELASTOS Int32 group,
        /* [out] */ _ELASTOS String * text) = 0;

    virtual CARAPI GroupCount(
        /* [out] */ _ELASTOS Int32 * count) = 0;

    virtual CARAPI Start(
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI Start(
        /* [in] */ _ELASTOS Int32 group,
        /* [out] */ _ELASTOS Int32 * index) = 0;

};
}
}
}

namespace Elastos {
namespace Utility {
namespace Regex {
CAR_INTERFACE("BFB8F627-CB92-3FFB-DADB-B821C3C60F0F")
IMatcher : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IMatcher*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMatcher*)pObj->Probe(EIID_IMatcher);
    }

    static CARAPI_(IMatcher*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMatcher*)pObj->Probe(EIID_IMatcher);
    }

    static CARAPI_(IMatcher*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI AppendReplacement(
        /* [in] */ Elastos::Core::IStringBuffer * buffer,
        /* [in] */ const _ELASTOS String& replacement) = 0;

    virtual CARAPI Reset() = 0;

    virtual CARAPI Reset(
        /* [in] */ Elastos::Core::ICharSequence * input) = 0;

    virtual CARAPI UsePattern(
        /* [in] */ Elastos::Utility::Regex::IPattern * pattern) = 0;

    virtual CARAPI Region(
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end) = 0;

    virtual CARAPI AppendTail(
        /* [in] */ Elastos::Core::IStringBuffer * buffer) = 0;

    virtual CARAPI ReplaceFirst(
        /* [in] */ const _ELASTOS String& replacement,
        /* [out] */ _ELASTOS String * result) = 0;

    virtual CARAPI ReplaceAll(
        /* [in] */ const _ELASTOS String& replacement,
        /* [out] */ _ELASTOS String * result) = 0;

    virtual CARAPI Pattern(
        /* [out] */ Elastos::Utility::Regex::IPattern ** pattern) = 0;

    virtual CARAPI Find(
        /* [out] */ _ELASTOS Boolean * found) = 0;

    virtual CARAPI Find(
        /* [in] */ _ELASTOS Int32 start,
        /* [out] */ _ELASTOS Boolean * found) = 0;

    virtual CARAPI LookingAt(
        /* [out] */ _ELASTOS Boolean * matched) = 0;

    virtual CARAPI Matches(
        /* [out] */ _ELASTOS Boolean * matched) = 0;

    virtual CARAPI ToMatchResult(
        /* [out] */ Elastos::Utility::Regex::IMatchResult ** result) = 0;

    virtual CARAPI UseAnchoringBounds(
        /* [in] */ _ELASTOS Boolean value) = 0;

    virtual CARAPI HasAnchoringBounds(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI UseTransparentBounds(
        /* [in] */ _ELASTOS Boolean value) = 0;

    virtual CARAPI HasTransparentBounds(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI RegionStart(
        /* [out] */ _ELASTOS Int32 * start) = 0;

    virtual CARAPI RegionEnd(
        /* [out] */ _ELASTOS Int32 * end) = 0;

    virtual CARAPI RequireEnd(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI HitEnd(
        /* [out] */ _ELASTOS Boolean * hit) = 0;

};
}
}
}

namespace Elastos {
namespace Utility {
namespace Regex {
CAR_INTERFACE("0E6E3535-CB92-11FB-50BC-9871FF477B1B")
IMatcherHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IMatcherHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMatcherHelper*)pObj->Probe(EIID_IMatcherHelper);
    }

    static CARAPI_(IMatcherHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMatcherHelper*)pObj->Probe(EIID_IMatcherHelper);
    }

    static CARAPI_(IMatcherHelper*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI QuoteReplacement(
        /* [in] */ const _ELASTOS String& s,
        /* [out] */ _ELASTOS String * result) = 0;

};
}
}
}

namespace Elastos {
namespace Utility {
namespace Regex {
CAR_INTERFACE("57CC2E52-8712-2C19-613F-FBE1A0A40C1B")
ISplitter : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISplitter*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISplitter*)pObj->Probe(EIID_ISplitter);
    }

    static CARAPI_(ISplitter*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISplitter*)pObj->Probe(EIID_ISplitter);
    }

    static CARAPI_(ISplitter*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI FastSplit(
        /* [in] */ const _ELASTOS String& regularExpression,
        /* [in] */ const _ELASTOS String& input,
        /* [in] */ _ELASTOS Int32 limit,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** array) = 0;

    virtual CARAPI Split(
        /* [in] */ Elastos::Utility::Regex::IPattern * pattern,
        /* [in] */ const _ELASTOS String& regularExpression,
        /* [in] */ const _ELASTOS String& input,
        /* [in] */ _ELASTOS Int32 limit,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** array) = 0;

};
}
}
}

namespace Elastos {
namespace Utility {
namespace Regex {
CAR_INTERFACE("7E014E5B-8652-9847-7F38-2829C3C60F0F")
IPattern : public IInterface
{
    static const _ELASTOS Int32 UNIX_LINES = 0x00000001;
    static const _ELASTOS Int32 CASE_INSENSITIVE = 0x00000002;
    static const _ELASTOS Int32 COMMENTS = 0x00000004;
    static const _ELASTOS Int32 MULTILINE = 0x00000008;
    static const _ELASTOS Int32 LITERAL = 0x00000010;
    static const _ELASTOS Int32 DOTALL = 0x00000020;
    static const _ELASTOS Int32 UNICODE_CASE = 0x00000040;
    static const _ELASTOS Int32 CANON_EQ = 0x00000080;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPattern*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPattern*)pObj->Probe(EIID_IPattern);
    }

    static CARAPI_(IPattern*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPattern*)pObj->Probe(EIID_IPattern);
    }

    static CARAPI_(IPattern*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI Matcher(
        /* [in] */ const _ELASTOS String& input,
        /* [out] */ Elastos::Utility::Regex::IMatcher ** matcher) = 0;

    virtual CARAPI Matcher(
        /* [in] */ Elastos::Core::ICharSequence * input,
        /* [out] */ Elastos::Utility::Regex::IMatcher ** matcher) = 0;

    virtual CARAPI Split(
        /* [in] */ const _ELASTOS String& input,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** result) = 0;

    virtual CARAPI Split(
        /* [in] */ Elastos::Core::ICharSequence * input,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** result) = 0;

    virtual CARAPI Split(
        /* [in] */ Elastos::Core::ICharSequence * input,
        /* [in] */ _ELASTOS Int32 limit,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** result) = 0;

    virtual CARAPI GetPattern(
        /* [out] */ _ELASTOS String * regex) = 0;

    virtual CARAPI GetFlags(
        /* [out] */ _ELASTOS Int32 * flags) = 0;

};
}
}
}

namespace Elastos {
namespace Utility {
namespace Regex {
CAR_INTERFACE("03AC4619-4652-37DE-5AC7-11FACE68FD3B")
IPatternHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPatternHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPatternHelper*)pObj->Probe(EIID_IPatternHelper);
    }

    static CARAPI_(IPatternHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPatternHelper*)pObj->Probe(EIID_IPatternHelper);
    }

    static CARAPI_(IPatternHelper*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI Compile(
        /* [in] */ const _ELASTOS String& pattern,
        /* [out] */ Elastos::Utility::Regex::IPattern ** result) = 0;

    virtual CARAPI Compile(
        /* [in] */ const _ELASTOS String& regularExpression,
        /* [in] */ _ELASTOS Int32 flags,
        /* [out] */ Elastos::Utility::Regex::IPattern ** result) = 0;

    virtual CARAPI Matches(
        /* [in] */ const _ELASTOS String& regularExpression,
        /* [in] */ const _ELASTOS String& input,
        /* [out] */ _ELASTOS Boolean * matched) = 0;

    virtual CARAPI Matches(
        /* [in] */ const _ELASTOS String& regularExpression,
        /* [in] */ Elastos::Core::ICharSequence * input,
        /* [out] */ _ELASTOS Boolean * matched) = 0;

    virtual CARAPI Quote(
        /* [in] */ const _ELASTOS String& string,
        /* [out] */ _ELASTOS String * result) = 0;

};
}
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("D63BB82F-0312-C6D8-5DA0-88C1A2C77D3D")
ICStringTokenizerClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICStringTokenizerClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICStringTokenizerClassObject*)pObj->Probe(EIID_ICStringTokenizerClassObject);
    }

    static CARAPI_(ICStringTokenizerClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICStringTokenizerClassObject*)pObj->Probe(EIID_ICStringTokenizerClassObject);
    }

    static CARAPI_(ICStringTokenizerClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithString(
        /* [in] */ const _ELASTOS String& string,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithStringDelimiters(
        /* [in] */ const _ELASTOS String& string,
        /* [in] */ const _ELASTOS String& delimiters,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithStringDelimitersReturnDelimiters(
        /* [in] */ const _ELASTOS String& string,
        /* [in] */ const _ELASTOS String& delimiters,
        /* [in] */ _ELASTOS Boolean returnDelimiters,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("2C429436-0312-0D2C-50D0-C081428FD11F")
ICArrayDequeClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICArrayDequeClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICArrayDequeClassObject*)pObj->Probe(EIID_ICArrayDequeClassObject);
    }

    static CARAPI_(ICArrayDequeClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICArrayDequeClassObject*)pObj->Probe(EIID_ICArrayDequeClassObject);
    }

    static CARAPI_(ICArrayDequeClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithNumElements(
        /* [in] */ _ELASTOS Int32 numElements,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithC(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("6E989028-0312-1A2C-F518-FDD1DEC60D19")
ICArrayListClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICArrayListClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICArrayListClassObject*)pObj->Probe(EIID_ICArrayListClassObject);
    }

    static CARAPI_(ICArrayListClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICArrayListClassObject*)pObj->Probe(EIID_ICArrayListClassObject);
    }

    static CARAPI_(ICArrayListClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCapacity(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithC(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("DDAE6829-0312-1A2C-25DC-B84FE2467E3D")
ICArrayListIteratorClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICArrayListIteratorClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICArrayListIteratorClassObject*)pObj->Probe(EIID_ICArrayListIteratorClassObject);
    }

    static CARAPI_(ICArrayListIteratorClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICArrayListIteratorClassObject*)pObj->Probe(EIID_ICArrayListIteratorClassObject);
    }

    static CARAPI_(ICArrayListIteratorClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithList(
        /* [in] */ Elastos::Utility::IArrayList * list,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("2EF26944-0312-0D0E-CD56-B02821F3A3AB")
ICSimpleListIteratorClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSimpleListIteratorClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSimpleListIteratorClassObject*)pObj->Probe(EIID_ICSimpleListIteratorClassObject);
    }

    static CARAPI_(ICSimpleListIteratorClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSimpleListIteratorClassObject*)pObj->Probe(EIID_ICSimpleListIteratorClassObject);
    }

    static CARAPI_(ICSimpleListIteratorClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithList(
        /* [in] */ Elastos::Utility::IList * list,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("74746C36-0312-1A71-25DC-B84FE2467E3D")
ICFullListIteratorClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICFullListIteratorClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFullListIteratorClassObject*)pObj->Probe(EIID_ICFullListIteratorClassObject);
    }

    static CARAPI_(ICFullListIteratorClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFullListIteratorClassObject*)pObj->Probe(EIID_ICFullListIteratorClassObject);
    }

    static CARAPI_(ICFullListIteratorClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithListStart(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ _ELASTOS Int32 start,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("1D827C09-C312-A5E1-52DA-774D9A77C5DA")
ICSubAbstractListIteratorClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSubAbstractListIteratorClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSubAbstractListIteratorClassObject*)pObj->Probe(EIID_ICSubAbstractListIteratorClassObject);
    }

    static CARAPI_(ICSubAbstractListIteratorClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSubAbstractListIteratorClassObject*)pObj->Probe(EIID_ICSubAbstractListIteratorClassObject);
    }

    static CARAPI_(ICSubAbstractListIteratorClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithListItOffsetLength(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ Elastos::Utility::IListIterator * it,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("99B66E0A-C312-A5E1-52DA-774D9A77C5DA")
ICSubAbstractListClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSubAbstractListClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSubAbstractListClassObject*)pObj->Probe(EIID_ICSubAbstractListClassObject);
    }

    static CARAPI_(ICSubAbstractListClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSubAbstractListClassObject*)pObj->Probe(EIID_ICSubAbstractListClassObject);
    }

    static CARAPI_(ICSubAbstractListClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithListStartEnd(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("B51A7218-B312-F191-29C3-8A69A2B6CDE1")
ICRandomAccessSubListClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICRandomAccessSubListClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRandomAccessSubListClassObject*)pObj->Probe(EIID_ICRandomAccessSubListClassObject);
    }

    static CARAPI_(ICRandomAccessSubListClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICRandomAccessSubListClassObject*)pObj->Probe(EIID_ICRandomAccessSubListClassObject);
    }

    static CARAPI_(ICRandomAccessSubListClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithListStartEnd(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("118F9129-8312-2C05-6E68-D663F4477B1B")
ICBitSetClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICBitSetClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBitSetClassObject*)pObj->Probe(EIID_ICBitSetClassObject);
    }

    static CARAPI_(ICBitSetClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBitSetClassObject*)pObj->Probe(EIID_ICBitSetClassObject);
    }

    static CARAPI_(ICBitSetClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithBitCount(
        /* [in] */ _ELASTOS Int32 bitCount,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithArray(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int64> * array,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("669E6A15-B312-37B0-87DE-11FACE68CDBC")
ICBitSetHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICBitSetHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBitSetHelperClassObject*)pObj->Probe(EIID_ICBitSetHelperClassObject);
    }

    static CARAPI_(ICBitSetHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBitSetHelperClassObject*)pObj->Probe(EIID_ICBitSetHelperClassObject);
    }

    static CARAPI_(ICBitSetHelperClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("4014A629-0312-2D63-F518-FDD1DEC60D19")
ICEnumMapClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICEnumMapClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICEnumMapClassObject*)pObj->Probe(EIID_ICEnumMapClassObject);
    }

    static CARAPI_(ICEnumMapClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICEnumMapClassObject*)pObj->Probe(EIID_ICEnumMapClassObject);
    }

    static CARAPI_(ICEnumMapClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithKeyType(
        /* [in] */ const _ELASTOS InterfaceID & keyType,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithEnummap(
        /* [in] */ Elastos::Utility::IEnumMap * enummap,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithMap(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("6D56B221-0312-2D74-F518-FDD1DEC60D19")
ICHashMapClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICHashMapClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICHashMapClassObject*)pObj->Probe(EIID_ICHashMapClassObject);
    }

    static CARAPI_(ICHashMapClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICHashMapClassObject*)pObj->Probe(EIID_ICHashMapClassObject);
    }

    static CARAPI_(ICHashMapClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCapacity(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCapacityLoadFactor(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithMap(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("A501D332-0312-9A74-F518-FDD1DEC60D19")
ICHashSetClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICHashSetClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICHashSetClassObject*)pObj->Probe(EIID_ICHashSetClassObject);
    }

    static CARAPI_(ICHashSetClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICHashSetClassObject*)pObj->Probe(EIID_ICHashSetClassObject);
    }

    static CARAPI_(ICHashSetClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCapacity(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCapacityLoadFactor(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCollection(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithBackingMap(
        /* [in] */ Elastos::Utility::IMap * backingMap,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("9AACBB2F-0312-BD74-F518-FDD1DEC60D19")
ICHashTableClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICHashTableClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICHashTableClassObject*)pObj->Probe(EIID_ICHashTableClassObject);
    }

    static CARAPI_(ICHashTableClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICHashTableClassObject*)pObj->Probe(EIID_ICHashTableClassObject);
    }

    static CARAPI_(ICHashTableClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCapacity(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCapacityLoadFactor(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithBackingMap(
        /* [in] */ Elastos::Utility::IMap * backingMap,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("2D89E52C-0312-FA8C-D1B5-D463F4477B1B")
ICLinkedHashMapClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICLinkedHashMapClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICLinkedHashMapClassObject*)pObj->Probe(EIID_ICLinkedHashMapClassObject);
    }

    static CARAPI_(ICLinkedHashMapClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICLinkedHashMapClassObject*)pObj->Probe(EIID_ICLinkedHashMapClassObject);
    }

    static CARAPI_(ICLinkedHashMapClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCapacity(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCapacityLoadFactor(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCapacityLoadFactorAccessOrder(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [in] */ _ELASTOS Boolean accessOrder,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithMap(
        /* [in] */ Elastos::Utility::IMap * Map,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("ABBFBF31-0312-FA8C-D169-D663F4477B1B")
ICLinkedHashSetClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICLinkedHashSetClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICLinkedHashSetClassObject*)pObj->Probe(EIID_ICLinkedHashSetClassObject);
    }

    static CARAPI_(ICLinkedHashSetClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICLinkedHashSetClassObject*)pObj->Probe(EIID_ICLinkedHashSetClassObject);
    }

    static CARAPI_(ICLinkedHashSetClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCapacity(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCapacityLoadFactor(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCollection(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("C996822A-0312-FA8C-35EA-31FAA3BD8D1B")
ICLinkedListClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICLinkedListClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICLinkedListClassObject*)pObj->Probe(EIID_ICLinkedListClassObject);
    }

    static CARAPI_(ICLinkedListClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICLinkedListClassObject*)pObj->Probe(EIID_ICLinkedListClassObject);
    }

    static CARAPI_(ICLinkedListClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCollection(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("CB3FBF3D-8312-280F-4CDC-C8AFC7E88FF6")
ICVectorClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICVectorClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICVectorClassObject*)pObj->Probe(EIID_ICVectorClassObject);
    }

    static CARAPI_(ICVectorClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICVectorClassObject*)pObj->Probe(EIID_ICVectorClassObject);
    }

    static CARAPI_(ICVectorClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCapacity(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCapacityCapacityIncrement(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Int32 capacityIncrement,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCollection(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("8F2D6338-0312-370E-4898-70A1C7E88FF6")
ICStackClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICStackClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICStackClassObject*)pObj->Probe(EIID_ICStackClassObject);
    }

    static CARAPI_(ICStackClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICStackClassObject*)pObj->Probe(EIID_ICStackClassObject);
    }

    static CARAPI_(ICStackClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("9C9DB63A-0312-2810-48B8-40D7528FD11F")
ICWeakHashMapClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICWeakHashMapClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICWeakHashMapClassObject*)pObj->Probe(EIID_ICWeakHashMapClassObject);
    }

    static CARAPI_(ICWeakHashMapClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICWeakHashMapClassObject*)pObj->Probe(EIID_ICWeakHashMapClassObject);
    }

    static CARAPI_(ICWeakHashMapClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCapacity(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCapacityLoadFactor(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithMap(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("322AB22D-8312-350E-50A0-68A9C7E88FF6")
ICTreeMapClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICTreeMapClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICTreeMapClassObject*)pObj->Probe(EIID_ICTreeMapClassObject);
    }

    static CARAPI_(ICTreeMapClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICTreeMapClassObject*)pObj->Probe(EIID_ICTreeMapClassObject);
    }

    static CARAPI_(ICTreeMapClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCopyFrommap(
        /* [in] */ Elastos::Utility::IMap * copyFrommap,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithComparator(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCopyFrom(
        /* [in] */ Elastos::Utility::ISortedMap * copyFrom,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("43AFBB2B-8312-350E-50A0-D0ACC7E88FF6")
ICTreeSetClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICTreeSetClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICTreeSetClassObject*)pObj->Probe(EIID_ICTreeSetClassObject);
    }

    static CARAPI_(ICTreeSetClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICTreeSetClassObject*)pObj->Probe(EIID_ICTreeSetClassObject);
    }

    static CARAPI_(ICTreeSetClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithNavmap(
        /* [in] */ Elastos::Utility::INavigableMap * navmap,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithMap(
        /* [in] */ Elastos::Utility::ICollection * map,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithComparator(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithSet(
        /* [in] */ Elastos::Utility::ISortedSet * set,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("7D49ED3A-8312-1AB5-70A0-C081428FD11F")
ICPriorityQueueClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPriorityQueueClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPriorityQueueClassObject*)pObj->Probe(EIID_ICPriorityQueueClassObject);
    }

    static CARAPI_(ICPriorityQueueClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPriorityQueueClassObject*)pObj->Probe(EIID_ICPriorityQueueClassObject);
    }

    static CARAPI_(ICPriorityQueueClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithInitialCapacity(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithInitialCapacityComparator(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCo(
        /* [in] */ Elastos::Utility::ICollection * co,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithQueue(
        /* [in] */ Elastos::Utility::IPriorityQueue * queue,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithSet(
        /* [in] */ Elastos::Utility::ISortedSet * set,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("69828125-8312-3808-54A0-30A6598FD11F")
ICHugeEnumSetClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICHugeEnumSetClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICHugeEnumSetClassObject*)pObj->Probe(EIID_ICHugeEnumSetClassObject);
    }

    static CARAPI_(ICHugeEnumSetClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICHugeEnumSetClassObject*)pObj->Probe(EIID_ICHugeEnumSetClassObject);
    }

    static CARAPI_(ICHugeEnumSetClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithClsEnums(
        /* [in] */ const _ELASTOS InterfaceID & cls,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * enums,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("7176813A-0312-2C9B-8C69-D663F4477B1B")
ICMiniEnumSetClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICMiniEnumSetClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICMiniEnumSetClassObject*)pObj->Probe(EIID_ICMiniEnumSetClassObject);
    }

    static CARAPI_(ICMiniEnumSetClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICMiniEnumSetClassObject*)pObj->Probe(EIID_ICMiniEnumSetClassObject);
    }

    static CARAPI_(ICMiniEnumSetClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithClsEnums(
        /* [in] */ const _ELASTOS InterfaceID & cls,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * enums,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("1BDA973A-0312-310F-6C90-4881028B463D")
ICUnsafeArrayListClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICUnsafeArrayListClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICUnsafeArrayListClassObject*)pObj->Probe(EIID_ICUnsafeArrayListClassObject);
    }

    static CARAPI_(ICUnsafeArrayListClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICUnsafeArrayListClassObject*)pObj->Probe(EIID_ICUnsafeArrayListClassObject);
    }

    static CARAPI_(ICUnsafeArrayListClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithElementTypeInitialCapacity(
        /* [in] */ const _ELASTOS InterfaceID & elementType,
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("4FE1692E-0312-3206-5EBC-406102BE0D3D")
ICCollectionsClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICCollectionsClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCollectionsClassObject*)pObj->Probe(EIID_ICCollectionsClassObject);
    }

    static CARAPI_(ICCollectionsClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICCollectionsClassObject*)pObj->Probe(EIID_ICCollectionsClassObject);
    }

    static CARAPI_(ICCollectionsClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Utility {
CAR_INTERFACE("0B836B3F-0312-9A63-23A0-7831E3BE1EA3")
ICEnumSetHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICEnumSetHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICEnumSetHelperClassObject*)pObj->Probe(EIID_ICEnumSetHelperClassObject);
    }

    static CARAPI_(ICEnumSetHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICEnumSetHelperClassObject*)pObj->Probe(EIID_ICEnumSetHelperClassObject);
    }

    static CARAPI_(ICEnumSetHelperClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Utility {
namespace Regex {
CAR_INTERFACE("44C26F24-0312-F797-F518-FDD1DEC60D19")
ICMatcherClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICMatcherClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICMatcherClassObject*)pObj->Probe(EIID_ICMatcherClassObject);
    }

    static CARAPI_(ICMatcherClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICMatcherClassObject*)pObj->Probe(EIID_ICMatcherClassObject);
    }

    static CARAPI_(ICMatcherClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithPatternInputSeq(
        /* [in] */ Elastos::Utility::Regex::IPattern * pattern,
        /* [in] */ Elastos::Core::ICharSequence * inputSeq,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}

namespace Elastos {
namespace Utility {
namespace Regex {
CAR_INTERFACE("F06F7125-0312-F797-23A0-7831E3BE1EA3")
ICMatcherHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICMatcherHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICMatcherHelperClassObject*)pObj->Probe(EIID_ICMatcherHelperClassObject);
    }

    static CARAPI_(ICMatcherHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICMatcherHelperClassObject*)pObj->Probe(EIID_ICMatcherHelperClassObject);
    }

    static CARAPI_(ICMatcherHelperClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}

namespace Elastos {
namespace Utility {
namespace Regex {
CAR_INTERFACE("26096C2F-0312-330E-5EB0-B871E3BE1EA3")
ICSplitterClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICSplitterClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSplitterClassObject*)pObj->Probe(EIID_ICSplitterClassObject);
    }

    static CARAPI_(ICSplitterClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICSplitterClassObject*)pObj->Probe(EIID_ICSplitterClassObject);
    }

    static CARAPI_(ICSplitterClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}

namespace Elastos {
namespace Utility {
namespace Regex {
CAR_INTERFACE("D273710F-9312-F791-8DD6-7184BE335A33")
ICPatternHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPatternHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPatternHelperClassObject*)pObj->Probe(EIID_ICPatternHelperClassObject);
    }

    static CARAPI_(ICPatternHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPatternHelperClassObject*)pObj->Probe(EIID_ICPatternHelperClassObject);
    }

    static CARAPI_(ICPatternHelperClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Utility {
class CStringTokenizer
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& string,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICStringTokenizerClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CStringTokenizer, RGM_SAME_DOMAIN,
                EIID_ICStringTokenizerClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithString(string, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& string,
        /* [in] */ const _ELASTOS String& delimiters,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICStringTokenizerClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CStringTokenizer, RGM_SAME_DOMAIN,
                EIID_ICStringTokenizerClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithStringDelimiters(string, delimiters, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& string,
        /* [in] */ const _ELASTOS String& delimiters,
        /* [in] */ _ELASTOS Boolean returnDelimiters,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICStringTokenizerClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CStringTokenizer, RGM_SAME_DOMAIN,
                EIID_ICStringTokenizerClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithStringDelimitersReturnDelimiters(string, delimiters, returnDelimiters, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& string,
        /* [out] */ Elastos::Utility::IStringTokenizer** __IStringTokenizer)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(string, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IStringTokenizer = (Elastos::Utility::IStringTokenizer*)__pNewObj->Probe(Elastos::Utility::EIID_IStringTokenizer);
        if (*__IStringTokenizer) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& string,
        /* [out] */ Elastos::Utility::IEnumeration** __IEnumeration)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(string, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IEnumeration = (Elastos::Utility::IEnumeration*)__pNewObj->Probe(Elastos::Utility::EIID_IEnumeration);
        if (*__IEnumeration) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& string,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(string, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& string,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(string, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& string,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(string, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& string,
        /* [in] */ const _ELASTOS String& delimiters,
        /* [out] */ Elastos::Utility::IStringTokenizer** __IStringTokenizer)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(string, delimiters, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IStringTokenizer = (Elastos::Utility::IStringTokenizer*)__pNewObj->Probe(Elastos::Utility::EIID_IStringTokenizer);
        if (*__IStringTokenizer) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& string,
        /* [in] */ const _ELASTOS String& delimiters,
        /* [out] */ Elastos::Utility::IEnumeration** __IEnumeration)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(string, delimiters, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IEnumeration = (Elastos::Utility::IEnumeration*)__pNewObj->Probe(Elastos::Utility::EIID_IEnumeration);
        if (*__IEnumeration) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& string,
        /* [in] */ const _ELASTOS String& delimiters,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(string, delimiters, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& string,
        /* [in] */ const _ELASTOS String& delimiters,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(string, delimiters, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& string,
        /* [in] */ const _ELASTOS String& delimiters,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(string, delimiters, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& string,
        /* [in] */ const _ELASTOS String& delimiters,
        /* [in] */ _ELASTOS Boolean returnDelimiters,
        /* [out] */ Elastos::Utility::IStringTokenizer** __IStringTokenizer)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(string, delimiters, returnDelimiters, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IStringTokenizer = (Elastos::Utility::IStringTokenizer*)__pNewObj->Probe(Elastos::Utility::EIID_IStringTokenizer);
        if (*__IStringTokenizer) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& string,
        /* [in] */ const _ELASTOS String& delimiters,
        /* [in] */ _ELASTOS Boolean returnDelimiters,
        /* [out] */ Elastos::Utility::IEnumeration** __IEnumeration)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(string, delimiters, returnDelimiters, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IEnumeration = (Elastos::Utility::IEnumeration*)__pNewObj->Probe(Elastos::Utility::EIID_IEnumeration);
        if (*__IEnumeration) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& string,
        /* [in] */ const _ELASTOS String& delimiters,
        /* [in] */ _ELASTOS Boolean returnDelimiters,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(string, delimiters, returnDelimiters, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& string,
        /* [in] */ const _ELASTOS String& delimiters,
        /* [in] */ _ELASTOS Boolean returnDelimiters,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(string, delimiters, returnDelimiters, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& string,
        /* [in] */ const _ELASTOS String& delimiters,
        /* [in] */ _ELASTOS Boolean returnDelimiters,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(string, delimiters, returnDelimiters, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Utility {
class CArrayDeque
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 numElements,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICArrayDequeClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CArrayDeque, RGM_SAME_DOMAIN,
                EIID_ICArrayDequeClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithNumElements(numElements, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICArrayDequeClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CArrayDeque, RGM_SAME_DOMAIN,
                EIID_ICArrayDequeClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithC(c, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IArrayDeque** __object)
    {
        return _CObject_CreateInstance(ECLSID_CArrayDeque, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IArrayDeque, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ICollection** __object)
    {
        return _CObject_CreateInstance(ECLSID_CArrayDeque, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ICollection, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IIterable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CArrayDeque, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IIterable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IDeque** __object)
    {
        return _CObject_CreateInstance(ECLSID_CArrayDeque, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IDeque, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ICloneable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CArrayDeque, RGM_SAME_DOMAIN, Elastos::Core::EIID_ICloneable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CArrayDeque, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CArrayDeque, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CArrayDeque, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 numElements,
        /* [out] */ Elastos::Utility::IArrayDeque** __IArrayDeque)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(numElements, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IArrayDeque = (Elastos::Utility::IArrayDeque*)__pNewObj->Probe(Elastos::Utility::EIID_IArrayDeque);
        if (*__IArrayDeque) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 numElements,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(numElements, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 numElements,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(numElements, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 numElements,
        /* [out] */ Elastos::Utility::IDeque** __IDeque)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(numElements, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDeque = (Elastos::Utility::IDeque*)__pNewObj->Probe(Elastos::Utility::EIID_IDeque);
        if (*__IDeque) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 numElements,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(numElements, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 numElements,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(numElements, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 numElements,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(numElements, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 numElements,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(numElements, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::IArrayDeque** __IArrayDeque)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IArrayDeque = (Elastos::Utility::IArrayDeque*)__pNewObj->Probe(Elastos::Utility::EIID_IArrayDeque);
        if (*__IArrayDeque) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::IDeque** __IDeque)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDeque = (Elastos::Utility::IDeque*)__pNewObj->Probe(Elastos::Utility::EIID_IDeque);
        if (*__IDeque) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Utility {
class CArrayList
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICArrayListClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CArrayList, RGM_SAME_DOMAIN,
                EIID_ICArrayListClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCapacity(capacity, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICArrayListClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CArrayList, RGM_SAME_DOMAIN,
                EIID_ICArrayListClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithC(c, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IArrayList** __object)
    {
        return _CObject_CreateInstance(ECLSID_CArrayList, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IArrayList, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IList** __object)
    {
        return _CObject_CreateInstance(ECLSID_CArrayList, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IList, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ICollection** __object)
    {
        return _CObject_CreateInstance(ECLSID_CArrayList, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ICollection, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IIterable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CArrayList, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IIterable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ICloneable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CArrayList, RGM_SAME_DOMAIN, Elastos::Core::EIID_ICloneable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IRandomAccess** __object)
    {
        return _CObject_CreateInstance(ECLSID_CArrayList, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IRandomAccess, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CArrayList, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CArrayList, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CArrayList, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::IArrayList** __IArrayList)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IArrayList = (Elastos::Utility::IArrayList*)__pNewObj->Probe(Elastos::Utility::EIID_IArrayList);
        if (*__IArrayList) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::IList** __IList)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IList = (Elastos::Utility::IList*)__pNewObj->Probe(Elastos::Utility::EIID_IList);
        if (*__IList) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::IRandomAccess** __IRandomAccess)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRandomAccess = (Elastos::Utility::IRandomAccess*)__pNewObj->Probe(Elastos::Utility::EIID_IRandomAccess);
        if (*__IRandomAccess) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::IArrayList** __IArrayList)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IArrayList = (Elastos::Utility::IArrayList*)__pNewObj->Probe(Elastos::Utility::EIID_IArrayList);
        if (*__IArrayList) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::IList** __IList)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IList = (Elastos::Utility::IList*)__pNewObj->Probe(Elastos::Utility::EIID_IList);
        if (*__IList) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Utility::IRandomAccess** __IRandomAccess)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRandomAccess = (Elastos::Utility::IRandomAccess*)__pNewObj->Probe(Elastos::Utility::EIID_IRandomAccess);
        if (*__IRandomAccess) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * c,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(c, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Utility {
class CArrayListIterator
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::IArrayList * list,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICArrayListIteratorClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CArrayListIterator, RGM_SAME_DOMAIN,
                EIID_ICArrayListIteratorClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithList(list, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IArrayList * list,
        /* [out] */ Elastos::Utility::IIterator** __IIterator)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(list, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterator = (Elastos::Utility::IIterator*)__pNewObj->Probe(Elastos::Utility::EIID_IIterator);
        if (*__IIterator) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IArrayList * list,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(list, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IArrayList * list,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(list, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IArrayList * list,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(list, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Utility {
class CSimpleListIterator
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::IList * list,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSimpleListIteratorClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSimpleListIterator, RGM_SAME_DOMAIN,
                EIID_ICSimpleListIteratorClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithList(list, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IList * list,
        /* [out] */ Elastos::Utility::IIterator** __IIterator)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(list, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterator = (Elastos::Utility::IIterator*)__pNewObj->Probe(Elastos::Utility::EIID_IIterator);
        if (*__IIterator) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IList * list,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(list, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IList * list,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(list, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IList * list,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(list, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Utility {
class CFullListIterator
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ _ELASTOS Int32 start,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICFullListIteratorClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CFullListIterator, RGM_SAME_DOMAIN,
                EIID_ICFullListIteratorClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithListStart(list, start, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ _ELASTOS Int32 start,
        /* [out] */ Elastos::Utility::IIterator** __IIterator)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(list, start, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterator = (Elastos::Utility::IIterator*)__pNewObj->Probe(Elastos::Utility::EIID_IIterator);
        if (*__IIterator) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ _ELASTOS Int32 start,
        /* [out] */ Elastos::Utility::IListIterator** __IListIterator)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(list, start, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IListIterator = (Elastos::Utility::IListIterator*)__pNewObj->Probe(Elastos::Utility::EIID_IListIterator);
        if (*__IListIterator) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ _ELASTOS Int32 start,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(list, start, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ _ELASTOS Int32 start,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(list, start, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ _ELASTOS Int32 start,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(list, start, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Utility {
class CSubAbstractListIterator
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ Elastos::Utility::IListIterator * it,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSubAbstractListIteratorClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSubAbstractListIterator, RGM_SAME_DOMAIN,
                EIID_ICSubAbstractListIteratorClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithListItOffsetLength(list, it, offset, length, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ Elastos::Utility::IListIterator * it,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ Elastos::Utility::IIterator** __IIterator)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(list, it, offset, length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterator = (Elastos::Utility::IIterator*)__pNewObj->Probe(Elastos::Utility::EIID_IIterator);
        if (*__IIterator) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ Elastos::Utility::IListIterator * it,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ Elastos::Utility::IListIterator** __IListIterator)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(list, it, offset, length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IListIterator = (Elastos::Utility::IListIterator*)__pNewObj->Probe(Elastos::Utility::EIID_IListIterator);
        if (*__IListIterator) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ Elastos::Utility::IListIterator * it,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(list, it, offset, length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ Elastos::Utility::IListIterator * it,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(list, it, offset, length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ Elastos::Utility::IListIterator * it,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(list, it, offset, length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Utility {
class CSubAbstractList
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICSubAbstractListClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CSubAbstractList, RGM_SAME_DOMAIN,
                EIID_ICSubAbstractListClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithListStartEnd(list, start, end, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ Elastos::Utility::IList** __IList)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(list, start, end, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IList = (Elastos::Utility::IList*)__pNewObj->Probe(Elastos::Utility::EIID_IList);
        if (*__IList) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(list, start, end, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(list, start, end, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(list, start, end, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(list, start, end, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(list, start, end, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Utility {
class CRandomAccessSubList
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICRandomAccessSubListClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CRandomAccessSubList, RGM_SAME_DOMAIN,
                EIID_ICRandomAccessSubListClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithListStartEnd(list, start, end, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ Elastos::Utility::IRandomAccess** __IRandomAccess)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(list, start, end, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRandomAccess = (Elastos::Utility::IRandomAccess*)__pNewObj->Probe(Elastos::Utility::EIID_IRandomAccess);
        if (*__IRandomAccess) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ Elastos::Utility::IList** __IList)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(list, start, end, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IList = (Elastos::Utility::IList*)__pNewObj->Probe(Elastos::Utility::EIID_IList);
        if (*__IList) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(list, start, end, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(list, start, end, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(list, start, end, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(list, start, end, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IList * list,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(list, start, end, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Utility {
class CBitSet
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 bitCount,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBitSetClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBitSet, RGM_SAME_DOMAIN,
                EIID_ICBitSetClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithBitCount(bitCount, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int64> * array,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBitSetClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBitSet, RGM_SAME_DOMAIN,
                EIID_ICBitSetClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithArray(array, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IBitSet** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBitSet, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IBitSet, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ICloneable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBitSet, RGM_SAME_DOMAIN, Elastos::Core::EIID_ICloneable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBitSet, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBitSet, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBitSet, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 bitCount,
        /* [out] */ Elastos::Utility::IBitSet** __IBitSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(bitCount, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBitSet = (Elastos::Utility::IBitSet*)__pNewObj->Probe(Elastos::Utility::EIID_IBitSet);
        if (*__IBitSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 bitCount,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(bitCount, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 bitCount,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(bitCount, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 bitCount,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(bitCount, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 bitCount,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(bitCount, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int64> * array,
        /* [out] */ Elastos::Utility::IBitSet** __IBitSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(array, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBitSet = (Elastos::Utility::IBitSet*)__pNewObj->Probe(Elastos::Utility::EIID_IBitSet);
        if (*__IBitSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int64> * array,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(array, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int64> * array,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(array, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int64> * array,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(array, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int64> * array,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(array, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Utility {
class CBitSetHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Utility::IBitSetHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBitSetHelper, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IBitSetHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBitSetHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBitSetHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBitSetHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Utility {
class CEnumMap
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS InterfaceID & keyType,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICEnumMapClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CEnumMap, RGM_SAME_DOMAIN,
                EIID_ICEnumMapClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithKeyType(keyType, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::IEnumMap * enummap,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICEnumMapClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CEnumMap, RGM_SAME_DOMAIN,
                EIID_ICEnumMapClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithEnummap(enummap, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICEnumMapClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CEnumMap, RGM_SAME_DOMAIN,
                EIID_ICEnumMapClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithMap(map, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IEnumMap** __object)
    {
        return _CObject_CreateInstance(ECLSID_CEnumMap, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IEnumMap, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ICloneable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CEnumMap, RGM_SAME_DOMAIN, Elastos::Core::EIID_ICloneable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IMap** __object)
    {
        return _CObject_CreateInstance(ECLSID_CEnumMap, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IMap, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CEnumMap, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CEnumMap, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CEnumMap, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS InterfaceID & keyType,
        /* [out] */ Elastos::Utility::IEnumMap** __IEnumMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyType, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IEnumMap = (Elastos::Utility::IEnumMap*)__pNewObj->Probe(Elastos::Utility::EIID_IEnumMap);
        if (*__IEnumMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS InterfaceID & keyType,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyType, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS InterfaceID & keyType,
        /* [out] */ Elastos::Utility::IMap** __IMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyType, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMap = (Elastos::Utility::IMap*)__pNewObj->Probe(Elastos::Utility::EIID_IMap);
        if (*__IMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS InterfaceID & keyType,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyType, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS InterfaceID & keyType,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyType, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS InterfaceID & keyType,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(keyType, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IEnumMap * enummap,
        /* [out] */ Elastos::Utility::IEnumMap** __IEnumMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(enummap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IEnumMap = (Elastos::Utility::IEnumMap*)__pNewObj->Probe(Elastos::Utility::EIID_IEnumMap);
        if (*__IEnumMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IEnumMap * enummap,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(enummap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IEnumMap * enummap,
        /* [out] */ Elastos::Utility::IMap** __IMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(enummap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMap = (Elastos::Utility::IMap*)__pNewObj->Probe(Elastos::Utility::EIID_IMap);
        if (*__IMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IEnumMap * enummap,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(enummap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IEnumMap * enummap,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(enummap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IEnumMap * enummap,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(enummap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ Elastos::Utility::IEnumMap** __IEnumMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IEnumMap = (Elastos::Utility::IEnumMap*)__pNewObj->Probe(Elastos::Utility::EIID_IEnumMap);
        if (*__IEnumMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ Elastos::Utility::IMap** __IMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMap = (Elastos::Utility::IMap*)__pNewObj->Probe(Elastos::Utility::EIID_IMap);
        if (*__IMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Utility {
class CHashMap
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICHashMapClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CHashMap, RGM_SAME_DOMAIN,
                EIID_ICHashMapClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCapacity(capacity, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICHashMapClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CHashMap, RGM_SAME_DOMAIN,
                EIID_ICHashMapClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCapacityLoadFactor(capacity, loadFactor, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICHashMapClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CHashMap, RGM_SAME_DOMAIN,
                EIID_ICHashMapClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithMap(map, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IHashMap** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHashMap, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IHashMap, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IMap** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHashMap, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IMap, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ICloneable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHashMap, RGM_SAME_DOMAIN, Elastos::Core::EIID_ICloneable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHashMap, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHashMap, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHashMap, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::IHashMap** __IHashMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IHashMap = (Elastos::Utility::IHashMap*)__pNewObj->Probe(Elastos::Utility::EIID_IHashMap);
        if (*__IHashMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::IMap** __IMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMap = (Elastos::Utility::IMap*)__pNewObj->Probe(Elastos::Utility::EIID_IMap);
        if (*__IMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ Elastos::Utility::IHashMap** __IHashMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IHashMap = (Elastos::Utility::IHashMap*)__pNewObj->Probe(Elastos::Utility::EIID_IHashMap);
        if (*__IHashMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ Elastos::Utility::IMap** __IMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMap = (Elastos::Utility::IMap*)__pNewObj->Probe(Elastos::Utility::EIID_IMap);
        if (*__IMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ Elastos::Utility::IHashMap** __IHashMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IHashMap = (Elastos::Utility::IHashMap*)__pNewObj->Probe(Elastos::Utility::EIID_IHashMap);
        if (*__IHashMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ Elastos::Utility::IMap** __IMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMap = (Elastos::Utility::IMap*)__pNewObj->Probe(Elastos::Utility::EIID_IMap);
        if (*__IMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Utility {
class CHashSet
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICHashSetClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CHashSet, RGM_SAME_DOMAIN,
                EIID_ICHashSetClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCapacity(capacity, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICHashSetClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CHashSet, RGM_SAME_DOMAIN,
                EIID_ICHashSetClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCapacityLoadFactor(capacity, loadFactor, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICHashSetClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CHashSet, RGM_SAME_DOMAIN,
                EIID_ICHashSetClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCollection(collection, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::IMap * backingMap,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICHashSetClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CHashSet, RGM_SAME_DOMAIN,
                EIID_ICHashSetClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithBackingMap(backingMap, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IHashSet** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHashSet, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IHashSet, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ISet** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHashSet, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ISet, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ICollection** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHashSet, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ICollection, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IIterable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHashSet, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IIterable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ICloneable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHashSet, RGM_SAME_DOMAIN, Elastos::Core::EIID_ICloneable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHashSet, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHashSet, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHashSet, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::IHashSet** __IHashSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IHashSet = (Elastos::Utility::IHashSet*)__pNewObj->Probe(Elastos::Utility::EIID_IHashSet);
        if (*__IHashSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::ISet** __ISet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISet = (Elastos::Utility::ISet*)__pNewObj->Probe(Elastos::Utility::EIID_ISet);
        if (*__ISet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ Elastos::Utility::IHashSet** __IHashSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IHashSet = (Elastos::Utility::IHashSet*)__pNewObj->Probe(Elastos::Utility::EIID_IHashSet);
        if (*__IHashSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ Elastos::Utility::ISet** __ISet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISet = (Elastos::Utility::ISet*)__pNewObj->Probe(Elastos::Utility::EIID_ISet);
        if (*__ISet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Utility::IHashSet** __IHashSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IHashSet = (Elastos::Utility::IHashSet*)__pNewObj->Probe(Elastos::Utility::EIID_IHashSet);
        if (*__IHashSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Utility::ISet** __ISet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISet = (Elastos::Utility::ISet*)__pNewObj->Probe(Elastos::Utility::EIID_ISet);
        if (*__ISet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * backingMap,
        /* [out] */ Elastos::Utility::IHashSet** __IHashSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(backingMap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IHashSet = (Elastos::Utility::IHashSet*)__pNewObj->Probe(Elastos::Utility::EIID_IHashSet);
        if (*__IHashSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * backingMap,
        /* [out] */ Elastos::Utility::ISet** __ISet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(backingMap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISet = (Elastos::Utility::ISet*)__pNewObj->Probe(Elastos::Utility::EIID_ISet);
        if (*__ISet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * backingMap,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(backingMap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * backingMap,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(backingMap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * backingMap,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(backingMap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * backingMap,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(backingMap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * backingMap,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(backingMap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * backingMap,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(backingMap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Utility {
class CHashTable
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICHashTableClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CHashTable, RGM_SAME_DOMAIN,
                EIID_ICHashTableClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCapacity(capacity, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICHashTableClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CHashTable, RGM_SAME_DOMAIN,
                EIID_ICHashTableClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCapacityLoadFactor(capacity, loadFactor, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::IMap * backingMap,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICHashTableClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CHashTable, RGM_SAME_DOMAIN,
                EIID_ICHashTableClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithBackingMap(backingMap, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IHashTable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHashTable, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IHashTable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IDictionary** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHashTable, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IDictionary, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IMap** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHashTable, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IMap, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ICloneable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHashTable, RGM_SAME_DOMAIN, Elastos::Core::EIID_ICloneable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHashTable, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHashTable, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHashTable, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::IHashTable** __IHashTable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IHashTable = (Elastos::Utility::IHashTable*)__pNewObj->Probe(Elastos::Utility::EIID_IHashTable);
        if (*__IHashTable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::IDictionary** __IDictionary)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDictionary = (Elastos::Utility::IDictionary*)__pNewObj->Probe(Elastos::Utility::EIID_IDictionary);
        if (*__IDictionary) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::IMap** __IMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMap = (Elastos::Utility::IMap*)__pNewObj->Probe(Elastos::Utility::EIID_IMap);
        if (*__IMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ Elastos::Utility::IHashTable** __IHashTable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IHashTable = (Elastos::Utility::IHashTable*)__pNewObj->Probe(Elastos::Utility::EIID_IHashTable);
        if (*__IHashTable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ Elastos::Utility::IDictionary** __IDictionary)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDictionary = (Elastos::Utility::IDictionary*)__pNewObj->Probe(Elastos::Utility::EIID_IDictionary);
        if (*__IDictionary) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ Elastos::Utility::IMap** __IMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMap = (Elastos::Utility::IMap*)__pNewObj->Probe(Elastos::Utility::EIID_IMap);
        if (*__IMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * backingMap,
        /* [out] */ Elastos::Utility::IHashTable** __IHashTable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(backingMap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IHashTable = (Elastos::Utility::IHashTable*)__pNewObj->Probe(Elastos::Utility::EIID_IHashTable);
        if (*__IHashTable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * backingMap,
        /* [out] */ Elastos::Utility::IDictionary** __IDictionary)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(backingMap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDictionary = (Elastos::Utility::IDictionary*)__pNewObj->Probe(Elastos::Utility::EIID_IDictionary);
        if (*__IDictionary) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * backingMap,
        /* [out] */ Elastos::Utility::IMap** __IMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(backingMap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMap = (Elastos::Utility::IMap*)__pNewObj->Probe(Elastos::Utility::EIID_IMap);
        if (*__IMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * backingMap,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(backingMap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * backingMap,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(backingMap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * backingMap,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(backingMap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * backingMap,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(backingMap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Utility {
class CLinkedHashMap
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICLinkedHashMapClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CLinkedHashMap, RGM_SAME_DOMAIN,
                EIID_ICLinkedHashMapClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCapacity(capacity, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICLinkedHashMapClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CLinkedHashMap, RGM_SAME_DOMAIN,
                EIID_ICLinkedHashMapClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCapacityLoadFactor(capacity, loadFactor, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [in] */ _ELASTOS Boolean accessOrder,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICLinkedHashMapClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CLinkedHashMap, RGM_SAME_DOMAIN,
                EIID_ICLinkedHashMapClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCapacityLoadFactorAccessOrder(capacity, loadFactor, accessOrder, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::IMap * Map,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICLinkedHashMapClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CLinkedHashMap, RGM_SAME_DOMAIN,
                EIID_ICLinkedHashMapClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithMap(Map, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ILinkedHashMap** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedHashMap, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ILinkedHashMap, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IHashMap** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedHashMap, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IHashMap, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IMap** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedHashMap, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IMap, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ICloneable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedHashMap, RGM_SAME_DOMAIN, Elastos::Core::EIID_ICloneable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedHashMap, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedHashMap, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedHashMap, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::ILinkedHashMap** __ILinkedHashMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ILinkedHashMap = (Elastos::Utility::ILinkedHashMap*)__pNewObj->Probe(Elastos::Utility::EIID_ILinkedHashMap);
        if (*__ILinkedHashMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::IHashMap** __IHashMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IHashMap = (Elastos::Utility::IHashMap*)__pNewObj->Probe(Elastos::Utility::EIID_IHashMap);
        if (*__IHashMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::IMap** __IMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMap = (Elastos::Utility::IMap*)__pNewObj->Probe(Elastos::Utility::EIID_IMap);
        if (*__IMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ Elastos::Utility::ILinkedHashMap** __ILinkedHashMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ILinkedHashMap = (Elastos::Utility::ILinkedHashMap*)__pNewObj->Probe(Elastos::Utility::EIID_ILinkedHashMap);
        if (*__ILinkedHashMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ Elastos::Utility::IHashMap** __IHashMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IHashMap = (Elastos::Utility::IHashMap*)__pNewObj->Probe(Elastos::Utility::EIID_IHashMap);
        if (*__IHashMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ Elastos::Utility::IMap** __IMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMap = (Elastos::Utility::IMap*)__pNewObj->Probe(Elastos::Utility::EIID_IMap);
        if (*__IMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [in] */ _ELASTOS Boolean accessOrder,
        /* [out] */ Elastos::Utility::ILinkedHashMap** __ILinkedHashMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, accessOrder, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ILinkedHashMap = (Elastos::Utility::ILinkedHashMap*)__pNewObj->Probe(Elastos::Utility::EIID_ILinkedHashMap);
        if (*__ILinkedHashMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [in] */ _ELASTOS Boolean accessOrder,
        /* [out] */ Elastos::Utility::IHashMap** __IHashMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, accessOrder, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IHashMap = (Elastos::Utility::IHashMap*)__pNewObj->Probe(Elastos::Utility::EIID_IHashMap);
        if (*__IHashMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [in] */ _ELASTOS Boolean accessOrder,
        /* [out] */ Elastos::Utility::IMap** __IMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, accessOrder, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMap = (Elastos::Utility::IMap*)__pNewObj->Probe(Elastos::Utility::EIID_IMap);
        if (*__IMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [in] */ _ELASTOS Boolean accessOrder,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, accessOrder, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [in] */ _ELASTOS Boolean accessOrder,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, accessOrder, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [in] */ _ELASTOS Boolean accessOrder,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, accessOrder, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [in] */ _ELASTOS Boolean accessOrder,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, accessOrder, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * Map,
        /* [out] */ Elastos::Utility::ILinkedHashMap** __ILinkedHashMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(Map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ILinkedHashMap = (Elastos::Utility::ILinkedHashMap*)__pNewObj->Probe(Elastos::Utility::EIID_ILinkedHashMap);
        if (*__ILinkedHashMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * Map,
        /* [out] */ Elastos::Utility::IHashMap** __IHashMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(Map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IHashMap = (Elastos::Utility::IHashMap*)__pNewObj->Probe(Elastos::Utility::EIID_IHashMap);
        if (*__IHashMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * Map,
        /* [out] */ Elastos::Utility::IMap** __IMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(Map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMap = (Elastos::Utility::IMap*)__pNewObj->Probe(Elastos::Utility::EIID_IMap);
        if (*__IMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * Map,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(Map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * Map,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(Map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * Map,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(Map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * Map,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(Map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Utility {
class CLinkedHashSet
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICLinkedHashSetClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CLinkedHashSet, RGM_SAME_DOMAIN,
                EIID_ICLinkedHashSetClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCapacity(capacity, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICLinkedHashSetClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CLinkedHashSet, RGM_SAME_DOMAIN,
                EIID_ICLinkedHashSetClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCapacityLoadFactor(capacity, loadFactor, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICLinkedHashSetClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CLinkedHashSet, RGM_SAME_DOMAIN,
                EIID_ICLinkedHashSetClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCollection(collection, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ILinkedHashSet** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedHashSet, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ILinkedHashSet, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IHashSet** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedHashSet, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IHashSet, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ISet** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedHashSet, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ISet, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ICollection** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedHashSet, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ICollection, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ICloneable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedHashSet, RGM_SAME_DOMAIN, Elastos::Core::EIID_ICloneable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedHashSet, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedHashSet, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedHashSet, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::ILinkedHashSet** __ILinkedHashSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ILinkedHashSet = (Elastos::Utility::ILinkedHashSet*)__pNewObj->Probe(Elastos::Utility::EIID_ILinkedHashSet);
        if (*__ILinkedHashSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::IHashSet** __IHashSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IHashSet = (Elastos::Utility::IHashSet*)__pNewObj->Probe(Elastos::Utility::EIID_IHashSet);
        if (*__IHashSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::ISet** __ISet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISet = (Elastos::Utility::ISet*)__pNewObj->Probe(Elastos::Utility::EIID_ISet);
        if (*__ISet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ Elastos::Utility::ILinkedHashSet** __ILinkedHashSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ILinkedHashSet = (Elastos::Utility::ILinkedHashSet*)__pNewObj->Probe(Elastos::Utility::EIID_ILinkedHashSet);
        if (*__ILinkedHashSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ Elastos::Utility::IHashSet** __IHashSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IHashSet = (Elastos::Utility::IHashSet*)__pNewObj->Probe(Elastos::Utility::EIID_IHashSet);
        if (*__IHashSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ Elastos::Utility::ISet** __ISet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISet = (Elastos::Utility::ISet*)__pNewObj->Probe(Elastos::Utility::EIID_ISet);
        if (*__ISet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Utility::ILinkedHashSet** __ILinkedHashSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ILinkedHashSet = (Elastos::Utility::ILinkedHashSet*)__pNewObj->Probe(Elastos::Utility::EIID_ILinkedHashSet);
        if (*__ILinkedHashSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Utility::IHashSet** __IHashSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IHashSet = (Elastos::Utility::IHashSet*)__pNewObj->Probe(Elastos::Utility::EIID_IHashSet);
        if (*__IHashSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Utility::ISet** __ISet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISet = (Elastos::Utility::ISet*)__pNewObj->Probe(Elastos::Utility::EIID_ISet);
        if (*__ISet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Utility {
class CLinkedList
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICLinkedListClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CLinkedList, RGM_SAME_DOMAIN,
                EIID_ICLinkedListClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCollection(collection, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ILinkedList** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedList, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ILinkedList, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IList** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedList, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IList, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ICollection** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedList, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ICollection, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IIterable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedList, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IIterable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IDeque** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedList, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IDeque, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IQueue** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedList, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IQueue, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ICloneable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedList, RGM_SAME_DOMAIN, Elastos::Core::EIID_ICloneable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedList, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedList, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLinkedList, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Utility::ILinkedList** __ILinkedList)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ILinkedList = (Elastos::Utility::ILinkedList*)__pNewObj->Probe(Elastos::Utility::EIID_ILinkedList);
        if (*__ILinkedList) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Utility::IList** __IList)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IList = (Elastos::Utility::IList*)__pNewObj->Probe(Elastos::Utility::EIID_IList);
        if (*__IList) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Utility::IDeque** __IDeque)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDeque = (Elastos::Utility::IDeque*)__pNewObj->Probe(Elastos::Utility::EIID_IDeque);
        if (*__IDeque) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Utility::IQueue** __IQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IQueue = (Elastos::Utility::IQueue*)__pNewObj->Probe(Elastos::Utility::EIID_IQueue);
        if (*__IQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Utility {
class CVector
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICVectorClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CVector, RGM_SAME_DOMAIN,
                EIID_ICVectorClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCapacity(capacity, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Int32 capacityIncrement,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICVectorClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CVector, RGM_SAME_DOMAIN,
                EIID_ICVectorClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCapacityCapacityIncrement(capacity, capacityIncrement, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICVectorClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CVector, RGM_SAME_DOMAIN,
                EIID_ICVectorClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCollection(collection, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IVector** __object)
    {
        return _CObject_CreateInstance(ECLSID_CVector, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IVector, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ICollection** __object)
    {
        return _CObject_CreateInstance(ECLSID_CVector, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ICollection, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IIterable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CVector, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IIterable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IList** __object)
    {
        return _CObject_CreateInstance(ECLSID_CVector, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IList, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IRandomAccess** __object)
    {
        return _CObject_CreateInstance(ECLSID_CVector, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IRandomAccess, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ICloneable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CVector, RGM_SAME_DOMAIN, Elastos::Core::EIID_ICloneable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CVector, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CVector, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CVector, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::IVector** __IVector)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IVector = (Elastos::Utility::IVector*)__pNewObj->Probe(Elastos::Utility::EIID_IVector);
        if (*__IVector) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::IList** __IList)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IList = (Elastos::Utility::IList*)__pNewObj->Probe(Elastos::Utility::EIID_IList);
        if (*__IList) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::IRandomAccess** __IRandomAccess)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRandomAccess = (Elastos::Utility::IRandomAccess*)__pNewObj->Probe(Elastos::Utility::EIID_IRandomAccess);
        if (*__IRandomAccess) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Int32 capacityIncrement,
        /* [out] */ Elastos::Utility::IVector** __IVector)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, capacityIncrement, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IVector = (Elastos::Utility::IVector*)__pNewObj->Probe(Elastos::Utility::EIID_IVector);
        if (*__IVector) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Int32 capacityIncrement,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, capacityIncrement, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Int32 capacityIncrement,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, capacityIncrement, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Int32 capacityIncrement,
        /* [out] */ Elastos::Utility::IList** __IList)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, capacityIncrement, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IList = (Elastos::Utility::IList*)__pNewObj->Probe(Elastos::Utility::EIID_IList);
        if (*__IList) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Int32 capacityIncrement,
        /* [out] */ Elastos::Utility::IRandomAccess** __IRandomAccess)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, capacityIncrement, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRandomAccess = (Elastos::Utility::IRandomAccess*)__pNewObj->Probe(Elastos::Utility::EIID_IRandomAccess);
        if (*__IRandomAccess) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Int32 capacityIncrement,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, capacityIncrement, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Int32 capacityIncrement,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, capacityIncrement, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Int32 capacityIncrement,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, capacityIncrement, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Int32 capacityIncrement,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, capacityIncrement, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Utility::IVector** __IVector)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IVector = (Elastos::Utility::IVector*)__pNewObj->Probe(Elastos::Utility::EIID_IVector);
        if (*__IVector) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Utility::IList** __IList)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IList = (Elastos::Utility::IList*)__pNewObj->Probe(Elastos::Utility::EIID_IList);
        if (*__IList) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Utility::IRandomAccess** __IRandomAccess)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRandomAccess = (Elastos::Utility::IRandomAccess*)__pNewObj->Probe(Elastos::Utility::EIID_IRandomAccess);
        if (*__IRandomAccess) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * collection,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(collection, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Utility {
class CStack
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IStack** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStack, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IStack, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IVector** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStack, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IVector, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ICollection** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStack, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ICollection, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IIterable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStack, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IIterable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IList** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStack, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IList, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IRandomAccess** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStack, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IRandomAccess, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ICloneable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStack, RGM_SAME_DOMAIN, Elastos::Core::EIID_ICloneable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStack, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStack, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CStack, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Utility {
class CWeakHashMap
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICWeakHashMapClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CWeakHashMap, RGM_SAME_DOMAIN,
                EIID_ICWeakHashMapClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCapacity(capacity, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICWeakHashMapClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CWeakHashMap, RGM_SAME_DOMAIN,
                EIID_ICWeakHashMapClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCapacityLoadFactor(capacity, loadFactor, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICWeakHashMapClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CWeakHashMap, RGM_SAME_DOMAIN,
                EIID_ICWeakHashMapClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithMap(map, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IWeakHashMap** __object)
    {
        return _CObject_CreateInstance(ECLSID_CWeakHashMap, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IWeakHashMap, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IMap** __object)
    {
        return _CObject_CreateInstance(ECLSID_CWeakHashMap, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IMap, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CWeakHashMap, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CWeakHashMap, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CWeakHashMap, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::IWeakHashMap** __IWeakHashMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakHashMap = (Elastos::Utility::IWeakHashMap*)__pNewObj->Probe(Elastos::Utility::EIID_IWeakHashMap);
        if (*__IWeakHashMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Utility::IMap** __IMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMap = (Elastos::Utility::IMap*)__pNewObj->Probe(Elastos::Utility::EIID_IMap);
        if (*__IMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ Elastos::Utility::IWeakHashMap** __IWeakHashMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakHashMap = (Elastos::Utility::IWeakHashMap*)__pNewObj->Probe(Elastos::Utility::EIID_IWeakHashMap);
        if (*__IWeakHashMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ Elastos::Utility::IMap** __IMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMap = (Elastos::Utility::IMap*)__pNewObj->Probe(Elastos::Utility::EIID_IMap);
        if (*__IMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 capacity,
        /* [in] */ _ELASTOS Float loadFactor,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(capacity, loadFactor, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ Elastos::Utility::IWeakHashMap** __IWeakHashMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakHashMap = (Elastos::Utility::IWeakHashMap*)__pNewObj->Probe(Elastos::Utility::EIID_IWeakHashMap);
        if (*__IWeakHashMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ Elastos::Utility::IMap** __IMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMap = (Elastos::Utility::IMap*)__pNewObj->Probe(Elastos::Utility::EIID_IMap);
        if (*__IMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * map,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Utility {
class CTreeMap
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::IMap * copyFrommap,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICTreeMapClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CTreeMap, RGM_SAME_DOMAIN,
                EIID_ICTreeMapClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCopyFrommap(copyFrommap, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICTreeMapClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CTreeMap, RGM_SAME_DOMAIN,
                EIID_ICTreeMapClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithComparator(comparator, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::ISortedMap * copyFrom,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICTreeMapClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CTreeMap, RGM_SAME_DOMAIN,
                EIID_ICTreeMapClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCopyFrom(copyFrom, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ITreeMap** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTreeMap, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ITreeMap, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IMap** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTreeMap, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IMap, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ISortedMap** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTreeMap, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ISortedMap, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::INavigableMap** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTreeMap, RGM_SAME_DOMAIN, Elastos::Utility::EIID_INavigableMap, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ICloneable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTreeMap, RGM_SAME_DOMAIN, Elastos::Core::EIID_ICloneable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTreeMap, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTreeMap, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTreeMap, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * copyFrommap,
        /* [out] */ Elastos::Utility::ITreeMap** __ITreeMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(copyFrommap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ITreeMap = (Elastos::Utility::ITreeMap*)__pNewObj->Probe(Elastos::Utility::EIID_ITreeMap);
        if (*__ITreeMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * copyFrommap,
        /* [out] */ Elastos::Utility::IMap** __IMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(copyFrommap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMap = (Elastos::Utility::IMap*)__pNewObj->Probe(Elastos::Utility::EIID_IMap);
        if (*__IMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * copyFrommap,
        /* [out] */ Elastos::Utility::ISortedMap** __ISortedMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(copyFrommap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISortedMap = (Elastos::Utility::ISortedMap*)__pNewObj->Probe(Elastos::Utility::EIID_ISortedMap);
        if (*__ISortedMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * copyFrommap,
        /* [out] */ Elastos::Utility::INavigableMap** __INavigableMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(copyFrommap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INavigableMap = (Elastos::Utility::INavigableMap*)__pNewObj->Probe(Elastos::Utility::EIID_INavigableMap);
        if (*__INavigableMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * copyFrommap,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(copyFrommap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * copyFrommap,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(copyFrommap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * copyFrommap,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(copyFrommap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * copyFrommap,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(copyFrommap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Utility::ITreeMap** __ITreeMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ITreeMap = (Elastos::Utility::ITreeMap*)__pNewObj->Probe(Elastos::Utility::EIID_ITreeMap);
        if (*__ITreeMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Utility::IMap** __IMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMap = (Elastos::Utility::IMap*)__pNewObj->Probe(Elastos::Utility::EIID_IMap);
        if (*__IMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Utility::ISortedMap** __ISortedMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISortedMap = (Elastos::Utility::ISortedMap*)__pNewObj->Probe(Elastos::Utility::EIID_ISortedMap);
        if (*__ISortedMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Utility::INavigableMap** __INavigableMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INavigableMap = (Elastos::Utility::INavigableMap*)__pNewObj->Probe(Elastos::Utility::EIID_INavigableMap);
        if (*__INavigableMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedMap * copyFrom,
        /* [out] */ Elastos::Utility::ITreeMap** __ITreeMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(copyFrom, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ITreeMap = (Elastos::Utility::ITreeMap*)__pNewObj->Probe(Elastos::Utility::EIID_ITreeMap);
        if (*__ITreeMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedMap * copyFrom,
        /* [out] */ Elastos::Utility::IMap** __IMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(copyFrom, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMap = (Elastos::Utility::IMap*)__pNewObj->Probe(Elastos::Utility::EIID_IMap);
        if (*__IMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedMap * copyFrom,
        /* [out] */ Elastos::Utility::ISortedMap** __ISortedMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(copyFrom, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISortedMap = (Elastos::Utility::ISortedMap*)__pNewObj->Probe(Elastos::Utility::EIID_ISortedMap);
        if (*__ISortedMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedMap * copyFrom,
        /* [out] */ Elastos::Utility::INavigableMap** __INavigableMap)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(copyFrom, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INavigableMap = (Elastos::Utility::INavigableMap*)__pNewObj->Probe(Elastos::Utility::EIID_INavigableMap);
        if (*__INavigableMap) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedMap * copyFrom,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(copyFrom, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedMap * copyFrom,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(copyFrom, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedMap * copyFrom,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(copyFrom, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedMap * copyFrom,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(copyFrom, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Utility {
class CTreeSet
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::INavigableMap * navmap,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICTreeSetClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CTreeSet, RGM_SAME_DOMAIN,
                EIID_ICTreeSetClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithNavmap(navmap, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::ICollection * map,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICTreeSetClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CTreeSet, RGM_SAME_DOMAIN,
                EIID_ICTreeSetClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithMap(map, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICTreeSetClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CTreeSet, RGM_SAME_DOMAIN,
                EIID_ICTreeSetClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithComparator(comparator, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::ISortedSet * set,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICTreeSetClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CTreeSet, RGM_SAME_DOMAIN,
                EIID_ICTreeSetClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithSet(set, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ITreeSet** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTreeSet, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ITreeSet, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ISet** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTreeSet, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ISet, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ICollection** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTreeSet, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ICollection, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IIterable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTreeSet, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IIterable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::INavigableSet** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTreeSet, RGM_SAME_DOMAIN, Elastos::Utility::EIID_INavigableSet, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ISortedSet** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTreeSet, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ISortedSet, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ICloneable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTreeSet, RGM_SAME_DOMAIN, Elastos::Core::EIID_ICloneable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTreeSet, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTreeSet, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CTreeSet, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::INavigableMap * navmap,
        /* [out] */ Elastos::Utility::ITreeSet** __ITreeSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(navmap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ITreeSet = (Elastos::Utility::ITreeSet*)__pNewObj->Probe(Elastos::Utility::EIID_ITreeSet);
        if (*__ITreeSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::INavigableMap * navmap,
        /* [out] */ Elastos::Utility::ISet** __ISet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(navmap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISet = (Elastos::Utility::ISet*)__pNewObj->Probe(Elastos::Utility::EIID_ISet);
        if (*__ISet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::INavigableMap * navmap,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(navmap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::INavigableMap * navmap,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(navmap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::INavigableMap * navmap,
        /* [out] */ Elastos::Utility::INavigableSet** __INavigableSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(navmap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INavigableSet = (Elastos::Utility::INavigableSet*)__pNewObj->Probe(Elastos::Utility::EIID_INavigableSet);
        if (*__INavigableSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::INavigableMap * navmap,
        /* [out] */ Elastos::Utility::ISortedSet** __ISortedSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(navmap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISortedSet = (Elastos::Utility::ISortedSet*)__pNewObj->Probe(Elastos::Utility::EIID_ISortedSet);
        if (*__ISortedSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::INavigableMap * navmap,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(navmap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::INavigableMap * navmap,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(navmap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::INavigableMap * navmap,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(navmap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::INavigableMap * navmap,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(navmap, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * map,
        /* [out] */ Elastos::Utility::ITreeSet** __ITreeSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ITreeSet = (Elastos::Utility::ITreeSet*)__pNewObj->Probe(Elastos::Utility::EIID_ITreeSet);
        if (*__ITreeSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * map,
        /* [out] */ Elastos::Utility::ISet** __ISet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISet = (Elastos::Utility::ISet*)__pNewObj->Probe(Elastos::Utility::EIID_ISet);
        if (*__ISet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * map,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * map,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * map,
        /* [out] */ Elastos::Utility::INavigableSet** __INavigableSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INavigableSet = (Elastos::Utility::INavigableSet*)__pNewObj->Probe(Elastos::Utility::EIID_INavigableSet);
        if (*__INavigableSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * map,
        /* [out] */ Elastos::Utility::ISortedSet** __ISortedSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISortedSet = (Elastos::Utility::ISortedSet*)__pNewObj->Probe(Elastos::Utility::EIID_ISortedSet);
        if (*__ISortedSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * map,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * map,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * map,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * map,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(map, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Utility::ITreeSet** __ITreeSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ITreeSet = (Elastos::Utility::ITreeSet*)__pNewObj->Probe(Elastos::Utility::EIID_ITreeSet);
        if (*__ITreeSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Utility::ISet** __ISet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISet = (Elastos::Utility::ISet*)__pNewObj->Probe(Elastos::Utility::EIID_ISet);
        if (*__ISet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Utility::INavigableSet** __INavigableSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INavigableSet = (Elastos::Utility::INavigableSet*)__pNewObj->Probe(Elastos::Utility::EIID_INavigableSet);
        if (*__INavigableSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Utility::ISortedSet** __ISortedSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISortedSet = (Elastos::Utility::ISortedSet*)__pNewObj->Probe(Elastos::Utility::EIID_ISortedSet);
        if (*__ISortedSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedSet * set,
        /* [out] */ Elastos::Utility::ITreeSet** __ITreeSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(set, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ITreeSet = (Elastos::Utility::ITreeSet*)__pNewObj->Probe(Elastos::Utility::EIID_ITreeSet);
        if (*__ITreeSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedSet * set,
        /* [out] */ Elastos::Utility::ISet** __ISet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(set, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISet = (Elastos::Utility::ISet*)__pNewObj->Probe(Elastos::Utility::EIID_ISet);
        if (*__ISet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedSet * set,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(set, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedSet * set,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(set, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedSet * set,
        /* [out] */ Elastos::Utility::INavigableSet** __INavigableSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(set, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INavigableSet = (Elastos::Utility::INavigableSet*)__pNewObj->Probe(Elastos::Utility::EIID_INavigableSet);
        if (*__INavigableSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedSet * set,
        /* [out] */ Elastos::Utility::ISortedSet** __ISortedSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(set, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISortedSet = (Elastos::Utility::ISortedSet*)__pNewObj->Probe(Elastos::Utility::EIID_ISortedSet);
        if (*__ISortedSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedSet * set,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(set, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedSet * set,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(set, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedSet * set,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(set, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedSet * set,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(set, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Utility {
class CPriorityQueue
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPriorityQueueClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPriorityQueue, RGM_SAME_DOMAIN,
                EIID_ICPriorityQueueClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithInitialCapacity(initialCapacity, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPriorityQueueClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPriorityQueue, RGM_SAME_DOMAIN,
                EIID_ICPriorityQueueClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithInitialCapacityComparator(initialCapacity, comparator, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::ICollection * co,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPriorityQueueClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPriorityQueue, RGM_SAME_DOMAIN,
                EIID_ICPriorityQueueClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCo(co, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::IPriorityQueue * queue,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPriorityQueueClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPriorityQueue, RGM_SAME_DOMAIN,
                EIID_ICPriorityQueueClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithQueue(queue, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::ISortedSet * set,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPriorityQueueClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPriorityQueue, RGM_SAME_DOMAIN,
                EIID_ICPriorityQueueClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithSet(set, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IPriorityQueue** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPriorityQueue, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IPriorityQueue, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ICollection** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPriorityQueue, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ICollection, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IIterable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPriorityQueue, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IIterable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IQueue** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPriorityQueue, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IQueue, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPriorityQueue, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPriorityQueue, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPriorityQueue, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [out] */ Elastos::Utility::IPriorityQueue** __IPriorityQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialCapacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPriorityQueue = (Elastos::Utility::IPriorityQueue*)__pNewObj->Probe(Elastos::Utility::EIID_IPriorityQueue);
        if (*__IPriorityQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialCapacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialCapacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [out] */ Elastos::Utility::IQueue** __IQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialCapacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IQueue = (Elastos::Utility::IQueue*)__pNewObj->Probe(Elastos::Utility::EIID_IQueue);
        if (*__IQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialCapacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialCapacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialCapacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Utility::IPriorityQueue** __IPriorityQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialCapacity, comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPriorityQueue = (Elastos::Utility::IPriorityQueue*)__pNewObj->Probe(Elastos::Utility::EIID_IPriorityQueue);
        if (*__IPriorityQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialCapacity, comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialCapacity, comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Utility::IQueue** __IQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialCapacity, comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IQueue = (Elastos::Utility::IQueue*)__pNewObj->Probe(Elastos::Utility::EIID_IQueue);
        if (*__IQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialCapacity, comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialCapacity, comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [in] */ Elastos::Core::IComparator * comparator,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(initialCapacity, comparator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * co,
        /* [out] */ Elastos::Utility::IPriorityQueue** __IPriorityQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(co, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPriorityQueue = (Elastos::Utility::IPriorityQueue*)__pNewObj->Probe(Elastos::Utility::EIID_IPriorityQueue);
        if (*__IPriorityQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * co,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(co, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * co,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(co, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * co,
        /* [out] */ Elastos::Utility::IQueue** __IQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(co, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IQueue = (Elastos::Utility::IQueue*)__pNewObj->Probe(Elastos::Utility::EIID_IQueue);
        if (*__IQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * co,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(co, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * co,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(co, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * co,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(co, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IPriorityQueue * queue,
        /* [out] */ Elastos::Utility::IPriorityQueue** __IPriorityQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(queue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPriorityQueue = (Elastos::Utility::IPriorityQueue*)__pNewObj->Probe(Elastos::Utility::EIID_IPriorityQueue);
        if (*__IPriorityQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IPriorityQueue * queue,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(queue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IPriorityQueue * queue,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(queue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IPriorityQueue * queue,
        /* [out] */ Elastos::Utility::IQueue** __IQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(queue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IQueue = (Elastos::Utility::IQueue*)__pNewObj->Probe(Elastos::Utility::EIID_IQueue);
        if (*__IQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IPriorityQueue * queue,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(queue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IPriorityQueue * queue,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(queue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IPriorityQueue * queue,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(queue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedSet * set,
        /* [out] */ Elastos::Utility::IPriorityQueue** __IPriorityQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(set, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPriorityQueue = (Elastos::Utility::IPriorityQueue*)__pNewObj->Probe(Elastos::Utility::EIID_IPriorityQueue);
        if (*__IPriorityQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedSet * set,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(set, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedSet * set,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(set, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedSet * set,
        /* [out] */ Elastos::Utility::IQueue** __IQueue)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(set, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IQueue = (Elastos::Utility::IQueue*)__pNewObj->Probe(Elastos::Utility::EIID_IQueue);
        if (*__IQueue) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedSet * set,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(set, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedSet * set,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(set, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ISortedSet * set,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(set, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Utility {
class CHugeEnumSet
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS InterfaceID & cls,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * enums,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICHugeEnumSetClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CHugeEnumSet, RGM_SAME_DOMAIN,
                EIID_ICHugeEnumSetClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithClsEnums(cls, enums, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IHugeEnumSet** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHugeEnumSet, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IHugeEnumSet, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ICollection** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHugeEnumSet, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ICollection, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IIterable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHugeEnumSet, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IIterable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ISet** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHugeEnumSet, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ISet, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ICloneable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHugeEnumSet, RGM_SAME_DOMAIN, Elastos::Core::EIID_ICloneable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHugeEnumSet, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHugeEnumSet, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHugeEnumSet, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS InterfaceID & cls,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * enums,
        /* [out] */ Elastos::Utility::IHugeEnumSet** __IHugeEnumSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(cls, enums, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IHugeEnumSet = (Elastos::Utility::IHugeEnumSet*)__pNewObj->Probe(Elastos::Utility::EIID_IHugeEnumSet);
        if (*__IHugeEnumSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS InterfaceID & cls,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * enums,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(cls, enums, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS InterfaceID & cls,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * enums,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(cls, enums, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS InterfaceID & cls,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * enums,
        /* [out] */ Elastos::Utility::ISet** __ISet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(cls, enums, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISet = (Elastos::Utility::ISet*)__pNewObj->Probe(Elastos::Utility::EIID_ISet);
        if (*__ISet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS InterfaceID & cls,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * enums,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(cls, enums, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS InterfaceID & cls,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * enums,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(cls, enums, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS InterfaceID & cls,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * enums,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(cls, enums, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS InterfaceID & cls,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * enums,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(cls, enums, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Utility {
class CMiniEnumSet
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS InterfaceID & cls,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * enums,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICMiniEnumSetClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CMiniEnumSet, RGM_SAME_DOMAIN,
                EIID_ICMiniEnumSetClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithClsEnums(cls, enums, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IMiniEnumSet** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMiniEnumSet, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IMiniEnumSet, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ICollection** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMiniEnumSet, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ICollection, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IIterable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMiniEnumSet, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IIterable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ISet** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMiniEnumSet, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ISet, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ICloneable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMiniEnumSet, RGM_SAME_DOMAIN, Elastos::Core::EIID_ICloneable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMiniEnumSet, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMiniEnumSet, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMiniEnumSet, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS InterfaceID & cls,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * enums,
        /* [out] */ Elastos::Utility::IMiniEnumSet** __IMiniEnumSet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(cls, enums, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMiniEnumSet = (Elastos::Utility::IMiniEnumSet*)__pNewObj->Probe(Elastos::Utility::EIID_IMiniEnumSet);
        if (*__IMiniEnumSet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS InterfaceID & cls,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * enums,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(cls, enums, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS InterfaceID & cls,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * enums,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(cls, enums, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS InterfaceID & cls,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * enums,
        /* [out] */ Elastos::Utility::ISet** __ISet)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(cls, enums, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISet = (Elastos::Utility::ISet*)__pNewObj->Probe(Elastos::Utility::EIID_ISet);
        if (*__ISet) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS InterfaceID & cls,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * enums,
        /* [out] */ Elastos::Core::ICloneable** __ICloneable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(cls, enums, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICloneable = (Elastos::Core::ICloneable*)__pNewObj->Probe(Elastos::Core::EIID_ICloneable);
        if (*__ICloneable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS InterfaceID & cls,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * enums,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(cls, enums, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS InterfaceID & cls,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * enums,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(cls, enums, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS InterfaceID & cls,
        /* [in] */ _ELASTOS ArrayOf<IInterface *> * enums,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(cls, enums, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Utility {
class CUnsafeArrayList
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS InterfaceID & elementType,
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICUnsafeArrayListClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CUnsafeArrayList, RGM_SAME_DOMAIN,
                EIID_ICUnsafeArrayListClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithElementTypeInitialCapacity(elementType, initialCapacity, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IUnsafeArrayList** __object)
    {
        return _CObject_CreateInstance(ECLSID_CUnsafeArrayList, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IUnsafeArrayList, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::ICollection** __object)
    {
        return _CObject_CreateInstance(ECLSID_CUnsafeArrayList, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ICollection, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IIterable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CUnsafeArrayList, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IIterable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Utility::IList** __object)
    {
        return _CObject_CreateInstance(ECLSID_CUnsafeArrayList, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IList, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CUnsafeArrayList, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CUnsafeArrayList, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CUnsafeArrayList, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS InterfaceID & elementType,
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [out] */ Elastos::Utility::IUnsafeArrayList** __IUnsafeArrayList)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(elementType, initialCapacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IUnsafeArrayList = (Elastos::Utility::IUnsafeArrayList*)__pNewObj->Probe(Elastos::Utility::EIID_IUnsafeArrayList);
        if (*__IUnsafeArrayList) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS InterfaceID & elementType,
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [out] */ Elastos::Utility::ICollection** __ICollection)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(elementType, initialCapacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICollection = (Elastos::Utility::ICollection*)__pNewObj->Probe(Elastos::Utility::EIID_ICollection);
        if (*__ICollection) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS InterfaceID & elementType,
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [out] */ Elastos::Utility::IIterable** __IIterable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(elementType, initialCapacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IIterable = (Elastos::Utility::IIterable*)__pNewObj->Probe(Elastos::Utility::EIID_IIterable);
        if (*__IIterable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS InterfaceID & elementType,
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [out] */ Elastos::Utility::IList** __IList)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(elementType, initialCapacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IList = (Elastos::Utility::IList*)__pNewObj->Probe(Elastos::Utility::EIID_IList);
        if (*__IList) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS InterfaceID & elementType,
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(elementType, initialCapacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS InterfaceID & elementType,
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(elementType, initialCapacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS InterfaceID & elementType,
        /* [in] */ _ELASTOS Int32 initialCapacity,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(elementType, initialCapacity, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Utility {
class CCollections
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Utility::ICollections** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCollections, RGM_SAME_DOMAIN, Elastos::Utility::EIID_ICollections, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCollections, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCollections, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CCollections, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Utility {
class CEnumSetHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Utility::IEnumSetHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CEnumSetHelper, RGM_SAME_DOMAIN, Elastos::Utility::EIID_IEnumSetHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CEnumSetHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CEnumSetHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CEnumSetHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Utility {
namespace Regex {
class CMatcher
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::Regex::IPattern * pattern,
        /* [in] */ Elastos::Core::ICharSequence * inputSeq,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICMatcherClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CMatcher, RGM_SAME_DOMAIN,
                EIID_ICMatcherClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPatternInputSeq(pattern, inputSeq, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Regex::IPattern * pattern,
        /* [in] */ Elastos::Core::ICharSequence * inputSeq,
        /* [out] */ Elastos::Utility::Regex::IMatcher** __IMatcher)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, inputSeq, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMatcher = (Elastos::Utility::Regex::IMatcher*)__pNewObj->Probe(Elastos::Utility::Regex::EIID_IMatcher);
        if (*__IMatcher) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Regex::IPattern * pattern,
        /* [in] */ Elastos::Core::ICharSequence * inputSeq,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, inputSeq, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Regex::IPattern * pattern,
        /* [in] */ Elastos::Core::ICharSequence * inputSeq,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, inputSeq, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::Regex::IPattern * pattern,
        /* [in] */ Elastos::Core::ICharSequence * inputSeq,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pattern, inputSeq, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Utility {
namespace Regex {
class CMatcherHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Utility::Regex::IMatcherHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMatcherHelper, RGM_SAME_DOMAIN, Elastos::Utility::Regex::EIID_IMatcherHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMatcherHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMatcherHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMatcherHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Utility {
namespace Regex {
class CSplitter
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Utility::Regex::ISplitter** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSplitter, RGM_SAME_DOMAIN, Elastos::Utility::Regex::EIID_ISplitter, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSplitter, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSplitter, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CSplitter, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Utility {
namespace Regex {
class CPatternHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Utility::Regex::IPatternHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPatternHelper, RGM_SAME_DOMAIN, Elastos::Utility::Regex::EIID_IPatternHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPatternHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPatternHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CPatternHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#endif // __Elastos_CoreLibrary_Utility_h__
