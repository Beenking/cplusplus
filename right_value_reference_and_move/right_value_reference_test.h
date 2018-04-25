#pragma once
#include <iostream>
using namespace std;

int power(int &i)
{
    cout << "left value reference" << endl;
    return i * i;
}

int power(int &&i)
{
    cout << "right value reference" << endl;
    return i * i;
}

void right_value_reference_test()
{
    int i = 2;
    cout << power(2) << endl;
    cout << power(i + 0) << endl;
    cout << power(i) << endl;
    cout << power(power(i)) << endl;
}