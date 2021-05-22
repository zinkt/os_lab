#include <stdio.h>
long int test_n_set(long int *lock)
{
	long int res;
	asm(
		"mov rax,0;"
		"mov rbx,1;"
		"lock cmpxchg [%1],rbx;"
		"mov %0,rax;"
		:
		:"m"(res),"r"(lock)
		:"eax","ebx"
		);
}
int main(int argc, char const *argv[])	//测试
{
	long int lock0 = 0;
	long int lock1 = 1;
	printf("origin lock0 is 0, now lock is:%ld, return value is: %ld\n", lock0,test_n_set(&lock0));
	printf("origin lock1 is 1, now lock is:%ld, return value is: %ld\n", lock1,test_n_set(&lock1));
	return 0;
}