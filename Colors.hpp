#pragma once
#ifndef COLORS_HPP
#define COLORS_HPP

using ColorCode = std::size_t;

namespace ColorFG {
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
} // namespace ColorFG

namespace ColorBG {
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
} // namespace ColorBG

template<ColorCode C=ColorFG::Default> 
struct ColorForeground {
  static constexpr auto value = static_string("\033[") +
                                int_string<C>() + 
                                static_string("m");                    
  static constexpr auto digits = num_digits<C>();
};

template<ColorCode C=ColorFG::Default> 
struct ColorBackground {
  static constexpr auto value = static_string("\033[") +
                                int_string<C>() + 
                                static_string("m");                    
  static constexpr auto digits = num_digits<C>();
};

template<ColorCode C>
constexpr StaticString<ColorForeground<C>::num_digits>
fg_color() {
  return ColorForeground
}

#endif //COLORS_HPP

