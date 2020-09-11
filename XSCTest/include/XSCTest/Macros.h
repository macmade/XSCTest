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
 * @header      Macros.h
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#ifndef XSCTEST_MACROS_H
#define XSCTEST_MACROS_H

#ifdef __cplusplus
extern "C" {
#endif

#define AssertTrue( _e_ )                                                                                       \
    do                                                                                                          \
    {                                                                                                           \
        if( XSCTestAssertBoolean( ( _e_ ), true, XSCTestInternalXString( _e_ ), __FILE__, __LINE__ ) == false ) \
        {                                                                                                       \
            return;                                                                                             \
        }                                                                                                       \
    }                                                                                                           \
    while( 0 )

#define AssertFalse( _e_ )                                                                                       \
    do                                                                                                           \
    {                                                                                                            \
        if( XSCTestAssertBoolean( ( _e_ ), false, XSCTestInternalXString( _e_ ), __FILE__, __LINE__ ) == false ) \
        {                                                                                                        \
            return;                                                                                              \
        }                                                                                                        \
    }                                                                                                            \
    while( 0 )

#define Test( _case_, _name_ )                                                     \
    void Test_##_case_##_##_name_##_Init( void ) __attribute__( ( constructor ) ); \
    void Test_##_case_##_##_name_( void );                                         \
    void Test_##_case_##_##_name_##_Init( void )                                   \
    {                                                                              \
        XSCTestRegisterTest(                                                       \
            XSCTestInternalString( _case_ ),                                       \
            XSCTestInternalString( _name_ ),                                       \
            Test_##_case_##_##_name_ );                                            \
    }                                                                              \
    void Test_##_case_##_##_name_( void )

#define XSCTestInternalXString( _s_ ) XSCTestInternalString( _s_ )
#define XSCTestInternalString( _s_ )  #_s_

#ifdef __cplusplus
}
#endif

#endif /* XSCTEST_MACROS_H */
