#include <iostream>

using namespace std;

template <class T>
class myPair{
    T a, b;
    public:
    myPair(T first, T second){
        a = first;
        b = second;
    }
    T getMax();
};

template <class T>
T myPair<T>::getMax(){
    T retval;
    retval = a>b?a:b;
    return retval;
}

int main(void){
    myPair<int> myObj(100,75);
    myPair<double> myObj2(20.5,14.66);
    cout << myObj.getMax() << endl;
    cout << myObj2.getMax() << endl;
    return 0;
}