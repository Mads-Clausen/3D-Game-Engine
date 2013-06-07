/******************************************************************
 * <insert name>   :    Game Engine produced by Mads Clausen
 * www             :    http://anickyan.koding.com/ge
 *
 * Game engine using OpenGL 3.2 for hardware-accelerated
 * graphics, for the best performance.
 *
 * Copyright (c) Mads Clausen :: All Rights Reserved
 ******************************************************************/


#ifndef MAT4_INCLUDED
#define MAT4_INCLUDED

#define DEGTORAD 3.14159265359 / 180

#include "math/vec3.hpp"
#include "math/vec4.hpp"
#include "math/mat3.hpp"

namespace math
{
    template<typename _type>
    class mat4
    {
        private:
            _type _mat[16];

        public:
            mat4()
            {
                for(unsigned int i = 0; i < 16; ++i)
                    _mat[i] = 0;
            };

            mat4(vec4<_type> v0, vec4<_type> v1, vec4<_type> v2, vec4<_type> v3)
            {
                _mat[0] = v0.x; _mat[4] = v0.y; _mat[8]  = v0.z; _mat[12] = v0.w;
                _mat[1] = v1.x; _mat[5] = v1.y; _mat[9]  = v1.z; _mat[13] = v1.w;
                _mat[2] = v2.x; _mat[6] = v2.y; _mat[10] = v2.z; _mat[14] = v2.w;
                _mat[3] = v3.x; _mat[7] = v3.y; _mat[11] = v3.z; _mat[15] = v3.w;
            }

            mat4(_type x0, _type y0, _type z0, _type w0,
                 _type x1, _type y1, _type z1, _type w1,
                 _type x2, _type y2, _type z2, _type w2,
                 _type x3, _type y3, _type z3, _type w3)
            {
                _mat[0] = x0; _mat[4] = y0; _mat[8]  = z0; _mat[12] = w0;
                _mat[1] = x1; _mat[5] = y1; _mat[9]  = z1; _mat[13] = w1;
                _mat[2] = x2; _mat[6] = y2; _mat[10] = z2; _mat[14] = w2;
                _mat[3] = x3; _mat[7] = y3; _mat[11] = z3; _mat[15] = w3;
            }

            mat4(vec3<_type> v)
            {
                _mat[0] = v.x; _mat[4] = 0;   _mat[8]  = 0;   _mat[12] = 0;
                _mat[1] = 0;   _mat[5] = v.y; _mat[9]  = 0;   _mat[13] = 0;
                _mat[2] = 0;   _mat[6] = 0;   _mat[10] = v.z; _mat[14] = 0;
                _mat[3] = 0;   _mat[7] = 0;   _mat[11] = 0;   _mat[15] = 1;
            }

            mat4(vec4<_type> v)
            {
                _mat[0] = v.x; _mat[4] = 0;   _mat[8]  = 0;   _mat[12] = 0;
                _mat[1] = 0;   _mat[5] = v.y; _mat[9]  = 0;   _mat[13] = 0;
                _mat[2] = 0;   _mat[6] = 0;   _mat[10] = v.z; _mat[14] = 0;
                _mat[3] = 0;   _mat[7] = 0;   _mat[11] = 0;   _mat[15] = v.w;
            }

            mat4(_type scalar)
            {
                _mat[0] = scalar;   _mat[4] = 0;        _mat[8] = 0;        _mat[12] = 0;
                _mat[1] = 0;        _mat[5] = scalar;   _mat[9] = 0;        _mat[13] = 0;
                _mat[2] = 0;        _mat[6] = 0;        _mat[10] = scalar;  _mat[14] = 0;
                _mat[3] = 0;        _mat[7] = 0;        _mat[11] = 0;       _mat[15] = scalar;
            }

