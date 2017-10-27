#ifndef SIMULATION
#define SIMULATION

#include <vector>

#include "star.h"
#include "Planet.h"

class Simulation {
public:
    Simulation() {};
    void setStar(int mass);
    void addPlanet(Planet* p);
    void Draw(GLuint shader);
private:
    Star mSun;
    std::vector<Planet*> mPlanets;

    void applyForcePhase();
    void moveCelestialPhase();
};

#endif
