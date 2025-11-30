#include <vector>
#include <string>
#include <iostream>

void ref_seg_fault()
{
    std::vector<std::string> v;
    v.push_back("hello");

    auto& s = v[0]; // any non-const operation might invalidate such references.
    std::cout << s << std::endl;

    v.push_back("world");
    std::cout << s << std::endl; //segfault

    /*
    results in segfault
    because memory for v is moved to some other location when second string is added
    but s still holds the address of old memory because it is a reference
    */
}

int main(){
    ref_seg_fault();
     
}