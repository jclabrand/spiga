
/****************************************************************************************

	Spiga Engine.
	Copyright (c) 2019, Juan Carlos Labrandero.
	For conditions of distribution and use, see copyright notice in LICENSE

****************************************************************************************/

#include <system/window.hpp>

using namespace spi::system;

/***************************************************************************************/

window::window() :
    __id(0)
#if defined(_X11_)
    ,
	__display(NULL)
#elif defined(_WINDOWS_)

#endif
{
#if defined(_X11_)

#elif defined(_WINDOWS_)

#endif
}

/***************************************************************************************/

window::~window()
{
#if defined(_X11_)

#elif defined(_WINDOWS_)

#endif
}

/***************************************************************************************/

void window::close()
{
#if defined(_X11_)
	if(__id) {
		on_close();
		XDestroyWindow(__display, __id);
		__id = 0;
		
		XFlush(__display);
		XSync(__display, 0);
	}
#elif defined(_WINDOWS_)
	if (IsWindow(__id)) {
		on_close();
		DestroyWindow(__id);
		__id = NULL;
	}
#endif
}

/***************************************************************************************/

void window::show()
{
#if defined(_X11_)
	if (__id) {
		XMapWindow(__display, __id);
	}
#elif defined(_WINDOWS_)
	if (IsWindow(__id)) {
		if (!ShowWindow(__id, SW_SHOW)) //If the window was previously hidden, the return value is zero.
			UpdateWindow(__id);
	}
#endif
}

/***************************************************************************************/

void window::hide()
{
#if defined(_X11_)
	if (__id) {
		XUnmapWindow(__display, __id);
	}
#elif defined(_WINDOWS_)
	if (IsWindow(__id))
		ShowWindow(__id, SW_HIDE);
#endif
}

/***************************************************************************************/
