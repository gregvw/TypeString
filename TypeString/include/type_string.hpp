#pragma once
#ifndef TYPE_STRING_HPP
#define TYPE_STRING_HPP

#include <cstddef>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>

#include "preprocessor.hpp"
#include "ct_string.hpp"
#include "colordefs.hpp"
#include "digits.hpp"
#include "type_cts.hpp"
#include "fundamental_types.hpp"
#include "type_string_macros.hpp"
#include "stl_types.hpp"

#define PRINT_TYPE(X) \
std::cout << "type(" << QUOTE(X) << ") = " << TypeString::type_string<decltype(X)>() << std::endl;


#endif //TYPE_STRING_HPP

