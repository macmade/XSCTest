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
 * @file        XSCTestStopWatchGetSeconds.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XSCTest/Private/StopWatch.h>
#include <string.h>
#include <stdlib.h>

const char * XSCTestStopWatchGetString( XSCTestStopWatchRef watch )
{
    if( watch == NULL || watch->status != XSCTestStopWatchStatusStopped )
    {
        return "";
    }

    if( watch->string == NULL )
    {
        int      size;
        uint64_t msec;

        msec = XSCTestStopWatchGetMilliseconds( watch );
        size = snprintf( NULL, 0, "%llu ms", msec );

        if( size <= 0 )
        {
            return "";
        }

        watch->string = calloc( ( size_t )size + 1, 1 );

        if( watch->string == NULL )
        {
            return "";
        }

        snprintf( watch->string, size + 1, "%llu ms", msec );
    }

    return watch->string;
}
