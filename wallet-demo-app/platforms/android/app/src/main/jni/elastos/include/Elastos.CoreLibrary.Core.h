#ifndef __Elastos_CoreLibrary_Core_h__
#define __Elastos_CoreLibrary_Core_h__

#include "Elastos.CoreLibrary.h"

ELAPI _Impl_AcquireCallbackHandler(PInterface pServerObj, _ELASTOS REIID iid, PInterface *ppHandler);
ELAPI _Impl_CheckClsId(PInterface pServerObj, const _ELASTOS ClassID* pClassid, PInterface *ppServerObj);

namespace Elastos {
namespace Core {
CAR_INTERFACE("F68E404B-90D2-1C44-50CC-8D01EA878392")
ICharSequence : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICharSequence*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICharSequence*)pObj->Probe(EIID_ICharSequence);
    }

    static CARAPI_(ICharSequence*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICharSequence*)pObj->Probe(EIID_ICharSequence);
    }

    static CARAPI_(ICharSequence*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetLength(
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI GetCharAt(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Char32 * c) = 0;

    virtual CARAPI SubSequence(
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ Elastos::Core::ICharSequence ** csq) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("271C2F5F-0292-C9B4-F4FC-705052868D1F")
IAppendable : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAppendable*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAppendable*)pObj->Probe(EIID_IAppendable);
    }

    static CARAPI_(IAppendable*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAppendable*)pObj->Probe(EIID_IAppendable);
    }

    static CARAPI_(IAppendable*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI AppendChar(
        /* [in] */ _ELASTOS Char32 c) = 0;

    virtual CARAPI Append(
        /* [in] */ Elastos::Core::ICharSequence * csq) = 0;

    virtual CARAPI Append(
        /* [in] */ Elastos::Core::ICharSequence * csq,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("6CD91D47-0312-479A-F5FC-705052868D1F")
ICloneable : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICloneable*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICloneable*)pObj->Probe(EIID_ICloneable);
    }

    static CARAPI_(ICloneable*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICloneable*)pObj->Probe(EIID_ICloneable);
    }

    static CARAPI_(ICloneable*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI Clone(
        /* [out] */ IInterface ** object) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("B7822252-1152-6018-EF5A-FAE1A0A40C1B")
IComparable : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IComparable*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IComparable*)pObj->Probe(EIID_IComparable);
    }

    static CARAPI_(IComparable*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IComparable*)pObj->Probe(EIID_IComparable);
    }

    static CARAPI_(IComparable*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CompareTo(
        /* [in] */ IInterface * another,
        /* [out] */ _ELASTOS Int32 * result) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("23B82048-1152-6018-EF9E-FEE1A0A40C1B")
IComparator : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IComparator*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IComparator*)pObj->Probe(EIID_IComparator);
    }

    static CARAPI_(IComparator*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IComparator*)pObj->Probe(EIID_IComparator);
    }

    static CARAPI_(IComparator*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI Compare(
        /* [in] */ IInterface * lhs,
        /* [in] */ IInterface * rhs,
        /* [out] */ _ELASTOS Int32 * result) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("69E1FB23-6C12-F736-7FB4-B77143868D1F")
IStringBuilder : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IStringBuilder*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStringBuilder*)pObj->Probe(EIID_IStringBuilder);
    }

    static CARAPI_(IStringBuilder*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStringBuilder*)pObj->Probe(EIID_IStringBuilder);
    }

    static CARAPI_(IStringBuilder*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI ToASCIILowerCase() = 0;

    virtual CARAPI ToASCIIUpperCase() = 0;

    virtual CARAPI Reset() = 0;

    virtual CARAPI GetByteCount(
        /* [out] */ _ELASTOS Int32 * byteLength) = 0;

    virtual CARAPI GetCapacity(
        /* [out] */ _ELASTOS Int32 * capacity) = 0;

    virtual CARAPI EnsureCapacity(
        /* [in] */ _ELASTOS Int32 min) = 0;

    virtual CARAPI TrimToSize() = 0;

    virtual CARAPI SetCharAt(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Char32 ch) = 0;

    virtual CARAPI GetCharAt(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Char32 * c) = 0;

    virtual CARAPI GetChars(
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ _ELASTOS ArrayOf<_ELASTOS Char32> * dst,
        /* [in] */ _ELASTOS Int32 dstStart) = 0;

    virtual CARAPI SetLength(
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI Substring(
        /* [in] */ _ELASTOS Int32 start,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI Substring(
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI IndexOf(
        /* [in] */ const _ELASTOS String& string,
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI IndexOf(
        /* [in] */ const _ELASTOS String& subString,
        /* [in] */ _ELASTOS Int32 start,
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI LastIndexOf(
        /* [in] */ const _ELASTOS String& string,
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI LastIndexOf(
        /* [in] */ const _ELASTOS String& subString,
        /* [in] */ _ELASTOS Int32 start,
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI AppendNULL() = 0;

    virtual CARAPI Append(
        /* [in] */ _ELASTOS Boolean b) = 0;

    virtual CARAPI AppendChar(
        /* [in] */ _ELASTOS Char32 c) = 0;

    virtual CARAPI Append(
        /* [in] */ _ELASTOS Double d) = 0;

    virtual CARAPI Append(
        /* [in] */ _ELASTOS Float f) = 0;

    virtual CARAPI Append(
        /* [in] */ _ELASTOS Int32 i) = 0;

    virtual CARAPI Append(
        /* [in] */ _ELASTOS Int64 l) = 0;

    virtual CARAPI Append(
        /* [in] */ IInterface * obj) = 0;

    virtual CARAPI Append(
        /* [in] */ IObject * obj) = 0;

    virtual CARAPI Append(
        /* [in] */ const _ELASTOS String& str) = 0;

    virtual CARAPI Append(
        /* [in] */ Elastos::Core::IStringBuffer * sb) = 0;

    virtual CARAPI Append(
        /* [in] */ Elastos::Core::IStringBuilder * sb) = 0;

    virtual CARAPI Append(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & chars) = 0;

    virtual CARAPI Append(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & str,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI Append(
        /* [in] */ Elastos::Core::ICharSequence * csq) = 0;

    virtual CARAPI Append(
        /* [in] */ Elastos::Core::ICharSequence * csq,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end) = 0;

    virtual CARAPI InsertChar(
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Char32 c) = 0;

    virtual CARAPI Insert(
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Boolean b) = 0;

    virtual CARAPI Insert(
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 i) = 0;

    virtual CARAPI Insert(
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int64 l) = 0;

    virtual CARAPI Insert(
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Double d) = 0;

    virtual CARAPI Insert(
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Float f) = 0;

    virtual CARAPI Insert(
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ IInterface * obj) = 0;

    virtual CARAPI Insert(
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ const _ELASTOS String& str) = 0;

    virtual CARAPI Insert(
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & ch) = 0;

    virtual CARAPI Insert(
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & chars,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI Insert(
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ Elastos::Core::ICharSequence * s) = 0;

    virtual CARAPI Insert(
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ Elastos::Core::ICharSequence * s,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end) = 0;

    virtual CARAPI Replace(
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [in] */ const _ELASTOS String& string) = 0;

    virtual CARAPI Reverse() = 0;

    virtual CARAPI DeleteCharAt(
        /* [in] */ _ELASTOS Int32 location) = 0;

    virtual CARAPI Delete(
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("5B3AFD3C-6C12-3F35-DADB-B821C3C68F49")
IStringBuffer : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IStringBuffer*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStringBuffer*)pObj->Probe(EIID_IStringBuffer);
    }

    static CARAPI_(IStringBuffer*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStringBuffer*)pObj->Probe(EIID_IStringBuffer);
    }

    static CARAPI_(IStringBuffer*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI ToASCIILowerCase() = 0;

    virtual CARAPI ToASCIIUpperCase() = 0;

    virtual CARAPI Reset() = 0;

    virtual CARAPI GetByteCount(
        /* [out] */ _ELASTOS Int32 * byteLength) = 0;

    virtual CARAPI GetCapacity(
        /* [out] */ _ELASTOS Int32 * capacity) = 0;

    virtual CARAPI EnsureCapacity(
        /* [in] */ _ELASTOS Int32 min) = 0;

    virtual CARAPI TrimToSize() = 0;

    virtual CARAPI SetCharAt(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Char32 ch) = 0;

    virtual CARAPI GetCharAt(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Char32 * c) = 0;

    virtual CARAPI GetChars(
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ _ELASTOS ArrayOf<_ELASTOS Char32> * dst,
        /* [in] */ _ELASTOS Int32 dstStart) = 0;

    virtual CARAPI Substring(
        /* [in] */ _ELASTOS Int32 start,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI Substring(
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI IndexOf(
        /* [in] */ const _ELASTOS String& string,
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI IndexOf(
        /* [in] */ const _ELASTOS String& subString,
        /* [in] */ _ELASTOS Int32 start,
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI LastIndexOf(
        /* [in] */ const _ELASTOS String& string,
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI LastIndexOf(
        /* [in] */ const _ELASTOS String& subString,
        /* [in] */ _ELASTOS Int32 start,
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI AppendNULL() = 0;

    virtual CARAPI Append(
        /* [in] */ _ELASTOS Boolean b) = 0;

    virtual CARAPI AppendChar(
        /* [in] */ _ELASTOS Char32 c) = 0;

    virtual CARAPI Append(
        /* [in] */ _ELASTOS Double d) = 0;

    virtual CARAPI Append(
        /* [in] */ _ELASTOS Float f) = 0;

    virtual CARAPI Append(
        /* [in] */ _ELASTOS Int32 i) = 0;

    virtual CARAPI Append(
        /* [in] */ _ELASTOS Int64 l) = 0;

    virtual CARAPI Append(
        /* [in] */ IInterface * obj) = 0;

    virtual CARAPI Append(
        /* [in] */ const _ELASTOS String& str) = 0;

    virtual CARAPI Append(
        /* [in] */ Elastos::Core::IStringBuffer * sb) = 0;

    virtual CARAPI Append(
        /* [in] */ Elastos::Core::IStringBuilder * sb) = 0;

    virtual CARAPI Append(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & chars) = 0;

    virtual CARAPI Append(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & str,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI Append(
        /* [in] */ Elastos::Core::ICharSequence * csq) = 0;

    virtual CARAPI Append(
        /* [in] */ Elastos::Core::ICharSequence * csq,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end) = 0;

    virtual CARAPI InsertChar(
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Char32 c) = 0;

    virtual CARAPI Insert(
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Boolean b) = 0;

    virtual CARAPI Insert(
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 i) = 0;

    virtual CARAPI Insert(
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int64 l) = 0;

    virtual CARAPI Insert(
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Double d) = 0;

    virtual CARAPI Insert(
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Float f) = 0;

    virtual CARAPI Insert(
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ IInterface * obj) = 0;

    virtual CARAPI Insert(
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ const _ELASTOS String& str) = 0;

    virtual CARAPI Insert(
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & ch) = 0;

    virtual CARAPI Insert(
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & chars,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI Insert(
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ Elastos::Core::ICharSequence * s) = 0;

    virtual CARAPI Insert(
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ Elastos::Core::ICharSequence * s,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end) = 0;

    virtual CARAPI Replace(
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end,
        /* [in] */ const _ELASTOS String& string) = 0;

    virtual CARAPI Reverse() = 0;

    virtual CARAPI DeleteCharAt(
        /* [in] */ _ELASTOS Int32 location) = 0;

    virtual CARAPI Delete(
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 end) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("D7A0533A-9612-3FA5-DADB-B821C3C68F49")
IArrayOf : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IArrayOf*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IArrayOf*)pObj->Probe(EIID_IArrayOf);
    }

    static CARAPI_(IArrayOf*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IArrayOf*)pObj->Probe(EIID_IArrayOf);
    }

    static CARAPI_(IArrayOf*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetLength(
        /* [out] */ _ELASTOS Int32 * size) = 0;

    virtual CARAPI Get(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ IInterface ** element) = 0;

    virtual CARAPI Set(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ IInterface * element) = 0;

    virtual CARAPI GetTypeId(
        /* [out] */ _ELASTOS InterfaceID * id) = 0;

    virtual CARAPI DeepToString(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI DeepGetHashCode(
        /* [out] */ _ELASTOS Int32 * hash) = 0;

    virtual CARAPI DeepEquals(
        /* [in] */ Elastos::Core::IArrayOf * other,
        /* [out] */ _ELASTOS Boolean * equals) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("B6FE510A-85D2-25C3-5AFF-CE4BDAB76CFF")
INumber : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INumber*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INumber*)pObj->Probe(EIID_INumber);
    }

    static CARAPI_(INumber*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INumber*)pObj->Probe(EIID_INumber);
    }

    static CARAPI_(INumber*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI ByteValue(
        /* [out] */ _ELASTOS Byte * result) = 0;

    virtual CARAPI Int16Value(
        /* [out] */ _ELASTOS Int16 * result) = 0;

    virtual CARAPI Int32Value(
        /* [out] */ _ELASTOS Int32 * result) = 0;

    virtual CARAPI Int64Value(
        /* [out] */ _ELASTOS Int64 * result) = 0;

    virtual CARAPI FloatValue(
        /* [out] */ _ELASTOS Float * result) = 0;

    virtual CARAPI DoubleValue(
        /* [out] */ _ELASTOS Double * result) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("79651E42-82D2-29A9-05FD-705052868D1F")
IBoolean : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IBoolean*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBoolean*)pObj->Probe(EIID_IBoolean);
    }

    static CARAPI_(IBoolean*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBoolean*)pObj->Probe(EIID_IBoolean);
    }

    static CARAPI_(IBoolean*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetValue(
        /* [out] */ _ELASTOS Boolean * value) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("D03B1B43-1092-3FCD-1C94-9461E34711BC")
IByte : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IByte*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IByte*)pObj->Probe(EIID_IByte);
    }

    static CARAPI_(IByte*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IByte*)pObj->Probe(EIID_IByte);
    }

    static CARAPI_(IByte*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetValue(
        /* [out] */ _ELASTOS Byte * value) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("AF0D1D0C-B312-F592-20FC-CE4BDAB76CFF")
IChar32 : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IChar32*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IChar32*)pObj->Probe(EIID_IChar32);
    }

    static CARAPI_(IChar32*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IChar32*)pObj->Probe(EIID_IChar32);
    }

    static CARAPI_(IChar32*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetValue(
        /* [out] */ _ELASTOS Char32 * value) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("3138204E-16D2-E8CD-6A04-30F0C3414919")
IInteger16 : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IInteger16*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInteger16*)pObj->Probe(EIID_IInteger16);
    }

    static CARAPI_(IInteger16*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInteger16*)pObj->Probe(EIID_IInteger16);
    }

    static CARAPI_(IInteger16*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetValue(
        /* [out] */ _ELASTOS Int16 * value) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("3536205A-16D2-E8CD-6A0C-10F0C3414919")
IInteger32 : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IInteger32*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInteger32*)pObj->Probe(EIID_IInteger32);
    }

    static CARAPI_(IInteger32*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInteger32*)pObj->Probe(EIID_IInteger32);
    }

    static CARAPI_(IInteger32*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetValue(
        /* [out] */ _ELASTOS Int32 * value) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("33332045-16D2-E8CD-6A18-20F0C3414919")
IInteger64 : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IInteger64*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInteger64*)pObj->Probe(EIID_IInteger64);
    }

    static CARAPI_(IInteger64*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInteger64*)pObj->Probe(EIID_IInteger64);
    }

    static CARAPI_(IInteger64*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetValue(
        /* [out] */ _ELASTOS Int64 * value) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("98602B42-03D2-8F9A-7E38-2829C3C68F22")
IFloat : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IFloat*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFloat*)pObj->Probe(EIID_IFloat);
    }

    static CARAPI_(IFloat*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IFloat*)pObj->Probe(EIID_IFloat);
    }

    static CARAPI_(IFloat*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetValue(
        /* [out] */ _ELASTOS Float * value) = 0;

    virtual CARAPI IsInfinite(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI IsNaN(
        /* [out] */ _ELASTOS Boolean * result) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("03902C57-1312-961C-7E38-2829C3C68F22")
IDouble : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDouble*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDouble*)pObj->Probe(EIID_IDouble);
    }

    static CARAPI_(IDouble*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDouble*)pObj->Probe(EIID_IDouble);
    }

    static CARAPI_(IDouble*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetValue(
        /* [out] */ _ELASTOS Double * value) = 0;

    virtual CARAPI IsInfinite(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI IsNaN(
        /* [out] */ _ELASTOS Boolean * result) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("1B2D1527-EC12-ED1F-6DDC-9061E3C7A41F")
IString : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IString*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IString*)pObj->Probe(EIID_IString);
    }

    static CARAPI_(IString*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IString*)pObj->Probe(EIID_IString);
    }

    static CARAPI_(IString*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("2F221A53-86D2-45DB-2DFD-705052868D1F")
IRunnable : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IRunnable*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRunnable*)pObj->Probe(EIID_IRunnable);
    }

    static CARAPI_(IRunnable*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IRunnable*)pObj->Probe(EIID_IRunnable);
    }

    static CARAPI_(IRunnable*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI Run() = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("391A3F36-EE12-ED1F-6DDC-9061E3C7A41F")
ISynchronize : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISynchronize*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISynchronize*)pObj->Probe(EIID_ISynchronize);
    }

    static CARAPI_(ISynchronize*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISynchronize*)pObj->Probe(EIID_ISynchronize);
    }

    static CARAPI_(ISynchronize*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI Lock() = 0;

    virtual CARAPI Unlock() = 0;

    virtual CARAPI Notify() = 0;

    virtual CARAPI NotifyAll() = 0;

    virtual CARAPI Wait() = 0;

    virtual CARAPI Wait(
        /* [in] */ _ELASTOS Int64 millis) = 0;

    virtual CARAPI Wait(
        /* [in] */ _ELASTOS Int64 millis,
        /* [in] */ _ELASTOS Int32 nanos) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("1BA13E4D-1B92-24BC-4ED0-E984A35D1450")
IThreadUncaughtExceptionHandler : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IThreadUncaughtExceptionHandler*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IThreadUncaughtExceptionHandler*)pObj->Probe(EIID_IThreadUncaughtExceptionHandler);
    }

    static CARAPI_(IThreadUncaughtExceptionHandler*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IThreadUncaughtExceptionHandler*)pObj->Probe(EIID_IThreadUncaughtExceptionHandler);
    }

    static CARAPI_(IThreadUncaughtExceptionHandler*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI UncaughtException(
        /* [in] */ Elastos::Core::IThread * thread,
        /* [in] */ _ELASTOS ECode ec) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("CC6DFC2C-F092-ED1F-6DDC-9061E3C7A41F")
IThread : public IInterface
{
    static const _ELASTOS Int32 MAX_PRIORITY = 10;
    static const _ELASTOS Int32 MIN_PRIORITY = 1;
    static const _ELASTOS Int32 NORM_PRIORITY = 5;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IThread*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IThread*)pObj->Probe(EIID_IThread);
    }

    static CARAPI_(IThread*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IThread*)pObj->Probe(EIID_IThread);
    }

    static CARAPI_(IThread*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CheckAccess() = 0;

    virtual CARAPI CountStackFrames(
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI Destroy() = 0;

    virtual CARAPI GetContextClassLoader(
        /* [out] */ Elastos::Core::IClassLoader ** outload) = 0;

    virtual CARAPI GetId(
        /* [out] */ _ELASTOS Int64 * id) = 0;

    virtual CARAPI GetName(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI GetPriority(
        /* [out] */ _ELASTOS Int32 * priority) = 0;

    virtual CARAPI GetState(
        /* [out] */ Elastos::Core::ThreadState * state) = 0;

    virtual CARAPI GetThreadGroup(
        /* [out] */ Elastos::Core::IThreadGroup ** group) = 0;

    virtual CARAPI GetUncaughtExceptionHandler(
        /* [out] */ Elastos::Core::IThreadUncaughtExceptionHandler ** handler) = 0;

    virtual CARAPI Interrupt() = 0;

    virtual CARAPI IsAlive(
        /* [out] */ _ELASTOS Boolean * isAlive) = 0;

    virtual CARAPI IsDaemon(
        /* [out] */ _ELASTOS Boolean * isDaemon) = 0;

    virtual CARAPI IsInterrupted(
        /* [out] */ _ELASTOS Boolean * isInterrupted) = 0;

    virtual CARAPI Join() = 0;

    virtual CARAPI Join(
        /* [in] */ _ELASTOS Int64 millis) = 0;

    virtual CARAPI Join(
        /* [in] */ _ELASTOS Int64 millis,
        /* [in] */ _ELASTOS Int32 nanos) = 0;

    virtual CARAPI Resume() = 0;

    virtual CARAPI SetContextClassLoader(
        /* [in] */ Elastos::Core::IClassLoader * cl) = 0;

    virtual CARAPI SetDaemon(
        /* [in] */ _ELASTOS Boolean isDaemon) = 0;

    virtual CARAPI PushInterruptAction(
        /* [in] */ Elastos::Core::IRunnable * interruptAction) = 0;

    virtual CARAPI PopInterruptAction(
        /* [in] */ Elastos::Core::IRunnable * interruptAction) = 0;

    virtual CARAPI SetName(
        /* [in] */ const _ELASTOS String& threadName) = 0;

    virtual CARAPI SetPriority(
        /* [in] */ _ELASTOS Int32 priority) = 0;

    virtual CARAPI SetUncaughtExceptionHandler(
        /* [in] */ Elastos::Core::IThreadUncaughtExceptionHandler * handler) = 0;

    virtual CARAPI Start() = 0;

    virtual CARAPI Stop() = 0;

    virtual CARAPI Suspend() = 0;

    virtual CARAPI Unpark() = 0;

    virtual CARAPI ParkFor(
        /* [in] */ _ELASTOS Int64 nanos) = 0;

    virtual CARAPI ParkUntil(
        /* [in] */ _ELASTOS Int64 time) = 0;

    virtual CARAPI Detach() = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("5BCCF026-7092-3508-64E0-98F1A3BD8D1B")
IThreadGroup : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IThreadGroup*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IThreadGroup*)pObj->Probe(EIID_IThreadGroup);
    }

    static CARAPI_(IThreadGroup*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IThreadGroup*)pObj->Probe(EIID_IThreadGroup);
    }

    static CARAPI_(IThreadGroup*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI ActiveCount(
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI ActiveGroupCount(
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI AllowThreadSuspension(
        /* [in] */ _ELASTOS Boolean b,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI CheckAccess() = 0;

    virtual CARAPI Destroy() = 0;

    virtual CARAPI Enumerate(
        /* [in] */ _ELASTOS ArrayOf<Elastos::Core::IThread *> * threads,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI Enumerate(
        /* [in] */ _ELASTOS ArrayOf<Elastos::Core::IThread *> * threads,
        /* [in] */ _ELASTOS Boolean recurse,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI Enumerate(
        /* [in] */ _ELASTOS ArrayOf<Elastos::Core::IThreadGroup *> * groups,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI Enumerate(
        /* [in] */ _ELASTOS ArrayOf<Elastos::Core::IThreadGroup *> * groups,
        /* [in] */ _ELASTOS Boolean recurse,
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI GetMaxPriority(
        /* [out] */ _ELASTOS Int32 * maxPriority) = 0;

    virtual CARAPI GetName(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI GetParent(
        /* [out] */ Elastos::Core::IThreadGroup ** parent) = 0;

    virtual CARAPI Interrupt() = 0;

    virtual CARAPI IsDaemon(
        /* [out] */ _ELASTOS Boolean * isDaemon) = 0;

    virtual CARAPI IsDestroyed(
        /* [out] */ _ELASTOS Boolean * isDestroyed) = 0;

    virtual CARAPI List() = 0;

    virtual CARAPI IsParentOf(
        /* [in] */ Elastos::Core::IThreadGroup * g,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Resume() = 0;

    virtual CARAPI SetDaemon(
        /* [in] */ _ELASTOS Boolean isDaemon) = 0;

    virtual CARAPI SetMaxPriority(
        /* [in] */ _ELASTOS Int32 newMax) = 0;

    virtual CARAPI Stop() = 0;

    virtual CARAPI Suspend() = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("D60A302C-1E92-F78E-7FB4-B77143868D1F")
IClassLoader : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IClassLoader*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IClassLoader*)pObj->Probe(EIID_IClassLoader);
    }

    static CARAPI_(IClassLoader*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IClassLoader*)pObj->Probe(EIID_IClassLoader);
    }

    virtual CARAPI LoadClass(
        /* [in] */ const _ELASTOS String& fullname,
        /* [out] */ IClassInfo ** klass) = 0;

    virtual CARAPI LoadInterface(
        /* [in] */ const _ELASTOS String& fullname,
        /* [out] */ IInterfaceInfo ** klass) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("192BA85A-1B92-C2BE-2DFD-705052868D1F")
IThrowable : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IThrowable*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IThrowable*)pObj->Probe(EIID_IThrowable);
    }

    static CARAPI_(IThrowable*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IThrowable*)pObj->Probe(EIID_IThrowable);
    }

    static CARAPI_(IThrowable*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI FillInStackTrace() = 0;

    virtual CARAPI GetMessage(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetLocalizedMessage(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetStackTrace(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Core::IStackTraceElement *> ** outarr) = 0;

    virtual CARAPI SetStackTrace(
        /* [in] */ _ELASTOS ArrayOf<Elastos::Core::IStackTraceElement *> * trace) = 0;

    virtual CARAPI PrintStackTrace() = 0;

    virtual CARAPI PrintStackTrace(
        /* [in] */ Elastos::Core::IAppendable * err,
        /* [in] */ const _ELASTOS String& indent,
        /* [in] */ _ELASTOS ArrayOf<Elastos::Core::IStackTraceElement *> * parentStack) = 0;

    virtual CARAPI InitCause(
        /* [in] */ Elastos::Core::IThrowable * throwable) = 0;

    virtual CARAPI GetCause(
        /* [out] */ Elastos::Core::IThrowable ** outthr) = 0;

    virtual CARAPI AddSuppressed(
        /* [in] */ Elastos::Core::IThrowable * throwable) = 0;

    virtual CARAPI GetSuppressed(
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Core::IThrowable *> ** outarr) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("11FA204B-8712-ABCA-E2EC-719052E70F07")
IStackTraceElement : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IStackTraceElement*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStackTraceElement*)pObj->Probe(EIID_IStackTraceElement);
    }

    static CARAPI_(IStackTraceElement*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IStackTraceElement*)pObj->Probe(EIID_IStackTraceElement);
    }

    static CARAPI_(IStackTraceElement*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("1B0E502A-1952-3808-48D4-38F1F5477B1B")
IBlockGuardPolicy : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IBlockGuardPolicy*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBlockGuardPolicy*)pObj->Probe(EIID_IBlockGuardPolicy);
    }

    static CARAPI_(IBlockGuardPolicy*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBlockGuardPolicy*)pObj->Probe(EIID_IBlockGuardPolicy);
    }

    static CARAPI_(IBlockGuardPolicy*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI OnWriteToDisk() = 0;

    virtual CARAPI OnReadFromDisk() = 0;

    virtual CARAPI OnNetwork() = 0;

    virtual CARAPI GetPolicyMask(
        /* [out] */ _ELASTOS Int32 * mask) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("D5684327-1952-3808-48D4-38F1A3BD8D1B")
IBlockGuard : public IInterface
{
    static const _ELASTOS Int32 DISALLOW_DISK_WRITE = 0x00000001;
    static const _ELASTOS Int32 DISALLOW_DISK_READ = 0x00000002;
    static const _ELASTOS Int32 DISALLOW_NETWORK = 0x00000004;
    static const _ELASTOS Int32 PASS_RESTRICTIONS_VIA_RPC = 0x00000008;
    static const _ELASTOS Int32 PENALTY_LOG = 0x00000010;
    static const _ELASTOS Int32 PENALTY_DIALOG = 0x00000020;
    static const _ELASTOS Int32 PENALTY_DEATH = 0x00000040;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IBlockGuard*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBlockGuard*)pObj->Probe(EIID_IBlockGuard);
    }

    static CARAPI_(IBlockGuard*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBlockGuard*)pObj->Probe(EIID_IBlockGuard);
    }

    static CARAPI_(IBlockGuard*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetThreadPolicy(
        /* [out] */ Elastos::Core::IBlockGuardPolicy ** policy) = 0;

    virtual CARAPI SetThreadPolicy(
        /* [in] */ Elastos::Core::IBlockGuardPolicy * policy) = 0;

    virtual CARAPI GetLaxPolicy(
        /* [out] */ Elastos::Core::IBlockGuardPolicy ** policy) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("3AC52724-1FD2-3808-48D4-3811F8FE8FF6")
ICloseGuardReporter : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICloseGuardReporter*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICloseGuardReporter*)pObj->Probe(EIID_ICloseGuardReporter);
    }

    static CARAPI_(ICloseGuardReporter*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICloseGuardReporter*)pObj->Probe(EIID_ICloseGuardReporter);
    }

    static CARAPI_(ICloseGuardReporter*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI Report(
        /* [in] */ const _ELASTOS String& message,
        /* [in] */ Elastos::Core::IThrowable * allocationSite) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("9CCF2C21-1FD2-3808-48D4-38F1A3BD8D1B")
ICloseGuard : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICloseGuard*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICloseGuard*)pObj->Probe(EIID_ICloseGuard);
    }

    static CARAPI_(ICloseGuard*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICloseGuard*)pObj->Probe(EIID_ICloseGuard);
    }

    static CARAPI_(ICloseGuard*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI Open(
        /* [in] */ const _ELASTOS String& closer) = 0;

    virtual CARAPI Close() = 0;

    virtual CARAPI WarnIfOpen() = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("5427420A-F312-36CA-0AE1-647D46E83BA3")
ICloseGuardHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICloseGuardHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICloseGuardHelper*)pObj->Probe(EIID_ICloseGuardHelper);
    }

    static CARAPI_(ICloseGuardHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICloseGuardHelper*)pObj->Probe(EIID_ICloseGuardHelper);
    }

    static CARAPI_(ICloseGuardHelper*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI Get(
        /* [out] */ Elastos::Core::ICloseGuard ** guard) = 0;

    virtual CARAPI SetEnabled(
        /* [in] */ _ELASTOS Boolean enabled) = 0;

    virtual CARAPI SetReporter(
        /* [in] */ Elastos::Core::ICloseGuardReporter * reporter) = 0;

    virtual CARAPI GetReporter(
        /* [out] */ Elastos::Core::ICloseGuardReporter ** report) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("E74F2F3C-B192-ED1F-6DDC-9061E3C7A41F")
IEnum : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IEnum*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IEnum*)pObj->Probe(EIID_IEnum);
    }

    static CARAPI_(IEnum*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IEnum*)pObj->Probe(EIID_IEnum);
    }

    static CARAPI_(IEnum*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI Name(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI Ordinal(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetDeclaringClass(
        /* [out] */ _ELASTOS InterfaceID * riid) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("816E322E-7092-3F8F-DADB-B821C3C68F49")
IThreadLocal : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IThreadLocal*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IThreadLocal*)pObj->Probe(EIID_IThreadLocal);
    }

    static CARAPI_(IThreadLocal*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IThreadLocal*)pObj->Probe(EIID_IThreadLocal);
    }

    static CARAPI_(IThreadLocal*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI Get(
        /* [out] */ IInterface ** obj) = 0;

    virtual CARAPI InitialValue(
        /* [out] */ IInterface ** obj) = 0;

    virtual CARAPI Set(
        /* [in] */ IInterface * obj) = 0;

    virtual CARAPI Remove() = 0;

};
}
}

