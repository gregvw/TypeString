#include "StaticString.hpp"
#include "TypeString.hpp"
#include <iostream>

// Currently builds and runs correctly with Clang 7 and GCC 8.1.1 using the -std=c++11 flag

REGISTER_TEMPLATE_CLASS(Foo,1);
REGISTER_TEMPLATE_CLASS(Bar,2);

int main( int argc, char* argv[] ) {

    constexpr auto a = TypeString<Foo<int>>::value;
    constexpr auto b = TypeString<Bar<Foo<double>,int>>::value;
    constexpr auto c = TypeString<Bar<double,Bar<float,Bar<int,Bar<char,Foo<bool>>>>>>::value;

    static_assert( a == "Foo<int>", "Failed" );
    static_assert( b == "Bar<Foo<double>,int>", "Failed" );
    static_assert( c == "Bar<double,Bar<float,Bar<int,Bar<char,Foo<bool>>>>>", "Failed" );

    std::cout << a.to_string() << std::endl;
    std::cout << b.to_string() << std::endl;
    std::cout << c.to_string() << std::endl;

    return 0;
}
