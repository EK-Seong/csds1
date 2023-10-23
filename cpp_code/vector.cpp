#include <iostream>
#include <vector>

using namespace std;

int main(void){
    vector<int> v{1};
    int a[2];

    cout << "&v = " << &v << endl;
    cout << "v is pointing at " << &v.front() << " , and it's end is at "<<&v.back()<< endl;
    cout << "&a = " << &a << endl;
    cout << "&a[0] = " << &a[0] << endl;
    cout << "&a[1] = " << &a[1] << endl;

    return 0;
}