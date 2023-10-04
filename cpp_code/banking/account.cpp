#include "account.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

Account::Account(void){
    balance = 0.0;
    transaction = 0;
}

void Account::Withdraw(float amt){
    balance = balance - amt;
    transaction++;
}

void Account::Deposit(float amt){
    balance += amt;
    transaction++;
}

float Account::GetBalance(void){
    return balance;
}

void Account::EndMonthUtil(void){
    std::cout << "transactions: " << transaction << "balance: " << balance << std::endl;
    transaction = 0;
}

class MonthlyFee : public Account{
    void EndMonth(void);
};

void MonthlyFee::EndMonth(void){
    Withdraw(5.00);
    Account::EndMonthUtil();
}

class NickleNDime : public Account{
    virtual void EndMonth(void);
};

void NickleNDime::EndMonth(void){
    Withdraw(transaction * 0.50);
    Account::EndMonthUtil();
}

class Gambler : public Account{
    virtual void Withdraw(float amt);
    virtual void EndMonth(void){
        EndMonthUtil();
    }
};

static int RandomNum(int num){
    return (rand() % num);
}

void Gambler::Withdraw(float amt){
    if(RandomNum(100) <= 50){
        Account::Withdraw(2*amt);
    }
    else{
        Account::Withdraw(0.00);
    }
}

static Account* RandomAccount(void){
    switch(RandomNum(3))
    {
    case 0: return (new Gambler);
        break;
    case 1: return (new NickleNDime);
        break;
    case 2: return (new MonthlyFee);
        break;
    }
    return 0;
}

#define NUMACCOUNTS 20

void Account::TestOneMonth(void){
    Account* accounts[NUMACCOUNTS];
    int accountNum;
    int day;

    for(accountNum = 0; accountNum < NUMACCOUNTS; accountNum++){
        accounts[accountNum] = RandomAccount();
        accounts[accountNum]->Deposit(100);
    }

    for (day = 1; day <= 31; day++){
        accountNum = RandomNum(NUMACCOUNTS);
        if(RandomNum(2)){
            accounts[accountNum]->Deposit(RandomNum(100));
        }
        else{
            accounts[accountNum]->Withdraw(RandomNum(100));
        }
    }

    for(accountNum = 0; accountNum < NUMACCOUNTS; accountNum++){
        std::cout << "account: " << accountNum << std::endl;
        accounts[accountNum]->EndMonth();
    }
}