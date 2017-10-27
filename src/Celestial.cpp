#include "Celestial.h"

Celestial::Celestial(int mass) {
    mMesh = Mesh("sphere.obj");
    mMass = mass;
}
