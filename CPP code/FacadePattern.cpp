#include <iostream>
#include <unistd.h>

class Subsystem_A {
public:
    void Print_System_A() {
        std::cout << "Now, you are in subsystem A. " << std::endl;
    }
};

class Subsystem_B {
public:
    void Print_System_B() {
        std::cout << "Now, you are in subsystem B. " << std::endl;
    }
};

class Subsystem_C {
public:
    void Print_System_C() {
        std::cout << "Now, you are in subsystem C. " << std::endl;
    }
};

class Subsystem_D {
public:
    void Print_System_D() {
        std::cout << "Now, you are in subsystem D. " << std::endl;
    }
};

// more subsystems should be put here.

class Facede {
private:
    Subsystem_A* sa;
    Subsystem_B* sb;
    Subsystem_C* sc;
    Subsystem_D* sd;
public:
    Facede() {
        sa = new Subsystem_A();
        sb = new Subsystem_B();
        sc = new Subsystem_C();
        sd = new Subsystem_D();
    }
    ~Facede() {
        delete sa;
        delete sb;
        delete sc;
        delete sd;
    }

    void MethodGroup_1() {
        std::cout << "Method Group 1 has been called." << std::endl;
        sa->Print_System_A();
        sb->Print_System_B();
    }

    void MethodGroup_2() {
        std::cout << "Method Group 2 has been called." << std::endl;
        sc->Print_System_C();
        sd->Print_System_D();
    }

    //more method groups should be put here.
};
int main(int argc, char** argv) {
    Facede* facede = new Facede();
    facede->MethodGroup_1();
    facede->MethodGroup_2();

    delete facede;
    return 0;
}