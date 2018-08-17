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

#ifndef __ELASTOS_UTILITY_LOGGING_SLOGGER_H__
#define __ELASTOS_UTILITY_LOGGING_SLOGGER_H__

#include <elastos.h>

#ifndef __ELASTOS_UTILITY_LOGGING_SLOGGER_MACRO__
#define __ELASTOS_UTILITY_LOGGING_SLOGGER_MACRO__
#define SLOGGERD(tag, ...)  Elastos::Utility::Logging::Slogger::D(tag, __VA_ARGS__);
#define SLOGGERE(tag, ...)  Elastos::Utility::Logging::Slogger::E(tag, __VA_ARGS__);
#define SLOGGERI(tag, ...)  Elastos::Utility::Logging::Slogger::I(tag, __VA_ARGS__);
#define SLOGGERV(tag, ...)  Elastos::Utility::Logging::Slogger::V(tag, __VA_ARGS__);
#define SLOGGERW(tag, ...)  Elastos::Utility::Logging::Slogger::W(tag, __VA_ARGS__);
#endif //__ELASTOS_UTILITY_LOGGING_SLOGGER_MACRO__

namespace Elastos {
namespace Utility {
namespace Logging {

class ECO_PUBLIC Slogger
{
public:
    /*!
     * @brief Send a DEBUG log message.
     * @param tag
     * @param msg
     */
    static CARAPI D(const char * tag, const char *fmt, ...);

    /*!
     * @brief Send an ERROR log message.
     * @param tag
     * @param msg
     */
    static CARAPI E(const char * tag, const char *fmt, ...);

    /*!
     * @brief Send an INFO log message.
     * @param tag
     * @param msg
     */
    static CARAPI I(const char * tag, const char *fmt, ...);

    /*!
     * @brief Send an VERBOSE log message.
     * @param tag
     * @param msg
     */
    static CARAPI V(const char * tag, const char *fmt, ...);

    /*!
     * @brief Send a WARN log message.
     * @param tag
     * @param msg
     */
    static CARAPI W(const char * tag, const char *fmt, ...);

    /*!
     * @brief Low-level logging call.
     * @param priority
     * @param tag
     * @param msg
     */
    static CARAPI Println(Int32 priority, const char * tag, const char *fmt, ...);

private:
    ECO_LOCAL Slogger();
    ECO_LOCAL Slogger(const Slogger&);
};

} // Logging
} // namespace Utility
} // namespace Elastos

#endif //__ELASTOS_UTILITY_LOGGING_ELASTOS_UTILITY_SLOGGER_H__
