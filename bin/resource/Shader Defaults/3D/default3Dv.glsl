#version 330 core

layout(location = 0) in vec3 v_pos;
layout(location = 1) in vec2 v_uv;
layout(location = 2) in vec3 v_normal;

uniform mat4 worldMatrix;
uniform mat4 cameraMatrix;
uniform float aspect;

out vec2 uv;

void main()
{
    uv = v_uv;

    vec4 pos = vec4(v_pos, 1.0);
    pos = worldMatrix*pos;
    pos = cameraMatrix*pos;

    pos.x /= aspect;

    gl_Position = pos;
}