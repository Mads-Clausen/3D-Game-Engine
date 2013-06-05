/******************************************************************
 * <insert name>   :    Game Engine produced by Mads Clausen
 * www             :    http://anickyan.koding.com/ge
 *
 * Game engine using OpenGL 3.2 for hardware-accelerated
 * graphics, for the best performance.
 *
 * Copyright (c) Mads Clausen :: All Rights Reserved
 ******************************************************************/

#ifndef MAT2_INCLUDED
#define MAT2_INCLUDED

namespace math
{
    template<typename _type> class vec2;

    template<typename _type>
    class mat2
    {
        private:
            _type _mat[4];

        public:
            mat2() {};
            mat2(vec2<_type> v0, vec2<_type> v1, vec2<_type> v2)
            {
                _mat[0] = v0.x; _mat[3] = v0.y;
                _mat[1] = v1.x; _mat[4] = v1.y;
            }

            mat2(_type x0, _type y0, _type x1, _type y1)
            {
                _mat[0] = x0; _mat[3] = y0;
                _mat[1] = x1; _mat[4] = y1;
            }

            mat2(vec2<_type> v)
            {
                _mat[0] = v.x; _mat[3] = 0;
                _mat[1] = 0;   _mat[4] = v.y;
            }

            mat2(_type scalar)
            {
                _mat[0] = scalar;   _mat[3] = 0;
                _mat[1] = 0;        _mat[4] = scalar;
            }

            inline _type operator[](int i)               { return _mat[i]; }
            inline _type operator()(int column, int row) { return _mat[2 * column + row]; }

            inline mat2<_type> operator+(_type other)
            {
                return mat2<_type>(_mat[0] + other, _mat[3] + other,
                                   _mat[1] + other, _mat[4] + other);
            }

            inline mat2<_type> operator-(_type other)
            {
                return mat2<_type>(_mat[0] - other, _mat[3] - other,
                                   _mat[1] - other, _mat[4] - other);
            }

            inline mat2<_type> operator*(_type other)
            {
                return mat2<_type>(_mat[0] * other, _mat[3] * other,
                                   _mat[1] * other, _mat[4] * other);
            }

            inline mat2<_type> operator/(_type other)
            {
                return mat2<_type>(_mat[0] / other, _mat[3] / other,
                                   _mat[1] / other, _mat[4] / other);
            }

            /****************************************************************/

            inline mat2<_type> operator+(vec2<_type> &other)
            {
                return mat2<_type>(_mat[0] + other.x, _mat[3] + other.y,
                                   _mat[1] + other.x, _mat[4] + other.y);
            }

            inline mat2<_type> operator-(vec2<_type> &other)
            {
                return mat2<_type>(_mat[0] - other.x, _mat[3] - other.y,
                                   _mat[1] - other.x, _mat[4] - other.y);
            }

            inline mat2<_type> operator*(vec2<_type> &other)
            {
                return mat2<_type>(_mat[0] * other.x, _mat[3] * other.y,
                                   _mat[1] * other.x, _mat[4] * other.y);
            }

            inline mat2<_type> operator/(vec2<_type> &other)
            {
                return mat2<_type>(_mat[0] / other.x, _mat[3] / other.y,
                                   _mat[1] / other.x, _mat[4] / other.y);
            }

            /****************************************************************/

            inline mat2<_type> operator+(mat2<_type> &other)
            {
                return mat2<_type>(_mat[0] + other[0], _mat[3] + other[3],
                                   _mat[1] + other[1], _mat[4] + other[4]);
            }

            inline mat2<_type> operator-(mat2<_type> &other)
            {
                return mat2<_type>(_mat[0] - other[0], _mat[3] - other[3],
                                   _mat[1] - other[1], _mat[4] - other[4]);
            }

            inline mat2<_type> operator*(mat2<_type> &other)
            {
                return mat2<_type>(_mat[0] * other[0], _mat[3] * other[3],
                                   _mat[1] * other[1], _mat[4] * other[4]);
            }

            inline mat2<_type> operator/(mat2<_type> &other)
            {
                return mat2<_type>(_mat[0] / other[0], _mat[3] / other[3],
                                   _mat[1] / other[1], _mat[4] / other[4]);
            }
    };

    typedef mat2<float>             mat2f;
    typedef mat2<double>            mat2d;
    typedef mat2<int>               mat2i;
    typedef mat2<unsigned int>      mat2ui;
    typedef mat2<short>             mat2s;
    typedef mat2<unsigned short>    mat2us;
};
#endif // MAT2_INCLUDED
