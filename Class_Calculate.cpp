#include <iostream>

using namespace std;

class Person {
public:
    char name[10];
    int age;
    char* hobby[3];

    Person() {
        for (int i = 0; i < 3; i++) {
            hobby[i] = nullptr;
        }
    }
};

class PersonManager {
private:
    int menuOption;
    Person p1;
public:
    int menu() {
        do
        {
            cout << "메뉴를 선택하시오. " << endl;
            cout << "1. 회원등록" << endl;
            cout << "2. 전체 회원 조회" << endl;
            cout << "3. 전체 회원 수" << endl;
            cout << "4. 이름 찾기" << endl;
            cout << "5. 기존 회원 관심사 추가" << endl;
            cin >> menuOption;
            if (menuOption < 1 || menuOption >5) {
                cout << "잘못된 입력" << endl;
            }
        } while (menuOption < 1 || menuOption >5);

        return menuOption;
    }

    Person* join_user() {
        cout << "이름과 나이를 입력하시오. " << endl;
        cout << "이름: ";
        cin >> p1.name;
        cout  << "나이: ";
        cin >> p1.age;
        cout << "\n";

        return &p1;
    }

      void search_user(Person* p[]) {
          for (int i = 0; p[i] != nullptr; i++) {
              cout << p[i]->name << endl;
              cout << p[i]->age << endl;
              cout << "\n";
          }
      }

     /* void total_user(Person* p[]) {
          for (int i = 0; p[i] != NULL; i++) {

          }
          cout << "회원 명수: " << i - 1 << endl;
      }

      void find_name(Person* p[]) {
          char name[10];
          cout << "이름을 입력하시오. ";
          cin >> name;

          for (int i = 0; p[i] != NULL; i++) {
              if (!= strcmp(&p[i]->name, &name)) {
                  return p[i];
              }
          }

          cout << "찾는 사람이 없습니다" << endl;*/
};

 int main() {
     Person* p[100] = { nullptr };
     PersonManager p1;
     int menu, i = 0;

       while (i + 1) {
           menu = p1.menu();

           if (menu == 1) {
                p[i] = p1.join_user();
                i++;
           }
           else if (menu == 2) {
                p1.search_user(p);
           }
            /*else if (menu == 3) {
                total_user(p1);
            }
            else if (menu == 4) {
                find_name();
            }*/

        }

  }
