#pragma once

#ifndef BUILD_MACRO
#define BUILD_MACRO

#ifdef CMAKE_INTDIR // variable used ONLY in Visual Studio build system.
	#ifdef VSDEBUG
		#define BUILD_TYPE_VSDEBUG 1
	#endif // VSDEBUG
#endif // CMAKE_INTDIR

#endif // !BUILD_MACRO
