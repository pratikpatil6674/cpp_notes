#include "include.h"
int main(){
    //Different methods are used to initialize scalar and array types before C++11

    //Initialize scalars
    int a1; //uninitialized
    int a2 = 0; //copy initialization
    int a3(5); //Direct initialization, int a3() does not work
    log(a3,a3); //works

    std::string s1("hello"); //Direct initialization, string is user-defined type
    log(s1,s1); //works

    //Initialize arrays
    char c1[4]; //uninitialized
    char c2[4] = {'\0'};
    char c3[4] = {'a', 'b', 'c', 'd'}; //aggregate initialization
    char c4[4] = {"abc"}; //last char reserved for null char
    log(c3,c3); // DANGER!! it will print c3+c4

    /**************C++11 introduced Uniform initization**************/

    int a4{}; //value initialization, initialized to default values of the primitive types
    int a5{5}; //Direct initialization

    char c5[4]{}; //Direct initialization
    char c6[4]{"abc"}; //Direct initialization

    //can be used for heap allocated objects
    int *p1 = new int; //uninitialized
    int *p2 = new int{}; //initialized to default value
    log(*p1,*p1); //=0
    log(*p2,*p2); //=0

    char *c7 = new char[4]{}; 
    //char *c8 = new char[4]{"abc"}; //Was not possible earlier, but requires -fpermissive flag

    return 0;
}

/* Summary
# Types
1. Value initialization => T obj{}
2. Direct initialization => T obj{v}
3. Copy initialization => T obj=v

# Benefits
1. It forces initialization
2. Direct initialization can be used with arrays too
3. It prevents narrowing conversions (assigning float to int)
    e.g. float f{}; int i{f}; will throw warning or errors
4. Uniform syntax for all types
*/