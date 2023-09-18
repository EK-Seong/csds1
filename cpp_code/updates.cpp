#include <iostream>

// Function argument defaults
/*
using namespace std;

int divide(int a, int b=2){
    int r;
    r = a/b;
    return r;
}

int main(){
    cout << divide(12) << endl;
    cout << divide(20,4) << endl;
    return 0;
}
*/

// Range-based for loop

#include <string>

using namespace std;
int main(){
    string myStr {"Hello!"};
    for (auto c : myStr){   //The type of c is automatically deduce as the type of the elements in str
        cout << "[" << c << "]";
    }
    cout << endl;

    return 0;
}