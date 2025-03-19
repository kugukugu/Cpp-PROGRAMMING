#include <iostream>
#include <string>

class Monster {
protected:
    char* name;
    int hp;
    char* skill;

public:
    virtual ~Monster() {}

    virtual void attack(Monster* target) = 0;

    virtual void takeDamage(int damage) = 0;

    virtual void displayStatus() const = 0;

};

class Pikachu : public Monster {
public:
    Pikachu () {
        name = new char[8];
        strcpy(name,"pikachu");
        hp = 100;
        skill = new char[4];
        strcpy(skill, "gun");
    }

    ~Pikachu() {
        delete[] name;
        delete[] skill;
    }

    void attack(Monster* target) {
        cout << this->name << "가 " << target->name << "을 공격합니다!" << "(스킬: "<< this -> skill << ")" <<endl;
        target->takeDamage(30);
    };

    void takeDamage(int damage) {
        this->hp = this->hp - damage;
    };

     void displayStatus() const {
        cout << this ->name << " - 체력: " << this->hp << endl;
    };


};

class Demon : public Monster{
     Demon () {
        name = new char[6];
        strcpy(name,"Demon");
        hp = 100;
        skill = new char[6];
        strcpy(skill, "knife");
    }

     ~Monster() {}

     void attack(Monster* target) {
        cout << this->name << "이 " << target->name << "를 공격합니다!" << "(스킬: "<< this -> skill << ")" <<endl;
        target->takeDamage(25);
     };

     void takeDamage(int damage) {
        this->hp = this->hp - damage;
     };

     void displayStatus() const {
        cout << this ->name << " - 체력: " << this->hp << endl;
     };

};

int main() {
    //todo
    // 반복문을 써서 피카츄와 데몬이 자동 전투
    // 승부 결과를 출력

    return 0;
}
