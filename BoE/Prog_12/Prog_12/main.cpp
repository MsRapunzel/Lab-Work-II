#include <iostream>

using namespace std;

class RestPlace{
protected:
    double square;
public:
    virtual void Print() = 0;
    RestPlace(double square) : square(square) {};
    virtual ~RestPlace() {
        cout << "Destructor RestPlace" << endl;
    }
};

class Park final : public RestPlace{
protected:
    char name[100];
public:
    Park (double square, char* name): RestPlace(square){
        strcpy(this->name, name);
    }
    void Print() override{
        cout << "Park: \t" << name << endl;
        cout << "Square: \t" << square << endl;
    }
    ~Park() {
        cout << "Destructor Park" << endl;
    }
};

class Attraction : public RestPlace{
protected:
    char name[100];
public:
    Attraction (double square, char* name): RestPlace(square){
        strcpy(this->name, name);
    }
    void Print() override{
        cout << "Attraction: \t" << name << endl;
        cout << "Square: \t" << square << endl;
    }
    ~Attraction() {
        cout << "Destructor Attraction" << endl;
    }
};

class WaterAttraction final : public Attraction{
public:
    WaterAttraction(double square, char* name) : Attraction(square, name) {};
    
    void Print() override{
        cout << "Water Attraction: \t" << name << endl;
        cout << "Square: \t" << square << endl;
    }
    ~WaterAttraction() {
        cout << "Destructor Water Attraction" << endl;
    }
};

void ShowInfo(RestPlace &place){
    place.Print();
}

void ShowInfo(RestPlace *place){
    place->Print();
}

int main()
{
    RestPlace** placearr = new RestPlace*[3];
    placearr[0] = new Park(50, "Mondstadt");
    placearr[1] = new Attraction(200.1, "Mykolaiv");
    placearr[2] = new WaterAttraction(218.7, "Inadzuma");
    
    for(int i = 0; i < 3; i++){
        ShowInfo(*placearr[i]);
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }
    
    for(int i = 0; i < 3; i++){
        delete placearr[i];
    }
    
    delete[] placearr;
    
    return 0;
}
