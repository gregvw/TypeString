#pragma once
#ifndef CPPSTD14_HPP
#define CPPSTD14_HPP

#include <utility>
#include <type_traits>



#if __cplusplus >= 201402L // Have C++14 
#define CPP14 true
#else 
#define CPP14 false
#endif


#if CPP14 // If we have C++14, alias the following from the std namespace

using std::decay_t;
using std::enable_if_t;
using std::common_type_t;   
using std::integer_sequence; 
using std::index_sequence;
using std::make_index_sequence;
using std::index_sequence_for; 

#else /* Implement certain C++14 standard features in C++11 */

namespace details { 
using namespace std;

template<typename...Args> 
using common_type_t = typename common_type<Args...>::type;

template<typename T> 
using decay_t = typename decay<T>::type;

template<bool B, typename T>
using enable_if_t = typename enable_if<B,T>::type;


template<typename Integer, Integer... I>
struct integer_sequence {
  using type = integer_sequence;
  using value_type = Integer;
  static constexpr size_t size() noexcept { 
    return sizeof...(I); 
  }
};

template<size_t... Ints>
using index_sequence = integer_sequence<size_t, Ints...>;

template <class Sequence1, class Sequence2>
struct _merge_and_renumber;

template <size_t... I1, size_t... I2>
struct _merge_and_renumber<index_sequence<I1...>, index_sequence<I2...>>
  : index_sequence<I1..., (sizeof...(I1)+I2)...> {};

template <size_t N>
struct make_index_sequence
  : _merge_and_renumber<typename make_index_sequence<N/2>::type,
                        typename make_index_sequence<N - N/2>::type> {};

template<> struct make_index_sequence<0> : index_sequence<> {};
template<> struct make_index_sequence<1> : index_sequence<0> {};

template<typename...T> using index_sequence_for = make_index_sequence<sizeof...(T)>;

} // namespace details

using details::common_type_t;   
using details::decay_t;
using details::enable_if_t;
using details::integer_sequence; 
using details::index_sequence;
using details::make_index_sequence;
using details::index_sequence_for; 

#endif // CPP14

#endif // CPPSTD14_HPP

