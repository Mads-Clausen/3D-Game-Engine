/******************************************************************
 * <insert name>   :    Game Engine produced by Mads Clausen
 * www             :    http://anickyan.koding.com/ge
 *
 * Game engine using OpenGL 3.2 for hardware-accelerated
 * graphics, for the best performance.
 *
 * Copyright (c) Mads Clausen :: All Rights Reserved
 ******************************************************************/


#ifndef VEC2_INCLUDED
#define VEC2_INCLUDED

#include <cmath>

namespace math
{
    template<typename _type>
    class vec2
    {
        private:
            _type _gl_a[2];

        public:
            _type x, y;

            vec2() {};
            vec2(_type _x, _type _y)
            {
                _gl_a[0] = x = _x;
                _gl_a[1] = y = _y;
            }

            inline vec2<_type> operator+(_type other)        { return vec2<_type>(x + other,   y + other); }
            inline vec2<_type> operator-(_type other)        { return vec2<_type>(x - other,   y - other); }
            inline vec2<_type> operator*(_type other)        { return vec2<_type>(x * other,   y * other); }
            inline vec2<_type> operator/(_type other)        { return vec2<_type>(x / other,   y / other); }

            inline vec2<_type> operator+(vec2<_type> &other) { return vec2<_type>(x + other.x, y + other.y); }
            inline vec2<_type> operator-(vec2<_type> &other) { return vec2<_type>(x - other.x, y - other.y); }
            inline vec2<_type> operator*(vec2<_type> &other) { return vec2<_type>(x * other.x, y * other.y); }
            inline vec2<_type> operator/(vec2<_type> &other) { return vec2<_type>(x / other.x, y / other.y); }

            inline _type operator[](int i)
            {
                if(i < 0 || i >= 2)
                    return 0;

                _gl_a[0] = x;
                _gl_a[1] = y;
                return _gl_a[i];
            }

            inline double magnitude()
            {
                return sqrt(x * x + y * y);
            }

            inline vec2<_type> normal()
            {
                double m = this->magnitude();
                return vec2<_type>(x / m, y / m);
            }

            inline _type dot(vec2<_type> other)
            {
                return x * other.x + y * other.y;
            }
    };

    typedef vec2<float>             vec2f;
    typedef vec2<double>            vec2d;
    typedef vec2<int>               vec2i;
    typedef vec2<unsigned int>      vec2ui;
    typedef vec2<short>             vec2s;
    typedef vec2<unsigned short>    vec2us;
};

#endif // VEC2_INCLUDED
