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

#ifdef _WIN32
#pragma warning( push )
#pragma warning( disable : 5105 )
#include <Windows.h>
#pragma warning( pop )
#endif

bool XSCTestRunAllSuites( FILE * fh, XSCTestArgumentsRef args )
{
    XSCTestStopWatchRef time;
    size_t              suites;
    size_t              cases;
    size_t              passed;
    size_t              failed;
    XSCTestStringRef    casesString;
    XSCTestStringRef    suitesString;
    XSCTestArrayRef     tests;

    #ifdef _WIN32
    UINT cp = GetConsoleOutputCP();
    #endif

    passed       = 0;
    failed       = 0;
    time         = XSCTestStopWatchCreate();
    tests        = XSCTestCreateListOfRunnableTestCases( args, &suites, &cases );
    casesString  = XSCTestCreateNumberedString( "test case", cases );
    suitesString = XSCTestCreateNumberedString( "test suite", suites );

    if( suites == 0 || cases == 0 )
    {
        XSCTestLog( fh, XSCTestTermColorNone, XSCTestLogStyleFailure, 0, "No test to run..." );
        XSCTestArrayDelete( tests );

        return false;
    }

    #ifdef _WIN32
    SetConsoleOutputCP( CP_UTF8 );
    #endif

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
        XSCTestSuiteRun( XSCTestArrayGetValueAtIndex( XSCTestSuites, i ), fh, args );
    }

    XSCTestStopWatchStop( time );

    {
        XSCTestStringRef passedString;
        XSCTestStringRef failedString;

        for( size_t i = 0; i < XSCTestArrayGetCount( tests ); i++ )
        {
            if( XSCTestCaseGetFailure( XSCTestArrayGetValueAtIndex( tests, i ) ) == NULL )
            {
                passed++;
            }
            else
            {
                failed++;
            }
        }

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

        for( size_t i = 0; i < XSCTestArrayGetCount( tests ); i++ )
        {
            XSCTestCaseRef testCase;

            testCase = XSCTestArrayGetValueAtIndex( tests, i );

            if( XSCTestCaseGetFailure( testCase ) == NULL )
            {
                XSCTestLogTestCase( fh, XSCTestCaseGetSuiteName( testCase ), XSCTestCaseGetName( testCase ), "  - ✅ " );
            }
        }

        if( failed > 0 )
        {
            XSCTestLog(
                fh,
                XSCTestTermColorRed,
                XSCTestLogStyleNone,
                0,
                "%s failed:",
                XSCTestStringGetCString( failedString ) );

            for( size_t i = 0; i < XSCTestArrayGetCount( tests ); i++ )
            {
                XSCTestCaseRef testCase;

                testCase = XSCTestArrayGetValueAtIndex( tests, i );

                if( XSCTestCaseGetFailure( testCase ) != NULL )
                {
                    XSCTestLogTestCase( fh, XSCTestCaseGetSuiteName( testCase ), XSCTestCaseGetName( testCase ), "  - ❌ " );
                }
            }

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
    XSCTestArrayDelete( tests );

    #ifdef _WIN32
    SetConsoleOutputCP( cp );
    #endif

    return failed == 0;
}
