#include <iostream>
#include <iomanip>

using namespace std;

class House {
    char adress[100];
    int floor;
    int flat;
public:

    House() :floor(0), flat(0), adress("empty"){}

    House(char adress[100]) :House()
    {
        strcpy(this->adress, adress);
    }

    House(char adress[100], int floor) :House(adress)
    {
        this->floor = floor;
    }

    House(char adress[100], int floor, int flat) :House(adress, floor)
    {
        this->flat = flat;
    }

    ~House() { cout << "Destructor was called" << endl; }

    void print();
};

void House::print()
{
    cout << "Adress: "<< this->adress << endl;
    cout << "Floor: " << this->floor << endl;
    cout << "Flat: " << this->flat << endl;
} 


int main()
{
    char arr[] = "22b";
    char arr1[] = "40a";
    char arr2[] = "22b";

    House einz;
    House zwei(arr);
    House drei(arr1, 3);
    House fier(arr2, 1, 2);

    House* ptr = new House(arr,2,4);
    ptr->print();
    delete ptr;
    return 0;
}

//#include <iostream>
//
//using namespace std;
//
//class Cow
//{
//    string name;
//    int age;
//public:
//    //void SetName(string name) { this->name = name; }
//
//    void Print()
//    {
//        cout << name << endl << age << endl;
//    }
//
//    Cow(string name, int age)
//    {
//        this->name = name;
//        this->age = age;
//    }
//    Cow()
//    {
//        name = "empty";
//        age = 0;
//    }
//
//};
//
//
//int main()
//{
//    Cow cow("Moo", 25);
//    cow.Print();
//    //cow.SetName("Kamado Moodjiro");
//}
