#include<stdio.h>
#include<Windows.h> 
#define limit  10
void GetCodeCachesigcnt() {
	MEMORY_BASIC_INFORMATION mbi = {};
	DWORD adr;
	adr = (DWORD)GetModuleHandle(NULL);
	DWORD ccsigcnt = 0;
	while (true)
	{
		if (!VirtualQuery((LPCVOID)adr, &mbi, sizeof(mbi))) {
			break;
		}
		if (mbi.Protect == PAGE_EXECUTE_READWRITE) {
			for (int i = 0; i < mbi.RegionSize; i++) {
				if (*(DWORD*)(adr + i) == 0xfeedbeaf) {
					ccsigcnt += 1;
					if (ccsigcnt > limit) exit(-1);
				}
			}
		}
		adr += mbi.RegionSize;
	}
}
int main() {
	char name[15];
	//Anti DBI
	GetCodeCachesigcnt();
    //Your Code
	printf("Please Input your name:");
	scanf("%10s", name);
	printf("Hello %s!\n", name);
}
