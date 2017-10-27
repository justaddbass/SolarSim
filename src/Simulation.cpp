#include "Simulation.h"

#include <cstdio>

void Simulation::setStar(int mass) {
    mSun = Star(mass);
}

void Simulation::addPlanet(Planet* p) {
    mPlanets.push_back(p);
}

void Simulation::applyForcePhase() {

}

void Simulation::moveCelestialPhase() {

}

void Simulation::Draw(GLuint shader) {
    mSun.Draw(shader);

    for(std::vector<Planet*>::iterator i = mPlanets.begin(); i != mPlanets.end(); i++) {
        (*i)->Draw(shader);
    }
}
