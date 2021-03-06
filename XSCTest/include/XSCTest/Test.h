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
 * @header      Test.h
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#ifndef XSCTEST_TEST_H
#define XSCTEST_TEST_H

#ifdef XSCTEST_INTERNAL_H
#include <XSCTest/Arguments.h>
#include <XSCTest/Suite.h>
#endif

#include <XSCTest/Failure.h>
#include <stddef.h>
#include <stdio.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

    int  XSCTestRun( FILE * fh, int argc, char * argv[] );
    void XSCTestRegisterTest( const char * suite, const char * name, void ( *func )( XSCTestFailureRef * ) );

#ifdef XSCTEST_INTERNAL_H

    bool            XSCTestRunAllSuites( FILE * fh, XSCTestArgumentsRef args );
    size_t          XSCTestGetNumberOfSuites( void );
    size_t          XSCTestGetNumberOfTestCases( void );
    XSCTestSuiteRef XSCTestGetSuiteNamed( const char * name );
    XSCTestArrayRef XSCTestCreateListOfRunnableTestCases( XSCTestArgumentsRef args, size_t * suiteCount, size_t * caseCount );

#endif

#ifdef __cplusplus
}
#endif

#endif /* XSCTEST_TEST_H */
