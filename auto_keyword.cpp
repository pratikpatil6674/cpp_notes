#include "include.h"
int main(){
    // auto <identifier> = <initializer>
    // auto is very useful with lambda expressions and templates
    auto i = 10, j = 9;
    // auto j; fails

    auto z = i+j;

    const int x = 10;
    auto var = x; //var is not const, qualifier of x is discarded, declare var with const
    auto &var1 = x; //var1 is const now
    auto ptr = &x; //qualifer is not discarded, ptr is const int*

    auto list = {1,2,3,4}; //initializer list
    auto k{1};


    return 0;

}


