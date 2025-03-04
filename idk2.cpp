#include <iostream>
#include <string.h>

using namespace std;

class Student {
    enum { NAME_LENGTH = 10 };

public:
   const char *name;
   //char *name
   // name[NAME_LENGTH]
    int number;

    void printStudent();
};


int main() {
    Student s1;
    Student s2;

   // strcpy(s1.name, "hong");
    s1.name = "hong";
    s1.number = 20240202;

//    strcpy(s2.name, "kugu");
    s2.number = 20250202;

    s1.printStudent();
    s2.printStudent();

    return 0;
}

void Student::printStudent() {
    cout << "학생 정보를 출력합니다.." << endl;
    cout << "이름 : " << name << endl;
    cout << "학번 : " << number << endl;
}
