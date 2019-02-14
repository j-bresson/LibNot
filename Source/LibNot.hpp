/*!
 *  @file       LibNot.hpp
 *  @brief      Library for score display and editing
 *  @author     Jean Bresson
 *  @date       12/02/2019
 */

#ifndef LibNot_hpp
#define LibNot_hpp

#include "Types.h"

#ifdef _MSC_VER
	#define LIBNOT_VISIBILITY_DEFAULT	__declspec( dllexport )
#else
	#define LIBNOT_VISIBILITY_DEFAULT	__attribute__ ((visibility ("default")))
#endif

#ifdef __cplusplus
#define LIBNOT_C_EXPORTS   extern "C"
#else
#define LIBNOT_C_EXPORTS
#endif

#define LIBNOT_API LIBNOT_C_EXPORTS LIBNOT_VISIBILITY_DEFAULT

LIBNOT_API const char* libNotInfo();

LIBNOT_API void* libNotNewEditor();
LIBNOT_API void libNotFreeEditor(void* libNot_editor);

LIBNOT_API void libNotOpenWindow(void* libNot_editor);
LIBNOT_API void libNotCloseWindow(void* libNot_editor);
LIBNOT_API void libNotWindowToFront(void* libNot_editor);
LIBNOT_API void libNotWindowSetName(void* libNot_editor, char *name);

LIBNOT_API void libNotRegisterCloseCallback(void* libNot_editor, lnCloseCallback callback);
LIBNOT_API void libNotRegisterUpdateCallback(void* libNot_editor, lnUpdateCallback callback);

/*
LIBNOT_API int  libNotGetScore(void* libNot_handler);
LIBNOT_API void libNotSetScore(void* libNot_handler, t_osc_bndl_s *bundle);
*/

#endif
