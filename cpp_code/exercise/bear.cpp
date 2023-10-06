#include "bear.h"
#include <iostream>
using namespace std;

Bear::Bear(float aWeight){
    weight = aWeight; // we access Bear::weight via this pointer
}

float Bear::GetWeight(void){
    return weight;
}

void Bear::SetWeight(float aWeight){
    weight = aWeight;
}

float Bear::Meanness(void){
    cout << "meanness of a normal Bear!" << endl;
    if(weight <= 100){
        return (weight*2);
    }
    else{
        return (weight*3);
    }
}

float Bear::noVirtualMeanness(void){
    cout << "no virtual meanness of a normal Bear!" << endl;
        if(weight <= 100){
        return (weight*2);
    }
    else{
        return (weight*3);
    }
}