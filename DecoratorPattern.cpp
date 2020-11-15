#include <iostream>
#include <unistd.h>
#include <string>

class Component {
public:
    Component(){}
    ~Component(){}
    virtual void showDescription() = 0;
};

class ConcreteComponent : public Component {
private:
    std::string m_name;
public:
    ConcreteComponent(std::string name){ m_name = name; }
    ~ConcreteComponent(){}
    void showDescription() { std::cout<< m_name << "'s decorator." << std::endl; }
};

class Decorator : public Component {
private:
    Component* m_component = NULL;
public:
    Decorator(Component *component) : m_component(component){}
    ~Decorator(){ delete m_component; }
    void showDescription() {
        if(nullptr != m_component) m_component->showDescription();
    }
};

class ConcreteDecoratorA : public Decorator {
private:
    void AddDecorate() { std::cout<< "Add Decoration A." << std::endl; }
public:
    ConcreteDecoratorA(Component* component) : Decorator(component) {}
    void showDescription() {
        Decorator::showDescription();
        AddDecorate();
    }
};

class ConcreteDecoratorB : public Decorator {
private:
    void AddDecorate() { std::cout << "Add Decoration B." << std::endl; }
public:
    ConcreteDecoratorB(Component* component) : Decorator(component) {}
    void showDescription() {
        Decorator::showDescription();
        AddDecorate();
    }
};

int main(int argc, char** argv) {
    Component* com = new ConcreteComponent("concrete_component1");
    
    ConcreteDecoratorA* dec1 = new ConcreteDecoratorA(com);
    ConcreteDecoratorB* dec2 = new ConcreteDecoratorB(dec1);
    dec2->showDescription();

    // delete com;
    // delete dec1;
    delete dec2;
    return 0;
}