#include "include.h"
#include<typeinfo>
/*
overload type conversion operator
RTTI

*/
class Integer{
    int a;
    public:
    // use explicit keyword to avoid calling the constructor implicitly
    // explicit Integer(int x): a(x){
    Integer(int x): a(x){

    }

    // make the class polymorphic
    virtual void func(){
        std::cout<<"In Integer func\n";
    }

    //user-type(Integer) to primitive(int) conversion
    //explicit keyword required to prevent implict conversion
    explicit operator int(){
        return a;
    }
};

// create child classes
class positive_Integer : public Integer{
    public:
    positive_Integer(int x): Integer(x){

    }
    void func(){
        std::cout<<"In positive_Integer func\n";
    }
};

class negative_Integer : public Integer{
    public:
    negative_Integer(int x): Integer(x){

    }
    void func(){
        std::cout<<"In negative_Integer func\n";
    }
};

int main(){
    int a = 5, b = 2;

    float f = (float)a/b; // C style cast
    float f1 = static_cast<float>(a)/b; // C++ style, checks validity of cast

    // char* p = &a; //not allowed, cannot assign int* to char*
    char* p = (char*)&a; //allowed in C style
    char* p1 = reinterpret_cast<char*>(&a); //allowed in C++ style

    const int x = 1;
    // int* p2 = &x; //does not work, const qualifier required
    // int* p3 = (int*)&x; //works, C style cast discards the const qualifier of x, do not do this
    // int* p4 = reinterpret_cast<int*>(&x); //does NOT work, C++ style cast does NOT discard the const qualifier of x, 
    // //reinterpret_cast cannot cast away const or other type qualifiersC/C++(694)

    int* p5 = const_cast<int*>(&x); //does work

    //Primitive to user-type conversion
    Integer i{5}; //explicit call to parametrized constructor
    Integer i1 = 5; //implict call to parametrized constructor

    //user-type to primitive conversion
    int j = static_cast<int>(i); //j=5 static_cast operator required if "explicit" used to define operator int(), used to prevent implict cast

    positive_Integer pI(6);
    Integer *i2 = &pI; //upcasting
    const std::type_info &ti = typeid(*i2);
    std::cout<< "Type is "<<ti.name()<<std::endl; // Type is positive_Integer, because of virtual modifier in base class.

    
    // Base -> child, dynamic_cast verifies if Base class pointer points to child class object. If not nullptr is returned.
    positive_Integer *pI1 = dynamic_cast<positive_Integer*>(i2); // down casting, the operand of a runtime dynamic_cast must have a polymorphic class type, virtual members must be present in the class.
    std::cout<< "Type is "<<typeid(pI1).name()<<std::endl; // Type is positive_Integer, because i2 actually points to positive_Integer object

    negative_Integer nI(-6);
    i2 = &nI;
    positive_Integer *pI2 = dynamic_cast<positive_Integer*>(i2); // returns nullptr
    if(pI2 == nullptr){
        std::cout<< "i2 does not point to positive_Integer\n";
    }

    Integer &i3 = nI;
    positive_Integer& pI3 = dynamic_cast<positive_Integer&>(i3); // references cannot be null hence throws bad cast exception. Put this in a try catch block.

}

/*
C++ casting operators work at compile time
It is easy to search these casting operators in the source code.
RTTI - runtime type information is added to polymorphic classes.

*/