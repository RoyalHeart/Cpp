#include <iostream>
// include header <string> to use string
#include <string>

int main(void)
{
    // create strings s1, s2
    // string is a class-template
    std::string s1 = "Hoang";
    std::string s2 = "Tam";

    // concatenate 2 strings (can be a string and/or a charater)
    s1 += " " + s2;
    std::cout << s1 << std::endl;

    // accessing characters in a string
    std::cout << s1[0] << std::endl;
    std::cout << s1.at(1) << std::endl;

    // comparing strings
    if (s1 == "Hoang Tam")
    {
        std::cout << "s1 is equal to Hoang Tam" << std::endl;
    }
    if (s1 == s2)
    {
        std::cout << "s1 is equal to s2" << std::endl;
    }
    else
    {
        std::cout << "s1 is not equal to s2" << std::endl;
    }

    // input string
    std::cout << "Please input a string" << std::endl;
    std::string s3;
    std::getline(std::cin, s3); // getline to make the string have white spaces
    // getline(read_from, into) read_from: standard input cin, into: string s3
    std::cout << s3 << std::endl;

    // pointer to string
    std::string s4 = "Hello World";
    std::cout << *s4.c_str() << std::endl; // c_str() returns the pointer to the first element of the string
    // type const char*

    // substrings
    std::string s5 = "Hi, How are you?";
    std::string substring = s5.substr(4, 3); // substr returns a string from a start position and length. substr(start, length)
    std::cout << substring << std::endl;

    // find substring
    std::string s6 = "C plus plus";
    std::string substring_to_find = "plus";
    std::string::size_type found = s6.find(substring_to_find);
    // type std::string::size_type
    // string.find(substring) returns the first position that the substring appear in the string

    // if can not find the subtring, find() returns std::string:npos
    if (found != std::string::npos)
    {
        std::cout << "The subtring is found at: " << s6.find(substring_to_find) << std::endl;
    }
    else
    {
        std::cout << "Can not find the substring" << std::endl;
    }
}
// result:
// Hoang Tam
// H
// o
// s1 is equal to Hoang Tam
// s1 is not equal to s2
// Please input a string
// a string
// a string
// H
// How
// The subtring is found at: 2