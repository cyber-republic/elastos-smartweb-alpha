//=========================================================================
// Copyright (C) 2012 The Elastos Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=========================================================================

#ifndef __ELASTOS_CORE_STRICT_MATH_H__
#define __ELASTOS_CORE_STRICT_MATH_H__

#include <elastos.h>

namespace Elastos {
namespace Core {

/**
 * Class StrictMath provides basic math constants and operations such as
 * trigonometric functions, hyperbolic functions, exponential, logarithms, etc.
 * <p>
 * In contrast to class {@link Math}, the methods in this class return exactly
 * the same results on all platforms. Algorithms based on these methods thus
 * behave the same (e.g. regarding numerical convergence) on all platforms,
 * complying with the slogan "write once, run everywhere". On the other side,
 * the implementation of class StrictMath may be less efficient than that of
 * class Math, as class StrictMath cannot utilize platform specific features
 * such as an extended precision math co-processors.
 * <p>
 * The methods in this class are specified using the "Freely Distributable Math
 * Library" (fdlibm), version 5.3.
 * <p>
 * <a href="http://www.netlib.org/fdlibm/">http://www.netlib.org/fdlibm/</a>
 */
class ECO_PUBLIC StrictMath
{
public:
    /**
     * The Double value closest to e, the base of the natural logarithm.
     */
    static const Double E;// = 2.718281828459045;

    /**
     * The Double value closest to pi, the ratio of a circle's circumference to
     * its diameter.
     */
    static const Double PI;// = 3.141592653589793;

    /**
     * Returns the absolute value of the argument.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code abs(-0.0) = +0.0}</li>
     * <li>{@code abs(+infinity) = +infinity}</li>
     * <li>{@code abs(-infinity) = +infinity}</li>
     * <li>{@code abs(NaN) = NaN}</li>
     * </ul>
     */
    static CARAPI_(Double) Abs(
        /* [in] */ Double d);

    static CARAPI_(Float) Abs(
        /* [in] */ Float f);

    static CARAPI_(Int32) Abs(
        /* [in] */ Int32 i);

    static CARAPI_(Int64) Abs(
        /* [in] */ Int64 i);

    /**
     * Returns the closest Double approximation of the arc cosine of the
     * argument within the range {@code [0..pi]}.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code acos((anything > 1) = NaN}</li>
     * <li>{@code acos((anything < -1) = NaN}</li>
     * <li>{@code acos(NaN) = NaN}</li>
     * </ul>
     *
     * @param d
     *            the value to compute arc cosine of.
     * @return the arc cosine of the argument.
     */
    static CARAPI_(Double) Acos(
        /* [in] */ Double d);

    /**
     * Returns the closest Double approximation of the arc sine of the argument
     * within the range {@code [-pi/2..pi/2]}. The returned result is within 1
     * ulp (unit in the last place) of the real result.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code asin((anything > 1)) = NaN}</li>
     * <li>{@code asin((anything < -1)) = NaN}</li>
     * <li>{@code asin(NaN) = NaN}</li>
     * </ul>
     *
     * @param d
     *            the value whose arc sine has to be computed.
     * @return the arc sine of the argument.
     */
    static CARAPI_(Double) Asin(
        /* [in] */ Double d);

    /**
     * Returns the closest Double approximation of the arc tangent of the
     * argument within the range {@code [-pi/2..pi/2]}. The returned result is
     * within 1 ulp (unit in the last place) of the real result.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code atan(+0.0) = +0.0}</li>
     * <li>{@code atan(-0.0) = -0.0}</li>
     * <li>{@code atan(+infinity) = +pi/2}</li>
     * <li>{@code atan(-infinity) = -pi/2}</li>
     * <li>{@code atan(NaN) = NaN}</li>
     * </ul>
     *
     * @param d
     *            the value whose arc tangent has to be computed.
     * @return the arc tangent of the argument.
     */
    static CARAPI_(Double) Atan(
        /* [in] */ Double d);

