#pragma once
#include <cstdlib>

class Account{
    protected:
    float balance;
    int transactions = 0;

    public:
    //Constructor
    Account();
    Account(float amt);

    //
    void Deposit(float amt);
    virtual void Withdraw(float amt);
    float GetBalance(void);
    virtual void EndMonth(void) = 0; 

    protected:
    void EndMonthUtil(void);
    /* You declare a pure virtual function by using a pure specifier(=0) 
    in the declaration of a virtual member function in the class declaration*/
};

class MonthlyFee : public Account{
    public:
    //Constructor
    MonthlyFee();
    MonthlyFee(float amt);

    //
    void EndMonth(void);
};

class NickleNDime : public Account{
    public:
    //Constructor
    NickleNDime();
    NickleNDime(float amt);

    //
    void Withdraw(float amt);
    void EndMonth(void);
};

class Gambler : public Account{

    public:
    //Constructor
    Gambler();
    Gambler(float amt);

    //
    void Withdraw(float amt);
    void EndMonth(void);
};