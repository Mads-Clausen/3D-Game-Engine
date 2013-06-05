/******************************************************************
 * <insert name>   :    Game Engine produced by Mads Clausen
 * www             :    http://anickyan.koding.com/ge
 *
 * Game engine using OpenGL 3.2 for hardware-accelerated
 * graphics, for the best performance.
 *
 * Copyright (c) Mads Clausen :: All Rights Reserved
 ******************************************************************/



#ifndef VEC4_INCLUDED
#define VEC4_INCLUDED

namespace math
{
    template<typename _type> class vec3;

    template<typename _type>
    class vec4
    {
        private:
            _type _gl_a[4];

        public:
            _type x, y, z, w;

            vec4() {};
            vec4(_type _x, _type _y, _type _z, _type _w)
            {
                _gl_a[0] = x = _x;
                _gl_a[1] = y = _y;
                _gl_a[2] = z = _z;
                _gl_a[3] = w = _w;
            }

            vec4(vec3<_type> v, _type w)
            {
                _gl_a[0] = x = v.x;
                _gl_a[1] = y = v.y;
                _gl_a[2] = z = v.z;
                _gl_a[3] = w = w;
            }

            inline vec4<_type> operator=(vec3<_type> &v)
            {
                _gl_a[0] = x = v.x;
                _gl_a[1] = y = v.y;
                _gl_a[2] = z = v.z;
                _gl_a[3] = w = 0;
            }

            inline vec4<_type> operator+(_type other)        { return vec4<_type>(x + other,   y + other,   z + other,   w + other); }
            inline vec4<_type> operator-(_type other)        { return vec4<_type>(x - other,   y - other,   z - other,   w - other); }
            inline vec4<_type> operator*(_type other)        { return vec4<_type>(x * other,   y * other,   z * other,   w * other); }
            inline vec4<_type> operator/(_type other)        { return vec4<_type>(x / other,   y / other,   z / other,   w / other); }

            inline vec4<_type> operator+(vec4<_type> &other) { return vec4<_type>(x + other.x, y + other.y, z + other.z, w + other.w); }
            inline vec4<_type> operator-(vec4<_type> &other) { return vec4<_type>(x - other.x, y - other.y, z - other.z, w + other.w); }
            inline vec4<_type> operator*(vec4<_type> &other) { return vec4<_type>(x * other.x, y * other.y, z * other.z, w + other.w); }
            inline vec4<_type> operator/(vec4<_type> &other) { return vec4<_type>(x / other.x, y / other.y, z / other.z, w + other.w); }

            inline _type operator[](int i)
            {
                if(i < 0 || i >= 4)
                    return 0;

                _gl_a[0] = x;
                _gl_a[1] = y;
                _gl_a[2] = z;
                _gl_a[3] = w;
                return _gl_a[i];
            }

            inline double magnitude()
            {
                return sqrt(x * x + y * y + z * z + w * w);
            }

            inline vec4<_type> normal()
            {
                double m = this->magnitude();
                return vec4<_type>(x / m, y / m, z / m, w / m);
            }
    };

    typedef vec4<float>             vec4f;
    typedef vec4<double>            vec4d;
    typedef vec4<int>               vec4i;
    typedef vec4<unsigned int>      vec4ui;
    typedef vec4<short>             vec4s;
    typedef vec4<unsigned short>    vec4us;
}

#endif // VEC4_INCLUDED
