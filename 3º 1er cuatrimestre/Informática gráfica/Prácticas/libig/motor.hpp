#ifndef PRACTICAS_MOTOR
#define PRACTICAS_MOTOR

/* #ifdef LINUX */
   #include <GL/glew.h>
   #include <GL/glu.h>
   #include <GL/glut.h>
/* #endif */

#ifdef MACOS
   #include <GLUT/glut.h>
   #include <OpenGL/GL.h>
   #include <OpenGL/glu.h>
   #pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

#ifdef _WIN32
   #include <windows.h>
#endif

#endif
