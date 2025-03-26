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

    friend Vector operator+(const Vector& v1, const Vector& v2) ;
    friend Vector operator-(const Vector& v1, const Vector& v2) ;

};

Vector operator+(const Vector& v1, const Vector& v2) {
    return Vector(v1.x+v2.x, v1.y+v2.y);
}

Vector operator-(const Vector& v1, const Vector& v2) {
    return Vector(v1.x-v2.x, v1.y-v2.y);
}

int main() {
    Vector v1(6,5);
    Vector v2(3,2);

    Vector v3= v1+v2;
    Vector v4= v1-v2;

    v3.printVector();
    v4.printVector();

    return 0;
}
