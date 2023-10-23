#include "account.h"
#include <iostream>
#include <cstdlib>
#include <new>

#define NUMACCOUNTS 20

using namespace std;

static int RandomNum(int num){
    return rand()%num;
}
static Account *RandomAccount(void){
    switch(RandomNum(3)){
        case 0: return new Gambler();
            break;
        case 1: return new NickleNDime();
            break;
        case 2: return new MonthlyFee();
            break;
    }
    return 0;
}

int main(void){
    Account* accounts[NUMACCOUNTS];

    for(int i = 0; i < NUMACCOUNTS; i++){
        accounts[i] = RandomAccount();
        accounts[i]->Deposit(100.0);
    }

    for(int i = 0; i <= 31; i++){
        i = RandomNum(NUMACCOUNTS);
        if(RandomNum(2)){
            accounts[i]->Deposit(RandomNum(100));
        }
        else{
            accounts[i]->Withdraw(RandomNum(100));
        }
    }

    for(int i = 0; i < NUMACCOUNTS; i++){
        cout << "account: " << i << " " ;
        accounts[i]->EndMonth();
    }
}