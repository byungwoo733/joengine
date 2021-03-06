/*
** Jo Sega Saturn Engine
** Copyright (c) 2012-2017, Johannes Fetz (johannesfetz@gmail.com)
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are met:
**     * Redistributions of source code must retain the above copyright
**       notice, this list of conditions and the following disclaimer.
**     * Redistributions in binary form must reproduce the above copyright
**       notice, this list of conditions and the following disclaimer in the
**       documentation and/or other materials provided with the distribution.
**     * Neither the name of the Johannes Fetz nor the
**       names of its contributors may be used to endorse or promote products
**       derived from this software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
** ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
** DISCLAIMED. IN NO EVENT SHALL Johannes Fetz BE LIABLE FOR ANY
** DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
** (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
** LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
** ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
/** @file math.h
 *  @author Johannes Fetz
 *
 *  @brief Jo Engine Math tools
 *  @bug Possible issue with jo_sin() and jo_cos() with some angle.
 */

#ifndef __JO_MATH_H__
# define __JO_MATH_H__

#ifdef JO_COMPILE_WITH_SINUS_TABLE

/** @brief Sinus lookup table (internal engine usage) use jo_sin() instead
 *  @warning MC Hammer: don't touch this
 */
extern int JoSinLookupTable[360];

#endif

/** @brief Cosinus lookup table (internal engine usage) use jo_cos() instead
 *  @warning MC Hammer: don't touch this
 */
extern int JoCosLookupTable[360];

/** @brief Set a variable to zero
 *  @remark faster than X = 0
 *  @param X Variable name
 */
# define JO_ZERO(X)					X ^= X
/** @brief Fixed floating point value for 0 */
# define JO_FIXED_0					(0)
/** @brief Fixed floating point value for 1 */
# define JO_FIXED_1					(65536)
/** @brief Fixed floating point value for 120 */
# define JO_FIXED_120				(7864320)
/** @brief Fixed floating point value for 150 */
# define JO_FIXED_150				(9830400)

/** @brief Float minimum positive value */
# define JO_FLOAT_EPSILON           (0.00001f)

/** @brief PI value */
# define JO_PI                      (3.1415927)

/** @brief PI/2 value */
# define JO_PI_2                    (1.5707963)

/** @brief Multiply a variable by 2
 *  @remark faster than X * 2
 *  @param X Variable name
 */
# define JO_MULT_BY_2(X)			((X) << 1)
/** @brief Multiply a variable by 4
 *  @remark faster than X * 4
 *  @param X Variable name
 */
# define JO_MULT_BY_4(X)			((X) << 2)
/** @brief Multiply a variable by 8
 *  @remark faster than X * 8
 *  @param X Variable name
 */
# define JO_MULT_BY_8(X)			((X) << 3)
/** @brief Multiply a variable by 16
 *  @remark faster than X * 16
 *  @param X Variable name
 */
# define JO_MULT_BY_16(X)			((X) << 4)
/** @brief Multiply a variable by 32
 *  @remark faster than X * 32
 *  @param X Variable name
 */
# define JO_MULT_BY_32(X)			((X) << 5)

/** @brief Multiply a variable by 256
 *  @remark faster than X * 256
 *  @param X Variable name
 */
# define JO_MULT_BY_256(X)			((X) << 8)

/** @brief Multiply a variable by 1024
 *  @remark faster than X * 1024
 *  @param X Variable name
 */
# define JO_MULT_BY_1024(X)			((X) << 10)

/** @brief Multiply a variable by 32768
 *  @remark faster than X * 32768
 *  @param X Variable name
 */
# define JO_MULT_BY_32768(X)			((X) << 15)

/** @brief Multiply a variable by 65536
 *  @remark faster than X * 65536
 *  @param X Variable name
 */
# define JO_MULT_BY_65536(X)			((X) << 16)

/** @brief Devide a variable by 2
 *  @remark faster than X / 2
 *  @param X Variable name
 */
# define JO_DIV_BY_2(X)				((X) >> 1)
/** @brief Devide a variable by 4
 *  @remark faster than X / 4
 *  @param X Variable name
 */
# define JO_DIV_BY_4(X)				((X) >> 2)
/** @brief Devide a variable by 8
 *  @remark faster than X / 8
 *  @param X Variable name
 */
# define JO_DIV_BY_8(X)				((X) >> 3)
/** @brief Devide a variable by 16
 *  @remark faster than X / 16
 *  @param X Variable name
 */
# define JO_DIV_BY_16(X)			((X) >> 4)
/** @brief Devide a variable by 32
 *  @remark faster than X / 32
 *  @param X Variable name
 */
