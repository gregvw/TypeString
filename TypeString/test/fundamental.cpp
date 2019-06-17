#include "type_string.hpp"

using namespace TypeString;

template<typename T>
void test_function( volatile T& x, const T& y ) {
  PRINT_TYPE(x);
  PRINT_TYPE(y);
}

void rvalue( int&& x ) {
  PRINT_TYPE(x);
}

class Foo {};

int main( int argc, char* argv[] ) {

  int i  = 10;
  int* p = &i;
  
  unsigned u = 20u;

  long l = 100000l;
  unsigned short us = 4u;

  double g1 = 4.0, g2 = 5.0;
  wchar_t wc;

  double* v[10][5];

  PRINT_TYPE(i);
  PRINT_TYPE( u );
  PRINT_TYPE( u*i );
  PRINT_TYPE( u+i );

  PRINT_TYPE(l);
  PRINT_TYPE(us);
  PRINT_TYPE(us+l);

  PRINT_TYPE(p);
  PRINT_TYPE(wc);
  PRINT_TYPE(v);
  PRINT_TYPE(&rvalue);

  PRINT_TYPE(&test_function<double>);
  test_function(g1,g2);

  rvalue(2*i);
  PRINT_TYPE(&rvalue);

  PRINT_TYPE( Foo{} );

  return 0;
}
