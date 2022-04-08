#include <iostream>

using namespace std;

class Point{
    
private:
    int x;
    int y;
    
public:
    Point(): x(0), y(0) {}
    Point(int x, int y): x(x), y(y) {}
    ~Point() { cout << "Destructor " << this << " was called" << endl; }
    
    friend Point operator+(int i, const Point &other);
    friend void Search(int find, Point arr[], int size);
    void Print();
    
    Point& operator = (const Point &other) { // об'єкт = об'єкт
        if (this == &other) return *this;
        x = other.x; y = other.y;
        return *this;
    }
    
    Point operator+(const int i)const{ // об'єкт + змінна
        return Point(this->x + i, this->y + i);
    }

    Point operator+(const Point &other)const{ // об'єкт + об'єкт
        return Point(x + other.x, y + other.y);
        }
    
    Point operator*(const Point &other)const { // об'єкт * об'єкт
        return Point(x * other.x, y * other.y);
        }
    
    Point operator*(const int i)const { // об'єкт * об'єкт
        return Point(this->x * i, this->y * i);
    }
    
    Point& operator++(){ // префіксний інкремент
        ++x;
        ++y;
        return *this;
    }
    
    Point operator++(int i){ // постфіксний інкремент
        return Point(x++, y++);
    }

};

Point operator+(int i, const Point &other){ // змінна + об'єкт
    return Point(i + other.x, other.y + i);
}

void Point::Print() {
    cout << "X = " << x << "\tY = " << y <<'\n';
}

void Search(int find, Point arr[], int size){
    for (int i = 0; i < size; i++)
        if (arr[i].x == find) arr[i].Print();
}

int main() {
    Point point1(14, 3);
    Point point2(0, 2);
    
    cout << "Point 1: " << '\t';
    point1.Print();
    cout << "Point 2: " << '\t';
    point2.Print();
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    
    cout << "object + object" << endl;
    point1 = point2 + point1;
    cout << "Point 1: " << '\t';
    point1.Print();
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "object * object" << endl;
    point1 = point2 * point1;
    cout << "Point 1: " << '\t';
    point1.Print();
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    
    cout << "int + object" << endl;
    point1 = 2 + point2;
    cout << "Point 1: " << '\t';
    point1.Print();
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "object + int" << endl;
    point1 = point2 + 2;
    cout << "Point 1: " << '\t';
    point1.Print();
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "object * int" << endl;
    point1 = point2 * 2;
    cout << "Point 1: " << '\t';
    point1.Print();
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "object = object" << endl;
    point1 = point2;
    cout << "Point 1: " << '\t';
    point1.Print();
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "object++" << endl;
    point1++;
    cout << "Point 1: " << '\t';
    point1.Print();
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "++object" << endl;
    ++point1;
    cout << "Point 1: " << '\t';
    point1.Print();
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    return 0;
}
