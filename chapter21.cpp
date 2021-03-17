#include <iostream>

// Local scope
// when create an object, it can be used in its local scope

// lifetime: the time of object spends in memmory (storage duration, have many types)

/* automatic storage duration: automatically allocated the duration at the beginning of a block
   and deallocated when the code block ends
   it is called stack memmory, all objects have this storage duration
*/

// dynamic storage duration: manually allocate and deallocate duration (heap memmory)
// do this by new and smart pointer(prefer smart pointer)

// static storage duration: allocate when the program start and deallocate when the program end
// can access at any given time when the program is executed
void local();
int main(void)
{
    int x = 1; // this x can be use in the main function before the { and will continue be used after a }
    std::cout << "First x is: " << x << '\n';

    {
        int x = 2; // this x can be used in the nearest brackets {}
        std::cout << "Second x is: " << x << '\n';
    }
    std::cout << "First x again is: " << x << '\n';

    // dynamically allocate and deallocate
    int *p = new int; // pointer p points to the new allocate integer object
    *p = 3;           // assign value
    std::cout << "The pointer p has value: " << *p << '\n';
    delete p; // deallocate
    {
        int *p = new int[3]; // allocate array
        p[0] = 0;            // assign value
        p[1] = 1;
        p[2] = 2;
        std::cout << "p array has value: " << '\n'
                  << p[0] << '\n'
                  << p[1] << '\n'
                  << p[2] << '\n';
        delete[] p; // deallocate array
    }
}
void local()
{
    int x = 0; // x is created and have a local scope in this function
    std::cout << x << '\n';
}