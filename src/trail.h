#ifndef TRAIL
#define TRAIL

#ifdef __APPLE__
    #include <OpenGL/gl3.h>
#else
    #include <GL/glew.h>
#endif
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_access.hpp>
#include <deque>

class Trail {
public:
    Trail() {};
    Trail(int size);
    ~Trail() {}
    void addPoint(glm::vec3 point);
    void draw();
private:
    int size;
    std::deque<glm::vec3> points;
    GLuint vao, vbo;
    GLuint shader;
};

#endif
