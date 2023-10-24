#include <iostream>
#include <string>

using namespace std;
class ex{
    public:
    string* ptr;

    public:
    ex(const string& str) : ptr(new string(str)){}
    ~ex(){delete ptr;}

    //copy constructor:
    ex(const ex& x) : ptr(new string(x.content())){}

    //move constructor:
    //ex(ex&& x) : ptr(x.ptr) {x.ptr = nullptr;}

    //access content:
    const string& content() const {
        return* ptr;
    }

    /*//copy assignment(deep)
    ex& operator= (const ex& x){
        delete ptr;
        ptr = new string(x.content());
        return *this;
    }*/
    
    
    //copy assignment(another variant)
    ex& operator=(const ex& x){
        *ptr = x.content();
        return *this;
    }
    
    /*//move assignment
    ex&operator=(ex&& x){
        delete ptr;
        ptr = x.ptr;
        x.ptr = nullptr;
        return *this;
    }*/

    //addition
    ex operator+(const ex& rhs){
        return ex(content()+rhs.content());
    }

};

int main(void){
    ex foo ("Example");

    //ex bar = foo;
    //ex bar("bar");
    ex bar = foo; //copy constructor
    ex baz("Another one");
    foo = baz; //copy assignment
    cout << "bar's content: " << bar.content() << endl;
    cout << "bar's address is " << &bar << endl;
    cout << "bar is pointing at " << bar.ptr << endl;
    cout << "foo is pointing at " << foo.ptr << endl;

    cout << "baz is pointing at " << baz.ptr << endl;


    ex foo1 ("Exam");
    ex bar1 = ex("ple");
    foo1 = foo1+bar1;
    cout << "foo1's content: " << foo1.content() << endl;
    return 0;
}