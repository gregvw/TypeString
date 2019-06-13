cmake_minimum_required( VERSION 3.9.6 )

project( TypeString VERSION 0.0.1 LANGUAGES CXX )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )


set( TYPESTRING_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/include )

add_subdirectory(test)


