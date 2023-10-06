#include "bear.h"
#include "mommabear.h"
#include <iostream>

using namespace std;

int main(void){
    Bear* bear = new Mommabear(300);
    bear->Meanness();
    bear->noVirtualMeanness();
    return 0;
}