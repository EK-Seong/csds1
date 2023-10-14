#pragma once

// Fill in here
class Electronics{
    private:
    int size;

    protected:
    double w;
    int price;

    public:
    Electronics();

    void SetSize(int aSize);
    int GetSize(void);
    virtual void PrintSelf(void);

    virtual void SetPrice(void);
    int GetPrice(void);
};

class TV : public Electronics {
    public:
    TV();
    TV(int aSize);

    void PrintSelf(void);
};

class Computer : public Electronics{
    protected:
    int numGPU = 0;

    public:
    Computer();
    Computer(int aSize);

    virtual void SetPrice(void);

    virtual void PrintSelf(void);
};

class Cellphone : public Electronics{
    public:
    Cellphone();
    Cellphone(int aSize);

    void PrintSelf(void);
};

class Laptop : public Computer{
    private:
    Electronics* GPU1 = nullptr;

    public:
    Laptop();
    Laptop(int aSize);

    void AddGPU(Electronics* aGPU);

    void SetPrice(void);
};

class Desktop : public Computer{
    private:
    int totalprice;
    Electronics* GPU1 = nullptr;
    Electronics* GPU2 = nullptr;

    public:
    Desktop();
    Desktop(int aSize);

    void AddGPU(Electronics* aGPU);

    virtual void PrintSelf(void);

    void SetPrice(void);
};