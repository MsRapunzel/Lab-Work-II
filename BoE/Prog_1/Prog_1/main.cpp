#include <iostream>

void times(int *count)
{
    (*count)++;
}

using namespace std;

int main()
{
    //Пункт 1
    int firstVariable = 45;
    int secondVariable = 2187;
    float thirdVariable = 99.0f;
    cout << "Пункт 1" << endl;
    cout << "Перша змінна: " << firstVariable << endl;
    cout << "Друга змінна: " << secondVariable << endl;
    //Пункт 2
    int* ptr1 = &firstVariable;
    int* ptr2 = nullptr;
    ptr2 = &secondVariable;
    cout << "Пункт 2" << endl;
    cout << "Якщо на поточний момент адреса невідома, краще проініціалізувати нульовий вказівник \n,для того, щоб показати, що дана зміна-вказівник ні на що не посилається." << endl;
    //Пункт 3
    cout << "Пункт 3" << endl;
    cout << "Початкове значення ptr1: " << firstVariable << endl;
    *ptr1 = 300;
    cout << "Значення ptr1 після зміни значення за допомогою вказівника: " << firstVariable << endl;
    //Пункт 4
    cout << "Пункт 4" << endl;
    ptr1 = (int*)100;
    ptr2 = (int*)108;
    cout << "ptr1: " << ptr1 << endl;
    cout << "ptr2: " << ptr2 << endl;
    cout << "ptr2 - ptr1 = " << ptr2 - ptr1 << endl;
    //108-100 = 8 байт;
    //8 байт / sizeof(int) = 8 / 4 = 2 комірки пам'яті
    //Пункт 5
    cout << "Пункт 5" << endl;
    ptr1 += 3;
    cout << "ptr1: " << ptr1 << endl;
    //sizeof(int) = 4 байта
    //0х64 + 1 = 0х68
    //0х64 + 2 = 0х6с
    //0х64 + 3 = 0х70
    //адреса + n = адреса + n*sizeof(змінна)
    //Пункт 6
    cout << "Пункт 6" << endl;
    ptr1++;
    cout << "ptr1: " << ptr1 << endl;
    //0х70 + 1 = 0х74
    //Пункт 7
    cout << "Пункт 7" << endl;
    cout << "ptr1 > ptr2? " << (ptr1 > ptr2 ? "так" : "ні") << endl;
    cout << "ptr1 < ptr2? " << (ptr1 < ptr2 ? "так" : "ні") << endl;
    cout << "ptr1 == ptr2? " << (ptr1 == ptr2 ? "так" : "ні") << endl;
    //Пункт 8
    cout << "Пункт 8" << endl;
    cout << "ptr1 * ptr2 призведе до помилки, оскільки множення та ділення є \nнедійсними операндами для вказівників" << endl;
    //Пункт 9
    cout << "Пункт 9" << endl;
    void *ptrthird = nullptr;
    ptrthird = &firstVariable;
    cout << "ptrthird:\t" << *((int*)ptrthird) << '\t' << ptrthird << endl;
    ptrthird = &thirdVariable;
    cout << "ptrthird:\t" << *((float*)ptrthird) << '\t' << ptrthird << endl;
    //Пункт 10
    cout << "Пункт 10" << endl;
    int count = 0;
    int* pcount = &count;
    times(pcount);
    cout << "Кількість разів, коли функція times була викликана: "<< count << endl;
    //Пункт 11
    cout << "Пункт 11" << endl;
    cout << "Треба змінити NULL на nullptr" << endl;
    return 0;
}
