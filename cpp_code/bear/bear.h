#pragma once

class Bear{
    public:
    Bear(float aWeight);

    void SetWeight(float aWeight);
    float GetWeight(void);

    virtual float Meanness(void);

    protected:
    float weight;
};