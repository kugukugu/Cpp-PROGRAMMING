#include <iostream>

using namespace std;

//swap 함수 오버로딩으로 구현
void swap(char* a, char* b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;

}

void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void swap(double* p, double* q)
{
    double temp;
    temp = *p;
    *p = *q;
    *q = temp;

}

int main()
{
    int a = 10, b = 20;
    cout << "정수 교환 전: a = " << a << ", b = " << b << endl;
    swap(&a, &b);
    cout << "정수 교환 후: a = " << a << ", b = " << b << endl;

    char x = 'A', y = 'B';
    cout << "문자 교환 전: x = " << x << ", y = " << y << endl;
    swap(&x, &y);
    cout << "문자 교환 후: x = " << x << ", y = " << y << endl;

    double p = 3.14, q = 2.71;
    cout << "실수 교환 전: p = " << p << ", q = " << q << endl;
    swap(&p, &q);
    cout << "실수 교환 후: p = " << p << ", q = " << q << endl;

    return 0;
}
