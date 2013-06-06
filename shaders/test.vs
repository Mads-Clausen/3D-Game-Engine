#version 330 core
layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec2 vertexUV;

out vec2 UV;
uniform mat4 rotation;
uniform mat4 projection;

void main()
{
    gl_Position = vec4(vertexPosition_modelspace, 1.0);
    gl_Position = rotation * gl_Position;
    gl_Position.z -= 0.15;
    gl_Position = projection * gl_Position;
    UV = vertexUV;
}
