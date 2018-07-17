#pragma once
#ifndef TYPESTRING_HPP
#define TYPESTRING_HPP

namespace token {
constexpr auto comma  = fg_clr::lightgray + static_string(",") + fg_default;
constexpr auto langle = fg_clr::lightcyan + static_string("<") + fg_default;
constexpr auto rangle = fg_clr::lightcyan + static_string(">") + fg_default;
constexpr auto question_mark = fg_clr::lightred + static_string("?") + fg_default;
} // namespace token



template<typename>
struct TypeString { 
  using type = decltype(fg_clr::lightred + token::question_mark + fg_default);
  static constexpr auto value = fg_clr::lightred + token::question_mark + fg_default;
};

template<typename T> 
using type_string_t = typename TypeString<T>::type;

template<typename T>
constexpr type_string_t<T> TypeString<T>::value; 


template<typename>
struct TypeString { 
  using type = decltype(fg_clr::lightred + token::question_mark + fg_default);
  static constexpr auto value = fg_clr::lightred + token::question_mark + fg_default;
};

template<typename T> 
using type_string_t = typename TypeString<T>::type;

template<typename T>
constexpr type_string_t<T> TypeString<T>::value; 







template<typename First, typename...Rest>
struct TemplateStringInterior {
  static constexpr auto value = TypeString<First>::value + static_string(",") +
                                TemplateStringInterior<Rest...>::value;
};

template<typename First>
struct TemplateStringInterior<First> {
  static constexpr auto value = TypeString<First>::value;           
};

template<typename...Ts>
struct TemplateString {
  static constexpr auto value = static_string("<") + 
                                TemplateStringInterior<Ts...>::value +
                                static_string(">");
};

#endif // TYPESTRING_HPP

