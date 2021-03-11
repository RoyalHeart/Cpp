#include <iostream>
#include <string>

int main(void)
{
    // 15.1
    std::cout << "15.1" << std::endl;
    double arr[5] = {1.23, 3.45, 6.78, 9.1, 10.11};
    arr[0] = 11.12; // change the first element
    arr[4] = 13.14; // change the last element
    std::cout << "The first element of the array is: " << arr[0] << std::endl;
    std::cout << "The last element of the array is: " << arr[4] << std::endl;
    // result:
    // The first element of the array is: 11.12
    // The last element of the array is: 13.14

    // 15.2
    std::cout << "15.2" << std::endl;
    double pi = 3.1415;
    double *p = &pi;
    std::cout << "The value of the pointed-to object is: " << *p << std::endl;
    // result:
    // The value of the pointed-to object is: 3.1415

    // 15.3
    std::cout << "15.3" << std::endl;
    double mydouble = 3.1415;
    double &myreference = mydouble; // myreference and mydouble have the same value
    myreference = 6.28;
    std::cout << "The values are: " << mydouble << " and " << myreference << std::endl;
    mydouble = 9.45;
    std::cout << "The values are: " << mydouble << " and " << myreference << std::endl;
    // result:
    // The values are: 6.28 and 6.28
    // The values are: 9.45 and 9.45

    //15.4
    std::cout << "15.4" << std::endl;
    std::string s1 = "Hello";
    std::string s2 = "World!";
    std::string s3 = s1 + ' ' + s2; // concatenate Hello, ' ', and World!
    std::cout << "The final string is: " << s3 << std::endl;
    // result:
    // The final string is: Hello World!

    //15.5
    std::cout << "15.5" << std::endl;
    std::string fullname;
    std::cout << "Please enter your fullname: ";
    std::getline(std::cin, fullname); // input fullname
    std::cout << "Your full name is: " << fullname << std::endl;
    // result:
    // Please enter your fullname: Thai Hoang Tam
    // Your full name is: Thai Hoang Tam

    //15.6
    std::cout << "15.6" << std::endl;
    std::string fullname6 = "Thai Hoang Tam";
    std::string firstname = fullname6.substr(0, 10);
    std::string lastname = fullname6.substr(11, 3);
    std::cout << "The full name is: " << fullname6 << std::endl;
    std::cout << "The first name is: " << firstname << std::endl;
    std::cout << "The last name is: " << lastname << std::endl;
    // result:
    // The full name is: Thai Hoang Tam
    // The first name is: Thai Hoang
    // The last name is: Tam

    //15.7
    std::cout << "15.7" << std::endl;
    std::string s7 = "Hello C++ World.";
    char c = 'C';
    auto found = s7.find(c);
    if (found != std::string::npos)
    {
        std::cout << "Character found at the position: " << found << std::endl;
    }
    else
    {
        std::cout << "Character was not found." << std::endl;
    }
    // result:
    // Character found at the position: 6

    //15.8
    std::cout << "15.8" << std::endl;
    std::string s8 = "Hello C++ World.";
    std::string substring = "C++";
    auto substringfound = s8.find(substring); // use auto to deduce std::string::size_type
    if (substringfound != std::string::npos)
    {
        std::cout << "Substring found at position: " << substringfound << std::endl;
    }
    else
    {
        std::cout << "Substring was not found." << std::endl;
    }
    // result:
    // Substring found at position: 6

    //15.9
    std::cout << "15.9" << std::endl;
    auto a = 'a';
    auto b = 2;
    auto d = 123.456;
    std::cout << "The type of a is deduced as char, the value is: " << a << std::endl;
    std::cout << "The type of b is deduced as int, the value is: " << b << std::endl;
    std::cout << "The type of d is deduced as double, the value is: " << d << std::endl;
    // result:
    // The type of a is deduced as char, the value is: a
    // The type of b is deduced as int, the value is: 2
    // The type of d is deduced as double, the value is: 123.456
}
