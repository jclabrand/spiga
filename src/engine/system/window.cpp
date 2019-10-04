
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
