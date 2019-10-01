
/****************************************************************************************

	Spiga Engine.
	Copyright (c) 2019, Juan Carlos Labrandero.
	For conditions of distribution and use, see copyright notice in LICENSE

****************************************************************************************/

#ifndef __spiga_keyboard_event_listener_hpp__
#define __spiga_keyboard_event_listener_hpp__

#include <system/event.hpp>
#include "ikeyboard_device.hpp"

namespace spi {
namespace input {

class keyboard_event_listener : public listener<const ikeyboard_device::ikey&>
{
public:
	inline keyboard_event_listener(void(*fdelegate)(const ikeyboard_device::ikey&))
		: listener(fdelegate)
		{}

	template<typename DELEGATE>
	inline keyboard_event_listener(DELEGATE& mdelegate, void (DELEGATE::*func)(const ikeyboard_device::ikey&))
		: listener(mdelegate, func)
		{}

	inline virtual void keyboard_key_down(const ikeyboard_device::ikey& key)
		{ (*this)(key); }
	inline virtual void keyboard_key_up(const ikeyboard_device::ikey& key)
		{ (*this)(key); }

protected:
	inline keyboard_event_listener()
		{}
};

} //end spi::io namespace
} //end spi namespace

#endif //__spiga_keyboard_event_listener_hpp__
