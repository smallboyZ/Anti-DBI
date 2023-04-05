#include <stdio.h>
#include <Windows.h>
bool checkEnv() {
	char buffer[2000];
	unsigned int size = GetEnvironmentVariable("PATH", buffer, 2000);
	char* index = strstr(buffer, "\\pin;");
	return index != NULL;
}

int main() {
	char name[15];
	//Anti DBI
	if (checkEnv()) exit(-1);
    //Your Code
	printf("Please Input your name:");
	scanf("%10s", name);
	printf("Hello %s!\n", name);
}
