/******************************************************************
 * <insert name>   :    Game Engine produced by Mads Clausen
 * www             :    http://anickyan.koding.com/ge
 *
 * Game engine using OpenGL 3.2 for hardware-accelerated
 * graphics, for the best performance.
 *
 * Copyright (c) Mads Clausen :: All Rights Reserved
 ******************************************************************/


#ifndef MAT3_INCLUDED
#define MAT3_INCLUDED

template<typename _type> class vec3;

template<typename _type>
class mat3
{
    private:
        _type _mat[9];

    public:
        mat3() {};
        mat3(vec3<_type> v0, vec3<_type> v1, vec3<_type> v2)
        {
            _mat[0] = v0.x; _mat[3] = v0.y; _mat[6] = v0.z;
            _mat[1] = v1.x; _mat[4] = v1.y; _mat[7] = v1.z;
            _mat[2] = v2.x; _mat[5] = v2.y; _mat[8] = v2.z;
        }

        mat3(_type x0, _type y0, _type z0, _type x1, _type y1, _type z1, _type x2, _type y2, _type z2)
        {
            _mat[0] = x0; _mat[3] = y0; _mat[6] = z0;
            _mat[1] = x1; _mat[4] = y1; _mat[7] = z1;
            _mat[2] = x2; _mat[5] = y2; _mat[8] = z2;
        }

        mat3(vec3<_type> v)
        {
            _mat[0] = v.x; _mat[3] = 0;   _mat[6] = 0;
            _mat[1] = 0;   _mat[4] = v.y; _mat[7] = 0;
            _mat[2] = 0;   _mat[5] = 0;   _mat[8] = v.z;
        }

        mat3(_type scalar)
        {
            _mat[0] = scalar;   _mat[3] = 0;       _mat[6] = 0;
            _mat[1] = 0;        _mat[4] = scalar;  _mat[7] = 0;
            _mat[2] = 0;        _mat[5] = 0;       _mat[8] = scalar;
        }

        inline _type &operator[](int i)               { return _mat[i]; }
        inline _type &operator()(int column, int row) { return _mat[3 * column + row]; }

        inline mat3<_type> operator+(_type other)
        {
            return mat3<_type>(_mat[0] + other, _mat[3] + other, _mat[6] + other,
                               _mat[1] + other, _mat[4] + other, _mat[7] + other,
                               _mat[2] + other, _mat[5] + other, _mat[8] + other);
        }

        inline mat3<_type> operator-(_type other)
        {
            return mat3<_type>(_mat[0] - other, _mat[3] - other, _mat[6] - other,
                               _mat[1] - other, _mat[4] - other, _mat[7] - other,
                               _mat[2] - other, _mat[5] - other, _mat[8] - other);
        }

        inline mat3<_type> operator*(_type other)
        {
            return mat3<_type>(_mat[0] * other, _mat[3] * other, _mat[6] * other,
                               _mat[1] * other, _mat[4] * other, _mat[7] * other,
                               _mat[2] * other, _mat[5] * other, _mat[8] * other);
        }

        inline mat3<_type> operator/(_type other)
        {
            return mat3<_type>(_mat[0] / other, _mat[3] / other, _mat[6] / other,
                               _mat[1] / other, _mat[4] / other, _mat[7] / other,
                               _mat[2] / other, _mat[5] / other, _mat[8] / other);
        }

        /****************************************************************/

        inline mat3<_type> operator+(vec3<_type> &other)
        {
            return mat3<_type>(_mat[0] + other.x, _mat[3] + other.y, _mat[6] + other.z,
                               _mat[1] + other.x, _mat[4] + other.y, _mat[7] + other.z,
                               _mat[2] + other.x, _mat[5] + other.y, _mat[8] + other.z);
        }

        inline mat3<_type> operator-(vec3<_type> &other)
        {
            return mat3<_type>(_mat[0] - other.x, _mat[3] - other.y, _mat[6] - other.z,
                               _mat[1] - other.x, _mat[4] - other.y, _mat[7] - other.z,
                               _mat[2] - other.x, _mat[5] - other.y, _mat[8] - other.z);
        }

        inline mat3<_type> operator*(vec3<_type> &other)
        {
            return mat3<_type>(_mat[0] * other.x, _mat[3] * other.y, _mat[6] * other.z,
                               _mat[1] * other.x, _mat[4] * other.y, _mat[7] * other.z,
                               _mat[2] * other.x, _mat[5] * other.y, _mat[8] * other.z);
        }

        inline mat3<_type> operator/(vec3<_type> &other)
        {
            return mat3<_type>(_mat[0] / other.x, _mat[3] / other.y, _mat[6] / other.z,
                               _mat[1] / other.x, _mat[4] / other.y, _mat[7] / other.z,
                               _mat[2] / other.x, _mat[5] / other.y, _mat[8] / other.z);
        }

        /****************************************************************/

        inline mat3<_type> operator+(mat3<_type> &other)
        {
            return mat3<_type>(_mat[0] + other[0], _mat[3] + other[3], _mat[6] + other[6],
                               _mat[1] + other[1], _mat[4] + other[4], _mat[7] + other[7],
                               _mat[2] + other[2], _mat[5] + other[5], _mat[8] + other[8]);
        }

        inline mat3<_type> operator-(mat3<_type> &other)
        {
            return mat3<_type>(_mat[0] - other[0], _mat[3] - other[3], _mat[6] - other[6],
                               _mat[1] - other[1], _mat[4] - other[4], _mat[7] - other[7],
                               _mat[2] - other[2], _mat[5] - other[5], _mat[8] - other[8]);
        }

        inline mat3<_type> operator*(mat3<_type> &other)
        {
            return mat3<_type>(_mat[0] * other[0], _mat[3] * other[3], _mat[6] * other[6],
                               _mat[1] * other[1], _mat[4] * other[4], _mat[7] * other[7],
                               _mat[2] * other[2], _mat[5] * other[5], _mat[8] * other[8]);
        }

        inline mat3<_type> operator/(mat3<_type> &other)
        {
            return mat3<_type>(_mat[0] / other[0], _mat[3] / other[3], _mat[6] / other[6],
                               _mat[1] / other[1], _mat[4] / other[4], _mat[7] / other[7],
                               _mat[2] / other[2], _mat[5] / other[5], _mat[8] / other[8]);
        }
};

typedef mat3<float>     mat3f;
typedef mat3<double>    mat3d;
typedef mat3<int>       mat3i;
typedef mat3<short>     mat3s;

#endif // MAT3_INCLUDED
