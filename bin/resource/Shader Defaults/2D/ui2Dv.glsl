#version 330 core

layout(location = 0) in vec3 v_pos;
layout(location = 1) in vec2 v_uv;

uniform vec2 windowSize;
uniform vec4 rect;
uniform float depth;

out vec2 uv;

void main()
{
    uv = v_uv;

    vec4 pos = vec4(v_pos, 1.0);
    pos.xy *= rect.zw;
    pos.xy += vec2(rect.x, -rect.y);

    pos.x /= windowSize.x;
    pos.y /= windowSize.y;

    pos.z = -(depth/100.0 - 1.0 + 0.001);

    gl_Position = vec4(pos.x*2.0 - 1.0, pos.y*2.0 + 1.0, pos.z, 1.0);
}
