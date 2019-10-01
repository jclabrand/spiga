
/****************************************************************************************

	Spiga Engine.
	Copyright (c) 2019, Juan Carlos Labrandero.
	For conditions of distribution and use, see copyright notice in LICENSE

****************************************************************************************/

#ifndef __spiga_keyboard_event_hpp__
#define __spiga_keyboard_event_hpp__

#include "keyboard_event_listener.hpp"

namespace spi {
namespace input {

class keyboard_event : public event<keyboard_event_listener>
{
public:
	inline virtual void execute_key_down(const ikeyboard_device::ikey& key)
		{ for (auto ke : (*this)) ke->keyboard_key_down(key); }

	inline virtual void execute_key_up(const ikeyboard_device::ikey& key)
		{ for (auto ke : (*this)) ke->keyboard_key_up(key); }
};

} //end spi::io namespace
} //end spi namespace

#endif //__spiga_keyboard_event_hpp__
