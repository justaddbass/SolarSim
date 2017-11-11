#ifndef STAR
#define STAR

#include "Celestial.h"

class Star {
public:
    Star() {};
    Star(double mass, float scale);
    void Draw(GLuint shader);
    //inline double getMass() {return mMass;}
private:

};

#endif