    /**
     * Returns the closest Double approximation of the arc tangent of {@code
     * y/x} within the range {@code [-pi..pi]}. This is the angle of the polar
     * representation of the rectangular coordinates (x,y). The returned result
     * is within 2 ulps (units in the last place) of the real result.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code atan2((anything), NaN ) = NaN;}</li>
     * <li>{@code atan2(NaN , (anything) ) = NaN;}</li>
     * <li>{@code atan2(+0.0, +(anything but NaN)) = +0.0}</li>
     * <li>{@code atan2(-0.0, +(anything but NaN)) = -0.0}</li>
     * <li>{@code atan2(+0.0, -(anything but NaN)) = +pi}</li>
     * <li>{@code atan2(-0.0, -(anything but NaN)) = -pi}</li>
     * <li>{@code atan2(+(anything but 0 and NaN), 0) = +pi/2}</li>
     * <li>{@code atan2(-(anything but 0 and NaN), 0) = -pi/2}</li>
     * <li>{@code atan2(+(anything but infinity and NaN), +infinity)} {@code =}
     * {@code +0.0}</li>
     * <li>{@code atan2(-(anything but infinity and NaN), +infinity)} {@code =}
     * {@code -0.0}</li>
     * <li>{@code atan2(+(anything but infinity and NaN), -infinity) = +pi}</li>
     * <li>{@code atan2(-(anything but infinity and NaN), -infinity) = -pi}</li>
     * <li>{@code atan2(+infinity, +infinity ) = +pi/4}</li>
     * <li>{@code atan2(-infinity, +infinity ) = -pi/4}</li>
     * <li>{@code atan2(+infinity, -infinity ) = +3pi/4}</li>
     * <li>{@code atan2(-infinity, -infinity ) = -3pi/4}</li>
     * <li>{@code atan2(+infinity, (anything but,0, NaN, and infinity))} {@code
     * =} {@code +pi/2}</li>
     * <li>{@code atan2(-infinity, (anything but,0, NaN, and infinity))} {@code
     * =} {@code -pi/2}</li>
     * </ul>
     *
     * @param y
     *            the numerator of the value whose atan has to be computed.
     * @param x
     *            the denominator of the value whose atan has to be computed.
     * @return the arc tangent of {@code y/x}.
     */
    static CARAPI_(Double) Atan2(
        /* [in] */ Double y,
        /* [in] */ Double x);

    /**
     * Returns the closest Double approximation of the cube root of the
     * argument.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code cbrt(+0.0) = +0.0}</li>
     * <li>{@code cbrt(-0.0) = -0.0}</li>
     * <li>{@code cbrt(+infinity) = +infinity}</li>
     * <li>{@code cbrt(-infinity) = -infinity}</li>
     * <li>{@code cbrt(NaN) = NaN}</li>
     * </ul>
     *
     * @param d
     *            the value whose cube root has to be computed.
     * @return the cube root of the argument.
     */
    static CARAPI_(Double) Cbrt(
        /* [in] */ Double d);

    /**
     * Returns the Double conversion of the most negative (closest to negative
     * infinity) integer value greater than or equal to the argument.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code ceil(+0.0) = +0.0}</li>
     * <li>{@code ceil(-0.0) = -0.0}</li>
     * <li>{@code ceil((anything in range (-1,0)) = -0.0}</li>
     * <li>{@code ceil(+infinity) = +infinity}</li>
     * <li>{@code ceil(-infinity) = -infinity}</li>
     * <li>{@code ceil(NaN) = NaN}</li>
     * </ul>
     */
    static CARAPI_(Double) Ceil(
        /* [in] */ Double d);

    /**
     * Returns the closest Double approximation of the cosine of the argument.
     * The returned result is within 1 ulp (unit in the last place) of the real
     * result.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code cos(+infinity) = NaN}</li>
     * <li>{@code cos(-infinity) = NaN}</li>
     * <li>{@code cos(NaN) = NaN}</li>
     * </ul>
     *
     * @param d
     *            the angle whose cosine has to be computed, in radians.
     * @return the cosine of the argument.
     */
    static CARAPI_(Double) Cos(
        /* [in] */ Double d);

    /**
     * Returns the closest Double approximation of the hyperbolic cosine of the
     * argument. The returned result is within 2.5 ulps (units in the last
     * place) of the real result.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code cosh(+infinity) = +infinity}</li>
     * <li>{@code cosh(-infinity) = +infinity}</li>
     * <li>{@code cosh(NaN) = NaN}</li>
     * </ul>
     *
     * @param d
     *            the value whose hyperbolic cosine has to be computed.
     * @return the hyperbolic cosine of the argument.
     */
    static CARAPI_(Double) Cosh(
        /* [in] */ Double d);

