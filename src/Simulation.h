#ifndef SIMULATION
#define SIMULATION

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Celestial.h"
#include "camera.h"
#include "include.h"

class Simulation {
public:
    Simulation() {};
    Simulation(camera* cam);
    void setCameraFollow(Celestial* c);
    void addCelestial(Celestial* c);
    void Draw();

    vec3 calculateForce(Celestial c1, Celestial c2);
    void applyForcePhase();
    void moveCelestialPhase(double deltaTime);
private:
    std::vector<Celestial*> mCelestial;
    Celestial* follow;
    camera* mCamera;

    double gravityPull(float m1, float m2, float r);
};

#endif