# define JO_DIV_BY_32(X)			((X) >> 5)
/** @brief Devide a variable by 1024
 *  @remark faster than X / 1024
 *  @param X Variable name
 */
# define JO_DIV_BY_1024(X)			((X) >> 10)

/** @brief Devide a variable by 32768
 *  @remark faster than X / 32768
 *  @param X Variable name
 */
# define JO_DIV_BY_32768(X)			((X) >> 15)

/** @brief Devide a variable by 65536
 *  @remark faster than X / 65536
 *  @param X Variable name
 */
# define JO_DIV_BY_65536(X)			((X) >> 16)

/** @brief Get the absolute value of X
 *  @param X Variable name
 */
# define JO_ABS(X)                  ((X) < 0 ? -(X) : (X))

/** @brief Get the absolute value of X
 *  @param X Variable name
 */
# define JO_FABS(X)                  ((X) < 0.0f ? -(X) : (X))

/** @brief Get the smaller value between A and B
 *  @param A First operand
 *  @param B Second operand
 */
# define JO_MIN(A, B)               (((A) < (B)) ? (A) : (B))

/** @brief Get the bigger value between A and B
 *  @param A First operand
 *  @param B Second operand
 */
# define JO_MAX(A, B)               (((A) > (B)) ? (A) : (B))

/** @brief Change the sign of X
 *  @param X Variable name
 */
# define JO_CHANGE_SIGN(X)          (-(X))

/** @brief Check if A and B is nearly the same value
 *  @param A First operand
 *  @param B Second operand
 */
# define JO_FLOAT_NEARLY_EQUALS(A, B)     ((A) <= ((B) + JO_FLOAT_EPSILON) && (A) >= ((B) - JO_FLOAT_EPSILON))

/** @brief Check if A nearly equals zero
 *  @param A operand
 */
# define JO_IS_FLOAT_NULL(A)              ((A) <= JO_FLOAT_EPSILON && (A) >= (-JO_FLOAT_EPSILON))

/** @brief Convert radians to degrees
 *  @param A operand
 */
# define JO_RAD_TO_DEG(A)                  (180.0 * (A) / JO_PI)

/** @brief Convert degrees to radians
 *  @param A operand
 */
# define JO_DEG_TO_RAD(A)                  (JO_PI * (A) / 180.0)

/** @brief Check if A is odd
 *  @param A operand
 */
# define JO_IS_ODD(A)                       ((A) & 1)

/** @brief Swap A and B values
 *  @param A operand
 *  @param B operand
 */
# define JO_SWAP(A, B)                      { (A) = (A) ^ (B); (B) = (A) ^ (B); (A) = (A) ^ (B); }

/** @brief Compute percent (100 / TOTAL * (TOTAL - FREE))
 *  @param TOTAL Total
 *  @param FREE Free
 */
# define JO_PERCENT_USED(TOTAL, FREE)       (int)(100.0f / (float)(TOTAL) * (float)((TOTAL) - (FREE)))

/** @brief Square computation (x�)
 *  @param A operand
 */
# define JO_SQUARE(A)                       ((A) * (A))

/** @brief Convert float to jo engine fixed (avoid usage of GCC Soft Float)
 *  @param x Float to convert
 *  @return Fixed value (int)(x * 32768.0f)
 *  @remarks result and point parameters can be the same pointer
 */
static __jo_force_inline int    jo_float2fixed(const float x)
{
    jo_IEEE754                  ieee754;

    ieee754.f = x;
    if (!ieee754.field.exponent)
        return 0;
    if (ieee754.field.sign)
        return -((ieee754.field.mantissa | 0x800000) >> (135 - ieee754.field.exponent));
    return ((ieee754.field.mantissa | 0x800000) >> (135 - ieee754.field.exponent));
}

/** @brief Check if float almost equals 0;
 *  @param f floating point number
 *  @return true if the float almost equals 0 otherwise false
 */
static  __jo_force_inline bool	jo_is_float_equals_zero(float f)
{
    return (JO_ABS(f) < 0.00000001f);
}

/** @brief Fast method to get if two square intersects (HitBox processing)
 *  @param x1 Horizontal position of the first square
 *  @param y1 Vertical position of the first square
 *  @param w1 Width of the first square
 *  @param h1 Height of the first square
 *  @param x2 Horizontal position of the second square
 *  @param y2 Vertical position of the second square
 *  @param w2 Width of the second square
 *  @param h2 Height of the second square
 *  @return true if squares collides otherwise false
 */
