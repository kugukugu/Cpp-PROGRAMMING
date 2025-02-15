#include <iostream>

using namespace std;

class Calculate {
private:
    int a;
    int b;
    int menu;

public:
    void input_number() {
        cout<<"숫자 2개를 입력하세요.." ;
        cin >> a;
        cin >> b;
    }

  void printmenu() {
        cout << "1.+\n2.-\n3.X\n4.%\n"<<endl;
        cout << "연산할 메뉴를 고르세요."<<endl;
        cin >> menu;
        cout << endl;
  }

  void print_result() {

        if(menu==1) {
            cout << a << '+' << b << '=' << a+b << endl;
        }
        if(menu==2) {
            cout << a << '-' << b << '=' << a-b << endl;
        }
        if(menu==3) {
            cout << a << 'X' << b << '=' << a*b << endl;
        }
        if(menu==4) {
            cout << a << '/' << b << '=' << a/b << endl;
        }
  }

};

int main() {
  Calculate c ;

  c.input_number();
  c.printmenu();
  c.print_result();

  return 0;
}
