#pragma once
#include "bear.h"

class Mommabear : public Bear {
    protected:
    Bear* cub = nullptr;

    public:
    Mommabear();
    Mommabear(float aWeight);
    Mommabear(float aWeight, Bear* aCub);

    void SetCub(Bear* aCub);
    Bear* GetCub(void);
    float Meanness(void);
    float TotalMeanness(void);

    void TestBears(void);
};