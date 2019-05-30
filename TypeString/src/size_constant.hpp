#pragma once
#ifndef SIZE_CONSTANT_HPP
#define SIZE_CONSTANT_HPP

#include <ostream>
#include <string>
#include <type_traits>


namespace TypeString {

using std::size_t;

template<size_t N>
struct size_constant : std::integral_constant<size_t, N> {

  constexpr auto operator ++ ()    const { return size_constant<N+1U>{}; }   
  constexpr auto operator ++ (int) const { return size_constant<N+1U>{}; }   
  constexpr auto operator -- ()    const { static_assert(N>0U);
                                           return size_constant<N-1U>{}; }   
  constexpr auto operator -- (int) const { static_assert(N>0U);
                                           return size_constant<N-1U>{}; }   
 
  template<size_t M>  
  constexpr auto operator + ( size_constant<M> ) { return size_constant<M+N>{}; }

  template<size_t M>
  constexpr auto operator - ( size_constant<M> ) { static_assert(N>=M);
                                                   return size_constant<M+N>{}; }
  template<size_t M>  
  constexpr auto operator * ( size_constant<M> ) { return size_constant<M*N>{}; }

  template<size_t M>  
  constexpr auto operator / ( size_constant<M> ) { return size_constant<M/N>{}; }

  template<size_t M>  
  constexpr auto operator == ( size_constant<M> ) { return N==M;   }   

  template<size_t M>  
  constexpr bool operator != ( size_constant<M> ) { return N != M; }

  template<size_t M>  
  constexpr bool operator >  ( size_constant<M> ) { return N > M; }

  template<size_t M>  
  constexpr bool operator <  ( size_constant<M> ) { return N < M; }

  template<size_t M>  
  constexpr bool operator >= ( size_constant<M> ) { return N >= M; }

  template<size_t M>  
  constexpr bool operator <= ( size_constant<M> ) { return N <= M; }

  inline auto to_string() const noexcept { return std::to_string(N); }

}; // class size_constant

template<size_t N>
inline std::ostream& operator << ( size_constant<N> sc, std::ostream& os ) { 
  os << sc.to_string();
  return os; 
}

} // namespace TypeString

#endif // SIZE_CONSTANT_HPP

