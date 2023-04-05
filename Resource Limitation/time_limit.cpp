#include<stdio.h>
#include<Windows.h>
int Fbnum(int n) {
	if (n <= 1) return 1;
	else return Fbnum(n - 1) + Fbnum(n - 2);
}
bool time_limit() {
	unsigned int beg, end, ans;
	beg = GetTickCount();
	ans = Fbnum(30);
	end = GetTickCount();
	return end - beg > 50;
}
int main() {
	char name[15];
	//Anti DBI
	if (time_limit()) exit(-1);
    //Your Code
	printf("Please Input your name:");
	scanf("%10s", name);
	printf("Hello %s!\n", name);
}