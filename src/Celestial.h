#ifndef CELESTIAL
#define CELESTIAL

#include <glm/glm.hpp>

#include "Mesh.h"

class Celestial {
public:
    Celestial() {};
    Celestial(int mass);
protected:
    Mesh mMesh;
    int mMass;
    //glm::mat4 mModel;
};

#endif
