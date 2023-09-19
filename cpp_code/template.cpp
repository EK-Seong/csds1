#include <iostream>


// Function template is like a
template <class T>
void mySwap(T &x,T &y){
    T temp = x;
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
    mySwap<int>(intA,intB);
    cout << "[After Swap] A: " << intA << "\t B: " << intB << endl;

    cout << "[Before Swap] A: " << doubleA << "\t B: " << doubleB << endl;
    mySwap<double>(doubleA,doubleB);
    cout << "[After Swap] A: " << doubleA << "\t B: " << doubleB << endl;

    cout << "[Before Swap] A: " << charA << "\t B: " << charB << endl;
    mySwap<char>(charA,charB);
    cout << "[After Swap] A: " << charA << "\t B: " << charB << endl;

    return 0;
}


// + Automatic parameter deduction

// 아까 function overload 할 때는 function name을 swap으로 해도 컴파일이 됐는데, template을 사용할 때는 이름이 swap은 안 되고 mySwap은 되는 것 같습니다. 혹시 이유가 뭘까요?
// swap은 std::swap이라는 기존의 함수가 있어서 그런 문제가 있습니다.

/*Recap
- Abstraction
for reproducibility, interpretablity ...
*/