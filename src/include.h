#ifndef INCLUDE
#define INCLUDE

#define DOUBLE_P

#ifdef DOUBLE_P
typedef glm::dvec3 vec3;
typedef glm::dmat4 mat4;
//typedef float double;
#else
typedef glm::vec3 vec3;
typedef glm::mat4 mat4;
#endif

#endif
