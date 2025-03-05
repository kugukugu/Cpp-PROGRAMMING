
#include <iostream>
#include <cstring>

using namespace std;

class Person {
public:
    char* name;
    int age;

    Person(char* name, int age) {
        cout << "constructor :" << name << endl;
        this->age = age;
        this->name = new char[100];
        strcpy(this->name, name);
    };

    Person(const Person& other) {
        cout << "copy constructor" << endl;
        this->age = other.age;
        this->name = new char[100];
        strcpy(this->name, other.name);
    };

    ~Person() {
        cout << "destructor :" << this->name << endl;
        delete[] this->name;
    };

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    void display() const {
        cout << "const Name: " << name << ", Age: " << age << endl;
    }
};

void testFunc(const Person p) { //여기가 이전 코드와 다름. 무슨 에러가 날까?
		p.display();
}

int main() {
    const Person p1("hong", 20);
    Person p2("kim", 22);

    p1.display();
    p2.display();

    testFunc(p2);

    return 0;
}