namespace Elastos {
namespace IO {
CAR_INTERFACE("7661194C-8712-0167-3DEA-F9E1A0A40C1B")
ISerializable : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ISerializable*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISerializable*)pObj->Probe(EIID_ISerializable);
    }

    static CARAPI_(ISerializable*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ISerializable*)pObj->Probe(EIID_ISerializable);
    }

    static CARAPI_(ISerializable*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("30976121-0312-7AA3-8CFE-686FE3860C1B")
ICObjectClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICObjectClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICObjectClassObject*)pObj->Probe(EIID_ICObjectClassObject);
    }

    static CARAPI_(ICObjectClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICObjectClassObject*)pObj->Probe(EIID_ICObjectClassObject);
    }

    static CARAPI_(ICObjectClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("6565F330-0312-7AE1-8CFE-686FE3860C1B")
ICThreadClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICThreadClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICThreadClassObject*)pObj->Probe(EIID_ICThreadClassObject);
    }

    static CARAPI_(ICThreadClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICThreadClassObject*)pObj->Probe(EIID_ICThreadClassObject);
    }

    static CARAPI_(ICThreadClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithRunnable(
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithRunnableThreadName(
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [in] */ const _ELASTOS String& threadName,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithThreadName(
        /* [in] */ const _ELASTOS String& threadName,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithGroupRunnable(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithGroupRunnableThreadName(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [in] */ const _ELASTOS String& threadName,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithGroupThreadName(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ const _ELASTOS String& threadName,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithGroupRunnableThreadNameStackSize(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [in] */ const _ELASTOS String& threadName,
        /* [in] */ _ELASTOS Int64 stackSize,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithGroupNamePriorityDaemon(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Int32 priority,
        /* [in] */ _ELASTOS Boolean daemon,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("D5D5942E-0312-10E1-6AC8-C031438FD11F")
ICThreadGroupClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICThreadGroupClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICThreadGroupClassObject*)pObj->Probe(EIID_ICThreadGroupClassObject);
    }

    static CARAPI_(ICThreadGroupClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICThreadGroupClassObject*)pObj->Probe(EIID_ICThreadGroupClassObject);
    }

    static CARAPI_(ICThreadGroupClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithName(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithParentName(
        /* [in] */ Elastos::Core::IThreadGroup * parent,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("9A156E37-8312-7AAC-38DE-D763F4477B1B")
ICPathClassLoaderClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPathClassLoaderClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPathClassLoaderClassObject*)pObj->Probe(EIID_ICPathClassLoaderClassObject);
    }

    static CARAPI_(ICPathClassLoaderClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPathClassLoaderClassObject*)pObj->Probe(EIID_ICPathClassLoaderClassObject);
    }

    virtual CARAPI CreateObjectWithClassPathParent(
        /* [in] */ const _ELASTOS String& classPath,
        /* [in] */ Elastos::Core::IClassLoader * parent,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("DCF1593A-0312-7AD8-8CFE-686FE3860C1B")
ICStringClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICStringClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICStringClassObject*)pObj->Probe(EIID_ICStringClassObject);
    }

    static CARAPI_(ICStringClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICStringClassObject*)pObj->Probe(EIID_ICStringClassObject);
    }

    static CARAPI_(ICStringClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithStr(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("18A85C3A-8312-3205-64BC-404122861EA3")
ICBooleanClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICBooleanClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBooleanClassObject*)pObj->Probe(EIID_ICBooleanClassObject);
    }

    static CARAPI_(ICBooleanClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBooleanClassObject*)pObj->Probe(EIID_ICBooleanClassObject);
    }

    static CARAPI_(ICBooleanClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithValue(
        /* [in] */ _ELASTOS Boolean value,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("E10C593D-8312-3736-50E8-31FAA3BD8D1B")
ICByteClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICByteClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICByteClassObject*)pObj->Probe(EIID_ICByteClassObject);
    }

    static CARAPI_(ICByteClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICByteClassObject*)pObj->Probe(EIID_ICByteClassObject);
    }

    static CARAPI_(ICByteClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithValue(
        /* [in] */ _ELASTOS Byte value,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("B2EB5B2C-0312-2B06-48D4-1820408FD11F")
ICChar32ClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICChar32ClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICChar32ClassObject*)pObj->Probe(EIID_ICChar32ClassObject);
    }

    static CARAPI_(ICChar32ClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICChar32ClassObject*)pObj->Probe(EIID_ICChar32ClassObject);
    }

    static CARAPI_(ICChar32ClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithValue(
        /* [in] */ _ELASTOS Char32 value,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("EB5F5E2E-8312-2882-54DC-0F60408FD11F")
ICInteger16ClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICInteger16ClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICInteger16ClassObject*)pObj->Probe(EIID_ICInteger16ClassObject);
    }

    static CARAPI_(ICInteger16ClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICInteger16ClassObject*)pObj->Probe(EIID_ICInteger16ClassObject);
    }

    static CARAPI_(ICInteger16ClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithValue(
        /* [in] */ _ELASTOS Int16 value,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("E9635E2D-8312-2882-54DC-1F20408FD11F")
ICInteger32ClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICInteger32ClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICInteger32ClassObject*)pObj->Probe(EIID_ICInteger32ClassObject);
    }

    static CARAPI_(ICInteger32ClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICInteger32ClassObject*)pObj->Probe(EIID_ICInteger32ClassObject);
    }

    static CARAPI_(ICInteger32ClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithValue(
        /* [in] */ _ELASTOS Int32 value,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("E6615E39-8312-2882-54DC-3740408FD11F")
ICInteger64ClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICInteger64ClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICInteger64ClassObject*)pObj->Probe(EIID_ICInteger64ClassObject);
    }

    static CARAPI_(ICInteger64ClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICInteger64ClassObject*)pObj->Probe(EIID_ICInteger64ClassObject);
    }

    static CARAPI_(ICInteger64ClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithValue(
        /* [in] */ _ELASTOS Int64 value,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("88035A30-8312-2F07-6490-B8A1C7E88FF6")
ICFloatClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICFloatClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFloatClassObject*)pObj->Probe(EIID_ICFloatClassObject);
    }

    static CARAPI_(ICFloatClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICFloatClassObject*)pObj->Probe(EIID_ICFloatClassObject);
    }

    static CARAPI_(ICFloatClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithValue(
        /* [in] */ _ELASTOS Float value,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("889D5B30-8312-385D-4ABC-40A1C7E88FF6")
ICDoubleClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDoubleClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDoubleClassObject*)pObj->Probe(EIID_ICDoubleClassObject);
    }

    static CARAPI_(ICDoubleClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDoubleClassObject*)pObj->Probe(EIID_ICDoubleClassObject);
    }

    static CARAPI_(ICDoubleClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithValue(
        /* [in] */ _ELASTOS Double value,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Core {
CAR_INTERFACE("9E075F24-0312-4B2C-F518-FDD1DEC60D19")
ICArrayOfClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICArrayOfClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICArrayOfClassObject*)pObj->Probe(EIID_ICArrayOfClassObject);
    }

    static CARAPI_(ICArrayOfClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICArrayOfClassObject*)pObj->Probe(EIID_ICArrayOfClassObject);
    }

    static CARAPI_(ICArrayOfClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithRiidSize(
        /* [in] */ const _ELASTOS InterfaceID & riid,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Math {
CAR_INTERFACE("EECE4E4B-8592-2B47-8868-DE71E3878392")
IMathContext : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IMathContext*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMathContext*)pObj->Probe(EIID_IMathContext);
    }

    static CARAPI_(IMathContext*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMathContext*)pObj->Probe(EIID_IMathContext);
    }

    static CARAPI_(IMathContext*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetPrecision(
        /* [out] */ _ELASTOS Int32 * precision) = 0;

    virtual CARAPI GetRoundingMode(
        /* [out] */ Elastos::Math::RoundingMode * roundingMode) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * obj,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI GetHashCode(
        /* [out] */ _ELASTOS Int32 * pCode) = 0;

    virtual CARAPI ToString(
        /* [out] */ _ELASTOS String * string) = 0;

};
}
}

