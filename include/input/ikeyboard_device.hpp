
/****************************************************************************************

	Spiga Engine.
	Copyright (c) 2019, Juan Carlos Labrandero.
	For conditions of distribution and use, see copyright notice in LICENSE

****************************************************************************************/

#ifndef __spiga_ikeyboard_device_hpp__
#define __spiga_ikeyboard_device_hpp__

namespace spi {
namespace input {

class ikeyboard_device
{
public:
	enum key_name
	{
		Empty	= 0,

		Back	= 0x08,

		Enter	= 0x0D,

		Shift	= 0x10,
		Capital	= 0x14,

		Escape	= 0x1B,

		Space	= 0x20,

		Left	= 0x25,
		Up		= 0x26,
		Right	= 0x27,
		Down	= 0x28,

		D0 = 0x30,
		D1 = 0x31,
		D2 = 0x32,
		D3 = 0x33,
		D4 = 0x34,
		D5 = 0x35,
		D6 = 0x36,
		D7 = 0x37,
		D8 = 0x38,
		D9 = 0x39,

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		NumPad0 = 96,
		NumPad1 = 97,
		NumPad2 = 98,
		NumPad3 = 99,
		NumPad4 = 100,
		NumPad5 = 101,
		NumPad6 = 102,
		NumPad7 = 103,
		NumPad8 = 104,
		NumPad9 = 105,

		Multiply = 106,
		Add = 107,
		Separator = 108,
		Subtract = 109,
		Decimal = 110,
		Divide = 111,

		F1,
		F2,
		F3,
		F4,
		F5,
		F6,
		F7,
		F8,
		F9,
		F10,
		F11,
		F12,

		OEM_Comma,
		OEM_Minus,
		OEM_Period
	};

	class ikey
	{
	public:
		virtual key_name	get_name() const = 0;
		virtual wchar_t		get_char() const = 0;

		virtual bool is_pressed() const = 0;
	};

public:
#if defined(_X11_)

#elif defined(_WINDOWS_)
	virtual const ikey& peek_key_down(WPARAM wParam) = 0;
	virtual const ikey& peek_key_up(WPARAM wParam) = 0;
#endif
};

} //end spi::input namespace
} //end spi namespace

#endif //__spiga_ikeyboard_device_hpp__
