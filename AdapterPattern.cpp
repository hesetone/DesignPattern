#include <iostream>
#include <unistd.h>

class Target {
public:
    virtual void SayHi() = 0;
    virtual void SayHello() = 0;
};

class Adaptee {
public:
    void Hi() { std::cout << "Hi." << std::endl; }
    void Hello() { std::cout << "Hello." << std::endl; }
};

class Adapter :public Target {
private:
    Adaptee* adaptee = new Adaptee();
public:
    void SayHi() { adaptee->Hi(); }
    void SayHello() { adaptee->Hello(); }
};

int main(int argc, char** argv) {
    Target *target = new Adapter();

    target->SayHi();
    target->SayHello();
    
    delete target;
    return 0;
}