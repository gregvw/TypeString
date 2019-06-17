cmake_minimum_required( VERSION 3.9.6 )

project( TypeString VERSION 0.0.1 LANGUAGES CXX )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )


set( TYPESTRING_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/include )

add_subdirectory(test)

install( FILES ${TYPESTRING_INCLUDE}/colordefs.hpp
               ${TYPESTRING_INCLUDE}/ct_string.hpp
               ${TYPESTRING_INCLUDE}/digits.hpp
               ${TYPESTRING_INCLUDE}/fundamental_types.hpp
               ${TYPESTRING_INCLUDE}/preprocessor.hpp
               ${TYPESTRING_INCLUDE}/size_constant.hpp
               ${TYPESTRING_INCLUDE}/stl_types.hpp
               ${TYPESTRING_INCLUDE}/type_cts.hpp
               ${TYPESTRING_INCLUDE}/type_string.hpp
               ${TYPESTRING_INCLUDE}/type_string_macros.hpp
       DESTINATION type_string )