static  __jo_force_inline bool	jo_square_intersect(const int x1, const int y1, const int w1, const int h1,
        const int x2, const int y2, const int w2, const int h2)
{
    return ((x1 < x2 + w2) && (x2 < x1 + w1)) && ((y1 < y2 + h2) && (y2 < y1 + h1));
}

/** @brief Get a random number
 *  @param max maximum value
 *  @return 1 to max
 */
int                             jo_random(int max);

/** @brief Get a random number with a specific multiple
 *  @param max maximum value
 *  @param multiple multiple
 *  @return A multiple between 1 to max
 */
static  __jo_force_inline int	jo_random_using_multiple(int max, int multiple)
{
    return (jo_random(max) / multiple) * multiple;
}

/** @brief Fast square root
 *  @param value Value
 *  @return Sqrt(value)
 */
unsigned int                    jo_sqrt(unsigned int value);

/** @brief Fast Square root using floating number
 *  @param value Value
 *  @return Sqrt(value)
 *  @warning Not precise
 */
static  __jo_force_inline float jo_sqrtf(float value)
{
    unsigned int i = *(unsigned int*)(void *)&value;
    i += 127 << 23;
    i >>= 1;
    return *(float*)(void *)&i;
}

/*
** COSINUS COMPUTATION
*/

/** @brief Fast cosinus computation
 *  @param angle Angle in degree
 *  @return Cos(angle) * 32768
 */
static  __jo_force_inline int	jo_cos(const int angle)
{
    return (JoCosLookupTable[JO_ABS(angle) % 360]);
}

/** @brief Cosinus computation
 *  @param angle Angle in degree
 *  @return Cos(angle) using floating number (slow)
 *  @warning slower than jo_cos() because it use floating point
 */
static  __jo_force_inline float	jo_cosf(const int angle)
{
    return (jo_cos(angle) / 32768.0f);
}

/** @brief Cosinus computation
 *  @param angle Angle in radian
 *  @return Cos(angle) * 32768
 *  @warning slower than jo_cos() because it use floating point
 */
static  __jo_force_inline int	jo_cos_rad(const float angle)
{
    return jo_cos((int)(JO_RAD_TO_DEG(angle)));
}

/** @brief Cosinus computation
 *  @param angle Angle in radian
 *  @return Cos(angle) using floating number (slow)
 *  @warning slower than jo_cos_rad() because it use floating point
 */
static  __jo_force_inline float	jo_cos_radf(const float angle)
{
    return jo_cos_rad(angle) / 32768.0f;
}

/** @brief Fast cosinus multiplication
 *  @param angle Angle in degree
 *  @param value Value
 *  @return value * Cos(angle)
 */
static  __jo_force_inline int	jo_cos_mult(const int value, const int angle)
{
    return JO_DIV_BY_32768(value * jo_cos(angle));
}

/** @brief Fast cosinus multiplication
 *  @param angle Angle in degree
 *  @param value Value
 *  @return value * Cos(angle) using floating number (slow)
 */
static  __jo_force_inline float	jo_cosf_mult(const float value, const int angle)
{
    return value * jo_cosf(angle);
}

/*
** SINUS COMPUTATION
*/

/** @brief Fast sinus computation
 *  @param angle Angle in degree
 *  @return Sin(angle) * 32768
 */
static  __jo_force_inline int	jo_sin(const int angle)
{
#ifdef JO_COMPILE_WITH_SINUS_TABLE
    return (angle >= 0 ? JoSinLookupTable[JO_ABS(angle) % 360] : -JoSinLookupTable[JO_ABS(angle) % 360]);
#else
    return (jo_cos(angle - 90));
#endif
}

/** @brief Sinus computation
 *  @param angle Angle in degree
 *  @return Sin(angle) using floating number (slow)
 *  @warning slower than jo_sin() because it use floating point
 */
static  __jo_force_inline float	jo_sinf(const int angle)
{
    return (jo_sin(angle) / 32768.0f);
}

/** @brief Sinus computation
 *  @param angle Angle in radian
 *  @return Sin(angle) * 32768
 *  @warning slower than jo_sin() because it use floating point
 */
static  __jo_force_inline int	jo_sin_rad(const float angle)
{
    return jo_sin((int)(JO_RAD_TO_DEG(angle)));
}

/** @brief Sinus computation
 *  @param angle Angle in radian
 *  @return Sin(angle) using floating number (slow)
 *  @warning slower than jo_sin_rad() because it use floating point
 */
static  __jo_force_inline float	jo_sin_radf(const float angle)
{
    return (jo_sin_rad(angle) / 32768.0f);
}

/** @brief Fast sinus multiplication
 *  @param angle Angle in degree
 *  @param value Value
 *  @return value * Sin(angle)
 */
