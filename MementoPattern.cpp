#include <iostream>
#include <unistd.h>

struct State {
    uint8_t No;
    std::string Name;
    bool On;
};

class Memento {
private:
    State m_state;
public:
    Memento(State state) : m_state(state) {}
    State getState() { return m_state; }
};

class Originator {
private:
    State m_state;
public:
    void setState(State val) { m_state = val; }
    State getState() { return m_state; }

    Memento* createMemento() { return (new Memento(m_state)); }
    void setMemento(Memento memento) { m_state = memento.getState(); }

    void show() { 
        printf("No: 0x%02x ", m_state.No);
        std::cout << "Name: " << m_state.Name << " " ;
        std::cout << "On: " << (m_state.On == true ? "true":"false") << std::endl;
    }
};

class Caretaker {
private:
    Memento m_memento;
public:
    Caretaker() : m_memento({0, "", 0}) {}
    Memento getMemento() { return m_memento; }
    void setMemento(Memento memento) { m_memento = memento; }
};

int main(int argc, char** argv) {
    Originator* originator = new Originator();

    struct State First = {0x01, "First", true};

    originator->setState(First);
    originator->show();

    Caretaker *caretaker = new Caretaker();
    caretaker->setMemento(*(originator->createMemento()));

    struct State Second = {0x10, "second", false};
    originator->setState(Second);
    originator->show();

    originator->setMemento(caretaker->getMemento());
    originator->show();

    delete originator;
    delete caretaker;

    return 0;
}