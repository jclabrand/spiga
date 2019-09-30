
/****************************************************************************************

	Spiga Engine.
	Copyright (c) 2019, Juan Carlos Labrandero.
	For conditions of distribution and use, see copyright notice in LICENSE

****************************************************************************************/

#ifndef __spiga_size_hpp__
#define __spiga_size_hpp__

#include <system/types.hpp>

namespace spi {
namespace graphics {

template<typename INTEGER = uint>
	class size
{
public:
	inline size(const INTEGER& value = INTEGER(0)) :
		width(value), height(value)
		{}

	inline size(const INTEGER* values) :
		width(values[0]), height(values[1])
		{}

	inline size(const INTEGER& w, const INTEGER& h) :
		width(w), height(h)
		{}

	inline size(const size& copy) :
		width(copy.width), height(copy.height)
		{}

public:

	inline void set(const INTEGER& w, const INTEGER& h)
		{ width = w, height = h; }

public:

	inline size& operator = (const size& copy)
		{
		if(&copy != this) set(copy.width, copy.height);
		return (*this);
		}

	inline size operator + (const size& s) const
		{ return size(width + s.width, height + s.height); }
	inline size operator + (const INTEGER& n) const
		{ return size(width + n, height + n); }

	inline size operator - (const size& s) const
		{ return size(width - s.width, height - s.height); }
	inline size operator - (const INTEGER& n) const
		{ return size(width - n, height - n); }

	inline size operator * (const size& s) const
		{ return size(width * s.width, height * s.height); }
	inline size operator * (const INTEGER& n) const
		{ return size(width * n, height * n); }

	inline size operator / (const size& s) const
		{ return size(width / s.width, height / s.height); }
	inline size operator / (const INTEGER& n) const
		{ return size(width / n, height / n); }


	inline size& operator += (const size& s)
		{ width += s.width, height += s.height; return *this; }
	inline size& operator += (const INTEGER& n)
		{ width += n, height += n; return *this; }

	inline size& operator -= (const size& s)
		{ width -= s.width, height -= s.height; return *this; }
	inline size& operator -= (const INTEGER& n)
		{ width -= n, height -= n; return *this; }

	inline size& operator *= (const size& s)
		{ width *= s.width, height *= s.height; return *this; }
	inline size& operator *= (const INTEGER& n)
		{ width *= n, height *= n; return *this; }

	inline size& operator /= (const size& s)
		{ width /= s.width, height /= s.height; return *this; }
	inline size& operator /= (const INTEGER& n)
		{ width /= n, height /= n; return *this; }


	inline bool operator == (const size& s) const
		{ return (width == s.width) && (height == s.height); }

	inline bool operator != (const size& s) const
		{ return (width != s.width) || (height != s.height); }

public:

	INTEGER width, height;
};


typedef size<> sizeui;
typedef size<ubyte> sizeub;


} //end spi::graphics namespace
} //end spi namespace

#endif //__spiga_size_hpp__
