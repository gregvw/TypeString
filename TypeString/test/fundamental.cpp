#include "type_string.hpp"
#include <iostream>
#include <array>
#include <vector>
#include <iomanip>
#include <typeinfo>

namespace TypeString {

template<typename T, size_t N>
struct type_cts<std::array<T,N>> {
  static constexpr auto value = in_namespace("std") +
	                        class_name("array") +
	                        angle_brackets( type_cts_v<T> + comma + integer_v<N> );
};


} // namespace TypeString

#define PRINT_TYPE(X) \
std::cout << type_string<decltype(X)>() << std::endl;


using namespace TypeString;







int main( int argc, char* argv[] ) {


  std::array<int,10> x;
  std::array<std::array<float,5>,10> y;


  PRINT_TYPE(x);
  PRINT_TYPE(y);

  return 0;
}
