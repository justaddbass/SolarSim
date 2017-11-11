INCLUDE=/usr/include/
LOCAL_INCLUDE=/usr/local/include/
BULLET_INC=/usr/local/include/bullet/
LIB_DIR=/usr/lib/
LOCAL_LIB_DIR=/usr/local/lib/
#GLEW_LIB_DIR=/usr/local/Cellar/glew/2.1.0/lib/
SDL_CFLAGS := $(shell sdl2-config --cflags)
SDL_LIBS := $(shell sdl2-config --libs)
CC=g++
CPPFLAGS=-g -std=c++11 $(SDL_CFLAGS) -I$(INCLUDE) -I$(LOCAL_INCLUDE) -I$(LIB_DIR) -I$(LOCAL_LIB_DIR)
#CPPFLAGS+=-g -O2 -I$(DIR) -I$(LUA_INC) -L$(LUA_LIB)
TARGET = SolarSim

UNIX_LIBS=-lSDL2 -lGL -lGLEW -llua -lassimp
MAC_LIBS=-framework OpenGL $(SDL_LIBS) -llua -lassimp #$(shell pkg-config --libs glew)

OBJ := $(patsubst %.cpp,%.o,$(wildcard src/*.cpp) $(wildcard src/**/*.cpp))
OS := $(shell uname -s)

all: $(TARGET)
ifeq ($(OS),Linux)
LIBS := $(UNIX_LIBS)
endif
ifeq ($(OS),Darwin)
LIBS := $(MAC_LIBS)
endif


$(TARGET): bin $(OBJ)
	$(CC) $(LIBS) $(OBJ) -o bin/$@

bin:
	mkdir -p $@

run:
	bin/$(TARGET)

.PHONY: clean
clean:
	$(RM) $(OBJ)
	$(RM) bin/$(TARGET)
