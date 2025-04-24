
//#include <iostream>
//#include "Profiler_Interface.h"
//
//int main()
//{
//    InitProfiler();
//
//    {
//        Profile pf(L"Func1");
//
//        // ... 뭔가 함
//    }
//    {
//        Profile pf(L"Func2");
//
//        // ... 뭔가 함
//    }
//
//    TerminateMeasure();
//
//    OutputProfileData(L"profile_data.txt");
//}


#include <windows.h>
#include <iostream>
#include <chrono>
#include "Profiler_Interface.h"

#pragma comment(lib, "Winmm.lib")

#define NUM_ITERATIONS 1000000  // 측정할 반복 횟수

// timeGetTime 성능 측정
void MeasureTimeGetTime() {
    DWORD start = timeGetTime();
    for (int i = 0; i < NUM_ITERATIONS; ++i) {
        Profile pf(L"timeGetTime");
        timeGetTime();
    }
    DWORD end = timeGetTime();
    std::cout << "timeGetTime total time: " << (end - start) << " ms" << std::endl;
}

// QueryPerformanceCounter 성능 측정
void MeasureQueryPerformanceCounter() {
    LARGE_INTEGER start, end, frequency;
    QueryPerformanceFrequency(&frequency);  // 클럭 주파수 획득
    QueryPerformanceCounter(&start);
    for (int i = 0; i < NUM_ITERATIONS; ++i) {
        Profile pf(L"QueryPerformanceCounter");
        QueryPerformanceCounter(&end);
    }
    std::cout << "QueryPerformanceCounter total time: "
        << static_cast<double>(end.QuadPart - start.QuadPart) / frequency.QuadPart * 1000
        << " ms" << std::endl;
}

// std::chrono 성능 측정
void MeasureChrono() {
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < NUM_ITERATIONS; ++i) {
        Profile pf(L"chrono");
        auto now = std::chrono::high_resolution_clock::now();
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "std::chrono total time: " << duration.count() * 1000 << " ms" << std::endl;
}

int main() {
    ProfileReset();

    timeBeginPeriod(1);

    std::cout << "Performance Comparison:" << std::endl;

    // std::chrono 성능 측정
    MeasureChrono();

    // timeGetTime 성능 측정
    MeasureTimeGetTime();

    // QueryPerformanceCounter 성능 측정
    MeasureQueryPerformanceCounter();

    std::cout << "테스트 완료. 파일 작성중...\n";

    FlushThreadProfileData();
    ProfileDataOutTextMultiThread(L"profile_data.txt");

    std::cout << "파일 작성 완료\n";

    return 0;
}
