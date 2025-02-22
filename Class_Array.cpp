#include <iostream>
#include <cstring>
#include <cctype>

#define NAME_LENGTH 10

using namespace std;

class Student {
private:
  char name[10];
  int number;
  double score;

public:

    Student ( char *n, int nu, double s) {
        strcpy(name, n);
        number = nu;
        score=s;

    }

   void print_Student_information(int i) {
           cout<< i+1 << '.' << "name: " << name <<endl;
           cout<< i+1 << '.' << "number: " << number <<endl;
           cout<< i+1 << '.' << "score: "<< score << '\n' << endl;
   }

};

int main() {

    Student* student[3];

    student[0] = new Student("jack", 20242000, 80);
    student[1] = new Student("ham", 20242001, 20);
    student[2] = new Student("kimbab", 20242221, 90);

    for(int i=0; i<3; i++) {
        student[i]->print_Student_information(i);
        delete student[i];
    }

    return 0;
}
