/******************************************************************
 * <insert name>   :    Game Engine produced by Mads Clausen
 * www             :    http://anickyan.koding.com/ge
 *
 * Game engine using OpenGL 3.2 for hardware-accelerated
 * graphics, for the best performance.
 *
 * Copyright (c) Mads Clausen :: All Rights Reserved
 ******************************************************************/

#include "math/mat4.hpp"

namespace math
{
    mat4<float> rotationMat4(float a, vec3<float> axis)
    {
        a *= DEGTORAD;
        double cosAx = cos(a * axis.x);
        double sinAx = sin(a * axis.x);
        double cosAy = cos(a * axis.y);
        double sinAy = sin(a * axis.y);
        double cosAz = cos(a * axis.z);
        double sinAz = sin(a * axis.z);

        mat4<float> rotX(1,     0,     0, 0,
                         0, cosAx,-sinAx, 0,
                         0, sinAx, cosAx, 0,
                         0,     0,     0, 1);

        mat4<float> rotY(cosAy, 0, sinAy, 0,
                         0,     1,     0, 0,
                        -sinAy, 0, cosAy, 0,
                         0,     0,     0, 1);

        mat4<float> rotZ(cosAz,-sinAz, 0, 0,
                         sinAz, cosAz, 0, 0,
                         0,     0,     1, 0,
                         0,     0,     0, 1);

        return rotX * rotY * rotZ;
    }

    mat4<float> perspectiveMat4(float left, float right, float near, float far, float bottom, float top)
    {
        mat4<float> mat(2 * near / (right - left), 0,                         (right + left) / (right - left), 0,
                        0,                         2 * near / (top - bottom), (top + bottom) / (top - bottom), 0,
                        0,                         0,                         -(far + near) / (far - near),    (-2 * far * near) / (far - near),
                        0,                         0,                          -1,                             0);

        return mat;
    }
};
