#include<stdio.h>
#include<Windows.h> 
#define limit 5
bool CheckPinHook() {
    DWORD pKiUserApcDispatcher;
    pKiUserApcDispatcher = (DWORD)GetProcAddress(LoadLibrary("ntdll.dll"), "KiUserApcDispatcher");
    BYTE fbyte = *(BYTE*)pKiUserApcDispatcher;
    printf("KiUserApcDispatcher first byte: 0x%02x\n", fbyte);
    if (fbyte == 0x83) return false;
	return true;
}
int main() {
	char name[15];
	//Anti DBI
	if (CheckPinHook()) exit(-1);
    //Your Code
	printf("Please Input your name:");
	scanf("%10s", name);
	printf("Hello %s!\n", name);
}
