#include <iostream>

class AbstractClass {
public:
    virtual void SayHi() = 0;
    virtual void SayHello() = 0;

    void Say() {
        SayHi();
        SayHello();
    }
};

class ConcreteClassA : public AbstractClass {
public:
    void SayHi() { std::cout << "Hi, I am ConcreteClassA. " << std::endl; }
    void SayHello() { std::cout << "Hello, I am ConcreteClassA. " << std::endl; }
};

class ConcreteClassB : public AbstractClass {
public:
    void SayHi() { std::cout << "Hi, I am ConcreteClassB. " << std::endl; }
    void SayHello() { std::cout << "Hello, I am ConcreteClassB. " << std::endl;}
};

int main(int argc, char** argv) {
    AbstractClass* ac1 = new ConcreteClassA();
    AbstractClass* ac2 = new ConcreteClassB();

    ac1->Say();
    ac2->Say();

    return 0;
}