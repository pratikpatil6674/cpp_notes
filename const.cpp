#include "include.h"
int main(){

    const int a0=0; //const always needs an initializer, unless it is a class variable(in this case, use initializer list)

    const int a = 9;
    const int* ap = &a; //pointer to const, const qualifer required
    // int *ap = (int*)&a; This works, but don't do this
    //a=0; run time error

    int b = 0;
    int d = 8;
    const int c = b; //can be assigned only once
    log(c is , c);
    //const int d; must be innitialized otherwise compile time error (CTE)

    const int* bptr1 = &b;
    b++;
    log(b is,b);
    //*bptr1 = 3; CTE, bptr1 location is read only location
    bptr1 = &d; //bptr1 can be reassigned

    int* bptr2 = &b;
    *bptr2 = 3; //bptr2 location is writable. A location is readable or writable depends on the type of pointer to that location
    log(b is,b);

    int* const dptr1 = &d;
    d++;
    log(d is, d); //works
    (*dptr1)++; //works
    log(d is, d);
    //dptr1 = &b; dptr1 is read only variable, dptr1 cannot be reassigned

    int e = 7;
    const int* const eptr = &e;
    //eptr = &e; CTE, eptr is read only variable, eptr cannot be reassigned
    //(*eptr)++; eptr location is read only.

    //int* cptr = &a; //CTE, int* cannot point to const int*, a is const int type
    const int* cptr = &a;
    //(*cptr)++; CTE as location is read only
    //int* const cptr1 = &a; CTE, int* cannot point to const int*, a is const int type

    //const reference
    const int &br = b;
    b=900;
    log(b,b);
    //br=900; assignment of read-only reference doesnt work

    //Try to modify x1 & x2 and see the compilation output
    int x = 5 ;
    const int MAX = 12 ;
    int &ref_x1 = x ;
    const int &ref_x2 = x ;

    //Try to modify the pointer (e.g. ptr1) and the pointee value (e.g. *ptr1)
    const int *ptr1 = &x ;
    int *const ptr2 = &x ;
    const int * const ptr3 = &x ;
    
    //Find which declarations are valid. If invalid, correct the declaration
    const int *ptr3 = &MAX ;
    int *ptr4 = &MAX ;
    
    const int &r1 = ref_x1 ;
    int &r2 = ref_x2 ;
    
    int *&p_ref1 = ptr1 ;
    const int*&p_ref2 = ptr2 ;

    return 0;

}

/*
const qualifier
1. Largely replaces C macros. C macros don't have scope and are not type safe
2. Commonly used with references. References are passed to functions with const qualifer
*/