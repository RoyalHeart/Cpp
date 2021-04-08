#include <iostream>
#include <vector>
#include <math.h>

class Pet
{
protected:
    std::string name;
    int code;

public:
    Pet() {}
    Pet(std::string name, int code)
    {
        this->name = name;
        this->code = code;
    }
    int getCode()
    {
        return this->code;
    }
    std::string getName()
    {
        return this->name;
    }
    virtual void makeNoise() = 0;
    bool operator==(Pet *rhs)
    {
        return this->code == rhs->getCode() && this->name == rhs->getName();
    }
};
class Dog : public Pet
{
public:
    Dog() {}
    Dog(std::string name, int code)
    {
        this->name = name;
        this->code = code;
    }
    void makeNoise()
    {
        std::cout << "Bark Bark!" << '\n';
    }
};
class Cat : public Pet
{
public:
    Cat() {}
    Cat(std::string name, int code)
    {
        this->name = name;
        this->code = code;
    }
    void makeNoise()
    {
        std::cout << "Meow Meow!" << '\n';
    }
};

class Address
{
private:
    std::string street_name;
    int house_number;
    std::string city_name;

public:
    Address()
    {
    }
    Address(std::string street_name, int house_number, std::string city_name)
    {
        this->street_name = street_name;
        this->house_number = house_number;
        this->city_name = city_name;
    }
    std::string getStreetName()
    {
        return this->street_name;
    }
    int getHouseNumber()
    {
        return this->house_number;
    }
    std::string getCityName()
    {
        return this->city_name;
    }
};
class House
{
private:
    Address address;
    std::vector<Pet *> list_of_pet;

public:
    House() {}
    House(Address address, std::vector<Pet *> list_of_pet)
    {
        this->address = address;
        this->list_of_pet = list_of_pet;
    }
    void addPet(Pet *object)
    {
        list_of_pet.push_back(object);
    }
    void removePet(Pet *object)
    {
        for (int i = 0; i < list_of_pet.size(); i++)
        {
            Pet *p1 = dynamic_cast<Pet *>(list_of_pet[i]);
            if (p1 == object)
            {
                std::cout << "Pet " << list_of_pet[i]->getName() << " is remove" << '\n';
                list_of_pet.erase(list_of_pet.begin() + i);
                i--;
            }
        }
    }
    int getHouseNumber()
    {
        return this->address.getHouseNumber();
    }
    int countPet()
    {
        int number_of_pets = list_of_pet.size();
        int dogs = 0;
        int cats = 0;
        for (int i = 0; i < number_of_pets; i++)
        {
            Dog *d = dynamic_cast<Dog *>(list_of_pet[i]);
            Cat *c = dynamic_cast<Cat *>(list_of_pet[i]);
            if (d != nullptr)
            {
                dogs++;
            }
            if (c != nullptr)
            {
                cats++;
            }
        }

        std::cout << "Number of pets in " << this->getHouseNumber() << ": " << number_of_pets << '\n';
        std::cout << "Number of dogs in " << this->getHouseNumber() << ": " << dogs << '\n';
        std::cout << "Number of cats in " << this->getHouseNumber() << ": " << cats << '\n';
        return number_of_pets;
    }
    std::string getStreetName()
    {
        return this->address.getStreetName();
    }
};
class City
{
private:
    std::vector<House> list_of_house;
    std::string city_name;

public:
    City() {}
    City(std::vector<House> list_of_house, std::string city_name)
    {
        this->list_of_house = list_of_house;
        this->city_name = city_name;
    }
    void addHouse(House object)
    {
        list_of_house.push_back(object);
    }
    void countPetInSameStreet(std::string street_name)
    {
        std::cout << "Search in " << street_name << '\n';
        int number_of_pet_in_street = 0;
        for (int i = 0; i < list_of_house.size(); i++)
        {
            if (list_of_house[i].getStreetName() == street_name)
            {
                number_of_pet_in_street += list_of_house[i].countPet();
            }
        }
        std::cout << "Number of pets in street " << street_name << " is: " << number_of_pet_in_street << '\n';
    }
};
void problem_1()
{
    std::cout << '\n'
              << "Prolem 1: " << '\n';
    Address a1("Le Lai", 123, "Binh Duong");
    Address a2("Le Lai", 119, "Binh Duong");
    Address a3("Huynh Tan Phat", 458, "Ho Chi Minh");
    Address a4("Dien Bien Phu", 986, "Ho Chi Minh");
    Pet *d1 = new Dog("Max", 001);
    Pet *d2 = new Dog("Min", 010);
    Pet *d3 = new Dog("Mimi", 011);
    Pet *d4 = new Dog("Mana", 100);
    Pet *d5 = new Dog("Mumu", 101);
    Pet *d6 = new Dog("Meme", 110);
    Pet *c1 = new Cat("Nyan", 002);
    Pet *c2 = new Cat("Bongo", 020);
    d1->makeNoise();
    c1->makeNoise();
    std::vector<Pet *> h1_pets;
    std::vector<Pet *> h2_pets;
    std::vector<Pet *> h3_pets;
    std::vector<Pet *> h4_pets;
    House h1(a1, h1_pets);
    House h2(a2, h2_pets);
    House h3(a3, h3_pets);
    House h4(a4, h4_pets);
    h1.addPet(d1);
    h1.addPet(d2);
    h1.addPet(c1);
    h2.addPet(d3);
    h2.addPet(c2);
    h3.addPet(d4);
    h3.addPet(d5);
    h4.addPet(d6);
    h1.countPet();
    h2.countPet();
    h2.removePet(d3);
    h2.countPet();
    std::vector<House> HCM_house;
    std::vector<House> BD_house;
    City HoChiMinh(HCM_house, "Ho Chi Minh");
    City BinhDuong(BD_house, "Binh Duong");
    HoChiMinh.addHouse(h3);
    HoChiMinh.addHouse(h4);
    BinhDuong.addHouse(h1);
    BinhDuong.addHouse(h2);
    HoChiMinh.countPetInSameStreet("Huynh Tan Phat");
    BinhDuong.countPetInSameStreet("Le Lai");
}
// class Location
// {
// private:
//     double x;
//     double y;

