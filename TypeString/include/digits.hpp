#pragma once
#ifndef DIGITS_HPP
#define DIGITS_HPP

namespace TypeString {

using std::size_t;

template<size_t N>
constexpr size_t num_digits() { return (N < 10U) ? 1U : 1U + num_digits<N/10U>(); }

template<size_t N>
struct one_plus_e { 
  static constexpr size_t value = 10U * one_plus_e<N-1U>::value; 
};
template<>
struct one_plus_e<0U> { static constexpr size_t value = 1U; };

template<size_t N>
constexpr auto digits_to_cts() -> ct_string<num_digits<N>()> {
  if constexpr( N < 10U ) return ct_string<1U>(static_cast<char>(48U+N));
  constexpr size_t d = num_digits<N>();
  constexpr size_t ten_power = one_plus_e<d-1U>::value;
  constexpr size_t head = N/ten_power;
  constexpr size_t tail = N-head*ten_power;
  return cts_cat( digits_to_cts<head>(), digits_to_cts<tail>() );
}

} // namespace TypeString

#endif // DIGITS_HPP

