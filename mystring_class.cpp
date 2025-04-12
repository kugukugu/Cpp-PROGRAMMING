#include <iostream>
#include <cstring>

using namespace std;

class mystring {
private:
    char *ch;
    int length;
public:
    mystring() {
        ch = nullptr;
        length = 0;
    }

    mystring(char *ch) {
        length = strlen(ch);
        this->ch = new char[length+1];
        strcpy(this->ch, ch);
    }

    mystring(const mystring& mystring1) {
        length = strlen(mystring1.ch);
        this->ch = new char[length+1];
        strcpy(this->ch, mystring1.ch);
    };

    int length1() {
        return length;
    }

    void operator+=(const mystring& v1) {
        char *ch = new char [length+strlen(v1.ch)+1];
        strcpy(ch,this->ch);
        strcat(ch, v1.ch);
        ch[length+strlen(v1.ch)] ='\0';
        delete []this->ch ;
        this->ch = ch;
        length= strlen(this->ch);
    }

   char operator[] (int index) {
        if (index < 0 || index >= length) {
            cout << "Array index out of bound" << endl;
            exit(1);
        }

        return ch[index];
    }

    mystring substr1(int start, int length) {
        char *test = new char[length+1];
        strncpy (test, this->ch+start, length);
        test[length] = '\0';
        mystring mys = test;
        delete[] test;
        return mys;
    }

    size_t find1(char* ch) {
        char *test = strstr(this->ch, ch);

        if (test != nullptr) {
            return test-this->ch;
        }
        else {
            return -1;
        }
    }

    friend mystring operator+(const mystring& mystring1, const mystring& mystring2);
    friend ostream& operator << (ostream& os, mystring& v);
    friend istream& operator >> (istream& os, mystring& v);
    friend bool operator==(const mystring& v1, const mystring&v2);
    friend bool operator>(const mystring& v1, const mystring&v2);

};

mystring operator+(const mystring& mystring1, const mystring& mystring2) {
    char *test = new char [strlen(mystring1.ch)+strlen(mystring2.ch)+1];
    strcpy (test, mystring1.ch);
    strcat(test, mystring2.ch);
    test[strlen(mystring1.ch)+strlen(mystring2.ch)] = '\0';
    mystring mys = test;

    return  mys;
}

ostream& operator << (ostream& os, mystring& v) {
        printf("%s", v.ch);
        return os;
}

istream& operator >> (istream& os, mystring& v) {
        char str[100];
        scanf("%s", str);
        v.ch = new char [strlen(str)+1];
        strcpy(v.ch, str);

        return os;
}

bool operator==(const mystring& v1, const mystring&v2) {
    if(strcmp(v1.ch, v2.ch)==0) {
        return true;
    }
    else {
        return false;
    }
}

bool operator>(const mystring& v1, const mystring&v2) {
    if(strcmp(v1.ch, v2.ch)>0) {
        return true;
    }
    else {
        return false;
    }
}

int main() {

    mystring str1 = "Hello";
    mystring str2 = "World!";

    mystring result = str1+str2;

    cout << result << endl;

    str1 += str2;

    cout << str1 << endl;

    if(str1==result) {
        cout << "두 문자열은 같음" << endl;
    }
    else {
        cout << "두 문자열은 다름" << endl;
    }

    //문자열의 크기 비교
    //1. 문자열의 길이 비교
    //2. 문자열의 알파벳 문자를 비교한다. >> 이걸로

    if(str1 > result) {
        cout << "str1이 더 크다." << endl;
    }
    else {
        cout << "str1이 더 작다." << endl;
    }

    mystring str3;
    cout << "문자열 입력 .. ";
    cin >> str3;
    cout << str3 << endl;

    cout << "Length: " << result.length1() << endl; //길이

    cout << "First char: " << result[0] << endl; //인덱싱

    mystring sub = result.substr1(5,5); //부분 문자열
    cout << "Substring: " << sub << endl;

    size_t pos = result.find1("animal"); //문자열 찾기
    if(pos != -1) {
        cout << pos << endl;
    }
    else {
        cout << "못 찾음" << endl;
    }

    return 0;
}
