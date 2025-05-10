#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class MyVector {
    T *temp;
    int size1;
    int capacity1;
public:
    MyVector() {
        this->size1=0;
        this->temp=NULL;
        this->capacity1=0;
    }

    ~MyVector() {
        delete []this->temp;
    }

    void push_back1(T tmp) {

    }

    void resize1(int n, T tmp=0) {
        
        if(temp!=NULL) {
            if(this->capacity < n) {
                T *tp = new T[n];
                for(int i=0; i<this->size1; i++) {
                    tp[i]=temp[i];
                }
                for(int i=this->size1; i<n; i++) {
                    tp[i]=tmp;
                }
                this->capacity=n;
                this->size1=n;
                delete []temp;
                temp = tp;
            }
            else {
                if(n>size1) {
                    
                }
                else 
                
            }
            
        }
        else {
            this->temp= new T[n];
            this->size1= n;
            this->capacity1= n;
        }
    }

    void capacity1() {

    }






};

int main() {


    return 0;
}
