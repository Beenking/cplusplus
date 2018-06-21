#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <memory>

#include "check_memory_leaks.h"
#include "class_A.h"

int main()
{
    _CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
    //_CrtSetBreakAlloc(70);

    _CrtMemState s1, s2, s3;
    _CrtMemCheckpoint(&s1);

    int* p = new int(2);
    long long* p2 = new long long(16);
    auto* pa = new A();

    _CrtMemCheckpoint(&s2);

    if (_CrtMemDifference(&s3, &s1, &s2))
        _CrtMemDumpStatistics(&s3);

    return 0;
}