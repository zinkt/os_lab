#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#define SIZE 200000
#define MAX 200000

int elem[SIZE];
int comp(const void *a,const void *b){return *(int*)a-*(int*)b;}

void initArray()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < SIZE; ++i)
		elem[i] = rand() % MAX;
}
int main(int argc, char const *argv[])
{
	initArray();
	qsort(elem,SIZE,sizeof(int),comp);
	for (int i = 0; i < SIZE; ++i)
	{
		printf("%d ", elem[i]);
	}
	return 0;
}
