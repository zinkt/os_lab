#include <stdio.h>
#include <stdlib.h>
#include "merge_ordered.c"
int main(int argc, char const *argv[])
{
	int a[] = {1,2,4,5,6,7,7,7,7,7,9,19};//12
	int b[] = {5,10,26,33,44,55,67,88,99,99};//10
	int *merged = merge_ordered(a,b,12,10);
	for (int i = 0; i < 22; ++i)	
		printf("%d ", merged[i]);
	return 0;
}