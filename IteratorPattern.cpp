#include <iostream>
#include <unistd.h>
#include <vector>

class Iterator {
public:
    virtual uint8_t First() = 0;
    virtual uint8_t Next() = 0;
    virtual bool IsDone() = 0;
    virtual uint8_t CurrentItem() = 0;
};

class Aggregate {
public:
    Aggregate() {}
    ~Aggregate() {}
    virtual int getCount() = 0;
    virtual Iterator* CreateIterator() = 0;
    virtual void insert(uint8_t object) = 0;
    virtual uint8_t& operator[](int idx) = 0;
    virtual uint8_t operator[](int idx) const = 0;
};

class ConcreteIterator : public Iterator {
private:
    Aggregate* m_aggregate;
    int current;
public:
    ConcreteIterator(Aggregate* aggregate) {
        current = 0;
        m_aggregate = aggregate;
    }
    ~ConcreteIterator() { delete m_aggregate; }
    uint8_t First() { return (*m_aggregate)[0]; }
    uint8_t Next() { 
        uint8_t ret = 0;
        current++; 
        if(current < m_aggregate->getCount()) ret = (*m_aggregate)[current];
        return ret;
    }
    bool IsDone() { return current >= m_aggregate->getCount(); }
    uint8_t CurrentItem() { return (*m_aggregate)[current]; }
};

class ConcreteAggregate : public Aggregate {
private:
    std::vector<uint8_t> items;
public:
    ConcreteAggregate() { for(int idx = 0; idx < 20; idx++) items.push_back(100); }
    int getCount() override { return items.size(); }
    Iterator* CreateIterator() override{ return (new ConcreteIterator(this)); };
    uint8_t operator[](int idx) const override { return items[idx]; }
    void insert(uint8_t val) override { items.push_back(val); } 
    uint8_t& operator[](int idx) override { 
        if(idx >= 0 && idx < items.size()) return items[idx];
        return items[0];
    }
};

int main(int argc, char** argv) {
    Aggregate *ag = new ConcreteAggregate();
    int idx = 0;
    while(idx < 10) {
        (*ag)[idx] = (idx << 1); // in replace method
        // ag->insert(idx << 1);    // in append method
        idx++;
    }
    Iterator *_it = new ConcreteIterator(ag);
    idx = 0;
    while(!_it->IsDone()) {
        std::cout << "No: " << idx++ << " has " << (int)(_it->CurrentItem()) << " coins." << std::endl;
        _it->Next();
    }

    delete _it;
    return 0;
}