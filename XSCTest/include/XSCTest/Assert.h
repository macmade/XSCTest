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
 * @header      Assert.h
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#ifndef XSCTEST_ASSERT_H
#define XSCTEST_ASSERT_H

#include <XSCTest/Failure.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

    bool XSCTestAssertBoolean( XSCTestFailureRef * failure, bool value, bool expected, const char * expression, const char * file, int line );
    bool XSCTestAssertStringEquality( XSCTestFailureRef * failure, const char * cp1, const char * cp2, bool expected, bool caseInsensitive, const char * expression1, const char * expression2, const char * file, int line );
    bool XSCTestAssertFloatCompareEqual( XSCTestFailureRef * failure, float v1, float v2, const char * expression1, const char * expression2, const char * file, int line );
    bool XSCTestAssertFloatCompareNotEqual( XSCTestFailureRef * failure, float v1, float v2, const char * expression1, const char * expression2, const char * file, int line );
    bool XSCTestAssertDoubleCompareEqual( XSCTestFailureRef * failure, double v1, double v2, const char * expression1, const char * expression2, const char * file, int line );
    bool XSCTestAssertDoubleCompareNotEqual( XSCTestFailureRef * failure, double v1, double v2, const char * expression1, const char * expression2, const char * file, int line );

#ifdef __cplusplus
}
#endif

#endif /* XSCTEST_ASSERT_H */
