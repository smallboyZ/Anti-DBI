#include <stdio.h>
#include <Windows.h>
#include<string.h>
bool findPindll() {
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
		__try {
			if (!memcmp((BYTE*)((size_t)mbi.BaseAddress + 0x288), ".pinvers", 8)) return true;
		}
		__except (1) {};
		adr += mbi.RegionSize;
	}
	return false;
}

int main() {
	char name[15];
	//Anti DBI
	if (findPindll()) exit(-1);
    //Your Code
	printf("Please Input your name:");
	scanf("%10s", name);
	printf("Hello %s!\n", name);
}
