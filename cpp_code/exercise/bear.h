#pragma once /* A non-standard but widely supported preprocessor directive
                designed to cause the current source file to be included
                only once in a single compilation */

class Bear{
    protected:
    float weight;

    public:
    void SetWeight(float aWeight);
    float GetWeight(void);
    virtual float Meanness(void);

    float noVirtualMeanness(void);

    Bear(float aWeight);
};