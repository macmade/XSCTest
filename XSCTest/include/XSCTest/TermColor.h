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
 * @header      TermColor.h
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#ifndef XSCTEST_TERM_COLOR_H
#define XSCTEST_TERM_COLOR_H

#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

    typedef enum
    {
        XSCTestTermColorNone,
        XSCTestTermColorGray,
        XSCTestTermColorRed,
        XSCTestTermColorGreen,
        XSCTestTermColorYellow,
        XSCTestTermColorBlue,
        XSCTestTermColorMagenta,
        XSCTestTermColorCyan,
        XSCTestTermColorWhite
    } XSCTestTermColor;

    bool         XSCTestSupportsANSISequences( FILE * fh );
    const char * XSCTestANSISequence( XSCTestTermColor foreground );
    void         XSCTestColorPrint( FILE * fh, XSCTestTermColor foreground, const char * fmt, ... ) __attribute__( ( format( printf, 3, 4 ) ) );

#ifdef __cplusplus
}
#endif

#endif /* XSCTEST_TERM_COLOR_H */
