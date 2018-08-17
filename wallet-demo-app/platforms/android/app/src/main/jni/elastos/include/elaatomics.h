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

#ifndef __ELAATOMICS_H__
#define __ELAATOMICS_H__

#include <elatypes.h>

extern "C" {

ECO_PUBLIC int atomic_cmpxchg(int old, int _new, volatile int *ptr);
ECO_PUBLIC int atomic_swap(int _new, volatile int *ptr);

ECO_PUBLIC int atomic_inc(volatile int *ptr);
ECO_PUBLIC int atomic_dec(volatile int *ptr);
ECO_PUBLIC int atomic_add(int value, volatile int* ptr);
ECO_PUBLIC int atomic_and(int value, volatile int* ptr);
ECO_PUBLIC int atomic_or(int value, volatile int *ptr);

}

#endif /* __ELAATOMICS_H__ */
