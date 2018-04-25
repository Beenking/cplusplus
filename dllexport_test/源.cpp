#include "../test_dll/print_fun.h"

extern void MyPrint(int i);
int main()
{
    MyPrint(19);

    Test t1;
    t1.print();
    Test::i = 3;
    return 0;
}
