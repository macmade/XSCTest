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
 * @file        AssertFloatEqual.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <unistd.h>
#include <math.h>
#include <float.h>

Test( Success, AssertFloatEqual )
{
    usleep( 10000 );

    AssertEqual( 0.1f, 0.1f );
}

Test( Success, AssertFloatNotEqual )
{
    usleep( 10000 );

    AssertNotEqual( 0.1f, 0.2f );
}

Test( Success, AssertFloatEqual_NextAfter )
{
    float   f1 = 0.1f;
    float   f2 = nextafterf( f1, 0.2f );
    float   f3 = nextafterf( f1, 0.0f );
    int32_t i1 = *( ( int32_t * )&f1 );
    int32_t i2 = *( ( int32_t * )&f2 );
    int32_t i3 = *( ( int32_t * )&f3 );

    usleep( 10000 );

    AssertNotEqual( i1, i2 );
    AssertNotEqual( i1, i3 );
    AssertNotEqual( i2, i3 );

    AssertEqual( f1, f2 );
    AssertEqual( f1, f3 );
}

Test( Success, AssertFloatEqual_NextToward )
{
    float   f1 = 0.1f;
    float   f2 = nexttowardf( f1, ( long double )0.2 );
    float   f3 = nexttowardf( f1, ( long double )0.0 );
    int32_t i1 = *( ( int32_t * )&f1 );
    int32_t i2 = *( ( int32_t * )&f2 );
    int32_t i3 = *( ( int32_t * )&f3 );

    usleep( 10000 );

    AssertNotEqual( i1, i2 );
    AssertNotEqual( i1, i3 );
    AssertNotEqual( i2, i3 );

    AssertEqual( f1, f2 );
    AssertEqual( f1, f3 );
}

Test( Success, AssertFloatEqual_INF )
{
    usleep( 10000 );

    AssertEqual( HUGE_VAL, HUGE_VAL );
}

Test( Failure, AssertFloatNotEqual )
{
    usleep( 10000 );

    AssertNotEqual( 0.1f, 0.1f );
}

Test( Failure, AssertFloatEqual_NAN )
{
    usleep( 10000 );

    AssertEqual( NAN, NAN );
}

Test( Failure, AssertFloatEqual_Sign )
{
    usleep( 10000 );

    AssertEqual( 0.1f, -0.1f );
}

Test( Failure, AssertFloatEqual_Epsilon )
{
    usleep( 10000 );

    AssertEqual( 0.1f, 0.1f + FLT_EPSILON );
}
