
/****************************************************************************************

	Spiga Engine.
	Copyright (c) 2019, Juan Carlos Labrandero.
	For conditions of distribution and use, see copyright notice in LICENSE

****************************************************************************************/

#ifndef __spiga_window_cache_hpp__
#define __spiga_window_cache_hpp__

#include <map>
#include <system/window.hpp>

#if defined(_X11_)
typedef Window WINDOW_ID;

#elif defined(_WINDOWS_)
typedef HWND WINDOW_ID;

#endif

typedef spi::system::window* WINDOW_PTR;

typedef class window_cache : protected std::map<WINDOW_ID, WINDOW_PTR>
{
public:
    inline WINDOW_PTR get_window(WINDOW_ID key) {
		iterator i = find(key);
		return (i != end()) ? i->second : NULL;
		}

	inline bool add_window(WINDOW_ID key, WINDOW_PTR window) {
		if (!key || !window)
			return false;

		value_type val(key, window);
		std::pair<iterator, bool> r = insert(val);
		return r.second;
		}

	inline bool del_window(WINDOW_ID key) {
		size_t s = erase(key);
		return (s > 0) ? true : false;
		}

public:
	static inline window_cache& get() {
static window_cache THE_CACHE;
		return THE_CACHE;
	}

private:
	window_cache();

	virtual ~window_cache();

private:
#if defined(_X11_)

#elif defined(_WINDOWS_)
	WNDCLASSEX	__reg_wcex;
#endif
	bool		__reg_succes;
} WINDOW_CACHE;

#endif //__spiga_window_cache_hpp__
