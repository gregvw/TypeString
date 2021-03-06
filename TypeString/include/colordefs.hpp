#pragma once
#ifndef COLORDEFS_HPP
#define COLORDEFS_HPP

namespace TypeString {

constexpr auto esc = to_cts("\033[");

// Select Graphics Rendition
constexpr auto s_normal       = to_cts("0");
constexpr auto s_bold         = to_cts("1");
constexpr auto s_faint        = to_cts("2");
constexpr auto s_italic       = to_cts("3");
constexpr auto s_underline    = to_cts("4");
constexpr auto s_slow_blink   = to_cts("5");
constexpr auto s_crossed      = to_cts("9");
constexpr auto s_overline     = to_cts("53");

// Foreground Colors
constexpr auto f_default       = to_cts("39");     
constexpr auto f_black         = to_cts("30");     
constexpr auto f_red           = to_cts("31");       
constexpr auto f_green         = to_cts("32");
constexpr auto f_yellow        = to_cts("33");
constexpr auto f_blue          = to_cts("34");
constexpr auto f_magenta       = to_cts("35");
constexpr auto f_cyan          = to_cts("36");
constexpr auto f_light_gray    = to_cts("37"); 
constexpr auto f_dark_gray     = to_cts("90"); 
constexpr auto f_light_red     = to_cts("91"); 
constexpr auto f_light_green   = to_cts("92"); 
constexpr auto f_light_yellow  = to_cts("93"); 
constexpr auto f_light_blue    = to_cts("94");
constexpr auto f_light_magenta = to_cts("95");
constexpr auto f_light_cyan    = to_cts("96"); 
constexpr auto f_white         = to_cts("97");

// Background Colors
constexpr auto b_default       = to_cts("49");     
constexpr auto b_black         = to_cts("40");     
constexpr auto b_red           = to_cts("41");       
constexpr auto b_green         = to_cts("42");
constexpr auto b_yellow        = to_cts("43");
constexpr auto b_blue          = to_cts("44");
constexpr auto b_magenta       = to_cts("45");
constexpr auto b_cyan          = to_cts("46");
constexpr auto b_light_gray    = to_cts("47"); 
constexpr auto b_dark_gray     = to_cts("100"); 
constexpr auto b_light_red     = to_cts("101"); 
constexpr auto b_light_green   = to_cts("102"); 
constexpr auto b_light_yellow  = to_cts("103"); 
constexpr auto b_light_blue    = to_cts("104");
constexpr auto b_light_magenta = to_cts("105");
constexpr auto b_light_cyan    = to_cts("106"); 
constexpr auto b_white         = to_cts("107");


constexpr auto color = [] ( auto...args ) {
  return cts_cat(esc,delimited(char_v<';'>,args... ),to_cts("m"));
};
constexpr auto reset_color = color(s_normal,f_default,b_default);


// Customization
constexpr auto comma_color          = color(f_light_gray);
constexpr auto parenthesis_color    = color(f_light_gray);
constexpr auto square_bracket_color = color(f_light_gray);
constexpr auto angle_bracket_color  = color(s_bold,f_light_yellow);
constexpr auto operator_color       = color(s_normal,f_white);
constexpr auto integer_color        = color(f_light_magenta);
constexpr auto string_color         = color(f_magenta);
constexpr auto char_color           = color(f_light_magenta);
constexpr auto fundamental_color    = color(s_bold,f_light_green);
constexpr auto class_color          = color(s_bold,s_italic,f_light_blue);
constexpr auto namespace_color      = color(s_bold,f_light_red);


constexpr auto const_type = color(f_light_cyan) + "const " + reset_color;
constexpr auto volatile_type = color(f_light_cyan) + "volatile " + reset_color;


constexpr auto undefined_type = color(s_bold,s_underline,f_light_red) +
                                "undefined type" + reset_color;


constexpr auto scope = color(s_normal,f_dark_gray) + "::" + reset_color;
constexpr auto comma = comma_color + "," + reset_color;

#if DISPLAY_NAMESPACE
template<size_t N>
constexpr auto in_namespace( const char(&ns)[N] ) {
  return namespace_color + to_cts(ns) + scope; 
}
#else 
inline constexpr auto in_namespace(...) { return to_cts(""); }
#endif

template<size_t N>
constexpr auto class_name( const char(&cn)[N] ) {
  return class_color + to_cts(cn) + reset_color; 
}


template<auto N>
constexpr auto abs_v = N < 0 ? -N : N;

template<auto N>
constexpr auto sign_f(){ 
  if constexpr(N < 0) return to_cts("-");
  return to_cts(" "); 
}

template<auto N> 
constexpr auto sign_v = sign_f<N>();

template<size_t N>
constexpr size_t num_digits();

template<size_t N>
constexpr auto digits_to_cts() -> ct_string<num_digits<N>()>;

template<auto N>
constexpr auto integer_v = integer_color + sign_v<N> + digits_to_cts<abs_v<N>>() + reset_color;

template<typename T>
constexpr auto class_v = class_color + to_cts<T>() + reset_color;

constexpr auto ptr_v = color(s_bold,f_white) + "*" + reset_color;
constexpr auto ref_v = color(s_bold,f_white) + "&" + reset_color;

} // namespace TypeString

#endif  // COLORDEFS_HPP

