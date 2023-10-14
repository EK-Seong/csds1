#include "Electronics.h"
#include <iostream>

// Fill in here

using namespace std;

Electronics::Electronics(){};

void Electronics::SetSize(int aSize){
    size = aSize;
}

int Electronics::GetSize(void){
    return size;
}
void Electronics::PrintSelf(void){
    cout << "It is a Electronics, Size=" << GetSize() << ", Price=" << GetPrice() << endl; 
}

void Electronics::SetPrice(void){
    price = (w*size);
}

int Electronics::GetPrice(void){
    return price;
}


TV::TV(){
    w = 1.8;
}

TV::TV(int aSize){
    w = 1.8;
    SetSize(aSize);
    SetPrice();
}

void TV::PrintSelf(void){
    cout << "It is a TV, Size=" << GetSize() << ", Price=" << GetPrice() << endl; 
}

Computer::Computer(){
    w = 0.6;
}

Computer::Computer(int aSize){
    w = 0.6;
    SetSize(aSize);
    SetPrice();
}

void Computer::SetPrice(void){
    Electronics::SetPrice();
}

void Computer::PrintSelf(void){
    cout << "It is a Computer, Size=" << GetSize() << ", Price=" << GetPrice() << endl; 
}

Laptop::Laptop() : Computer::Computer() {}
Laptop::Laptop(int aSize) : Computer::Computer(aSize){
    SetPrice();
}

void Laptop::AddGPU(Electronics* aGPU){
    if(GPU1){
        GPU1 = aGPU;
    }
    else{
        GPU1 = aGPU;
        SetPrice();
    }
    if(numGPU==0){
        numGPU++;
    }
}

void Laptop::SetPrice(void) {
    if(GPU1){
        price = GetSize()*w*2;
    }
    else{
        price = GetSize()*w;
    }
}

Desktop::Desktop() : Computer::Computer(){}
Desktop::Desktop(int aSize) : Computer::Computer(aSize){
    SetPrice();
    totalprice = price;
}

void Desktop::AddGPU(Electronics* aGPU){
    if(GPU1 == nullptr){
        GPU1 = aGPU;
        SetPrice();
        totalprice = price + GPU1->GetPrice();
    }
    else if(GPU2 == nullptr){
        GPU2 = aGPU;
        SetPrice();
        totalprice = price + GPU1->GetPrice() + GPU2->GetPrice();
    }
    else{
        Electronics* temp;
        temp = GPU2;
        GPU1 = GPU2;
        GPU2 = aGPU;
        totalprice = price + GPU1->GetPrice() + GPU2->GetPrice();
    }
    if(numGPU < 2){
        numGPU++;
    }
    
}

void Desktop::PrintSelf(void){
    cout << "It is a Desktop with " << numGPU << " GPU(s), Size=" << GetSize() << ", Price=" << GetPrice() << ", Total Price=" << totalprice << endl; 
}

void Desktop::SetPrice(void){
    if(GPU1){
        price = GetSize()*w*1.8;
    }
    else{
        price = GetSize()*w;
    }
}

Cellphone::Cellphone(){
    w = 0.7;
    SetPrice();
}
Cellphone::Cellphone(int aSize){
    w = 0.7;
    SetSize(aSize);
    SetPrice();
}

void Cellphone::PrintSelf(void){
    cout << "It is a Cellphone, Size=" << GetSize() << ", Price=" << GetPrice() << endl; 
}