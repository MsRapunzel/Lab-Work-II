//Складіть програму, яка повинна демонструвати:
//
//1.    Виділення пам‘яті в мові С++:
//
//1.1. Виділити пам‘ять під один об‘єкт.
//
//1.2. Вивести на друк значення, яке зберігається за вказаною у вказівнику адресою.
//
//1.3. Записати значення за вказаною у вказівнику адресою.
//
//1.4. Вивести на друк записане значення.
//
//1.5. Звільнити виділену пам‘ять.
//
//1.6. Виділити пам‘ять під групу об‘єктів.
//
//1.7. Вивести на друк значення, яке зберігається у другому елементі об‘єкту використовуючи квадратні дужки та вказівник.
//
//1.8.  Записати значення в кожний елемент об‘єкту.
//
//1.9. Вивести на друк всі значення.
//
//1.10.              Звільнити виділену пам‘ять.
//
//2.    Наведіть приклади коду, який призводить до витоку пам‘яті.
//
//3.    Наведіть приклади коду, який призводить до “краху” програми.
#include <iostream>

using namespace std;

int main()
{
    cout << "Task 1" << endl;
    //1.1 Виділити пам‘ять під один об‘єкт
    int *ptr = new int;
    //1.2 Вивести на друк значення, яке зберігається за вказаною у вказівнику адресою
    cout << "Value *ptr = " << *ptr << endl;
    //1.3 Записати значення за вказаною у вказівнику адресою
    *ptr = 21;
    //1.4 Вивести на друк записане значення.
    cout << "Value ptr = " << *ptr << endl;
    //1.5. звільнення пам'яті
    delete ptr;
    //1.6. Виділити пам‘ять під групу об‘єктів.
    int* parr = new int[2];
    //1.7 Вивести на друк значення, яке зберігається у другому елементі об‘єкту використовуючи квадратні дужки та вказівник.
    cout << "Value *(parr + 1) = " << *(parr + 1) << endl;
    cout << "Value parr[1] = " << parr[1] << endl;
    //1.8.  Записати значення в кожний елемент об‘єкту.
    *parr = 21;
    parr[1] = 87;
    //1.9. Вивести на друк всі значення.
    cout << "Value *parr = " << parr[0] << '\n';
    cout << "Value *(parr + 1) = " << *(parr + 1) << '\n';
    //1.10. Звільнити виділену пам‘ять.
    delete []parr;
    //2. Наведіть приклади коду, який призводить до витоку пам‘яті.
    cout << "Task 2" << endl;
    //Приклад 1
    cout << "1" << endl;
    int *first = new int;
    *first = 21;
    int i = 87;
    first = &i;
    //Приклад 2
    cout << "2" << endl;
    int *second = new int[10];
    second[0] = 78;
    int j = 12;
    second = &j;
    //3. Наведіть приклади коду, який призводить до “краху” програми.
    cout << "Task 3" << endl;
    //Приклад 1
    int * crash = new int[10];
    crash[0] = 77;
    delete crash;
    int k = 19;
    crash = &k;
    cout << "1" << endl;
    //Приклад 2
    int *collapse = new int;
    *collapse = 77;
    delete collapse;
    delete collapse;
    cout << "2" << endl;
    return 0;
}