#include <iostream>

class Base
{
public:
    virtual void Print()
    {
        std::cout << "Base \n";
    }
};

class Dervied : public Base
{
public:
    virtual void Print() override
    {
        std::cout << "Dervied \n";
    }

    int GetID()
    {
        return m_id;
    }

private:
    int m_id;
};

int main()
{
    Base *pb = new Base();
    pb->Print();

    Dervied *pd = dynamic_cast<Dervied*>(pb);
    //Dervied *pd = static_cast<Dervied*>(pb);
    std::cout << pd->GetID() << std::endl;

    return 0;
}