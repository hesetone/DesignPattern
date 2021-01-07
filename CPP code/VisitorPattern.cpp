#include <iostream>
#include <unistd.h>
#include <vector>

class Element;
class ConcreteElement_A;
class ConcreteElement_B;

class Visitor {
public:
    virtual void VisitConcreteElement_A(ConcreteElement_A* Element_A) = 0;
    virtual void VisitConcreteElement_B(ConcreteElement_B* Element_B) = 0;
};

class Element {
public:
    virtual void Accept(Visitor* visitor) = 0;
};

class ConcreteElement_A : public Element {
public:
    void Accept(Visitor* visitor) { visitor->VisitConcreteElement_A(this); }
    void operation_A() {}
};

class ConcreteElement_B : public Element {
public:
    void Accept(Visitor* visitor) { visitor->VisitConcreteElement_B(this); }
    void operation_B() {}
};

class ConcreteVisitor_A : public Visitor {
public:
    void VisitConcreteElement_A(ConcreteElement_A* Element_A) {
        std::cout << "visitor A visit concrete element a." << std::endl;
    }
    void VisitConcreteElement_B(ConcreteElement_B* Element_B) {
        std::cout << "visitor A visit concrete element b." << std::endl;
    }
};

class ConcreteVisitor_B : public Visitor {
public:
    void VisitConcreteElement_A(ConcreteElement_A* Element_A) {
        std::cout << "visitor B visit concrete element a." << std::endl;
    }
    void VisitConcreteElement_B(ConcreteElement_B* Element_B) {
        std::cout << "visitor B visit concrete element b." << std::endl;
    }
};

class ObjectStructure {
private:
    std::vector<Element*> ve;
public:
    void Attach(Element* element) { ve.emplace_back(element); }
    void Detach(Element* element) { 
        for(auto idx = ve.begin(); idx != ve.end(); idx++) {
            if((*idx) == element) ve.erase(idx);
        }
    }
    void Accept(Visitor* visitor) {
        for(auto idx = ve.begin(); idx != ve.end(); idx++) (*idx)->Accept(visitor);
    }
};

int main(int argc, char** argv) {
    ObjectStructure* os = new ObjectStructure();

    os->Attach(new ConcreteElement_A());
    os->Attach(new ConcreteElement_B());

    ConcreteVisitor_A* ca = new ConcreteVisitor_A();
    ConcreteVisitor_B* cb = new ConcreteVisitor_B();

    os->Accept(ca);
    os->Accept(cb);

    delete cb;
    delete ca;
    delete os;

    return 0;
}