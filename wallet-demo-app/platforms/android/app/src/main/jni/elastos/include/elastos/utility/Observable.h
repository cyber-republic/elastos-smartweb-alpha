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

#ifndef __ELASTOS_UTILITY_OBSERVABLE_H__
#define __ELASTOS_UTILITY_OBSERVABLE_H__

#include "Elastos.CoreLibrary.Utility.h"
#include "elastos/core/Object.h"

using Elastos::Core::Object;

namespace Elastos {
namespace Utility {

class ECO_PUBLIC Observable
    : public Object
    , public IObservable
{
public:
    CAR_INTERFACE_DECL()

    Observable();

    virtual ~Observable();

    CARAPI constructor();

    /**
     * Adds the specified observer to the list of observers. If it is already
     * registered, it is not added a second time.
     *
     * @param observer
     *            the Observer to add.
     */
    CARAPI AddObserver(
        /* [in] */ IObserver* observer);

    /**
     * Returns the number of observers registered to this {@code Observable}.
     *
     * @return the number of observers.
     */
    CARAPI CountObservers(
        /* [out] */ Int32* value);

    /**
     * Removes the specified observer from the list of observers. Passing null
     * won't do anything.
     *
     * @param observer
     *            the observer to remove.
     */
    CARAPI DeleteObserver(
        /* [in] */ IObserver* observer);

    /**
     * Removes all observers from the list of observers.
     */
    CARAPI DeleteObservers();

    /**
     * Returns the changed flag for this {@code Observable}.
     *
     * @return {@code true} when the changed flag for this {@code Observable} is
     *         set, {@code false} otherwise.
     */
    CARAPI HasChanged(
        /* [out] */ Boolean* value);

    /**
     * If {@code hasChanged()} returns {@code true}, calls the {@code update()}
     * method for every observer in the list of observers using null as the
     * argument. Afterwards, calls {@code clearChanged()}.
     * <p>
     * Equivalent to calling {@code notifyObservers(null)}.
     */
    CARAPI NotifyObservers();

    /**
     * If {@code hasChanged()} returns {@code true}, calls the {@code update()}
     * method for every Observer in the list of observers using the specified
     * argument. Afterwards calls {@code clearChanged()}.
     *
     * @param data
     *            the argument passed to {@code update()}.
     */
    CARAPI NotifyObservers(
        /* [in] */ IInterface* data);

    /**
     * Clears the changed flag for this {@code Observable}. After calling
     * {@code clearChanged()}, {@code hasChanged()} will return {@code false}.
     */
    CARAPI ClearChanged();

    /**
     * Sets the changed flag for this {@code Observable}. After calling
     * {@code setChanged()}, {@code hasChanged()} will return {@code true}.
     */
    CARAPI SetChanged();

protected:
    AutoPtr<IList> mObservers; // = new ArrayList<Observer>();

    Boolean mChanged; // = false;
};

} // namespace Utility
} // namespace Elastos

#endif // __ELASTOS_UTILITY_OBSERVABLE_H__
