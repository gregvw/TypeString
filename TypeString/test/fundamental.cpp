#include "type_string.hpp"
#include <iostream>
#include "stl_types.hpp"
#include <iomanip>
#include <typeinfo>

template<typename> struct is_templated : public std::false_type {};


#define PRINT_TYPE(X) \
std::cout << "type(" << QUOTE(X) << ") = " << type_string<decltype(X)>() << std::endl;


using namespace TypeString;

template<typename X, typename Y> 
auto product( X x , Y y ) { return x*y; }

int main( int argc, char* argv[] ) {

  int i  = 10;
  int* p = &i;

  double* v[10][5];
  std::array<int,10> x;

  auto m = std::make_unique<std::map<std::string,int>>();

  std::vector<char> y(10);

  auto q = std::make_tuple(i,p,x,y);

  PRINT_TYPE(i);
  PRINT_TYPE(p);
  PRINT_TYPE(v);
  PRINT_TYPE(x);
  PRINT_TYPE(m);
  PRINT_TYPE(y);
  PRINT_TYPE(q);


  PRINT_TYPE(std::cout); 


  return 0;
}
