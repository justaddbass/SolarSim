#version 330 core

uniform sampler2D texture_sampler;

in vec2 uv;

out vec4 color;

void main() {
    //color = texture(texture_sampler, uv);
    color = vec4(0.2, 0.5, 1.0, 1.0);
}