// public:
//     Location() {}
//     Location(double x, double y)
//     {
//         this->x = x;
//         this->y = y;
//     }
//     double getX()
//     {
//         return x;
//     }
//     double getY()
//     {
//         return y;
//     }
//     double computeDistance(Location other)
//     {
//         return sqrt(pow((this->x - other.getX()), 2) + pow((this->y - other.getY()), 2));
//     }
// };
// class Building
// {
// protected:
//     std::string name;
//     std::string address;
//     Location location;
//     double phone_number;

// public:
//     Building() {}
//     Location getLocation()
//     {
//         return this->location;
//     }
//     virtual void computeDistance() = 0;
//     virtual ~Building();
// };
class Club
{
private:
    std::string club_name;
    std::string building_name;
    std::string phone_number;

public:
    Club() {}
    Club(std::string club_name, std::string building_name, std::string phone_number)
    {
        this->club_name = club_name;
        this->building_name = building_name;
        this->phone_number = phone_number;
    }
    std::string getNumber()
    {
        std::cout << phone_number << '\n';
        return phone_number;
    }
    std::string getBuildingName()
    {
        std::cout << building_name << '\n';
        return building_name;
    }
    std::string getClubName()
    {
        std::cout << club_name << '\n';
        return this->club_name;
    }
};
class Campus
{
private:
    std::string name;
    std::string address;
    double distance;
    Club club;

public:
    Campus(std::string name, std::string address, double distance, Club club)
    {
        this->name = name;
        this->address = address;
        this->distance = distance;
        this->club = club;
    }
    std::string getName()
    {
        return name;
    }
    double getDistance()
    {
        return this->distance;
    }
};

class Lecturer
{
private:
    int ID;
    std::string name;
    std::string title;
    std::string office_room;

public:
    Lecturer() {}
    Lecturer(int ID,
             std::string name,
             std::string title,
             std::string office_room)
    {
        this->ID = ID;
        this->name = name;
        this->title = title;
        this->office_room = office_room;
    }
    std::string getName()
    {
        return name;
    }
    std::string getTitle()
    {
        return title;
    }
    std::string getOfficeRoom()
    {
        return office_room;
    }
};
class University
{
private:
    std::vector<Campus> list_of_campus;
    std::vector<Lecturer> list_of_lecturer;

public:
    University() {}
    University(std::vector<Campus> list_of_campus, std::vector<Lecturer> list_of_lecturer)
    {
        this->list_of_campus = list_of_campus;
        this->list_of_lecturer = list_of_lecturer;
    }
    void getCampus()
    {
        for (int i = 0; i < list_of_campus.size(); i++)
        {
            std::cout << list_of_campus[i].getName() << '\n';
        }
    }
    void getLecturer()
    {
        for (int i = 0; i < this->list_of_lecturer.size(); i++)
        {
            std::cout << list_of_lecturer[i].getName() << '\n';
        }
    }
    void addCampus(Campus object)
    {
        list_of_campus.push_back(object);
    }
    void addLecturer(Lecturer object)
    {
        list_of_lecturer.push_back(object);
    }
};
void problem_2()
{
    std::cout << '\n'
              << "Problem 2: " << '\n';
    Lecturer l1(001, "Tom", "Math professor", "Lab");
    Lecturer l2(010, "Tam", "Physic professor", "CS office");
    std::cout << "Title of lecturer 1: " << l1.getTitle() << '\n';
    std::vector<Lecturer> lecturer_list;
    Club cl1("Basketball", "B1", "093338928");
    Club cl2("Baseball", "A1", "093338928");
    Club cl3("Football", "C1", "093338928");
    Campus c1("B1", "123 Le Loi", 5.4, cl1);
    Campus c2("A1", "124 Le Loi", 6.2, cl2);
    Campus c3("C1", "125 Le Loi", 7.3, cl3);
    std::vector<Campus> campus_list;
    University VGU(campus_list, lecturer_list);
    VGU.addCampus(c1);
    VGU.addCampus(c2);
    VGU.addCampus(c3);
    VGU.addLecturer(l1);
    VGU.addLecturer(l2);
    VGU.getCampus();
    VGU.getLecturer();
    std::cout << "campus 1 distance to center: " << c1.getDistance() << '\n';
}

