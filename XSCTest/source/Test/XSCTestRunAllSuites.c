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
 * @file        XSCTestRunAllSuites.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XSCTest/Private/Test.h>

bool XSCTestRunAllSuites( FILE * fh )
{
    bool                ret;
    XSCTestStopWatchRef time;
    size_t              suites;
    size_t              cases;
    XSCTestStringRef    casesString;
    XSCTestStringRef    suitesString;

    ret          = true;
    time         = XSCTestStopWatchCreate();
    suites       = XSCTestGetNumberOfSuites();
    cases        = XSCTestGetNumberOfTestCases();
    casesString  = XSCTestCreateNumberedString( "test case", cases );
    suitesString = XSCTestCreateNumberedString( "test suite", suites );

    if( suites == 0 || cases == 0 )
    {
        XSCTestLog( fh, XSCTestTermColorNone, XSCTestLogStyleFailure, 0, "No test to run..." );

        return false;
    }

    XSCTestLog(
        fh,
        XSCTestTermColorNone,
        XSCTestLogStyleNone,
        0,
        "Running %s from %s",
        XSCTestStringGetCString( casesString ),
        XSCTestStringGetCString( suitesString ) );

    XSCTestStopWatchStart( time );

    for( size_t i = 0; i < XSCTestArrayGetCount( XSCTestSuites ); i++ )
    {
        if( XSCTestSuiteRun( XSCTestArrayGetValueAtIndex( XSCTestSuites, i ), fh ) == false )
        {
            ret = false;
        }
    }

    XSCTestStopWatchStop( time );

    {
        size_t           passed;
        size_t           failed;
        XSCTestStringRef passedString;
        XSCTestStringRef failedString;

        passed       = XSCTestGetNumberOfPassedTestCases();
        failed       = XSCTestGetNumberOfFailedTestCases();
        passedString = XSCTestCreateNumberedString( "test", passed );
        failedString = XSCTestCreateNumberedString( "test", failed );

        XSCTestLog(
            fh,
            XSCTestTermColorNone,
            XSCTestLogStyleNone,
            XSCTestLogOptionNewLineBefore,
            "%s from %s ran (%s total)",
            XSCTestStringGetCString( casesString ),
            XSCTestStringGetCString( suitesString ),
            XSCTestStopWatchGetString( time ) );

        XSCTestLog(
            fh,
            ( passed > 0 ) ? XSCTestTermColorGreen : XSCTestTermColorRed,
            XSCTestLogStyleNone,
            0,
            "%s passed:",
            XSCTestStringGetCString( passedString ) );

        XSCTestEnumeratePassedTestCases( XSCTestPrintPassedTestCase, fh );

        if( failed > 0 )
        {
            XSCTestLog(
                fh,
                XSCTestTermColorRed,
                XSCTestLogStyleNone,
                0,
                "%s failed:",
                XSCTestStringGetCString( failedString ) );

            XSCTestEnumerateFailedTestCases( XSCTestPrintFailedTestCase, fh );

            XSCTestLog( fh, XSCTestTermColorRed, XSCTestLogStyleNone, XSCTestLogOptionNewLineBefore, "TESTING FAILED" );
        }
        else
        {
            XSCTestLog( fh, XSCTestTermColorGreen, XSCTestLogStyleNone, XSCTestLogOptionNewLineBefore, "TESTING PASSED" );
        }

        XSCTestStringDelete( passedString );
        XSCTestStringDelete( failedString );
    }

    XSCTestStopWatchDelete( time );
    XSCTestStringDelete( casesString );
    XSCTestStringDelete( suitesString );

    return ret;
}
