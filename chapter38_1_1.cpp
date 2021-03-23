#include <iostream>
#include <vector>

// vector
// : a container defined in <vector> and is a sequence of contiguous elements of any types
// other container: list, forward_list, deque
int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5}; // create a vector v of int type with 5 elements
    v.push_back(6);                       // insert an element at the end of the vector
    // v = {1,2,3,4,5,6}
    std::cout << "Index 0: " << v[0] << '\n';
    std::cout << "Index 5: " << v[5] << '\n';
    int size = v.size(); // v.size() return the size of vector
    std::cout << "Size: " << size << '\n';
}