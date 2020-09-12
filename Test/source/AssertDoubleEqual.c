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
 * @file        AssertDoubleEqual.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <unistd.h>
#include <math.h>
#include <float.h>

Test( Success, AssertDoubleEqual )
{
    usleep( 10000 );

    AssertDoubleEqual( 0.1, 0.1 );
}

Test( Success, AssertDoubleNotEqual )
{
    usleep( 10000 );

    AssertDoubleNotEqual( 0.1, 0.2 );
}

Test( Success, AssertDoubleEqual_NextAfter )
{
    double  f1 = 0.1;
    double  f2 = nextafter( f1, 0.2 );
    double  f3 = nextafter( f1, 0.0 );
    int64_t i1 = *( ( int64_t * )&f1 );
    int64_t i2 = *( ( int64_t * )&f2 );
    int64_t i3 = *( ( int64_t * )&f3 );

    usleep( 10000 );

    AssertNotEqual( i1, i2 );
    AssertNotEqual( i1, i3 );
    AssertNotEqual( i2, i3 );

    AssertDoubleEqual( f1, f2 );
    AssertDoubleEqual( f1, f3 );
}

Test( Success, AssertDoubleEqual_NextToward )
{
    double  f1 = 0.1;
    double  f2 = nexttoward( f1, ( long double )0.2 );
    double  f3 = nexttoward( f1, ( long double )0.0 );
    int64_t i1 = *( ( int64_t * )&f1 );
    int64_t i2 = *( ( int64_t * )&f2 );
    int64_t i3 = *( ( int64_t * )&f3 );

    usleep( 10000 );

    AssertNotEqual( i1, i2 );
    AssertNotEqual( i1, i3 );
    AssertNotEqual( i2, i3 );

    AssertDoubleEqual( f1, f2 );
    AssertDoubleEqual( f1, f3 );
}

Test( Success, AssertDoubleEqual_INF )
{
    usleep( 10000 );

    AssertDoubleEqual( HUGE_VAL, HUGE_VAL );
}

Test( Failure, AssertDoubleNotEqual )
{
    usleep( 10000 );

    AssertDoubleNotEqual( 0.1, 0.1 );
}

Test( Failure, AssertDoubleEqual_NAN )
{
    usleep( 10000 );

    AssertDoubleEqual( NAN, NAN );
}

Test( Failure, AssertDoubleEqual_Sign )
{
    usleep( 10000 );

    AssertDoubleEqual( 0.1, -0.1 );
}

Test( Failure, AssertDoubleEqual_Epsilon )
{
    usleep( 10000 );

    AssertDoubleEqual( 0.1, 0.1 + DBL_EPSILON );
}
