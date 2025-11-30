#include "include.h"
#include <initializer_list>

class Bag{
    int arr[10];
    public:
    Bag(std::initializer_list<int> data){
        int i=0;
        for( int d : data){
            arr[i++]=d;
            std::cout<<d<<std::endl;
        }
        // can also be used like a container - data.size(), access through iterators: data.begin(), data.end()
    }
};
int main(){

    // uniform initialization
    int x{0};
    std::string s{"hello"};
    int arr[5]{0,1,2,3,4};

    std::initializer_list<int> data = {0,1,2,3,4};
    auto data2 = {0,1,2,3,4}; //also an initializer list

    // initializer list can be used with user defined classes by creating a constructor that accepts an initializer_list
    Bag b{1,2,3};
}   

/*
uniform initialization introducted a new class called initializer list.
initializer_list is a class template.
It is not a true container. But has similar behaviour.
It is constructed automatically from a braced list of elements.
*/