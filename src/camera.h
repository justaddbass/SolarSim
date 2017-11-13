#ifndef CAMERA
#define CAMERA

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

typedef struct camera {
    glm::mat4 view;
    glm::mat4 projection;

    camera() {
        view = glm::mat4();
        projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    }
} camera;

#endif
