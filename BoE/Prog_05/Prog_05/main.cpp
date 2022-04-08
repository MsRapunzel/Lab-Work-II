#include <iostream>
#include <iomanip>

using namespace std;

class House {
    char adress[100];
    int floor;
    int flat;
public:
    void SetAdress(char adress[100])
    {
        int i = 0;
        for (; adress[i] != '\0'; )
        {
            this->adress[i] = adress[i];
            i++;
        }
        this->adress[i] = '\0';
    }
    void SetFloor(int floor) { this->floor = floor; }
    void SetFlat(int flat) { this->flat = flat; }
    char* GetAdress() { return adress; }
    int GetFloor() { return floor; }
    int GetFlat() { return flat; }
    void print();
};

void House :: print()
{
    cout << "Adress: ";
    for (int i = 0; this->adress[i] != '\0'; i++)
        cout << this->adress[i];
    cout << endl;
    cout << "Floor: " << this->floor << endl;
    cout << "Flat: " << this->flat << endl;
}

int count(House arr[3])
{
    int sum = 0;
    for (int i = 0; i < 3; i++) {

        sum += arr[i].GetFlat();
    }
    return sum;
}

void search(House arr[3])
{
    char str[80];
    char str2[80];
    cout << "Input adress: " << endl;
    cin.ignore(100, '\n');
    gets(str);
    
    for (int i = 0; i < 3; i++)
    {
        int j = 0;
        for (; *(arr[i].GetAdress() + j) != '\0'; j++)
        {
            str2[j] = *(arr[i].GetAdress() + j);
        }
        str2[j] = '\0';
        if (strcmp(str, str2) == 0)
        {
            arr[i].print();
            break;
        }
        if (i == 2) cout << "No match" << endl;
    }
}

int main()
{
    bool flag = true;
    House arr[3];
    House* ptr = &arr[0];
    for (int i = 0; i < 3; i++)
    {
        char adress[100];
        int floor;
        int flat;

        cin.ignore(100, '\n');
        cout << "``````````````````````" << endl;
        gets(adress);
        cin >> floor >> flat;

        arr[i].SetAdress(adress);
        arr[i].SetFloor(floor);
        arr[i].SetFlat(flat);
    }
    cout << "``````````````````````" << endl;
    cout << "Flat sum = " << count(arr) << endl;
    cout << "``````````````````````" << endl;
    cout << "Search:" << endl;
    while(flag)
    {
        char str[80];
        search(arr);
        cout << "Search again (0 - no, 1 - yes):? ";
        gets(str);
        if (strcmp(str, "1") == 0)
        {
            flag = 1;
        }
        else flag = 0;
    }
}