            mat4(mat3<_type> other)
            {
                _mat[0] = other[0]; _mat[4] = other[3];   _mat[8]  = other[6]; _mat[12] = 0;
                _mat[1] = other[1]; _mat[5] = other[4];   _mat[9]  = other[7]; _mat[13] = 0;
                _mat[2] = other[2]; _mat[6] = other[5];   _mat[10] = other[9]; _mat[14] = 0;
                _mat[3] = 0;        _mat[7] = 0;          _mat[11] = 0;        _mat[15] = 0;
            }

            inline _type &operator[](int i)               { return _mat[i]; }
            inline _type &operator()(int column, int row) { return _mat[4 * column + row]; }

            inline mat4<_type> operator+(_type other)
            {
                return mat4<_type>(_mat[0] + other, _mat[4] + other, _mat[8]  + other, _mat[12] + other,
                                   _mat[1] + other, _mat[5] + other, _mat[9]  + other, _mat[13] + other,
                                   _mat[2] + other, _mat[6] + other, _mat[10] + other, _mat[14] + other,
                                   _mat[3] + other, _mat[7] + other, _mat[11] + other, _mat[15] + other);
            }

            inline mat4<_type> operator-(_type other)
            {
                return mat4<_type>(_mat[0] - other, _mat[4] - other, _mat[8]  - other, _mat[12] - other,
                                   _mat[1] - other, _mat[5] - other, _mat[9]  - other, _mat[13] - other,
                                   _mat[2] - other, _mat[6] - other, _mat[10] - other, _mat[14] - other,
                                   _mat[3] - other, _mat[7] - other, _mat[11] - other, _mat[15] - other);
            }

            inline mat4<_type> operator*(_type other)
            {
                return mat4<_type>(_mat[0] * other, _mat[4] * other, _mat[8]  * other, _mat[12] * other,
                                   _mat[1] * other, _mat[5] * other, _mat[9]  * other, _mat[13] * other,
                                   _mat[2] * other, _mat[6] * other, _mat[10] * other, _mat[14] * other,
                                   _mat[3] * other, _mat[7] * other, _mat[11] * other, _mat[15] * other);
            }

            inline mat4<_type> operator/(_type other)
            {
                return mat4<_type>(_mat[0] / other, _mat[4] / other, _mat[8]  / other, _mat[12] / other,
                                   _mat[1] / other, _mat[5] / other, _mat[9]  / other, _mat[13] / other,
                                   _mat[2] / other, _mat[6] / other, _mat[10] / other, _mat[14] / other,
                                   _mat[3] / other, _mat[7] / other, _mat[11] / other, _mat[15] / other);
            }

            /****************************************************************/

            inline mat4<_type> operator+(vec4<_type> other)
            {
                return mat4<_type>(_mat[0] + other.x, _mat[4] + other.y, _mat[8]  + other.z, _mat[12] + other.w,
                                   _mat[1] + other.x, _mat[5] + other.y, _mat[9]  + other.z, _mat[13] + other.w,
                                   _mat[2] + other.x, _mat[6] + other.y, _mat[10] + other.z, _mat[14] + other.w,
                                   _mat[3] + other.x, _mat[7] + other.y, _mat[11] + other.z, _mat[15] + other.w);
            }

            inline mat4<_type> operator-(vec4<_type> other)
            {
                return mat4<_type>(_mat[0] - other.x, _mat[4] - other.y, _mat[8]  - other.z, _mat[12] - other.w,
                                   _mat[1] - other.x, _mat[5] - other.y, _mat[9]  - other.z, _mat[13] - other.w,
                                   _mat[2] - other.x, _mat[6] - other.y, _mat[10] - other.z, _mat[14] - other.w,
                                   _mat[3] - other.x, _mat[7] - other.y, _mat[11] - other.z, _mat[15] - other.w);
            }

            inline mat4<_type> operator*(vec4<_type> other)
            {
                return mat4<_type>(_mat[0] * other.x, _mat[4] * other.y, _mat[8]  * other.z, _mat[12] * other.w,
                                   _mat[1] * other.x, _mat[5] * other.y, _mat[9]  * other.z, _mat[13] * other.w,
                                   _mat[2] * other.x, _mat[6] * other.y, _mat[10] * other.z, _mat[14] * other.w,
                                   _mat[3] * other.x, _mat[7] * other.y, _mat[11] * other.z, _mat[15] * other.w);
            }

