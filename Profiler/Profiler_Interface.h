#pragma once

#include "Profiler.h"

// 프로파일링 시작시 호출
void InitProfiler(void)
{
    ProfileReset();
}

// InitProfiler 호출 이후에 축척된 데이터 출력
void OutputProfileData(const std::wstring& fileName)
{
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