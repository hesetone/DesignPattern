#include <iostream>
class BaseProduct {
public:
    virtual void PrintProductName() = 0;
};

class ProductA :public BaseProduct {
public:
    void PrintProductName() {
        std::cout << "This is Product A." << std::endl;
    }
};
class ProductB : public BaseProduct {
public:
    void PrintProductName() {
        std::cout << "This is Product B." << std::endl;
    }
};
class ProductC : public BaseProduct {
public:
    void PrintProductName() {
        std::cout << "This is Product C." << std::endl;
    }
};

class Factory {
public :
    virtual BaseProduct* getProduct() = 0;
};

class ProductA_Factory : public Factory {
public:
    BaseProduct* getProduct() {
        return new ProductA();
    }
};

class ProductB_Factory : public Factory {
public:
    BaseProduct* getProduct() {
        return new ProductB();
    }
};
class ProductC_Factory : public Factory {
public:
    BaseProduct* getProduct() {
        return new ProductC();
    }
};

int main(int argc,char** argv) {

    Factory* a_factory = new ProductA_Factory();
    Factory* b_facroty = new ProductB_Factory();
    Factory* c_factory = new ProductC_Factory();
    //... derived new child class from 'Factory' if necessary.

    a_factory->getProduct()->PrintProductName();
    b_facroty->getProduct()->PrintProductName();
    c_factory->getProduct()->PrintProductName();

    delete a_factory;
    delete b_facroty;
    delete c_factory;

    return 0;
}