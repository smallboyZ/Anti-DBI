#include<stdio.h>
#include<Windows.h> 
#define limit 5
bool memExecRW() {
	BYTE* buffer = (PBYTE)VirtualAlloc(0, 1, MEM_COMMIT, PAGE_READWRITE); 
	*buffer = 0xc3;
	__try {
		_asm call buffer      
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		if (GetExceptionCode() == EXCEPTION_ACCESS_VIOLATION)
		return false;
	}
	return true;
}
int main() {
	char name[15];
	//Anti DBI
	if (memExecRW()) exit(-1);
    //Your Code
	printf("Please Input your name:");
	scanf("%10s", name);
	printf("Hello %s!\n", name);
}
