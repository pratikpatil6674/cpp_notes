#include "./../include.h"
#include "car.h"

/*
std::move(x)
*/

int main()
{
    goto io_overload;

    {
    move_func:
        car c = car(25.0f);
        car d{std::move(c)}; // move the state of c into d

        exit(0);
    }

    {
    op_load:
        car a(1,2);
        car b(3,4);
        car c = a+b; // use of operator+ overload
        c.dashboard();
        c = b; // assignment operator= overload
        c.dashboard();
        //++a; // use of operator++ overload
        (a++).dashboard();

        if(a==b)std::cout<<"Equal\n"; // use of operator== overload
        exit(0);

    }
    {
    io_overload:
        car a(1,2);
        std::cin>>a;
        std::cout<<a<<std::endl;
        a(); // function call overload
        exit(0);

    }
}

