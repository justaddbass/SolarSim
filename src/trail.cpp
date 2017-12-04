#include "trail.h"

#include "Shaders.h"

#include <stdio.h>

Trail::Trail(int size) {
    this->size = size;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0 );
    glBindVertexArray(0);

    glm::mat4 projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 10000.0f);
    glm::mat4 view = glm::lookAt(glm::vec3(0, 50, 50), glm::vec3(0,0,0), glm::vec3(0,1,0));

    shader = LoadShaders("trail.vs","trail.fs");
    glUseProgram(shader);
    GLuint viewID = glGetUniformLocation(shader, "view");
    GLuint projID = glGetUniformLocation(shader, "projection");
    glUniformMatrix4fv(viewID, 1, GL_FALSE, &view[0][0]);
    glUniformMatrix4fv(projID, 1, GL_FALSE, &projection[0][0]);
    glUseProgram(0);
}

void Trail::addPoint(glm::vec3 point) {
    points.push_front(point);
    //printf("%f  %f  %f\n", point.x, point.y, point.z);
    if(points.size() > size)
        points.pop_back();
}

void Trail::draw() {
    glUseProgram(shader);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    //glClearBufferfv(GL_ARRAY_BUFFER, vbo, NULL);
    glBufferData(GL_ARRAY_BUFFER, points.size() * sizeof(glm::vec3), &points[0], GL_STATIC_DRAW);
    glDrawArrays(GL_POINTS, 0, points.size() * 3);
    glBindVertexArray(0);
    glUseProgram(0);
}
