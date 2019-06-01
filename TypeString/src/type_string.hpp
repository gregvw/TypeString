#pragma once
#ifndef TYPE_STRING_HPP
#define TYPE_STRING_HPP

#include <cstddef>

#include "ct_string.hpp"
#include "colordefs.hpp"

namespace TypeString {

using std::size_t;

template<typename> 
struct type_cts { static constexpr auto value = undefined_type; };

type_cts( bool )                { static constexpr auto value = fundamental_color + "bool"               + reset_color; }; 
 type_cts( char )                { static constexpr auto value = fundamental_color + "char"               + reset_color; };
 type_cts( unsigned int  )       { static constexpr auto value = fundamental_color + "unsigned int"       + reset_color; };
 type_cts( signed int  )         { static constexpr auto value = fundamental_color + "int"                + reset_color; };
 type_cts( unsigned long  )      { static constexpr auto value = fundamental_color + "unsigned long"      + reset_color; };
 type_cts( signed long  )        { static constexpr auto value = fundamental_color + "long"               + reset_color; };
 type_cts( unsigned long long  ) { static constexpr auto value = fundamental_color + "unsigned long long" + reset_color; };
 type_cts( signed long long  )   { static constexpr auto value = fundamental_color + "long long"          + reset_color; };
 type_cts( float  )              { static constexpr auto value = fundamental_color + "float"              + reset_color; };
 type_cts( double  )             { static constexpr auto value = fundamental_color + "double"             + reset_color; };
 type_cts( long double  )        { static constexpr auto value = fundamental_color + "long double"        + reset_color; };
 type_cts( unsigned char  )      { static constexpr auto value = fundamental_color + "unsigned char"      + reset_color; };
 type_cts( signed char  )        { static constexpr auto value = fundamental_color + "signed char"        + reset_color; };
 type_cts( wchar_t  )            { static constexpr auto value = fundamental_color + "wchar_t"            + reset_color; };
 type_cts( char16_t  )           { static constexpr auto value = fundamental_color + "char16_t"           + reset_color; };
 type_cts( char32_t  )           { static constexpr auto value = fundamental_color + "char32_t"           + reset_color; };

//template<typename T>
//constexpr auto type_cts( T* ) { return type_cts(T{}) + operator_color + "*" + reset_color; }


template<typename T> 
inline std::string type_string( T t ) { return type_cts(t).to_string(); }

} // namespace TypeString


#endif  // TYPE_STRING_HPP
