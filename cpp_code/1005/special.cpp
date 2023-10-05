#include <iostream>
#include <string>

using namespace std;

class Ex{
    string* ptr;
    public:
    // constructors:
    Ex(): ptr(new string){}
    Ex(const string& str) : ptr(new string(str)) {}
    // destructor: class내부에서 dynamic memory alloc이 있을 경우 주로 명시적으로 선언한다
    ~Ex(){delete ptr;}
    // access content:
    const string& content() const {
        return *ptr;
    }
};

int main(){
    Ex foo;
    Ex bar("Example");

    cout << "bar's content: " << bar.content() << endl;
    return 0;
}