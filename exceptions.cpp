#include "include.h"

class Test
{
    std::string s;

public:
    Test(std::string s) : s(s)
    {
        std::cout << "Acquired resources by " << s << std::endl;
    }
    ~Test()
    {
        std::cout << "Released resources by " << s << std::endl;
    }
};

int basics_ex(int n)
{
    if (n < 10)
    {
        throw std::out_of_range("count less than 10");
    }
    int *p1 = new int[n * 100];
    int *p = (int *)malloc(n * sizeof(int) * 100);
    if (p == nullptr)
    {
        throw std::runtime_error("Failed to allocate memory");
    }
    return 0;
}

int advanced_ex(int n)
{
    // this is for demonstrating stack unwinding - invoke destructors of stack objects when exception is thrown
    Test t1("Stack object"); // destructor invoked

    Test *t2 = new Test("Heap object"); // destructor NOT invoked

    std::unique_ptr<Test> t3(new Test("Smart pointer")); // destructor invoked, t3 is stack object bound to heap Test object

    if (n < 5)
    {
        throw std::out_of_range("count less than 5");
    }
    delete t2;
}

int sum(int x, int y) noexcept(true)
{
    return x + y;
}

int main()
{

    try
    {
        // basics_ex(std::numeric_limits<int>::max());
        // basics_ex(5);
        advanced_ex(2);
    }
    catch (std::runtime_error &ex)
    {
        std::cout << ex.what() << std::endl; // show information about the exception
    }
    catch (std::out_of_range &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch (std::bad_alloc &ex) // thrown by new
    {
        std::cout << ex.what() << std::endl;
    }
    catch (std::exception &ex) // can  be used for all exceptions
    {
        std::cout << ex.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "Unknown exception thrown" << std::endl;
    }
}

/*

All exceptions inherit base class std::exception and it has a virtual function called what().
If exception is thrown in constructor, destructor is not invoked.
Dont thrown exception in destructor.
If a function does not throw any exception, you can use noexcept qualifer or noexcept(true).
If you implement move operation in a class, they should be marked with noexpect(true) specifier
because move operation will be preferred by the compiler and that will improve the performance (other it will copy)
*/