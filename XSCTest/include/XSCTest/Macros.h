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

#define AssertTrue( _e_ )                                                                                                 \
    if( XSCTestAssertBoolean( _xscFailure_, ( _e_ ), true, XSCTestInternalXString( _e_ ), __FILE__, __LINE__ ) == false ) \
    return

#define AssertFalse( _e_ )                                                                                                 \
    if( XSCTestAssertBoolean( _xscFailure_, ( _e_ ), false, XSCTestInternalXString( _e_ ), __FILE__, __LINE__ ) == false ) \
    return

#define AssertStringEqual( _s1_, _s2_ )                                                                                                                                             \
    if( XSCTestAssertStringEquality( _xscFailure_, ( _s1_ ), ( _s2_ ), true, false, XSCTestInternalXString( _s1_ ), XSCTestInternalXString( _s2_ ), __FILE__, __LINE__ ) == false ) \
    return

#define AssertStringNotEqual( _s1_, _s2_ )                                                                                                                                           \
    if( XSCTestAssertStringEquality( _xscFailure_, ( _s1_ ), ( _s2_ ), false, false, XSCTestInternalXString( _s1_ ), XSCTestInternalXString( _s2_ ), __FILE__, __LINE__ ) == false ) \
    return

#define AssertStringEqualCaseInsensitive( _s1_, _s2_ )                                                                                                                             \
    if( XSCTestAssertStringEquality( _xscFailure_, ( _s1_ ), ( _s2_ ), true, true, XSCTestInternalXString( _s1_ ), XSCTestInternalXString( _s2_ ), __FILE__, __LINE__ ) == false ) \
    return

#define AssertStringNotEqualCaseInsensitive( _s1_, _s2_ )                                                                                                                           \
    if( XSCTestAssertStringEquality( _xscFailure_, ( _s1_ ), ( _s2_ ), false, true, XSCTestInternalXString( _s1_ ), XSCTestInternalXString( _s2_ ), __FILE__, __LINE__ ) == false ) \
    return

#define AssertEqual( _v1_, _v2_ )                                                                                                                                            \
    if( XSCTestAssertEqualGeneric( _v1_ )( _xscFailure_, ( _v1_ ), ( _v2_ ), XSCTestInternalXString( _v1_ ), XSCTestInternalXString( _v2_ ), __FILE__, __LINE__ ) == false ) \
    return

#define AssertNotEqual( _v1_, _v2_ )                                                                                                                                            \
    if( XSCTestAssertNotEqualGeneric( _v1_ )( _xscFailure_, ( _v1_ ), ( _v2_ ), XSCTestInternalXString( _v1_ ), XSCTestInternalXString( _v2_ ), __FILE__, __LINE__ ) == false ) \
    return

#define AssertLess( _v1_, _v2_ ) \
    ( void )_xscFailure_;        \
    ( void )( _v1_ );            \
    ( void )( _v2_ );

#define AssertLessOrEqual( _v1_, _v2_ ) \
    ( void )_xscFailure_;               \
    ( void )( _v1_ );                   \
    ( void )( _v2_ );

#define AssertGreater( _v1_, _v2_ ) \
    ( void )_xscFailure_;           \
    ( void )( _v1_ );               \
    ( void )( _v2_ );

#define AssertGreaterOrEqual( _v1_, _v2_ ) \
    ( void )_xscFailure_;                  \
    ( void )( _v1_ );                      \
    ( void )( _v2_ );

#define Test( _case_, _name_ )                                                     \
    void Test_##_case_##_##_name_##_Init( void ) __attribute__( ( constructor ) ); \
    void Test_##_case_##_##_name_( XSCTestFailureRef * _xscFailure_ );             \
    void Test_##_case_##_##_name_##_Init( void )                                   \
    {                                                                              \
        XSCTestRegisterTest(                                                       \
            XSCTestInternalString( _case_ ),                                       \
            XSCTestInternalString( _name_ ),                                       \
            Test_##_case_##_##_name_ );                                            \
    }                                                                              \
    void Test_##_case_##_##_name_( XSCTestFailureRef * _xscFailure_ )

#define XSCTestInternalXString( _s_ ) XSCTestInternalString( _s_ )
#define XSCTestInternalString( _s_ )  #_s_

#define XSCTestAssertEqualGeneric( _v_ ) _Generic( \
    ( _v_ ),                                       \
    signed char                                    \
    : XSCTestAssertIntegerCompareEqual,            \
      signed short                                 \
    : XSCTestAssertIntegerCompareEqual,            \
      signed int                                   \
    : XSCTestAssertIntegerCompareEqual,            \
      signed long                                  \
    : XSCTestAssertIntegerCompareEqual,            \
      signed long long                             \
    : XSCTestAssertIntegerCompareEqual,            \
      unsigned char                                \
    : XSCTestAssertUnsignedIntegerCompareEqual,    \
      unsigned short                               \
    : XSCTestAssertUnsignedIntegerCompareEqual,    \
      unsigned int                                 \
    : XSCTestAssertUnsignedIntegerCompareEqual,    \
      unsigned long                                \
    : XSCTestAssertUnsignedIntegerCompareEqual,    \
      unsigned long long                           \
    : XSCTestAssertUnsignedIntegerCompareEqual,    \
      float                                        \
    : XSCTestAssertFloatCompareEqual,              \
      double                                       \
    : XSCTestAssertDoubleCompareEqual )

#define XSCTestAssertNotEqualGeneric( _v_ ) _Generic( \
    ( _v_ ),                                          \
    signed char                                       \
    : XSCTestAssertIntegerCompareNotEqual,            \
      signed short                                    \
    : XSCTestAssertIntegerCompareNotEqual,            \
      signed int                                      \
    : XSCTestAssertIntegerCompareNotEqual,            \
      signed long                                     \
    : XSCTestAssertIntegerCompareNotEqual,            \
      signed long long                                \
    : XSCTestAssertIntegerCompareNotEqual,            \
      unsigned char                                   \
    : XSCTestAssertUnsignedIntegerCompareNotEqual,    \
      unsigned short                                  \
    : XSCTestAssertUnsignedIntegerCompareNotEqual,    \
      unsigned int                                    \
    : XSCTestAssertUnsignedIntegerCompareNotEqual,    \
      unsigned long                                   \
    : XSCTestAssertUnsignedIntegerCompareNotEqual,    \
      unsigned long long                              \
    : XSCTestAssertUnsignedIntegerCompareNotEqual,    \
      float                                           \
    : XSCTestAssertFloatCompareNotEqual,              \
      double                                          \
    : XSCTestAssertDoubleCompareNotEqual )

#ifdef __cplusplus
}
#endif

#endif /* XSCTEST_MACROS_H */
