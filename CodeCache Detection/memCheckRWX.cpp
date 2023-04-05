#include<stdio.h>
#include<Windows.h> 
#define limit 5
DWORD GetRWXmemcnt() {
	MEMORY_BASIC_INFORMATION mbi = {};
	DWORD adr;
	adr = (DWORD)GetModuleHandle(NULL);
	DWORD cnt = 0;
	DWORD rwxsum = 0;
	while (true)
	{
		if (!VirtualQuery((LPCVOID)adr, &mbi, sizeof(mbi))) {
			break;
		}
		//printf("%x : %p %x\n", cnt, mbi.BaseAddress, mbi.RegionSize);
		if (mbi.Protect == PAGE_EXECUTE_READWRITE) {
			rwxsum += 1;
			if (rwxsum > limit) exit(-1);
		}
		adr += mbi.RegionSize;
		cnt += 1;
	}
	return rwxsum;
}

int main() {
	char name[15];
	//Anti DBI
	GetRWXmemcnt();
    //Your Code
	printf("Please Input your name:");
	scanf("%10s", name);
	printf("Hello %s!\n", name);
}
