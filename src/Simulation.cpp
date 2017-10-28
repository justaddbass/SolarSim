#include "Simulation.h"

#include <cmath>

const long double G = 6.674 * pow(10, -11);


void Simulation::setStar(int mass) {
    mSun = new Star(mass);
}

void Simulation::addPlanet(Planet* p) {
    mPlanets.push_back(p);
}

void Simulation::applyForcePhase() {
    for(std::vector<Planet*>::iterator i = mPlanets.begin(); i != mPlanets.end(); i++) {
        (*i)->setPull(glm::vec3(0,0,0));
    }
}

double Simulation::gravityPull(double m1, double m2, double r) {
    return G * ( (m1 * m2) / pow(r, 2));
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
