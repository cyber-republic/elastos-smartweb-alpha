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

#ifndef __ETL_STACK_H__
#define __ETL_STACK_H__

#include "elastos/utility/etl/etl_def.h"
#include "elastos/utility/etl/ConceptCheck.h"
#include <elrefbase.h>

using Elastos::ElLightRefBase;

_ETL_NAMESPACE_BEGIN

// Forward declarations of operators == and <, needed for friend declaration.

template <class Tp,
          class Sequence = Deque<Tp> >
class Stack;

template <class Tp, class Seq>
Boolean operator==(const Stack<Tp, Seq>& x, const Stack<Tp, Seq>& y);

template <class Tp, class Seq>
Boolean operator<(const Stack<Tp, Seq>& x, const Stack<Tp, Seq>& y);


template <class Tp, class Sequence>
class Stack : public ElLightRefBase
{
  // concept requirements
    Concept_ClassRequires(Tp, SGIAssignableConcept)
    Concept_ClassRequires(Sequence, BackInsertionSequenceConcept)
    typedef typename Sequence::ValueType SequenceValueType;
    Concept_ClassRequires2(Tp, SequenceValueType, SameTypeConcept);

    template <class Tp1, class Seq1>
    friend Boolean operator== (const Stack<Tp1, Seq1>&,
                          const Stack<Tp1, Seq1>&);
    template <class Tp1, class Seq1>
    friend Boolean operator< (const Stack<Tp1, Seq1>&,
                         const Stack<Tp1, Seq1>&);
public:
    typedef typename Sequence::ValueType       ValueType;
    typedef typename Sequence::SizeType        SizeType;
    typedef           Sequence                   ContainerType;

    typedef typename Sequence::Reference       Reference;
    typedef typename Sequence::ConstReference ConstReference;

protected:
    Sequence c;

public:
    Stack() : c() {}
    explicit Stack(const Sequence& s) : c(s) {}

    Boolean IsEmpty() const { return c.IsEmpty(); }
    SizeType GetSize() const { return c.GetSize(); }
    Reference GetTop() { return c.GetBack(); }
    ConstReference GetTop() const { return c.GetBack(); }
    void Push(const ValueType& x) { c.PushBack(x); }
    void Pop() { c.PopBack(); }
};

template <class Tp, class Seq>
Boolean operator==(const Stack<Tp, Seq>& x, const Stack<Tp, Seq>& y)
{
  return x.c == y.c;
}

template <class Tp, class Seq>
Boolean operator<(const Stack<Tp, Seq>& x, const Stack<Tp, Seq>& y)
{
  return x.c < y.c;
}

template <class Tp, class Seq>
Boolean operator!=(const Stack<Tp, Seq>& x, const Stack<Tp, Seq>& y)
{
  return !(x == y);
}

template <class Tp, class Seq>
Boolean operator>(const Stack<Tp, Seq>& x, const Stack<Tp, Seq>& y)
{
  return y < x;
}

template <class Tp, class Seq>
Boolean operator<=(const Stack<Tp, Seq>& x, const Stack<Tp, Seq>& y)
{
  return !(y < x);
}

template <class Tp, class Seq>
Boolean operator>=(const Stack<Tp, Seq>& x, const Stack<Tp, Seq>& y)
{
  return !(x < y);
}

_ETL_NAMESPACE_END


#endif //__ETL_STACK_H__
