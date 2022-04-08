#include <iostream>

using namespace std;

constexpr double rarity = 0.006;

class Character{
    
    char name[100];
    int lvl;
    static int count;
    const int UID;
    
public:
    
    int Getlvl() const{ return lvl; }
    
    Character() :name("Empty"), lvl(0), UID(count) { count++; }

    Character(char name [100]) :Character() { strcpy(this->name, name); }

    Character(char name [100], int lvl) :Character(name) { this->lvl = lvl; }

    ~Character() {
        cout << "Destructor " << this << " was called" << endl;
        count --;
    }
    void Print_Character() {
        cout << "Name: " << this->name << endl;
        cout << "Level: " << this->lvl << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }
    static void Print_count(){
        cout << "Amount of characters: " << count << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    }

};

int Character:: count = 0; // int Character:: count;

int main() {
    cout << "Five-star Characters: \n" << endl;
    Character first_character("Arataki Itto", 40);
    first_character.Print_Character();
    Character second_character("Xiao", 80);
    second_character.Print_Character();
    Character third_character("Keqing", 20);
    third_character.Print_Character();
    Character::Print_count();
    return 0;
}
