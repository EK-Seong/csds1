#include <iostream>

/*
namespace foo{
    int value(){
        return 5;
    }
}
*/

namespace foo{
    int value = 5;
}

/*
namespace bar{
    const double pi = 3.1416;
    double value(){
        return 2*pi;
    }
}
*/

namespace bar{
    const double pi = 3.1416;
    double value = 2*pi;
}


int main(){
    std::cout << foo::value << '\n' ;
    std::cout << bar::value << '\n';
    std::cout << bar::pi << '\n';
    return 0;
}