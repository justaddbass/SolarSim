#ifndef STAR
#define STAR

#include "Celestial.h"

class Star {
public:
    Star() {};
    Star(int mass);
    void Draw(GLuint shader);
    inline float getMass() {return mMass;}
private:
    Mesh mMesh;
    float mMass;
};

#endif
