
/****************************************************************************************

	Spiga Engine.
	Copyright (c) 2019, Juan Carlos Labrandero.
	For conditions of distribution and use, see copyright notice in LICENSE

****************************************************************************************/

#include "window_cache.hpp";

using namespace spi::system;

/***************************************************************************************/

window_cache::window_cache() :
	__reg_succes(false)
{
#if defined(_WINDOWS_)
	__reg_wcex.cbSize = sizeof(WNDCLASSEX);
	__reg_wcex.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	__reg_wcex.lpfnWndProc = spi_window_proc;
	__reg_wcex.cbClsExtra = 0;
	__reg_wcex.cbWndExtra = 0;
	__reg_wcex.hInstance = application::get_instance();
	__reg_wcex.hIcon = NULL;
	__reg_wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	__reg_wcex.hbrBackground = (HBRUSH)(COLOR_WINDOWFRAME);
	__reg_wcex.lpszMenuName = NULL;
	__reg_wcex.lpszClassName = _T("SPI_WFCN");
	__reg_wcex.hIconSm = NULL;

	if (RegisterClassEx(&__reg_wcex))
		__reg_succes = true;
#endif
}

/***************************************************************************************/

window_cache::~window_cache() {
#if defined(_WINDOWS_)
	if (__reg_succes) {
		if (UnregisterClass(__reg_wcex.lpszClassName, __reg_wcex.hInstance))
			__reg_succes = false;
	}
#endif
}

/***************************************************************************************/
