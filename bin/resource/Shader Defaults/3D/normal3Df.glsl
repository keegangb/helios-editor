#version 330 core

in vec2 uv;
in vec3 normal;

out vec4 fragColor;

uniform sampler2D tex;
uniform bool useTexture;

void main()
{
    vec3 color = vec3(1.0, 1.0, 1.0) + normal;
    color *= 0.5;

    if (useTexture)
        fragColor = vec4(texture(tex, vec2(uv.x, uv.y)).xyz, 1.0);
    else
        fragColor = vec4(color, 1.0);
}