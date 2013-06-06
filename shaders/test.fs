#version 330 core
out vec3 color;

in vec2 UV;
uniform sampler2D tex_sampler;

void main()
{
    color = texture(tex_sampler, UV).rgb;
}
