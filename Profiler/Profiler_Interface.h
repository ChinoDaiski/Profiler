#pragma once

#include "Profiler.h"

UINT32 isMultiThread = 0;

// 프로파일링 시작시 호출
void InitProfiler(void)
{
    ProfileReset();
}

// 해당 스레드에서의 측정이 끝났을 경우 호출
void TerminateMeasure(void)
{
    FlushThreadProfileData();

    InterlockedIncrement(&isMultiThread);
}

// InitProfiler 호출 이후에 축척된 데이터 출력
void OutputProfileData(const std::wstring& fileName)
{
    UINT32 callCnt = InterlockedCompareExchange(&isMultiThread, 0, 0);

    // 한번이라도 TerminateMeasure를 호출해서 g_allProfileDatas에 데이터를 옮겼다면
    if (callCnt != 0)
        ProfileDataOutTextMultiThread(fileName);
    // 아니라면 thread_local인 profileDatas 변수에 있는 값을 그대로 출력
    else
        ProfileDataOutText(fileName);
}

class Profile {
public:
    Profile(const std::wstring& tag) : m_tagName(tag) {
        PRO_BEGIN(m_tagName);
    }
    ~Profile() {
        PRO_END(m_tagName);
    }

private:
    std::wstring m_tagName;
};

// 사용 방법
/*
#include "Profiler_Interface.h"

    InitProfiler();

    {
        Profile pf(L"Func1");

        // ... 뭔가 함
    }
    {
        Profile pf(L"Func2");

        // ... 뭔가 함
    }
    ...

    OutputProfileData(L"원하는 파일 이름.txt");
*/