static  __jo_force_inline int	jo_sin_mult(const int value, const int angle)
{
    return JO_DIV_BY_32768(value * jo_sin(angle));
}

/** @brief Fast sinus multiplication
 *  @param angle Angle in degree
 *  @param value Value
 *  @return value * Sin(angle) using floating number (slow)
 */
static  __jo_force_inline float	jo_sinf_mult(const float value, const int angle)
{
    return value * jo_sinf(angle);
}

/*
** TAN
*/

/** @brief Fast tangent computation
 *  @param angle Angle in degree
 *  @return Tan(angle) * 32768
 */
static __jo_force_inline int    jo_tan(const int angle)
{
    return (jo_sin(angle) / jo_cos(angle));
}

/** @brief Tangent computation
 *  @param angle Angle in degree
 *  @return Tan(angle) using floating number (slow)
 *  @warning slower than jo_tan() because it use floating point
 */
static __jo_force_inline float    jo_tanf(const float angle)
{
    return (jo_sinf(angle) / jo_cosf(angle));
}

/** @brief Tangent computation
 *  @param angle Angle in radian
 *  @return Tan(angle) * 32768
 *  @warning slower than jo_tan() because it use floating point
 */
static __jo_force_inline int    jo_tan_rad(const float angle)
{
    return (jo_sin_rad(angle) / jo_cos_rad(angle));
}

/** @brief Tangent computation
 *  @param angle Angle in radian
 *  @return Tan(angle) using floating number (slow)
 *  @warning slower than jo_tan_rad() because it use floating point
 */
static __jo_force_inline float  jo_tan_radf(const float angle)
{
    return (jo_sin_radf(angle) / jo_cos_radf(angle));
}

/*
** ACOS
*/

/** @brief Fast Arc Cosinus computation
 *  @param angle Angle in radian
 *  @return Acos(angle) using floating number
 */
static  __jo_force_inline float	jo_acos_radf(const float angle)
{
    return (3.14159f - 1.57079f * angle);
}

/*
** ATAN2
*/

/** @brief Fast ATAN2 computation in radian
 *  @param y First value
 *  @param x Second value
 *  @warning Y is the first operand (like Math.Atan2() in C#)
 *  @return ATAN2(Y, X)
 */
float                           jo_atan2f_rad(const float y, const float x);

/** @brief Fast ATAN2 computation in degree
 *  @param y First value
 *  @param x Second value
 *  @warning Y is the first operand (like Math.Atan2() in C#)
 *  @return ATAN2(Y, X)
 */
static __jo_force_inline int    jo_atan2f(const float y, const float x)
{
    return (int)JO_RAD_TO_DEG(jo_atan2f_rad(y, x));
}

/*
** 3D VECTOR
*/

/** @brief Add 2 vectors (using floating numbers)
 *  @param a First vector
 *  @param b Second vector
 *  @param result output vector
 *  @remarks You can pass a or b address for result parameter
 */
static __jo_force_inline void jo_vectorf_add(const jo_vectorf * const a, const jo_vectorf * const b, jo_vectorf * const result)
{
    result->x = a->x + b->x;
    result->y = a->y + b->y;
    result->z = a->z + b->z;
}

/** @brief Add value to vector (using floating numbers)
 *  @param a Vector
 *  @param s Constant
 *  @param result output vector
 *  @remarks You can pass a address for result parameter
 */
static __jo_force_inline void jo_vectorf_adds(const jo_vectorf * const a, const float s, jo_vectorf * const result)
{
    result->x = a->x + s;
    result->y = a->y + s;
    result->z = a->z + s;
}

/** @brief Subtract 2 vectors (using floating numbers)
 *  @param a First vector
 *  @param b Second vector
 *  @param result output vector
 *  @remarks You can pass a or b address for result parameter
 */
static __jo_force_inline void jo_vectorf_sub(const jo_vectorf * const a, const jo_vectorf * const b, jo_vectorf * const result)
{
    result->x = a->x - b->x;
    result->y = a->y - b->y;
    result->z = a->z - b->z;
}

/** @brief Subtract value to vector (using floating numbers)
 *  @param a Vector
 *  @param s Constant
 *  @param result output vector
 *  @remarks You can pass a address for result parameter
 */
static __jo_force_inline void jo_vectorf_subs(const jo_vectorf * const a, const float s, jo_vectorf * const result)
{
    result->x = a->x - s;
    result->y = a->y - s;
    result->z = a->z - s;
}

/** @brief Multiply 2 vectors (using floating numbers)
 *  @param a First vector
 *  @param b Second vector
 *  @param result output vector
 *  @remarks You can pass a or b address for result parameter
 */
