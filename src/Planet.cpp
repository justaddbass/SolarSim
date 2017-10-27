#include "Planet.h"

#include <cstdio>

Planet::Planet(int mass, glm::vec3 initialVel, glm::vec3 initialPos) {
    mModel = glm::mat4();
    mMesh = Mesh("sphere.obj");
    mMass = mass;
}

void Planet::Draw(GLuint shader) {
    //mModel = glm::mat4();
    glUseProgram(shader);
    modelID = glGetUniformLocation(shader, "model");
    glUniformMatrix4fv(modelID, 1 , GL_FALSE, &mModel[0][0]);
    mMesh.Draw(shader);
}
