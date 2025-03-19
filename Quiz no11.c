#include <iostream>
#include <cstring>

using namespace std;

class Animal {
public:

   virtual void speak_animal() {

    }

};

class Dog : public Animal {

    void speak_animal() {
        cout << "멍멍" << endl;
    }

};

class Cat : public Animal {

    void speak_animal() {
        cout << "야옹" << endl;
    }

};

int main() {

    Animal *animal1 = new Dog;
    Animal *animal2 = new Cat;

    animal1->speak_animal();
    animal2->speak_animal();

    delete animal1;
    delete animal2;

    return 0;
}