            inline mat4<_type> operator/(vec4<_type> other)
            {
                return mat4<_type>(_mat[0] / other.x, _mat[4] / other.y, _mat[8]  / other.z, _mat[12] / other.w,
                                   _mat[1] / other.x, _mat[5] / other.y, _mat[9]  / other.z, _mat[13] / other.w,
                                   _mat[2] / other.x, _mat[6] / other.y, _mat[10] / other.z, _mat[14] / other.w,
                                   _mat[3] / other.x, _mat[7] / other.y, _mat[11] / other.z, _mat[15] / other.w);
            }

            /****************************************************************/

            inline mat4<_type> operator+(mat4<_type> other)
            {
                return mat4<_type>(_mat[0] + other[0], _mat[4] + other[4], _mat[8]  + other[8],  _mat[12] + other[12],
                                   _mat[1] + other[1], _mat[5] + other[5], _mat[9]  + other[9],  _mat[13] + other[13],
                                   _mat[2] + other[2], _mat[6] + other[6], _mat[10] + other[10], _mat[14] + other[14],
                                   _mat[3] + other[3], _mat[7] + other[7], _mat[11] + other[11], _mat[15] + other[15]);
            }

            inline mat4<_type> operator-(mat4<_type> other)
            {
                return mat4<_type>(_mat[0] - other[0], _mat[4] - other[4], _mat[8]  - other[8],  _mat[12] - other[12],
                                   _mat[1] - other[1], _mat[5] - other[5], _mat[9]  - other[9],  _mat[13] - other[13],
                                   _mat[2] - other[2], _mat[6] - other[6], _mat[10] - other[10], _mat[14] - other[14],
                                   _mat[3] - other[3], _mat[7] - other[7], _mat[11] - other[11], _mat[15] - other[15]);
            }

            inline mat4<_type> operator*(mat4<_type> other)
            {
                vec4<_type> row1, row2, row3, row4;
                row1.x = vec4<_type>(_mat[0], _mat[4], _mat[8],  _mat[12]).dot(vec4<_type>(other[0], other[1], other[2], other[3]));
                row2.x = vec4<_type>(_mat[1], _mat[5], _mat[9],  _mat[13]).dot(vec4<_type>(other[0], other[1], other[2], other[3]));
                row3.x = vec4<_type>(_mat[3], _mat[6], _mat[10], _mat[14]).dot(vec4<_type>(other[0], other[1], other[2], other[3]));
                row4.x = vec4<_type>(_mat[4], _mat[7], _mat[11], _mat[15]).dot(vec4<_type>(other[0], other[1], other[2], other[3]));

                row1.y = vec4<_type>(_mat[0], _mat[4], _mat[8],  _mat[12]).dot(vec4<_type>(other[4], other[5], other[6], other[7]));
                row2.y = vec4<_type>(_mat[1], _mat[5], _mat[9],  _mat[13]).dot(vec4<_type>(other[4], other[5], other[6], other[7]));
                row3.y = vec4<_type>(_mat[3], _mat[6], _mat[10], _mat[14]).dot(vec4<_type>(other[4], other[5], other[6], other[7]));
                row4.y = vec4<_type>(_mat[4], _mat[7], _mat[11], _mat[15]).dot(vec4<_type>(other[4], other[5], other[6], other[7]));

                row1.z = vec4<_type>(_mat[0], _mat[4], _mat[8],  _mat[12]).dot(vec4<_type>(other[8], other[9], other[10], other[11]));
                row2.z = vec4<_type>(_mat[1], _mat[5], _mat[9],  _mat[13]).dot(vec4<_type>(other[8], other[9], other[10], other[11]));
                row3.z = vec4<_type>(_mat[3], _mat[6], _mat[10], _mat[14]).dot(vec4<_type>(other[8], other[9], other[10], other[11]));
                row4.z = vec4<_type>(_mat[4], _mat[7], _mat[11], _mat[15]).dot(vec4<_type>(other[8], other[9], other[10], other[11]));

                row1.w = vec4<_type>(_mat[0], _mat[4], _mat[8],  _mat[12]).dot(vec4<_type>(other[12], other[13], other[14], other[15]));
                row2.w = vec4<_type>(_mat[1], _mat[5], _mat[9],  _mat[13]).dot(vec4<_type>(other[12], other[13], other[14], other[15]));
                row3.w = vec4<_type>(_mat[3], _mat[6], _mat[10], _mat[14]).dot(vec4<_type>(other[12], other[13], other[14], other[15]));
                row4.w = vec4<_type>(_mat[4], _mat[7], _mat[11], _mat[15]).dot(vec4<_type>(other[12], other[13], other[14], other[15]));


                return mat4<_type>(row1.x, row1.y, row1.z, row1.w,
                                   row2.x, row2.y, row2.z, row2.w,
                                   row3.x, row3.y, row3.z, row3.w,
                                   row4.x, row4.y, row4.z, row4.w);
            }

