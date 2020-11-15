#include <iostream>
#include <unistd.h>
#include <vector>
struct Request {
    bool req_1 = false;
    bool req_2 = false;
    bool req_3 = false;
};

class Handler {
public:
    virtual void SetSuccessor(Handler* handler) = 0;
    virtual void HandleRequest(Request* req) = 0;
};

class Handler_A : public Handler {
private:
    Handler* m_successor;
public:
    void SetSuccessor(Handler* handler) { this->m_successor = handler; }
    void HandleRequest(Request* req) { 
        if(req->req_1) {
            std::cout << "req_1 handled." << std::endl; 
            req->req_1 = false;
        }
        m_successor->HandleRequest(req);
    }
};

class Handler_B : public Handler {
private:
    Handler* m_successor;
public:
    void SetSuccessor(Handler* handler) { this->m_successor = handler; }
    void HandleRequest(Request* req) { 
        if(req->req_2) {
            std::cout << "req_2 handled." << std::endl; 
            req->req_2 = false;
        }
        m_successor->HandleRequest(req);
    }
};

class Handler_C : public Handler {
private:
    Handler* m_successor;
public:
    void SetSuccessor(Handler* handler) { this->m_successor = handler; }
    void HandleRequest(Request* req) { 
        if(req->req_3) {
            std::cout << "req_3 handled." << std::endl; 
            req->req_3 = false;
        }
        //the highest one, no need to notify next one.
    }
};

int main(int argc, char** argv) {
    Handler* h1 = new Handler_A();
    Handler* h2 = new Handler_B();
    Handler* h3 = new Handler_C();

    h1->SetSuccessor(h2);
    h2->SetSuccessor(h3);

    Request m_req = {true, true, true};
    h1->HandleRequest(&m_req);

    delete h1;
    delete h2;
    delete h3;
    return 0;
}