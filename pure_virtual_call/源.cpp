#include <iostream>

class Base
{
public:
    Base()
    {
        std::cout << "Base Construcotr Called" << std::endl;
    }

    ~Base()
    {
        clear();
        std::cout << "Base Destructor Called" << std::endl;
    }

    virtual void clear() 
    {
        ThePureCall();
    };

    virtual void ThePureCall() = 0;
};


class Derived : public Base
{
public:
    Derived()
    {
        std::cout << "Derived Construcotr Called" << std::endl;
    }

    ~Derived()
    {
        std::cout << "Derived Destructor Called" << std::endl;
    }

    virtual void ThePureCall() override
    {
        std::cout << "Derived ThePureCall " << std::endl;
    }
};

int main()
{
    int i = 0;
    int j = 1;
    std::cout << "Test DebugBreak" << std::endl;

    //__debugbreak();
    Derived *pd = new Derived();
    delete pd;
    system("pause");

    return 0;
}


///* Compile options needed: none
//*/
//
//class A;
//
//void fcn(A*);
//
//class A
//{
//public:
//    virtual void f() = 0;
//    A() { fcn(this); }
//};
//
//class B : A
//{
//    void f() { }
//};
//
//void fcn(A* p)
//{
//    p->f();
//}
//
//// The declaration below invokes class B's constructor, which
//// first calls class A's constructor, which calls fcn. Then
//// fcn calls A::f, which is a pure virtual function, and
//// this causes the run-time error. B has not been constructed
//// at this point, so the B::f cannot be called. You would not
//// want it to be called because it could depend on something
//// in B that has not been initialized yet.
//
//B b;
//
//void main()
//{
//}