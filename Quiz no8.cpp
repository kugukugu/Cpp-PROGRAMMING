#include <iostream>
#include <cstring>

using namespace std;

class Student {
private:
    int score;
    char *name;
public:

    Student () {

    }

    Student (int score, char *name) {
        this->score = score;
        this->name = new char[10];
        strncpy(this->name,name,9);
        this->name[9] = '\0';
        cout << "생성자" << endl;
    }

     Student (const Student& a) {
        this->score = a.score;
        this->name = new char[10];
        strncpy(this->name, a.name, 9);
        this->name[9] = '\0';
        cout << "복사 생성자" << endl;
    }

    ~Student () {
        delete[] this->name;
        cout << "소멸자" << endl;
    }

} ;

int main() {

    Student s1(30, "hello");
    Student s2= s1;

    return 0;
}
