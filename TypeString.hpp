#pragma once
#ifndef TYPESTRING_HPP
#define TYPESTRING_HPP

#include "Preprocessor.hpp"

constexpr size_t length( const char* str, size_t count = 0 ) {
  return ( str[0] == '\0' ? count : length(str+1,count+1) );
}

static constexpr auto langle = static_string("<");
static constexpr auto rangle = static_string(">");
static constexpr auto comma  = static_string(",");

template<typename>
struct TypeString { 
  using type = const StaticString<length("?")>; 
  static constexpr type value = static_string("?"); 
};

template<typename T> using type_string_t = typename TypeString<T>::type;

template<typename First, typename...Rest>
struct Composition {
  static constexpr size_t length = 1 + TypeString<First>::value.Length() +
                                       Composition<Rest...>::length;
};

template<typename First>
struct Composition<First> { 
  static constexpr size_t length = 2 + TypeString<First>::value.Length();
};

template<typename First, typename...Rest>
struct TemplateStringInterior {
  static constexpr StaticString<Composition<First,Rest...>::length-2> 
  value = TypeString<First>::value + static_string(",") +
          TemplateStringInterior<Rest...>::value;
};

template<typename First, typename...Rest>
constexpr StaticString<Composition<First,Rest...>::length-2>
TemplateStringInterior<First,Rest...>::value;

template<typename First>
struct TemplateStringInterior<First> {
  static constexpr StaticString<Composition<First>::length-2> 
  value = TypeString<First>::value;           
};

template<typename First>
constexpr StaticString<Composition<First>::length-2>
TemplateStringInterior<First>::value;


template<typename...Ts>
struct TemplateString {
  static constexpr StaticString<Composition<Ts...>::length>
    value = static_string("<") + 
            TemplateStringInterior<Ts...>::value 
            + static_string(">");
};

template<typename...Ts>
constexpr StaticString<Composition<Ts...>::length>
TemplateString<Ts...>::value;

template<typename...Ts>
constexpr StaticString<Composition<Ts...>::length> 
template_string() { return TemplateString<Ts...>::value; }


template<size_t N, typename...Ts> using composite_type = 
  const StaticString<N+Composition<Ts...>::length>;


#define _QUOTE_(x) #x 
#define QUOTE(x) _QUOTE_(x)

#define REGISTER_FUNDAMENTAL(X)                          \
template<>                                               \
struct TypeString<X> {                                   \
  using type = const StaticString<length(QUOTE(X))>;     \
  static constexpr type value = static_string(QUOTE(X)); \
};

REGISTER_FUNDAMENTAL(int);
REGISTER_FUNDAMENTAL(unsigned);
REGISTER_FUNDAMENTAL(short);
REGISTER_FUNDAMENTAL(unsigned short);
REGISTER_FUNDAMENTAL(long);
REGISTER_FUNDAMENTAL(unsigned long);
REGISTER_FUNDAMENTAL(long long);
REGISTER_FUNDAMENTAL(unsigned long long);
REGISTER_FUNDAMENTAL(float);
REGISTER_FUNDAMENTAL(double );
REGISTER_FUNDAMENTAL(long double);
REGISTER_FUNDAMENTAL(void);
REGISTER_FUNDAMENTAL(bool);
REGISTER_FUNDAMENTAL(char);
REGISTER_FUNDAMENTAL(unsigned char);
REGISTER_FUNDAMENTAL(wchar_t);
REGISTER_FUNDAMENTAL(char16_t);
REGISTER_FUNDAMENTAL(char32_t);

#if defined(__clang__)
#define REGISTER_TEMPLATE_CLASS_VALUE_1(NAME)                \
template<typename T>                                         \
constexpr type_string_t<NAME<T>> TypeString<NAME<T>>::value; 
#else 
#define REGISTER_TEMPLATE_CLASS_VALUE_1(NAME)                         
#endif

#define REGISTER_TEMPLATE_CLASS_1(NAME)                      \
template<class> class NAME;                                  \
template<class T>                                            \
struct TypeString<NAME<T>> {                                 \
  using type = composite_type<length(QUOTE(NAME)),T>;        \
  static constexpr type value = static_string(QUOTE(NAME))   \
                                + template_string<T>();      \
};                                                           \
REGISTER_TEMPLATE_CLASS_VALUE_1(NAME)

#if defined(__clang__)
#define REGISTER_TEMPLATE_CLASS_VALUE(NAME,K)                        \
template<TEMPLATE_DECL(K)>                                           \
constexpr type_string_t<NAME<TEMPLATE_PARAM(K)>>                     \
TypeString<NAME<TEMPLATE_PARAM(K)>>::value;                          
#else
#define REGISTER_TEMPLATE_CLASS_VALUE(NAME,K)
#endif

#define REGISTER_TEMPLATE_CLASS(NAME,K)                              \
template<TEMPLATE_DECL(K)> class NAME;                               \
template<TEMPLATE_DECL(K)>                                           \
struct TypeString<NAME<TEMPLATE_PARAM(K)>> {                         \
  using type = composite_type<length(QUOTE(NAME)),TEMPLATE_PARAM(K)>;\
  static constexpr type value = static_string(QUOTE(NAME))           \
               + template_string<TEMPLATE_PARAM(K)>();               \
};                                                                   \
REGISTER_TEMPLATE_CLASS_VALUE(NAME,K)







#endif // TYPESTRING_HPP

