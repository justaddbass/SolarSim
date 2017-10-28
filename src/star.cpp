#include "star.h"

Star::Star(int mass) :
    mMesh(Mesh("sphere.obj")) {
}

void Star::Draw(GLuint shader) {
    glUseProgram(shader);
    GLuint modelID = glGetUniformLocation(shader, "model");
    glUniformMatrix4fv(modelID, 1 , GL_FALSE, &glm::mat4()[0][0]);
    mMesh.Draw(shader);
}
