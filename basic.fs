#version 330 core

uniform sampler2D texture_sampler;

in vec3 normal;
in vec3 fragPos;
//in vec3 normalEyeSpace;

out vec4 color;

uniform vec3 viewPos;

void main() {
/*
    float ambientStrength = 0.1f;
    float specularStrength = 0.5f;
    vec3 lightColor = vec3(1.0, 1.0, 1.0);

    // diffuse
    vec3 lightDir = normalize(-1.0 * fragPos);
    vec3 diff = max(dot(normalEyeSpace, lightDir), 0.0) * lightColor;

    // Specular
    vec3 viewDir = normalize(viewPos - fragPos);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;
*/
    //color = vec4((ambientStrength + diff + specular) + vec3(0.2,0.7,0.9) * 0.5, 1.0);
    //color = vec4(normal, 0.0);
    color = vec4(0.2, 0.5, 1.0, 1.0);
}
