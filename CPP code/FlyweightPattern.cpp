#include <iostream>
#include <vector>
#include <utility>

class Flyweight {
public:
    virtual void Operation(int extrinsicstate) = 0;
};

class ConcreteFlyweight : public Flyweight {
public:
    void Operation(int extrinsicstate) {
        std::cout << "this is class ConcreteFlyweight. extrinsicstate: " << extrinsicstate << std::endl;
    }
};

class UnsharedConcreteFlyweight : public Flyweight {
public:
    void Operation(int extrinsicstate) {
        std::cout << "this is class UnsharedConcreteFlyweight. extrinsicstate: " << extrinsicstate << std::endl;
    }
};

class FlyweightFactory {
private:
    std::vector<std::pair<std::string, Flyweight*>> psf;
public:
    FlyweightFactory() {
        psf.emplace_back("X", new ConcreteFlyweight());
        psf.emplace_back("Y", new ConcreteFlyweight());
        psf.emplace_back("Z", new ConcreteFlyweight());
    }
    Flyweight* getFlyweight(std::string key) {
        for(auto idx = psf.begin(); idx != psf.end(); idx++) {
            if((*idx).first == key) 
                return (*idx).second;
        }
        std::cout << "object not found, create a new one, ";
        std::pair<std::string, Flyweight*> tmp = std::make_pair(key, new ConcreteFlyweight());
        psf.emplace_back(tmp);
        return tmp.second;
    }
};

int main(int argc, char** argv) {
    int extrinsicstate = 22;
    FlyweightFactory* fly = new FlyweightFactory();

    Flyweight* fx = fly->getFlyweight("X");
    fx->Operation(--extrinsicstate);

    Flyweight* fy = fly->getFlyweight("Y");
    fy->Operation(--extrinsicstate);

    Flyweight* fw = fly->getFlyweight("W");
    fw->Operation(--extrinsicstate);

    Flyweight* fz = fly->getFlyweight("Z");
    fy->Operation(--extrinsicstate);

    Flyweight* fu = new UnsharedConcreteFlyweight();
    fu->Operation(--extrinsicstate);

    delete fu;
    delete fz;
    delete fy;
    delete fx;
    delete fly;

    return 0;
}