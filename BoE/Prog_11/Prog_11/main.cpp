#include <iostream>

using namespace std;

class Place{
private:
    char name[100];
    
protected:
    char location[100];
    // рядом сидит мама и наверное будет странно если я буду говорить об этом)0)
public:
    
    char* GetName() {
        return name;
    }
    
    Place(): name("empty"), location("none") {}
    
    Place(const char* name) :Place(){
        strcpy(this->name, name);
    }
    
    Place(const char* name, const char* location) :Place(name){
        strcpy(this->location, location);
    }
    
    Place(const Place& other) = default;
    
    ~Place(){
        cout << "Destructor " << this << " was called" << endl;
    }
    
    void Print(){
        cout << "Name: \t" << this->name << endl;
        cout << "Location: \t" << this->location << endl;
    }
};

class Park : public Place{
private:
    double distance;
    double area;
    int visitors;
    
public:
    
    using Place::Place;
    
    Park(const char* name, const char* location): Place(name, location){
        distance = 0.0;
        area = 0;
        visitors = 0;
    }

    Park(const char* name, const char* location, double distance) :Park(name, location){
        this->distance = distance;
    }
    
    Park(const char* name, const char* location, double distance, double area) :Park(name, location, distance){
        this->area = area;
    }

    Park(const char* name, const char* location, double distance, double area, int visitors) :Park(name, location, distance, area){
        this->visitors = visitors;
    }
    
    Park(const Park& other) = default;

    ~Park(){
        cout << "Destructor " << this << " was called" << endl;
    }
    
    void Print(){
        Place::Print();
        cout << "Distance: \t" << this->distance << " km" << endl;
        cout << "Area: \t" << this->area << " sq km" << endl;
        cout << "Visitors: \t" << this->visitors << endl;
    }
    
    void PrintName(){
      //cout << "Private Name" << name << endl; //error
        cout << "Private Name: \t" << GetName() << endl;
    }
};

int main() {
    char name1[] = "Dune Sea";
    char name2[] = "Carpathian";
    char name3[] = "Redwood";
    char name4[] = "Knowhere";
    
    char loc1[] = "Tatooine";
    char loc2[] = "Ukraine";
    char loc3[] = "USA";
    
    
    cout << "Place: " << endl;
    Place place1(name1, loc1);
    place1.Print();
    cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Park 1: " << endl;
    Park park1(name2, loc2, 450.3, 80, 500000);
    park1.Print();
    cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Park 2: " << endl;
    Park park2(name3, loc3, 9367.12, 120.8, 1000000);
    park2.Print();
    cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Park 3: " << endl;
    Park park3(name4);
    park3.PrintName();
    
    return 0;
}