    /**
     * Returns the closest Double approximation of the raising "e" to the power
     * of the argument. The returned result is within 1 ulp (unit in the last
     * place) of the real result.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code exp(+infinity) = +infinity}</li>
     * <li>{@code exp(-infinity) = +0.0}</li>
     * <li>{@code exp(NaN) = NaN}</li>
     * </ul>
     *
     * @param d
     *            the value whose exponential has to be computed.
     * @return the exponential of the argument.
     */
    static CARAPI_(Double) Exp(
        /* [in] */ Double d);

    /**
     * Returns the closest Double approximation of <i>{@code e}</i><sup> {@code
     * d}</sup>{@code - 1}. If the argument is very close to 0, it is much more
     * accurate to use {@code expm1(d)+1} than {@code exp(d)} (due to
     * cancellation of significant digits). The returned result is within 1 ulp
     * (unit in the last place) of the real result.
     * <p>
     * For any finite input, the result is not less than -1.0. If the real
     * result is within 0.5 ulp of -1, -1.0 is returned.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code expm1(+0.0) = +0.0}</li>
     * <li>{@code expm1(-0.0) = -0.0}</li>
     * <li>{@code expm1(+infinity) = +infinity}</li>
     * <li>{@code expm1(-infinity) = -1.0}</li>
     * <li>{@code expm1(NaN) = NaN}</li>
     * </ul>
     *
     * @param d
     *            the value to compute the <i>{@code e}</i><sup>{@code d} </sup>
     *            {@code - 1} of.
     * @return the <i>{@code e}</i><sup>{@code d}</sup>{@code - 1} value of the
     *         argument.
     */
    static CARAPI_(Double) Expm1(
        /* [in] */ Double d);

    /**
     * Returns the Double conversion of the most positive (closest to positive
     * infinity) integer value less than or equal to the argument.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code floor(+0.0) = +0.0}</li>
     * <li>{@code floor(-0.0) = -0.0}</li>
     * <li>{@code floor(+infinity) = +infinity}</li>
     * <li>{@code floor(-infinity) = -infinity}</li>
     * <li>{@code floor(NaN) = NaN}</li>
     * </ul>
     */
    static CARAPI_(Double) Floor(
        /* [in] */ Double d);

    /**
     * Returns {@code sqrt(}<i>{@code x}</i><sup>{@code 2}</sup>{@code +} <i>
     * {@code y}</i><sup>{@code 2}</sup>{@code )}. The final result is without
     * medium underflow or overflow. The returned result is within 1 ulp (unit
     * in the last place) of the real result. If one parameter remains constant,
     * the result should be semi-monotonic.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code hypot(+infinity, (anything including NaN)) = +infinity}</li>
     * <li>{@code hypot(-infinity, (anything including NaN)) = +infinity}</li>
     * <li>{@code hypot((anything including NaN), +infinity) = +infinity}</li>
     * <li>{@code hypot((anything including NaN), -infinity) = +infinity}</li>
     * <li>{@code hypot(NaN, NaN) = NaN}</li>
     * </ul>
     *
     * @param x
     *            a Double number.
     * @param y
     *            a Double number.
     * @return the {@code sqrt(}<i>{@code x}</i><sup>{@code 2}</sup>{@code +}
     *         <i> {@code y}</i><sup>{@code 2}</sup>{@code )} value of the
     *         arguments.
     */
    static CARAPI_(Double) Hypot(
        /* [in] */ Double x,
         /* [in] */ Double y);

    /**
     * Returns the remainder of dividing {@code x} by {@code y} using the IEEE
     * 754 rules. The result is {@code x-round(x/p)*p} where {@code round(x/p)}
     * is the nearest integer (rounded to even), but without numerical
     * cancellation problems.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code IEEEremainder((anything), 0) = NaN}</li>
     * <li>{@code IEEEremainder(+infinity, (anything)) = NaN}</li>
     * <li>{@code IEEEremainder(-infinity, (anything)) = NaN}</li>
     * <li>{@code IEEEremainder(NaN, (anything)) = NaN}</li>
     * <li>{@code IEEEremainder((anything), NaN) = NaN}</li>
     * <li>{@code IEEEremainder(x, +infinity) = x } where x is anything but
     * +/-infinity</li>
     * <li>{@code IEEEremainder(x, -infinity) = x } where x is anything but
     * +/-infinity</li>
     * </ul>
     *
     * @param x
     *            the numerator of the operation.
     * @param y
     *            the denominator of the operation.
     * @return the IEEE754 floating point reminder of of {@code x/y}.
     */
    static CARAPI_(Double) IEEEremainder(
        /* [in] */ Double x,
         /* [in] */ Double y);

