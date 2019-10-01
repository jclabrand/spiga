
/****************************************************************************************

	Spiga Engine.
	Copyright (c) 2019, Juan Carlos Labrandero.
	For conditions of distribution and use, see copyright notice in LICENSE

****************************************************************************************/

#ifndef __spiga_ikeyboard_activity_hpp__
#define __spiga_ikeyboard_activity_hpp__

#include "ikeyboard_device.hpp"

namespace spi {
namespace input {

class ikeyboard_activity
{
public:
	virtual void on_keyboard_key_down(const ikeyboard_device::ikey&) = 0;
	virtual void on_keyboard_key_up(const ikeyboard_device::ikey&) = 0;
};

} //end spi::input namespace
} //end spi namespace

#endif //__spiga_ikeyboard_activity_hpp__
