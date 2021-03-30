#include <iostream>
// #include "header.h"

// organizing code

// 2 kinds of files: header files and source files
// header files: have .h or .hpp extension, have declaration and constants
// source files: have definitions and main program
// use #include <header_name>
// compiler combine header and source files into translation unit -> object file -> linker links -> program

// header guards
// it ensures that our header content is included only once in the compilation process
// #ifndef MY_HEADER_H
// #define MY_HEADER_H
// #endif

// namespace
// is a scope with a name
// many namespace can have the same name of object because it is different scope

namespace A_namespace
{
    int i;
    double d;
}
namespace A_namespace // extending namespace
{
    int i2;
    char c;
}

using namespace A_namespace; // using all namespace object

int main()
{
    A_namespace::i = 31;
    A_namespace::d = 31.1;
    d = 31.2;
    c = 'n';
    std::cout << A_namespace::i << " " << A_namespace::d << '\n';
    std::cout << d << '\n'
              << c << '\n';
}