    /**
     * Returns the closest Double approximation of the natural logarithm of the
     * argument. The returned result is within 1 ulp (unit in the last place) of
     * the real result.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code log(+0.0) = -infinity}</li>
     * <li>{@code log(-0.0) = -infinity}</li>
     * <li>{@code log((anything < 0) = NaN}</li>
     * <li>{@code log(+infinity) = +infinity}</li>
     * <li>{@code log(-infinity) = NaN}</li>
     * <li>{@code log(NaN) = NaN}</li>
     * </ul>
     *
     * @param d
     *            the value whose log has to be computed.
     * @return the natural logarithm of the argument.
     */
    static CARAPI_(Double) Log(
        /* [in] */ Double d);

    /**
     * Returns the closest Double approximation of the base 10 logarithm of the
     * argument. The returned result is within 1 ulp (unit in the last place) of
     * the real result.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code log10(+0.0) = -infinity}</li>
     * <li>{@code log10(-0.0) = -infinity}</li>
     * <li>{@code log10((anything < 0) = NaN}</li>
     * <li>{@code log10(+infinity) = +infinity}</li>
     * <li>{@code log10(-infinity) = NaN}</li>
     * <li>{@code log10(NaN) = NaN}</li>
     * </ul>
     *
     * @param d
     *            the value whose base 10 log has to be computed.
     * @return the natural logarithm of the argument.
     */
    static CARAPI_(Double) Log10(
        /* [in] */ Double d);

    /**
     * Returns the closest Double approximation of the natural logarithm of the
     * sum of the argument and 1. If the argument is very close to 0, it is much
     * more accurate to use {@code log1p(d)} than {@code log(1.0+d)} (due to
     * numerical cancellation). The returned result is within 1 ulp (unit in the
     * last place) of the real result and is semi-monotonic.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code log1p(+0.0) = +0.0}</li>
     * <li>{@code log1p(-0.0) = -0.0}</li>
     * <li>{@code log1p((anything < 1)) = NaN}</li>
     * <li>{@code log1p(-1.0) = -infinity}</li>
     * <li>{@code log1p(+infinity) = +infinity}</li>
     * <li>{@code log1p(-infinity) = NaN}</li>
     * <li>{@code log1p(NaN) = NaN}</li>
     * </ul>
     *
     * @param d
     *            the value to compute the {@code ln(1+d)} of.
     * @return the natural logarithm of the sum of the argument and 1.
     */
    static CARAPI_(Double) Log1p(
        /* [in] */ Double d);

    /**
     * Returns the most positive (closest to positive infinity) of the two
     * arguments.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code max(NaN, (anything)) = NaN}</li>
     * <li>{@code max((anything), NaN) = NaN}</li>
     * <li>{@code max(+0.0, -0.0) = +0.0}</li>
     * <li>{@code max(-0.0, +0.0) = +0.0}</li>
     * </ul>
     */
    static CARAPI_(Double) Max(
        /* [in] */ Double d1,
        /* [in] */ Double d2);

    /**
     * Returns the most positive (closest to positive infinity) of the two
     * arguments.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code max(NaN, (anything)) = NaN}</li>
     * <li>{@code max((anything), NaN) = NaN}</li>
     * <li>{@code max(+0.0, -0.0) = +0.0}</li>
     * <li>{@code max(-0.0, +0.0) = +0.0}</li>
     * </ul>
     */
    static CARAPI_(Float) Max(
        /* [in] */ Float f1,
        /* [in] */ Float f2);

    /**
     * Returns the most positive (closest to positive infinity) of the two
     * arguments.
     */
    static CARAPI_(Int32) Max(
        /* [in] */ Int32 i1,
        /* [in] */ Int32 i2);

    /**
     * Returns the most positive (closest to positive infinity) of the two
     * arguments.
     */
    static CARAPI_(Int64) Max(
        /* [in] */ Int64 l1,
        /* [in] */ Int64 l2);

    /**
     * Returns the most negative (closest to negative infinity) of the two
     * arguments.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code min(NaN, (anything)) = NaN}</li>
     * <li>{@code min((anything), NaN) = NaN}</li>
     * <li>{@code min(+0.0, -0.0) = -0.0}</li>
     * <li>{@code min(-0.0, +0.0) = -0.0}</li>
     * </ul>
     */
    static CARAPI_(Double) Min(
        /* [in] */ Double d1,
        /* [in] */ Double d2);

