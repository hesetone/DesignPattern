#include <iostream>
#include <unistd.h>
#include <string.h>

class ProtoType {
private:
    std::string id;
    char* m_name;
public:
    ProtoType(std::string I, char* name) {
        id = I;
        int len = strlen(name);
        m_name = new char[len + 1]; //malloc the space.
        std::cout << &m_name << std::endl;

        strcpy(m_name, name); // copy char one by one.
        m_name[len] = '\0'; //write '\0' for an end.
    }
    std::string getId() { return id; }
    char* getName() { return m_name; }
    
    virtual ~ProtoType(){
        delete [] m_name;
    }
    virtual ProtoType* clone() = 0;
};

class ConcreteProtoTypeA : public ProtoType {
public:
    ConcreteProtoTypeA(std::string id, char* name) : ProtoType(id, name) {}
    ConcreteProtoTypeA(ConcreteProtoTypeA &cp) : ProtoType(cp.getId(), cp.getName()) {}
    ProtoType* clone() { return new ConcreteProtoTypeA(*this); }
};

class ConcreteProtoTypeB : public ProtoType {
public:
    ConcreteProtoTypeB(std::string id, char* name) : ProtoType(id, name) {}
    ConcreteProtoTypeB(ConcreteProtoTypeB &cp) : ProtoType(cp.getId(), cp.getName()) {}
    ProtoType* clone() { return new ConcreteProtoTypeB(*this); }
};

int main(int argc, char** argv) {
    
    char* name = (char*)"Hello";

    ProtoType* pt1 = new ConcreteProtoTypeA("A", name);
    ProtoType* pt2 = pt1->clone();

    std::cout << pt2->getId() << std::endl;
    std::cout << pt2->getName() << std::endl;

    delete pt1;
    delete pt2;

    return 0;
}