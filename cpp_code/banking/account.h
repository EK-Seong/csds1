#pragma once
#include <stdio.h>
#include <iostream>

class Account{
    public:
    Account(void);
    virtual void Withdraw(float amt);
    virtual void Deposit(float amt);
    virtual float GetBalance(void);
    virtual void EndMonth(void) = 0; // pure virtual, force subclasses to implement

    protected:
    float balance;
    int transaction;
    void EndMonthUtil(void);

    public:
    static void TestOneMonth(void);
};