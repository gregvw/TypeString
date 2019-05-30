#include <iostream>
#include "ct_string.hpp"



int main( int argc, char* argv[] ) {
 
  using namespace TypeString;

  constexpr auto x = to_cts("xyz");
  constexpr auto y = to_cts("ab");
  constexpr auto z = cts_cat(x,y,x);


  return 0;

}
