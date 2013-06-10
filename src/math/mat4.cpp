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

    mat4<float> perspectiveMat4(float frustumScale, float aspect, float near, float far)
    {
        mat4<float> mat(
                        frustumScale * aspect,      0,                          0,                              0,
                        0,                          frustumScale,               0,                              0,
                        0,                          0,                         (far + near) / (near - far),     (2 * far * near) / (near - far),
                        0,                          0,                         -1,                              0
                        );

        return mat;
    }

    mat4<float> lookAt(vec3<float> pos, vec3<float> look)
    {
        vec3<float> up(0.0f, 1.0f, 0.0f), right;

        vec3<float> dir(look.x - pos.x,
                        look.y - pos.y,
                        look.z - pos.z);
        dir = dir.normal();

        right = dir.cross(up);
        up = right.cross(dir).normal();

        mat4<float> view(
			right.x, right.y, right.z, 0.0f,
                       	up.x,    up.y,    up.z,	   0.0f,
                       -dir.x,  -dir.y,  -dir.z,   0.0f,
                       	 0.0f,    0.0f,    0.0f,   1.0f);
        mat4<float> aux;
        for(unsigned int i = 0; i < 4; ++i) aux[i + i * 4] = 1.0f; // fill diagonal

        aux[12] = -pos.x;
        aux[13] = -pos.y;
        aux[14] = -pos.z;

        return view * aux;
    }
};
