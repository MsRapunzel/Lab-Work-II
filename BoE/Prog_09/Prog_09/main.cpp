#include <iostream>

using namespace std;

class Apple{
    
private:
    char color[21];
    int weight;
    
public:
    Apple(char color[21], int weight){
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        strcpy(this->color, color);
        this->weight = weight;
    }
    
    ~Apple(){
        cout << "Destructor " << this << " was called" << endl;
    }
    void Print(){
        cout << "Color: "<< this->color << '\t';
        cout << "Weight: " << this->weight << endl;
    }
    friend void ChangeWeight(Apple &value);
    friend int SomeFunc(Apple &value);
};

void ChangeWeight(Apple &value){
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Change weight of " << value.color << " apple:" << endl;
    value.weight = 112;
}

inline int SomeFunc(Apple &value){
    int weight = 150;
    if (value.weight < weight) return 0;
    else return value.weight;
}

int main() {
    Apple apple("Red", 200);
    apple.Print();
    Apple apple2("Yellow", 140);
    apple2.Print();
    cout << "Inline function: " << SomeFunc(apple) << endl;
    ChangeWeight(apple);
    apple.Print();
    return 0;
}
