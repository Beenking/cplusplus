#include <iostream>

// value值保持在[min, max]区间内
template<typename T1, typename T2>
bool clamp(T1 min, T2 &value, T1 max)
{
    T2 fixValue = value < min ? min : (value > max ? max : value);
    bool IsChanged = (fixValue != value);
    value = fixValue;
    return IsChanged;
}

int main()
{
    int value = -1;
    std::cout << clamp(1, value, 3) << std::endl;
    std::cout << value << std::endl;


    double d = 2.2;
    int i = 1.99999999;
    std::cout << ++d << std::endl;
    std::cout << i << std::endl;
    return 0;
}