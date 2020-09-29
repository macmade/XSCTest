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
 * @file        XSCTestANSISequence.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest-Internal.h>

const char * XSCTestANSISequence( XSCTestTermColor foreground )
{
    switch( foreground )
    {
        case XSCTestTermColorNone: return "\033[00m";
        case XSCTestTermColorGray: return "\033[30m";
        case XSCTestTermColorRed: return "\033[31m";
        case XSCTestTermColorGreen: return "\033[32m";
        case XSCTestTermColorYellow: return "\033[33m";
        case XSCTestTermColorBlue: return "\033[34m";
        case XSCTestTermColorMagenta: return "\033[35m";
        case XSCTestTermColorCyan: return "\033[36m";
        case XSCTestTermColorWhite: return "\033[37m";
    }

#ifdef _WIN32
    return "";
#endif
}
