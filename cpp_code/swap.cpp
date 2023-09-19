#include <iostream>
// call by value(copied!!) vs call by reference

/*
void swap(int x,int y){
    int temp = x;
    x = y;
    y = temp;
}

using namespace std;
int main(void){
    int intA = 10,intB = 20;

    cout << "[Before Swap] A: " << intA << "\t B: " << intB << endl;
    swap(intA,intB);
    cout << "[After Swap] A: " << intA << "\t B: " << intB << endl;

    return 0;
}
*/

/*
void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

using namespace std;
int main(void){
    int intA = 10, intB = 20;
    int* intPtrA = &intA;
    int* intPtrB = &intB;

    cout << "[Before Swap] A: " << intA << "\t B: " << intB << endl;
    swap(intPtrA,intPtrB);
    cout << "[After Swap] A: " << intA << "\t B: " << intB << endl;

    return 0;
}
*/

// Now, new C++ feature!!
void swap(int &x, int &y){      // just add & to the varname
    int temp = x;               // then automatically will call its address!!!
    x = y;                      // No dereferencing!!
    y = temp;
}

using namespace std;
int main(void){
    int intA = 10, intB = 20;

    cout << "[Before Swap] A: " << intA << "\t B: " << intB << endl;
    swap(intA,intB);
    cout << "[After Swap] A: " << intA << "\t B: " << intB << endl;

    return 0;
}

// Call by reference with const!! for memory efficiency
