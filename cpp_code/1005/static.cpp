// static members in classes
#include <iostream>
using namespace std;
class Dummy{
    public:
    static int n;
    Dummy(){
        n++;
        };
};

int Dummy::n = 0;   // Static members cannot be initialized directly in the class, 
                    // but need to be initialized somewhere outside of it.
                    // object 와 상관없이 class자체에 initialization함
int main(void){
    Dummy a;
    Dummy b[5];
    cout << a.n << '\n'; // 지금까지 총 6개의 Dummy object를 생성했다
    Dummy* c = new Dummy; // 이젠 7개
    cout << Dummy::n << endl;
    delete c;
    return 0;
}