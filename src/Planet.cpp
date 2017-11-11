//#include "Planet.h"

#include <cstdio>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_access.hpp>

#if 0
Planet::Planet(double mass, float scale, glm::dvec3 initialVel, glm::dvec3 initialPos) :
    //Celestial(mass, scale)
    {
    mModel = glm::translate(glm::mat4(), glm::vec3(initialPos));
    mInertia = initialVel;
    mMass = mass;
    mScale = scale;
}

void Planet::Draw(GLuint shader) {
    glUseProgram(shader);
    GLuint modelID = glGetUniformLocation(shader, "model");
    GLuint scaleID= glGetUniformLocation(shader, "scale");
    glUniformMatrix4fv(modelID, 1 , GL_FALSE, &mModel[0][0]);
    glUniform1f(scaleID, mScale);
    mMesh.Draw(shader);
}

void Planet::addPull(glm::dvec3 pull) {
    mPull += pull;
}

// TODO: remove this
void Planet::setPull(glm::dvec3 pull) {
    mPull = pull;
}

glm::dvec3 Planet::getPos() {
    return mModel[3];
}

void Planet::applyPhysics(double deltaTime) {
    mInertia += mPull / mMass * deltaTime;
    mModel = glm::translate(mModel, glm::vec3(mInertia));
    mPull = glm::dvec3(0,0,0);
}
#endif
