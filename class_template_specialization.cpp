#include <iostream>
#include <cstring>

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



    friend ostream& operator<<(ostream& os, const MyBox<T>& box) {
        return os << box.value;
    }
};

template <>
class MyBox <char* >{
private:
    char* value;
public:
    MyBox(const char* a) {
         char* test = new char[strlen(a)+1];
         strcpy(test,a);
         this->value= test;
    }

    ~MyBox() {

        delete[] value;
    }

    friend ostream& operator<<(ostream& os, const MyBox<char *>& box) {
        return os << box.value;
    }
};

int main() {
		char* str = new char[6];
		strcpy(str, "hello");
		MyBox<char*> m1(str);
		cout << m1 << endl;
		delete[] str;
		cout << m1 << endl;

		return 0;
}
