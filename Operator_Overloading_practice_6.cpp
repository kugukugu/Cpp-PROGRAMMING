#include <iostream>

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

    friend ostream& operator<< (ostream& os, Vector& v1) ;
    friend istream& operator >> (istream& os, Vector& v1);
};

ostream& operator << (ostream& os, Vector& v1) {
        printf("%d %d", v1.x, v1.y);
        return os;
}

istream& operator >> (istream& os, Vector& v1) {
        scanf("%d %d", &v1.x, &v1.y);
        return os;
}

int main() {

	Vector v1;

	cin >> v1;

	cout << v1 << endl;

	return 0;
}
