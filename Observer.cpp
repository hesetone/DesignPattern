//
// Created by hesetone on 11/6/20.
//

#include <iostream>
#include <vector>
#include <unistd.h>

class BaseSubscriber {
public:
    virtual void Update(int value) = 0;
};

class BasePublisher {
private:
    int m_count;
    std::string m_name;
public:
    virtual void Attach(BaseSubscriber *subs) = 0;
    virtual void Detach(BaseSubscriber *subs) = 0;
    virtual void Notify(int m_val) = 0;

    std::string getName() {
        return m_name;
    }

    void print_count() {
        std::cout << this->getName() << " still has " << this->m_count << std::endl;
    }
};

class Publisher : public BasePublisher {
private:
    std::vector<BaseSubscriber *> subscribers;
public:
    Publisher() {
        subscribers.clear();
    }

    void Attach(BaseSubscriber *subs) {
        subscribers.push_back(subs);
    }

    void Detach(BaseSubscriber *subs) {
        for (auto VS = subscribers.begin(); VS != subscribers.end(); VS++) {
            if (*VS == subs) {
                subscribers.erase(VS);
                return;
            }
        }
    }

    void Notify(int m_val) {
        for (auto VS = subscribers.begin(); VS != subscribers.end(); VS++) {
            (*VS)->Update(m_val);
        }
    }
};

class Subscriber : public BaseSubscriber {
private:
    int m_count;
    std::string m_name;
public:
    Subscriber(int _count, std::string _name) {
        m_count = _count;
        m_name = _name;
    }

    void print_count() {
        std::cout << this->m_name << " still has " << this->m_count << std::endl;
    }

    void Update(int value) {
        if (value & 1)
            this->m_count--;
        else 
            this->m_count++;
        print_count();
    }
};

int main(int argc, char **argv) {

    //publisher 
    Publisher *pub = new Publisher();

    //three subscribers
    Subscriber *sub1 = new Subscriber(50, "A");
    Subscriber *sub2 = new Subscriber(50, "B");
    Subscriber *sub3 = new Subscriber(50, "C");

    pub->Attach(sub1);
    pub->Attach(sub2);
    pub->Attach(sub3);

    while (true) {
        int val = rand() % 6 + 1; // random1 ~ 6
        std::cout<<"value " << val << " will be published." << std::endl;
        pub->Notify(val);
        sleep(1);
    }
    return 0;
}