static __jo_force_inline void jo_vectorf_mul(const jo_vectorf * const a, const jo_vectorf * const b, jo_vectorf * const result)
{
    result->x = a->x * b->x;
    result->y = a->y * b->y;
    result->z = a->z * b->z;
}

/** @brief Multiply value to vector (using floating numbers)
 *  @param a Vector
 *  @param s Constant
 *  @param result output vector
 *  @remarks You can pass a address for result parameter
 */
static __jo_force_inline void jo_vectorf_muls(const jo_vectorf * const a, const float s, jo_vectorf * const result)
{
    result->x = a->x * s;
    result->y = a->y * s;
    result->z = a->z * s;
}

/** @brief Divide 2 vectors (using floating numbers)
 *  @param a First vector
 *  @param b Second vector
 *  @param result output vector
 *  @remarks You can pass a or b address for result parameter
 */
static __jo_force_inline void jo_vectorf_div(const jo_vectorf * const a, const jo_vectorf * const b, jo_vectorf * const result)
{
    result->x = a->x / b->x;
    result->y = a->y / b->y;
    result->z = a->z / b->z;
}

/** @brief Divide value to vector (using floating numbers)
 *  @param a Vector
 *  @param s Constant
 *  @param result output vector
 *  @remarks You can pass a address for result parameter
 */
static __jo_force_inline void jo_vectorf_divs(const jo_vectorf * const a, const float s, jo_vectorf * const result)
{
    result->x = a->x / s;
    result->y = a->y / s;
    result->z = a->z / s;
}

/** @brief Get the length of a vector (using floating numbers)
 *  @param a Vector
 *  @return Vector length
 */
static __jo_force_inline float  jo_vectorf_length(const jo_vectorf * const a)
{
    return (jo_sqrtf(JO_SQUARE(a->x) + JO_SQUARE(a->y) + JO_SQUARE(a->z)));
}

/** @brief Get the dot product of 2 vectors (using floating numbers)
 *  @param a First vector
 *  @param b Second vector
 *  @return a.b
 */
static __jo_force_inline float  jo_vectorf_dot(const jo_vectorf * const a, const jo_vectorf * const b)
{
    return (a->x * b->x + a->y * b->y + a->z * b->z);
}

/** @brief Normalize a vector (using floating numbers)
 *  @param a Vector
 *  @param result output vector
 *  @remarks You can pass a address for result parameter
 */
static __jo_force_inline void jo_vectorf_normalize(const jo_vectorf * const a, jo_vectorf * const result)
{
    float len = jo_vectorf_length(a);
    if (len > 0)
    {
        result->x = a->x / len;
        result->y = a->y / len;
        result->z = a->z / len;
    }
    else
    {
        result->x = 0;
        result->y = 0;
        result->z = 0;
    }
}

/** @brief Compute projection vector (using floating numbers)
 *  @param v Vector
 *  @param onto Vector
 *  @param result output vector
 */
static __jo_force_inline void jo_vectorf_proj(const jo_vectorf * const v, const jo_vectorf * const onto, jo_vectorf * const result)
{
    jo_vectorf_muls(onto, jo_vectorf_dot(v, onto) / jo_vectorf_dot(onto, onto), result);
}

/** @brief Cross 2 vectors (using floating numbers)
 *  @param a First vector
 *  @param b Second vector
 *  @param result output vector
 *  @warning Don't pass a or b address in result parameter
 */
static __jo_force_inline void jo_vectorf_cross(const jo_vectorf * const a, const jo_vectorf * const b, jo_vectorf * const result)
{
    result->x = a->y * b->z - a->z * b->y;
    result->y = a->z * b->x - a->x * b->z;
    result->z = a->x * b->y - a->y * b->x;
}

/** @brief Get the angle between 2 vectors (using floating numbers)
 *  @param a First vector
 *  @param b Second vector
 *  @return Angle in radian using floating numbers
 */
static __jo_force_inline float jo_vectorf_angle_between_radf(const jo_vectorf * const a, const jo_vectorf * const b)
{
    return jo_acos_radf(jo_vectorf_dot(a, b) / (jo_vectorf_length(a) * jo_vectorf_length(b)));
}

/*
** 3D MATRIX 4x4
*/

/** @brief Creates the identity matrix (using floating numbers)
 *  @param result Result matrix
 */
static __jo_force_inline void   jo_matrixf_identity(jo_matrixf * const result)
{
    register int                i;

    for (i = 1; i < 15; ++i)
        result->table[i] = 0;
    result->m00 = 1;
    result->m11 = 1;
    result->m22 = 1;
    result->m33 = 1;
}

