#include <iostream>
#include <cstdio>

using namespace std;

class Vector {
private:
    int x;
    int y;
public:
    Vector() {
    }

    Vector(int x, int y) {
        this->x = x;
        this->y = y;
    }

    ~Vector() {}

    Vector& operator=(int x) {
        this->x=x;
        this->y=x;

        return *this;
    }

    showVector() {
        cout<< this->x << ", " << this->y << endl;
    }

    friend ostream& operator << (ostream& os, Vector& v1);

};

class SmartArray {
private:
    Vector **arr;
    int arrSize;

    SmartArray(const SmartArray& ) {}
    void operator=(const SmartArray& ) {}

public:
    SmartArray(int arrSize) {
        this->arrSize = arrSize;
        //arr = (Vector**)malloc(sizeof(Vector*)*arrSize);
        arr = new Vector*[arrSize];
        for(int i=0; i<arrSize; i++) {
            arr[i]=nullptr;
        }
    }

    ~SmartArray() {
        delete[] arr;
    }

    Vector* operator[] (int index) {
        if (index < 0 || index >= arrSize) {
            cout << "Array index out of bound" << endl;
            exit(1);
        }

        return arr[index];
    }

     void setVector(int index) {
        arr[index]= new Vector(20, 21);
    }
};

ostream& operator << (ostream& os, Vector& v1) {
        printf("%d %d", v1.x, v1.y);
        return os;
}

int main() {

    int n;

    cin >> n;

    SmartArray sarr(n);

    sarr[5] = new Vector(20, 21);
    //sarr.setVector(3);

    sarr[5]->showVector();

    //SmartArray sarr2(sarr); //default copy constructor

    //SmartArray sarr3(40);
    //sarr3 = sarr; // default assign operator

    return 0;
}
