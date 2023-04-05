#include<stdio.h>
#include<Windows.h>
void Trap_PIN() {
    __try {
        _asm {
            push eax
            pushfd
            pop eax
            or eax, 0x100
            push eax
            popfd
            pop eax
        }
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {}
}
int main() {
	char name[15];
	//Anti DBI
    Trap_PIN();
    //Your Code
	printf("Please Input your name:");
	scanf("%10s", name);
	printf("Hello %s!\n", name);
}