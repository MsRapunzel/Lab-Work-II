#include <iostream>

using namespace std;

int multiply (int a, int b, int c) { return a*b*c; }

float multiply (float a, float b, float c) { return a*b*c; }

int main()
{
    cout << "int multiply: " << multiply(5, 8, 4) << endl;
    cout << "float multiply: " << multiply(5.0f, 4.0f, 2.0f) << endl;
    return 0;
}

/*
int sum(int a, int b, int c) { return a + b + c; }

double subtraction(double a, double b, double c) { return a - b - c; }

float multiply(float a, float b, float c) { return a * b * c; }
*/
