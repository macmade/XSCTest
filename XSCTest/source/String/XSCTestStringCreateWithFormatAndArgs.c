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
 * @file        XSCTestStringCreateWithFormatAndArgs.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest-Internal.h>
#include <XSCTest/Private/String.h>
#include <string.h>
#include <stdlib.h>

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat-nonliteral"
#endif

XSCTestStringRef XSCTestStringCreateWithFormatAndArgs( const char * fmt, va_list ap )
{
    XSCTestStringRef string;
    int              length;
    va_list          ap2;

    if( fmt == NULL || strlen( fmt ) == 0 )
    {
        return XSCTestStringCreateWithCString( "" );
    }

    string = calloc( 1, sizeof( struct XSCTestString ) );

    if( string == NULL )
    {
        return NULL;
    }

    va_copy( ap2, ap );

    length = vsnprintf( NULL, 0, fmt, ap );

    if( length < 0 )
    {
        free( string );
        va_end( ap2 );

        return XSCTestStringCreateWithCString( "" );
    }

    string->length = ( size_t )length;
    string->cstr   = calloc( 1, string->length + 1 );

    if( string->cstr == NULL )
    {
        free( string );
        va_end( ap2 );

        return NULL;
    }

    vsnprintf( string->cstr, string->length + 1, fmt, ap2 );
    va_end( ap2 );

    return string;
}

#ifdef __clang__
#pragma clang diagnostic pop
#endif
