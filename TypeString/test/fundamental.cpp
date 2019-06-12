#include "type_string.hpp"
#include <iostream>
#include "stl_types.hpp"
#include <iomanip>
#include <typeinfo>

template<typename> struct is_templated : public std::false_type {};

#define PRINT_TYPE(X) \
std::cout << type_string<decltype(X)>() << std::endl;

using namespace TypeString;

int main( int argc, char* argv[] ) {

  int i  = 10;
  int* p = &i;

  std::array<int,10> x;

  auto m = std::make_unique<std::map<std::string,int>>();

  std::vector<char> y(10);

  auto q = std::make_tuple(i,p,x,y);

  PRINT_TYPE(i);
  PRINT_TYPE(p);
  PRINT_TYPE(x);
  PRINT_TYPE(m);
  PRINT_TYPE(y);
  PRINT_TYPE(q);
  



  return 0;
}
