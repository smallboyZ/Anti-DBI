#include<stdio.h>
__declspec(naked) void x86_to_x64() {
	_asm {
		push 0x33
		push x64code
		retf;           
	x64code: 
		_emit 0xE8;
		_emit 0x00;
		_emit 0x00;
		_emit 0x00;
		_emit 0x00;
		_emit 0xC7;
		_emit 0x44;
		_emit 0x24;
		_emit 0x04;
		_emit 0x23;
		_emit 0x00;
		_emit 0x00;
		_emit 0x00;
		_emit 0x83;
		_emit 0x04;
		_emit 0x24;
		_emit 0x0D;
		_emit 0xCB;
		ret  
	}
}
int main() {
	char name[15];
	//Anti DBI
	x86_to_x64();
	//Your Code
	printf("Please Input your name:");
	scanf("%10s", name);
	printf("Hello %s!\n", name);
}