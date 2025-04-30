#include <iostream>

using namespace std;

template <typename T>
class MyBox {
private:
    T value;
public:
		MyBox() {
	    value = T();
    }

    MyBox(T val) {
	    value = val;
    }

    void print() const {
        cout << "Value: " << value << endl;
    }
};

template <typename T>
class SmartArray {
private:
    T *arr;
    int arrSize;

    SmartArray(const SmartArray& ) {}
    void operator=(const SmartArray& ) {}

public:
    SmartArray(int arrSize) {
        this->arrSize = arrSize;
        arr = new T[arrSize];
    }

    ~SmartArray() {
        delete[] arr;
    }


    T& operator[] (int index) {
        if (index < 0 || index >= arrSize) {
            cout << "Array index out of bound" << endl;
            exit(1);
        }

        return arr[index];
    }

};

int main() {

    SmartArray<MyBox<int>> array1(3);
    array1[0]=MyBox<int>(2);
    array1[1]=MyBox<int>(3);
    array1[2]=MyBox<int>(6);

    array1[0].print();
    array1[1].print();
    array1[2].print();
}
