
#include <iostream>
#include "Profiler_Interface.h"

int main()
{
    InitProfiler();

    {
        Profile pf(L"Func1");

        // ... ���� ��
    }
    {
        Profile pf(L"Func2");

        // ... ���� ��
    }

    OutputProfileData(L"profile_data.txt");
}