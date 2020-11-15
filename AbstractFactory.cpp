#include <iostream>
class BaseProduct_A {
public:
    virtual void SayHi() = 0;
};

class DerivedProduct_A1 : public BaseProduct_A {
public: 
    void SayHi() {
        std::cout<<"This is Derived Product A1."<<std::endl;
    }
};

class DerivedProduct_A2 : public BaseProduct_A {
public:
    void SayHi() {
        std::cout<<"This is Derived Product A2."<<std::endl;
    }
};

class BaseProduct_B {
public:
    virtual void SayHello() = 0;
};

class DerivedProduct_B1 : public BaseProduct_B {
public:
    void SayHello() {
        std::cout<<"This is Derived Product B1."<<std::endl;
    }
};

class DerivedProduct_B2 : public BaseProduct_B {
public:
    void SayHello() {
        std::cout<<"This is Derived Product B2."<<std::endl;
    }
};

class Factory {
public:
    virtual BaseProduct_A* CreateProduct_A() = 0;
    virtual BaseProduct_B* CreateProduct_B() = 0; 
};

class Factory_1 : public Factory {
public:
    DerivedProduct_A1* CreateProduct_A() {
        return new DerivedProduct_A1();
    }

    DerivedProduct_B1* CreateProduct_B() {
        return new DerivedProduct_B1();
    }
};

class Factory_2 : public Factory {
public:
    DerivedProduct_A2* CreateProduct_A() {
        return new DerivedProduct_A2();
    }
    DerivedProduct_B2* CreateProduct_B() {
        return new DerivedProduct_B2();
    }
};

int main(int argc, char** argv) {

    Factory * factory_1 = new Factory_1();
    Factory * factory_2 = new Factory_2();

    factory_1->CreateProduct_A()->SayHi();
    factory_1->CreateProduct_B()->SayHello();

    factory_2->CreateProduct_A()->SayHi();
    factory_2->CreateProduct_B()->SayHello();

    delete factory_1;
    delete factory_2;
    return 0;
}