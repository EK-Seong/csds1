#include "account.h"
#include <iostream>

using namespace std;

Account::Account(){}
Account::Account(float amt){
    balance = amt;
}

void Account::Deposit(float amt){
    balance += amt;
    transactions++;
}
void Account::Withdraw(float amt){
    balance -= amt;
    transactions++;
}
float Account::GetBalance(void){
    return balance;
}

void Account::EndMonthUtil(void){
    cout << "transactions: " << transactions << ", balance: " << balance << endl;
    transactions = 0;
}

// MonthlyFee

MonthlyFee::MonthlyFee() : Account() {}
MonthlyFee::MonthlyFee(float amt) : Account(amt) {}


void MonthlyFee::EndMonth(void){
    Withdraw(5.00);
    EndMonthUtil();
}

// Nickle'n Dime

NickleNDime::NickleNDime() : Account() {}
NickleNDime::NickleNDime(float amt) : Account(amt) {}

void NickleNDime::Withdraw(float amt){
    Account::Withdraw(amt);
    Account::Withdraw(0.50);
}

void NickleNDime::EndMonth(void){
    EndMonthUtil();
}

// Gambler

static int RandomNum(int num){
    return (rand() % num);
} //storage

Gambler::Gambler() : Account() {}
Gambler::Gambler(float amt) : Account(amt) {}

void Gambler::Withdraw(float amt){
    if(RandomNum(100) <= 49){
        Account::Withdraw(0.0);
    }
    else{
        Account::Withdraw(amt*2);
    }
}

void Gambler::EndMonth(void){
    EndMonthUtil();
}