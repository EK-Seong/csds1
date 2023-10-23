#pragma once

class Bear{
    protected:
    float weight;

    public:
    Bear();
    Bear(float aWeight);
    
    void SetWeight(float aWeight);
    float GetWeight(void);
    virtual float Meanness(void);
};