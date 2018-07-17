#pragma once
#ifndef DIGITSTRING_HPP
#define DIGITSTRING_HPP

#include "StaticString.hpp"

using std::size_t;

template<size_t N>
struct OnePlusE { static constexpr size_t value = 10*OnePlusE<N-1>::value;};
template<> struct OnePlusE<0> { static constexpr size_t value = 1; };

template<size_t N>
constexpr size_t num_digits() { return N < 10 ? 1 : 1 + num_digits<N/10>(); }

template<size_t Number> struct SplitNumber {
  static constexpr size_t digits = num_digits<Number>(); 
  static constexpr size_t first  = Number/OnePlusE<digits-1>::value;
  static constexpr size_t rest   = Number-(OnePlusE<digits-1>::value*first); 
};

template<size_t N> 
constexpr size_t digit_first() { return SplitNumber<N>::first; }

template<size_t N>
constexpr size_t digit_rest() { return SplitNumber<N>::rest; }
template<size_t> struct DigitString { static constexpr StaticString<1> value{'\0'}; };

template<> struct DigitString<0> { static constexpr auto value{'0'}; };
template<> struct DigitString<1> { static constexpr auto value{'1'}; };
template<> struct DigitString<2> { static constexpr auto value{'2'}; };
template<> struct DigitString<3> { static constexpr auto value{'3'}; };
template<> struct DigitString<4> { static constexpr auto value{'4'}; };
template<> struct DigitString<5> { static constexpr auto value{'5'}; };
template<> struct DigitString<6> { static constexpr auto value{'6'}; };
template<> struct DigitString<7> { static constexpr auto value{'7'}; };
template<> struct DigitString<8> { static constexpr auto value{'8'}; };
template<> struct DigitString<9> { static constexpr auto value{'9'}; };

template<size_t N> 
constexpr StaticString<1> digit_string() {
  return DigitString<N>::value;
}

template<size_t N, size_t D>
struct IntStringImpl {
  static constexpr auto first   = digit_first<N>();
  static constexpr auto rest    = digit_rest<N>();
  static constexpr auto current = digit_string<first>();
  static constexpr auto value   = current + 
                                  IntStringImpl<rest,D-1>::value; 
};

template<size_t N>
struct IntStringImpl<N,0> {
  static constexpr auto value = digit_string<N>();
};

template<size_t N>
struct IntString {
  static constexpr StaticString<num_digits<N>()> value = 
          IntStringImpl<N,num_digits<N>()-1>::value;
};

template<size_t N>
constexpr StaticString<num_digits<N>()> IntString<N>::value; 

template<size_t N>
constexpr StaticString<num_digits<N>()> int_string() {
  return IntString<N>::value;
}

#endif // DIGITSTRING_HPP

