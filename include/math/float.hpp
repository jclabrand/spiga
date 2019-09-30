
/****************************************************************************************

	Spiga Engine.
	Copyright (c) 2019, Juan Carlos Labrandero.
	For conditions of distribution and use, see copyright notice in LICENSE

****************************************************************************************/

#ifndef __spiga_float_hpp__
#define __spiga_float_hpp__

#include <math.h>
#include <system/types.hpp>

namespace spi {
namespace math {

#ifndef M_PI
#	define M_2_PI		float(6.283185307179586232)
#	define M_PI			(M_2_PI * float(0.5))
#	define M_PI_2		(M_PI * float(0.5))
#endif

} //end spi::math namespace
} //end spi namespace

#endif //__spiga_float_hpp__
