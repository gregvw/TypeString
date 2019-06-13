#pragma once
#ifndef STL_TYPES_HPP
#define STL_TYPES_HPP
#include "preprocessor.hpp"
#include <array>
#include <functional>
#include <list>
#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>


#define STL_TYPESTRING_T0( TYPENAME )                        \
template<>                                                   \
struct type_cts<std:: TYPENAME> {                            \
  static constexpr auto value = in_namespace("std") +        \
                                class_name(QUOTE(TYPENAME)); \
};                                                              

#define STL_TYPESTRING_T1( TYPENAME )                            \
template<typename T>                                             \
struct type_cts<std:: TYPENAME <T>> {                            \
  static constexpr auto value = in_namespace("std") +            \
                                class_name(QUOTE(TYPENAME)) +    \
                                angle_brackets( type_cts_v<T> ); \
};                                                               



#define TYPE_CTS_V_1(T)  type_cts_v<T##0>
#define TYPE_CTS_V_2(T)  TYPE_CTS_V_1(T)  , type_cts_v<T##1>
#define TYPE_CTS_V_3(T)  TYPE_CTS_V_2(T)  , type_cts_v<T##2 >
#define TYPE_CTS_V_4(T)  TYPE_CTS_V_3(T)  , type_cts_v<T##3 >
#define TYPE_CTS_V_5(T)  TYPE_CTS_V_4(T)  , type_cts_v<T##4 >
#define TYPE_CTS_V_6(T)  TYPE_CTS_V_5(T)  , type_cts_v<T##5 >
#define TYPE_CTS_V_7(T)  TYPE_CTS_V_6(T)  , type_cts_v<T##6 >
#define TYPE_CTS_V_8(T)  TYPE_CTS_V_7(T)  , type_cts_v<T##7 >
#define TYPE_CTS_V_9(T)  TYPE_CTS_V_8(T)  , type_cts_v<T##8 >
#define TYPE_CTS_V_10(T) TYPE_CTS_V_9(T)  , type_cts_v<T##9 >
#define TYPE_CTS_V_11(T) TYPE_CTS_V_10(T) , type_cts_v<T##10>
#define TYPE_CTS_V_12(T) TYPE_CTS_V_11(T) , type_cts_v<T##11>
#define TYPE_CTS_V_13(T) TYPE_CTS_V_12(T) , type_cts_v<T##12>
#define TYPE_CTS_V_14(T) TYPE_CTS_V_13(T) , type_cts_v<T##13>
#define TYPE_CTS_V_15(T) TYPE_CTS_V_14(T) , type_cts_v<T##14>
#define TYPE_CTS_V_16(T) TYPE_CTS_V_15(T) , type_cts_v<T##15>
#define TYPE_CTS_V_17(T) TYPE_CTS_V_16(T) , type_cts_v<T##16>
#define TYPE_CTS_V_18(T) TYPE_CTS_V_17(T) , type_cts_v<T##17>
#define TYPE_CTS_V_19(T) TYPE_CTS_V_18(T) , type_cts_v<T##18>
#define TYPE_CTS_V_20(T) TYPE_CTS_V_19(T) , type_cts_v<T##19>
#define TYPE_CTS_V_21(T) TYPE_CTS_V_20(T) , type_cts_v<T##20>
#define TYPE_CTS_V_22(T) TYPE_CTS_V_21(T) , type_cts_v<T##21>
#define TYPE_CTS_V_23(T) TYPE_CTS_V_22(T) , type_cts_v<T##22>
#define TYPE_CTS_V_24(T) TYPE_CTS_V_23(T) , type_cts_v<T##23>
#define TYPE_CTS_V_24(T) TYPE_CTS_V_23(T) , type_cts_v<T##23>
#define TYPE_CTS_V_25(T) TYPE_CTS_V_24(T) , type_cts_v<T##24>
#define TYPE_CTS_V_26(T) TYPE_CTS_V_25(T) , type_cts_v<T##25>
#define TYPE_CTS_V_27(T) TYPE_CTS_V_26(T) , type_cts_v<T##26>
#define TYPE_CTS_V_28(T) TYPE_CTS_V_27(T) , type_cts_v<T##27>
#define TYPE_CTS_V_29(T) TYPE_CTS_V_28(T) , type_cts_v<T##28>
#define TYPE_CTS_V_30(T) TYPE_CTS_V_29(T) , type_cts_v<T##29>
#define TYPE_CTS_V(N)    TYPE_CTS_V_##N(T)


#define STL_TYPESTRING( TYPENAME, K )                            \
namespace std { template<TEMPLATE_DECL(K)> struct TYPENAME; }    \
namespace TypeString {                                           \
template<TEMPLATE_DECL(K)>                                       \
struct type_cts<std:: TYPENAME<TEMPLATE_PARAM(K)>> {             \
  static constexpr auto value = in_namespace("std") +            \
                                class_name(QUOTE(TYPENAME)) +    \
                                angle_brackets( TYPE_CTS_V(K) ); \
}; } // namespace TypeString


#define STL_VARIADIC_TYPESTRING( TYPENAME ) \
namespace std { template<typename...> struct TYPENAME; } \
namespace TypeString {                      \
template<typename... Ts> \
struct type_cts<std:: TYPENAME <Ts...>> { \
  static constexpr auto value = in_namespace("std") + \
                                class_name(QUOTE(TYPENAME)) + \
                                angle_brackets( delimited( comma, type_cts_v<Ts>... ) ); \
}; } // namespace TypeString


STL_VARIADIC_TYPESTRING(tuple);

STL_TYPESTRING(allocator,1);

STL_TYPESTRING(default_delete,1);

STL_TYPESTRING(shared_ptr,1);


namespace TypeString {


// array
template<typename T, size_t N>
struct type_cts<std::array<T,N>> {
  static constexpr auto value = in_namespace("std") +
                                class_name("array") +
                                angle_brackets( type_cts_v<T> + comma + integer_v<N> );
};


// map 
template<typename key_type, typename value_type, 
         typename compare_type, 
         typename allocator_type>
struct type_cts<std::map<key_type,value_type,compare_type,allocator_type>> {
  static constexpr auto value = in_namespace("std") + 
                                class_name("map") + 
                                angle_brackets( delimited( comma, type_cts_v<key_type>,  
                                                                  type_cts_v<value_type>,
                                                                  type_cts_v<compare_type>,
                                                                  type_cts_v<allocator_type> ) );
};


// pair
template<typename first_type, typename second_type>
struct type_cts<std::pair<first_type,second_type>> {
  static constexpr auto value = in_namespace("std") + 
                                class_name("pair") +
                                angle_brackets( type_cts_v<first_type> + comma + type_cts_v<second_type> );
};

// shared_ptr
template<typename T>
struct type_cts<std::shared_ptr<T>> {
  static constexpr auto value = in_namespace("std") + 
                                class_name("shared_ptr") + 
                                angle_brackets( type_cts_v<T> );
};


STL_TYPESTRING_T0(string);


// unique_ptr
template<typename T, typename Deleter>
struct type_cts<std::unique_ptr<T,Deleter>> {
  static constexpr auto value = in_namespace("std") + 
                                class_name("unique_ptr") + 
                                angle_brackets( type_cts_v<T> + comma + type_cts_v<Deleter> );
};

// vector
template<typename T, typename Allocator>
struct type_cts<std::vector<T,Allocator>> {
  static constexpr auto value = in_namespace("std") + 
                                class_name("vector") + 
                                angle_brackets( type_cts_v<T> + comma +
                                                type_cts_v<Allocator> );
};

} // namespace TypeString

#endif //STL_TYPES_HPP

