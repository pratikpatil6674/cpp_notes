#include "include.h"
void null(){
    //NULL is a macro in C and pre-C++11 and is defined to be 0 in most compilers
    //nullptr introduced in C++11 is safe and better way to initialize pointers
    log(NULL is, NULL);
}

void null_ptr(){
    //Two nullptrs are equal
    //You cannot read/write to nullptr, by dereferencing
    int *x1 = nullptr;
    int *x2 = nullptr;
    log(Two nullptrs are equal:,x1==x2);
}

class A{
    int x;
    public:
    A(int x){
        std::cout<<"Constructor called = "<<x<<std::endl;
        this->x = x;
    }
    void showData()
    {   
        log(x is,this->x);
    }
    ~A(){
        std::cout<<"Destructor called = "<<x<<std::endl;
    }
};

//unique pointer: resource is not shared
std::unique_ptr<A> fun_uniq(){

    //unique_ptr has explicit constructor, cannot use assignment, must use direct initialization, assignment to nullptr works though
    std::unique_ptr<A> p(new A(1));
    // std::unique_ptr<int[]> p1{new int[3]{1,2,3}}; dynamic array example, int[] was added in C++17

    // std::unique_ptr<A> p = std::make_unique<A>(1); //preferred way*, if constructor of A throws an exception
    log(p is:,p.get()); //get() address of resource

    std::unique_ptr<A> p2 = std::move(p); //transfer ownership to p2,
    log(p after move() is:,p.get()); //p will be 0 now
    log(p2 is,p2.get());

    p2.reset(new A(2)); //assign p2 to new object, but delete old object also, destructor of A(1) will be called.
    log(After assigning new object: p2 is,p2.get());

    return (p2); //the return value must be explictly captured otherwise p2 will be freed
}

void uniqueptr(){
    fun_uniq();
}

//custom deleters
struct Free{
    //overload function call operator
    void operator()(int* p){
        free(p);
        std::cout<<"Custom deleter invoked\n";
    }
};

void uniqPtrDeleter(){
    //must specify deleter type as template arg in case of uniq_ptr
    std::unique_ptr<int, Free> p{(int *)malloc(4), Free{}};
}

void sharedPtrDeleter(){
    //dont specify deleter type as template arg in case of shared_ptr
    std::shared_ptr<int> p{(int *)malloc(4), Free{}};
    std::shared_ptr<int> p1 = p;
    log(count is,p1.use_count()); // count = 2
}

//shared pointer: resource is shared, uses reference counting
void fun_shared(std::shared_ptr<A> p){ //pass by value increases ref count
    p->showData();
    log(pass by value: count is,p.use_count()); //count = 3, count = #references to the resource
    //if p is returned AND explicitly captured, count will remain same, otherwise decrement by 1

}
void sharedptr(){
    std::shared_ptr<A> p1(new A(1));
    // std::shared_ptr<int[]> p1{new int[3]{1,2,3}}; dynamic array example, int[] was added in C++17
    // std::shared_ptr<A> p = std::make_shared<A>(1); //preferred way*, if constructor of A throws an exception, added in C++20

    p1->showData();
    std::shared_ptr<A> p2(p1);
    p2->showData();
    log(count is,p2.use_count()); // count = 2

    fun_shared(p2);
    log(after function call count is ,p2.use_count()); // count = 2

    p2.reset(); //give up ownership, can also be used for p2.reset(new A(2))
    log(count after reset is,p1.use_count()); // count = 1

}

void weakptr(){
    //weak_ptr is used with shared_ptr
    std::shared_ptr<A> p1 = std::make_shared<A>(1);
    std::shared_ptr<A> p2 = p1;
    log(count is,p2.use_count()); // count = 2

    std::weak_ptr<A> wk = p1; // takes weak owner-ship, does not increase the ref count
    log(count remains,p1.use_count()); // count remains 2

    // p1.reset();
    // p2.reset();
    //weak-ptr can ask if the resource is alive, but it cannot keep it alive
    if(wk.expired()){
        std::cout<<"Resource is not available\n";
    }
    else{//resource is alive
        auto shared_p = wk.lock(); //create a shared_ptr to the resource
        shared_p->showData(); //use it
        log(count is,p2.use_count()); // count = 3    
    }

}


int main(){
    sharedPtrDeleter();
}

/*
A smart pointer provides the overloads of following basic operators: * ->
 RAII (resource acquisition is initialization): Lifetime of a resource is bound to a local object

 unique_ptr : copy constructor is deleted. Hence pass by value is not possible. Pass by reference is possible.
 *Don't use make_unique if you need a custom deleter or are adopting a raw pointer from elsewhere.

 smart pointers invoke delete on the underlying pointer to release resources. However, delete only works with pointers constructed using new.
 Some resources like memory created using malloc, file and stream handlers cannot be released by smartpointers.
 To be precise, smartpointers do not invoke delete, they invoke the deleter. Default deleter is the delete operator.
 If we use smart pointers for other kind resources, we can specify our custom deleter as a callback.
Custom deleters cannot be used with make_unique or make_shared

 Dynamic arrays example:
 std::uniq_ptr<int[]> p{new int[3]{1,2,3}}
*/