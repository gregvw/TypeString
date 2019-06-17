#pragma once
#ifndef TYPE_CTS_HPP
#define TYPE_CTS_HPP

namespace TypeString {

template<typename> struct type_cts {
  static constexpr auto value = undefined_type;
};

template<typename T> 
constexpr auto type_cts_v = type_cts<T>::value;

template<typename T>
inline std::string type_string() { return type_cts_v<T>.to_string(); };

template<typename T>
struct type_cts<const T> {
  static constexpr auto value = const_type + type_cts_v<T>;
};

template<typename T>
struct type_cts<volatile T> {
  static constexpr auto value = volatile_type + type_cts_v<T>;
};

template<typename T>
struct type_cts<T*> { static constexpr auto value = type_cts_v<T> + ptr_v; };

template<typename T>
struct type_cts<T&> { static constexpr auto value = type_cts_v<T> + ref_v; };
template<typename T>
struct type_cts<T&&> { static constexpr auto value = type_cts_v<T> + ref_v + ref_v; };



constexpr auto square_brackets = []( auto arg ) { return square_bracket_color + "[" + 
	                                                 arg + 
					                 square_bracket_color + "]" + 
					                 reset_color; };

constexpr auto angle_brackets = []( auto arg ) { return angle_bracket_color + "<" + 
	                                                arg + 
			     		                angle_bracket_color + ">" + 
                                                        reset_color; };

template<typename ReturnType, typename...Args>
struct type_cts<ReturnType(*)(Args...)> {
  static constexpr auto value = type_cts_v<ReturnType> + parenthesis_color + "(" + ptr_v
                                                       + parenthesis_color + ")(" 
                                                       + delimited(comma, type_cts_v<Args>...)
                                                       + parenthesis_color + ")";
};

template<typename T, size_t N>
struct type_cts<T[N]> { static constexpr auto value = type_cts_v<T> + square_brackets( digits_to_cts<N>() ); };


} // namespace TypeString

#endif  // TYPE_CTS_HPP
