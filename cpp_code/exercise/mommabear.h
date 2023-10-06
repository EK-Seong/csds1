#pragma once
#include "bear.h"

class Mommabear : public Bear{ //  Specifier
    protected:
    Bear* cub;

    public:
    Mommabear(float aWeight);
    void SetCub(Bear* aCub); // 주목
    Bear* GetCub(void);
    virtual float Meanness(void);
    
    float noVirtualMeanness(void);

    float TotalMeanness(void);
};