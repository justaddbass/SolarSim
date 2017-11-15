#include "Simulation.h"

#include <cmath>
#include <cstdio>

const float G = 6.674 * pow(10, -11);

Simulation::Simulation(camera* cam) {
    mCamera = cam;
}

void Simulation::setCameraFollow(Celestial* c) {
    follow = c;
}

void Simulation::addCelestial(Celestial* c) {
    mCelestial.push_back(c);
}

// meters and kilograms
double Simulation::gravityPull(float m1, float m2, float r) {
    return G * ( (m1 * m2) / pow(r, 2));
}

vec3 Simulation::calculateForce(Celestial c1, Celestial c2) {
    glm::dvec3 pull;

    //get unit vector between objects
    pull = c1.getPos() - c2.getPos();
    float length = glm::length(pull);
    pull = glm::normalize(pull);

    //calculate gravitational pull
    pull = pull * gravityPull(c1.getMass(), c2.getMass(), length) / 1.5*pow(10,8);
    return pull;
}

void Simulation::applyForcePhase() {
    for(std::vector<Celestial*>::iterator i = mCelestial.begin(); i != mCelestial.end(); i++) {

        for(std::vector<Celestial*>::iterator j = mCelestial.begin(); j != mCelestial.end(); j++) {
            if((*i) == (*j))
                continue;
            (*i)->addPull(calculateForce((*(*i)), (*(*j))));
        }
    }
}

void Simulation::moveCelestialPhase(double deltaTime) {
    for(std::vector<Celestial*>::iterator i = mCelestial.begin(); i != mCelestial.end(); i++) {
        (*i)->applyPhysics(deltaTime);
    }

    mCamera->view = glm::lookAt(glm::vec3(follow->getPos() + glm::dvec3(0, 12, 12)), glm::vec3(follow->getPos()), glm::vec3(0,1,0));
}

void Simulation::Draw() {

    for(std::vector<Celestial*>::iterator i = mCelestial.begin(); i != mCelestial.end(); i++) {
        (*i)->Draw();
    }
}
