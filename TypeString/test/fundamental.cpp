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

  cout << std::is_array_v<decltype(_double_array)> << endl;
  cout << type_string(_int)  << endl;
  cout << type_string(_double_array)  << endl;
  cout << type_string(std::array<double,4>{})  << endl;

  cout << type_string(_int_ptr)  << endl;
  cout << type_string(_uint) << endl;
  cout << type_string(_char) << endl;

  return 0;
}
