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

#ifndef __ELASTOS_UTILITY_LOGGING_LOGGER_H__
#define __ELASTOS_UTILITY_LOGGING_LOGGER_H__

#include <elastos.h>

#ifndef __ELASTOS_UTILITY_LOGGING_LOGGER_MACRO__
#define __ELASTOS_UTILITY_LOGGING_LOGGER_MACRO__
#define LOGGERD(tag, ...)  Elastos::Utility::Logging::Logger::D(tag, __VA_ARGS__);
#define LOGGERE(tag, ...)  Elastos::Utility::Logging::Logger::E(tag, __VA_ARGS__);
#define LOGGERI(tag, ...)  Elastos::Utility::Logging::Logger::I(tag, __VA_ARGS__);
#define LOGGERV(tag, ...)  Elastos::Utility::Logging::Logger::V(tag, __VA_ARGS__);
#define LOGGERW(tag, ...)  Elastos::Utility::Logging::Logger::W(tag, __VA_ARGS__);
#endif //__ELASTOS_UTILITY_LOGGING_LOGGER_MACRO__


namespace Elastos {
namespace Utility {
namespace Logging {

class ECO_PUBLIC Logger
{
public:
    /*!
     * @brief Priority constant for the println method; use Logger.V.
     */
    static const Int32 VERBOSE = 2;

    /*!
     * @brief Priority constant for the println method; use Logger.D.
     */
    static const Int32 ___DEBUG = 3;

    /*!
     * @brief Priority constant for the println method; use Logger.I.
     */
    static const Int32 INFO = 4;

    /*!
     * @brief Priority constant for the println method; use Logger.W.
     */
    static const Int32 WARN = 5;

    /*!
     * @brief Priority constant for the println method; use Logger.E.
     */
    static const Int32 ERROR = 6;

    /*!
     * @brief Priority constant for the println method.
     */
    static const Int32 ASSERT = 7;

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
     * @brief Checks to see whether or not a log for the specified tag is
     * loggable at the specified level.
     * @param tag
     * @param level
     * @param pIsLoggable
     */
    static Boolean IsLoggable(const char * tag, Int32 level);

    /*!
     * @brief Low-level logging call.
     * @param priority
     * @param tag
     * @param msg
     */
    static CARAPI Println(Int32 priority, const char * tag, const char *fmt, ...);

    /*!
     * @brief
     */
    static const Int32 LOG_ID_MAIN = 0;
    /*!
     * @brief
     */
    static const Int32 LOG_ID_RADIO = 1;
    /*!
     * @brief
     */
    static const Int32 LOG_ID_EVENTS = 2;
    /*!
     * @brief
     */
    static const Int32 LOG_ID_SYSTEM = 3;

    /*!
     * @brief According the Logger's priority,output corresponding infomation.
     * @param bufID
     * @param priority
     * @param tag
     * @param msg
     */
    static CARAPI PrintlnImpl(Int32 bufID, Int32 priority, const char * tag, const char *fmt, ...);

private:
    ECO_LOCAL Logger();
    ECO_LOCAL Logger(const Logger&);
};

} // Logging
} // namespace Utility
} // namespace Elastos

#endif // __ELASTOS_UTILITY_LOGGING_ELASTOS_UTILITY_LOGGER_H__