            inline mat4<_type> operator/(mat4<_type> other)
            {
                return mat4<_type>(_mat[0] / other[0], _mat[4] / other[4], _mat[8]  / other[8],  _mat[12] / other[12],
                                   _mat[1] / other[1], _mat[5] / other[5], _mat[9]  / other[9],  _mat[13] / other[13],
                                   _mat[2] / other[2], _mat[6] / other[6], _mat[10] / other[10], _mat[14] / other[14],
                                   _mat[3] / other[3], _mat[7] / other[7], _mat[11] / other[11], _mat[15] / other[15]);
            }

            /****************************************************************/

            inline vec3<_type> vec_multiply(vec3<_type> other)
            {
                return vec3<_type>(_mat[0] * other.x + _mat[3] * other.y + _mat[6] * other.z,
                                   _mat[1] * other.x + _mat[4] * other.y + _mat[7] * other.z,
                                   _mat[2] * other.x + _mat[4] * other.y + _mat[8] * other.z);
            }

            inline vec3<_type> vec_divide(vec3<_type> other)
            {
                return vec3<_type>(_mat[0] / other.x + _mat[3] / other.y + _mat[6] / other.z,
                                   _mat[1] / other.x + _mat[4] / other.y + _mat[7] / other.z,
                                   _mat[2] / other.x + _mat[4] / other.y + _mat[8] / other.z);
            }
    };

    typedef mat4<float>             mat4f;
    typedef mat4<double>            mat4d;
    typedef mat4<int>               mat4i;
    typedef mat4<unsigned int>      mat4ui;
    typedef mat4<short>             mat4s;
    typedef mat4<unsigned short>    mat4us;

    /**************************************************************
     * Generate a 4*4 rotation matrix.
     *
     * @param a The rotation angle(euler).
     * @param axis The axis to rotate around(a * (0 <= n <= 1))
     *
     * @return The rotation matrix.
     **************************************************************/
    mat4<float> rotationMat4(float a, vec3<float> axis);


    /************************************************
     * Generate a 4*4 projection matrix.
     *
     * @param left The left clipping point
     * @param right The right clipping point.
     * @param near The near clipping point.
     * @param far The far clipping point.
     * @param bottom The bottom clipping point.
     * @param top The top clipping point.
     *
     * @return The projection matrix.
     ************************************************/
    mat4<float> perspectiveMat4(float left, float right, float near, float far, float bottom, float top);


    /*************************************************
     * Generate a 4*4 view matrix.
     *
     * @param pos The position of the "camera".
     * @param look The direction it's looking into.
     *
     * @return The view matrix.
     *************************************************/
    mat4<float> lookAt(vec3<float> pos, vec3<float> dir);
};

#endif // MAT4_INCLUDED
