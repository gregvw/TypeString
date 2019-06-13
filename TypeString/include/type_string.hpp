#pragma once
#ifndef TYPE_STRING_HPP
#define TYPE_STRING_HPP

#include <cstddef>
#include "preprocessor.hpp"
#include "ct_string.hpp"
#include "colordefs.hpp"

#define FUNDAMENTAL_TYPESTRING( TYPENAME )        \
namespace TypeString {                            \
template<> struct type_cts<TYPENAME>  {           \
  static constexpr auto value = fundamental_color \
                                + QUOTE(TYPENAME) \
                                + reset_color; }; \
} // namespace TypeString

namespace TypeString {

using std::size_t;

template<typename> 
struct type_cts { static constexpr auto value = undefined_type; };




template<typename T> constexpr auto type_cts_v = type_cts<T>::value;

template<typename T>
struct type_cts<T*> { static constexpr auto value = type_cts_v<T> + ptr_v; };

constexpr auto square_brackets = []( auto arg ) { return square_bracket_color + "[" + 
	                                                 arg + 
					                 square_bracket_color + "]" + 
					                 reset_color; };

constexpr auto angle_brackets = []( auto arg ) { return angle_bracket_color + "<" + 
	                                                arg + 
			     		                angle_bracket_color + ">" + 
                                                        reset_color; };

template<typename T, size_t N>
struct type_cts<T[N]> { static constexpr auto value = type_cts_v<T> + square_brackets( digits_to_cts<N>() ); };





template<typename T> 
inline std::string type_string() { return type_cts_v<T>.to_string(); }

} // namespace TypeString

FUNDAMENTAL_TYPESTRING(bool);
FUNDAMENTAL_TYPESTRING(char);
FUNDAMENTAL_TYPESTRING(unsigned int);
FUNDAMENTAL_TYPESTRING(int);
FUNDAMENTAL_TYPESTRING(unsigned long);
FUNDAMENTAL_TYPESTRING(long);
FUNDAMENTAL_TYPESTRING(unsigned long long);
FUNDAMENTAL_TYPESTRING(long long);
FUNDAMENTAL_TYPESTRING(float);
FUNDAMENTAL_TYPESTRING(double);
FUNDAMENTAL_TYPESTRING(long double);
FUNDAMENTAL_TYPESTRING(unsigned char);
FUNDAMENTAL_TYPESTRING(wchar_t);
FUNDAMENTAL_TYPESTRING(char16_t);
FUNDAMENTAL_TYPESTRING(char32_t);


#endif  // TYPE_STRING_HPP
