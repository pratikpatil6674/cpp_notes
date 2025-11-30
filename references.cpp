#include "include.h"
void swap(int& a, int& b){
    //reference must be used
    //witout &, a, b are local copies
    int temp=a;
    a=b;
    b=temp;
}
int main(){
    //a variable is an identifier of a memory address
    //a reference to variable is an identifier of the same memory address
    int a=3;
    int &ar=a;
    log(ar,ar);
    a=5;
    log(ar,ar);

    int b=9;
    int &br=ar; //ref to a ref
    log(br,br); //works

    //example
    int c=1, d=2;
    swap(c,d);
    log(c,c);
    log(d,d);

    //rvalue initializer
    const int &cr=-1;
    log(cr,cr);

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
| Reference                                                              | Pointer                                                    |
| ---------------------------------------------------------------------- | ---------------------------------------------------------- |
| Always needs an initializer                                            | Initializer is optional                                    |
| Initializer should be lvalue(const ref can be initialized with rvalue) | Initializer need not be lvalue                             |
| Cannot be nullptr                                                      | Can be nullptr                                             |
| Bound to its referent                                                  | Can point to other variables                               |
| No storage required. Has the same memory address as its referent.      | Has its own storage, so will have different memory address |
| Dereference is not required to access value.                           | Required                                                   |
*/