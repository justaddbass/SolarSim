#ifndef PLANET
#define PLANET

#include "Celestial.h"

class Planet {
public:
    Planet(int mass, glm::vec3 initialVel, glm::vec3 initialPos);
    void Draw(GLuint shader);
    void addPull(glm::vec3 pull);
    void setPull(glm::vec3 pull);
    inline glm::vec3 getPos() {return mPos;}
    inline float getMass() {return mMass;}
    void applyPhysics(double timeDelta);
private:
    float mMass;
    Mesh mMesh;
    glm::vec3 mInertia;
    glm::vec3 mPull;
    glm::vec3 mPos;
    glm::mat4 mModel;
    GLuint modelID;
};

#endif
