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
    cout << a.n << '\n';
    Dummy* c = new Dummy;
    cout << Dummy::n << endl;
    delete c;
    return 0;
}