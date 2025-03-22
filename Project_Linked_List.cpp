#include <iostream>
#include <cstring>

using namespace std;

class Monster {
protected:
    char* name;
    int hp;
    char* skill;

public:
    virtual ~Monster() {}

    bool compareName (char* name) {
        if(strcmp(this->name, name)==0) {
            return true;
        }
        else {
            return false;
        }
    }

    virtual void attack(Monster* target) = 0;

    virtual void takeDamage(int damage) = 0;

    virtual void displayStatus() const = 0;

    char* get_name() {
        return this->name;
    };

};

//Node클래스 직접 디자인
class Node {
public:
    Monster *mp;
    Node *next;
};



class MonsterLinkedList {
protected:
    Node* head;

public:
    MonsterLinkedList() {
        head = nullptr;
    }

    ~MonsterLinkedList() {
        Node *temp = head;

        while (head != nullptr) {
            delete temp->mp;
            head = temp -> next;
            delete temp;
            temp = head;
        }

    }

    void Append(Monster* mp) {
        Node* np = new Node ;
        np->mp = mp;
        np->next = nullptr;

        if (this->head == nullptr) { //연결리스트가 비어 있을 때
            this->head = np;
        }
        else { //연결리스트가 비어있지 않다 = 하나이상
            Node *temp = head;
            while(temp -> next != nullptr) {
                temp = temp ->next;
            }
            temp -> next = np;
        }
    };

    void Remove(char *name) {
        if (head == nullptr) {
            return;
        }

        Node* temp  = head;
        Node* prev = head;

        while(temp->mp->compareName(name) == false) {
            prev = temp;
            if (temp -> next == nullptr) {
                return ;
            }
            temp = temp -> next;
        }
        prev -> next = temp -> next;
        delete temp -> mp;
        delete temp;
    };

    void print() const {
        Node *temp = head;

        while (temp != nullptr) {
            temp -> mp -> displayStatus();
            temp = temp -> next;
        }
    };

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
        cout << this->name << "가 " << target->get_name() << "을 공격합니다!" << "(스킬: "<< this -> skill << ")" <<endl;
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
public:
    Demon () {
        name = new char[6];
        strcpy(name,"Demon");
        hp = 100;
        skill = new char[6];
        strcpy(skill, "knife");
    }

     ~Demon() {}

     void attack(Monster* target) {
        cout << this->name << "이 " << target->get_name() << "를 공격합니다!" << "(스킬: "<< this -> skill << ")" <<endl;
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

    MonsterLinkedList ml;

    Monster* m1 = new Pikachu ;
    Monster* m2 = new Demon ;

    ml.Append(m1);
    ml.Append(m2);

    ml.print();

    return 0;
}
