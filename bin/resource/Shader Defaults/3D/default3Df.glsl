#version 330 core

in vec2 uv;
in vec3 normal;

out vec4 fragColor;

uniform sampler2D tex;
uniform bool useTexture;
uniform vec4 color;

void main()
{
    if (useTexture)
        fragColor = vec4(texture(tex, vec2(uv.x, uv.y)).xyz, 1.0);
    else
        fragColor = color;
}