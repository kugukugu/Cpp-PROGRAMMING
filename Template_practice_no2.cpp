#include <iostream>
#include <cstdio>

using namespace std;

template <typename T>
T sumArr(T data[], int data1) {
    T sum = T();
    for(int i=0; i<data1; i++)
    {
        sum += data[i];
    }

    return sum;
}

int main() {

    int a[5] = {1, 2, 3, 4, 5};

    int sum = sumArr(a,5);

    cout << sum << endl;

    string b[5] = {"1", "2", "3", "4", "5"};

    string sum1 = sumArr(b,5);

    cout << sum1 << endl;

    return 0;
}
