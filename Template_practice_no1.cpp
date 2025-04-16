#include <iostream>
#include <cstdio>

using namespace std;

template <typename T>
void swap_func(T& data, T& data1) {
    T temp = data;
    data = data1;
    data1 = temp;

}

int main() {

    int a=6;
    int b=3;

    swap_func<int>(a,b);

    cout<< a << b<< endl;

    char *c = "hello";
    char *d = "world";

    swap_func<char *>(c,d);

    cout<< c << d << endl;

    return 0;
}
