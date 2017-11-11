#ifndef TRAIL
#define TRAIL

#ifdef __APPLE__
    #include <OpenGL/gl3.h>
#else
    #include <GL/glew.h>
#endif
#include <glm/glm.hpp>
#include <queue>

#include "Shaders.h"

class Trail {
public:
    Trail() {};

    void addPoint(glm::vec3 p);
    void Draw(GLuint shader);
private:
    std::queue<glm::vec3> trail;
    GLuint vbo;
};

#endif
