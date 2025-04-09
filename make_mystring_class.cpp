#include <iostream>

using namespace std;

class mystring() {
private:
    char *ch;
  
public:
    mystring(char *ch) {
        this->ch = new char[strlen(ch)+1];
        strcpy(this->ch, ch);
    }

    mystring(const mystring& mystring1) {
        this->ch = new char[strlen(mystring1.ch)+1];
        strcpy(this->ch, mystring1.c);
    };

    friend mystring operator+(const mystring& mystring1, const mystring& mystring2);

};

mystring& operator+(const mystring& mystring1, const mystring& mystring2) {
    mystring mys ;
    char *test = new char [strlen(mystring1.ch)+strlen(mysting2.ch)+1];
    strcpy (test, strcat(mystring1.ch, mystring2.ch));
    mys = test;

    return  mys;
}

int main() {

    return 0;
}
