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

#define AssertLess( _v1_, _v2_ )                                                                                                                                            \
    if( XSCTestAssertLessGeneric( _v1_ )( _xscFailure_, ( _v1_ ), ( _v2_ ), XSCTestInternalXString( _v1_ ), XSCTestInternalXString( _v2_ ), __FILE__, __LINE__ ) == false ) \
    return

#define AssertLessOrEqual( _v1_, _v2_ )                                                                                                                                            \
    if( XSCTestAssertLessOrEqualGeneric( _v1_ )( _xscFailure_, ( _v1_ ), ( _v2_ ), XSCTestInternalXString( _v1_ ), XSCTestInternalXString( _v2_ ), __FILE__, __LINE__ ) == false ) \
    return

#define AssertGreater( _v1_, _v2_ )                                                                                                                                            \
    if( XSCTestAssertGreaterGeneric( _v1_ )( _xscFailure_, ( _v1_ ), ( _v2_ ), XSCTestInternalXString( _v1_ ), XSCTestInternalXString( _v2_ ), __FILE__, __LINE__ ) == false ) \
    return

#define AssertGreaterOrEqual( _v1_, _v2_ )                                                                                                                                            \
    if( XSCTestAssertGreaterOrEqualGeneric( _v1_ )( _xscFailure_, ( _v1_ ), ( _v2_ ), XSCTestInternalXString( _v1_ ), XSCTestInternalXString( _v2_ ), __FILE__, __LINE__ ) == false ) \
    return

#ifdef _MSC_VER

#pragma section( ".CRT$XCU", read )

#define XSCTEST_CONSTRUCTOR( _name_ )                                                  \
    static void __cdecl _name_( void );                                                \
    __declspec( allocate( ".CRT$XCU" ) ) void( __cdecl * _name_##_ )( void ) = _name_; \
    static void __cdecl _name_( void )

#else

#define XSCTEST_CONSTRUCTOR( _name_ )                            \
    static void _name_( void ) __attribute__( ( constructor ) ); \
    static void _name_( void )

#endif

#define Test( _case_, _name_ )                                         \
    void Test_##_case_##_##_name_( XSCTestFailureRef * _xscFailure_ ); \
    XSCTEST_CONSTRUCTOR( Test_##_case_##_##_name_##_Init )             \
    {                                                                  \
        XSCTestRegisterTest(                                           \
            XSCTestInternalString( _case_ ),                           \
            XSCTestInternalString( _name_ ),                           \
            Test_##_case_##_##_name_ );                                \
    }                                                                  \
    void Test_##_case_##_##_name_( XSCTestFailureRef * _xscFailure_ )

#define XSCTestInternalXString( _s_ ) XSCTestInternalString( _s_ )
#define XSCTestInternalString( _s_ )  #_s_

#ifdef _WIN32
#define XSCTestAssertEqualGenericChar char: XSCTestAssertIntegerCompareEqual
#else
#define XSCTestAssertEqualGenericChar char: XSCTestAssertIntegerCompareEqual, signed char: XSCTestAssertIntegerCompareEqual
#endif

#define XSCTestAssertEqualGeneric( _v_ ) _Generic( \
    ( _v_ ),                                       \
    XSCTestAssertEqualGenericChar,                 \
    signed short                                   \
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

#ifdef _WIN32
#define XSCTestAssertNotEqualGenericChar char: XSCTestAssertIntegerCompareNotEqual
#else
#define XSCTestAssertNotEqualGenericChar char: XSCTestAssertIntegerCompareNotEqual, signed char: XSCTestAssertIntegerCompareNotEqual
#endif

#define XSCTestAssertNotEqualGeneric( _v_ ) _Generic( \
    ( _v_ ),                                          \
    XSCTestAssertNotEqualGenericChar,                 \
    signed short                                      \
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

#ifdef _WIN32
#define XSCTestAssertLessGenericChar char: XSCTestAssertIntegerCompareLess
#else
#define XSCTestAssertLessGenericChar char: XSCTestAssertIntegerCompareLess, signed char: XSCTestAssertIntegerCompareLess
#endif

#define XSCTestAssertLessGeneric( _v_ ) _Generic( \
    ( _v_ ),                                      \
    XSCTestAssertLessGenericChar,                 \
    signed short                                  \
    : XSCTestAssertIntegerCompareLess,            \
      signed int                                  \
    : XSCTestAssertIntegerCompareLess,            \
      signed long                                 \
    : XSCTestAssertIntegerCompareLess,            \
      signed long long                            \
    : XSCTestAssertIntegerCompareLess,            \
      unsigned char                               \
    : XSCTestAssertUnsignedIntegerCompareLess,    \
      unsigned short                              \
    : XSCTestAssertUnsignedIntegerCompareLess,    \
      unsigned int                                \
    : XSCTestAssertUnsignedIntegerCompareLess,    \
      unsigned long                               \
    : XSCTestAssertUnsignedIntegerCompareLess,    \
      unsigned long long                          \
    : XSCTestAssertUnsignedIntegerCompareLess,    \
      float                                       \
    : XSCTestAssertFloatCompareLess,              \
      double                                      \
    : XSCTestAssertDoubleCompareLess )

#ifdef _WIN32
#define XSCTestAssertLessOrEqualGenericChar char: XSCTestAssertIntegerCompareLessOrEqual
#else
#define XSCTestAssertLessOrEqualGenericChar char: XSCTestAssertIntegerCompareLessOrEqual, signed char: XSCTestAssertIntegerCompareLessOrEqual
#endif

#define XSCTestAssertLessOrEqualGeneric( _v_ ) _Generic( \
    ( _v_ ),                                             \
    XSCTestAssertLessOrEqualGenericChar,                 \
    signed short                                         \
    : XSCTestAssertIntegerCompareLessOrEqual,            \
      signed int                                         \
    : XSCTestAssertIntegerCompareLessOrEqual,            \
      signed long                                        \
    : XSCTestAssertIntegerCompareLessOrEqual,            \
      signed long long                                   \
    : XSCTestAssertIntegerCompareLessOrEqual,            \
      unsigned char                                      \
    : XSCTestAssertUnsignedIntegerCompareLessOrEqual,    \
      unsigned short                                     \
    : XSCTestAssertUnsignedIntegerCompareLessOrEqual,    \
      unsigned int                                       \
    : XSCTestAssertUnsignedIntegerCompareLessOrEqual,    \
      unsigned long                                      \
    : XSCTestAssertUnsignedIntegerCompareLessOrEqual,    \
      unsigned long long                                 \
    : XSCTestAssertUnsignedIntegerCompareLessOrEqual,    \
      float                                              \
    : XSCTestAssertFloatCompareLessOrEqual,              \
      double                                             \
    : XSCTestAssertDoubleCompareLessOrEqual )

#ifdef _WIN32
#define XSCTestAssertGreaterGenericChar char: XSCTestAssertIntegerCompareGreater
#else
#define XSCTestAssertGreaterGenericChar char: XSCTestAssertIntegerCompareGreater, signed char: XSCTestAssertIntegerCompareGreater
#endif

#define XSCTestAssertGreaterGeneric( _v_ ) _Generic( \
    ( _v_ ),                                         \
    XSCTestAssertGreaterGenericChar,                 \
    signed short                                     \
    : XSCTestAssertIntegerCompareGreater,            \
      signed int                                     \
    : XSCTestAssertIntegerCompareGreater,            \
      signed long                                    \
    : XSCTestAssertIntegerCompareGreater,            \
      signed long long                               \
    : XSCTestAssertIntegerCompareGreater,            \
      unsigned char                                  \
    : XSCTestAssertUnsignedIntegerCompareGreater,    \
      unsigned short                                 \
    : XSCTestAssertUnsignedIntegerCompareGreater,    \
      unsigned int                                   \
    : XSCTestAssertUnsignedIntegerCompareGreater,    \
      unsigned long                                  \
    : XSCTestAssertUnsignedIntegerCompareGreater,    \
      unsigned long long                             \
    : XSCTestAssertUnsignedIntegerCompareGreater,    \
      float                                          \
    : XSCTestAssertFloatCompareGreater,              \
      double                                         \
    : XSCTestAssertDoubleCompareGreater )

