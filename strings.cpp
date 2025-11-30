#include "include.h"
#include <sstream>

void basics();
void string_stream();
/*
std::string class overloads == != > < 
*/
int main(){
string_stream();
    
}
void basics(){
// initialize, assign or read from console
    std::string s1{"hello"};
    std::string s2 = "world";

    //read from console
    std::string s;
    // std::cin>>s; // cin will stop at first space
    std::getline(std::cin, s); // newline char is NOT read
    std::cout<<s<<std::endl;

    // Access
    s1[0] = 'H';
    s2[0] = 'W';
    char c = s1[0];

    // length() - constant time operation unlike strlen() which is linear
    int l = s1.length() ;

    // concatenate
    std::string s3 = s1 + s2;
    std::string s4 = s1 + " " + s2;
    std::cout<<s4<<std::endl;

    // substring find(char or string, position from where to start search)
    auto pos = s4.find("World", 0);
    if(pos != std::string::npos){ //npos = Value returned by various member functions when they fail.
        std::cout<<"String found\n";
    }

    // remove a char form the string erase(start, number of chars to remove), empty args will erase the string
    s.erase(1, 3);
    std::cout<<s<<std::endl;

    //clear the string
    s.clear();

    // extract the raw c-style string 
    printf("%s\n", s4.c_str());
}
void string_stream(){
    // string streams are used for writing/reading to/from formatted data
    int a =8, b = 9;

    // cout can created formatted text but it writes to stdout, what if want to store it in a string
    std::cout<<"Sum of "<<a<<" & "<<b<< " is "<<a+b<<std::endl;

    // create a string stream and write to it
    std::stringstream ss;
    ss<<"Sum of "<<a<<" & "<<b<< " is "<<a+b<<std::endl;

    // extract the string from the stream
    std::string s = ss.str();
    std::cout<<s;

    // we can also reset the stream buffer
    ss.str("");

    // we can also read from the stream, ignores spaces
    ss.str("12 -2 3 -1.9   34");
    float c;
    while(ss>>c){
        std::cout<<c<<std::endl;
    }

}