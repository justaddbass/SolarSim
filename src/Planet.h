#ifndef PLANET
#define PLANET

#include <queue>

#include "Celestial.h"

class Planet {
public:
    Planet(double mass, float scale, glm::dvec3 initialVel, glm::dvec3 initialPos);
    void Draw(GLuint shader);
private:
    GLuint modelID;
};

#endif
