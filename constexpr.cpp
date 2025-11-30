#include "include.h"

int getNumber(){
    return 42;
}

constexpr int getConstNumber(){
    return 42;
}

constexpr int Add(int x, int y){
    return x+y;
}

int main(){
    constexpr int i = 10; // can be used where compile time constant is required like
    int arr[i];

    // this is also a compile time constant
    const int j = 10;

    // but this is NOT evaluated at compile time
    const int k = getNumber();

    // constexpr int i = getNumber(); // this won't work, because getNumber() is not constexpr function.

    constexpr int l = getConstNumber(); // return value will be computed at COMPILE time
    const int m = getConstNumber(); // return value will be computed at COMPILE time
    int n = getConstNumber(); // return value will be computed at RUN time

    constexpr int p = Add(3,4); // computed at COMPILE time
    int q = Add(3,4); // computed at RUN time

    const int x = 1, y = 2;
    constexpr int r = Add(x,y); // does not work with non-const inputs
    
}

/*
constexpr represents an expression that is constant and can be evaluated at compile time
can be applied to variables or functions.
If a function returns a value that can be computed at compile time, it can be constexpr function.
From C++14, constexpr functions can have more than one line of code. Prior to this, only one statement i.e. return statement was allowed.
constexpr functions are implicityly inlined. They must be defined in header files.


*/