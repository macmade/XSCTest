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
 * @file        XSCTestFailureDelete.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XSCTest/Private/Failure.h>
#include <stdlib.h>
#include <string.h>

XSCTestFailureRef XSCTestFailureCreate( const char * expression, const char * evaluated, const char * expected, const char * actual, const char * file, int line )
{
    struct XSCTestFailure * failure;

    failure = calloc( 1, sizeof( struct XSCTestFailure ) );

    if( failure == NULL )
    {
        return NULL;
    }

    failure->expression  = XSCTestStringCreateWithCString( expression );
    failure->evaluated   = XSCTestStringCreateWithCString( evaluated );
    failure->expected    = XSCTestStringCreateWithCString( expected );
    failure->actual      = XSCTestStringCreateWithCString( actual );
    failure->file        = XSCTestStringCreateWithCString( file );
    failure->line        = line;
    failure->description = XSCTestStringCreateWithCString( "" );

    if( expression != NULL && strlen( expression ) != 0 )
    {
        XSCTestStringAppendFormat( failure->description, "Expression: %s", expression );
    }

    if( evaluated != NULL && strlen( evaluated ) != 0 && strcmp( expression, evaluated ) != 0 )
    {
        if( XSCTestStringGetLength( failure->description ) > 0 )
        {
            XSCTestStringAppendCString( failure->description, " | " );
        }

        XSCTestStringAppendFormat( failure->description, "Evaluated: %s", evaluated );
    }

    if( expected != NULL && strlen( expected ) != 0 )
    {
        if( XSCTestStringGetLength( failure->description ) > 0 )
        {
            XSCTestStringAppendCString( failure->description, " | " );
        }

        XSCTestStringAppendFormat( failure->description, "Expected: %s", expected );
    }

    if( actual != NULL && strlen( actual ) != 0 )
    {
        if( XSCTestStringGetLength( failure->description ) > 0 )
        {
            XSCTestStringAppendCString( failure->description, " | " );
        }

        XSCTestStringAppendFormat( failure->description, "Actual: %s", actual );
    }

    return failure;
}
