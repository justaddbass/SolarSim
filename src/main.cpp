#ifdef __APPLE__
    #include <OpenGL/gl3.h>
#else
    #include <GL/glew.h>
#endif
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>

#include "Simulation.h"
#include "SDLWrapper.h"
#include "camera.h"

int main(int, char**) {

	SDLWrapper::Init(800, 600, "SolarSim");

	camera cam = camera();

    GLuint planetShader, sunShader;
    planetShader = LoadShaders("basic.vs", "basic.fs");
	sunShader = LoadShaders("basic.vs", "sun.fs");
	glUniformMatrix4fv(glGetUniformLocation(planetShader, "projection"), 1, GL_FALSE, &cam.projection[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(sunShader, "projection"), 1, GL_FALSE, &cam.projection[0][0]);

	Simulation sim = Simulation(&cam);
	Celestial planet1 = Celestial(50, 2.0, glm::vec3(0,0,0.05), glm::vec3(30,0,0), planetShader, &cam);
	Celestial planet2 = Celestial(25, 1.0, glm::vec3(0,0,-0.05), glm::vec3(-20,0,0), planetShader, &cam);
	Celestial sun1 = Celestial(1000000.0, 3.0, glm::vec3(0.0), glm::vec3(0.0), sunShader, &cam);
	sim.addCelestial(&planet1);
	sim.addCelestial(&planet2);
	sim.addCelestial(&sun1);
	sim.setCameraFollow(&sun1);

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
		sim.Draw();

		SDLWrapper::swapBuffer();
    }

    SDL_Quit();

    return 0;
}