#ifdef _WIN32
#define XSCTestAssertGreaterOrEqualGenericChar char: XSCTestAssertIntegerCompareGreaterOrEqual
#else
#define XSCTestAssertGreaterOrEqualGenericChar char: XSCTestAssertIntegerCompareGreaterOrEqual, signed char: XSCTestAssertIntegerCompareGreaterOrEqual
#endif

#define XSCTestAssertGreaterOrEqualGeneric( _v_ ) _Generic( \
    ( _v_ ),                                                \
    XSCTestAssertGreaterOrEqualGenericChar,                 \
    signed short                                            \
    : XSCTestAssertIntegerCompareGreaterOrEqual,            \
      signed int                                            \
    : XSCTestAssertIntegerCompareGreaterOrEqual,            \
      signed long                                           \
    : XSCTestAssertIntegerCompareGreaterOrEqual,            \
      signed long long                                      \
    : XSCTestAssertIntegerCompareGreaterOrEqual,            \
      unsigned char                                         \
    : XSCTestAssertUnsignedIntegerCompareGreaterOrEqual,    \
      unsigned short                                        \
    : XSCTestAssertUnsignedIntegerCompareGreaterOrEqual,    \
      unsigned int                                          \
    : XSCTestAssertUnsignedIntegerCompareGreaterOrEqual,    \
      unsigned long                                         \
    : XSCTestAssertUnsignedIntegerCompareGreaterOrEqual,    \
      unsigned long long                                    \
    : XSCTestAssertUnsignedIntegerCompareGreaterOrEqual,    \
      float                                                 \
    : XSCTestAssertFloatCompareGreaterOrEqual,              \
      double                                                \
    : XSCTestAssertDoubleCompareGreaterOrEqual )

#ifdef __cplusplus
}
#endif

#endif /* XSCTEST_MACROS_H */
