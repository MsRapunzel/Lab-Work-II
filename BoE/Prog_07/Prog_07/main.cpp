#include <iostream>

using namespace std;

class House {
    char adress[100];
    int floor;
    int flat;
    double price;
public:

    void SetPrice(int price) { this->price = price; }

    int GetPrice() { return price; }


    House() :floor(0), flat(0), adress("empty"){}
    
    House(char* adress) :House() { strcpy(this->adress, adress); }
    
    House(char* adress, int floor) :House(adress) { this->floor = floor; }
    
    House(char* adress, int floor, int flat) :House(adress, floor) { this->flat = flat; }
    
    House(char* adress, int floor, int flat, int price) :House(adress, floor, flat) { this->price = price; }
    
    // lr 7 starts here

    House(const House& other) = default;

    House(House&& house) = delete;

    House(int floor) : House() { this->floor = floor; } //допустиме неявне перетворення типу

    explicit House(double price) : House() { this->price = price; } //заборона неявного перетворення типу (explicit)
    
    ~House() {
        cout << "Destructor " << this << " was called" << endl;
    }

    // lr 7 ends here
};

void discount(House house, int discount){ house.SetPrice(house.GetPrice() - discount); } // об'єкт класу в якості параметру за значенням

void discountptr(House &house, int discount) { house.SetPrice(house.GetPrice() - discount); } // об'єкт класу в якості параметру за посиланням


int main()
{
    House house(90.40);

    House house2 = house;

    House house3(house);

    House arrHouse[5] = { {}, {"40a"}, {"10", 1}, {"71b", 4, 3}, {"68", 4, 1, 300} };
    
    discount(house, 9);
    cout << "Param by value: " << house.GetPrice() << endl;

    discountptr(house, 9);
    cout << "Param by reference: " << house.GetPrice() << endl;

    return 0;
}
