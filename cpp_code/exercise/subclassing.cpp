class Base{
    public:
    int x;
    protected:
    int y;
    private:
    int z;
};

class Pub : public Base{
    public:
    Pub(){
        Base::x = 1;
        Base::y = 2;
        //z = 3;
    }
};

int main(void){
    Base base;
    base.x = 1;
    //base.y = 2;
    //base.z = 3;

    Pub pub;
    pub.x = 1;
    //pub.y = 2;
    //pub.z = 3;
    return 0;
}