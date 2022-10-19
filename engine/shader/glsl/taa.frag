#version 310 es

#extension GL_GOOGLE_include_directive : enable

#include "constants.h"

layout(set = 0, binding = 0) uniform highp sampler2D scene_color;
layout(set = 0, binding = 1) uniform highp sampler2D history_buffer;

layout(location = 0) in vec2 in_uv;
layout(location = 0) out highp vec4 out_color;


void main()
{
    highp vec4 scene_color = texture(scene_color, in_uv);
    highp vec4 history_color = texture(history_buffer, in_uv);
    out_color = lerp(scene_color, history_color, 0.98f);
}

