#pragma once

#include "Profiler.h"

// �������ϸ� ���۽� ȣ��
void InitProfiler(void)
{
    ProfileReset();
}

// InitProfiler ȣ�� ���Ŀ� ��ô�� ������ ���
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

// ��� ���
/*
#include "Profiler_Interface.h"

    InitProfiler();

    {
        Profile pf(L"Func1");

        // ... ���� ��
    }
    {
        Profile pf(L"Func2");

        // ... ���� ��
    }
    ...

    OutputProfileData(L"���ϴ� ���� �̸�.txt");
*/