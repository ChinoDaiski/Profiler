
#include <iostream>
#include "Profiler_Interface.h"

int main()
{
    InitProfiler();

    {
        Profile pf(L"Func1");

        // ... ¹º°¡ ÇÔ
    }
    {
        Profile pf(L"Func2");

        // ... ¹º°¡ ÇÔ
    }

    OutputProfileData(L"profile_data.txt");
}