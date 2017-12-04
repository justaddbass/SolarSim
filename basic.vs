#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec2 vertexUV;
layout(location = 2) in vec3 vertexNormal_modelspace;

out vec2 uv;
out vec3 normal;
out vec3 fragPos;
out vec3 normalEyeSpace;

uniform mat4 view;
uniform mat4 projection;
uniform mat4 model;

void main() {
    gl_Position = projection * view * model * vec4(vertexPosition_modelspace, 1.0);
    fragPos = gl_Position.xyz;
    normal = vertexNormal_modelspace;
    //normalEyeSpace = normalize(transpose(inverse(model)) * vec4(normal,1.0)).xyz;
}
