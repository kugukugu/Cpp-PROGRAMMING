#include <iostream>
#include <cstring>

using namespace std;

class Vector {
private:
    int x;
    int y;
public:
    Vector(int x, int y) {
        this->x = x;
        this->y = y;
    }

    ~Vector() {}

    void printVector() {
        cout << this->x << ", " << this->y << endl;
    }


    Vector& operator* (int n) {
        this->x*=n;
        this->y*=n;

        return *this;
    }


    friend Vector& operator* (int n, Vector& v1) ;

};

Vector& operator* (int n, Vector& v1) {
    v1.x*=n;
    v1.y*=n;
    return v1;
}

int main() {
    Vector v1(2, 4);


    (v1*2).printVector() ;


    (2*v1).printVector() ;

    return 0;
}
