
/****************************************************************************************

	Spiga Engine.
	Copyright (c) 2019, Juan Carlos Labrandero.
	For conditions of distribution and use, see copyright notice in LICENSE

****************************************************************************************/

#ifndef __spiga_iwindow_hpp__
#define __spiga_iwindow_hpp__

#include <string>
#include "iwindow_activity.hpp"

namespace spi {
namespace system {

class iwindow : protected iwindow_activity
{
public:
	virtual void close() = 0;
	virtual void show() = 0;
	virtual void hide() = 0;

	virtual bool is_visible() const = 0;
	virtual bool is_open() const = 0;

	virtual const std::wstring&		get_text() const = 0;
	virtual const math::vec2i&		get_location() const = 0;
	virtual const graphics::sizeui&	get_size() const = 0;
	virtual const graphics::sizeui&	get_client_size() const = 0;

	virtual void set_text(const std::string& text) = 0;
	virtual void set_text(const std::wstring& text) = 0;
	virtual void set_size(uint width, uint height) = 0;
	virtual void set_size(const graphics::sizeui& size) = 0;
};

} //end spi::system namespace
} //end spi namespace

#endif //__spiga_iwindow_hpp__
