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
    struct XSCTestSuiteList * list;
    bool                      ret;
    XSCTestStopWatchRef       time;
    size_t                    suites;
    size_t                    cases;

    ret  = true;
    list = XSCTestSuites;
    time = XSCTestStopWatchCreate();

    suites = XSCTestGetNumberOfSuites();
    cases  = 0;

    while( list != NULL )
    {
        cases += XSCTestSuiteGetNumberOfTestCases( list->suite );
        list = list->next;
    }

    if( suites == 0 || cases == 0 )
    {
        XSCTestLog( fh, XSCTestTermColorNone, XSCTestLogStyleFailure, 0, "No test to run..." );

        return false;
    }

    if( suites == 1 && cases == 1 )
    {
        XSCTestLog( fh, XSCTestTermColorNone, XSCTestLogStyleNone, 0, "Running %zu test cases from %zu test suites", cases, suites );
    }
    else if( suites == 1 )
    {
        XSCTestLog( fh, XSCTestTermColorNone, XSCTestLogStyleNone, 0, "Running %zu test cases from %zu test suite", cases, suites );
    }
    else if( cases == 1 )
    {
        XSCTestLog( fh, XSCTestTermColorNone, XSCTestLogStyleNone, 0, "Running %zu test case from %zu test suites", cases, suites );
    }
    else
    {
        XSCTestLog( fh, XSCTestTermColorNone, XSCTestLogStyleNone, 0, "Running %zu test cases from %zu test suites", cases, suites );
    }

    list = XSCTestSuites;

    XSCTestStopWatchStart( time );

    while( list != NULL )
    {
        if( XSCTestSuiteRun( list->suite, fh ) == false )
        {
            ret = false;
        }

        list = list->next;
    }

    XSCTestStopWatchStop( time );

    XSCTestStopWatchDelete( time );

    return ret;
}
