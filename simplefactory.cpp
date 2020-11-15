#include <iostream>

typedef enum {
	TYPE_A,
    TYPE_B,
    TYPE_C
}S_Type;

class simplefac {
public:
    virtual void Print(std::string str) = 0;
};
class SA: public simplefac {
public:
    void Print(std::string str) {
        std::cout<<"SA: "<<str<<std::endl;
    }
};
class SB: public simplefac {
public:
    void Print(std::string str) {
        std::cout<<"SB: "<<str<<std::endl;
    }
};
class SC:public simplefac {
public:
    void Print(std::string str) {
        std::cout << "SC: " << str << std::endl;
    }
};

class Factory {
public:
    simplefac* chooseSandPrint(S_Type Type) {
        switch (Type)
        {
        case TYPE_A: return new SA(); break;
        case TYPE_B: return new SB(); break;
        case TYPE_C: return new SC(); break;
        default: return NULL; break;
        }
    }
};

int main (int argc,char**argv) {

    Factory *result = new Factory();
    simplefac * sim = result->chooseSandPrint(TYPE_A);
    sim->Print("this is me");

    //...

    delete result;
    return 0;
}
