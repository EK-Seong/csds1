#include <iostream>

void swap_int_int(int &x,int &y){
    int temp = x;
    x = y;
    y = temp;
}

void swap_double_double(double &x,double &y){
    double temp = x;
    x = y;
    y = temp;
}

void swap_char_char(char &x,char &y){
    char temp = x;
    x = y;
    y = temp;
}

using namespace std;
int main(void){
    int intA = 10, intB = 20;
    double doubleA = 10.15, doubleB = 20.25;
    char charA = 'a', charB = 'b';

    //
    cout << "[Before Swap] A: " << intA << "\t B: " << intB << endl;
    swap_int_int(intA,intB);
    cout << "[After Swap] A: " << intA << "\t B: " << intB << endl;

    cout << "[Before Swap] A: " << doubleA << "\t B: " << doubleB << endl;
    swap_double_double(doubleA,doubleB);
    cout << "[After Swap] A: " << doubleA << "\t B: " << doubleB << endl;

    cout << "[Before Swap] A: " << charA << "\t B: " << charB << endl;
    swap_char_char(charA,charB);
    cout << "[After Swap] A: " << charA << "\t B: " << charB << endl;

    return 0;
}

// Function overloading