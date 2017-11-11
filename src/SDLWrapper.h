#pragma once

#include <SDL2/SDL.h>
#include <cstdio>

namespace SDLWrapper {

struct SDLInfo {
    SDL_Window* window;
    //unsigned int windowHeight = 600, windowWidth = 800;
    SDL_GLContext glContext;
    SDL_Event e;
};

SDLInfo sdlInfo;

    void Init(int width, int height, const char* title) {

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

        sdlInfo.window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
        sdlInfo.glContext = SDL_GL_CreateContext(sdlInfo.window);

        SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,32);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,32);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);

        glViewport(0,0, width, height);
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
    }

    void swapBuffer() {
        SDL_GL_SwapWindow(sdlInfo.window);
    }

}
