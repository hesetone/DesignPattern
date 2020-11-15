#include <iostream>
#include <unistd.h>

class Strategy {
public:
    virtual void AlgorithmInterface() = 0;
};

class StrategyA : public Strategy{
public:
    void AlgorithmInterface() {
        std::cout << "Use Strategy A." << std::endl;
    }
};

class StrategyB : public Strategy{
public:
    void AlgorithmInterface() {
        std::cout << "Use Strategy B." << std::endl;
    }
};

class StrategyC : public Strategy{
public:
    void AlgorithmInterface() {
        std::cout << "Use Strategy C." << std::endl;
    }
};

class Context {
private:
    Strategy* m_strategy = NULL;
public:
    Context(Strategy* strategy) : m_strategy(strategy) {}
    void ContextInterface() { m_strategy->AlgorithmInterface(); }
};


int main(int argc, char ** argv) {
    Context *context;
    
    //Use Strategy A.
    context = new Context(new StrategyA());
    context->ContextInterface();

    //Use Strategy B.
    context = new Context(new StrategyB());
    context->ContextInterface();

    //Use Strategy C.
    context = new Context(new StrategyC());
    context->ContextInterface();
    return 0;
}