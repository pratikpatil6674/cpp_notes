#include "include.h"
#include<vector>

void printVec(const std::vector<int>& v){
    for(int d : v){
        std::cout<<d<<" ";
    }
    std::cout<<"\n";
}

void unions(){
    //size of a union is size of its biggest data type
    // only one element will be active at any given moment.
    // Advantages: it saves space, useful in embedded applications.
    // if the members have user-defined default constructor/destructor, default constructor/destructor of the union also gets deleted, you cannot even use default keyword in the union in that case.

    class A{
        int *x;
        public:
        A(int y){
            x = new int(y);
            std::cout<<"Constructor of A\n";
        }
        ~A(){
            delete x;
            x=nullptr;
            std::cout<<"Destructor of A\n";
        }

        void printVal(){
            std::cout<<*x<<std::endl;
        }
    };
    union Test
    {
        int i;
        char c;
        double d;
        A a; // user defined object has its own constructor. Not trivial to define user-defined object inside union. use placement new operator.
        Test(){
            std::cout<<"Constructor of Union\n";
        }
        ~Test(){
            std::cout<<"Destructor of union\n";
        }  
    };

    Test t;
    // t.a = A{1}; // Assignment does not work because there is not object of type A at t.a Memory allocated for union Test is not initialized yet.
    new(&t.a) A{1}; // A a is active, placement new operator initializes already allocated memory of the Union.
    t.a.printVal(); // prints 1
    t.a.~A(); // destructor not invoked implicitly in union, hence call it manually

    t.c = 'a';
    std::cout<<t.c<<std::endl; // char is active
    t.i = 100;
    std::cout<<t.i<<std::endl; // now int becomes active. 
    
}
void vectors(){
    // initialize, add elements
    std::vector<int> v{0,1,2};
    v.reserve(20); // reserve space for atlease 20 elements
    for(int i = 3; i<10; i++){
        v.push_back(i);
    }
    printVec(v);

    // access elements : using index, or iterator
    int d = v[0];
    auto it = v.begin(); // std::vector<int>::iterator it = v.begin();
    for(auto it = v.begin(); it!=v.end(); it++){
        std::cout<<*it<<" ";
    }
    std::cout<<"\n";

    // delete elements
    v.erase(it+3); // v becomes [0 1 2 4 5 6 7 8 9]

    // insert elements
    v.insert(it+3, -100); // v becomes [0 1 2 -100 4 5 6 7 8 9]
}


int main(){

  
unions();
// vectors();

}