#ifndef STAR
#define STAR

#include "Celestial.h"

class Star {
public:
    Star() {};
    Star(int mass);
    void Draw(GLuint shader);
private:
    Mesh mMesh;
};

#endif
