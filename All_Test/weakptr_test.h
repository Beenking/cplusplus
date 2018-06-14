#pragma once
#include <memory>
#include <iostream>

class A;
class B;

class A {
public:
    A() { std::cout << "A Constructor" << std::endl; }
    ~A(){ std::cout << "A Destructor" << std::endl; }

    std::weak_ptr<B> m_spB;
    //std::shared_ptr<B> m_spB;
};

class B {
public:
    B() { std::cout << "B Constructor" << std::endl; }
    ~B() { std::cout << "B Destructor" << std::endl; }

    std::shared_ptr<A> m_spA;
};