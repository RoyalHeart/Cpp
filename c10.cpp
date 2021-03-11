#include <iostream>

int main(void)
{
    // create an array of integer with 5 elements
    int arr[5] = {1, 2, 3, 4, 5};
    // ctreate an array of characters
    char name[] = "Tam";
    for (int i = 0; i < 5; i++)
    {
        std::cout << arr[i] << std::endl;
    }
    std::cout << name;
}
// result:
// 1
// 2
// 3
// 4
// 5
// Tam