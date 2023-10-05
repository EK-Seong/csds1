#include <iostream>
#include <string>

using namespace std;
class ex{
    string* ptr;
    public:
    ex(const string& str) : ptr(new string(str)){}
    ~ex(){delete ptr;}
    //copy constructor:
    ex(const ex& x) : ptr(new string(x.content())){}
    //access content:
    const string& content() const {
        return* ptr;
        }
};

int main(void){
    ex foo ("Example");
    ex bar = foo;
    ex baz ("Another one");
    foo = baz;
    cout << "bar's content: " << bar.content() << endl;
    return 0;
}