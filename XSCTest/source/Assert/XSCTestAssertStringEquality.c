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
 * @file        XSCTestAssertStringEquality.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <string.h>

bool XSCTestAssertStringEquality( XSCTestFailureRef * failure, const char * cp1, const char * cp2, bool expected, bool caseInsensitive, const char * expression1, const char * expression2, const char * file, int line )
{
    bool result;

    if( cp1 == NULL || cp2 == NULL )
    {
        result = ( expected ) ? false : true;
    }
    else if( caseInsensitive )
    {
        result = strcasecmp( cp1, cp2 ) == 0;
    }
    else
    {
        result = strcmp( cp1, cp2 ) == 0;
    }

    if( result != expected )
    {
        XSCTestStringRef s1;
        XSCTestStringRef s2;
        XSCTestStringRef expression;
        XSCTestStringRef evaluated;

        s1         = ( cp1 == NULL ) ? XSCTestStringCreateWithCString( "NULL" ) : XSCTestStringCreateWithFormat( "\"%s\"", cp1 );
        s2         = ( cp1 == NULL ) ? XSCTestStringCreateWithCString( "NULL" ) : XSCTestStringCreateWithFormat( "\"%s\"", cp2 );
        expression = XSCTestStringCreateWithFormat( "%s %s %s", expression1, ( ( expected ) ? "==" : "!=" ), expression2 );
        evaluated  = XSCTestStringCreateWithFormat( "%s %s %s", XSCTestStringGetCString( s1 ), ( ( expected ) ? "==" : "!=" ), XSCTestStringGetCString( s2 ) );

        if( failure != NULL )
        {
            *( failure ) = XSCTestFailureCreate(
                XSCTestStringGetCString( expression ),
                XSCTestStringGetCString( evaluated ),
                ( expected ) ? "True" : "False",
                ( result ) ? "True" : "False",
                file,
                line );
        }

        XSCTestStringDelete( s1 );
        XSCTestStringDelete( s2 );
        XSCTestStringDelete( expression );
        XSCTestStringDelete( evaluated );
    }

    return result == expected;
}