    /**
     * Returns the most negative (closest to negative infinity) of the two
     * arguments.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code min(NaN, (anything)) = NaN}</li>
     * <li>{@code min((anything), NaN) = NaN}</li>
     * <li>{@code min(+0.0, -0.0) = -0.0}</li>
     * <li>{@code min(-0.0, +0.0) = -0.0}</li>
     * </ul>
     */
    static CARAPI_(Float) Min(
        /* [in] */ Float f1,
        /* [in] */ Float f2);

    /**
     * Returns the most negative (closest to negative infinity) of the two
     * arguments.
     */
    static CARAPI_(Int32) Min(
        /* [in] */ Int32 i1,
        /* [in] */ Int32 i2);

    /**
     * Returns the most negative (closest to negative infinity) of the two
     * arguments.
     */
    static CARAPI_(Int64) Min(
        /* [in] */ Int64 l1,
        /* [in] */ Int64 l2);

    /**
     * Returns the closest Double approximation of the result of raising {@code
     * x} to the power of {@code y}.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code pow((anything), +0.0) = 1.0}</li>
     * <li>{@code pow((anything), -0.0) = 1.0}</li>
     * <li>{@code pow(x, 1.0) = x}</li>
     * <li>{@code pow((anything), NaN) = NaN}</li>
     * <li>{@code pow(NaN, (anything except 0)) = NaN}</li>
     * <li>{@code pow(+/-(|x| > 1), +infinity) = +infinity}</li>
     * <li>{@code pow(+/-(|x| > 1), -infinity) = +0.0}</li>
     * <li>{@code pow(+/-(|x| < 1), +infinity) = +0.0}</li>
     * <li>{@code pow(+/-(|x| < 1), -infinity) = +infinity}</li>
     * <li>{@code pow(+/-1.0 , +infinity) = NaN}</li>
     * <li>{@code pow(+/-1.0 , -infinity) = NaN}</li>
     * <li>{@code pow(+0.0, (+anything except 0, NaN)) = +0.0}</li>
     * <li>{@code pow(-0.0, (+anything except 0, NaN, odd integer)) = +0.0}</li>
     * <li>{@code pow(+0.0, (-anything except 0, NaN)) = +infinity}</li>
     * <li>{@code pow(-0.0, (-anything except 0, NAN, odd integer))} {@code =}
     * {@code +infinity}</li>
     * <li>{@code pow(-0.0, (odd integer)) = -pow( +0 , (odd integer) )}</li>
     * <li>{@code pow(+infinity, (+anything except 0, NaN)) = +infinity}</li>
     * <li>{@code pow(+infinity, (-anything except 0, NaN)) = +0.0}</li>
     * <li>{@code pow(-infinity, (anything)) = -pow(0, (-anything))}</li>
     * <li>{@code pow((-anything), (integer))} {@code =} {@code
     * pow(-1,(integer))*pow(+anything,integer) }</li>
     * <li>{@code pow((-anything except 0 and inf), (non-integer)) = NAN}</li>
     * </ul>
     *
     * @param x
     *            the base of the operation.
     * @param y
     *            the exponent of the operation.
     * @return {@code x} to the power of {@code y}.
     */
    static CARAPI_(Double) Pow(
        /* [in] */ Double x,
        /* [in] */ Double y);

    /**
     * Returns the Double conversion of the result of rounding the argument to
     * an integer. Tie breaks are rounded towards even.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code rint(+0.0) = +0.0}</li>
     * <li>{@code rint(-0.0) = -0.0}</li>
     * <li>{@code rint(+infinity) = +infinity}</li>
     * <li>{@code rint(-infinity) = -infinity}</li>
     * <li>{@code rint(NaN) = NaN}</li>
     * </ul>
     *
     * @param d
     *            the value to be rounded.
     * @return the closest integer to the argument (as a Double).
     */
    static CARAPI_(Double) Rint(
        /* [in] */ Double d);

