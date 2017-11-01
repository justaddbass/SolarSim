#include "Simulation.h"

#include <cmath>

const float G = 6.674 * pow(10, -11);

void Simulation::setStar(int mass) {
    mSun = new Star(mass);
}

void Simulation::addPlanet(Planet* p) {
    mPlanets.push_back(p);
}

float Simulation::gravityPull(float m1, float m2, float r) {
    return G * ( (m1 * m2) / pow(r, 2));
}

void Simulation::applyForcePhase() {
    for(std::vector<Planet*>::iterator i = mPlanets.begin(); i != mPlanets.end(); i++) {
        glm::vec3 pull;

        //get unit vector towards sun
        pull = -1.0f * (*i)->getPos();
        float length = glm::length(pull);
        pull = glm::normalize(pull);

        //calculate gravitational pull
        pull = gravityPull((*i)->getMass(), mSun->getMass(), length) * pull;

        (*i)->setPull(pull);
    }
}

void Simulation::moveCelestialPhase(double deltaTime) {
    for(std::vector<Planet*>::iterator i = mPlanets.begin(); i != mPlanets.end(); i++) {
        (*i)->applyPhysics(deltaTime);
    }
}

void Simulation::Draw(GLuint shader, GLuint sunShader) {
    mSun->Draw(sunShader);

    for(std::vector<Planet*>::iterator i = mPlanets.begin(); i != mPlanets.end(); i++) {
        (*i)->Draw(shader);
    }
}
