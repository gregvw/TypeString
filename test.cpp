#include "IntString.hpp"
#include "Colors.hpp"
#include "TypeStringMacros.hpp"
#include <iostream>

// Currently builds and runs correctly with Clang 7 and GCC 8.1.1 using the -std=c++11 flag

REGISTER_TEMPLATE_CLASS(Foo,1);
REGISTER_TEMPLATE_CLASS(Bar,2);

struct TroubleMaker;

int main( int argc, char* argv[] ) {

  constexpr auto a = TypeString<Foo<int>>::value;
  constexpr auto b = TypeString<Bar<Foo<double>,int>>::value;
  constexpr auto c = TypeString<Bar<double,Bar<float,Bar<int,Bar<char,Foo<bool>>>>>>::value;

  static_assert( a == "Foo<int>", "Failed" );
  static_assert( b == "Bar<Foo<double>,int>", "Failed" );
  static_assert( c == "Bar<double,Bar<float,Bar<int,Bar<char,Foo<bool>>>>>", "Failed" );

  std::cout << TypeString<TroubleMaker>::value.to_string() << std::endl;
  std::cout << a.to_string() << std::endl;
  std::cout << b.to_string() << std::endl;
  std::cout << c.to_string() << std::endl;

  //std::cout << OnePlusE<0>::value << std::endl;
  //std::cout << OnePlusE<1>::value << std::endl;
  //std::cout << OnePlusE<2>::value << std::endl;
  //std::cout << OnePlusE<3>::value << std::endl;
  //std::cout << SplitNumber<3672>::first << ",";
  //std::cout << SplitNumber<3672>::rest<< std::endl;
  //std::cout << digit_string<8>().to_string() << std::endl;

  std::cout << fg_clr::white.to_string();
  std::cout << int_string<3672>().to_string() << std::endl;
  std::cout << fg_default.to_string();

    return 0;
}
