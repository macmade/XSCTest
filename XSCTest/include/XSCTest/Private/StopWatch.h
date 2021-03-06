/*******************************************************************************
 * The MIT License (MIT)
 * 
 * Copyright (c) 2020 Jean-David Gadina - www.xs-labs.com
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 ******************************************************************************/

/*!
 * @header      StopWatch.h
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#ifndef XSCTEST_PRIVATE_STOP_WATCH_H
#define XSCTEST_PRIVATE_STOP_WATCH_H

#include <stdint.h>

#ifdef _WIN32
#pragma warning( push )
#pragma warning( disable : 5105 )
#include <Windows.h>
#pragma warning( pop )
#else
#include <sys/time.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

    typedef enum
    {
        XSCTestStopWatchStatusUnknown,
        XSCTestStopWatchStatusStarted,
        XSCTestStopWatchStatusStopped
    } XSCTestStopWatchStatus;

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

    struct XSCTestStopWatch
    {
        XSCTestStopWatchStatus status;
        uint64_t               start;
        uint64_t               end;
        char *                 string;

        #ifdef _WIN32
        LARGE_INTEGER freq;
        BOOL          useQPC;
        #endif
    };

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#ifdef __cplusplus
}
#endif

#endif /* XSCTEST_PRIVATE_STOP_WATCH_H */
