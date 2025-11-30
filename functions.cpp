/*
1. Function overload
2. Name mangling in C++
3. Default function arguments
4. Inline functions
5. Function pointers
*/
#include "include.h"
//1. Function overload
extern "C"
int Print(int x){
    std::cout<<x<<"\n";
    return 0;
}
int Print(float x, int y){
    std::cout<<x<<" "<<y<<"\n";
    return 0;
}

//2. Name mangling in C++
extern "C" {
    int add(int a, int b){
        return a+b;
    }
    int mul(int a, int b){
        return a*b;
    }
}

//3. Default function arguments
void default_args(const char* s, int x = 1, int y = 8, int w = 0, int z = 7){
    //default args must be given from right side
    //while calling, argument value must be provided from left side.

}

/*4. Inline functions
Inlining may improve the performance of the code, as no need of stack memory for function args and return address.
It is only a request to the compiler as compiler may choose not to inline that function, if the function is large, have too many conditional args,
recursive function, functions invoked through pointers.
inline functions be always defined in a header file if multiple source files have to use them
*/
inline int square(int x){
    return x*x;
}

// 5. Function pointers
void func_pointer(){
    // return type (*fptr_name)(arg types) = &function_name; & is not necessary
    int (*fptr)(float, int) = &Print;
    fptr(3,4);
    (*fptr)(3,4); //also works
}

#include "include.h"
int main(){

    func_pointer();

}

/*

Function overloading is a type of static polymorphism. Return type is ignored and only arguments and their types are
considered when choosing function behaviour.
*https://stackoverflow.com/questions/1041866/what-is-the-effect-of-extern-c-in-c
In every C++ program, all non-static functions are represented in the binary file as symbols.
These symbols are special text strings that uniquely identify a function in the program.
In C, the symbol name is the same as the function name. 
This is possible because in C no two non-static functions can have the same name. C doesn’t support overloading.
Because C++ allows overloading and has many features that C does not — like classes, member functions, exception specifications,
it is not possible to simply use the function name as the symbol name. 
To solve that, C++ uses so-called name mangling, which transforms the function name and all the necessary information (like the number and size of the arguments) into some weird-looking string processed only by the compiler and linker.
So if you specify a function to be extern C, the compiler doesn't perform name mangling with it and it can be directly accessed using its symbol name as the function name.
This comes handy while using dlsym() and dlopen() for calling such functions.
Due to name mangling C++ functions are not callable from C code.
extern C can be applied to only one function in a set of overloaded  functions. It is applied to both declaration and definition(if they are in separate files .h and .cpp), if .h is included in .cpp, extern C is not required in .cpp definitions.
*/