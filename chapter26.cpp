#include <iostream>

// ex1
class Person
{
private:
    std::string name;

public:
    Person() {}
    Person(std::string name)
    {
        this->name = name;
    }
    std::string getname() // return name of person
    {
        return this->name;
    }
    void setname(std::string name) // set name for person
    {
        this->name = name;
    }
};
class Student : public Person
{
private:
    int semester;

public:
    Student(std::string name, int semester)
    {
        Person::setname(name);
        this->semester = semester;
    }
    int getsemester()
    {
        return semester;
    }
};
int main()
{
    Person person{"Hoang Tam"}; // create a person in class Person
    std::string person_name = person.getname();
    std::cout << person_name << '\n';
    Student student{"Thai Tam", 2}; // create a student in the derive class Student
    std::string student_name = student.getname();
    std::cout << student_name << '\n';
    int semester = student.getsemester();
    std::cout << "Semester is: " << semester << '\n';
}
