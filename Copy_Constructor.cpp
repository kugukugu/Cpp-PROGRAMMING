#include <iostream>
#include <cstring>
#include <cctype>

#define NAME_LENGTH 10

using namespace std;

class Person {  ;
public:
    char *name;
    int age;

    Person (char* name, int age) {
        cout<<"constructor "<<endl;
        this->age =  age;
        this->name =  new char[100];
        strcpy(this->name, name);
    }

     Person (const Person& other) {
        cout<<"copy constructor "<<endl;
        this->age =  other.age;
        this->name =  new char[100];
        strcpy(this->name, other.name);
    }

     ~Person () {
        cout << "destructor" << endl;
        delete[] this -> name;

    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

};

void func (Person p) {
    p.display();
}

Person func2 () {
    Person p("kim", 22);
    return p;

}

int main() {

    Person p = Person("hong", 20);
    Person p1 = Person(p); //복사 생성자 호출 케이스 1

    p1.display();

    // 케이스 2
    func (p);

    // 케이스 3
    func2();

    return 0;
}
