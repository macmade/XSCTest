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
 * @file        XSCTestAssertFloatCompareLess.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <string.h>

bool XSCTestAssertFloatCompareLess( XSCTestFailureRef * failure, float v1, float v2, const char * expression1, const char * expression2, const char * file, int line )
{
    XSCTestStringRef expression;
    XSCTestStringRef evaluated;

    if( v1 < v2 )
    {
        return true;
    }

    expression = XSCTestStringCreateWithFormat( "%s < %s", expression1, expression2 );
    evaluated  = XSCTestStringCreateWithFormat( "%f < %f", ( double )v1, ( double )v2 );

    if( failure != NULL )
    {
        *( failure ) = XSCTestFailureCreate(
            XSCTestStringGetCString( expression ),
            XSCTestStringGetCString( evaluated ),
            "True",
            "False",
            file,
            line );
    }

    XSCTestStringDelete( expression );
    XSCTestStringDelete( evaluated );

    return false;
}
