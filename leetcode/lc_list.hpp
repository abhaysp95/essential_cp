// methods which would read (nested) list for leetcode input
#ifndef __LC_LIST_INCLUDED__
#define __LC_LIST_INCLUDED__

#include <iostream>
#include <cassert>
#include <sstream>
#include <string>
#include <format>
#include <type_traits>
#include <vector>

#define ASSERT_MSG(condition, msg)                                             \
  do {                                                                         \
    if (!(condition)) {                                                        \
      std::cerr << std::format(                                                \
          "Assertion failed: {}, {}\nFile: {}, line: {}\n", #condition, msg,   \
          __FILE__, __LINE__);                                                 \
      std::abort();                                                            \
    }                                                                          \
  } while (0)

template<typename T>
concept Numeric = std::is_arithmetic_v<T>;

template<Numeric T>
T get_num_from_string(const std::string& s) {
  if constexpr (std::is_same_v<int, T>) return std::stoi(s);
  else if constexpr (std::is_same_v<long, T>) return std::stol(s);
  else if constexpr (std::is_same_v<long long, T>) return std::stoll(s);
  else if constexpr (std::is_same_v<float, T>) return std::stof(s);
  else if constexpr (std::is_same_v<double, T>) return std::stod(s);
  else if constexpr (std::is_same_v<long double, T>) return std::stold(s);
}

// Returns the 1D vector for the string passed in format `[1,2,3,...]`
//
// NOTE: the method will make change in the passed string argument
template<Numeric T>
std::vector<T> read_vector(std::string& str) {
  std::vector<T> vec{};
  ASSERT_MSG(str[0] == '[', "List should be passed as [1,2,3,...]");
  str = str.substr(1, str.size()-1);
  std::istringstream istream{str};
  for (std::string s{}; getline(istream, s, ',');) {
    if (s.empty()) continue;
    vec.push_back(get_num_from_string<T>(s));
  }
  return vec;
}

// Returns the 1D vector for the string passed in format `[[1,2],[3],...]`
//
// NOTE: the method will make change in the passed string argument
template<Numeric T>
std::vector<std::vector<T>> read_vector_2d(std::string& str) {
  std::vector<std::vector<T>> res{};
  ASSERT_MSG(str[0] == '[', "Argument format should be [[1,2],[3],...]");
  str = str.substr(1,str.size()-1);
  std::istringstream istream{str};
  for (std::string s{}; getline(istream, s, ']');) {
    if (s.empty()) continue;
    std::vector<T> vec{};
    if (s[0]=='[') s = s.substr(1, s.size()-1);
    else if (s[0]==',') s = s.substr(2, s.size()-2);
    std::istringstream i2stream{s};
    for (std::string s2{}; getline(i2stream, s2, ',');) {
      if (s2.empty()) continue;
      vec.push_back(get_num_from_string<T>(s2));
    }
    res.push_back(std::move(vec));
  }
  return res;
}

// NOTE: try using both these methods with auto, and see if compiler is able to
// deduce based solely on the return type. As unlike java, C++ allows function
// overloading based on unambiguity which is combination of return type + parameters

#endif