    /**
     * Returns the result of rounding the argument to an integer. The result is
     * equivalent to {@code (Int64) Math.floor(d+0.5)}.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code round(+0.0) = +0.0}</li>
     * <li>{@code round(-0.0) = +0.0}</li>
     * <li>{@code round((anything > Long.MAX_VALUE) = Long.MAX_VALUE}</li>
     * <li>{@code round((anything < Long.MIN_VALUE) = Long.MIN_VALUE}</li>
     * <li>{@code round(+infinity) = Long.MAX_VALUE}</li>
     * <li>{@code round(-infinity) = Long.MIN_VALUE}</li>
     * <li>{@code round(NaN) = +0.0}</li>
     * </ul>
     *
     * @param d
     *            the value to be rounded.
     * @return the closest integer to the argument.
     */
    static CARAPI_(Int64) Round(
        /* [in] */ Double d);

    /**
     * Returns the result of rounding the argument to an integer. The result is
     * equivalent to {@code (Int32) Math.floor(f+0.5)}.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code round(+0.0) = +0.0}</li>
     * <li>{@code round(-0.0) = +0.0}</li>
     * <li>{@code round((anything > Integer.MAX_VALUE) = Integer.MAX_VALUE}</li>
     * <li>{@code round((anything < Integer.MIN_VALUE) = Integer.MIN_VALUE}</li>
     * <li>{@code round(+infinity) = Integer.MAX_VALUE}</li>
     * <li>{@code round(-infinity) = Integer.MIN_VALUE}</li>
     * <li>{@code round(NaN) = +0.0}</li>
     * </ul>
     *
     * @param f
     *            the value to be rounded.
     * @return the closest integer to the argument.
     */
    static CARAPI_(Int32) Round(
        /* [in] */ Float f);
    /**
     * Returns the signum function of the argument. If the argument is less than
     * zero, it returns -1.0. If the argument is greater than zero, 1.0 is
     * returned. If the argument is either positive or negative zero, the
     * argument is returned as result.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code signum(+0.0) = +0.0}</li>
     * <li>{@code signum(-0.0) = -0.0}</li>
     * <li>{@code signum(+infinity) = +1.0}</li>
     * <li>{@code signum(-infinity) = -1.0}</li>
     * <li>{@code signum(NaN) = NaN}</li>
     * </ul>
     *
     * @param d
     *            the value whose signum has to be computed.
     * @return the value of the signum function.
     */
    static CARAPI_(Double) Signum(
        /* [in] */ Double d);

    /**
     * Returns the signum function of the argument. If the argument is less than
     * zero, it returns -1.0. If the argument is greater than zero, 1.0 is
     * returned. If the argument is either positive or negative zero, the
     * argument is returned as result.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code signum(+0.0) = +0.0}</li>
     * <li>{@code signum(-0.0) = -0.0}</li>
     * <li>{@code signum(+infinity) = +1.0}</li>
     * <li>{@code signum(-infinity) = -1.0}</li>
     * <li>{@code signum(NaN) = NaN}</li>
     * </ul>
     *
     * @param f
     *            the value whose signum has to be computed.
     * @return the value of the signum function.
     */
    static CARAPI_(Float) Signum(
        /* [in] */ Float f);

    /**
     * Returns the closest Double approximation of the sine of the argument. The
     * returned result is within 1 ulp (unit in the last place) of the real
     * result.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code sin(+0.0) = +0.0}</li>
     * <li>{@code sin(-0.0) = -0.0}</li>
     * <li>{@code sin(+infinity) = NaN}</li>
     * <li>{@code sin(-infinity) = NaN}</li>
     * <li>{@code sin(NaN) = NaN}</li>
     * </ul>
     *
     * @param d
     *            the angle whose sin has to be computed, in radians.
     * @return the sine of the argument.
     */
    static CARAPI_(Double) Sin(
        /* [in] */ Double d);

    /**
     * Returns the closest Double approximation of the hyperbolic sine of the
     * argument. The returned result is within 2.5 ulps (units in the last
     * place) of the real result.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code sinh(+0.0) = +0.0}</li>
     * <li>{@code sinh(-0.0) = -0.0}</li>
     * <li>{@code sinh(+infinity) = +infinity}</li>
     * <li>{@code sinh(-infinity) = -infinity}</li>
     * <li>{@code sinh(NaN) = NaN}</li>
     * </ul>
     *
     * @param d
     *            the value whose hyperbolic sine has to be computed.
     * @return the hyperbolic sine of the argument.
     */
    static CARAPI_(Double) Sinh(
        /* [in] */ Double d);

