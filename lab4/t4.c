#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "quick_sort_rec.c"
#include "bubbling_sort.c"
#include "merge_ordered.c"
#define SIZE 1000000
#define MAX 200000
struct ary_info
{
	int *ary;
	int size;
};
int ary1[SIZE];
int ary2[SIZE];
void *runner(void *param);
void initArray(int *ary);
int main()
{
	initArray(ary1);
	initArray(ary2);
	struct ary_info arg1, arg2;
	arg1.ary = ary1;
	arg1.size = SIZE;
	arg2.ary = ary2;
	arg2.size = SIZE;
	pthread_t tid1, tid2;
	pthread_attr_t attr1;
	pthread_attr_t attr2;
	pthread_attr_init(&attr1);
	pthread_attr_init(&attr2);
	pthread_create(&tid1,&attr1,runner,&arg1);
	pthread_create(&tid2,&attr2,runner,&arg2);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	int *merge = merge_ordered(ary1,ary2,SIZE,SIZE);
	/*for (int i = 0; i < SIZE; ++i)
		printf("%d ", merge[i]);	*/
	return 0;
}

void *runner(void *para)
{
	struct ary_info *p = (struct ary_info *)para;
	quick_sort_rec(p->ary,0,p->size-1);
	//bubbling_sort(p->ary,0,p->size-1);
	pthread_exit(NULL);
}

void initArray(int *ary)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < SIZE; ++i)
		ary[i] = rand() % MAX;
}