#include <iostream>
#include <fstream>

using namespace std;

class Person {
public:
    char name[20];
    int age;

    void greet() const {
        cout << "Hi, I'm " << name << ", age " << age << endl;
    }
};

int main()
{
    Person p[3] = {{"Alice", 30}, {"Tom", 10}, {"Jack", 20}};
    ofstream out("person.bin", ios::binary);
    out.write(reinterpret_cast<char*>(p), sizeof(p));
    out.close();

    Person p2[3];
    ifstream in("person.bin", ios::binary);
    in.read(reinterpret_cast<char*>(p2), sizeof(p2));
    in.close();

    p2[0].greet();
    p2[1].greet();
    p2[2].greet();

    return 0;
}
