
/****************************************************************************************

	Spiga Engine.
	Copyright (c) 2019, Juan Carlos Labrandero.
	For conditions of distribution and use, see copyright notice in LICENSE

****************************************************************************************/

#include <sstream>
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

bool window::is_visible() const
{
#if defined(_X11_)

#elif defined(_WINDOWS_)
	if (IsWindow(__id))
		return (IsWindowVisible(__id)) ? true : false;
#endif
	return false;
}

/***************************************************************************************/

bool window::is_open() const
{
#if defined(_X11_)
	return __id ? true : false;
#elif defined(_WINDOWS_)
	return (IsWindow(__id)) ? true : false;
#endif
}

/***************************************************************************************/

void window::set_text(const std::string& text)
{
	std::wstringstream wstr;
	wstr << text.c_str();
	__text = wstr.str();

#if defined(_X11_)
	if(__id) {
	    wchar_t* txt = (wchar_t*)__text.data();
	    XTextProperty tp;
	    XwcTextListToTextProperty(__display, &txt, 1, XStringStyle, &tp);
	    XSetWMName(__display, __id, &tp);
	}
#elif defined(_WINDOWS_)
	if (IsWindow(__id))
#if defined(SPI_SYS_USE_MULTIBYTE_CHAR)
        SetWindowText(__id, text.data());
#else
		SetWindowText(__id, __text.data());
#endif
#endif
}

/***************************************************************************************/

void window::set_text(const std::wstring& text)
{
	__text = text;

#if defined(_X11_)
	if(__id) {
		wchar_t* txt = (wchar_t*)__text.data();
		XTextProperty tp;
		XwcTextListToTextProperty(__display, &txt, 1, XStringStyle, &tp);
		XSetWMName(__display, __id, &tp);
	}
#elif defined(_WINDOWS_)
	if (IsWindow(__id))
#if defined (SPI_SYS_USE_MULTIBYTE_CHAR)
    {
        std::stringstream strs;
        std::string str;
        strs << text.c_str();
        str = strs.str();
        SetWindowText(__id, str.data());
    }
#else
		SetWindowText(__id, __text.data());
#endif
#endif
}

/***************************************************************************************/

void window::set_size(uint width, uint height)
{
	if (__size.width == width && __size.height == height)
		return;

#if defined(_X11_)
	if(__id) {
	    XResizeWindow(__display, __id, width, height);
	}
#elif defined(_WINDOWS_)
	if(IsWindow(__id)) {
		BOOL ret_value = SetWindowPos(
			__id,
			HWND_TOP,			//hWndInsertAfter
			0,					//X
			0,					//Y
			width,
			height,
			SWP_NOMOVE |		//Retains the current position (ignores X and Y parameters)
			SWP_NOZORDER |		//Retains the current Z order (ignores the hWndInsertAfter parameter)
			SWP_NOREDRAW
		);

		if(ret_value)
			UpdateWindow(__id);
	}
#endif
}

/***************************************************************************************/
