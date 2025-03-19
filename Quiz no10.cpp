#include <iostream>
#include <cstring>

using namespace std;

class Counter {
private:
    int Count;
    static int totalcount;

public:

    Counter (int Count) {
        this-> Count = Count;
        totalcount ++;
    }

    void print_value () {
        cout << Count << endl;
        cout << totalcount << endl;
    }

} ;

int Counter::totalcount;

int main() {

    Counter s1(1);
    Counter s2(2);
    Counter s3(3);
    Counter s4(4);
    
    s1.print_value();

    return 0;
}