namespace Elastos {
namespace Math {
CAR_INTERFACE("98E15113-4592-2BDE-23C7-37BADF11FACE")
IMathContextHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IMathContextHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMathContextHelper*)pObj->Probe(EIID_IMathContextHelper);
    }

    static CARAPI_(IMathContextHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IMathContextHelper*)pObj->Probe(EIID_IMathContextHelper);
    }

    static CARAPI_(IMathContextHelper*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI GetDECIMAL32(
        /* [out] */ Elastos::Math::IMathContext ** context) = 0;

    virtual CARAPI GetDECIMAL64(
        /* [out] */ Elastos::Math::IMathContext ** context) = 0;

    virtual CARAPI GetDECIMAL128(
        /* [out] */ Elastos::Math::IMathContext ** context) = 0;

    virtual CARAPI GetUNLIMITED(
        /* [out] */ Elastos::Math::IMathContext ** context) = 0;

};
}
}

namespace Elastos {
namespace Math {
CAR_INTERFACE("3905F44F-02D2-2A16-8EA8-CAF9E2878392")
IBigDecimal : public IInterface
{
    static const _ELASTOS Int32 ROUND_UP = 0;
    static const _ELASTOS Int32 ROUND_DOWN = 1;
    static const _ELASTOS Int32 ROUND_CEILING = 2;
    static const _ELASTOS Int32 ROUND_FLOOR = 3;
    static const _ELASTOS Int32 ROUND_HALF_UP = 4;
    static const _ELASTOS Int32 ROUND_HALF_DOWN = 5;
    static const _ELASTOS Int32 ROUND_HALF_EVEN = 6;
    static const _ELASTOS Int32 ROUND_UNNECESSARY = 7;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IBigDecimal*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBigDecimal*)pObj->Probe(EIID_IBigDecimal);
    }

