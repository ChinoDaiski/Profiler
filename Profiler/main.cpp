
#include <iostream>
#include "Profiler.h"

int main()
{
    ProfileReset();

    {
        Profile pf(L"Func1");

        // ... ¹º°¡ ÇÔ
    }
    {
        Profile pf(L"Func2");

        // ... ¹º°¡ ÇÔ
    }

    ProfileDataOutText(L"profile_data.txt");
}