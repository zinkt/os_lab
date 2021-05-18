#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "quick_sort_rec.c"
#include "bubbling_sort.c"
#define SIZE 2000000
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
	quick_sort_rec(elem,0,SIZE-1);
	//bubbling_sort(elem,0,SIZE-1);
	/*for (int i = 0; i < SIZE; ++i)
	{
		printf("%d ", elem[i]);
	}
	*/
	return 0;
}
