#include <stdio.h>

int sum(int a,int b)
{
	int c;
	asm volatile(
		"mov eax,%0;"
		"mov ebx,%1;"
		"add eax,ebx;"
		"mov %2,eax;"
		:
		:"m"(a), "m"(b), "m"(c)	//m表示内存操作

		);
	return c;
}

void inc(int *a)
{
	asm(
		"mov eax,[%0];"
		"inc eax;"
		"mov [%0],eax;"
		:
		:"r"(a)
		:"eax"
		);
}

int main(int argc, char const *argv[])
{
	int i = 1024;
	printf("%d\n", sum(1,i));
	printf("size of int is: %ld\n",sizeof(int));
	inc(&i);
	printf("%d\n", i);
	return 0;
}