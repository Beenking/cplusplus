#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <thread>
#include <memory>
#include <algorithm>
#include <exception>

#include "test_and_or.h"
#include "weakptr_test.h"
#include "check_memory_leak.h"


int main()
{
    // test1
    //bool re = (fa() || fb()) && fc();

    //// test2 weak_ptr
    //std::shared_ptr<A> spA(new A());
    //std::shared_ptr<B> spB(new B());
    //spA->m_spB = spB;
    //spB->m_spA = spA;

    ////test3  x64 8   x86 4
    //auto pSize_a = sizeof(new A());
    //auto pSize_i = sizeof(new int);

    // test4

    _CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
    _CrtSetBreakAlloc(177);
    int* pi = new int(2);
    A* pa = new A();
    *pi = 3;

    delete pi;

    _CrtDumpMemoryLeaks();
    return 0;
}