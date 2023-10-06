#include "mommabear.h"
#include <iostream>
using namespace std;


Mommabear::Mommabear(float aWeight) : Bear(aWeight) {
    cub = nullptr;
}

Bear* Mommabear::GetCub(void){
    return cub;
}

void Mommabear::SetCub(Bear* aCub){
    cub = aCub;
}

float Mommabear::Meanness(void){
    cout << "meanness of a momma Bear!" << endl;
    return (Bear::Meanness()*2);
}


float Mommabear::noVirtualMeanness(void){
    cout << "no virtual meanness of a momma Bear!" << endl;
    return (Bear::noVirtualMeanness()*2);
}


float Mommabear::TotalMeanness(void){
    if (cub != nullptr){
        return(Mommabear::Meanness()+cub->Meanness());
    }
    else{
        return(Mommabear::Meanness());
    }
}