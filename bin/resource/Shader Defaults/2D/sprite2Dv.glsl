#version 330 core

layout(location = 0) in vec3 v_pos;
layout(location = 1) in vec2 v_uv;

uniform mat4 worldMatrix;
uniform vec2 windowSize;
uniform float unitsPerPixel;

out vec2 uv;

void main()
{
    uv = v_uv;

    vec4 pos = vec4(v_pos, 1.0)*worldMatrix;

    pos.x /= windowSize.x/2.0;
    pos.y /= windowSize.y/2.0;
    pos.z /= max(windowSize.x, windowSize.y)/unitsPerPixel;

    pos.xy *= unitsPerPixel;

    gl_Position = pos;
}
