#include <Windows.h>
#include <stdio.h>
#include <tlhelp32.h>
#include <Psapi.h>
#include<string.h>
DWORD getParentPID(DWORD pid)
{
    HANDLE h = NULL;
    PROCESSENTRY32 pe = { 0 };
    DWORD ppid = 0;
    pe.dwSize = sizeof(PROCESSENTRY32);
    h = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); 
    if (Process32First(h, &pe)) 
    {
        do
        {
            if (pe.th32ProcessID == pid) 
            {
                ppid = pe.th32ParentProcessID;
                break;
            }
        } while (Process32Next(h, &pe));
    }
    CloseHandle(h);
    return (ppid); 
}

int getProcessName(DWORD pid, LPSTR fname, DWORD sz)
{
    HANDLE h = NULL;
    int e = 0;
    h = OpenProcess 
    (
        PROCESS_QUERY_INFORMATION,
        FALSE,
        pid
    );
    if (h)
    {
        if (GetModuleFileNameEx(h, NULL, fname, sz) == 0) 
            e = GetLastError(); 
        CloseHandle(h);
    }
    else
    {
        e = GetLastError();
    }
    return (e);
}
bool checkParentProc() {
    DWORD pid, ppid;
    int e;
    char fname[MAX_PATH] = { 0 };
    char name[100];
    pid = GetCurrentProcessId();
    ppid = getParentPID(pid);
    e = getProcessName(ppid, fname, MAX_PATH);
    char* check = strstr(fname, "pin.exe");
    if (check != NULL) return true;
    return false;
}
int main() {
	char name[15];
	//Anti DBI
	if (checkParentProc()) exit(-1);
    //Your Code
	printf("Please Input your name:");
	scanf("%10s", name);
	printf("Hello %s!\n", name);
}
