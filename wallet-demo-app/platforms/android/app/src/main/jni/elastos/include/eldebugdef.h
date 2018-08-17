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

#ifndef __ELDEBUGDEF_H__
#define __ELDEBUGDEF_H__

#include <elstring.h>
#include <stdio.h>

_ELASTOS_NAMESPACE_BEGIN

class FileLinePrinter
{
public:
    static void Print(const char* filename, Int32 lineNumber)
    {
#if defined(_DEBUG) || defined(_ELASTOS_DEBUG)
        String name(filename);
        if (!name.IsNullOrEmpty()) {
            Int32 pos = name.LastIndexOf('/');
            if (pos > 0) {
                name = name.Substring(pos + 1);
            }

            printf("FILE: %s, LINE: %d\n", name.string(), lineNumber);
        }
#endif
    }

    static void PrintEx(const char* filename, Int32 lineNumber, const char *fmt, ...)
    {
#if defined(_DEBUG) || defined(_ELASTOS_DEBUG)
        static const Int32 MSG_BUF_SIZE = 1024;
        char msgBuf[MSG_BUF_SIZE];
        va_list args;
        va_start(args, fmt);
        vsnprintf(msgBuf, MSG_BUF_SIZE, fmt, args);
        va_end(args);

        String name(filename);
        Int32 pos = name.LastIndexOf('/');
        if (pos > 0) {
            name = name.Substring(pos + 1);
        }
        printf("FILE: %s, LINE: %d, INFO: > %s\n", name.string(), lineNumber, msgBuf);
#endif
    }
};

class DebugEnterLeavePrinter {
#if defined(_DEBUG) || defined(_ELASTOS_DEBUG)
    String mInfo;
    String mFileName;
    Int32 mLineNumber;
#endif
public:
    DebugEnterLeavePrinter(const char* in = NULL, const char* filename = NULL, Int32 lineNumber = -1)
    {
#if defined(_DEBUG) || defined(_ELASTOS_DEBUG)
        mLineNumber = lineNumber;
        mInfo = String(in ? in : "-");
        mFileName = String(filename ? filename : "");
        Int32 pos = mFileName.LastIndexOf('/');
        if (pos > 0) {
            mFileName = mFileName.Substring(pos + 1);
        }
        printf("::ENTER >>");
        if (!mFileName.IsNullOrEmpty()) {
            printf(" FILE: %s", mFileName.string());
        }
        if (mLineNumber >= 0) {
            printf(" LINE: %d", mLineNumber);
        }
        printf(" %s\n", mInfo.string());
#endif
    }

    ~DebugEnterLeavePrinter()
    {
#if defined(_DEBUG) || defined(_ELASTOS_DEBUG)
        printf("::LEAVE <<");
        if (!mFileName.IsNullOrEmpty()) {
            printf(" FILE: %s", mFileName.string());
        }
        if (mLineNumber >= 0) {
            printf(" LINE: %d", mLineNumber);
        }
        printf(" %s\n", mInfo.string());
#endif
    }
};

//=============================================================================
#ifndef PRINT_FILE_LINE
#if defined(_DEBUG) || defined(_ELASTOS_DEBUG)
//#define PRINT_FILE_LINE printf("FILE: %s, LINE: %d\n", __FILE__, __LINE__);
#define PRINT_FILE_LINE FileLinePrinter::Print(__FILE__, __LINE__);
#define PFL FileLinePrinter::Print(__FILE__, __LINE__);
#else
#define PRINT_FILE_LINE(...)
#define PFL(...)
#endif
#endif

#ifndef PRINT_FILE_LINE_EX
#if defined(_DEBUG) || defined(_ELASTOS_DEBUG)
//#define PRINT_FILE_LINE_EX(format, ...) printf("FILE: "__FILE__", LINE: %d: "format"\n", __LINE__, ##__VA_ARGS__);
#define PRINT_FILE_LINE_EX(...) FileLinePrinter::PrintEx(__FILE__, __LINE__, __VA_ARGS__);
#define PFL_EX(...) FileLinePrinter::PrintEx(__FILE__, __LINE__, __VA_ARGS__);
#define ELDBG(...) FileLinePrinter::PrintEx(__FILE__, __LINE__, __VA_ARGS__);
#else
#define PRINT_FILE_LINE_EX(...)
#define PFL_EX(...)
#define ELDBG(...)
#endif
#endif

#ifndef PRINT_ENTER_LEAVE
#if defined(_DEBUG) || defined(_ELASTOS_DEBUG)
#define PRINT_ENTER_LEAVE(info) DebugEnterLeavePrinter debugEnterLeavePrinter(info);
#define PEL(info) DebugEnterLeavePrinter debugEnterLeavePrinter(info);
#else
#define PRINT_ENTER_LEAVE(...)
#define PEL(...)
#endif
#endif

#ifndef PRINT_ENTER_LEAVE_EX
#if defined(_DEBUG) || defined(_ELASTOS_DEBUG)
#define PRINT_ENTER_LEAVE_EX(info) DebugEnterLeavePrinter debugEnterLeavePrinterEx(info, __FILE__, __LINE__);
#define PEL_EX(info) DebugEnterLeavePrinter debugEnterLeavePrinterEx(info, __FILE__, __LINE__);
#else
#define PRINT_ENTER_LEAVE_EX(...)
#define PEL_EX(...)
#endif
#endif


_ELASTOS_NAMESPACE_END

#endif // __ELDEBUGDEF_H__
