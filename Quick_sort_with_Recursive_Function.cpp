#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;



int* quick_sort(int a[], int len) {

    if(len<=1) {
        return a;
    }

    int pivot = a[len/2];

    int *arr_left = new int[len];
    int *arr_right= new int[len];

    int left_index=0;
    int right_index=0;

    for(int i=0; i<len; i++) {
        if(pivot > a[i]) {
            arr_left[left_index]=a[i];
            left_index++;
        }
        else {
            arr_right[right_index]=a[i];
            right_index;
        }
    }

    int* receive_arr = quick_sort(arr_left, left_index);
    int* receive_arr1 = quick_sort(arr_right, right_index);

    int return_index=0;

    for (int i=0; i < left_index; i++) {
        a[i]=receive_arr[i];
    }
    for (int i=left_index; i < right_index; i++) {
        a[i]=receive_arr1[return_index++];
    }

    delete []arr_left;
    delete []arr_right;

    return a;
}

int main() {

    int arr[7] = {3,2,6,7,1,4,5};

    quick_sort(arr, 7);

    for(int i=0; i<7; i++) {
        cout << arr[i] << ' ';
    }

    cout << endl;

    return 0;
}
