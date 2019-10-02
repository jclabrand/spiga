
/****************************************************************************************

	Spiga Engine.
	Copyright (c) 2019, Juan Carlos Labrandero.
	For conditions of distribution and use, see copyright notice in LICENSE

****************************************************************************************/

#ifndef __spiga_window_event_hpp__
#define __spiga_window_event_hpp__

#include "window_event_listener.hpp"

namespace spi {
namespace system {

class window_size_event : public event<window_size_listener>
{
public:
	inline virtual void execute_resize(iwindow& wnd, const math::vec2i& location, const graphics::sizeui& size, const graphics::sizeui& client)
		{ for (auto we : (*this)) we->resize(wnd, location, size, client); }

	inline virtual void execute_move(iwindow& wnd, const math::vec2i& location, const graphics::sizeui& size, const graphics::sizeui& client)
		{ for (auto we : (*this)) we->move(wnd, location, size, client); }
};

class window_keyboard_event : public event<window_keyboard_listener>
{
public:
	inline virtual void execute_key_down(iwindow& wnd, const input::ikeyboard_device::ikey& key)
		{ for (auto we : (*this)) we->window_keyboard_key_down(wnd, key); }

	inline virtual void execute_key_up(iwindow& wnd, const input::ikeyboard_device::ikey& key)
		{ for (auto we : (*this)) we->window_keyboard_key_up(wnd, key); }
};

class window_mouse_move_event : public event<window_mouse_move_listener>
{
public:
	inline virtual void execute_mouse_move(iwindow& wnd, const math::vec2i& position, const math::vec2i& delta)
		{ for (auto we : (*this)) we->window_mouse_move(wnd, position, delta); }
};

class window_mouse_wheel_event : public event<window_mouse_wheel_listener>
{
public:
	inline virtual void execute_mouse_wheel(iwindow& wnd, const math::vec2i& position, const short delta)
		{ for (auto we : (*this)) we->window_mouse_wheel(wnd, position, delta); }
};

class window_mouse_button_event : public event<window_mouse_button_listener>
{
public:
	inline virtual void execute_mouse_button_press(iwindow& wnd, const math::vec2i& pos, const input::imouse_device::ibutton& btn)
		{ for (auto we : (*this)) we->window_mouse_button_press(wnd, pos, btn); }

	inline virtual void execute_mouse_button_release(iwindow& wnd, const math::vec2i& pos, const input::imouse_device::ibutton& btn)
		{ for (auto we : (*this)) we->window_mouse_button_release(wnd, pos, btn); }
};

class window_event : public event<window_event_listener>
{
public:
	inline virtual void execute_loading(iwindow& wnd) { for (auto we : (*this)) we->loading(wnd); }

	inline virtual void execute_closing(iwindow& wnd) { for (auto we : (*this)) we->closing(wnd); }
};

} //end spi::system namespace
} //end spi namespace

#endif //__spiga_window_event_hpp__
