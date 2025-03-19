#include <iostream>
#include <cstring>

using namespace std;

void swap (int *a, int*b) {

    int temp;
    temp = *a;
    *a= *b;
    *b= temp;

}

void swap (char **a, char **b) {

    char* temp;
    temp = *a;
    *a = *b;
    *b= temp;

}

int main() {
    int a=20;
    int b=30;

    char *c = "abcd";
    char *d = "efgh";

    swap(&a, &b);
    swap(&c, &d);

    cout << a <<' '<< b << endl;
    cout << c <<' '<< d << endl;
}