    /**
     * Returns the closest Double approximation of the square root of the
     * argument.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code sqrt(+0.0) = +0.0}</li>
     * <li>{@code sqrt(-0.0) = -0.0}</li>
     * <li>{@code sqrt( (anything < 0) ) = NaN}</li>
     * <li>{@code sqrt(+infinity) = +infinity}</li>
     * <li>{@code sqrt(NaN) = NaN}</li>
     * </ul>
     */
    static CARAPI_(Double) Sqrt(
        /* [in] */ Double d);

    /**
     * Returns the closest Double approximation of the tangent of the argument.
     * The returned result is within 1 ulp (unit in the last place) of the real
     * result.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code tan(+0.0) = +0.0}</li>
     * <li>{@code tan(-0.0) = -0.0}</li>
     * <li>{@code tan(+infinity) = NaN}</li>
     * <li>{@code tan(-infinity) = NaN}</li>
     * <li>{@code tan(NaN) = NaN}</li>
     * </ul>
     *
     * @param d
     *            the angle whose tangent has to be computed, in radians.
     * @return the tangent of the argument.
     */
    static CARAPI_(Double) Tan(
        /* [in] */ Double d);

    /**
     * Returns the closest Double approximation of the hyperbolic tangent of the
     * argument. The absolute value is always less than 1. The returned result
     * is within 2.5 ulps (units in the last place) of the real result. If the
     * real result is within 0.5ulp of 1 or -1, it should return exactly +1 or
     * -1.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code tanh(+0.0) = +0.0}</li>
     * <li>{@code tanh(-0.0) = -0.0}</li>
     * <li>{@code tanh(+infinity) = +1.0}</li>
     * <li>{@code tanh(-infinity) = -1.0}</li>
     * <li>{@code tanh(NaN) = NaN}</li>
     * </ul>
     *
     * @param d
     *            the value whose hyperbolic tangent has to be computed.
     * @return the hyperbolic tangent of the argument.
     */
    static CARAPI_(Double) Tanh(
        /* [in] */ Double d);

    /**
     * Returns a pseudo-random Double {@code n}, where {@code n >= 0.0 && n < 1.0}.
     * This method reuses a single instance of {@link java.util.Random}.
     * This method is thread-safe because access to the {@code Random} is synchronized,
     * but this harms scalability. Applications may find a performance benefit from
     * allocating a {@code Random} for each of their threads.
     *
     * @return a pseudo-random number.
     */
    static Double Random();

    /**
     * Returns the measure in radians of the supplied degree angle. The result
     * is {@code angdeg / 180 * pi}.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code toRadians(+0.0) = +0.0}</li>
     * <li>{@code toRadians(-0.0) = -0.0}</li>
     * <li>{@code toRadians(+infinity) = +infinity}</li>
     * <li>{@code toRadians(-infinity) = -infinity}</li>
     * <li>{@code toRadians(NaN) = NaN}</li>
     * </ul>
     *
     * @param angdeg
     *            an angle in degrees.
     * @return the radian measure of the angle.
     */
    static CARAPI_(Double) ToRadians(
        /* [in] */ Double angdeg);

    /**
     * Returns the measure in degrees of the supplied radian angle. The result
     * is {@code angrad * 180 / pi}.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code toDegrees(+0.0) = +0.0}</li>
     * <li>{@code toDegrees(-0.0) = -0.0}</li>
     * <li>{@code toDegrees(+infinity) = +infinity}</li>
     * <li>{@code toDegrees(-infinity) = -infinity}</li>
     * <li>{@code toDegrees(NaN) = NaN}</li>
     * </ul>
     *
     * @param angrad
     *            an angle in radians.
     * @return the degree measure of the angle.
     */
    static CARAPI_(Double) ToDegrees(
        /* [in] */ Double angrad);

    /**
     * Returns the argument's ulp (unit in the last place). The size of a ulp of
     * a Double value is the positive distance between this value and the Double
     * value next larger in magnitude. For non-NaN {@code x}, {@code ulp(-x) ==
     * ulp(x)}.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code ulp(+0.0) = Double.MIN_VALUE}</li>
     * <li>{@code ulp(-0.0) = Double.MIN_VALUE}</li>
     * <li>{@code ulp(+infinity) = infinity}</li>
     * <li>{@code ulp(-infinity) = infinity}</li>
     * <li>{@code ulp(NaN) = NaN}</li>
     * </ul>
     *
     * @param d
     *            the floating-point value to compute ulp of.
     * @return the size of a ulp of the argument.
     */
    static CARAPI_(Double) Ulp(
        /* [in] */ Double d);

