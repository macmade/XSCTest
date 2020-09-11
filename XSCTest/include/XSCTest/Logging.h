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
 * @header      Logging.h
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#ifndef XSCTEST_LOGGING_H
#define XSCTEST_LOGGING_H

#include <XSCTest/Failure.h>
#include <XSCTest/StopWatch.h>
#include <XSCTest/TermColor.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

    typedef enum
    {
        XSCTestLogStyleNone,
        XSCTestLogStyleSuccess,
        XSCTestLogStyleFailure
    } XSCTestLogStyle;

    typedef enum
    {
        XSCTestLogOptionNewLineBefore = 1 << 1,
        XSCTestLogOptionNewLineAfter  = 1 << 2
    } XSCTestLogOption;

    void XSCTestLogSuccessPrompt( FILE * fh );
    void XSCTestLogFailedPrompt( FILE * fh );
    void XSCTestLogPrompt( FILE * fh );

    void XSCTestLogMessage( FILE * fh, const char * message, XSCTestTermColor color, XSCTestLogStyle style, unsigned int options );
    void XSCTestLogTestCase( FILE * fh, const char * testSuite, const char * testCase, const char * prefix );
    void XSCTestLogTestCaseResult( FILE * fh, const char * testSuite, const char * testCase, XSCTestFailureRef failure, XSCTestStopWatchRef time );

#ifdef __cplusplus
}
#endif

#endif /* XSCTEST_LOGGING_H */