/** @brief Creates translation matrix (using floating numbers)
 *  @param offset Offset vector
 *  @param result Result matrix
 */
static __jo_force_inline void jo_matrixf_translation(const jo_vectorf * const offset, jo_matrixf * const result)
{
    jo_matrixf_identity(result);
    result->m30 = offset->x;
    result->m31 = offset->y;
    result->m32 = offset->z;
}

/** @brief Creates scaling matrix (using floating numbers)
 *  @param scale Scale vector
 *  @param result Result matrix
 */
static __jo_force_inline void jo_matrixf_scaling(const jo_vectorf * const scale, jo_matrixf * const result)
{
    jo_matrixf_identity(result);
    result->m00 = scale->x;
    result->m11 = scale->y;
    result->m22 = scale->z;
}

/** @brief Creates rotating matrix (X axis) (using floating numbers)
 *  @param angle_in_rad Angle in radiant
 *  @param result Result matrix
 */
static __jo_force_inline void jo_matrixf_rotation_x_rad(const float angle_in_rad, jo_matrixf * const result)
{
    jo_matrixf_identity(result);
    result->m11 = jo_cos_radf(angle_in_rad);
    result->m12 = jo_sin_radf(angle_in_rad);
    result->m21 = -result->m12;
    result->m22 = result->m11;
}

/** @brief Creates rotating matrix (Y axis) (using floating numbers)
 *  @param angle_in_rad Angle in radiant
 *  @param result Result matrix
 */
static __jo_force_inline void jo_matrixf_rotation_y_rad(const float angle_in_rad, jo_matrixf * const result)
{
    jo_matrixf_identity(result);
    result->m00 = jo_cos_radf(angle_in_rad);
    result->m20 = jo_sin_radf(angle_in_rad);
    result->m02 = -result->m20;
    result->m22 = result->m00;
}

/** @brief Creates rotating matrix (Z axis) (using floating numbers)
 *  @param angle_in_rad Angle in radiant
 *  @param result Result matrix
 */
static __jo_force_inline void jo_matrixf_rotation_z_rad(const float angle_in_rad, jo_matrixf * const result)
{
    jo_matrixf_identity(result);
    result->m00 = jo_cos_radf(angle_in_rad);
    result->m01 = jo_sin_radf(angle_in_rad);
    result->m10 = -result->m01;
    result->m11 = result->m00;
}

/** @brief Creates transpose matrix (using floating numbers)
 *  @param matrix Input matrix
 *  @param result Result matrix
 *  @warning matrix and result parameters must not be the same address
 */
static __jo_force_inline void jo_matrixf_transpose(const jo_matrixf * const matrix, jo_matrixf * const result)
{
    result->m00 = matrix->m00;
    result->m10 = matrix->m01;
    result->m20 = matrix->m02;
    result->m30 = matrix->m03;
    result->m01 = matrix->m10;
    result->m11 = matrix->m11;
    result->m21 = matrix->m12;
    result->m31 = matrix->m13;
    result->m02 = matrix->m20;
    result->m12 = matrix->m21;
    result->m22 = matrix->m22;
    result->m32 = matrix->m23;
    result->m03 = matrix->m30;
    result->m13 = matrix->m31;
    result->m23 = matrix->m32;
    result->m33 = matrix->m33;
}

/** @brief Multiply 2 matrix (using floating numbers)
 *  @param a First matrix
 *  @param b Second matrix
 *  @param result Result matrix
 *  @warning a, b and result parameters must not be the same address
 */
static __jo_force_inline void   jo_matrixf_mul(const jo_matrixf * const a, const jo_matrixf * const b, jo_matrixf * const result)
{
    register int                i;
    register int                j;
    register int                k;
    register float              sum;

    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            sum = 0;
            for (k = 0; k < 4; ++k)
                sum += a->m[k][j] * b->m[i][k];
            result->m[i][j] = sum;
        }
    }
}

/** @brief Creates a matrix to rotate around an axis by a given angle in radiant (using floating numbers)
 *  @param angle_in_rad Angle in radiant
 *  @param axis Axis
 *  @param result Result matrix
 */
