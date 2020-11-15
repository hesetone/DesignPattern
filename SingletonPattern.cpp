#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <mutex>
#include <atomic>


//method 1
class LazySingleton {
private:
    static LazySingleton* LazySingletonInstance;
    LazySingleton() { }
public:
    static LazySingleton* getInstance() {
        if(NULL == LazySingletonInstance) LazySingletonInstance = new LazySingleton();
        return LazySingletonInstance;
    }
};

//method 2
class HungrySingleton {
private:
    HungrySingleton() { }
public:
    static HungrySingleton* getInstance() {
        static HungrySingleton HungrySingletonInstance;
        return &HungrySingletonInstance;
    }
};

// method 3, may cause error 'cannot access memory which has not been initialized'
class DoubleLockSingleton {
private:
    static DoubleLockSingleton* doubleLockSingleton;
    static pthread_mutex_t mtx;
    DoubleLockSingleton() {}
    ~DoubleLockSingleton() {}

    class MemoryFree {
    public:
        MemoryFree() {}
        ~MemoryFree() { 
            if(DoubleLockSingleton::doubleLockSingleton != nullptr) 
                delete DoubleLockSingleton::doubleLockSingleton;
        }
    };
    static MemoryFree* memoryfree;

public:
    static DoubleLockSingleton* getIntance() {
        if(nullptr == doubleLockSingleton) {
            pthread_mutex_lock(&mtx);
            if(nullptr == doubleLockSingleton) {
                doubleLockSingleton = new DoubleLockSingleton();
            }
            pthread_mutex_unlock(&mtx);
        }
        return doubleLockSingleton;
    }
};

// method 4, use atomic
class AtomicSingleton {
private:
    static std::atomic<AtomicSingleton*> atomicSingletonInstance;
    AtomicSingleton() {}
    ~AtomicSingleton() {}

    class MemoryFree{
    public:
        MemoryFree() {}
        ~MemoryFree() {
            AtomicSingleton* _ins = atomicSingletonInstance.load(std::memory_order_relaxed);
            if(_ins != nullptr) 
                delete _ins;
        }
    };

    static MemoryFree* memoryfree;
public:
    static AtomicSingleton* getInstance() {
        AtomicSingleton* _ins = atomicSingletonInstance.load(std::memory_order_relaxed);
        std::atomic_thread_fence(std::memory_order_acquire);

        if(_ins == nullptr) {
            static std::mutex mtx;
            std::lock_guard<std::mutex> lock(mtx);
            _ins = atomicSingletonInstance.load(std::memory_order_relaxed);
            if(_ins == nullptr) {
                _ins = new AtomicSingleton();
                std::atomic_thread_fence(std::memory_order_release);
                atomicSingletonInstance.store(_ins, std::memory_order_relaxed);
            }
        }
        return _ins;
    }
};

// method 5, use pthread_once
class Pthread_once_singleton {
private:
    static pthread_once_t _p_once;
    static Pthread_once_singleton* pthread_once_singleton;
    Pthread_once_singleton() {}
    ~Pthread_once_singleton() {}
    static void init() { pthread_once_singleton = new Pthread_once_singleton(); }

public:
    static Pthread_once_singleton* getInstance() {
        pthread_once(&_p_once, &Pthread_once_singleton::init);
        return pthread_once_singleton;
    }
};

// method 6, use call_once
class Call_once_singleton {
private:
    static Call_once_singleton* call_once_instance;
    Call_once_singleton() {}
    ~Call_once_singleton() {}

public:
    static Call_once_singleton* getInstance () {
        static std::once_flag oc;
        std::call_once(oc,[&]() { call_once_instance = new Call_once_singleton(); });
        return call_once_instance;
    }
};

LazySingleton* LazySingleton::LazySingletonInstance = nullptr;

DoubleLockSingleton* DoubleLockSingleton::doubleLockSingleton = nullptr;
pthread_mutex_t DoubleLockSingleton::mtx = PTHREAD_MUTEX_INITIALIZER;
DoubleLockSingleton::MemoryFree* DoubleLockSingleton::memoryfree;

std::atomic<AtomicSingleton*> AtomicSingleton::atomicSingletonInstance;
AtomicSingleton::MemoryFree* AtomicSingleton::memoryfree;

pthread_once_t Pthread_once_singleton::_p_once = PTHREAD_ONCE_INIT;
Pthread_once_singleton* Pthread_once_singleton::pthread_once_singleton = nullptr;

Call_once_singleton* Call_once_singleton::call_once_instance = nullptr;

int main(int argc, char** argv) {

    LazySingleton *s1 = LazySingleton::getInstance();
    LazySingleton *s2 = LazySingleton::getInstance();
    if(s1 == s2) {
        // check address of s1 and s2
        std::cout << "s1: " << s1 << "    " << "s2: " << s2 << std::endl;
    }

    HungrySingleton *s3 = HungrySingleton::getInstance();
    HungrySingleton *s4 = HungrySingleton::getInstance();
    if(s3 == s4) {
        // check address of s3 and s4
        std::cout << "s3: " << s3 << "    " << "s4: " << s4 << std::endl;
    }

    DoubleLockSingleton *s5 = DoubleLockSingleton::getIntance();
    DoubleLockSingleton *s6 = DoubleLockSingleton::getIntance();
    if(s5 == s6) {
        //check address of s5 and s6
        std::cout << "s5: " << s5 << "    " << "s6: " << s6 << std::endl;
    }

    AtomicSingleton *s7 = AtomicSingleton::getInstance();
    AtomicSingleton *s8 = AtomicSingleton::getInstance();
    if(s7 == s8) {
        //check address of s7 and s8
        std::cout << "s7: " << s7 << "    " << "s8: " << s8 << std::endl;
    }

    Pthread_once_singleton *s9 = Pthread_once_singleton::getInstance();
    Pthread_once_singleton *s10 = Pthread_once_singleton::getInstance();
    if(s9 == s10) {
        //check address of s9 and s10
        std::cout << "s9: " << s9 << "    " << "s10: " << s10 << std::endl;
    }

    Call_once_singleton* s11 = Call_once_singleton::getInstance();
    Call_once_singleton* s12 = Call_once_singleton::getInstance();
    if(s11 == s12) {
        //check address of s11 and s12
        std::cout << "s11: " << s11 << "    " << "s12: " << s12 << std::endl;
    }
    return 0;
}


// use command : g++ -o main SingletonPattern.cpp -pthread && ./main
// or pthread_once will throw a compile error.