#include <iostream>

namespace first{
    int x = 5;
    int y = 10;
}

namespace second{
    double x = 3.1416;
    double y = 2.7183;
}

/*
int main(){
    using first::x;
    using second::y;
    std::cout << x <<'\n';
    std::cout << y <<'\n';
    std::cout << first::y <<'\n';
    std::cout << second::x << '\n';
    return 0;
}
*/

/*
int main(){
    using namespace std;
    using namespace first;
    cout << x << '\n';
    cout << y << '\n';
    cout << second::x << '\n';
    cout << second::y << '\n';
    return 0;
}
*/

/*
int main(){
    using namespace std;
    {
        using namespace first;
        cout << x << '\n';
    }
    {
        using namespace second;
        cout << x << '\n';
    }
    return 0;
}
*/

/*
int main(){
    {
        using namespace std;
        {
            using namespace first;
            cout << x << endl;
            using namespace second;
            cout << x << endl;
            // "x" is ambiguousC/C++(266)
            //    double second::x
        }
    }
}
*/

int main(){
    return 0;
}