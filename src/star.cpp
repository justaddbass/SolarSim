//#include "star.h"

#if 0
Star::Star(double mass, float scale) :
    Celestial(mass, scale) {
    mMass = mass;
    mScale = scale;
}

void Star::Draw(GLuint shader) {
    glUseProgram(shader);
    GLuint modelID = glGetUniformLocation(shader, "model");
    GLuint scaleID = glGetUniformLocation(shader, "scale");
    glUniformMatrix4fv(modelID, 1 , GL_FALSE, &glm::mat4()[0][0]);
    glUniform1f(scaleID, mScale);
    mMesh.Draw(shader);
}
#endif
