#version 330 core

in vec2 uv;

out vec4 fragColor;

uniform sampler2D tex;

void main()
{
    fragColor = vec4(texture(tex, uv).xyz, 1.0);
}
