#include "include.h"

// this is a function pointer
// using Comparator = bool(*)(int, int);


template<typename T, typename Comparator>
void Sort(T& t, Comparator comp) {
    using eType = typename T::value_type; // get value of container's element type
	for (int i = 0; i < t.size()-1; ++i) {
		for (int j = 0; j < t.size() - 1; ++j) {
			if (comp(t[j], t[j + 1])) {
                eType temp = std::move(t[j]); // move is used for user-defined objects
				t[j] = std::move(t[j + 1]);
				t[j + 1] = std::move(temp);
			}
		}
	}
}
//Function pointers as comparators
bool CompDesc(int x, int y) {
	return x > y;
}
bool CompAsc(int x, int y) {
	return x < y;
}

// this is a function object, can store state information
struct CompObject {
	bool operator()(int x, int y) {
		return x > y;
	}
};

void function_pointers_vs_objects(){
	CompObject comp;
	comp(3, 5);//comp.operator()(3,5) ;
	std::array<int, 5> arr{ 1,6,8,4,0 };
    println("Before sorting:");
    println(arr);
	Sort(arr, comp); // function object
    println("After sorting");
    println(arr);

	std::array<int, 5> arr2{ 1,6,8,4,0 };
    println("Before sorting");
    println(arr);
    Sort(arr2, CompDesc); // function pointer
    println("After sorting");
    println(arr2);
}

void lambda(){
    //[capture clause](<args>)<mutable> <exception specification> -> <return type> {...function body...}
    auto func = [](){
        println("Hello world");
    };
    func();
    println("Type of lambda function is :", typeid(func).name());

    auto sum = [](int x, int y) -> int {
        println(x+y);
        return x+y;
    };
    sum(3,2);

    // generic lambda, can accept any argument type
    auto gen_sum = [](auto x, auto y) noexcept {
        println(x+y);
    };
    gen_sum(2.3, 7.2);
    gen_sum(2, 7);
}

int main(){
    //function_pointers_vs_objects();
    lambda();
}










/*
Function object : Object with overloaded function call operator.
Advantage of function object over function pointer is that it can be inlined and become faster.
Function object can save state.
Lamda expressions are better way to implement callbacks than function objects.
Lambda expression is a syntactic shortcut for a function object. we dont need to create struct or class.
It is implemented as a nameless function object internally by compiler. We can assign a name by auto name = lambda expression.



*/