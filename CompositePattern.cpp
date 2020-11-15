#include <iostream>
#include <unistd.h>
#include <vector>

class Component {
public:
    virtual void Add(Component *component) = 0;
    virtual void Remove(Component *component) = 0;
    virtual void Display() = 0;
};

class Leaf : public Component {
private:
    std::string m_name;
public:
    Leaf(std::string name) : m_name(name) {}
    void Add(Component *component) { std::cout << "This is leaf, Don't support Add." << std::endl; }
    void Remove(Component *component) { std::cout << "This is leaf, Don't support Remove." << std::endl; }
    void Display() { std::cout << "This is Node, its name: " << m_name << std::endl; }
};

class Composite : public Component {
private:
    std::string m_name;
    std::vector<Component*> childlink;
public:
    Composite(std::string name) : m_name(name) { childlink.clear(); }
    void Add(Component *component) { childlink.push_back(component); }
    void Remove(Component *component) {
        for(auto idx = childlink.begin(); idx != childlink.end(); idx++) {
            if(*idx == component) {
                childlink.erase(idx);
                break;
            }
        }
    }
    void Display() {
        for(auto idx = childlink.begin(); idx != childlink.end(); idx++) { (*idx)->Display(); }
    }
};
int main(int argc, char** argv) {
    Composite* root = new Composite("root");
    root->Add(new Leaf("Leaf A"));
    root->Add(new Leaf("Leaf B"));

    Composite* composite_1 = new Composite("Composite_X");
    composite_1->Add(new Leaf("Leaf XA"));
    composite_1->Add(new Leaf("Leaf XB"));

    root->Add(composite_1);

    Composite* composite_2 = new Composite("Composite_Y");
    composite_2->Add(new Leaf("Leaf YA"));
    composite_2->Add(new Leaf("Leaf YB"));

    composite_1->Add(composite_2);

    root->Add(new Leaf("Leaf C"));

    Leaf* leaf = new Leaf("Leaf D");
    root->Add(leaf);

    //display before remove leaf "D"
    root->Display();
    std::cout << std::endl;

    //display again after remove leaf "D"
    root->Remove(leaf);

    root->Display();


    return 0;
}