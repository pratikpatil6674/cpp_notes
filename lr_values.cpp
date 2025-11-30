#include "include.h"

// return rvalue
int add(int x, int y){

    return x+y;
}

// returns lvalue
int& transform(int &x){
    x*=x;
    return x;
}

void Print(int &x){print(Print(int &x));}
void Print(const int &x){print(Print(const int &x));}
void Print(int &&x){print(Print(int &&x));}

int main(){

    // x, y, z are lvalues, 1,2,3 are rvalues
    int x=1;
    int y=2;
    int z=3;

    // RHS expression returns rvalue
    int k = (x+y)*z;

    // LHS expression returns lvalue
    ++x = 6;
    log(x,x); //x=6

    // functions that return lvalue can be written on the LHS
    transform(x) = -1;
    log(x,x); //x=-1

    //rvalue references can only bind to rvalue
    int&& r1 = 10;
    int&& r2 = 10+99;
    // int&& r3 = x; //is error

    //lvalue references bind to lvalue, they can bind to rvalue if the reference is const
    const int& r4 = 8; //is allowed
    // int& r4 = 8; // error, temporary value cannot bind to a non-const lvalue reference

    // function overloading and rvalue references
    Print(x); // calls Print(int &x)
    Print(9); // calls Print(int &&x), if it is not present it looks for Print(const int &x). If both are not available, error.



    
}

/*
| lvalue                             | rvalue                             |
| ---------------------------------- | ---------------------------------- |
| has a name                         | does not have a name               |
| Can be assigned values             | cannot be assigned values          |
| Some expressions return lvalues    | some return rvalues                |
| l-value persists beyond expression | does not persist beyond expression |
|                                    |                                    |
*/