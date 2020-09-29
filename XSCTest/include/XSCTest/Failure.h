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
 * @header      Failure.h
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#ifndef XSCTEST_FAILURE_H
#define XSCTEST_FAILURE_H

#ifdef XSCTEST_INTERNAL_H
#include <XSCTest/String.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct XSCTestFailure * XSCTestFailureRef;

#ifdef XSCTEST_INTERNAL_H

    XSCTestFailureRef XSCTestFailureCreate( const char * expression, const char * evaluated, const char * expected, const char * actual, const char * file, int line );
    void              XSCTestFailureDelete( XSCTestFailureRef failure );
    const char *      XSCTestFailureGetDescription( XSCTestFailureRef failure );
    const char *      XSCTestFailureGetExpression( XSCTestFailureRef failure );
    const char *      XSCTestFailureGetEvaluated( XSCTestFailureRef failure );
    const char *      XSCTestFailureGetExpected( XSCTestFailureRef failure );
    const char *      XSCTestFailureGetActual( XSCTestFailureRef failure );
    const char *      XSCTestFailureGetFile( XSCTestFailureRef failure );
    int               XSCTestFailureGetLine( XSCTestFailureRef failure );

#endif

#ifdef __cplusplus
}
#endif

#endif /* XSCTEST_FAILURE_H */
