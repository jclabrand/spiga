
/****************************************************************************************

	Spiga Engine.
	Copyright (c) 2019, Juan Carlos Labrandero.
	For conditions of distribution and use, see copyright notice in LICENSE

****************************************************************************************/

#ifndef __spiga_vector2_hpp__
#define __spiga_vector2_hpp__

#include "float.hpp"

namespace spi {
namespace math {

template<typename SCALAR = float>
	class vector2
{
public:

	inline vector2(const SCALAR& value = SCALAR(0))
		: x(value), y(value)
		{}

	inline vector2(const SCALAR& _x, const SCALAR& _y)
		: x(_x), y(_y)
		{}

	inline vector2(const SCALAR* values)
		: x(values[0]), y(values[1])
		{}

	inline vector2(const vector2& copy)
		: x(copy.x), y(copy.y)
		{}

	inline vector2& set(const vector2& copy)
		{ x = copy.x, y = copy.y; return *this; }

	inline vector2& set(const SCALAR& _x, const SCALAR& _y)
		{ x = _x, y = _y; return *this; }

	inline vector2& set(const SCALAR* values)
		{ x = values[0], y = values[1]; return *this; }

	
	inline vector2& normalize()
		{ *this /= length(); return *this; }


	inline SCALAR length() const
		{ return SCALAR(sqrtf(float(x*x + y*y))); }

	inline vector2 normalized() const
		{ return (*this) / length(); }

	inline SCALAR dot(const vector2& v) const
		{ return (x*v.x + y*v.y); }

public:

	static inline SCALAR dot(const vector2& u, const vector2& v)
		{ return (u.x*v.x + u.y*v.y); }

public:

	inline vector2& operator = (const vector2& copy)
		{
		if(&copy != this) { x = copy.x, y = copy.y; }
		return *this;
		}

	inline vector2 operator + (const vector2& u) const
		{ return vector2(x+u.x, y+u.y); }
	inline vector2 operator + (const SCALAR& n) const
		{ return vector2(x+n, y+n); }

	inline vector2 operator - (const vector2& u) const
		{ return vector2(x-u.x, y-u.y); }
	inline vector2 operator - (const SCALAR& n) const
		{ return vector2(x-n, y-n); }

	inline vector2 operator * (const vector2& u) const
		{ return vector2(x*u.x, y*u.y); }
	inline vector2 operator * (const SCALAR& n) const
		{ return vector2(x*n, y*n); }

	inline vector2& operator += (const vector2& v)
		{ x += v.x,	y += v.y; return *this; }
	inline vector2& operator += (const SCALAR& n)
		{ x += n, y += n; return *this; }

	inline vector2& operator -= (const vector2& v)
		{ x -= v.x,	y -= v.y; return *this; }
	inline vector2& operator -= (const SCALAR& n)
		{ x -= n, y -= n; return *this; }

	inline vector2& operator *= (const vector2& v)
		{ x *= v.x,	y *= v.y; return *this; }
	inline vector2& operator *= (const SCALAR& n)
		{ x *= n, y *= n; return *this; }

	inline vector2& operator /= (const vector2& v)
		{ x /= v.x,	y /= v.y; return *this; }
	inline vector2& operator /= (const SCALAR& n)
		{ x /= n, y /= n; return *this; }

	
	inline bool operator == (const vector2& v) const
		{ return (x == v.x) && (y == v.y); }
	inline bool operator == (const SCALAR& n) const
		{ return (x == n) && (y == n); }

	inline bool operator != (const vector2& v) const
		{ return (x != v.x) || (y != v.y); }
	inline bool operator != (const SCALAR& n) const
		{ return (x != n) || (y != n); }

	// Indexing
	inline SCALAR& operator [] (int i)
		{ return v[i]; }

	inline const SCALAR& operator [] (int i) const
		{ return v[i]; }

	// Type-cast
	inline operator SCALAR* ()
		{ return v; }

	inline operator const SCALAR* () const
		{ return v; }

public:
	union {
		struct {
			SCALAR x, y;
		};
		struct {
			SCALAR s, t;
        };
		struct {
			SCALAR first, second;
		};
		SCALAR v[2];
	};
};

typedef vector2<char> vec2b;
typedef vector2<ubyte> vec2ub;
typedef vector2<short> vec2s;
typedef vector2<ushort> vec2us;
typedef vector2<int> vec2i;
typedef vector2<uint> vec2ui;
typedef vector2<> vec2f;
typedef vector2<double> vec2d;

} //end spi::math namespace
} //end spi namespace

#endif //__spiga_vector2_hpp__
