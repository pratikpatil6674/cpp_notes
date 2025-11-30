#pragma once

#include <iostream>
#include <cmath>
#include <memory>
#include <thread>
#include <chrono>
#include <string>
#include <vector>
#include <list>
#include "prettyprint.hpp"
#define log(s,x) std::cout<<#s<<" = "<<(x)<<std::endl

// print without newline
template<class... Args>
void print(Args... args)
{
    ((std::cout << args), ...);
    std::cout<<" ";
}
// template <typename Container>
// void print(const Container &c) {
//     for (auto e: c){
//         std::cout<<e<<" ";
//     }
// }
// void print(const char *s){
//     std::cout<<s;
// }
// void print(std::string s){
//     std::cout<<s;
// }


// print with newline
template<class... Args>
void println(Args... args)
{
    ((std::cout << args << " "), ...);
    std::cout<<"\n";
}
// template <typename Container>
// void println(const Container &c) {
//     for (auto e: c){
//         std::cout<<e<<" ";
//     }
//     std::cout<<"\n";
// }
// void println(const char *s){
//     std::cout<<s<<"\n";
// }
// void println(std::string s){
//     std::cout<<s<<"\n";
// }
//C headers
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
