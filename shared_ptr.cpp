//
// Created by User on 06.07.2019.
//

#include <cstdio>
template <typename T>
class shared_ptr {
public:
    class Aux {
    public:
        explicit Aux(T* ptr = nullptr);
        ~Aux();
    private:
        size_t counter;
        T* ptr;
    };
    shared_ptr(const shared_ptr&);
    shared_ptr(T* ptr);
    shared_ptr& operator=(const shared_ptr&);

    ~shared_ptr();

private:
    Aux *aux;
    void substr();
};

template<typename T>
shared_ptr<T>::shared_ptr(T *ptr) {
    this->aux = new Aux(ptr);
}

template<typename T>
shared_ptr<T>::shared_ptr(const shared_ptr &sp) {
    if (sp.aux == nullptr) {
        this->aux = nullptr;
    } else {
        this->aux = sp.aux;
        ++this->aux->counter;
    }
}

template<typename T>
shared_ptr<T>::~shared_ptr() {
    if (aux != nullptr) {
        this->substr();
    }
}

template<typename T>
void shared_ptr<T>::substr() {
    if (aux != nullptr) {
        --aux->counter;
        if (aux->counter == 0) {
            aux.~Aux();
        }
    }
}

template<typename T>
shared_ptr<T>& shared_ptr<T>::operator=(const shared_ptr &other) {
    if (aux == other.aux) {
        return *this;
    }
    if (this->aux != nullptr) {
        this->substr();
    }
    if (other.aux == nullptr) {
        aux = nullptr;
    } else {
        aux = other.aux;
        aux->counter++;
    }
    return *this;
}

template<typename T>
shared_ptr<T>::Aux::Aux(T *ptr) {
        this->ptr = ptr;
        counter = 1;
}

template<typename T>
shared_ptr<T>::Aux::~Aux() {
    operator delete [] (ptr);
}
