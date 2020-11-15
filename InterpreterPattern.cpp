#include <iostream>
#include <unistd.h>
#include <vector>

class Context {
private:
    std::string _in, _out;
public:
    void set_in(std::string input) { _in = input; }
    std::string get_in() { return _in; }

    void set_out(std::string output) { _out = output; }
    std::string get_out() { return _out; }
};

class AbstractExpression {
public:
    virtual void Interpret(Context* context) = 0;
};

class TerminalExpression : public AbstractExpression {
public:
    void Interpret(Context* context) { std::cout << "this is class TerminalExpression." << std::endl; }
};

class NonterminalExpression : public AbstractExpression {
public:
    void Interpret(Context* context) { std::cout << "this is class NonterminalExpression." << std::endl; }
};
int main(int argc, char** argv) {
    Context* context = new Context();

    std::vector<AbstractExpression*> vae;

    vae.emplace_back(new TerminalExpression());
    vae.emplace_back(new TerminalExpression());
    vae.emplace_back(new NonterminalExpression());
    vae.emplace_back(new TerminalExpression());

    for(auto idx = vae.begin(); idx != vae.end(); idx++) (*idx)->Interpret(context);

    delete context;
    return 0;
}