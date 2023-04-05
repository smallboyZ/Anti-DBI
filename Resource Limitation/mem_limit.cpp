#include<stdio.h>
#include<Windows.h>
#include <psapi.h> 
#define limit  1000
bool Meminfo_Limit() {
	HANDLE handle = GetCurrentProcess();
	PROCESS_MEMORY_COUNTERS pmc;
	GetProcessMemoryInfo(handle, &pmc, sizeof(pmc));
	printf("PeakPagefileUsage: %d(KB)\n", pmc.PeakPagefileUsage / 1024);
	return pmc.PeakPagefileUsage / 1024 > limit;
}
int main() {
	char name[15];
	//Anti DBI
	if (Meminfo_Limit()) exit(-1);
    //Your Code
	printf("Please Input your name:");
	scanf("%10s", name);
	printf("Hello %s!\n", name);
}