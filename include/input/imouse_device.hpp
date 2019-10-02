
/****************************************************************************************

	Spiga Engine.
	Copyright (c) 2019, Juan Carlos Labrandero.
	For conditions of distribution and use, see copyright notice in LICENSE

****************************************************************************************/

#ifndef __spiga_imouse_device_hpp__
#define __spiga_imouse_device_hpp__

#include <math/vector2.hpp>

namespace spi {
namespace input {

class imouse_device
{
public:
	enum button_name {
		Unknown = 0,
		Left = 1048576,
		Right = 2097152,
		Middle = 4194304,
		XButton1 = 8388608,
		XButton2 = 16777216
	};

	enum cursor_name {
		No = 32648,
		Arrow = 32512,
		Cross = 32515,
		Hand = 32649,
		Help = 32651,
		SizeALL = 32646,
		SizeNESW = 32643,
		SizeNS = 32645,
		SizeNWSE = 32642,
		SizeWE = 32644,
		UpArrow = 32516,
		Wait = 32514
	};

	class ibutton
	{
	public:
		virtual button_name get_name() const = 0;
		virtual bool is_pressed() const = 0;
	};

public:
#if defined(_X11_)

#elif defined(_WINDOWS_)
	virtual const math::vec2i	peek_move() = 0;
	virtual const short			peek_wheel(WPARAM wParam) = 0;
	virtual const ibutton&		peek_button_press(UINT msg, WPARAM wParam) = 0;
	virtual const ibutton&		peek_button_release(UINT msg, WPARAM wParam) = 0;
#endif

public:
	virtual void on_move(const math::vec2i) = 0;
	virtual void on_wheel(const short) = 0;
	virtual void on_button_press(const ibutton& button) = 0;
	virtual void on_button_release(const ibutton& button) = 0;

	virtual void on_set_cursor() = 0;
};

} //end spi::input namespace
} //end spi namespace

#endif //__spiga_imouse_device_hpp__