static __jo_force_inline void   jo_matrixf_rotation(const float angle_in_rad, const jo_vectorf * const axis, jo_matrixf * const result)
{
    jo_vectorf                   normalized_axis;

    jo_vectorf_normalize(axis, &normalized_axis);
    float c = jo_cos_radf(angle_in_rad);
    float s = jo_sin_radf(angle_in_rad);
    float a = 1 - c;
    jo_matrixf_identity(result);
    result->m00 = c + normalized_axis.x * normalized_axis.x * a;
    result->m10 = normalized_axis.x * normalized_axis.y * a - normalized_axis.z * s;
    result->m20 = normalized_axis.x * normalized_axis.z * a + normalized_axis.y * s;
    result->m01 = normalized_axis.y * normalized_axis.x * a + normalized_axis.z * s;
    result->m11 = c + normalized_axis.y * normalized_axis.y * a;
    result->m21 = normalized_axis.y * normalized_axis.z * a - normalized_axis.x * s;
    result->m02 = normalized_axis.z * normalized_axis.x * a - normalized_axis.y * s;
    result->m12 = normalized_axis.z * normalized_axis.y * a + normalized_axis.x * s;
    result->m22 = c + normalized_axis.z * normalized_axis.z * a;
}

/** @brief Creates an orthographic projection matrix (using floating numbers)
 *  @param left Left (Cube)
 *  @param right Right (Cube)
 *  @param bottom Bottom (Cube)
 *  @param top Top (Cube)
 *  @param back Back (Cube)
 *  @param front Front (Cube)
 *  @param result Result matrix
 */
static __jo_force_inline void jo_matrixf_ortho(const float left, const float right, const float bottom, const float top,
                                                   const float back, const float front, jo_matrixf * const result)
{
    jo_matrixf_identity(result);
    result->m00 = 2 / (right - left);
    result->m11 = 2 / (top - bottom);
    result->m22 = 2 / (back - front);
    result->m30 = -(right + left) / (right - left);
    result->m31 = -(top + bottom) / (top - bottom);
    result->m32 = -(back + front) / (back - front);
}

/** @brief Creates a perspective projection matrix for a camera (using floating numbers)
 *  @param vertical_field_of_view_in_deg Specifies the field of view angle, in degrees, in the y direction.
 *  @param aspect_ratio Specifies the aspect ratio that determines the field of view in the x direction. The aspect ratio is the ratio of x (width) to y (height).
 *  @param near_view_distance Specifies the distance from the viewer to the near clipping plane (always positive).
 *  @param far_view_distance Specifies the distance from the viewer to the far clipping plane (always positive).
 *  @param result Result matrix
 *  @remarks Similar to gluPerspective
 */
static __jo_force_inline void jo_matrixf_perspective(const float vertical_field_of_view_in_deg, const float aspect_ratio,
                                                    const float near_view_distance, const float far_view_distance, jo_matrixf * const result)
{
    jo_matrixf_identity(result);
    result->m11 = 1.0f / jo_tan_radf((vertical_field_of_view_in_deg / 180 * JO_PI) / 2.0f);
    result->m00 = result->m11 / aspect_ratio;
    result->m22 = (far_view_distance + near_view_distance) / (near_view_distance - far_view_distance);
    result->m32 = (2 * far_view_distance * near_view_distance) / (near_view_distance - far_view_distance);
    result->m23 = -1;
    result->m33 = 0;
}

/** @brief Builds a transformation matrix for a camera (using floating numbers)
 *  @param from Viewpoint
 *  @param to target
 *  @param up Defines the direction that's upwards for the camera
 *  @param result Result matrix
 */
static __jo_force_inline void   jo_matrixf_look_at(const jo_vectorf * const from, const jo_vectorf * const to,
                                                     const jo_vectorf * const up, jo_matrixf * const result)
{
    jo_vectorf                   tmp;
    jo_vectorf                   x;
    jo_vectorf                   y;
    jo_vectorf                   z;

    jo_vectorf_sub(to, from, &tmp);
    jo_vectorf_normalize(&tmp, &tmp);
    jo_vectorf_muls(&tmp, -1, &z);
    jo_vectorf_cross(up, &z, &tmp);
    jo_vectorf_normalize(&tmp, &x);
    jo_vectorf_cross(&z, &x, &y);

    jo_matrixf_identity(result);
    result->m00 = x.x;
    result->m10 = x.y;
    result->m20 = x.z;
    result->m30 = -jo_vectorf_dot(from, &x);
    result->m01 = y.x;
    result->m11 = y.y;
    result->m21 = y.z;
    result->m31 = -jo_vectorf_dot(from, &y);
    result->m02 = z.x;
    result->m12 = z.y;
    result->m22 = z.z;
    result->m33 = -jo_vectorf_dot(from, &z);
}

/** @brief Inverts an affine transformation matrix (using floating numbers)
 *  @param matrix Matrix
 *  @param result Result matrix
 */
