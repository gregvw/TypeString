#include <iostream>
#include "ct_string.hpp"
#include "colordefs.hpp"
#include "preprocessor.hpp"

#define TEST_COLOR( COLOR )                                           \
{                                                                     \
  constexpr auto s = color(f_##COLOR) + QUOTE(COLOR) + reset_color;   \
  cout << s.to_string() << endl;                                      \
}

#define TEST_ATTR( ATTR )                                             \
{                                                                     \
  constexpr auto s = color(s_##ATTR) + QUOTE(ATTR) + reset_color;     \
  cout << s.to_string() << endl;                                      \
}


int main( int argc, char* argv[] ) {
 
  using std::cout;
  using std::endl;
  using namespace TypeString;
  
  TEST_COLOR(green);
  TEST_COLOR(red);
  TEST_COLOR(yellow);
  TEST_COLOR(blue);
  TEST_COLOR(magenta);
  TEST_COLOR(cyan);
  TEST_COLOR(light_gray);
  TEST_COLOR(dark_gray);
  TEST_COLOR(light_green);
  TEST_COLOR(light_red);
  TEST_COLOR(light_yellow);
  TEST_COLOR(light_blue);
  TEST_COLOR(light_magenta);
  TEST_COLOR(light_cyan);
  TEST_COLOR(white);
  cout << "----------" << endl;
  TEST_ATTR(normal);
  TEST_ATTR(bold);
  TEST_ATTR(faint);
  TEST_ATTR(italic);
  TEST_ATTR(underline);
  TEST_ATTR(slow_blink);
  TEST_ATTR(crossed);
  TEST_ATTR(overline);

  return 0;

}