    /**
     * Returns the argument's ulp (unit in the last place). The size of a ulp of
     * a Float value is the positive distance between this value and the Float
     * value next larger in magnitude. For non-NaN {@code x}, {@code ulp(-x) ==
     * ulp(x)}.
     * <p>
     * Special cases:
     * <ul>
     * <li>{@code ulp(+0.0) = Float.MIN_VALUE}</li>
     * <li>{@code ulp(-0.0) = Float.MIN_VALUE}</li>
     * <li>{@code ulp(+infinity) = infinity}</li>
     * <li>{@code ulp(-infinity) = infinity}</li>
     * <li>{@code ulp(NaN) = NaN}</li>
     * </ul>
     *
     * @param f
     *            the floating-point value to compute ulp of.
     * @return the size of a ulp of the argument.
     */
    static CARAPI_(Float) Ulp(
        /* [in] */ Float f);

    /**
     * Returns a Double with the given magnitude and the sign of {@code sign}.
     * If {@code sign} is NaN, the sign of the result is arbitrary.
     * If you need a determinate sign in such cases, use {@code StrictMath.copySign}.
     * @since 1.6
     */
    static CARAPI_(Double) CopySign(
        /* [in] */ Double magnitude,
        /* [in] */ Double sign);

    /**
     * Returns a Float with the given magnitude and the sign of {@code sign}.
     * If {@code sign} is NaN, the sign of the result is arbitrary.
     * If you need a determinate sign in such cases, use {@code StrictMath.copySign}.
     * @since 1.6
     */
    static CARAPI_(Float) CopySign(
        /* [in] */ Float magnitude,
        /* [in] */ Float sign);

    /**
     * Returns the unbiased base-2 exponent of Float {@code f}.
     * @since 1.6
     */
    static CARAPI_(Int32) GetExponent(
        /* [in] */ Float f);

    /**
     * Returns the unbiased base-2 exponent of Double {@code d}.
     * @since 1.6
     */
    static CARAPI_(Int32) GetExponent(
        /* [in] */ Double d);

    /**
     * Returns the next Double after {@code start} in the given {@code direction}.
     * @since 1.6
     */
    static CARAPI_(Double) NextAfter(
        /* [in] */ Double start,
        /* [in] */ Double direction);

    /**
     * Returns the next Float after {@code start} in the given {@code direction}.
     * @since 1.6
     */
    static CARAPI_(Float) NextAfter(
        /* [in] */ Float start,
        /* [in] */ Double direction);

    /**
     * Returns the next Double larger than {@code d}.
     * @since 1.6
     */
    static CARAPI_(Double) NextUp(
        /* [in] */ Double d);

    /**
     * Returns the next Float larger than {@code f}.
     * @since 1.6
     */
    static CARAPI_(Float) NextUp(
        /* [in] */ Float f);

    /**
     * Returns {@code d} * 2^{@code scaleFactor}. The result may be rounded.
     * @since 1.6
     */
    static CARAPI_(Double) Scalb(
        /* [in] */ Double d,
        /* [in] */ Int32 scaleFactor);

    /**
     * Returns {@code d} * 2^{@code scaleFactor}. The result may be rounded.
     * @since 1.6
     */
    static CARAPI_(Float) Scalb(
        /* [in] */ Float d,
        /* [in] */ Int32 scaleFactor);

private:

    ECO_LOCAL static CARAPI_(Double) NativeNextAfter(
        /* [in] */ Double x,
        /* [in] */ Double y);

    // Shifts integer bits as Float, if the digits is positive, left-shift; if
    // not, shift to right and calculate its carry.
    ECO_LOCAL static CARAPI_(Int32) ShiftInt32Bits(
        /* [in] */ Int32 bits,
        /* [in] */ Int32 digits);

    // Shifts Int64 bits as Double, if the digits is positive, left-shift; if
    // not, shift to right and calculate its carry.
    ECO_LOCAL static CARAPI_(Int64) ShiftInt64Bits(
        /* [in] */ Int64 bits,
        /* [in] */ Int64 digits);

private:
    ECO_LOCAL StrictMath();
    ECO_LOCAL StrictMath(const StrictMath&);
};

} // namespace Core
} // namespace Elastos

#endif //__ELASTOS_CORE_STRICT_MATH_H__
