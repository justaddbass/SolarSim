#include "Celestial.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_access.hpp>

#include "Simulation.h"

Celestial::Celestial(double mass, float scale, glm::dvec3 initialVel, glm::dvec3 initialPos, GLuint shader, camera* cam) :
    mMesh(Mesh("sphere.obj")) {
    mMass = mass;
    mScale = scale;
    mVelocity = initialVel;
    mModel = glm::translate(glm::dmat4(), initialPos);
    mShader = shader;
    //glUseProgram(shader);
    mCamera = cam;
    //glUniformMatrix4fv(glGetUniformLocation(shader, "projection"), 1, GL_FALSE, &mCamera->projection[0][0]);
}

void Celestial::Draw() {
    glUseProgram(mShader);
    GLuint modelID = glGetUniformLocation(mShader, "model");
    GLuint scaleID = glGetUniformLocation(mShader, "scale");
    GLuint viewID = glGetUniformLocation(mShader, "view");
    glUniformMatrix4dv(modelID, 1 , GL_FALSE, &mModel[0][0]);
    glUniformMatrix4fv(viewID, 1, GL_FALSE, &mCamera->view[0][0]);
    glUniform1f(scaleID, mScale);
    mMesh.Draw(mShader);
}

void Celestial::addPull(glm::dvec3 pull) {
    mPull += pull;
}

void Celestial::applyPhysics(double deltaTime) {
    mVelocity += mPull / mMass * deltaTime;
    //mModel = glm::translate(mModel, mVelocity);
    mPull = glm::dvec3(0,0,0);
}
