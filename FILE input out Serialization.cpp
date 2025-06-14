#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Person {
public:
    char *name;
    int age;

    void greet() const {
        cout << "Hi, I'm " << name << ", age " << age << endl;
    }

    ~Person() { delete[] name; }
};

int main()
{
    Person p1;

    p1.age = 30;
    p1.name = new char[20];
    strcpy(p1.name, "KimBab");

    ofstream file("output.bin", ios::binary);

    file.write(reinterpret_cast<char*>(&p1.age), sizeof(int));

    int len = strlen(p1.name);

    file.write(reinterpret_cast<char*>(&len), sizeof(int));

    file.write(p1.name, len);

    file.close();

    Person p2;

    ifstream file1("output.bin", ios::binary);

    int len2;

    file1.read(reinterpret_cast<char*>(&p2.age), sizeof(int));
    file1.read(reinterpret_cast<char*>(&len2), sizeof(int));
    p2.name = new char[len2+1];
    file1.read(p2.name, len2);
    p2.name[len2] = '\0';

    p2.greet();

    file1.close();


    return 0;
}
