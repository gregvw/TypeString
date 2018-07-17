#pragma once
#ifndef TYPESTRINGMACROS_HPP
#define TYPESTRINGMACROS_HPP

#include "Preprocessor.hpp"
#include "TypeString.hpp"

#define REGISTER_FUNDAMENTAL(X)                          \
template<>                                               \
struct TypeString<X> {                                   \
  static constexpr auto value = static_string(QUOTE(X)); \
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

#define REGISTER_TEMPLATE_CLASS_1(NAME)                      \
template<class> class NAME;                                  \
template<class T>                                            \
struct TypeString<NAME<T>> {                                 \
  static constexpr auto value = static_string(QUOTE(NAME))   \
                              + TemplateString<T>::value;    \
};                                                           

#define REGISTER_TEMPLATE_CLASS(NAME,K)                              \
template<TEMPLATE_DECL(K)> class NAME;                               \
template<TEMPLATE_DECL(K)>                                           \
struct TypeString<NAME<TEMPLATE_PARAM(K)>> {                         \
  static constexpr auto value = static_string(QUOTE(NAME))           \
               + TemplateString<TEMPLATE_PARAM(K)>::value;           \
};                                                                   



#endif // TYPESTRINGMACROS_HPP

