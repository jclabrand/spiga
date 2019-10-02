
/****************************************************************************************

	Spiga Engine.
	Copyright (c) 2019, Juan Carlos Labrandero.
	For conditions of distribution and use, see copyright notice in LICENSE

****************************************************************************************/

#ifndef __spiga_mouse_event_hpp__
#define __spiga_mouse_event_hpp__

#include "mouse_event_listener.hpp"

namespace spi {
namespace input {

class mouse_move_event : public event<mouse_move_listener>
{
public:
	inline virtual void execute_move(const math::vec2i& position, const math::vec2i& delta)
		{ for (auto me : (*this)) me->move(position, delta); }
};

class mouse_wheel_event : public event<mouse_wheel_listener>
{
public:
	inline virtual void execute_wheel(const math::vec2i& position, const short delta)
		{ for (auto me : (*this)) me->wheel(position, delta); }
};

class mouse_button_event : public event<mouse_button_listener>
{
public:
	inline virtual void execute_button_press(const math::vec2i& pos, const imouse_device::ibutton& btn)
		{ for (auto me : (*this)) me->button_press(pos, btn); }

	inline virtual void execute_button_release(const math::vec2i& pos, const imouse_device::ibutton& btn)
		{ for (auto me : (*this)) me->button_release(pos, btn); }
};

} //end spi::input namespace
} //end spi namespace

#endif //__spiga_mouse_event_hpp__
