
#include <iostream>
#include "Profiler.h"

int main()
{
    ProfileReset();

    {
        Profile pf(L"Func1");

        // ... ���� ��
    }
    {
        Profile pf(L"Func2");

        // ... ���� ��
    }

    ProfileDataOutText(L"profile_data.txt");
}