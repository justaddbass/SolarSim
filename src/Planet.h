#ifndef PLANET
#define PLANET

#include "Celestial.h"

class Planet {
public:
    Planet(int mass, glm::vec3 initialVel, glm::vec3 initialPos);
    void Draw(GLuint shader);
private:
    int mMass;
    Mesh mMesh;
    glm::vec3 mVel;
    glm::mat4 mModel;
    GLuint modelID;
};

#endif
