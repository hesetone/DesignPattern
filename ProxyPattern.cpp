#include <iostream>
#include <unistd.h>

class Subject {
public:
    virtual void Request() = 0;
};
class RealSubject : public Subject {
public:
    void Request() {
        std::cout << "I am the RealSubject." << std::endl;
    }
};

class Proxy : public Subject {
private:
    Subject* realsubject;
public:
    void Request() {
        if(NULL == realsubject) 
            realsubject = new RealSubject();
        realsubject->Request();
    }
};

int main(int argc, char** argv) {

    Proxy *proxy = new Proxy();
    proxy->Request();
    
    return 0;
}