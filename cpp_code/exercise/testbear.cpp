#include "bear.h"
#include "mommabear.h"
#include <iostream>

using namespace std;

int main(void){
    Bear* cub;
    Mommabear* mom;
    cub = new Bear(50);
    mom = new Mommabear(300);

    cout << "Cub's meanness is : " << cub->Meanness() << endl;
    cout << "Mom's meanness is : " << mom->Meanness() << endl;

    mom->SetCub(cub);
    cub->SetWeight(75);

    cout << "Mom's meanness with a cub, which weights 75kg is : " << mom->TotalMeanness() << endl;
}