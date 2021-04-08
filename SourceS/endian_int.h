#pragma once

namespace devilution {

template <class T>
T SwapLE(T in)
{
	static_assert((sizeof(T) == 1) || (sizeof(T) == 2) ||
	              (sizeof(T) == 4) || (sizeof(T) == 8),
	              "SwapLE called for unsupported size");
	switch (sizeof(T)) {
	case 1:
		return in;
	case 2:
		return static_cast<T>(SDL_SwapLE16(static_cast<Uint16>(in)));
	case 4:
		return static_cast<T>(SDL_SwapLE32(static_cast<Uint32>(in)));
	case 8:
		return static_cast<T>(SDL_SwapLE64(static_cast<Uint64>(in)));
	}
}

template <class T>
T SwapBE(T in)
{
	static_assert((sizeof(T) == 1) || (sizeof(T) == 2) ||
	              (sizeof(T) == 4) || (sizeof(T) == 8),
	              "SwapBE called for unsupported size");
	switch (sizeof(T)) {
	case 1:
		return in;
	case 2:
		return static_cast<T>(SDL_SwapBE16(static_cast<Uint16>(in)));
	case 4:
		return static_cast<T>(SDL_SwapBE32(static_cast<Uint32>(in)));
	case 8:
		return static_cast<T>(SDL_SwapBE64(static_cast<Uint64>(in)));
	}
}

template <class T, T (*f)(T)>
class endian_int {
	T value;

public:
	endian_int() :
		value(0)
	{
	}

	endian_int(const endian_int<T, f>& in) :
		value(in.value)
	{
	}

	endian_int(const T& in) :
		value(f(in))
	{
	}

	endian_int<T, f>& operator=(const endian_int<T, f>& in)
	{
		value = in.value;
		return *this;
	}

	endian_int<T, f>& operator=(const T& in)
	{
		value = f(in);
		return *this;
	}

	endian_int<T, f>& operator-=(const T& in)
	{
		value = f(f(value) - in);
		return *this;
	}

	endian_int<T, f>& operator+=(const T& in)
	{
		value = f(f(value) + in);
		return *this;
	}

	operator T() const
	{
		return f(value);
	}
};

typedef endian_int<Uint16, SwapBE> Uint16_BE;
typedef endian_int<Uint32, SwapBE> Uint32_BE;
typedef endian_int<Uint64, SwapBE> Uint64_BE;
typedef endian_int<Sint16, SwapBE> Sint16_BE;
typedef endian_int<Sint32, SwapBE> Sint32_BE;
typedef endian_int<Sint64, SwapBE> Sint64_BE;

typedef endian_int<Uint16, SwapLE> Uint16_LE;
typedef endian_int<Uint32, SwapLE> Uint32_LE;
typedef endian_int<Uint64, SwapLE> Uint64_LE;
typedef endian_int<Sint16, SwapLE> Sint16_LE;
typedef endian_int<Sint32, SwapLE> Sint32_LE;
typedef endian_int<Sint64, SwapLE> Sint64_LE;

typedef Uint16_BE Uint16_NET;
typedef Uint32_BE Uint32_NET;
typedef Uint64_BE Uint64_NET;
typedef Sint16_BE Sint16_NET;
typedef Sint32_BE Sint32_NET;
typedef Sint64_BE Sint64_NET;

}
