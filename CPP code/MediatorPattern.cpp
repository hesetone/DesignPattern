#include <iostream>
#include <unistd.h>
#include <vector>
class Mediator;

class Person {
protected:
    Mediator* m_mediator;
public:
    virtual void SetMediator(Mediator* mediator) = 0;
    virtual void SendMessage(std::string msg) = 0;
    virtual void GetMessage(std::string msg) = 0;
};

class Mediator {
public:
    virtual void Send(std::string msg, Person* person) = 0;
    virtual void SetA(Person* person) = 0;
    virtual void SetB(Person* person) = 0;
};

class ConcreteMediator : public Mediator {
private:
    Person* _PA;
    Person* _PB;
public:
    ConcreteMediator() : _PA(nullptr), _PB(nullptr) {}
    void SetA(Person* person) { _PA = person; }
    void SetB(Person* person) { _PB = person; }
    void Send(std::string msg, Person* person) { 
        if(person == _PA) {
            std::cout << "[A] -> [B] :";
            _PB->GetMessage(msg);
        } else {
            std::cout << "[B] -> [A] :";
            _PA->GetMessage(msg);
        }
    }
};

class Person_A : public Person {
public:
    Person_A() {}
    ~Person_A() {}
    void SetMediator(Mediator* mediator) { m_mediator = mediator; }
    void SendMessage(std::string msg) { m_mediator->Send(msg, this); }
    void GetMessage(std::string msg) { std::cout << "A message get from mediator is : " << msg << std::endl; }
};

class Person_B : public Person {
public:
    Person_B() {}
    ~Person_B() {}
    void SetMediator(Mediator* mediator) { m_mediator = mediator; }
    void SendMessage(std::string msg) { m_mediator->Send(msg, this); }
    void GetMessage(std::string msg) { std::cout << "B message get from mediator is : " << msg << std::endl; }
};
int main(int argc, char** argv) {

    Mediator* mediator = new ConcreteMediator();

    Person* pa = new Person_A();
    Person* pb = new Person_B();

    mediator->SetA(pa);
    mediator->SetB(pb);

    pa->SetMediator(mediator);
    pb->SetMediator(mediator);

    pa->SendMessage("Hi, i am person A.");
    pb->SendMessage("Hi, This is Person B.");

    delete mediator;
    delete pa;
    delete pb;

    return 0;
}