    static CARAPI_(IBigDecimal*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBigDecimal*)pObj->Probe(EIID_IBigDecimal);
    }

    static CARAPI_(IBigDecimal*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI Add(
        /* [in] */ Elastos::Math::IBigDecimal * augend,
        /* [out] */ Elastos::Math::IBigDecimal ** result) = 0;

    virtual CARAPI Add(
        /* [in] */ Elastos::Math::IBigDecimal * augend,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Math::IBigDecimal ** result) = 0;

    virtual CARAPI Subtract(
        /* [in] */ Elastos::Math::IBigDecimal * subtrahend,
        /* [out] */ Elastos::Math::IBigDecimal ** result) = 0;

    virtual CARAPI Subtract(
        /* [in] */ Elastos::Math::IBigDecimal * subtrahend,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Math::IBigDecimal ** result) = 0;

    virtual CARAPI Multiply(
        /* [in] */ Elastos::Math::IBigDecimal * multiplicand,
        /* [out] */ Elastos::Math::IBigDecimal ** result) = 0;

    virtual CARAPI Multiply(
        /* [in] */ Elastos::Math::IBigDecimal * multiplicand,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Math::IBigDecimal ** result) = 0;

    virtual CARAPI Divide(
        /* [in] */ Elastos::Math::IBigDecimal * divisor,
        /* [in] */ _ELASTOS Int32 scale,
        /* [in] */ Elastos::Math::RoundingMode roundingMode,
        /* [out] */ Elastos::Math::IBigDecimal ** result) = 0;

    virtual CARAPI Divide(
        /* [in] */ Elastos::Math::IBigDecimal * divisor,
        /* [in] */ Elastos::Math::RoundingMode roundingMode,
        /* [out] */ Elastos::Math::IBigDecimal ** result) = 0;

    virtual CARAPI Divide(
        /* [in] */ Elastos::Math::IBigDecimal * divisor,
        /* [out] */ Elastos::Math::IBigDecimal ** result) = 0;

    virtual CARAPI Divide(
        /* [in] */ Elastos::Math::IBigDecimal * divisor,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Math::IBigDecimal ** result) = 0;

    virtual CARAPI DivideToIntegralValue(
        /* [in] */ Elastos::Math::IBigDecimal * divisor,
        /* [out] */ Elastos::Math::IBigDecimal ** result) = 0;

    virtual CARAPI DivideToIntegralValue(
        /* [in] */ Elastos::Math::IBigDecimal * divisor,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Math::IBigDecimal ** result) = 0;

    virtual CARAPI Remainder(
        /* [in] */ Elastos::Math::IBigDecimal * divisor,
        /* [out] */ Elastos::Math::IBigDecimal ** result) = 0;

    virtual CARAPI Remainder(
        /* [in] */ Elastos::Math::IBigDecimal * divisor,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Math::IBigDecimal ** result) = 0;

    virtual CARAPI DivideAndRemainder(
        /* [in] */ Elastos::Math::IBigDecimal * divisor,
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Math::IBigDecimal *> ** result) = 0;

    virtual CARAPI DivideAndRemainder(
        /* [in] */ Elastos::Math::IBigDecimal * divisor,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Math::IBigDecimal *> ** result) = 0;

    virtual CARAPI Pow(
        /* [in] */ _ELASTOS Int32 n,
        /* [out] */ Elastos::Math::IBigDecimal ** result) = 0;

    virtual CARAPI Pow(
        /* [in] */ _ELASTOS Int32 n,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Math::IBigDecimal ** result) = 0;

    virtual CARAPI Abs(
        /* [out] */ Elastos::Math::IBigDecimal ** result) = 0;

    virtual CARAPI Abs(
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Math::IBigDecimal ** result) = 0;

    virtual CARAPI Negate(
        /* [out] */ Elastos::Math::IBigDecimal ** result) = 0;

    virtual CARAPI Negate(
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Math::IBigDecimal ** result) = 0;

    virtual CARAPI Plus(
        /* [out] */ Elastos::Math::IBigDecimal ** result) = 0;

    virtual CARAPI Plus(
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Math::IBigDecimal ** result) = 0;

    virtual CARAPI GetSignum(
        /* [out] */ _ELASTOS Int32 * sign) = 0;

    virtual CARAPI GetScale(
        /* [out] */ _ELASTOS Int32 * scale) = 0;

    virtual CARAPI GetPrecision(
        /* [out] */ _ELASTOS Int32 * precision) = 0;

    virtual CARAPI GetUnscaledValue(
        /* [out] */ Elastos::Math::IBigInteger ** value) = 0;

    virtual CARAPI Round(
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Math::IBigDecimal ** result) = 0;

    virtual CARAPI SetScale(
        /* [in] */ _ELASTOS Int32 newScale,
        /* [in] */ Elastos::Math::RoundingMode roundingMode,
        /* [out] */ Elastos::Math::IBigDecimal ** result) = 0;

    virtual CARAPI SetScale(
        /* [in] */ _ELASTOS Int32 newScale,
        /* [out] */ Elastos::Math::IBigDecimal ** result) = 0;

    virtual CARAPI MovePointLeft(
        /* [in] */ _ELASTOS Int32 n,
        /* [out] */ Elastos::Math::IBigDecimal ** result) = 0;

    virtual CARAPI MovePointRight(
        /* [in] */ _ELASTOS Int32 n,
        /* [out] */ Elastos::Math::IBigDecimal ** result) = 0;

    virtual CARAPI ScaleByPowerOfTen(
        /* [in] */ _ELASTOS Int32 n,
        /* [out] */ Elastos::Math::IBigDecimal ** result) = 0;

    virtual CARAPI StripTrailingZeros(
        /* [out] */ Elastos::Math::IBigDecimal ** result) = 0;

    virtual CARAPI Min(
        /* [in] */ Elastos::Math::IBigDecimal * val,
        /* [out] */ Elastos::Math::IBigDecimal ** result) = 0;

    virtual CARAPI Max(
        /* [in] */ Elastos::Math::IBigDecimal * val,
        /* [out] */ Elastos::Math::IBigDecimal ** result) = 0;

    virtual CARAPI ToEngineeringString(
        /* [out] */ _ELASTOS String * representation) = 0;

    virtual CARAPI ToPlainString(
        /* [out] */ _ELASTOS String * representation) = 0;

    virtual CARAPI ToBigInteger(
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

    virtual CARAPI ToBigIntegerExact(
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

    virtual CARAPI Int64ValueExact(
        /* [out] */ _ELASTOS Int64 * value) = 0;

    virtual CARAPI Int32ValueExact(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI Int16ValueExact(
        /* [out] */ _ELASTOS Int16 * value) = 0;

    virtual CARAPI ByteValueExact(
        /* [out] */ _ELASTOS Byte * value) = 0;

    virtual CARAPI Ulp(
        /* [out] */ Elastos::Math::IBigDecimal ** newObj) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * obj,
        /* [out] */ _ELASTOS Boolean * result) = 0;

};
}
}

namespace Elastos {
namespace Math {
CAR_INTERFACE("E724471F-C2D2-0DAA-6AB2-30F946E83BA3")
IBigDecimalHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IBigDecimalHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBigDecimalHelper*)pObj->Probe(EIID_IBigDecimalHelper);
    }

    static CARAPI_(IBigDecimalHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBigDecimalHelper*)pObj->Probe(EIID_IBigDecimalHelper);
    }

    static CARAPI_(IBigDecimalHelper*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI ValueOf(
        /* [in] */ _ELASTOS Int64 unscaledVal,
        /* [in] */ _ELASTOS Int32 scale,
        /* [out] */ Elastos::Math::IBigDecimal ** newObj) = 0;

    virtual CARAPI ValueOf(
        /* [in] */ _ELASTOS Int64 unscaledVal,
        /* [out] */ Elastos::Math::IBigDecimal ** newObj) = 0;

    virtual CARAPI ValueOf(
        /* [in] */ _ELASTOS Double val,
        /* [out] */ Elastos::Math::IBigDecimal ** newObj) = 0;

    virtual CARAPI GetZERO(
        /* [out] */ Elastos::Math::IBigDecimal ** zero) = 0;

    virtual CARAPI GetONE(
        /* [out] */ Elastos::Math::IBigDecimal ** one) = 0;

    virtual CARAPI GetTEN(
        /* [out] */ Elastos::Math::IBigDecimal ** ten) = 0;

};
}
}

