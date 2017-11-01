#ifdef __APPLE__
	#include <OpenGL/gl3.h>
#else
	#include <GL/glew.h>
#endif
#undef main
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
//#include <AntTweakBar.h>

//#include "Mesh.h"
#include "Simulation.h"

int main(int, char**) {

    SDL_Window* g_window;
    unsigned int windowHeight = 600, windowWidth = 800;
    SDL_GLContext _glContext;
	SDL_Event e;
    SDL_Init(SDL_INIT_EVERYTHING);

    //required to get OpenGL 4.1. this may change
#ifdef __APPLE__
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
#endif

	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 16);

	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

    g_window = SDL_CreateWindow("SolarSim", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_OPENGL);
    _glContext = SDL_GL_CreateContext(g_window);

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,32);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);

	glViewport(0,0,windowWidth,windowHeight);
	glEnable(GL_MULTISAMPLE);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_CULL_FACE);

#ifndef __APPLE__
    glewExperimental = true;
    GLenum err = glewInit();
    if(glewInit() != err) {
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
        exit(1);
    }
    else
        printf("%s\n", glGetString(GL_VERSION));
#else
    printf("%s\n", glGetString(GL_VERSION));
#endif


    glm::mat4 projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 10000.0f);
    glm::mat4 view = glm::lookAt(glm::vec3(0, 50, 50), glm::vec3(0,0,0), glm::vec3(0,1,0));
	glm::mat4 model = glm::mat4();
    GLuint planetShader, sunShader;
	GLuint pviewID, pprojectionID, sviewID, sprojectionID;
    planetShader = LoadShaders("basic.vs", "basic.fs");
	sunShader = LoadShaders("basic.vs", "sun.fs");
    glUseProgram(planetShader);
    pviewID = glGetUniformLocation(planetShader, "view");
    pprojectionID = glGetUniformLocation(planetShader, "projection");
    glUniformMatrix4fv(pviewID, 1 , GL_FALSE, &view[0][0]);
    glUniformMatrix4fv(pprojectionID, 1, GL_FALSE, &projection[0][0]);
	glUseProgram(sunShader);
	sviewID = glGetUniformLocation(sunShader, "view");
    sprojectionID = glGetUniformLocation(sunShader, "projection");
    glUniformMatrix4fv(sviewID, 1 , GL_FALSE, &view[0][0]);
    glUniformMatrix4fv(sprojectionID, 1, GL_FALSE, &projection[0][0]);
	glUseProgram(0);

	Simulation sim = Simulation();
	Planet p = Planet(50, glm::vec3(0,0,0.07), glm::vec3(40,0,0));
	Planet p2 = Planet(5, glm::vec3(0,0,-0.07), glm::vec3(-10,0,0));
	sim.setStar(100000000);
	sim.addPlanet(&p);
	sim.addPlanet(&p2);

    SDL_Event sdlEvent;
    bool isRunning = true;

	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double deltaTime = 0;

    while(isRunning) {
		LAST = NOW;
   		NOW = SDL_GetPerformanceCounter();
   		deltaTime = (double)((NOW - LAST)*1000 / SDL_GetPerformanceFrequency() );

        SDL_PollEvent(&sdlEvent);
        if(sdlEvent.type == SDL_QUIT) {
            isRunning = false;
        }

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		sim.applyForcePhase();
		sim.moveCelestialPhase(deltaTime);
		sim.Draw(planetShader, sunShader);

        SDL_GL_SwapWindow(g_window);
    }

    SDL_Quit();

    return 0;
}
