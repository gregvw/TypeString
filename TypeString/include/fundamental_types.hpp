#pragma once
#ifndef FUNDAMENTAL_TYPES_HPP
#define FUNDAMENTAL_TYPES_HPP


#define FUNDAMENTAL_TYPESTRING( TYPENAME )        \
namespace TypeString {                            \
template<> struct type_cts<TYPENAME>  {           \
  static constexpr auto value = fundamental_color \
                                + QUOTE(TYPENAME) \
                                + reset_color; }; \
} // namespace TypeString

FUNDAMENTAL_TYPESTRING(void);
FUNDAMENTAL_TYPESTRING(bool);
FUNDAMENTAL_TYPESTRING(char);
FUNDAMENTAL_TYPESTRING(unsigned short);
FUNDAMENTAL_TYPESTRING(short);
FUNDAMENTAL_TYPESTRING(unsigned int);
FUNDAMENTAL_TYPESTRING(int);
FUNDAMENTAL_TYPESTRING(unsigned long);
FUNDAMENTAL_TYPESTRING(long);
FUNDAMENTAL_TYPESTRING(unsigned long long);
FUNDAMENTAL_TYPESTRING(long long);
FUNDAMENTAL_TYPESTRING(float);
FUNDAMENTAL_TYPESTRING(double);
FUNDAMENTAL_TYPESTRING(long double);
FUNDAMENTAL_TYPESTRING(unsigned char);
FUNDAMENTAL_TYPESTRING(wchar_t);
FUNDAMENTAL_TYPESTRING(char16_t);
FUNDAMENTAL_TYPESTRING(char32_t);

#endif  // FUNDAMENTAL_TYPES_HPP
