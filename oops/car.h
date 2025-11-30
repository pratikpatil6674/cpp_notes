#pragma once
#include "../include.h"
/*
constructor overload
copy/move constructors
delete keyword
const member functions
operator overload
global overloads
friend functions
*/
class car
{
private:
    int *car_type;
    float fuel, speed;
    int passengers;
    static int total_count;

public:
    car();
    car(float amount);                 // overloaded constructor
    car(float amount, int passengers); // overloaded constructor
    car(const car &obj);               // copy constructor, const because we are passing obj by reference
    car(car &&obj);                    // move constructor, 
    ~car();

    car operator +(const car &a)const;  //overload + operator
    car& operator ++();  //overload ++ pre-increment operator, return reference
    car operator ++(int);  //overload ++ post-increment operator, return reference, int arg for distinguishing the two overloads
    bool operator ==(const car &a)const;  //overload == operator
    car& operator =(const car &a);  //overload = copy assignment  operator, car a=b is not assignment(it is copy), a=b is assignment
    car& operator =(car &&a);  //overload = move assignment  operator,
    void operator()(); //function call operator overload, extensively used in STL, can accept any number of args, can be used with templates to implement callbacks

    void fill_fuel(float amount);
    void accelerate();
    void brake();
    void add_passengers(int count);

    /*usage of delete keyword*/
    void add_passengers(float) = delete;

    void dashboard() const; // const function, because it does not change member variables

    static void show_count();

    //friend functions, global overload
    friend std::ostream& operator<<(std::ostream& out, const car &c);
    friend std::istream& operator>>(std::istream& in, car &c);
};

/*
we should use member initializer lists to initialize members of a class. It allows initialization of member variables without assignment.

Abstraction: hide unnecessary details of objects, it is represented through a class, struct, interface, union, or enum
Encapsulation: Hides the implementation details
Inheritance : relationships and hierarchy of classes
Compositions :
Polymorphisms
Non-static data memebers cannot use auto keyword.
this pointer : useful only in class member functions. It is a pointer to the object that is calling this member function.
Automatically inserted when accessing class variables.

Static functions: cannot acess non-static members of the class. this pointer is not passed to static functions.
It can be called with classname which is preferred or any object
Static functions and variables do not belong to any object and they must be defined outside the class.

Const functions: cannot change any member variables, constant object can invoke only const member functions,
const functions can invoke only other const member functions.

copy constructors: copy object's state into another object. If a copy constructor is not provided, it is synthesized automatically by the compiler.
It simply copies values. It might be undesirable specially if class has ownership semantics(owns a resource). 
Without user-defined copy constructor, the compiler generated copy constructor will perform a shallow copy that will lead to undefined results.
Copy of an object is created when it is passed by value to a function or returned as a value by a function, or assignment is used between two objects.
In those cases, copy constructor is invoked.
Shallow copy : is copy only address of an object into another object. Both objects point to same block of memory on heap or stack.
Deep copy : is copy the variables, pointers(and the memory it points to), into another memory location

delegated constructor: call is made the delegated constructor first.

delete keyword is used to prevent the compiler from creating default implementations of some functions.
e.g to stop compiler from creating default copy constructor, set it to delete

Rule of 5:
If a class has ownership semantics, it must provide a user-defined: destructor, copy constructor, copy assignment operator, move constructor
and move assignment operator
Rule of 0:
If there are no ownership semantics and you do not implement custom copy or/and move constructors, then the compiler will not synthesize some
constructors or operators. The rules regarding this are not simple. They are described in ruleof0.png.

copy elison: copying of objects is omitted by the compiler

std::move(x) is always used with lvalues. Internally, it typecasts x to rvalue reference, hence a move constructor is invoked
x goes in unspecified state. std::move is useful with non-copiable objects-objects that contain stream, thread resources.
Usage of std::move on primitive type is redundant.

Operator overloading: custom implementation of primitive operators for user-defined objects.
It can be implemented as member functions or global functions(number of arguments = number of operands.)
If implemented as member function, one operand is passed as argument through this pointer.
Rules of operator overloading:
Associativity, precedence, arity(operand count) does not change.
Operator functions should be non-static (except for new&delete).
One argument should be user defined type.
Global overload if first operand is primitive type.
. ?: .* # sizeof cannot be overloaded.
cannot define new operators.
Overloaded for conventional behaviour only.
If the second operand of a binary operator is a primitive type, then you can overload as member or global function "as long as first operand is a user defined type".
Example: Number n1(1); cout << n1 << endl ; is resolved as-
operator<<(cout,n1).operator<<endl;
The operator << returns a cout object and that invokes the operator<< for endl operand, as it is already overloaded in the ostream class


Friend functions can access private, public, protected members of the class. Usage is usually discouraged.
*/