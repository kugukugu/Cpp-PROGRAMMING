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

    Vector& operator++() {
        ++this->x;
        ++this->y;

        return *this;
    }


    friend Vector operator++ ( Vector& v1,int) ;

};

Vector operator++ ( Vector& v1, int) {
    Vector temp = v1;
    v1.x++;
    v1.y++;
    return temp;
}

int main() {
    Vector v1(2, 4);

    (v1++).printVector();
    (++v1).printVector();

    return 0;
}
