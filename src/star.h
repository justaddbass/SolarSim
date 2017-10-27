#ifndef STAR
#define STAR

#include "Celestial.h"

class Star : public Celestial {
public:
    Star() {};
    Star(int mass);
    void Draw(GLuint shader);
private:

};

#endif
