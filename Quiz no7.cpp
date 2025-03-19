#include <iostream>
#include <cstring>

using namespace std;

class BankAccount {
private:
    int money;
    char account[10];
public:

    BankAccount (char *name) {
        money = 0;
        strcpy(account, name);
    }

    void deposit (int money) {
        cout << "잔액: "<< this->money <<endl;
        this->money = money + this->money;
        cout << "잔액: "<< this->money <<endl;
    }

    void withdrawl(int money) {
        if (this->money > money){
            cout << money << "원이 출금 됐습니다."<< endl;
        }
        else {
            cout << "잔액 부족"<< endl;
        }
    }

    void balance () {
        cout << "잔액: "<< money <<endl;
    }

} ;

int main() {

    char account[10];

    cout << "계좌명을 입력하시오. ";
    cin >> account;

    BankAccount bank(account);

    bank.balance();
    bank.deposit(100000);
    bank.withdrawl(90000);
    bank.withdrawl(100000);

    return 0;
}
