#include <iostream>
#include <cstring>

using namespace std;

class Person {
protected:
    char name[10];
    int age;
    char* likes[3];
public:
    Person() {}

    Person(const char* name, int age) {
        this->age = age;
        strncpy(this->name, name, 9);
        this->name[9] = '\0';

        for (int i = 0; i < 3; i++) {
            likes[i] = nullptr;
        }
    }

    ~Person() {
        for (int i = 0; i < 3; i++) {
            if (likes[i] != nullptr) {
                delete[] likes[i];
            }
        }
    }

    char* getName() {
       return this->name;
    }

    void addLike(char* like) {
        for (int i = 0; i < 3; i++) {
            if (likes[i] == nullptr) {
                likes[i] = new char[strlen(like) + 1];
                strcpy(likes[i], like);
                return;
            }
        }
        cout << "관심사는 최대 3개까지 등록할 수 있습니다." << endl;
    }

    virtual void printInfo() const {
        cout << "이름: " << name << endl;
        cout << "나이: " << age << endl;
        cout << "관심사: ";
        for (int i = 0; i < 3; i++) {
            if (likes[i] != nullptr) {
                cout << likes[i] << ", ";
            }
        }
        cout << endl;
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

    ~VIPerson() {
        delete[] email;
    }

     void printInfo() const {
        cout << "********* VIP *********" << endl;
        cout << "이름: " << name << endl;
        cout << "나이: " << age << endl;
        cout << "이메일: " << email << endl;
        cout << "관심사: ";
        for (int i = 0; i < 3; i++) {
            if (likes[i] != nullptr) {
                cout << likes[i] << ", ";
            }
        }
        cout << endl;
        cout << "***********************" << endl;
    }
};

class PersonManager {
private:
    Person* members[10];

public:
    PersonManager() {
        for (int i = 0; i < 10; i++) {
            members[i] = nullptr;
        }
    }

    ~PersonManager() {
        for (int i = 0; i < 10; i++) {
            if (members[i] != nullptr) {
                delete members[i];
            }
        }
    }

    void registerMember(char* name, int age) {
        for (int i = 0; i < 10; i++) {
            if (members[i] == nullptr) {
                members[i] = new Person(name, age);
                return;
            }
        }
        cout << "회원은 최대 10명까지 등록할 수 있습니다." << endl;
    }

    void registerVIPMember(char* name, int age, char* email) {
        for (int i = 0; i < 10; i++) {
            if (members[i] == nullptr) {
                members[i] = new VIPerson(name, age, email);
                return;
            }
        }
        cout << "회원은 최대 10명까지 등록할 수 있습니다." << endl;
    }

    void showAllMembers() const {
        cout << "=========== 전체 회원 목록 ===========" << endl;

        for (int i = 0; i < 10; i++) {
            if (members[i] != nullptr) {
                members[i]->printInfo();
                cout << "-----------------------------------------" << endl;
            }
        }
    }

    int getTotalMembers() const {
        for (int i = 0; i < 10; i++) {
            if (members[i] == nullptr) {
                return i;
            }
        }
        return 10;
    }

    Person* findByName(char* name) {
        for (int i = 0; i < 10; i++) {
            if (members[i] != nullptr && strcmp(members[i]->getName(), name) == 0) {
               return members[i];
            }
        }
        return nullptr;
    }

    void addLikeToPerson(char* name, char* like) {
        Person* person = findByName(name);
        if (person != nullptr) {
            person->addLike(like);
        } else {
            cout << "해당 이름의 회원을 찾을 수 없습니다." << endl;
        }
    }
};


int main() {
    PersonManager manager;

    manager.registerMember("Lee", 25);
    manager.registerMember("Park", 30);
    manager.registerVIPMember("Ko", 21, "kugukugu");

    manager.showAllMembers();

    cout << endl;
    cout << "전체 회원 수: " << manager.getTotalMembers() << endl;
    cout << endl;

    manager.addLikeToPerson("Lee", "Reading");
    manager.addLikeToPerson("Parking", "Drving");
    manager.addLikeToPerson("Ko", "Building");

    manager.showAllMembers();

    return 0;
}
