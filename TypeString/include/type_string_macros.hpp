#pragma once
#ifndef TYPESTRING_MACROS_HPP
#define TYPESTRING_MACROS_HPP

#define TYPESTRING_NONTEMPLATE( TYPENAME )               \
namespace TypeString {                                       \
template<>                                                   \
struct type_cts<TYPENAME> {                            \
  static constexpr auto value = class_name(QUOTE(TYPENAME)); \
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


#define TYPESTRING( TYPENAME, K )                                \
namespace TypeString {                                           \
template<TEMPLATE_DECL(K)>                                       \
struct type_cts<TYPENAME<TEMPLATE_PARAM(K)>> {                   \
  static constexpr auto value = class_name(QUOTE(TYPENAME)) +    \
                                angle_brackets( TYPE_CTS_V(K) ); \
}; } // namespace TypeString


#define VARIADIC_TYPESTRING( TYPENAME ) \
namespace TypeString {                      \
template<typename... Ts> \
struct type_cts<TYPENAME <Ts...>> { \
  static constexpr auto value = class_name(QUOTE(TYPENAME)) + \
                                angle_brackets( delimited( comma, type_cts_v<Ts>... ) ); \
}; } // namespace TypeString

#endif // TYPESTRING_MACROS_HPP

