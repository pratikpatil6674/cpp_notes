#include "include.h"
/*
user defined literals

*/
class Distance{
    long double m_Kilometers;

    public:
    Distance(long double km): m_Kilometers(km) {
        std::cout<<m_Kilometers<<std::endl;
    }
};

Distance operator"" _mi(long double mi){
    return Distance{mi*1.6};
}

Distance operator"" _meters(long double m){
    return Distance{m/1000};
}

int main(){
    Distance d1{10.0_mi};
    Distance d2{1000.0_meters};
}

/*
User defined literals can only be used for integer, floats, character, string literals.
They must always start with an underscore.
Literals without underscore are reserved for standard library.
Cannot redefine the meaning of built-in literal suffixes.
Literal operator functions cannot be member functions. Only global functions.


*/