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

#ifndef __ETL_QUEUE_H__
#define __ETL_QUEUE_H__


/** @file stl_queue.h
 *  This is an internal header file, included by other library headers.
 *  You should not attempt to use it directly.
 */

#include "elastos/utility/etl/etl_def.h"
#include "elastos/utility/etl/ConceptCheck.h"
#include <elrefbase.h>

using Elastos::ElLightRefBase;

_ETL_NAMESPACE_BEGIN

// Forward declarations of operators < and ==, needed for friend declaration.

template <class Tp,
          class Sequence = Deque<Tp> >
class Queue;

template <class Tp, class Seq>
inline Boolean operator==(const Queue<Tp, Seq>&, const Queue<Tp, Seq>&);

template <class Tp, class Seq>
inline Boolean operator<(const Queue<Tp, Seq>&, const Queue<Tp, Seq>&);


template <class Tp, class Sequence>
class Queue : public ElLightRefBase
{
    // concept requirements
    Concept_ClassRequires(Tp, SGIAssignableConcept)
    Concept_ClassRequires(Sequence, FrontInsertionSequenceConcept)
    Concept_ClassRequires(Sequence, BackInsertionSequenceConcept)
    typedef typename Sequence::ValueType SequenceValueType;
    Concept_ClassRequires2(Tp, SequenceValueType, SameTypeConcept);

    template <class Tp1, class Seq1>
    friend Boolean operator== (const Queue<Tp1, Seq1>&,
                            const Queue<Tp1, Seq1>&);
    template <class Tp1, class Seq1>
    friend Boolean operator< (const Queue<Tp1, Seq1>&,
                           const Queue<Tp1, Seq1>&);
public:
    typedef typename Sequence::ValueType      ValueType;
    typedef typename Sequence::SizeType       SizeType;
    typedef Sequence                  ContainerType;

    typedef typename Sequence::Reference       Reference;
    typedef typename Sequence::ConstReference ConstReference;
protected:
    Sequence mC;
public:
    explicit Queue(const Sequence& c = Sequence()) : mC(c) {}

    Boolean IsEmpty() const { return mC.IsEmpty(); }
    SizeType GetSize() const { return mC.GetSize(); }
    Reference GetFront() { return mC.GetFront(); }
    ConstReference GetFront() const { return mC.GetFront(); }
    Reference GetBack() { return mC.GetBack(); }
    ConstReference GetBack() const { return mC.GetBack(); }
    void Push(const ValueType& x) { mC.PushBack(x); }
    void Pop() { mC.PopFront(); }
};

template <class Tp, class Sequence>
Boolean
operator==(const Queue<Tp, Sequence>& x, const Queue<Tp, Sequence>& y)
{
    return x.mC == y.mC;
}

template <class Tp, class Sequence>
Boolean
operator<(const Queue<Tp, Sequence>& x, const Queue<Tp, Sequence>& y)
{
    return x.mC < y.mC;
}

template <class Tp, class Sequence>
Boolean
operator!=(const Queue<Tp, Sequence>& x, const Queue<Tp, Sequence>& y)
{
    return !(x == y);
}

template <class Tp, class Sequence>
Boolean
operator>(const Queue<Tp, Sequence>& x, const Queue<Tp, Sequence>& y)
{
    return y < x;
}

template <class Tp, class Sequence>
Boolean
operator<=(const Queue<Tp, Sequence>& x, const Queue<Tp, Sequence>& y)
{
    return !(y < x);
}

template <class Tp, class Sequence>
Boolean
operator>=(const Queue<Tp, Sequence>& x, const Queue<Tp, Sequence>& y)
{
    return !(x < y);
}

template <class Tp,
          class Sequence = Vector<Tp>,
          class Compare  = Less<typename Sequence::ValueType> >
class PriorityQueue
{
    // concept requirements
    Concept_ClassRequires(Tp, SGIAssignableConcept)
    Concept_ClassRequires(Sequence, SequenceConcept)
    Concept_ClassRequires(Sequence, RandomAccessContainerConcept)
    typedef typename Sequence::ValueType SequenceValueType;
    Concept_ClassRequires2(Tp, SequenceValueType, SameTypeConcept);
    Concept_ClassRequires4(Compare, Boolean, Tp, Tp, BinaryFunctionConcept);

public:
    typedef typename Sequence::ValueType      ValueType;
    typedef typename Sequence::SizeType       SizeType;
    typedef          Sequence                  ContainerType;

    typedef typename Sequence::Reference       Reference;
    typedef typename Sequence::ConstReference ConstReference;
protected:
    Sequence mC;
    Compare comp;
public:
    explicit PriorityQueue(const Compare& x = Compare(),
                const Sequence& s = Sequence())
    : mC(s), comp(x)
    { MakeHeap(mC.Begin(), mC.End(), comp); }

    template <class InputIterator>
    PriorityQueue(InputIterator first, InputIterator last,
                   const Compare& x = Compare(),
           const Sequence& s = Sequence())
    : mC(s), comp(x)
    {
        mC.Insert(mC.End(), first, last);
        MakeHeap(mC.Begin(), mC.End(), comp);
    }

    Boolean IsEmpty() const { return mC.IsEmpty(); }
    SizeType GetSize() const { return mC.GetSize(); }
    ConstReference GetTop() const { return mC.GetFront(); }

    void
    Push(const ValueType& x)
    {
        try {
            mC.PushBack(x);
            PushHeap(mC.Begin(), mC.End(), comp);
        }
        catch(...) {
            mC.Clear();
            THROW_EXCEPTION_AGAIN;
        }
    }

    void
    Pop()
    {
        try {
            PopHeap(mC.Begin(), mC.End(), comp);
            mC.PopBack();
        }
        catch(...) {
            mC.Clear();
            THROW_EXCEPTION_AGAIN;
        }
    }
};

// no equality is provided

_ETL_NAMESPACE_END

#endif //__ETL_QUEUE_H__
