#pragma once
#ifndef STL_TYPES_HPP
#define STL_TYPES_HPP
#include "preprocessor.hpp"
#include <array>
#include <functional>
#include <list>
#include <map>
#include <memory>
#include <ostream>
#include <string>
#include <utility>
#include <vector>


#define STL_TYPESTRING_NONTEMPLATE( TYPENAME )               \
namespace TypeString {                                       \
template<>                                                   \
struct type_cts<std:: TYPENAME> {                            \
  static constexpr auto value = in_namespace("std") +        \
                                class_name(QUOTE(TYPENAME)); \
}; } // namespace TypeString                                                              

#define TYPE_CTS_V_1(T)  type_cts_v<T##0>
#define TYPE_CTS_V_2(T)  TYPE_CTS_V_1(T)  + comma + type_cts_v<T##1>
#define TYPE_CTS_V_3(T)  TYPE_CTS_V_2(T)  + comma + type_cts_v<T##2 >
#define TYPE_CTS_V_4(T)  TYPE_CTS_V_3(T)  + comma + type_cts_v<T##3 >
#define TYPE_CTS_V_5(T)  TYPE_CTS_V_4(T)  + comma + type_cts_v<T##4 >
#define TYPE_CTS_V_6(T)  TYPE_CTS_V_5(T)  + comma + type_cts_v<T##5 >
#define TYPE_CTS_V_7(T)  TYPE_CTS_V_6(T)  + comma + type_cts_v<T##6 >
#define TYPE_CTS_V_8(T)  TYPE_CTS_V_7(T)  + comma + type_cts_v<T##7 >
#define TYPE_CTS_V_9(T)  TYPE_CTS_V_8(T)  + comma + type_cts_v<T##8 >
#define TYPE_CTS_V_10(T) TYPE_CTS_V_9(T)  + comma + type_cts_v<T##9 >
#define TYPE_CTS_V_11(T) TYPE_CTS_V_10(T) + comma + type_cts_v<T##10>
#define TYPE_CTS_V_12(T) TYPE_CTS_V_11(T) + comma + type_cts_v<T##11>
#define TYPE_CTS_V_13(T) TYPE_CTS_V_12(T) + comma + type_cts_v<T##12>
#define TYPE_CTS_V_14(T) TYPE_CTS_V_13(T) + comma + type_cts_v<T##13>
#define TYPE_CTS_V_15(T) TYPE_CTS_V_14(T) + comma + type_cts_v<T##14>
#define TYPE_CTS_V_16(T) TYPE_CTS_V_15(T) + comma + type_cts_v<T##15>
#define TYPE_CTS_V_17(T) TYPE_CTS_V_16(T) + comma + type_cts_v<T##16>
#define TYPE_CTS_V_18(T) TYPE_CTS_V_17(T) + comma + type_cts_v<T##17>
#define TYPE_CTS_V_19(T) TYPE_CTS_V_18(T) + comma + type_cts_v<T##18>
#define TYPE_CTS_V_20(T) TYPE_CTS_V_19(T) + comma + type_cts_v<T##19>
#define TYPE_CTS_V_21(T) TYPE_CTS_V_20(T) + comma + type_cts_v<T##20>
#define TYPE_CTS_V_22(T) TYPE_CTS_V_21(T) + comma + type_cts_v<T##21>
#define TYPE_CTS_V_23(T) TYPE_CTS_V_22(T) + comma + type_cts_v<T##22>
#define TYPE_CTS_V_24(T) TYPE_CTS_V_23(T) + comma + type_cts_v<T##23>
#define TYPE_CTS_V_24(T) TYPE_CTS_V_23(T) + comma + type_cts_v<T##23>
#define TYPE_CTS_V_25(T) TYPE_CTS_V_24(T) + comma + type_cts_v<T##24>
#define TYPE_CTS_V_26(T) TYPE_CTS_V_25(T) + comma + type_cts_v<T##25>
#define TYPE_CTS_V_27(T) TYPE_CTS_V_26(T) + comma + type_cts_v<T##26>
#define TYPE_CTS_V_28(T) TYPE_CTS_V_27(T) + comma + type_cts_v<T##27>
#define TYPE_CTS_V_29(T) TYPE_CTS_V_28(T) + comma + type_cts_v<T##28>
#define TYPE_CTS_V_30(T) TYPE_CTS_V_29(T) + comma + type_cts_v<T##29>
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



STL_TYPESTRING(allocator,1);
STL_TYPESTRING(char_traits,1);
STL_TYPESTRING(default_delete,1);
STL_TYPESTRING(greater,1);
STL_TYPESTRING(greater_equal,1);
STL_TYPESTRING(equal_to,1);
STL_TYPESTRING(less,1);
STL_TYPESTRING(less_equal,1);
STL_TYPESTRING(logical_and,1);
STL_TYPESTRING(logical_or,1);
STL_TYPESTRING(map,4);
STL_TYPESTRING(multiplies,1);
STL_TYPESTRING(not_equal_to,1);
STL_TYPESTRING(basic_ostream,2);
STL_TYPESTRING(pair,2);
STL_TYPESTRING(plus,1);
STL_TYPESTRING(shared_ptr,1);
STL_TYPESTRING_NONTEMPLATE(string);
STL_VARIADIC_TYPESTRING(tuple);
STL_TYPESTRING(unique_ptr,2);
STL_TYPESTRING(vector,2);


namespace TypeString {

// array
template<typename T, size_t N>
struct type_cts<std::array<T,N>> {
  static constexpr auto value = in_namespace("std") +
                                class_name("array") +
                                angle_brackets( type_cts_v<T> + comma + integer_v<N> );
};

} // namespace TypeString

#endif //STL_TYPES_HPP

