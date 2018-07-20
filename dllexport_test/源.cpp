#include "../test_dll/print_fun.h"

int main()
{
    MyPrint(100);
    MyPrint2();

    Test t1;
    t1.print();
    Test::i = 3;
    return 0;
}