namespace Elastos {
namespace Math {
CAR_INTERFACE("DF99F852-02D2-2A16-B668-4657E3878392")
IBigInteger : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IBigInteger*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBigInteger*)pObj->Probe(EIID_IBigInteger);
    }

    static CARAPI_(IBigInteger*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBigInteger*)pObj->Probe(EIID_IBigInteger);
    }

    static CARAPI_(IBigInteger*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI ToByteArray(
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Byte> ** bytes) = 0;

    virtual CARAPI Abs(
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

    virtual CARAPI Negate(
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

    virtual CARAPI Add(
        /* [in] */ Elastos::Math::IBigInteger * value,
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

    virtual CARAPI Subtract(
        /* [in] */ Elastos::Math::IBigInteger * value,
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

    virtual CARAPI GetSignum(
        /* [out] */ _ELASTOS Int32 * sign) = 0;

    virtual CARAPI ShiftRight(
        /* [in] */ _ELASTOS Int32 n,
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

    virtual CARAPI ShiftLeft(
        /* [in] */ _ELASTOS Int32 n,
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

    virtual CARAPI ShiftLeftOneBit(
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

    virtual CARAPI BitLength(
        /* [out] */ _ELASTOS Int32 * length) = 0;

    virtual CARAPI TestBit(
        /* [in] */ _ELASTOS Int32 n,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI SetBit(
        /* [in] */ _ELASTOS Int32 n,
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

    virtual CARAPI ClearBit(
        /* [in] */ _ELASTOS Int32 n,
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

    virtual CARAPI FlipBit(
        /* [in] */ _ELASTOS Int32 n,
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

    virtual CARAPI GetLowestSetBit(
        /* [out] */ _ELASTOS Int32 * position) = 0;

    virtual CARAPI BitCount(
        /* [out] */ _ELASTOS Int32 * number) = 0;

    virtual CARAPI Not(
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

    virtual CARAPI And(
        /* [in] */ Elastos::Math::IBigInteger * value,
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

    virtual CARAPI Or(
        /* [in] */ Elastos::Math::IBigInteger * value,
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

    virtual CARAPI Xor(
        /* [in] */ Elastos::Math::IBigInteger * value,
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

    virtual CARAPI AndNot(
        /* [in] */ Elastos::Math::IBigInteger * value,
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

    virtual CARAPI Min(
        /* [in] */ Elastos::Math::IBigInteger * value,
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

    virtual CARAPI Max(
        /* [in] */ Elastos::Math::IBigInteger * value,
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

    virtual CARAPI Gcd(
        /* [in] */ Elastos::Math::IBigInteger * value,
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

    virtual CARAPI Multiply(
        /* [in] */ Elastos::Math::IBigInteger * value,
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

    virtual CARAPI Pow(
        /* [in] */ _ELASTOS Int32 exp,
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

    virtual CARAPI DivideAndRemainder(
        /* [in] */ Elastos::Math::IBigInteger * divisor,
        /* [out, callee] */ _ELASTOS ArrayOf<Elastos::Math::IBigInteger *> ** bigIntegerArray) = 0;

    virtual CARAPI Divide(
        /* [in] */ Elastos::Math::IBigInteger * divisor,
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

    virtual CARAPI Remainder(
        /* [in] */ Elastos::Math::IBigInteger * divisor,
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

    virtual CARAPI ModInverse(
        /* [in] */ Elastos::Math::IBigInteger * divisor,
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

    virtual CARAPI ModPow(
        /* [in] */ Elastos::Math::IBigInteger * exponent,
        /* [in] */ Elastos::Math::IBigInteger * m,
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

    virtual CARAPI Mod(
        /* [in] */ Elastos::Math::IBigInteger * m,
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

    virtual CARAPI IsProbablePrime(
        /* [in] */ _ELASTOS Int32 certainty,
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI NextProbablePrime(
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

    virtual CARAPI ToString(
        /* [in] */ _ELASTOS Int32 radix,
        /* [out] */ _ELASTOS String * string) = 0;

    virtual CARAPI Equals(
        /* [in] */ IInterface * obj,
        /* [out] */ _ELASTOS Boolean * result) = 0;

};
}
}

namespace Elastos {
namespace Math {
CAR_INTERFACE("E89B440C-C2D2-52AA-7CA3-2A5A47E83BA3")
IBigIntegerHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IBigIntegerHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBigIntegerHelper*)pObj->Probe(EIID_IBigIntegerHelper);
    }

    static CARAPI_(IBigIntegerHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IBigIntegerHelper*)pObj->Probe(EIID_IBigIntegerHelper);
    }

    static CARAPI_(IBigIntegerHelper*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI ValueOf(
        /* [in] */ _ELASTOS Int64 value,
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

    virtual CARAPI GetMINUSOne(
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

    virtual CARAPI GetZERO(
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

    virtual CARAPI GetONE(
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

    virtual CARAPI GetTEN(
        /* [out] */ Elastos::Math::IBigInteger ** result) = 0;

};
}
}

namespace Elastos {
namespace Math {
CAR_INTERFACE("07A6F52E-8312-2C05-5488-620183C40B3D")
ICBigDecimalClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICBigDecimalClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBigDecimalClassObject*)pObj->Probe(EIID_ICBigDecimalClassObject);
    }

    static CARAPI_(ICBigDecimalClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBigDecimalClassObject*)pObj->Probe(EIID_ICBigDecimalClassObject);
    }

    static CARAPI_(ICBigDecimalClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithI32Value(
        /* [in] */ _ELASTOS Int32 i32Value,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithI64Value(
        /* [in] */ _ELASTOS Int64 i64Value,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithDValue(
        /* [in] */ _ELASTOS Double dValue,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithI64SmallValueScale(
        /* [in] */ _ELASTOS Int64 i64SmallValue,
        /* [in] */ _ELASTOS Int32 scale,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithI32SmallValueScale(
        /* [in] */ _ELASTOS Int32 i32SmallValue,
        /* [in] */ _ELASTOS Int32 scale,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithSVal(
        /* [in] */ const _ELASTOS String& sVal,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithBuf(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & buf,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithBufOffsetLength(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithVal(
        /* [in] */ Elastos::Math::IBigInteger * val,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithValScale(
        /* [in] */ Elastos::Math::IBigInteger * val,
        /* [in] */ _ELASTOS Int32 scale,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithValScaleMc(
        /* [in] */ Elastos::Math::IBigInteger * val,
        /* [in] */ _ELASTOS Int32 scale,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithBufOffsetLengthMc(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithBufMc(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & buf,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithStrValMc(
        /* [in] */ const _ELASTOS String& strVal,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithDValMc(
        /* [in] */ _ELASTOS Double dVal,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithBigIntegerValMc(
        /* [in] */ Elastos::Math::IBigInteger * bigIntegerVal,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithInt32ValMc(
        /* [in] */ _ELASTOS Int32 int32Val,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithInt64ValMc(
        /* [in] */ _ELASTOS Int64 int64Val,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Math {
CAR_INTERFACE("44B46B1E-B312-6AB0-839A-2C4CBE11FACE")
ICBigDecimalHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICBigDecimalHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBigDecimalHelperClassObject*)pObj->Probe(EIID_ICBigDecimalHelperClassObject);
    }

    static CARAPI_(ICBigDecimalHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBigDecimalHelperClassObject*)pObj->Probe(EIID_ICBigDecimalHelperClassObject);
    }

    static CARAPI_(ICBigDecimalHelperClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Math {
CAR_INTERFACE("734EFE25-8312-2C05-5414-44A1E2BE1EA3")
ICBigIntegerClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICBigIntegerClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBigIntegerClassObject*)pObj->Probe(EIID_ICBigIntegerClassObject);
    }

    static CARAPI_(ICBigIntegerClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBigIntegerClassObject*)pObj->Probe(EIID_ICBigIntegerClassObject);
    }

    static CARAPI_(ICBigIntegerClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithSignValue(
        /* [in] */ _ELASTOS Int32 sign,
        /* [in] */ _ELASTOS Int64 value,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithSignNumberLengthDigits(
        /* [in] */ _ELASTOS Int32 sign,
        /* [in] */ _ELASTOS Int32 numberLength,
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Int32> & digits,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithValue(
        /* [in] */ const _ELASTOS String& value,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithValueRadix(
        /* [in] */ const _ELASTOS String& value,
        /* [in] */ _ELASTOS Int32 radix,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithSignumMagnitude(
        /* [in] */ _ELASTOS Int32 signum,
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Byte> & magnitude,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithArrValue(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Byte> & arrValue,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Math {
CAR_INTERFACE("2EAB6B05-B312-AAB0-14DF-A88AD611FACE")
ICBigIntegerHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICBigIntegerHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBigIntegerHelperClassObject*)pObj->Probe(EIID_ICBigIntegerHelperClassObject);
    }

    static CARAPI_(ICBigIntegerHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICBigIntegerHelperClassObject*)pObj->Probe(EIID_ICBigIntegerHelperClassObject);
    }

    static CARAPI_(ICBigIntegerHelperClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Math {
CAR_INTERFACE("F29E8902-6312-F791-CAC8-F18DEE37F392")
ICMathContextClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICMathContextClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICMathContextClassObject*)pObj->Probe(EIID_ICMathContextClassObject);
    }

    static CARAPI_(ICMathContextClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICMathContextClassObject*)pObj->Probe(EIID_ICMathContextClassObject);
    }

    static CARAPI_(ICMathContextClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithPrecision(
        /* [in] */ _ELASTOS Int32 precision,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithPrecisionRoundingMode(
        /* [in] */ _ELASTOS Int32 precision,
        /* [in] */ Elastos::Math::RoundingMode roundingMode,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace Math {
CAR_INTERFACE("FA4F6C0A-6312-F791-CAC8-F18DEE7784BE")
ICMathContextHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICMathContextHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICMathContextHelperClassObject*)pObj->Probe(EIID_ICMathContextHelperClassObject);
    }

    static CARAPI_(ICMathContextHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICMathContextHelperClassObject*)pObj->Probe(EIID_ICMathContextHelperClassObject);
    }

    static CARAPI_(ICMathContextHelperClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

namespace Elastos {
namespace IO {
CAR_INTERFACE("20894850-0652-1293-1FB0-48F9C3414919")
IPlainFile : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IPlainFile*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPlainFile*)pObj->Probe(EIID_IPlainFile);
    }

    static CARAPI_(IPlainFile*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IPlainFile*)pObj->Probe(EIID_IPlainFile);
    }

    static CARAPI_(IPlainFile*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI Exists(
        /* [out] */ _ELASTOS Boolean * exists) = 0;

    virtual CARAPI IsDir(
        /* [out] */ _ELASTOS Boolean * isDir) = 0;

    virtual CARAPI IsFile(
        /* [out] */ _ELASTOS Boolean * isFile) = 0;

    virtual CARAPI Delete() = 0;

    virtual CARAPI Mkdir() = 0;

    virtual CARAPI Mkdirs() = 0;

    virtual CARAPI Write(
        /* [in] */ const _ELASTOS String& content) = 0;

    virtual CARAPI Read(
        /* [out] */ _ELASTOS String * content) = 0;

    virtual CARAPI GetPath(
        /* [out] */ _ELASTOS String * path) = 0;

};
}
}

namespace Elastos {
namespace IO {
CAR_INTERFACE("54987125-8312-2F0C-48B0-88414D8FD11F")
ICPlainFileClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICPlainFileClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPlainFileClassObject*)pObj->Probe(EIID_ICPlainFileClassObject);
    }

    static CARAPI_(ICPlainFileClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICPlainFileClassObject*)pObj->Probe(EIID_ICPlainFileClassObject);
    }

    static CARAPI_(ICPlainFileClassObject*) QueryInterface(const Elastos::String& uid)
    {
        return NULL;
    }

    virtual CARAPI CreateObjectWithDir(
        /* [in] */ const _ELASTOS String& dir,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithDirName(
        /* [in] */ const _ELASTOS String& dir,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Core {
class CObject
{
public:
    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CObject, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CObject, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CObject, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Core {
class CThread
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICThreadClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CThread, RGM_SAME_DOMAIN,
                EIID_ICThreadClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithRunnable(runnable, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [in] */ const _ELASTOS String& threadName,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICThreadClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CThread, RGM_SAME_DOMAIN,
                EIID_ICThreadClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithRunnableThreadName(runnable, threadName, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& threadName,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICThreadClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CThread, RGM_SAME_DOMAIN,
                EIID_ICThreadClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithThreadName(threadName, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICThreadClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CThread, RGM_SAME_DOMAIN,
                EIID_ICThreadClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithGroupRunnable(group, runnable, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [in] */ const _ELASTOS String& threadName,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICThreadClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CThread, RGM_SAME_DOMAIN,
                EIID_ICThreadClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithGroupRunnableThreadName(group, runnable, threadName, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ const _ELASTOS String& threadName,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICThreadClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CThread, RGM_SAME_DOMAIN,
                EIID_ICThreadClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithGroupThreadName(group, threadName, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [in] */ const _ELASTOS String& threadName,
        /* [in] */ _ELASTOS Int64 stackSize,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICThreadClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CThread, RGM_SAME_DOMAIN,
                EIID_ICThreadClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithGroupRunnableThreadNameStackSize(group, runnable, threadName, stackSize, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Int32 priority,
        /* [in] */ _ELASTOS Boolean daemon,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICThreadClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CThread, RGM_SAME_DOMAIN,
                EIID_ICThreadClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithGroupNamePriorityDaemon(group, name, priority, daemon, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::IThread** __object)
    {
        return _CObject_CreateInstance(ECLSID_CThread, RGM_SAME_DOMAIN, Elastos::Core::EIID_IThread, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::IRunnable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CThread, RGM_SAME_DOMAIN, Elastos::Core::EIID_IRunnable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CThread, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CThread, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CThread, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [out] */ Elastos::Core::IThread** __IThread)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(runnable, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IThread = (Elastos::Core::IThread*)__pNewObj->Probe(Elastos::Core::EIID_IThread);
        if (*__IThread) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [out] */ Elastos::Core::IRunnable** __IRunnable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(runnable, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRunnable = (Elastos::Core::IRunnable*)__pNewObj->Probe(Elastos::Core::EIID_IRunnable);
        if (*__IRunnable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(runnable, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(runnable, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(runnable, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [in] */ const _ELASTOS String& threadName,
        /* [out] */ Elastos::Core::IThread** __IThread)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(runnable, threadName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IThread = (Elastos::Core::IThread*)__pNewObj->Probe(Elastos::Core::EIID_IThread);
        if (*__IThread) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [in] */ const _ELASTOS String& threadName,
        /* [out] */ Elastos::Core::IRunnable** __IRunnable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(runnable, threadName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRunnable = (Elastos::Core::IRunnable*)__pNewObj->Probe(Elastos::Core::EIID_IRunnable);
        if (*__IRunnable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [in] */ const _ELASTOS String& threadName,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(runnable, threadName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [in] */ const _ELASTOS String& threadName,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(runnable, threadName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [in] */ const _ELASTOS String& threadName,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(runnable, threadName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& threadName,
        /* [out] */ Elastos::Core::IThread** __IThread)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(threadName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IThread = (Elastos::Core::IThread*)__pNewObj->Probe(Elastos::Core::EIID_IThread);
        if (*__IThread) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& threadName,
        /* [out] */ Elastos::Core::IRunnable** __IRunnable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(threadName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRunnable = (Elastos::Core::IRunnable*)__pNewObj->Probe(Elastos::Core::EIID_IRunnable);
        if (*__IRunnable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& threadName,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(threadName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& threadName,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(threadName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& threadName,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(threadName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [out] */ Elastos::Core::IThread** __IThread)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(group, runnable, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IThread = (Elastos::Core::IThread*)__pNewObj->Probe(Elastos::Core::EIID_IThread);
        if (*__IThread) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [out] */ Elastos::Core::IRunnable** __IRunnable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(group, runnable, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRunnable = (Elastos::Core::IRunnable*)__pNewObj->Probe(Elastos::Core::EIID_IRunnable);
        if (*__IRunnable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(group, runnable, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(group, runnable, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(group, runnable, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [in] */ const _ELASTOS String& threadName,
        /* [out] */ Elastos::Core::IThread** __IThread)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(group, runnable, threadName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IThread = (Elastos::Core::IThread*)__pNewObj->Probe(Elastos::Core::EIID_IThread);
        if (*__IThread) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [in] */ const _ELASTOS String& threadName,
        /* [out] */ Elastos::Core::IRunnable** __IRunnable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(group, runnable, threadName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRunnable = (Elastos::Core::IRunnable*)__pNewObj->Probe(Elastos::Core::EIID_IRunnable);
        if (*__IRunnable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [in] */ const _ELASTOS String& threadName,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(group, runnable, threadName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [in] */ const _ELASTOS String& threadName,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(group, runnable, threadName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [in] */ const _ELASTOS String& threadName,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(group, runnable, threadName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ const _ELASTOS String& threadName,
        /* [out] */ Elastos::Core::IThread** __IThread)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(group, threadName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IThread = (Elastos::Core::IThread*)__pNewObj->Probe(Elastos::Core::EIID_IThread);
        if (*__IThread) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ const _ELASTOS String& threadName,
        /* [out] */ Elastos::Core::IRunnable** __IRunnable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(group, threadName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRunnable = (Elastos::Core::IRunnable*)__pNewObj->Probe(Elastos::Core::EIID_IRunnable);
        if (*__IRunnable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ const _ELASTOS String& threadName,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(group, threadName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ const _ELASTOS String& threadName,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(group, threadName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ const _ELASTOS String& threadName,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(group, threadName, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [in] */ const _ELASTOS String& threadName,
        /* [in] */ _ELASTOS Int64 stackSize,
        /* [out] */ Elastos::Core::IThread** __IThread)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(group, runnable, threadName, stackSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IThread = (Elastos::Core::IThread*)__pNewObj->Probe(Elastos::Core::EIID_IThread);
        if (*__IThread) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [in] */ const _ELASTOS String& threadName,
        /* [in] */ _ELASTOS Int64 stackSize,
        /* [out] */ Elastos::Core::IRunnable** __IRunnable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(group, runnable, threadName, stackSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRunnable = (Elastos::Core::IRunnable*)__pNewObj->Probe(Elastos::Core::EIID_IRunnable);
        if (*__IRunnable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [in] */ const _ELASTOS String& threadName,
        /* [in] */ _ELASTOS Int64 stackSize,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(group, runnable, threadName, stackSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [in] */ const _ELASTOS String& threadName,
        /* [in] */ _ELASTOS Int64 stackSize,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(group, runnable, threadName, stackSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ Elastos::Core::IRunnable * runnable,
        /* [in] */ const _ELASTOS String& threadName,
        /* [in] */ _ELASTOS Int64 stackSize,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(group, runnable, threadName, stackSize, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Int32 priority,
        /* [in] */ _ELASTOS Boolean daemon,
        /* [out] */ Elastos::Core::IThread** __IThread)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(group, name, priority, daemon, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IThread = (Elastos::Core::IThread*)__pNewObj->Probe(Elastos::Core::EIID_IThread);
        if (*__IThread) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Int32 priority,
        /* [in] */ _ELASTOS Boolean daemon,
        /* [out] */ Elastos::Core::IRunnable** __IRunnable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(group, name, priority, daemon, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IRunnable = (Elastos::Core::IRunnable*)__pNewObj->Probe(Elastos::Core::EIID_IRunnable);
        if (*__IRunnable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Int32 priority,
        /* [in] */ _ELASTOS Boolean daemon,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(group, name, priority, daemon, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Int32 priority,
        /* [in] */ _ELASTOS Boolean daemon,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(group, name, priority, daemon, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IThreadGroup * group,
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Int32 priority,
        /* [in] */ _ELASTOS Boolean daemon,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(group, name, priority, daemon, &__pNewObj);
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
namespace Core {
class CThreadGroup
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICThreadGroupClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CThreadGroup, RGM_SAME_DOMAIN,
                EIID_ICThreadGroupClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithName(name, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Core::IThreadGroup * parent,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICThreadGroupClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CThreadGroup, RGM_SAME_DOMAIN,
                EIID_ICThreadGroupClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithParentName(parent, name, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::IThreadGroup** __object)
    {
        return _CObject_CreateInstance(ECLSID_CThreadGroup, RGM_SAME_DOMAIN, Elastos::Core::EIID_IThreadGroup, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CThreadGroup, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CThreadGroup, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CThreadGroup, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Core::IThreadGroup** __IThreadGroup)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IThreadGroup = (Elastos::Core::IThreadGroup*)__pNewObj->Probe(Elastos::Core::EIID_IThreadGroup);
        if (*__IThreadGroup) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IThreadGroup * parent,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Core::IThreadGroup** __IThreadGroup)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parent, name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IThreadGroup = (Elastos::Core::IThreadGroup*)__pNewObj->Probe(Elastos::Core::EIID_IThreadGroup);
        if (*__IThreadGroup) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IThreadGroup * parent,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parent, name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IThreadGroup * parent,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parent, name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Core::IThreadGroup * parent,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parent, name, &__pNewObj);
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
namespace Core {
class CPathClassLoader
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& classPath,
        /* [in] */ Elastos::Core::IClassLoader * parent,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPathClassLoaderClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPathClassLoader, RGM_SAME_DOMAIN,
                EIID_ICPathClassLoaderClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithClassPathParent(classPath, parent, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& classPath,
        /* [in] */ Elastos::Core::IClassLoader * parent,
        /* [out] */ Elastos::Core::IClassLoader** __IClassLoader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(classPath, parent, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IClassLoader = (Elastos::Core::IClassLoader*)__pNewObj->Probe(Elastos::Core::EIID_IClassLoader);
        if (*__IClassLoader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& classPath,
        /* [in] */ Elastos::Core::IClassLoader * parent,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(classPath, parent, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& classPath,
        /* [in] */ Elastos::Core::IClassLoader * parent,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(classPath, parent, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& classPath,
        /* [in] */ Elastos::Core::IClassLoader * parent,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(classPath, parent, &__pNewObj);
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
namespace Core {
class CString
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICStringClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CString, RGM_SAME_DOMAIN,
                EIID_ICStringClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithStr(str, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ Elastos::Core::ICharSequence** __ICharSequence)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(str, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ICharSequence = (Elastos::Core::ICharSequence*)__pNewObj->Probe(Elastos::Core::EIID_ICharSequence);
        if (*__ICharSequence) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ Elastos::Core::IString** __IString)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(str, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IString = (Elastos::Core::IString*)__pNewObj->Probe(Elastos::Core::EIID_IString);
        if (*__IString) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(str, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(str, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(str, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(str, &__pNewObj);
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
namespace Core {
class CBoolean
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Boolean value,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBooleanClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBoolean, RGM_SAME_DOMAIN,
                EIID_ICBooleanClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithValue(value, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Boolean value,
        /* [out] */ Elastos::Core::IBoolean** __IBoolean)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBoolean = (Elastos::Core::IBoolean*)__pNewObj->Probe(Elastos::Core::EIID_IBoolean);
        if (*__IBoolean) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Boolean value,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Boolean value,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Boolean value,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Boolean value,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Boolean value,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
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
namespace Core {
class CByte
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Byte value,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICByteClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CByte, RGM_SAME_DOMAIN,
                EIID_ICByteClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithValue(value, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Byte value,
        /* [out] */ Elastos::Core::IByte** __IByte)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IByte = (Elastos::Core::IByte*)__pNewObj->Probe(Elastos::Core::EIID_IByte);
        if (*__IByte) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Byte value,
        /* [out] */ Elastos::Core::INumber** __INumber)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumber = (Elastos::Core::INumber*)__pNewObj->Probe(Elastos::Core::EIID_INumber);
        if (*__INumber) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Byte value,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Byte value,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Byte value,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Byte value,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Byte value,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
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
namespace Core {
class CChar32
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Char32 value,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICChar32ClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CChar32, RGM_SAME_DOMAIN,
                EIID_ICChar32ClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithValue(value, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Char32 value,
        /* [out] */ Elastos::Core::IChar32** __IChar32)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IChar32 = (Elastos::Core::IChar32*)__pNewObj->Probe(Elastos::Core::EIID_IChar32);
        if (*__IChar32) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Char32 value,
        /* [out] */ Elastos::Core::INumber** __INumber)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumber = (Elastos::Core::INumber*)__pNewObj->Probe(Elastos::Core::EIID_INumber);
        if (*__INumber) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Char32 value,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Char32 value,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Char32 value,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Char32 value,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
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
namespace Core {
class CInteger16
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int16 value,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICInteger16ClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CInteger16, RGM_SAME_DOMAIN,
                EIID_ICInteger16ClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithValue(value, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int16 value,
        /* [out] */ Elastos::Core::IInteger16** __IInteger16)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInteger16 = (Elastos::Core::IInteger16*)__pNewObj->Probe(Elastos::Core::EIID_IInteger16);
        if (*__IInteger16) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int16 value,
        /* [out] */ Elastos::Core::INumber** __INumber)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumber = (Elastos::Core::INumber*)__pNewObj->Probe(Elastos::Core::EIID_INumber);
        if (*__INumber) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int16 value,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int16 value,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int16 value,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int16 value,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int16 value,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
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
namespace Core {
class CInteger32
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 value,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICInteger32ClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CInteger32, RGM_SAME_DOMAIN,
                EIID_ICInteger32ClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithValue(value, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 value,
        /* [out] */ Elastos::Core::IInteger32** __IInteger32)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInteger32 = (Elastos::Core::IInteger32*)__pNewObj->Probe(Elastos::Core::EIID_IInteger32);
        if (*__IInteger32) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 value,
        /* [out] */ Elastos::Core::INumber** __INumber)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumber = (Elastos::Core::INumber*)__pNewObj->Probe(Elastos::Core::EIID_INumber);
        if (*__INumber) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 value,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 value,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 value,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 value,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 value,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
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
namespace Core {
class CInteger64
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int64 value,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICInteger64ClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CInteger64, RGM_SAME_DOMAIN,
                EIID_ICInteger64ClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithValue(value, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 value,
        /* [out] */ Elastos::Core::IInteger64** __IInteger64)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInteger64 = (Elastos::Core::IInteger64*)__pNewObj->Probe(Elastos::Core::EIID_IInteger64);
        if (*__IInteger64) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 value,
        /* [out] */ Elastos::Core::INumber** __INumber)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumber = (Elastos::Core::INumber*)__pNewObj->Probe(Elastos::Core::EIID_INumber);
        if (*__INumber) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 value,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 value,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 value,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 value,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 value,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
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
namespace Core {
class CFloat
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Float value,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICFloatClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CFloat, RGM_SAME_DOMAIN,
                EIID_ICFloatClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithValue(value, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Float value,
        /* [out] */ Elastos::Core::IFloat** __IFloat)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IFloat = (Elastos::Core::IFloat*)__pNewObj->Probe(Elastos::Core::EIID_IFloat);
        if (*__IFloat) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Float value,
        /* [out] */ Elastos::Core::INumber** __INumber)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumber = (Elastos::Core::INumber*)__pNewObj->Probe(Elastos::Core::EIID_INumber);
        if (*__INumber) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Float value,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Float value,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Float value,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Float value,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Float value,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
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
namespace Core {
class CDouble
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Double value,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDoubleClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDouble, RGM_SAME_DOMAIN,
                EIID_ICDoubleClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithValue(value, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Double value,
        /* [out] */ Elastos::Core::IDouble** __IDouble)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDouble = (Elastos::Core::IDouble*)__pNewObj->Probe(Elastos::Core::EIID_IDouble);
        if (*__IDouble) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Double value,
        /* [out] */ Elastos::Core::INumber** __INumber)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumber = (Elastos::Core::INumber*)__pNewObj->Probe(Elastos::Core::EIID_INumber);
        if (*__INumber) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Double value,
        /* [out] */ Elastos::IO::ISerializable** __ISerializable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISerializable = (Elastos::IO::ISerializable*)__pNewObj->Probe(Elastos::IO::EIID_ISerializable);
        if (*__ISerializable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Double value,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Double value,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Double value,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Double value,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
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
namespace Core {
class CArrayOf
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS InterfaceID & riid,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICArrayOfClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CArrayOf, RGM_SAME_DOMAIN,
                EIID_ICArrayOfClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithRiidSize(riid, size, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS InterfaceID & riid,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::Core::IArrayOf** __IArrayOf)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(riid, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IArrayOf = (Elastos::Core::IArrayOf*)__pNewObj->Probe(Elastos::Core::EIID_IArrayOf);
        if (*__IArrayOf) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS InterfaceID & riid,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(riid, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS InterfaceID & riid,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(riid, size, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS InterfaceID & riid,
        /* [in] */ _ELASTOS Int32 size,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(riid, size, &__pNewObj);
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
namespace Math {
class CBigDecimal
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 i32Value,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBigDecimalClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBigDecimal, RGM_SAME_DOMAIN,
                EIID_ICBigDecimalClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithI32Value(i32Value, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int64 i64Value,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBigDecimalClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBigDecimal, RGM_SAME_DOMAIN,
                EIID_ICBigDecimalClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithI64Value(i64Value, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Double dValue,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBigDecimalClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBigDecimal, RGM_SAME_DOMAIN,
                EIID_ICBigDecimalClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithDValue(dValue, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int64 i64SmallValue,
        /* [in] */ _ELASTOS Int32 scale,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBigDecimalClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBigDecimal, RGM_SAME_DOMAIN,
                EIID_ICBigDecimalClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithI64SmallValueScale(i64SmallValue, scale, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 i32SmallValue,
        /* [in] */ _ELASTOS Int32 scale,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBigDecimalClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBigDecimal, RGM_SAME_DOMAIN,
                EIID_ICBigDecimalClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithI32SmallValueScale(i32SmallValue, scale, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& sVal,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBigDecimalClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBigDecimal, RGM_SAME_DOMAIN,
                EIID_ICBigDecimalClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithSVal(sVal, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & buf,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBigDecimalClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBigDecimal, RGM_SAME_DOMAIN,
                EIID_ICBigDecimalClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithBuf(buf, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBigDecimalClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBigDecimal, RGM_SAME_DOMAIN,
                EIID_ICBigDecimalClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithBufOffsetLength(buf, offset, length, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Math::IBigInteger * val,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBigDecimalClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBigDecimal, RGM_SAME_DOMAIN,
                EIID_ICBigDecimalClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithVal(val, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Math::IBigInteger * val,
        /* [in] */ _ELASTOS Int32 scale,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBigDecimalClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBigDecimal, RGM_SAME_DOMAIN,
                EIID_ICBigDecimalClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithValScale(val, scale, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Math::IBigInteger * val,
        /* [in] */ _ELASTOS Int32 scale,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBigDecimalClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBigDecimal, RGM_SAME_DOMAIN,
                EIID_ICBigDecimalClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithValScaleMc(val, scale, mc, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBigDecimalClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBigDecimal, RGM_SAME_DOMAIN,
                EIID_ICBigDecimalClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithBufOffsetLengthMc(buf, offset, length, mc, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & buf,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBigDecimalClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBigDecimal, RGM_SAME_DOMAIN,
                EIID_ICBigDecimalClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithBufMc(buf, mc, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& strVal,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBigDecimalClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBigDecimal, RGM_SAME_DOMAIN,
                EIID_ICBigDecimalClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithStrValMc(strVal, mc, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Double dVal,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBigDecimalClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBigDecimal, RGM_SAME_DOMAIN,
                EIID_ICBigDecimalClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithDValMc(dVal, mc, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Math::IBigInteger * bigIntegerVal,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBigDecimalClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBigDecimal, RGM_SAME_DOMAIN,
                EIID_ICBigDecimalClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithBigIntegerValMc(bigIntegerVal, mc, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 int32Val,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBigDecimalClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBigDecimal, RGM_SAME_DOMAIN,
                EIID_ICBigDecimalClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithInt32ValMc(int32Val, mc, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int64 int64Val,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBigDecimalClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBigDecimal, RGM_SAME_DOMAIN,
                EIID_ICBigDecimalClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithInt64ValMc(int64Val, mc, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 i32Value,
        /* [out] */ Elastos::Core::INumber** __INumber)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(i32Value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumber = (Elastos::Core::INumber*)__pNewObj->Probe(Elastos::Core::EIID_INumber);
        if (*__INumber) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 i32Value,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(i32Value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 i32Value,
        /* [out] */ Elastos::Math::IBigDecimal** __IBigDecimal)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(i32Value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBigDecimal = (Elastos::Math::IBigDecimal*)__pNewObj->Probe(Elastos::Math::EIID_IBigDecimal);
        if (*__IBigDecimal) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 i32Value,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(i32Value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 i32Value,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(i32Value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 i32Value,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(i32Value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 i64Value,
        /* [out] */ Elastos::Core::INumber** __INumber)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(i64Value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumber = (Elastos::Core::INumber*)__pNewObj->Probe(Elastos::Core::EIID_INumber);
        if (*__INumber) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 i64Value,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(i64Value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 i64Value,
        /* [out] */ Elastos::Math::IBigDecimal** __IBigDecimal)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(i64Value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBigDecimal = (Elastos::Math::IBigDecimal*)__pNewObj->Probe(Elastos::Math::EIID_IBigDecimal);
        if (*__IBigDecimal) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 i64Value,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(i64Value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 i64Value,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(i64Value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 i64Value,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(i64Value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Double dValue,
        /* [out] */ Elastos::Core::INumber** __INumber)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dValue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumber = (Elastos::Core::INumber*)__pNewObj->Probe(Elastos::Core::EIID_INumber);
        if (*__INumber) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Double dValue,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dValue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Double dValue,
        /* [out] */ Elastos::Math::IBigDecimal** __IBigDecimal)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dValue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBigDecimal = (Elastos::Math::IBigDecimal*)__pNewObj->Probe(Elastos::Math::EIID_IBigDecimal);
        if (*__IBigDecimal) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Double dValue,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dValue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Double dValue,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dValue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Double dValue,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dValue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 i64SmallValue,
        /* [in] */ _ELASTOS Int32 scale,
        /* [out] */ Elastos::Core::INumber** __INumber)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(i64SmallValue, scale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumber = (Elastos::Core::INumber*)__pNewObj->Probe(Elastos::Core::EIID_INumber);
        if (*__INumber) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 i64SmallValue,
        /* [in] */ _ELASTOS Int32 scale,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(i64SmallValue, scale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 i64SmallValue,
        /* [in] */ _ELASTOS Int32 scale,
        /* [out] */ Elastos::Math::IBigDecimal** __IBigDecimal)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(i64SmallValue, scale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBigDecimal = (Elastos::Math::IBigDecimal*)__pNewObj->Probe(Elastos::Math::EIID_IBigDecimal);
        if (*__IBigDecimal) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 i64SmallValue,
        /* [in] */ _ELASTOS Int32 scale,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(i64SmallValue, scale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 i64SmallValue,
        /* [in] */ _ELASTOS Int32 scale,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(i64SmallValue, scale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 i64SmallValue,
        /* [in] */ _ELASTOS Int32 scale,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(i64SmallValue, scale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 i32SmallValue,
        /* [in] */ _ELASTOS Int32 scale,
        /* [out] */ Elastos::Core::INumber** __INumber)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(i32SmallValue, scale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumber = (Elastos::Core::INumber*)__pNewObj->Probe(Elastos::Core::EIID_INumber);
        if (*__INumber) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 i32SmallValue,
        /* [in] */ _ELASTOS Int32 scale,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(i32SmallValue, scale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 i32SmallValue,
        /* [in] */ _ELASTOS Int32 scale,
        /* [out] */ Elastos::Math::IBigDecimal** __IBigDecimal)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(i32SmallValue, scale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBigDecimal = (Elastos::Math::IBigDecimal*)__pNewObj->Probe(Elastos::Math::EIID_IBigDecimal);
        if (*__IBigDecimal) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 i32SmallValue,
        /* [in] */ _ELASTOS Int32 scale,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(i32SmallValue, scale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 i32SmallValue,
        /* [in] */ _ELASTOS Int32 scale,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(i32SmallValue, scale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 i32SmallValue,
        /* [in] */ _ELASTOS Int32 scale,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(i32SmallValue, scale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& sVal,
        /* [out] */ Elastos::Core::INumber** __INumber)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sVal, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumber = (Elastos::Core::INumber*)__pNewObj->Probe(Elastos::Core::EIID_INumber);
        if (*__INumber) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& sVal,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sVal, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& sVal,
        /* [out] */ Elastos::Math::IBigDecimal** __IBigDecimal)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sVal, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBigDecimal = (Elastos::Math::IBigDecimal*)__pNewObj->Probe(Elastos::Math::EIID_IBigDecimal);
        if (*__IBigDecimal) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& sVal,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sVal, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& sVal,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sVal, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& sVal,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sVal, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & buf,
        /* [out] */ Elastos::Core::INumber** __INumber)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumber = (Elastos::Core::INumber*)__pNewObj->Probe(Elastos::Core::EIID_INumber);
        if (*__INumber) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & buf,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & buf,
        /* [out] */ Elastos::Math::IBigDecimal** __IBigDecimal)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBigDecimal = (Elastos::Math::IBigDecimal*)__pNewObj->Probe(Elastos::Math::EIID_IBigDecimal);
        if (*__IBigDecimal) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & buf,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & buf,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & buf,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ Elastos::Core::INumber** __INumber)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, offset, length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumber = (Elastos::Core::INumber*)__pNewObj->Probe(Elastos::Core::EIID_INumber);
        if (*__INumber) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, offset, length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ Elastos::Math::IBigDecimal** __IBigDecimal)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, offset, length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBigDecimal = (Elastos::Math::IBigDecimal*)__pNewObj->Probe(Elastos::Math::EIID_IBigDecimal);
        if (*__IBigDecimal) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, offset, length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, offset, length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, offset, length, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * val,
        /* [out] */ Elastos::Core::INumber** __INumber)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(val, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumber = (Elastos::Core::INumber*)__pNewObj->Probe(Elastos::Core::EIID_INumber);
        if (*__INumber) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * val,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(val, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * val,
        /* [out] */ Elastos::Math::IBigDecimal** __IBigDecimal)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(val, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBigDecimal = (Elastos::Math::IBigDecimal*)__pNewObj->Probe(Elastos::Math::EIID_IBigDecimal);
        if (*__IBigDecimal) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * val,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(val, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * val,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(val, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * val,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(val, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * val,
        /* [in] */ _ELASTOS Int32 scale,
        /* [out] */ Elastos::Core::INumber** __INumber)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(val, scale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumber = (Elastos::Core::INumber*)__pNewObj->Probe(Elastos::Core::EIID_INumber);
        if (*__INumber) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * val,
        /* [in] */ _ELASTOS Int32 scale,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(val, scale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * val,
        /* [in] */ _ELASTOS Int32 scale,
        /* [out] */ Elastos::Math::IBigDecimal** __IBigDecimal)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(val, scale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBigDecimal = (Elastos::Math::IBigDecimal*)__pNewObj->Probe(Elastos::Math::EIID_IBigDecimal);
        if (*__IBigDecimal) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * val,
        /* [in] */ _ELASTOS Int32 scale,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(val, scale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * val,
        /* [in] */ _ELASTOS Int32 scale,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(val, scale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * val,
        /* [in] */ _ELASTOS Int32 scale,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(val, scale, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * val,
        /* [in] */ _ELASTOS Int32 scale,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Core::INumber** __INumber)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(val, scale, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumber = (Elastos::Core::INumber*)__pNewObj->Probe(Elastos::Core::EIID_INumber);
        if (*__INumber) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * val,
        /* [in] */ _ELASTOS Int32 scale,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(val, scale, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * val,
        /* [in] */ _ELASTOS Int32 scale,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Math::IBigDecimal** __IBigDecimal)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(val, scale, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBigDecimal = (Elastos::Math::IBigDecimal*)__pNewObj->Probe(Elastos::Math::EIID_IBigDecimal);
        if (*__IBigDecimal) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * val,
        /* [in] */ _ELASTOS Int32 scale,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(val, scale, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * val,
        /* [in] */ _ELASTOS Int32 scale,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(val, scale, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * val,
        /* [in] */ _ELASTOS Int32 scale,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(val, scale, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Core::INumber** __INumber)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, offset, length, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumber = (Elastos::Core::INumber*)__pNewObj->Probe(Elastos::Core::EIID_INumber);
        if (*__INumber) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, offset, length, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Math::IBigDecimal** __IBigDecimal)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, offset, length, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBigDecimal = (Elastos::Math::IBigDecimal*)__pNewObj->Probe(Elastos::Math::EIID_IBigDecimal);
        if (*__IBigDecimal) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, offset, length, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, offset, length, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & buf,
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 length,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, offset, length, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & buf,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Core::INumber** __INumber)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumber = (Elastos::Core::INumber*)__pNewObj->Probe(Elastos::Core::EIID_INumber);
        if (*__INumber) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & buf,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & buf,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Math::IBigDecimal** __IBigDecimal)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBigDecimal = (Elastos::Math::IBigDecimal*)__pNewObj->Probe(Elastos::Math::EIID_IBigDecimal);
        if (*__IBigDecimal) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & buf,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & buf,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Char32> & buf,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(buf, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& strVal,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Core::INumber** __INumber)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(strVal, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumber = (Elastos::Core::INumber*)__pNewObj->Probe(Elastos::Core::EIID_INumber);
        if (*__INumber) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& strVal,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(strVal, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& strVal,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Math::IBigDecimal** __IBigDecimal)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(strVal, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBigDecimal = (Elastos::Math::IBigDecimal*)__pNewObj->Probe(Elastos::Math::EIID_IBigDecimal);
        if (*__IBigDecimal) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& strVal,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(strVal, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& strVal,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(strVal, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& strVal,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(strVal, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Double dVal,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Core::INumber** __INumber)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dVal, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumber = (Elastos::Core::INumber*)__pNewObj->Probe(Elastos::Core::EIID_INumber);
        if (*__INumber) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Double dVal,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dVal, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Double dVal,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Math::IBigDecimal** __IBigDecimal)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dVal, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBigDecimal = (Elastos::Math::IBigDecimal*)__pNewObj->Probe(Elastos::Math::EIID_IBigDecimal);
        if (*__IBigDecimal) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Double dVal,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dVal, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Double dVal,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dVal, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Double dVal,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dVal, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * bigIntegerVal,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Core::INumber** __INumber)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(bigIntegerVal, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumber = (Elastos::Core::INumber*)__pNewObj->Probe(Elastos::Core::EIID_INumber);
        if (*__INumber) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * bigIntegerVal,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(bigIntegerVal, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * bigIntegerVal,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Math::IBigDecimal** __IBigDecimal)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(bigIntegerVal, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBigDecimal = (Elastos::Math::IBigDecimal*)__pNewObj->Probe(Elastos::Math::EIID_IBigDecimal);
        if (*__IBigDecimal) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * bigIntegerVal,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(bigIntegerVal, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * bigIntegerVal,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(bigIntegerVal, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Math::IBigInteger * bigIntegerVal,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(bigIntegerVal, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 int32Val,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Core::INumber** __INumber)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(int32Val, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumber = (Elastos::Core::INumber*)__pNewObj->Probe(Elastos::Core::EIID_INumber);
        if (*__INumber) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 int32Val,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(int32Val, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 int32Val,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Math::IBigDecimal** __IBigDecimal)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(int32Val, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBigDecimal = (Elastos::Math::IBigDecimal*)__pNewObj->Probe(Elastos::Math::EIID_IBigDecimal);
        if (*__IBigDecimal) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 int32Val,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(int32Val, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 int32Val,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(int32Val, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 int32Val,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(int32Val, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 int64Val,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Core::INumber** __INumber)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(int64Val, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumber = (Elastos::Core::INumber*)__pNewObj->Probe(Elastos::Core::EIID_INumber);
        if (*__INumber) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 int64Val,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(int64Val, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 int64Val,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Math::IBigDecimal** __IBigDecimal)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(int64Val, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBigDecimal = (Elastos::Math::IBigDecimal*)__pNewObj->Probe(Elastos::Math::EIID_IBigDecimal);
        if (*__IBigDecimal) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 int64Val,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(int64Val, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 int64Val,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(int64Val, mc, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int64 int64Val,
        /* [in] */ Elastos::Math::IMathContext * mc,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(int64Val, mc, &__pNewObj);
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
namespace Math {
class CBigDecimalHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Math::IBigDecimalHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBigDecimalHelper, RGM_SAME_DOMAIN, Elastos::Math::EIID_IBigDecimalHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBigDecimalHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBigDecimalHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBigDecimalHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Math {
class CBigInteger
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 sign,
        /* [in] */ _ELASTOS Int64 value,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBigIntegerClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBigInteger, RGM_SAME_DOMAIN,
                EIID_ICBigIntegerClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithSignValue(sign, value, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 sign,
        /* [in] */ _ELASTOS Int32 numberLength,
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Int32> & digits,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBigIntegerClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBigInteger, RGM_SAME_DOMAIN,
                EIID_ICBigIntegerClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithSignNumberLengthDigits(sign, numberLength, digits, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& value,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBigIntegerClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBigInteger, RGM_SAME_DOMAIN,
                EIID_ICBigIntegerClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithValue(value, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& value,
        /* [in] */ _ELASTOS Int32 radix,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBigIntegerClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBigInteger, RGM_SAME_DOMAIN,
                EIID_ICBigIntegerClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithValueRadix(value, radix, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 signum,
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Byte> & magnitude,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBigIntegerClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBigInteger, RGM_SAME_DOMAIN,
                EIID_ICBigIntegerClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithSignumMagnitude(signum, magnitude, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Byte> & arrValue,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICBigIntegerClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CBigInteger, RGM_SAME_DOMAIN,
                EIID_ICBigIntegerClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithArrValue(arrValue, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::INumber** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBigInteger, RGM_SAME_DOMAIN, Elastos::Core::EIID_INumber, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::IComparable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBigInteger, RGM_SAME_DOMAIN, Elastos::Core::EIID_IComparable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Math::IBigInteger** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBigInteger, RGM_SAME_DOMAIN, Elastos::Math::EIID_IBigInteger, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBigInteger, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBigInteger, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBigInteger, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 sign,
        /* [in] */ _ELASTOS Int64 value,
        /* [out] */ Elastos::Core::INumber** __INumber)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sign, value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumber = (Elastos::Core::INumber*)__pNewObj->Probe(Elastos::Core::EIID_INumber);
        if (*__INumber) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 sign,
        /* [in] */ _ELASTOS Int64 value,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sign, value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 sign,
        /* [in] */ _ELASTOS Int64 value,
        /* [out] */ Elastos::Math::IBigInteger** __IBigInteger)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sign, value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBigInteger = (Elastos::Math::IBigInteger*)__pNewObj->Probe(Elastos::Math::EIID_IBigInteger);
        if (*__IBigInteger) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 sign,
        /* [in] */ _ELASTOS Int64 value,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sign, value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 sign,
        /* [in] */ _ELASTOS Int64 value,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sign, value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 sign,
        /* [in] */ _ELASTOS Int64 value,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sign, value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 sign,
        /* [in] */ _ELASTOS Int32 numberLength,
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Int32> & digits,
        /* [out] */ Elastos::Core::INumber** __INumber)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sign, numberLength, digits, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumber = (Elastos::Core::INumber*)__pNewObj->Probe(Elastos::Core::EIID_INumber);
        if (*__INumber) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 sign,
        /* [in] */ _ELASTOS Int32 numberLength,
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Int32> & digits,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sign, numberLength, digits, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 sign,
        /* [in] */ _ELASTOS Int32 numberLength,
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Int32> & digits,
        /* [out] */ Elastos::Math::IBigInteger** __IBigInteger)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sign, numberLength, digits, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBigInteger = (Elastos::Math::IBigInteger*)__pNewObj->Probe(Elastos::Math::EIID_IBigInteger);
        if (*__IBigInteger) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 sign,
        /* [in] */ _ELASTOS Int32 numberLength,
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Int32> & digits,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sign, numberLength, digits, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 sign,
        /* [in] */ _ELASTOS Int32 numberLength,
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Int32> & digits,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sign, numberLength, digits, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 sign,
        /* [in] */ _ELASTOS Int32 numberLength,
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Int32> & digits,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(sign, numberLength, digits, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [out] */ Elastos::Core::INumber** __INumber)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumber = (Elastos::Core::INumber*)__pNewObj->Probe(Elastos::Core::EIID_INumber);
        if (*__INumber) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [out] */ Elastos::Math::IBigInteger** __IBigInteger)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBigInteger = (Elastos::Math::IBigInteger*)__pNewObj->Probe(Elastos::Math::EIID_IBigInteger);
        if (*__IBigInteger) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [in] */ _ELASTOS Int32 radix,
        /* [out] */ Elastos::Core::INumber** __INumber)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, radix, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumber = (Elastos::Core::INumber*)__pNewObj->Probe(Elastos::Core::EIID_INumber);
        if (*__INumber) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [in] */ _ELASTOS Int32 radix,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, radix, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [in] */ _ELASTOS Int32 radix,
        /* [out] */ Elastos::Math::IBigInteger** __IBigInteger)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, radix, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBigInteger = (Elastos::Math::IBigInteger*)__pNewObj->Probe(Elastos::Math::EIID_IBigInteger);
        if (*__IBigInteger) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [in] */ _ELASTOS Int32 radix,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, radix, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [in] */ _ELASTOS Int32 radix,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, radix, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& value,
        /* [in] */ _ELASTOS Int32 radix,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(value, radix, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 signum,
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Byte> & magnitude,
        /* [out] */ Elastos::Core::INumber** __INumber)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(signum, magnitude, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumber = (Elastos::Core::INumber*)__pNewObj->Probe(Elastos::Core::EIID_INumber);
        if (*__INumber) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 signum,
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Byte> & magnitude,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(signum, magnitude, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 signum,
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Byte> & magnitude,
        /* [out] */ Elastos::Math::IBigInteger** __IBigInteger)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(signum, magnitude, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBigInteger = (Elastos::Math::IBigInteger*)__pNewObj->Probe(Elastos::Math::EIID_IBigInteger);
        if (*__IBigInteger) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 signum,
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Byte> & magnitude,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(signum, magnitude, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 signum,
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Byte> & magnitude,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(signum, magnitude, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 signum,
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Byte> & magnitude,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(signum, magnitude, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Byte> & arrValue,
        /* [out] */ Elastos::Core::INumber** __INumber)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(arrValue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__INumber = (Elastos::Core::INumber*)__pNewObj->Probe(Elastos::Core::EIID_INumber);
        if (*__INumber) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Byte> & arrValue,
        /* [out] */ Elastos::Core::IComparable** __IComparable)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(arrValue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IComparable = (Elastos::Core::IComparable*)__pNewObj->Probe(Elastos::Core::EIID_IComparable);
        if (*__IComparable) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Byte> & arrValue,
        /* [out] */ Elastos::Math::IBigInteger** __IBigInteger)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(arrValue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IBigInteger = (Elastos::Math::IBigInteger*)__pNewObj->Probe(Elastos::Math::EIID_IBigInteger);
        if (*__IBigInteger) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Byte> & arrValue,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(arrValue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Byte> & arrValue,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(arrValue, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS ArrayOf<_ELASTOS Byte> & arrValue,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(arrValue, &__pNewObj);
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
namespace Math {
class CBigIntegerHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Math::IBigIntegerHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBigIntegerHelper, RGM_SAME_DOMAIN, Elastos::Math::EIID_IBigIntegerHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBigIntegerHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBigIntegerHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CBigIntegerHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace Math {
class CMathContext
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 precision,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICMathContextClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CMathContext, RGM_SAME_DOMAIN,
                EIID_ICMathContextClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPrecision(precision, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 precision,
        /* [in] */ Elastos::Math::RoundingMode roundingMode,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICMathContextClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CMathContext, RGM_SAME_DOMAIN,
                EIID_ICMathContextClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPrecisionRoundingMode(precision, roundingMode, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 precision,
        /* [out] */ Elastos::Math::IMathContext** __IMathContext)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(precision, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMathContext = (Elastos::Math::IMathContext*)__pNewObj->Probe(Elastos::Math::EIID_IMathContext);
        if (*__IMathContext) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 precision,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(precision, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 precision,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(precision, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 precision,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(precision, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 precision,
        /* [in] */ Elastos::Math::RoundingMode roundingMode,
        /* [out] */ Elastos::Math::IMathContext** __IMathContext)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(precision, roundingMode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IMathContext = (Elastos::Math::IMathContext*)__pNewObj->Probe(Elastos::Math::EIID_IMathContext);
        if (*__IMathContext) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 precision,
        /* [in] */ Elastos::Math::RoundingMode roundingMode,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(precision, roundingMode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 precision,
        /* [in] */ Elastos::Math::RoundingMode roundingMode,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(precision, roundingMode, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 precision,
        /* [in] */ Elastos::Math::RoundingMode roundingMode,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(precision, roundingMode, &__pNewObj);
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
namespace Math {
class CMathContextHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Math::IMathContextHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMathContextHelper, RGM_SAME_DOMAIN, Elastos::Math::EIID_IMathContextHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMathContextHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMathContextHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CMathContextHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
#endif // _INSIDE_ELASTOS_CORELIBRARY_

#ifndef _INSIDE_ELASTOS_CORELIBRARY_
namespace Elastos {
namespace IO {
class CPlainFile
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& dir,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPlainFileClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPlainFile, RGM_SAME_DOMAIN,
                EIID_ICPlainFileClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithDir(dir, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& dir,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICPlainFileClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CPlainFile, RGM_SAME_DOMAIN,
                EIID_ICPlainFileClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithDirName(dir, name, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& dir,
        /* [out] */ Elastos::IO::IPlainFile** __IPlainFile)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dir, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPlainFile = (Elastos::IO::IPlainFile*)__pNewObj->Probe(Elastos::IO::EIID_IPlainFile);
        if (*__IPlainFile) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& dir,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dir, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& dir,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dir, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& dir,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dir, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& dir,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::IO::IPlainFile** __IPlainFile)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dir, name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IPlainFile = (Elastos::IO::IPlainFile*)__pNewObj->Probe(Elastos::IO::EIID_IPlainFile);
        if (*__IPlainFile) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& dir,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dir, name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& dir,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dir, name, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& dir,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(dir, name, &__pNewObj);
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

#endif // __Elastos_CoreLibrary_Core_h__
