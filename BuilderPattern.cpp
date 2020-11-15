#include <iostream>
#include <iomanip>
#include <vector>
#include <unistd.h>

struct PART{
    int No;
    std::string description;
    int cost;
};

class Product {
private:
    std::vector<PART> Parts;
public:
    Product() { Parts.clear(); }
    void AddParts(PART part) {
        Parts.emplace_back(part);
    }
    void ShowParts() {
        for (auto idx = Parts.begin(); idx != Parts.end(); idx++) {
            std::cout << "No: " << (*idx).No << " " 
                      << "Description: " << (*idx).description << " " 
                      << "Cost: " << (*idx).cost << std::endl;
        }
    }
};

class Builder {
public:
    virtual void buildContent1() = 0;
    virtual void buildContent2() = 0;
    virtual void buildContent3() = 0;
    virtual Product* getResult() = 0;
    //... more puts here.
};

class ConcreteBuilder :public Builder {
private:
    Product *product = new Product();
    PART pt;
public:
    void buildContent1() {
        pt = {001, "this is head.", 100};
        product->AddParts(pt);
    }
    void buildContent2() {
        pt = {002, "this is body.", 50};
        product->AddParts(pt);
    }
    void buildContent3() {
        pt = {003, "this is foot.", 10};
        product->AddParts(pt);
    }
    Product* getResult() {
        return product;
    }
};

class Director {
public:
    Director(Builder *builder) { m_builder = builder; }
    void CallMethodsOfBuilder() {
        m_builder->buildContent1();
        m_builder->buildContent2();
        m_builder->buildContent3();
    }
private:
    Builder* m_builder;
};
int main(int argc, char** argv) {
    ConcreteBuilder *cb = new ConcreteBuilder();
    Director* director = new Director(cb);

    director->CallMethodsOfBuilder(); // build 
    cb->getResult()->ShowParts();   // display

    delete cb;
    delete director;
    return 0;
}