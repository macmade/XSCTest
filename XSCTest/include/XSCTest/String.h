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
 * @header      String.h
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#ifndef XSCTEST_STRING_H
#define XSCTEST_STRING_H

#include <stddef.h>
#include <stdarg.h>
#include <stdbool.h>
#include <XSCTest/Compiler-Support.h>

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct XSCTestString * XSCTestStringRef;

    XSCTestStringRef XSCTestStringCreateWithCString( const char * s );
    XSCTestStringRef XSCTestStringCreateWithFormat( const char * fmt, ... ) XSCTEST_ATTRIBUTE_FORMAT( 1, 2 );
    XSCTestStringRef XSCTestStringCreateWithFormatAndArgs( const char * fmt, va_list ap );
    void             XSCTestStringDelete( XSCTestStringRef string );
    size_t           XSCTestStringGetLength( XSCTestStringRef string );
    const char *     XSCTestStringGetCString( XSCTestStringRef string );
    void             XSCTestStringAppendString( XSCTestStringRef string, XSCTestStringRef append );
    void             XSCTestStringAppendCString( XSCTestStringRef string, const char * append );
    void             XSCTestStringAppendFormat( XSCTestStringRef string, const char * fmt, ... ) XSCTEST_ATTRIBUTE_FORMAT( 2, 3 );
    void             XSCTestStringAppendFormatAndArgs( XSCTestStringRef string, const char * fmt, va_list ap );
    bool             XSCTestStringIsEqualToString( XSCTestStringRef string, XSCTestStringRef other );
    bool             XSCTestStringIsEqualToCString( XSCTestStringRef string, const char * other );

#ifdef __cplusplus
}
#endif

#endif /* XSCTEST_STRING_H */
