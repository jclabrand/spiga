
/****************************************************************************************

	Spiga Engine.
	Copyright (c) 2019, Juan Carlos Labrandero.
	For conditions of distribution and use, see copyright notice in LICENSE

****************************************************************************************/

#ifndef __spiga_window_event_listener_hpp__
#define __spiga_window_event_listener_hpp__

#include "event.hpp"
#include "iwindow.hpp"

namespace spi {
namespace system {

class window_size_listener :
	public listener<iwindow&, const math::vec2i&, const graphics::sizeui&, const graphics::sizeui&>
{
public:
	inline window_size_listener(void(*fdelegate)(iwindow&, const math::vec2i&, const graphics::sizeui&, const graphics::sizeui&))
		: listener(fdelegate) {}

	template<typename Delegate>
	inline window_size_listener(Delegate& mdelegate, void (Delegate::*func)(iwindow&, const math::vec2i&, const graphics::sizeui&, const graphics::sizeui&))
		: listener(mdelegate, func) {}

	inline virtual void resize(iwindow& wnd, const math::vec2i& location, const graphics::sizeui& size, const graphics::sizeui& client)
		{ (*this)(wnd, location, size, client); }
	inline virtual void move(iwindow& wnd, const math::vec2i& location, const graphics::sizeui& size, const graphics::sizeui& client)
		{ (*this)(wnd, location, size, client); }

protected:
	inline window_size_listener() {}
};

class window_keyboard_listener :
	public listener<iwindow&, const input::ikeyboard_device::ikey&>
{
public:
	inline window_keyboard_listener(void(*fdelegate)(iwindow&, const input::ikeyboard_device::ikey&))
		: listener(fdelegate)
		{}

	template<typename DELEGATE>
	inline window_keyboard_listener(DELEGATE& mdelegate, void (DELEGATE::*func)(iwindow&, const input::ikeyboard_device::ikey&))
		: listener(mdelegate, func)
		{}

	inline virtual void window_keyboard_key_down(iwindow& wnd, const input::ikeyboard_device::ikey& key)
		{ (*this)(wnd, key); }
	inline virtual void window_keyboard_key_up(iwindow& wnd, const input::ikeyboard_device::ikey& key)
		{ (*this)(wnd, key); }

protected:
	inline window_keyboard_listener()
		{}
};

class window_mouse_move_listener :
	public listener<iwindow&, const math::vec2i&, const math::vec2i&>
{
public:
	inline window_mouse_move_listener(void(*fdelegate)(iwindow&, const math::vec2i&, const math::vec2i&))
		: listener(fdelegate) {}

	template<typename Delegate>
	inline window_mouse_move_listener(Delegate& mdelegate, void (Delegate::*func)(iwindow&, const math::vec2i&, const math::vec2i&))
		: listener(mdelegate, func) {}

	inline virtual void window_mouse_move(iwindow& wnd, const math::vec2i& position, const math::vec2i& delta)
		{ (*this)(wnd, position, delta); }

protected:
	inline window_mouse_move_listener() {}
};

class window_mouse_wheel_listener :
	public listener<iwindow&, const math::vec2i&, const short>
{
public:
	inline window_mouse_wheel_listener(void(*fdelegate)(iwindow&, const math::vec2i&, const short))
		: listener(fdelegate) {}

	template<typename Delegate>
	inline window_mouse_wheel_listener(Delegate& mdelegate, void (Delegate::*func)(iwindow&, const math::vec2i&, const short))
		: listener(mdelegate, func) {}

	inline virtual void window_mouse_wheel(iwindow& wnd, const math::vec2i& position, const short delta)
		{ (*this)(wnd, position, delta); }

protected:
	inline window_mouse_wheel_listener() {}
};

class window_mouse_button_listener :
	public listener<iwindow&, const math::vec2i&, const input::imouse_device::ibutton&>
{
public:
	inline window_mouse_button_listener(void(*fdelegate)(iwindow&, const math::vec2i&, const input::imouse_device::ibutton&))
		: listener(fdelegate) {}

	template<typename DELEGATE>
	inline window_mouse_button_listener(DELEGATE& mdelegate, void (DELEGATE::*func)(iwindow&, const math::vec2i&, const input::imouse_device::ibutton&))
		: listener(mdelegate, func) {}

	inline virtual void window_mouse_button_press(iwindow& wnd, const math::vec2i& pos, const input::imouse_device::ibutton& btn)
		{ (*this)(wnd, pos, btn); }
	inline virtual void window_mouse_button_release(iwindow& wnd, const math::vec2i& pos, const input::imouse_device::ibutton& btn)
		{ (*this)(wnd, pos, btn); }

protected:
	inline window_mouse_button_listener() {}
};

class window_event_listener : public listener<iwindow&>
{
public:
	inline window_event_listener(void(*fdelegate)(iwindow&)) : listener(fdelegate) {}

	template<typename Delegate>
	inline window_event_listener(Delegate& mdelegate, void (Delegate::*func)(iwindow&))
		: listener(mdelegate, func) {}

	inline virtual void loading(iwindow& wnd) { (*this)(wnd); }
	inline virtual void closing(iwindow& wnd) { (*this)(wnd); }

protected:
	inline window_event_listener() {}
};

} //end spi::system namespace
} //end spi namespace

#endif //__spiga_window_event_listener_hpp__
