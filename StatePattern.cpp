#include <iostream>
#include <iomanip>
#include <unistd.h>
static int idx = 0;
class Context;

class State {
public:
    virtual void Handle(Context* context) = 0;
    virtual ~State() {}
};

class Context {
private:
    State* m_state;
public:
    Context(State* state) { m_state = state; }
    State* GetState() { return m_state; }
    void SetState(State* state) { m_state = state; }

    void Request() {
        m_state->Handle(this);
    }
};

class ConcreteStateA : public State {
public:
    void Handle(Context* context);
};
class ConcreteStateB : public State {
public:
    void Handle(Context* context);
};

void ConcreteStateA::Handle(Context* context) {
    idx++;
    std::cout << idx << ", this is ConcreteState A." << std::endl;   
    context->SetState(new ConcreteStateB());
}

void ConcreteStateB::Handle(Context* context) {
    idx++;
    std::cout << idx << ", this is ConcreteState B." << std::endl;
    context->SetState(new ConcreteStateA());
}

int main(int argc, char** argv) {
    Context *context =  new Context(new ConcreteStateA());

    context->Request();
    context->Request();
    context->Request();

    delete context;
    return 0;
}