static __jo_force_inline void jo_matrixf_invert_affine(const jo_matrixf * const matrix, jo_matrixf * const result)
{
    float c00 = matrix->m11 * matrix->m22 - matrix->m12 * matrix->m21;
    float c10 = -(matrix->m01 * matrix->m22 - matrix->m02 * matrix->m21);
    float c20 =   matrix->m01 * matrix->m12 - matrix->m02 * matrix->m11;
    float det = matrix->m00 * c00 + matrix->m10 * c10 + matrix->m20 * c20;
    jo_matrixf_identity(result);
    if (JO_FABS(det) < JO_FLOAT_EPSILON)
        return;
    float c01 = -(matrix->m10 * matrix->m22 - matrix->m12 * matrix->m20);
    float c11 = matrix->m00 * matrix->m22 - matrix->m02 * matrix->m20;
    float c21 = -(matrix->m00 * matrix->m12 - matrix->m02 * matrix->m10);
    float c02 = matrix->m10 * matrix->m21 - matrix->m11 * matrix->m20;
    float c12 = -(matrix->m00 * matrix->m21 - matrix->m01 * matrix->m20);
    float c22 = matrix->m00 * matrix->m11 - matrix->m01 * matrix->m10;
    float i00 = c00 / det;
    float i10 = c01 / det;
    float i20 = c02 / det;
    float i01 = c10 / det;
    float i11 = c11 / det;
    float i21 = c12 / det;
    float i02 = c20 / det;
    float i12 = c21 / det;
    float i22 = c22 / det;

    result->m00 = i00;
    result->m10 = i10;
    result->m20 = i20;
    result->m30 = -(i00 * matrix->m30 + i10 * matrix->m31 + i20 * matrix->m32);
    result->m01 = i01;
    result->m11 = i11;
    result->m21 = i21;
    result->m31 = -(i01 * matrix->m30 + i11 * matrix->m31 + i21 * matrix->m32);
    result->m02 = i02;
    result->m12 = i12;
    result->m22 = i22;
    result->m32 = -(i02 * matrix->m30 + i12 * matrix->m31 + i22 * matrix->m32);
}

/** @brief Multiplies a 4x4 matrix with a 3D vector representing a point in 3D space (using floating numbers)
 *  @param matrix Matrix
 *  @param position Position
 *  @param result Result matrix
 */
static __jo_force_inline void jo_matrixf_mul_pos(const jo_matrixf * const matrix, const jo_vectorf * const position,
                                                     jo_vectorf * const result)
{
    float w = matrix->m03 * position->x + matrix->m13 * position->y + matrix->m23 * position->z + matrix->m33;
    result->x = matrix->m00 * position->x + matrix->m10 * position->y + matrix->m20 * position->z + matrix->m30;
    result->y = matrix->m01 * position->x + matrix->m11 * position->y + matrix->m21 * position->z + matrix->m31;
    result->z = matrix->m02 * position->x + matrix->m12 * position->y + matrix->m22 * position->z + matrix->m32;
    if (w != 0 && w != 1)
    {
        result->x /= w;
        result->y /= w;
        result->z /= w;
    }
}

/** @brief Multiplies a 4x4 matrix with a 3D vector representing a direction in 3D space (using floating numbers)
 *  @param matrix Matrix
 *  @param direction Direction
 *  @param result Result matrix
 */
static __jo_force_inline void jo_matrixf_mul_dir(const jo_matrixf * const matrix, const jo_vectorf * const direction,
                                                     jo_vectorf * const result)
{
    float w = matrix->m03 * direction->x + matrix->m13 * direction->y + matrix->m23 * direction->z;
    result->x = matrix->m00 * direction->x + matrix->m10 * direction->y + matrix->m20 * direction->z;
    result->y = matrix->m01 * direction->x + matrix->m11 * direction->y + matrix->m21 * direction->z;
    result->z = matrix->m02 * direction->x + matrix->m12 * direction->y + matrix->m22 * direction->z;
    if (w != 0 && w != 1)
    {
        result->x /= w;
        result->y /= w;
        result->z /= w;
    }
}

/*
** MISC
*/

/** @brief Get the greatest common divisor
 *  @remarks PGCD in French
 *  @param a First value (> 0)
 *  @param b Second value (> 0)
 *  @return GCD(a, b)
 */
int     jo_gcd(int a, int b);

/** @brief Rotate a point on the plan with a specific origin
 *  @param point Point to rotate
 *  @param origin Rotation origin
 *  @param angle Angle in degrees
 *  @param result The new point coordinate
 *  @remarks result and point parameters can be the same pointer
 */
void            jo_planar_rotate(const jo_pos2D * const point, const jo_pos2D * const origin, const int angle, jo_pos2D * const result);

#endif /* !__JO_MATH_H__ */

/*
** END OF FILE
*/

