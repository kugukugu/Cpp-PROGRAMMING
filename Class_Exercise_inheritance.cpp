#include <iostream>
#include <cstring>

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

class VIPerson : public Person {
private:
    char* email;
public:
  VIPerson (char* name, int age, char* email)   {
        strncpy(this->name, name, 9);
        this->name[9] = '\0';
        this->age = age;
        this->email = new char[strlen(email)+1];
        strcpy(this->email ,email);
  }  

    
};

class PersonManager {
private:
    int MenuOption, index;
    Person* p[100];
public:

    PersonManager() {
        index = 0;
        for (int i = 0; i < 3; i++) {
            p[i] = nullptr;
        }
    }

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
            cout << endl;
            if (MenuOption < 1 || MenuOption >5) {
                cout << "잘못된 입력" << endl;
            }
            cout << endl;
        } while (MenuOption < 1 || MenuOption >5);

        return MenuOption;
    }

    void join_user() {
        int choose, age;
        char *name, *email;

        do
        {
            cout << "메뉴를 선택하시오. " << endl;
            cout << "1. 일반회원" << endl;
            cout << "2. VIP" << endl;
            cin >> choose;
            cout << endl;
            if (MenuOption < 1 || MenuOption >5) {
                cout << "잘못된 입력" << endl;
            }
            cout << endl;
        } while (choose < 1 || MenuOption >2);

        if (choose == 1) {
            
            cout << "이름과 나이를 입력하시오. " << endl;
            cout << "이름: ";
            cin >> name;
            cout << "나이: ";
            cin >> age;
            cout << "이메일: "
            cin >> email;
            cout << "\n";
            p[index] = new VIPerson(name, age, email);
            index++;
        }
        else {
            p[index] = new Person;
            cout << "이름과 나이를 입력하시오. " << endl;
            cout << "이름: ";
            cin >> p[index]->name;
            cout << "나이: ";
            cin >> p[index]->age;
            cout << "\n";
            index++;

        }
        
    }

    void search_user() {
        for (int i = 0; p[i] != nullptr; i++) {
            cout << p[i]->name << endl;
            cout << p[i]->age << endl;
            for (int j = 0; j < 3; j++) {
                if (p[i]->hobby[j] != nullptr)
                    cout << p[i]->hobby[j] << ' ';
            }
            cout << '\n' << endl;
        }
    }

    void total_user() {
        cout << "회원 명수: " << index << endl;
        cout << '\n';
    }

    Person* find_name() {
        char name[10];
        bool count = false;

        do {
            cout << "이름을 입력하시오. ";
            cin >> name;

            for (int i = 0; p[i] != nullptr; i++) {
                if (strcmp(p[i]->name, name) == 0) {
                    count = true;
                    cout << p[i]->name << ' ' << p[i]->age << ' ';
                    for (int j = 0; j < 3; j++) {
                        if (p[i]->hobby[j] != nullptr) {
                            cout << p[i]->hobby[j] << ' ';
                        }
                    }
                    cout << '\n' << endl;
                    return p[i];
                }
            }
            if (count == false) {
                cout << "찾는 사람이 없습니다" << endl;
                cout << endl;
            }
        } while (count == false);
    }

    void add_hobby() {
        Person* tmp = find_name();

        for (int k = 0; k < 3; k++) {
            if (tmp->hobby[k] == nullptr) {
                cout << "취미를 입력하시오. " << endl;
                tmp->hobby[k] = new char[10];
                cin >> tmp->hobby[k];
                break;
            }
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
        else if (menu == 4) {
            p1.find_name();
        }
        else {
            p1.add_hobby();
        }

    }

}
