/******************************************************************
 * <insert name>   :    Game Engine produced by Mads Clausen
 * www             :    http://anickyan.koding.com/ge
 *
 * Game engine using OpenGL 3.2 for hardware-accelerated
 * graphics, for the best performance.
 *
 * Copyright (c) Mads Clausen :: All Rights Reserved
 ******************************************************************/

#include "math/mat3.hpp"

namespace math
{
    mat3<float> rotationMat3(float a, vec3<float> axis)
    {
        a *= DEGTORAD;
        double cosAx = cos(a * axis.x);
        double sinAx = sin(a * axis.x);
        double cosAy = cos(a * axis.y);
        double sinAy = sin(a * axis.y);
        double cosAz = cos(a * axis.z);
        double sinAz = sin(a * axis.z);

        mat3<float> rotX(1,     0,     0,
                         0, cosAx,-sinAx,
                         0, sinAx, cosAx);

        mat3<float> rotY(cosAy, 0, sinAy,
                         0,     1,     0,
                        -sinAy, 0, cosAy);

        mat3<float> rotZ(cosAz,-sinAz,  0,
                         sinAz, cosAz,  0,
                         0,     0,      1);

        return rotX * rotY * rotZ;
    }
};
