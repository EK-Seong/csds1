#pragma once

// Fill in here
class Electronics{
    private:
    float size;

    protected:
    float price;

    public:
    Electronics();
    Electronics(float aSize);

    void SetSize(float aSize);
    float GetSize(void);
    virtual void PrintSelf(void);

    virtual void SetPrice(void);
    float GetPrice(void);
};

class TV : public Electronics {
    public:
    TV();
    TV(float aSize);

    void PrintSelf(void);

    void SetPrice(void);
};

class Computer : public Electronics{
    protected:
    int numGPU = 0;

    public:
    Computer();
    Computer(float aSize);

    virtual void PrintSelf(void);

    virtual void SetPrice(void);
    virtual void AddGPU(Electronics* aGPU);
};

class Cellphone : public Electronics{
    public:
    Cellphone();
    Cellphone(float aSize);

    void PrintSelf(void);

    void SetPrice(void);
};

class Laptop : public Computer{
    private:
    Electronics* gpu1 = nullptr;

    public:
    Laptop();
    Laptop(float aSize);

    void AddGPU(Electronics* aGPU);

    // PrintSelf는 그대로 가져다 쓴다 Inherit
    void SetPrice(void);
};

class Desktop : public Computer{
    private:
    float totalprice;
    Electronics* gpu1 = nullptr;
    Electronics* gpu2 = nullptr;

    public:
    Desktop();
    Desktop(float aSize);

    void AddGPU(Electronics* aGPU);

    void PrintSelf(void);

    void SetPrice(void);
};