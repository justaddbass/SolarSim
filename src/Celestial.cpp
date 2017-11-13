#include "Celestial.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_access.hpp>

#include "Simulation.h"

Celestial::Celestial(double mass, float scale, vec3 initialVel, vec3 initialPos, GLuint shader, camera* cam) :
    mMesh(Mesh("sphere.obj")) {
    mMass = mass;
    mScale = scale;
    mVelocity = initialVel;
    mModel = glm::translate(mat4(), initialPos);
    mShader = shader;
    glUseProgram(shader);
    mCamera = cam;
    glUniformMatrix4fv(glGetUniformLocation(shader, "projection"), 1, GL_FALSE, &mCamera->projection[0][0]);
    glUseProgram(0);
}

void Celestial::Draw() {
    glUseProgram(mShader);
    GLuint modelID = glGetUniformLocation(mShader, "model");
    GLuint scaleID = glGetUniformLocation(mShader, "scale");
    GLuint viewID = glGetUniformLocation(mShader, "view");
    glUniformMatrix4fv(modelID, 1 , GL_FALSE, &glm::mat4(mModel)[0][0]);
    //glUniformMatrix4fv(viewID, 1, GL_FALSE, &mCamera->view[0][0]);
    glUniform1f(scaleID, mScale);
    mMesh.Draw(mShader);
    glUseProgram(0);
}

void Celestial::addPull(vec3 pull) {
    mPull += pull;
}

void Celestial::applyPhysics(double deltaTime) {
    mVelocity += mPull / mMass * deltaTime;
    mModel = glm::translate(mModel, mVelocity);
    mPull = vec3(0,0,0);
}
