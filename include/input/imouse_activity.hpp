
/****************************************************************************************

	Spiga Engine.
	Copyright (c) 2019, Juan Carlos Labrandero.
	For conditions of distribution and use, see copyright notice in LICENSE

****************************************************************************************/

#ifndef __spiga_imouse_activity_hpp__
#define __spiga_imouse_activity_hpp__

#include "imouse_device.hpp"

namespace spi {
namespace input {

class imouse_activity
{
public:
	virtual void on_mouse_move(const math::vec2i&, const math::vec2i&) = 0;

	virtual void on_mouse_wheel(const math::vec2i&, const short) = 0;

	virtual void on_mouse_button_press(const math::vec2i&, const imouse_device::ibutton&) = 0;
	virtual void on_mouse_button_release(const math::vec2i&, const imouse_device::ibutton&) = 0;
};

} //end spi::input namespace
} //end spi namespace

#endif //__spiga_imouse_activity_hpp__
