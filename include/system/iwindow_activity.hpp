
/****************************************************************************************

	Spiga Engine.
	Copyright (c) 2019, Juan Carlos Labrandero.
	For conditions of distribution and use, see copyright notice in LICENSE

****************************************************************************************/

#ifndef __spiga_iwindow_activity_hpp__
#define __spiga_iwindow_activity_hpp__

#include <input/ikeyboard_activity.hpp>
#include <input/imouse_activity.hpp>

#include <graphics/size.hpp>

namespace spi {
namespace system {

class iwindow_activity :
	public input::ikeyboard_activity,
	public input::imouse_activity
{
public:
	virtual void on_load() = 0;
	virtual void on_close() = 0;

	virtual void on_resize(const math::vec2i& location,
		const graphics::sizeui& size, const graphics::sizeui& client) = 0;

	virtual void on_move(const math::vec2i& location,
		const graphics::sizeui& size, const graphics::sizeui& client) = 0;
};

} //end spi::system namespace
} //end spi namespace

#endif //__spiga_iwindow_activity_hpp__