class Member
{
protected:
    std::string name;
    std::string address;

public:
    Member() {}
    Member(std::string name, std::string address)
    {
        this->name = name;
        this->address = address;
    }
    std::string getName()
    {
        return this->name;
    }
    std::string getAdress()
    {
        return this->address;
    }
    virtual int getFee() = 0;
};
class SeniorMember : public Member
{
private:
    int fee;

public:
    SeniorMember() {}
    SeniorMember(std::string name, std::string address, int fee)
    {
        this->name = name;
        this->address = address;
        this->fee = fee;
    }
    int getFee()
    {
        return fee;
    }
};
class StandardMember : public Member
{
public:
    StandardMember() {}
    StandardMember(std::string name, std::string address)
    {
        this->name = name;
        this->address = address;
    }
    int getFee()
    {
        return 0;
    }
};
class ManagementCttee
{
private:
    std::vector<SeniorMember> senior_member_list;

public:
    void addCtteeMember(SeniorMember s)
    {
        senior_member_list.push_back(s);
    }
    void removeCtteeMember(std::string name)
    {
        for (int i = 0; i < this->senior_member_list.size(); i++)
        {
            if (senior_member_list[i].getName() == name)
            {
                std::cout << "Member " << senior_member_list[i].getName() << " is removed" << '\n';
                senior_member_list.erase(senior_member_list.begin() + i);
                i--;
            }
        }
    }
    int getFeeTotal()
    {
        int feeTotal = 0;
        for (int i = 0; i < this->senior_member_list.size(); i++)
        {
            feeTotal += senior_member_list[i].getFee();
        }
        std::cout << "Total fee cttee: " << feeTotal << '\n';
        return feeTotal;
    }
};
class Society
{
private:
    std::string name;
    std::vector<Member *> member_list;
    ManagementCttee management_cttee;

public:
    Society() {}
    Society(std::string name, std::vector<Member *> member_list, ManagementCttee management_cttee)
    {
        this->name = name;
        this->member_list = member_list;
        this->management_cttee = management_cttee;
    }
    void addMember(std::string name, std::string address)
    {
        Member *a = new StandardMember(name, address);
        member_list.push_back(a);
    }
    void addSeniorMember(std::string name, std::string address, int fee)
    {
        Member *s = new SeniorMember(name, address, fee);
        member_list.push_back(s);
    }
    void addCtteeMember(SeniorMember member)
    {
        this->management_cttee.addCtteeMember(member);
    }
    void showMember()
    {
        for (int i = 0; i < this->member_list.size(); i++)
        {
            std::cout << member_list[i]->getName() << '\n';
        }
    }
    int getFeeTotal()
    {
        int feeTotal = 0;
        for (int i = 0; i < this->member_list.size(); i++)
        {
            SeniorMember *s = dynamic_cast<SeniorMember *>(member_list[i]);
            if (s != nullptr)
            {
                feeTotal += s->getFee();
            }
        }
        feeTotal += management_cttee.getFeeTotal();
        std::cout << "Total fee society: " << feeTotal << '\n';
        return feeTotal;
    }
};
void problem_3()
{
    std::cout << '\n'
              << "Problem 3" << '\n';
    StandardMember sm1("Tom", "123 Hololive");
    StandardMember sm2("Tim", "456 Hologram");
    SeniorMember senior_member1("Max", "457 Street", 500);
    SeniorMember senior_member2("Min", "901 Street", 300);
    senior_member1.getFee();

    ManagementCttee M;
    Society Virtual_society;
    Virtual_society.addCtteeMember(senior_member1);
    Virtual_society.addCtteeMember(senior_member2);
    Virtual_society.addMember("Tam", "458 HTP");
    Virtual_society.addSeniorMember("Tama", "458 HTPT", 500);
    Virtual_society.getFeeTotal();
}
int main()
{
    problem_1();
    problem_2();
    problem_3();
}