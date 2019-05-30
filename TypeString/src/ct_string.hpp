#pragma once
#ifndef CT_STRING_HPP
#define CT_STRING_HPP

#include <utility>
#include "size_constant.hpp"

// Compile Time "String" 

namespace TypeString {

using std::size_t;

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

constexpr size_constant<1U> length_impl(char&&);

template<size_t N>
constexpr auto length_impl( const ct_string<N>& ) -> size_constant<N>;

template<size_t N>
constexpr auto length_impl( const char(&c)[N] ) -> size_constant<N-1U>;

} // namespace details

template<typename T> 
using length_t = decltype( details::length_impl( std::declval<T>() ) );

template<typename T> 
constexpr size_t length_v = length_t<T>::value;

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
constexpr auto cts_cat( const T& t ) { 
  return ct_string<length_v<T>>(t);
}

template<typename L, typename R>
constexpr auto cts_cat( const L& l, const R& r ) {
  return details::cts_cat(l,r,indices(l),indices(r));
}

template<typename First, typename...Rest>
constexpr auto cts_cat( const First& f, const Rest&...r ) {
  return cts_cat( f, cts_cat(r...) );
}

template<typename T>
constexpr auto to_cts( T&& t ) { return ct_string<length_v<T>>(std::forward<T>(t)); }

} // namespace TypeString



#endif // CT_STRING_HPP

