#include<stdio.h>
#include<Windows.h> 

bool check_ip() {
	unsigned int myip;
	unsigned int orgip;
	_asm {
	start:
		fldz
			sub esp, 28
			fnstenv[esp - 0xc]
			mov eax, dword ptr[esp]
			mov myip, eax
			lea eax, start
			mov orgip, eax
			add esp, 28
	}
	printf("orgip: 0x%p\n", orgip);
	printf("getip: 0x%p\n", myip);
	return orgip == myip;
}

int main() {
	char name[15];
	//Anti DBI
	if (!check_ip()) exit(-1);
    //Your Code
	printf("Please Input your name:");
	scanf("%10s", name);
	printf("Hello %s!\n", name);
}
