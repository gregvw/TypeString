#pragma once
#ifndef STL_TYPES_HPP
#define STL_TYPES_HPP

#include <array>
#include <list>
#include <map>
#include <memory>
#include <string>
#include <tuple> 
#include <utility>
#include <vector>


#define STL_CLASS_1(NAME) \
template<typename T>      

namespace TypeString {

template<template<typename...> class Object, typename...Ts>
constexpr auto tparams( Object<Ts...> ) {
  return angle_brackets( delimited( comma, type_cts_v<Ts>... ) );
}

// Allocator
template<typename T>
struct type_cts<std::allocator<T>> {
  static constexpr auto value = in_namespace("std") + 
                                class_name("allocator") + 
                                angle_brackets( type_cts_v<T> );
};

// array
template<typename T, size_t N>
struct type_cts<std::array<T,N>> {
  static constexpr auto value = in_namespace("std") +
                                class_name("array") +
                                angle_brackets( type_cts_v<T> + comma + integer_v<N> );
};

// map 
template<typename key_type, typename value_type> 
struct type_cts<std::map<key_type,value_type>> {
  static constexpr auto value = in_namespace("std") + 
                                class_name("map") + 
                                angle_brackets( type_cts_v<key_type> + comma 
                                                + type_cts_v<value_type> );
};

// pair
template<typename first_type, typename second_type>
struct type_cts<std::pair<first_type,second_type>> {
  static constexpr auto value = in_namespace("std") + 
                                class_name("pair") +
                                angle_brackets( first_type{} + comma + second_type{} );
};

// shared_ptr
template<typename T>
struct type_cts<std::shared_ptr<T>> {
  static constexpr auto value = in_namespace("std") + 
                                class_name("shared_ptr") + 
                                angle_brackets( type_cts_v<T> );
};

// string
template<>
struct type_cts<std::string> {
   static constexpr auto value = in_namespace("std") + 
                                 class_name("string");
};

// tuple 
template<typename... Ts>
struct type_cts<std::tuple<Ts...>> {
  static constexpr auto value = in_namespace("std") +
                                class_name("tuple") +
                                angle_brackets( delimited( comma, type_cts_v<Ts>... ) );
};

// unique_ptr
template<typename T, typename Deleter>
struct type_cts<std::unique_ptr<T,Deleter>> {
  static constexpr auto value = in_namespace("std") + 
                                class_name("unique_ptr") + 
                                angle_brackets( type_cts_v<T> + comma + type_cts_v<Deleter> );
};

// vector
template<typename T, typename Allocator>
struct type_cts<std::vector<T,Allocator>> {
  static constexpr auto value = in_namespace("std") + 
                                class_name("vector") + 
                                angle_brackets( type_cts_v<T> + comma +
                                                type_cts_v<Allocator> );
};

} // namespace TypeString

#endif //STL_TYPES_HPP

