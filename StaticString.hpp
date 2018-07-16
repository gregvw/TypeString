#pragma once
#ifndef STATICSTRING_HPP
#define STATICSTRING_HPP

// Modified from StringConstant.hpp by David Sanders
// https://gist.github.com/dsanders11/8951887
// to be C++11 compliant

#include "cppstd14.hpp"
#include <stdexcept>
#include <string>

using std::out_of_range;
using std::is_void;
using std::size_t;
using std::string;

template <size_t Length, size_t Index, typename Left, typename Right>
constexpr auto CompareChars( const Left& lhs, const Right& rhs ) -> enable_if_t<Index != Length, bool> {
  return lhs[Index] == rhs[Index] ? CompareChars<Length, Index + 1>( lhs, rhs ) : false;
}

template <size_t Length, size_t Index, typename Left, typename Right, enable_if_t<Index == Length, bool> = 0>
constexpr bool CompareChars( const Left& lhs, const Right& rhs ) {
  return true;
}

template <typename T>
struct length_of {
  static_assert( is_void<T>::value, "Unsupported type for length_of" );
  static constexpr size_t value = 1;
};

template <size_t N>
struct length_of< const char(&)[N] > {
  static constexpr size_t value = N - 1;
};

template <size_t N>
struct length_of< char[N] > {
  static constexpr size_t value = N - 1;
};

template <size_t N>
struct length_of< const char[N] > {
  static constexpr size_t value = N - 1;
};


template <size_t N>
class StaticString {
public:
  template <typename... Chars>
  constexpr StaticString( Chars... characters ) : m_value{ characters..., '\0' } {}

  template <size_t... I>
  constexpr StaticString( const StaticString<N>& rhs, index_sequence<I...> = StaticString::g_indexes )
      : m_value{ rhs[I]..., '\0' } {}

  template <size_t X, size_t... I>
  constexpr StaticString( const StaticString<X>& rhs, index_sequence<I...> )
      : m_value{ rhs[I]..., '\0' } {}

  template <size_t... I>
  constexpr StaticString( const char(&value)[N + 1], index_sequence<I...> )
      : StaticString( value[I]... ) {}

  constexpr StaticString( const char(&value)[N + 1] )
      : StaticString( value, make_index_sequence<N>{} ) {}

  constexpr char operator[]( const size_t index ) const {
      return index < N ? m_value[index] : throw out_of_range("Index out of range");
  }

  constexpr const char* const Get( ) const { return m_value; }
  constexpr size_t Length( ) const { return N; }

  string to_string( ) const { return string( m_value ); }

protected:
  const char m_value[N + 1];
  static constexpr auto g_indexes = make_index_sequence<N>{};
};

template <size_t N>
struct length_of< StaticString<N> > {
  static constexpr size_t value = N;
};

template <size_t N>
struct length_of< const StaticString<N> > {
  static constexpr size_t value = N;
};

template <size_t N>
struct length_of< const StaticString<N>& > {
  static constexpr size_t value = N;
};

template <typename T>
struct is_string_constant {
  static constexpr bool value = false;
};

template <size_t N>
struct is_string_constant< StaticString<N> > {
  static constexpr bool value = true;
};

template <size_t N>
struct is_string_constant< StaticString<N>& > {
  static constexpr bool value = true;
};

template <size_t N>
struct is_string_constant< const StaticString<N> > {
  static constexpr bool value = true;
};

template <size_t N>
struct is_string_constant< const StaticString<N>& > {
  static constexpr bool value = true;
};

template <typename Left, typename Right, size_t... ILeft, size_t... IRight>
constexpr StaticString<sizeof...(ILeft) + sizeof...(IRight)> 
ConcatStrings( const Left& lhs, const Right& rhs, index_sequence<ILeft...>, index_sequence<IRight...> ) {
  return StaticString<sizeof...(ILeft) + sizeof...(IRight)>( lhs[ILeft]..., rhs[IRight]... );
}

template <typename Left, typename Right>
constexpr StaticString<length_of<Left>::value + length_of<Right>::value> ConcatStrings( const Left& lhs, const Right& rhs ) {
  return ConcatStrings( lhs, rhs, make_index_sequence<length_of<decltype(lhs)>::value>{}, make_index_sequence<length_of<decltype(rhs)>::value>{} );
}

template <size_t N, typename Right>
constexpr StaticString<N + length_of<Right>::value> operator+( const StaticString<N>& lhs, const Right& rhs ) {
  return ConcatStrings( lhs, rhs );
}

template <typename Left, size_t N>
constexpr StaticString<length_of<Left>::value + N> operator+( const Left& lhs, const StaticString<N>& rhs ) {
  return ConcatStrings( lhs, rhs );
}

template <size_t X, size_t Y>
constexpr StaticString<X + Y> operator+( const StaticString<X>& lhs, const StaticString<Y>& rhs ) {
  return ConcatStrings( lhs, rhs );
}

template <size_t N, typename Right>
constexpr auto operator==( const StaticString<N>& lhs, const Right& rhs ) -> enable_if_t<N == length_of<Right>::value, bool> {
  return CompareChars<N, 0>( lhs, rhs );
}

template <typename Left, size_t N>
constexpr auto operator==( const Left& lhs, const StaticString<N>& rhs ) -> enable_if_t<length_of<Left>::value == N, bool> {
  return CompareChars<N, 0>( lhs, rhs );
}

template <size_t X, size_t Y>
constexpr auto operator==( const StaticString<X>& lhs, const StaticString<Y>& rhs ) -> enable_if_t<X == Y, bool> {
  return CompareChars<X, 0>( lhs, rhs );
}

template <size_t N, typename Right, enable_if_t<N != length_of<Right>::value, bool> = 0>
constexpr bool operator==( const StaticString<N>& lhs, const Right& rhs ) {
  return false;
}

template <typename Left, size_t N, enable_if_t<length_of<Left>::value != N, bool> = 0>
constexpr bool operator==( const Left& lhs, const StaticString<N>& rhs ) {
  return false;
}

template <size_t X, size_t Y, enable_if_t<X != Y, bool> = 0>
constexpr bool operator==( const StaticString<X>& lhs, const StaticString<Y>& rhs ) {
  return false;
}

template <size_t N, size_t... I>
constexpr auto static_string( const char(&value)[N], index_sequence<I...> ) -> decltype( StaticString<N-1>(value[I]... ) ) {
  return StaticString<N - 1>( value[I]... );
}

template <size_t N>
constexpr auto static_string( const char(&value)[N] ) -> decltype( static_string( value, make_index_sequence<N - 1>{} ) ) {
  return static_string( value, make_index_sequence<N - 1>{} );
}


#endif //STATICSTRING_HPP

