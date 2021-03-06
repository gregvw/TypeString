#pragma once
#ifndef CT_STRING_HPP
#define CT_STRING_HPP

#include <utility>
#include "size_constant.hpp"


namespace TypeString {

using std::size_t;

template<size_t> class ct_string;

template<typename T> 
constexpr auto to_cts( T&& t );

template<char c>
struct char_constant : std::integral_constant<char,c> {
  static constexpr const char data[] = { c, '\0' };	
  static constexpr auto value = to_cts(data);
};

template<char c> constexpr auto char_v = char_constant<c>::value;


template<size_t N>  
class ct_string {
private:

  const char data[N+1U];

public:

  template<typename...Cs> 
  constexpr ct_string( Cs... cs ) : data{ cs...,'\0' } {}

  template<size_t...I>
  constexpr ct_string( const char(&c)[N+1U], std::index_sequence<I...> ) : 
    data{ c[I]... } {}

  constexpr ct_string( const char(&c)[N+1U] ) : 
    ct_string( c, std::make_index_sequence<N>{} ) {}

  template<size_t M, size_t...I>
  constexpr ct_string( const ct_string<M>& s, 
                       std::index_sequence<I...> ) :
    data{ s[I]..., '\0' } {
  }

  template<size_t M>
  constexpr ct_string( const ct_string<M>& s ) :
    ct_string( s, std::make_index_sequence<N>{} ) {
  }
	                          

  constexpr char operator[]( size_t k ) const {
    return k < size() ? data[k] : throw std::out_of_range("");
  }

  constexpr size_t size() const { return N; }

  inline std::string to_string() const { return std::string(data); }

};

constexpr bool is_cts(...) { return false; }

template<size_t N>  
constexpr bool is_cts( const char(&c)[N] ) { return true; }

template<size_t N> 
constexpr bool is_cts( const ct_string<N>& ) { return true; } 

namespace details {

template<char c>
constexpr size_constant<1U> length_impl(char_constant<c>);

template<size_t N>
constexpr auto length_impl( const ct_string<N>& ) -> size_constant<N>;

template<size_t N>
constexpr auto length_impl( const char(&c)[N] ) -> size_constant<N-1U>;

} // namespace details

template<typename T> 
using length_t = decltype( details::length_impl( std::declval<const T&>() ) );

template<typename T> 
constexpr size_t length_v = length_t<T>::value;

template<char c>
constexpr size_t length( char_constant<c> ) { return 1U; }


constexpr size_t length( const char& ) { return 1U; }

template<size_t N>
constexpr size_t length( const ct_string<N>& ) { return N; }

template<size_t N>
constexpr size_t length( const char(&c)[N] ) { return N-1U; }

template<typename T>
constexpr auto indices( const T& ) { return std::make_index_sequence<length_v<T>>{}; }

template<typename L, typename R, size_t k>
constexpr bool compare_elements( const L& l, const R& r, size_constant<k> index ) { 
   if constexpr( length_v<L> != length_v<R> ) return false;
   if constexpr( k < length_v<L> ) return l[k] == r[k] ? compare_elements(l,r,index++) : false;
   else return true;
}

template<typename L, typename R>
constexpr bool operator == ( const L& l, const R& r ) { 
  return compare_elements(l, r, size_constant<0U>{});
}

namespace details {

template<typename L, typename R, size_t... IL, size_t...IR>
constexpr auto cts_cat( const L& l, const R& r,  
                        std::index_sequence<IL...>, 
                        std::index_sequence<IR...> ) { 
  return ct_string<length_v<L>+length_v<R>>( l[IL]...,r[IR]... );
}

} // namespace details

template<typename T>
constexpr auto to_cts( T&& t ) { 
  return ct_string<length_v<T>>(std::forward<T>(t)); 
}


template<typename T>
constexpr auto cts_cat( const T& t ) { 
  return ct_string<length_v<T>>(t);
}

template<typename L, typename R>
constexpr auto cts_cat( const L& l, const R& r ) {
  return details::cts_cat(to_cts(l),to_cts(r),indices(l),indices(r));
}

template<typename First, typename...Rest>
constexpr auto cts_cat( const First& f, const Rest&...r ) {
  return cts_cat( f, cts_cat(r...) );
}

template<size_t nl, size_t nr>
inline constexpr auto operator + ( const ct_string<nl>& l, const char(&r)[nr] ) {
  return cts_cat(l,r);
}

template<size_t nl, size_t nr>
inline constexpr auto operator + ( const char(&l)[nl], const ct_string<nr>& r ) {
  return cts_cat(l,r);
}

template<size_t nl, size_t nr>
inline constexpr auto operator + ( const ct_string<nl>& l, const ct_string<nr>& r ) {
  return cts_cat(l,r);
}


template<typename Delimiter, typename First>
constexpr auto delimited( Delimiter, First&& f ) {
  return to_cts(std::forward<First>(f));
}

template<typename Delimiter, typename First, typename...Rest>
constexpr auto delimited( Delimiter d, First&& f, Rest&&... r ) {
  return cts_cat( to_cts(std::forward<First>(f)), 
		         std::forward<Delimiter>(d), 
			 delimited(std::forward<Delimiter>(d),std::forward<Rest>(r)...) );
}

} // namespace TypeString

#endif // CT_STRING_HPP

