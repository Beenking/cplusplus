#include <iostream>
#include <typeinfo>

class OperationBase
{
public :
    virtual int Excute()
    {
        return 0;
    }
};

class ZoomOperation : public OperationBase
{
public:
    int Excute2()
    {
        return 100;
    }
};


int main()
{
    OperationBase* op = new ZoomOperation();
    std::cout << typeid(*op).name() << std::endl;

    return 0;
}