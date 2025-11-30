#include "include.h"

/* unscoped enums, color names will conflict
 enum Color {RED, GREEN, BLUE};
 enum TrafficLight {RED, GREEN, BLUE};
*/

// use scoped enums always, type of enum and values can be specified as below.
// sufficient to specify only first value, increments by 1 for remaining enum values OR specify all
enum class sColor : long{RED = 2L, GREEN, BLUE};
enum class sTrafficLight : char{RED = 'r', GREEN = 'g', BLUE = 'b'};

enum byte : unsigned char {}; // byte is a new integer type
byte b{42};       // OK as of C++17 (direct-list-initialization)
// byte c = {42};     // error
byte d = byte{42}; // OK as of C++17; same value as b
// byte e{-1};       // error

void fillColor(sColor c){

    //scoped enums don't have << overloaded
    if(c==sColor::RED){
        std::cout<<"RED"<<std::endl;
    }
    
}
int main(){

    sColor c = sColor::RED;
    fillColor(c);

    //cast enum to int
    int x = static_cast<int>(sTrafficLight::RED); // prints 114
    std::cout<<x<<std::endl;

    // int n = sColor::RED; // error: no implicit conversion from scoped enum to int
}