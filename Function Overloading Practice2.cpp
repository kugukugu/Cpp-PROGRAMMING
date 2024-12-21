#include <iostream>

using namespace std;

struct Student
{
    char name[50];
    int age;
};

struct Professor 
{
    char name[50];
    int age;
    char subject[50];
};

// 출력 함수를 함수 오버로딩으로 구현
void print(Student student)
{
    cout<<student.name<<endl;
    cout<<student.age<<endl;
}

void print(Professor professor)
{
    cout<<professor.name<<endl;
    cout<<professor.age<<endl;
    cout<<professor.subject<<endl;
}

int main() {
    Student student = {"홍길동", 20};
    Professor professor = {"이순신", 45, "역사"};

    // 함수 오버로딩을 이용한 출력
    print(student);
    cout<<endl;
    print(professor);

    return 0;
}
