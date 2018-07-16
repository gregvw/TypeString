TypeString
----------

Tools to create static TypeStrings at compile time from fundamental types and
template classes. Preprocessor macros are not necessary to define TypeStrings,
however, I have created a couple to rapidly define the fundamental types and
classes with arbitrary numbers of template parameters

TODO:  handling for template template types

Currently works with GCC 8.1.1 and Clang 7

$ g++ -std=c++11 test.cpp


