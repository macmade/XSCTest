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
 * @file        XSCTestLogTestCaseResult.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest-Internal.h>
#include <string.h>

void XSCTestLogTestCaseResult( FILE * fh, const char * testSuite, const char * testCase, XSCTestFailureRef failure, XSCTestStopWatchRef time )
{
    if( fh == NULL )
    {
        return;
    }

    if( failure != NULL )
    {
        XSCTestLogFailedPrompt( fh );
    }
    else
    {
        XSCTestLogSuccessPrompt( fh );
    }

    XSCTestColorPrint( fh, XSCTestTermColorBlue, "%s", testSuite );
    XSCTestColorPrint( fh, XSCTestTermColorNone, "." );
    XSCTestColorPrint( fh, XSCTestTermColorMagenta, "%s", testCase );

    if( time != NULL )
    {
        XSCTestColorPrint( fh, XSCTestTermColorNone, " - %s", XSCTestStopWatchGetString( time ) );
    }

    XSCTestColorPrint( fh, XSCTestTermColorNone, "\n" );

    if( failure != NULL )
    {
        const char * file;
        const char * expression;
        const char * evaluated;
        const char * expected;
        const char * actual;

        file       = XSCTestFailureGetFile( failure );
        expression = XSCTestFailureGetExpression( failure );
        evaluated  = XSCTestFailureGetEvaluated( failure );
        expected   = XSCTestFailureGetExpected( failure );
        actual     = XSCTestFailureGetActual( failure );

        if( file == NULL || strlen( file ) == 0 )
        {
            file = "<unknown>";
        }

        XSCTestColorPrint( fh, XSCTestTermColorNone, "            - File:       " );
        XSCTestColorPrint( fh, XSCTestTermColorYellow, "%s:%i", file, XSCTestFailureGetLine( failure ) );

        if( expression != NULL && strlen( expression ) > 0 )
        {
            XSCTestColorPrint( fh, XSCTestTermColorNone, "\n" );
            XSCTestColorPrint( fh, XSCTestTermColorNone, "            - Expression: " );
            XSCTestColorPrint( fh, XSCTestTermColorCyan, "%s", expression );

            if( evaluated != NULL && strlen( evaluated ) > 0 && strcmp( expression, evaluated ) != 0 )
            {
                XSCTestColorPrint( fh, XSCTestTermColorNone, "\n" );
                XSCTestColorPrint( fh, XSCTestTermColorNone, "            - Evaluated:  " );
                XSCTestColorPrint( fh, XSCTestTermColorBlue, "%s", evaluated );
            }

            if( expected != NULL && strlen( expected ) > 0 )
            {
                XSCTestColorPrint( fh, XSCTestTermColorNone, "\n" );
                XSCTestColorPrint( fh, XSCTestTermColorNone, "            - Expected:   " );
                XSCTestColorPrint( fh, XSCTestTermColorGreen, "%s", expected );
            }

            if( actual != NULL && strlen( actual ) > 0 )
            {
                XSCTestColorPrint( fh, XSCTestTermColorNone, "\n" );
                XSCTestColorPrint( fh, XSCTestTermColorNone, "            - Actual:     " );
                XSCTestColorPrint( fh, XSCTestTermColorRed, "%s", actual );
            }
        }
        else
        {
            XSCTestColorPrint( fh, XSCTestTermColorNone, "\n" );
            XSCTestColorPrint( fh, XSCTestTermColorNone, "            - Reason:     " );
            XSCTestColorPrint( fh, XSCTestTermColorRed, "%s", XSCTestFailureGetDescription( failure ) );
        }

        XSCTestColorPrint( fh, XSCTestTermColorNone, "\n" );
    }
}
