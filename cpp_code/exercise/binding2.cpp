#include <iostream>
using namespace std;

class Bear{
    public:
    virtual void Meanness(void);
    void noVirtualMeanness(void);
};

void Bear::Meanness(void){
    cout << "Meanness of normal Bear" << endl;
}
void Bear::noVirtualMeanness(void){
    cout << "Meanness of normal Bear" << endl;
}


class Mommabear : public Bear {
    public:
    virtual void Meanness(void);
    void noVirtualMeanness(void);
};

void Mommabear::Meanness(void){
    cout << "Meanness of momma Bear" << endl;
}

void noVirtualMeanness(void){
    cout << "Meanness of momma Bear" << endl;
}

int main(void){
    Bear* bear = new Mommabear;
    bear->Meanness();
    bear->noVirtualMeanness();
    return 0;
}

