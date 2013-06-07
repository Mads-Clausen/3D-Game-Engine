/******************************************************************
 * <insert name>   :    Game Engine produced by Mads Clausen
 * www             :    http://anickyan.koding.com/ge
 *
 * Game engine using OpenGL 3.2 for hardware-accelerated
 * graphics, for the best performance.
 *
 * Copyright (c) Mads Clausen :: All Rights Reserved
 ******************************************************************/


#ifndef VEC3_INCLUDED
#define VEC3_INCLUDED

#include <cmath>

namespace math
{
    template<typename _type> class vec2;

    template<typename _type>
    class vec3
    {
        private:
            _type _gl_a[3];

        public:
            _type x, y, z;

            vec3() {};
            vec3(_type _x, _type _y, _type _z)
            {
                _gl_a[0] = x = _x;
                _gl_a[1] = y = _y;
                _gl_a[2] = z = _z;
            }

            vec3(vec2<_type> v, _type w)
            {
                _gl_a[0] = x = v.x;
                _gl_a[1] = y = v.y;
                _gl_a[2] = z = w;
            }

            inline vec3<_type> operator=(vec2<_type> &v)
            {
                _gl_a[0] = x = v.x;
                _gl_a[1] = y = v.y;
                _gl_a[2] = z = 0;
            }

            inline vec3<_type> operator+(_type other)        { return vec3<_type>(x + other,   y + other,   z + other); }
            inline vec3<_type> operator-(_type other)        { return vec3<_type>(x - other,   y - other,   z - other); }
            inline vec3<_type> operator*(_type other)        { return vec3<_type>(x * other,   y * other,   z * other); }
            inline vec3<_type> operator/(_type other)        { return vec3<_type>(x / other,   y / other,   z / other); }

            inline vec3<_type> operator+(vec3<_type> &other) { return vec3<_type>(x + other.x, y + other.y, z + other.z); }
            inline vec3<_type> operator-(vec3<_type> &other) { return vec3<_type>(x - other.x, y - other.y, z - other.z); }
            inline vec3<_type> operator*(vec3<_type> &other) { return vec3<_type>(x * other.x, y * other.y, z * other.z); }
            inline vec3<_type> operator/(vec3<_type> &other) { return vec3<_type>(x / other.x, y / other.y, z / other.z); }

            inline _type operator[](int i)
            {
                if(i < 0 || i >= 3)
                    return 0;

                _gl_a[0] = x;
                _gl_a[1] = y;
                _gl_a[2] = z;
                return _gl_a[i];
            }

            inline double magnitude()
            {
                return sqrt(x * x + y * y + z * z);
            }

            inline vec3<_type> normal()
            {
                double m = this->magnitude();
                return vec3<_type>(x / m, y / m, z / m);
            }

            inline _type dot(vec3<_type> other)
            {
                return x * other.x + y * other.y + z * other.z;
            }

            inline vec3<_type> cross(vec3<_type> other)
            {
                return vec3<_type>(y * other.z - other.y * z,
                                   z * other.x - other.z * x,
                                   x * other.y - other.x * y);
            }
    };

    typedef vec3<float>             vec3f;
    typedef vec3<double>            vec3d;
    typedef vec3<int>               vec3i;
    typedef vec3<unsigned int>      vec3ui;
    typedef vec3<short>             vec3s;
    typedef vec3<unsigned short>    vec3us;
};

#endif // VEC3_INCLUDED
