#include <iostream>
#include <string>

int main(void){
    std::string myStr;
    //std::cin >> myStr;
    getline(std::cin, myStr);
    std::cout << myStr;

    return 0;
}