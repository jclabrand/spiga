
/****************************************************************************************

	Spiga Engine.
	Copyright (c) 2019, Juan Carlos Labrandero.
	For conditions of distribution and use, see copyright notice in LICENSE

****************************************************************************************/

#ifndef __spiga_window_hpp__
#define __spiga_window_hpp__

#include "window_event.hpp"

namespace spi {
namespace system {

class SPI_CORE_API window : public iwindow
{
public:
	window();
	virtual ~window();

	virtual void close();
	virtual void show();
	virtual void hide();

	virtual bool is_visible() const;

	virtual bool is_open() const;


	virtual inline const std::wstring& get_text() const { return __text; }

	virtual inline const math::vec2i&	get_location() const { return __location; }

	virtual inline const graphics::sizeui& get_size() const { return __size; }

	virtual inline const graphics::sizeui&	get_client_size() const { return __client_size; }
	

	virtual void set_text(const std::string& text);
	virtual void set_text(const std::wstring& text);
	virtual void set_size(uint width, uint height);

	virtual inline void set_size(const graphics::sizeui& size) { set_size(size.width, size.height); }

public:
#if defined(_X11_)
	static bool check_event(XEvent& event);

#elif defined(_WINDOWS_)
	virtual void poll_event(MSG* lpMsg);
	virtual bool check_event(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam);
#endif

public:
	window_event	loading,
					closing;

	window_size_event	resize,
						move;

	window_keyboard_event	keyboard_key_down,
							keyboard_key_up;

	window_mouse_move_event		mouse_move;
	window_mouse_wheel_event	mouse_wheel;
	window_mouse_button_event	mouse_button_press,
								mouse_button_release;

protected:
	virtual void on_load();
	virtual void on_close();

	virtual void on_resize(const math::vec2i&, const graphics::sizeui&, const graphics::sizeui&);
	virtual void on_move(const math::vec2i&, const graphics::sizeui&, const graphics::sizeui&);

	virtual void on_keyboard_key_down(const input::ikeyboard_device::ikey&);
	virtual void on_keyboard_key_up(const input::ikeyboard_device::ikey&);

	virtual void on_mouse_move(const math::vec2i&, const math::vec2i&);
	virtual void on_mouse_wheel(const math::vec2i&, const short);
	virtual void on_mouse_button_press(const math::vec2i&, const input::imouse_device::ibutton&);
	virtual void on_mouse_button_release(const math::vec2i&, const input::imouse_device::ibutton&);

protected:

#if defined(_X11_)
	Window		__id;
	Display*	__display;
	Atom		__wm_delete_window;
#elif defined(_WINDOWS_)
	HINSTANCE	__instance;
	HWND 		__id;
#endif

	std::wstring		__text;
	math::vec2i			__location;
	graphics::sizeui	__size,
						__client_size;
};

} //end spi::system namespace
} //end spi namespace

#endif //__spiga_window_hpp__
