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
    int MenuOption, i=0;
    Person* p[100] = { nullptr };
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
            cin >> MenuOption;
            if (MenuOption < 1 || MenuOption >5) {
                cout << "잘못된 입력" << endl;
            }
            cout << endl;
        } while (MenuOption < 1 || MenuOption >5);

        return MenuOption;
    }

    void join_user() {
        p[i] = new Person;
        cout << "이름과 나이를 입력하시오. " << endl;
        cout << "이름: ";
        cin >> p[i]->name;
        cout  << "나이: ";
        cin >> p[i]->age;
        cout << "\n";
        i++;
    }

      void search_user() {
          for (int i = 0; p[i] != nullptr; i++) {
              cout << p[i]->name << endl;
              cout << p[i]->age << endl;
              for (int j = 0; j < 3; j++) {
                  if(p[i]->hobby[j] != nullptr)
                    cout << p[i]->hobby[j] << ' ';
              }
              cout << '\n' << endl;
          }
      }

      void total_user() {
          cout << "회원 명수: " << i << endl;
          cout << '\n';
      }

     /* void find_name(Person* p[]) {
          char name[10];
          cout << "이름을 입력하시오. ";
          cin >> name;

          for (int i = 0; p[i] != NULL; i++) {
              if (!= strcmp(&p[i]->name, &name)) {
                  return p[i];
              }
          }

          cout << "찾는 사람이 없습니다" << endl;*/
      void add_hobby() {
          char name[10];
          int j = 0 , i=0;
          
          do {
                cout << "이름을 입력하시오. " << endl;
                cout << "이름: ";
                cin >> name;
                getchar();

                for ( i = 0; p[i] != nullptr; i++) {
                    if (strcmp(p[i]->name, name)==0) {
                        j=0;
                         break;
                    }
                    else {
                        j++;
                    }

                    if (j > 0) {
                        cout << "잘못된 입력" << j<<endl;
                    }
                    cout << endl;
                }
          } while (j>0);

          cout << "취미 3개를 입력하시오. " << endl;
          for (int k = 0; k < 3; k++) {
              cout << k + 1 << "번 째 취미: ";
              p[i]->hobby[k] = new char[50];
              cin >> p[i]->hobby[k];
          }
          cout << endl;
      }
};

 int main() {
    
     PersonManager p1;
     int menu, i = 0;

       while (1) {
           menu = p1.menu();

           if (menu == 1) {
                p1.join_user();
           
           }
           else if (menu == 2) {
                p1.search_user();
           }
           else if (menu == 3) {
                p1.total_user();
            }
           /* else if (menu == 4) {
                find_name();
            }*/
           else {
               p1.add_hobby();
           }

        }

  }
