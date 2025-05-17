#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class MyVector {
    T* temp;
    int size1;
    int capacity1;
public:
    MyVector() {
        this->size1 = 0;
        this->temp = NULL;
        this->capacity1 = 0;
    }

    ~MyVector() {
        delete[]this->temp;
    }

    void resize1(int n, T tmp = 0) {
        if (temp != NULL) {
            if (this->capacity1 < n) {
                this->capacity1 = 2*n;
                T* tp = new T[this->capacity1];
                for (int i = 0; i < this->size1; i++) {
                    tp[i] = temp[i];
                }
                for (int i = this->size1; i < n; i++) {
                    tp[i] = tmp;
                }
                this->size1 = n;
                delete[]temp;
                temp = tp;
            }
            else {
                if(n > size1) {
                    for(int i=this->size1; i<n; i++) {
                        temp[i]=tmp;
                    }
                    this->size1=n;
                }
                else {
                    this->size1=n;
                }
            }
        }
        else {
            this->capacity1 = n*2;
            this->temp = new T[this->capacity1];
            this->size1 = n;
            for(int i=0; i<n; i++) {
                this->temp[i]=tmp;
            }
        }
    }

    int get_capacity1() {
        return this->capacity1;
    }

    int get_size1() {
        return this->size1;
    }

    void clear1() {
        delete [] this->temp ;
        this->capacity1 = 0;
        this->size1=0;
        this->temp=NULL;
    }

    void push_back1(T n) {
        if(temp == NULL) {
            this->capacity1=5;
            temp = new T[this->capacity1];
            this->size1=1;
            temp[0]=n;
        }
        else {
            if(size1 < capacity1) {
                this->size1++;
                temp[this->size1-1]=n;
            }
            else {
                this->capacity1 *= 2;
                T *tmp = new T[this->capacity1];
                for (int i = 0; i < this->size1; i++) {
                    tmp[i] = temp[i];
                }
                delete [] temp;
                temp = tmp;
                this->size1++;
                temp[this->size1-1]=n;
            }
        }
    }

    T pop_back1() {
        this->size1=this->size1-1;
        return temp[this->size1];
    }

    void swap1 (MyVector<T> &d) {
        int temp = d.size1;
        d.size1 = this->size1;
        this->size1 = temp;

        int temp1 = d.capacity1;
        d.capacity1 = this->capacity1;
        this->capacity1 = temp1;

        T* tmp = d.temp;
        d.temp= this->temp;
        this->temp = tmp;
    }

};

int main() {

    MyVector<int>c;
    MyVector<int>d;

    c.push_back1(3);

    c.push_back1(1);

    c.push_back1(2);

    c.push_back1(4);

    c.push_back1(6);

    c.push_back1(7);

    /*cout << c.pop_back1() << endl;
    cout << c.pop_back1() << endl;
    cout << c.pop_back1() << endl;
    cout << c.pop_back1() << endl;
    cout << c.pop_back1() << endl;*/

    cout << "Size: "<< c.get_size1() << endl;
    cout << "Capacity: "<< c.get_capacity1() << endl;

    c.resize1(10);
    cout << "Size: "<< c.get_size1() << endl;
    cout << "Capacity: "<< c.get_capacity1() << endl;

    c.resize1(15);
    cout << "Size: "<< c.get_size1() << endl;
    cout << "Capacity: "<< c.get_capacity1() << endl;


    c.resize1(18);
    cout << "Size: "<< c.get_size1() << endl;
    cout << "Capacity: "<< c.get_capacity1() << endl;

    int count1= c.get_size1();

    for(int i = 0; i< count1; i++)
    {
        cout << c.pop_back1() << endl;
    }

    c.push_back1(3);
    d.push_back1(16);

    c.push_back1(1);
    d.push_back1(90);

    c.push_back1(2);

    c.push_back1(4);

    c.swap1(d);

    count1 = c.get_size1();
    int count2 = d.get_size1();

    for(int i = 0; i< count1; i++)
    {
        cout << c.pop_back1() << ' ';
    }

    cout << endl;

    for(int i = 0; i< count2; i++)
    {
        cout << d.pop_back1() << ' ';
    }

    cout << endl;

    return 0;
}
