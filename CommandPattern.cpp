#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>


class Reciver {
public:
    virtual void action() = 0;
};

class RiceReciver : public Reciver {
public:
    void action() { std::cout << "Rice will be OK later! " << std::endl; }
};

class NoodleReciver : public Reciver {
public:
    void action() { std::cout << "Noodle will be OK later! " << std::endl; }
};
// more Recivers should be put here.

class Command {
public:
    virtual void Excute() = 0;
};

class ConcreteCommand : public Command {
private:
    Reciver* m_reciver;
public:
    ConcreteCommand(Reciver *reciver) :m_reciver(reciver) {}
    void Excute() {
        m_reciver->action();
    }
};

class Invoker {
private:
    std::vector<Command*> m_command;
public:
    Invoker() { m_command.clear(); }
    void SetRecord(Command* command) { m_command.emplace_back(command); }
    void Notify() { 
        for(auto idx = m_command.begin(); idx != m_command.end(); idx++) (*idx)->Excute();
    }
};

int main(int argc, char** argv) {
    Invoker *invoker = new Invoker();
    
    // add rice requirements
    Reciver *reciver = new RiceReciver();
    Command *command = new ConcreteCommand(reciver);
    invoker->SetRecord(command);

    // add noodle requirements
    reciver = new NoodleReciver();
    command = new ConcreteCommand(reciver);
    invoker->SetRecord(command);

    // add rice requirements again
    reciver = new RiceReciver();
    command = new ConcreteCommand(reciver);
    invoker->SetRecord(command);

    // more commands should be put here.

    // notify to all at one time, and begin execute.
    invoker->Notify();

    delete invoker;
    delete command;
    delete reciver;
    return 0;
}