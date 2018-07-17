#pragma once
#ifndef COLORS_HPP
#define COLORS_HPP

using ColorCode = std::size_t;
namespace color {
namespace fg {
constexpr const ColorCode Default      = 39; 
constexpr const ColorCode Black        = 30; 
constexpr const ColorCode Red          = 31; 
constexpr const ColorCode Green        = 32; 
constexpr const ColorCode Yellow       = 33; 
constexpr const ColorCode Blue         = 34; 
constexpr const ColorCode Magenta      = 35; 
constexpr const ColorCode Cyan         = 36; 
constexpr const ColorCode LightGray    = 37; 
constexpr const ColorCode DarkGray     = 90;  
constexpr const ColorCode LightRed     = 91; 
constexpr const ColorCode LightGreen   = 92; 
constexpr const ColorCode LightYellow  = 93; 
constexpr const ColorCode LightBlue    = 94; 
constexpr const ColorCode LightMagenta = 95; 
constexpr const ColorCode LightCyan    = 96; 
constexpr const ColorCode White        = 97; 

#ifdef COLORED_OUTPUT
template<ColorCode C=Default> 
struct ColorString {
  static constexpr auto value = static_string("\033[") +
                                int_string<C>() + 
                                static_string("m");                    
  static constexpr auto digits = num_digits<C>();
}; // ColorString
#else // No colors
template<ColorCode C=Default> 
struct ColorString {
  static constexpr auto value  = static_string("");
  static constexpr auto digits = 0;
}; // ColorString
#endif

template<ColorCode C>
constexpr StaticString<ColorString<C>::num_digits>
set() { return ColorString<C>::value; }

constexpr auto reset        = ColorString<Default>::value; 
constexpr auto black        = ColorString<Black>::value;
constexpr auto red          = ColorString<Red>::value;
constexpr auto green        = ColorString<Green>::value;
constexpr auto yellow       = ColorString<Yellow>::value;
constexpr auto blue         = ColorString<Blue>::value;
constexpr auto magenta      = ColorString<Magenta>::value;
constexpr auto cyan         = ColorString<Cyan>::value;
constexpr auto lightgray    = ColorString<LightGray>::value;
constexpr auto darkgray     = ColorString<DarkGray>::value;
constexpr auto lightred     = ColorString<LightRed>::value;
constexpr auto lightgreen   = ColorString<LightGreen>::value;
constexpr auto lightyellow  = ColorString<LightYellow>::value;
constexpr auto lightblue    = ColorString<LightBlue>::value;
constexpr auto lightmagenta = ColorString<LightMagenta>::value;
constexpr auto lightcyan    = ColorString<LightCyan>::value;
constexpr auto white        = ColorString<White>::value;

} // namespace fg

namespace bg {
constexpr const ColorCode Default      = 49;
constexpr const ColorCode Black        = 40; 
constexpr const ColorCode Red          = 41; 
constexpr const ColorCode Green        = 42; 
constexpr const ColorCode Yellow       = 43; 
constexpr const ColorCode Blue         = 44; 
constexpr const ColorCode Magenta      = 45; 
constexpr const ColorCode Cyan         = 46; 
constexpr const ColorCode LightGray    = 47; 
constexpr const ColorCode DarkGray     = 48; 
constexpr const ColorCode LightRed     = 101; 
constexpr const ColorCode LightGreen   = 102; 
constexpr const ColorCode LightYellow  = 103; 
constexpr const ColorCode LightBlue    = 104; 
constexpr const ColorCode LightMagenta = 105; 
constexpr const ColorCode LightCyan    = 106; 
constexpr const ColorCode White        = 107;

#ifdef COLORED_OUTPUT
template<ColorCode C=Default> 
struct ColorString {
  static constexpr auto value = static_string("\033[") +
                                int_string<C>() + 
                                static_string("m");                    
  static constexpr auto digits = num_digits<C>();
}; // ColorString
#else // No Colors
template<ColorCode C=Default> 
struct ColorString {
  static constexpr auto value = static_string("");
  static constexpr auto digits = num_digits<C>();
}; // ColorString
#endif // COLORED_OUTPUT

template<ColorCode C>
constexpr StaticString<ColorString<C>::num_digits>
set() {return ColorString<C>::value; }

constexpr auto reset        = ColorString<Default>::value; 
constexpr auto black        = ColorString<Black>::value;
constexpr auto red          = ColorString<Red>::value;
constexpr auto green        = ColorString<Green>::value;
constexpr auto yellow       = ColorString<Yellow>::value;
constexpr auto blue         = ColorString<Blue>::value;
constexpr auto magenta      = ColorString<Magenta>::value;
constexpr auto cyan         = ColorString<Cyan>::value;
constexpr auto lightgray    = ColorString<LightGray>::value;
constexpr auto darkgray     = ColorString<DarkGray>::value;
constexpr auto lightred     = ColorString<LightRed>::value;
constexpr auto lightgreen   = ColorString<LightGreen>::value;
constexpr auto lightyellow  = ColorString<LightYellow>::value;
constexpr auto lightblue    = ColorString<LightBlue>::value;
constexpr auto lightmagenta = ColorString<LightMagenta>::value;
constexpr auto lightcyan    = ColorString<LightCyan>::value;
constexpr auto white        = ColorString<White>::value;

} // namespace bg
} // namespace color

namespace fg_clr = color::fg;
namespace bg_clr = color::bg;

constexpr const ColorCode FG_DEFAULT = color::fg::Default;
constexpr const ColorCode BG_DEFAULT = color::bg::Default;

constexpr auto fg_default    = fg_clr::reset;
constexpr auto bg_default    = bg_clr::reset;
constexpr auto color_default = fg_clr::reset + bg_clr::reset;

#endif // COLORS_HPP

