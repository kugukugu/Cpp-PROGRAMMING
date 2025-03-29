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

    Vector& operator=(const Vector& v3) {
        this->x=v3.x;
        this->y=v3.y;

        return *this;
    }

     Vector& operator+=(const Vector& v3) {
        this->x+=v3.x;
        this->y+=v3.y;

        return *this;
    }

    friend Vector operator+(const Vector& v1, const Vector& v2) ;
    friend Vector operator-(const Vector& v1, const Vector& v2) ;
    friend bool operator==(const Vector& v1, const Vector&v2);
    friend bool operator!=(const Vector& v1, const Vector&v2);
};

Vector operator+(const Vector& v1, const Vector& v2) {
    return Vector(v1.x+v2.x, v1.y+v2.y);
}

Vector operator-(const Vector& v1, const Vector& v2) {
    return Vector(v1.x-v2.x, v1.y-v2.y);
}

bool operator==(const Vector& v1, const Vector&v2) {
    if(v1.x==v2.x && v1.y == v2.y) {
        return true;
    }
    else {
        return false;
    }
}

bool operator!=(const Vector& v1, const Vector&v2) {
    if(v1.x!=v2.x || v1.y != v2.y) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    Vector v1(6,5);
    Vector v2(3,2);

    Vector v3= v1+v2;
    Vector v4= v1-v2;

    v3.printVector();
    v4.printVector();

    v4 = v3;
    v4.printVector();

    v4 = v3 + v1 +v2;
    v4.printVector();

    v4 = v3 = v1 ;
    v4.printVector();

    v1 += v2;
    v1.printVector();

    if(v1==v2) {
        cout<< "같다." << endl;
    }
    else {
        cout << "다르다."<< endl;
    }

    if(v1!=v2) {
        cout<< "같다." << endl;
    }
    else {
        cout << "다르다."<< endl;
    }

    return 0;
}
