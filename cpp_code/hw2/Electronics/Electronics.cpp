#include "Electronics.h"
#include <iostream>
#include <cmath>

// Fill in here

using namespace std;

// Electronics
Electronics::Electronics(){}
Electronics::Electronics(float aSize){
    size = aSize;
    SetPrice();
}

void Electronics::SetSize(float aSize){
    size = aSize;
    SetPrice();
}
float Electronics::GetSize(void){
    return size;
}
void Electronics::PrintSelf(void){
    SetPrice();
    cout << "It is a Electronics, Size=" << round(GetSize()) << ", Price=" << round(price) << endl; 
}

void Electronics::SetPrice(void){
    float w = 0.0;
    price = (w*size);
}

float Electronics::GetPrice(void){
    return price;
}



// TV

TV::TV(){}
TV::TV(float aSize){
    SetSize(aSize);
    SetPrice();
}

void TV::PrintSelf(void){
    SetPrice();
    cout << "It is a TV, Size=" << round(GetSize()) << ", Price=" << round(price) << endl; 
}

void TV::SetPrice(void){
    float w = 1.8;
    price = (w*GetSize());
}




// Computer

Computer::Computer(){}
Computer::Computer(float aSize){
    SetSize(aSize);
    SetPrice();
}

void Computer::PrintSelf(void){
    SetPrice();
    cout << "It is a Computer, Size=" << round(GetSize()) << ", Price=" << round(price) << endl; 
}
void Computer::AddGPU(Electronics* aGPU){}

void Computer::SetPrice(void){
    float w = 0.6;
    price = w*GetSize();
}


// Laptop

Laptop::Laptop() : Computer::Computer() {}
Laptop::Laptop(float aSize) : Computer::Computer(aSize){}

void Laptop::AddGPU(Electronics* aGPU){
    if(gpu1){
        gpu1 = aGPU;
        SetPrice();
    }
    else{
        gpu1 = aGPU;
    }
    if(numGPU==0){
        numGPU++;
    }
}

void Laptop::SetPrice(void) {
    float w = 0.6;
    if(gpu1){
        price = GetSize()*w*2;
    }
}

// Desktop

Desktop::Desktop() : Computer::Computer(){}
Desktop::Desktop(float aSize) : Computer::Computer(aSize){
    totalprice = price;
}

void Desktop::AddGPU(Electronics* aGPU){
    if(gpu1 == nullptr){
        gpu1 = aGPU;
        SetPrice();
        totalprice = price + gpu1->GetPrice();
    }
    else if(gpu2 == nullptr){
        gpu2 = aGPU;
        totalprice = price + gpu1->GetPrice() + gpu2->GetPrice();
    }
    else{
        Electronics* temp;
        temp = gpu2;
        gpu1 = gpu2;
        gpu2 = aGPU;
        totalprice = price + gpu1->GetPrice() + gpu2->GetPrice();
    }
    if(numGPU < 2){
        numGPU++;
    }
    
}

void Desktop::PrintSelf(void){
    SetPrice();
    cout << "It is a Desktop with " << numGPU << " GPU(s), Size=" << round(GetSize()) << ", Price=" << round(price) << ", Total Price=" << round(totalprice) << endl; 
}

void Desktop::SetPrice(void){
    float w = 0.6;
    if(gpu1){
        price = GetSize()*w*1.8;
    }
    // setting the total price
    if(gpu1 == nullptr){
        totalprice = price;
    }
    else if(gpu2 == nullptr){
        totalprice = price + gpu1->GetPrice();
    }
    else{
        totalprice = price + gpu1->GetPrice() + gpu2->GetPrice();
    }
}

// Cellphone

Cellphone::Cellphone(){}
Cellphone::Cellphone(float aSize){
    SetSize(aSize);
    SetPrice();
}

void Cellphone::PrintSelf(void){
    SetPrice();
    cout << "It is a Cellphone, Size=" << round(GetSize()) << ", Price=" << round(price) << endl; 
}

void Cellphone::SetPrice(void){
    float w = 0.7;
    price = w*GetSize();
}