#include <iostream>
#include <tuple>
#include <string>

int main()
{
    std::tuple<int, double, std::string, int> tp(1, 2.2, "ss", 2);
    auto item = std::get<0>(tp);
    auto item2 = std::get<1>(tp);
    auto item3 = std::get<2>(tp);

    std::cout << item << " " << item2 << " " << item3 << std::endl;
}