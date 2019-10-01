
/****************************************************************************************

	Spiga Engine.
	Copyright (c) 2019, Juan Carlos Labrandero.
	For conditions of distribution and use, see copyright notice in LICENSE

****************************************************************************************/

#ifndef __spiga_event_hpp__
#define __spiga_event_hpp__

#include <list>

namespace spi {

template <typename LISTENER>
	class event : public std::list<LISTENER*>
{
public:
	inline event() {}

	inline virtual ~event() {}

	inline void push_copy(const LISTENER& listener) { __cache.push_back(listener), this->push_back(&__cache.back()); }

	inline void push_reference(LISTENER& listener) { this->push_back(&listener); }

public:
	inline virtual event& operator += (const LISTENER& listener) { __cache.push_back(listener), this->push_back(&__cache.back()); return (*this); }

	inline virtual event& operator << (LISTENER& listener) { this->push_back(&listener); return (*this); }

protected:
	std::list<LISTENER>	__cache;
};

} //end spi namespace

#include "listener.hpp"

#endif //__spiga_event_hpp__
