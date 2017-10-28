#include "Planet.h"

#include <cstdio>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Planet::Planet(int mass, glm::vec3 initialVel, glm::vec3 initialPos) :
    mMesh(Mesh("sphere.obj")) {
    mModel = glm::translate(glm::mat4(), initialPos);

    mInertia = initialVel;
    mMass = mass;
}

void Planet::Draw(GLuint shader) {
    glUseProgram(shader);
    GLuint modelID = glGetUniformLocation(shader, "model");
    glUniformMatrix4fv(modelID, 1 , GL_FALSE, &mModel[0][0]);
    mMesh.Draw(shader);
}

void Planet::addPull(glm::vec3 pull) {
    mPull += pull;
}

void Planet::setPull(glm::vec3 pull) {
    mPull = pull;
}

void Planet::applyPhysics(double timeDelta) {
    
}
