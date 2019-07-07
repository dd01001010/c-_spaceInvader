#ifndef _glfw3_h_
#define _glfw3_h_

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(_WIN32) && (defined(__WIN32__) || defined(WIN32) || defined(__MINGW32__))
 #define _WIN32
#endif /* _WIN32 */


//use APIENTRY for openGl function pointer declarations, all platforms
#ifndef APIENTRY
 #ifdef _WIN32
  #define APIENTRY __stdcall
 #else
  #define APIENTRY
 #endif
#endif /* APIENTRY */

// (some) windows opengl headers need the following 
#if !defined(WINGDIAPI) && defined(_WIN32)
 #define WINGDIAPI __declspec(dllimport)
 #define GLFW_WINGDIAPI_DEFINED
#endif /* WINGDIAPI */

//some windows glu headers need the following 
#if !defined(CALLBACK) && defined(_WIN32)
 #define CALLBACK __stdcall
 #define GLFW_CALLBACK_DEFINED
#endif /* CALLBACK */

#include <stddef.h>
#include <stdint.h>

//include the chosen client API headers
#if defined(__APPLE__)
 #if defined(GLFW_INCLUDE_GLCOREARB)
  #include <OpenGL/gl3.h>
  #if defined(GLFW_INCLUDE_GLEXT)
   #include <OpenGL/gl3ext.h>
  #endif
 #elif !defined(GLFW_INCLUDE_NONE)
  #if !defined(GLFW_INCLUDE_GLEXT)
   #define GL_GLEXT_LEGACY
  #endif
  #include <OpenGL/gl.h>
 #endif
 #if defined(GLFW_INCLUDE_GLU)
  #include <OpenGL/glu.h>
 #endif
#else
 #if defined(GLFW_INCLUDE_GLCOREARB)
  #include <GL/glcorearb.h>
 #elif defined(GLFW_INCLUDE_ES1)
  #include <GLES/gl.h>
  #if defined(GLFW_INCLUDE_GLEXT)
   #include <GLES/glext.h>
  #endif
 #elif defined(GLFW_INCLUDE_ES2)
  #include <GLES2/gl2.h>
  #if defined(GLFW_INCLUDE_GLEXT)
   #include <GLES2/gl2ext.h>
  #endif
 #elif defined(GLFW_INCLUDE_ES3)
  #include <GLES3/gl3.h>
   #if defined(GLFW_INCLUDE_GLEXT)
   #include <GLES2/gl2ext.h>
  #endif
 #elif defined(GLFW_INCLUDE_ES31)
  #include <GLES3/gl31.h>
  #if defined(GLFW_INCLUDE_GLEXT)
   #include <GLES2/gl2ext.h>
  #endif
 #elif defined(GLFW_INCLUDE_VULKAN)
  #include <vulkan/vulkan.h>
 #elif !defined(GLFW_INCLUDE_NONE)
  #include <GL/gl.h>
  #if defined(GLFW_INCLUDE_GLEXT)
   #include <GL/glext.h>
  #endif
 #endif
 #if defined(GLFW_INCLUDE_GLU)
  #include <GL/glu.h>
 #endif
#endif

#if defined(GLFW_DLL) && defined(_GLFW_BUILD_DLL)
//config header application when compiling DLL-vers library
#error "You must not have both GLFW_DLL and _GLFW_BUILD_DLL defined"
#endif

//used to declare public API funct when export in DLL, shared library,dynamic library 
#if defined(_WIN32) && defined(_GLFW_BUILD_DLL)
 /* We are building GLFW as a Win32 DLL */
 #define GLFWAPI __declspec(dllexport)
#elif defined(_WIN32) && defined(GLFW_DLL)
 /* We are calling GLFW as a Win32 DLL */
 #define GLFWAPI __declspec(dllimport)
#elif defined(__GNUC__) && defined(_GLFW_BUILD_DLL)
 /* We are building GLFW as a shared / dynamic library */
 #define GLFWAPI __attribute__((visibility("default")))
#else
 /* We are building or calling GLFW as a static library */
 #define GLFWAPI
#endif

#define GLFW_VERSION_MAJOR          3
#define GLFW_VERSION_MINOR          2
#define GLFW_VERSION_REVISION       1
#define GLFW_TRUE                   1
#define GLFW_FALSE                  0
#define GLFW_FALSE                  0
#define GLFW_PRESS                  1
#define GLFW_REPEAT                 2

