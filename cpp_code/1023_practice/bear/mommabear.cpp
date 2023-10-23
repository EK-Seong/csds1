#include "mommabear.h"
#include <iostream>

using namespace std;

Mommabear::Mommabear(){}
Mommabear::Mommabear(float aWeight) : Bear(aWeight) {}
Mommabear::Mommabear(float aWeight, Bear* aCub) : Bear(aWeight){
    cub = aCub;
}

void Mommabear::SetCub(Bear* aCub){
    cub = aCub;
}

Bear* Mommabear::GetCub(void){
    return cub;
}

float Mommabear::Meanness(void){
    if(cub){
        return Bear::Meanness()*2;
    }
    else{
        return Bear::Meanness();
    }
}
float Mommabear::TotalMeanness(void){
    if(cub){
        return Meanness()+cub->Meanness();
    }
    else{
        return Meanness();
    }
}

void Mommabear::TestBears(void){
    /*
    Bear* cub;
    Mommabear* mom;
    cub = new Bear(50);
    mom = new Mommabear(300);

    cout << "The cub's meanness: " << cub->Meanness() << endl;
    cout << "The mom's meanness: " << mom->Meanness() << endl;

    mom->SetCub(cub);
    cub->SetWeight(75);

    cout << "The total meanness: " << mom->TotalMeanness() << endl;
    */

    /*
    Bear cub = Bear(50);
    Mommabear mom = Mommabear(300);
    cout << "The cub's meanness: " << cub.Meanness() << endl;
    cout << "The mom's meanness: " << mom.Meanness() << endl;

    mom.SetCub(&cub);
    cub.SetWeight(75);
    cout << "The total meanness: " << mom.TotalMeanness() << endl;
    */
    // 기본적으로 이렇게 stack을 활용하는 방식도 동작은 한다. 
    // 하지만 class substitution이 안된다는 단점이 있다.
    // 또한 TestBears()를 Mommabear class에만 정의하게 되면 Bear pointer에 대해서는 call할 수가 없다. 
}