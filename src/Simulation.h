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
    void Draw(GLuint shader, GLuint sunShader);

    void applyForcePhase();
    void moveCelestialPhase(double deltaTime);
private:
    Star* mSun;
    std::vector<Planet*> mPlanets;


    float gravityPull(float m1, float m2, float r);
};

#endif
