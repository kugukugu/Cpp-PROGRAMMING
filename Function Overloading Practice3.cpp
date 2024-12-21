#include <iostream>
#include <random>
#include <ctime>

using namespace std;

struct Student
{
    char name[50];
    int age;
};

// 함수 오버로딩을 활용한 랜덤 데이터 생성
void rdm(char *name, int random )
{
    int i;
    random_device rd;
    mt19937 gen(rd());

    for(i=0; i<random; i++)
    {
        uniform_int_distribution<>dis(0,25);
        name[i]= 'a'+ dis(gen);
    }

}

void rdm(int *age, int random)
{
    *age = random;
}

int main()
{
    int i;

    // 학생 데이터 100개를 랜덤 생성
    Student student[100];

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<>dis(1,100);

    int random_number = dis(gen);

    // 이름도 랜덤 생성, 나이도 랜덤 생성, 함수 오버로딩을 활용해 구현
    for(i=0; i<100; i++)
    {
        rdm(student[i].name, random_number);
        rdm(&student[i].age, random_number);
    }

    // 출력하기

     for(i=0; i<100; i++)
    {
        cout<<student[i].name<<endl;
        cout<<student[i].age<<endl;
        cout<<endl;
    }

    return 0;
}
