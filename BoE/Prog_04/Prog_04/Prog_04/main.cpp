#include <iostream>

using namespace std;

void printarr(int arr[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}

void fillarray(int arr[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            arr[i][j] = 0;
        }
    }
}

int main()
{
    int arr[8][8];

    //Вариант 1
    cout << "var 1" << endl;
    fillarray(arr);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8 - i; j++)
        {
            arr[i][j] = 1;
        }
    }
    printarr(arr);
    cout << "********************************" << endl;

    //Вариант 2
    cout << "var 2" << endl;
    fillarray(arr);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 7 - i; j < 8; j++)
        {
            arr[i][j] = 1;
        }
    }
    printarr(arr);
    cout << "********************************" << endl;

    //Вариант 3
    cout << "var 3" << endl;
    fillarray(arr);
    for (int i = 0; i < 8; i++)
    {
        for (int j = i; j < 8; j++)
        {
            arr[i][j] = 1;
        }
    }
    printarr(arr);
    cout << "********************************" << endl;

    //Вариант 4
    cout << "var 4" << endl;
    fillarray(arr);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            arr[i][j] = 1;
        }
    }
    printarr(arr);
    cout << "********************************" << endl;

    //Вариант 5
    cout << "var 5" << endl;
    fillarray(arr);
    for (int i = 0; i < 4; i++)
    {
        for (int j = i; j < 8 - i; j++)
        {
            arr[i][j] = 1;
        }
    }
    printarr(arr);
    cout << "********************************" << endl;

    //Вариант 6
    cout << "var 6" << endl;
    fillarray(arr);
    for (int i = 4; i < 8; i++)
    {
        for (int j = 7 - i; j <= i; j++)
        {
            arr[i][j] = 1;
        }
    }
    printarr(arr);
    cout << "********************************" << endl;

    //Вариант 7
    cout << "var 7" << endl;
    fillarray(arr);
    for (int i = 0; i < 4; i++)
    {
        for (int j = i; j < 8 - i; j++)
        {
            arr[j][i] = 1;
        }
    }
    printarr(arr);
    cout << "********************************" << endl;

    //Вариант 8
    cout << "var 8" << endl;
    fillarray(arr);
    for (int i = 4; i < 8; i++)
    {
        for (int j = 7 - i; j <= i; j++)
        {
            arr[j][i] = 1;
        }
    }
    printarr(arr);
    cout << "********************************" << endl;
}
