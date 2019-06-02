#include "type_string.hpp"
#include <iostream>
#include <array>
using namespace TypeString;


int main( int argc, char* argv[] ) {

  using std::cout; 
  using std::endl;

  int  _int          = 4;
  unsigned int _uint = 3u;
  char _char         = 'x';
  
  int* _int_ptr = &_int;

  double _double_array[10];

  cout << type_string<decltype(_int)>()           << endl;
  cout << type_string<decltype(_double_array)>()  << endl;

  return 0;
}
