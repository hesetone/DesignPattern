#include <iostream>
#include <unistd.h>

class Implementor {
public:
    virtual void Operation()  = 0;
};

class ConcreteImpletor_A : public Implementor {
public:
    void Operation() { std::cout << "This is class ConcreteImpletor_A." << std::endl; }
};

class ConcreteImpletor_B : public Implementor {
public:
    void Operation() { std::cout << "This is class ConcreteImpletor_B." << std::endl; }
};

class Abstraction {
protected:
    Implementor* m_implementor;
public:
    void SetImplementor(Implementor *implementor) { m_implementor = implementor; }
    virtual void Operation() = 0;
};

class ConcreteAbstraction : public Abstraction{
public:
    void Operation() { m_implementor->Operation(); }
};

int main(int argc, char** argv) {
    Abstraction* ca = new ConcreteAbstraction();
    
    ca->SetImplementor(new ConcreteImpletor_A());
    ca->Operation();

    ca->SetImplementor(new ConcreteImpletor_B());
    ca->Operation();

    delete ca;
    return 0;
}
