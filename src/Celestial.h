#ifndef CELESTIAL
#define CELESTIAL

#include <glm/glm.hpp>

#include "Mesh.h"
#include "camera.h"

class Celestial {
public:
    Celestial() {};
    Celestial(double mass, float scale, glm::dvec3 initialVel, glm::dvec3 initialPos, GLuint shader, camera* cam);

    void addPull(glm::dvec3 pull);
    void applyPhysics(double deltaTime);
    inline glm::dvec3 getPos() {return mModel[3];}
    inline double getMass() {return mMass;}
    void Draw();
protected:
    Mesh mMesh;
    double mMass;
    float mScale;
    glm::dmat4 mModel;
    glm::dvec3 mVelocity;
    glm::dvec3 mPull;
    GLuint mShader;
    camera* mCamera;
};

#endif
