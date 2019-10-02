
/****************************************************************************************

	Spiga Engine.
	Copyright (c) 2019, Juan Carlos Labrandero.
	For conditions of distribution and use, see copyright notice in LICENSE

****************************************************************************************/

#ifndef __spiga_mouse_event_listener_hpp__
#define __spiga_mouse_event_listener_hpp__

#include <system/event.hpp>
#include "imouse_device.hpp"

namespace spi {
namespace input {

class mouse_move_listener :
	public listener<const math::vec2i&, const math::vec2i&>
{
public:
	inline mouse_move_listener(void(*fdelegate)(const math::vec2i&, const math::vec2i&)) : listener(fdelegate) {}

	template<typename DELEGATE>
	inline mouse_move_listener(DELEGATE& mdelegate, void (DELEGATE::*func)(const math::vec2i&, const math::vec2i&))
		: listener(mdelegate, func) {}

	inline virtual void move(const math::vec2i& position, const math::vec2i& delta) { (*this)(position, delta); }

protected:
	inline mouse_move_listener() {}
};

class mouse_wheel_listener :
	public listener<const math::vec2i&, const short>
{
public:
	inline mouse_wheel_listener(void(*fdelegate)(const math::vec2i&, short)) : listener(fdelegate) {}

	template<typename DELEGATE>
	inline mouse_wheel_listener(DELEGATE& mdelegate, void (DELEGATE::*func)(const math::vec2i&, const short))
		: listener(mdelegate, func) {}

	inline virtual void wheel(const math::vec2i& position, const short delta) { (*this)(position, delta); }

protected:
	inline mouse_wheel_listener() {}
};

class mouse_button_listener :
	public listener<const math::vec2i&, const imouse_device::ibutton&>
{
public:
	inline mouse_button_listener(void(*fdelegate)(const math::vec2i&, const imouse_device::ibutton&)) : listener(fdelegate) {}

	template<typename DELEGATE>
	inline mouse_button_listener(DELEGATE& mdelegate, void (DELEGATE::*func)(const math::vec2i&, const imouse_device::ibutton&))
		: listener(mdelegate, func) {}

	inline virtual void button_press(const math::vec2i& pos, const imouse_device::ibutton& btn) { (*this)(pos, btn); }
	inline virtual void button_release(const math::vec2i& pos, const imouse_device::ibutton& btn) { (*this)(pos, btn); }

protected:
	inline mouse_button_listener() {}
};

class mouse_event_listener :
	public mouse_move_listener, public mouse_wheel_listener, public mouse_button_listener
{
protected:
	inline mouse_event_listener() {}
};

} //end spi::input namespace
} //end spi namespace

#endif //__spiga_mouse_event_listener_hpp__
