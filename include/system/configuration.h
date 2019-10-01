
/****************************************************************************************

	Spiga Engine.
	Copyright (c) 2019, Juan Carlos Labrandero.
	For conditions of distribution and use, see copyright notice in LICENSE

****************************************************************************************/

#ifndef __spiga_configuration_h__
#define __spiga_configuration_h__

// Import, Export
#if defined(_WIN32) || defined (_WIN64)
#   define SPI_CALL      __stdcall
#   define SPI_EXPORT    __declspec(dllexport)
#   define SPI_IMPORT    __declspec(dllimport)

#	include <tchar.h>
#	include <windows.h>

#	if !defined(_WINDOWS_)
#		define _WINDOWS_
#	endif // _WINDOWS_

#   if defined(__GNUC__)
#       define SPI_SYS_USE_MULTIBYTE_CHAR
#   endif // __GNUC__

#	if defined (_MSC_VER) && (_MSC_VER >= 1020)
#		pragma warning(disable : 4251)
#	endif

#elif defined(__GNUC__)
#   define SPI_CALL
#   define SPI_EXPORT
#   define SPI_IMPORT

#	include <X11/Xlib.h>
#	include <X11/Xutil.h>

#	ifndef _X11_
#		define _X11_
#	endif // _X11_

typedef void *PVOID;

#else
#   define SPI_CALL
#   define SPI_EXPORT
#   define SPI_IMPORT
#endif

// Core Library
#if defined SPI_CORE_EXPORTS
#   define SPI_CORE_API   SPI_EXPORT
#elif defined SPI_CORE_STATIC
#   define SPI_CORE_API
#else
#   define SPI_CORE_API   SPI_IMPORT
#endif

// Render API
#if defined SPI_RENDER_EXPORTS
#   define SPI_RENDER_API   SPI_EXPORT
#elif defined SPI_RENDER_STATIC
#   define SPI_RENDER_API
#else
#   define SPI_RENDER_API   SPI_IMPORT
#endif

// Controls API
#if defined SPI_CONTROLS_EXPORTS
#   define SPI_CONTROLS_API   SPI_EXPORT
#elif defined SPI_CONTROLS_STATIC
#   define SPI_CONTROLS_API
#else
#   define SPI_CONTROLS_API   SPI_IMPORT
#endif

// User Messages
#if defined(_X11_)

#elif defined(_WINDOWS_)
#	define SPI_APP_FPS (WM_USER + 100)
#endif

#endif //__spiga_configuration_h__
