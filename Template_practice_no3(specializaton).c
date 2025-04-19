#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

template <typename T>
void sort_arr(T arr[], int size1) {

    T temp;
    int min_idx = 0;

    for(int i=0; i<size1; i++) {
        min_idx=i;
        for(int j=i+1; j<size1; j++) {
            if(arr[min_idx] > arr[j]) {
                min_idx=j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx]=arr[i];
        arr[i]=temp;
    }

}

template <>
void sort_arr(string arr[], int size1) {

    int min_idx = 0;
    string temp;

    for(int i=0; i<size1; i++) {
        min_idx = i;
        for(int j=i+1; j<size1; j++) {
            if(arr[min_idx]>arr[j]) {
                min_idx=j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {

    int a[5] = {3, 1, 5, 2, 4};

    sort_arr(a, 5);

    for(int i=0; i<5; i++) {

        cout << a[i] << ' ';
    }
    cout << endl;

    string b[5] = {"hello", "abcd", "what", "metamorphosis", "switch"};

    sort_arr(b, 5);

    for(int i=0; i<5; i++) {

        cout << b[i] << ' ';
    }
    cout << endl;

    return 0;
}
