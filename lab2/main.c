#include <stdio.h>
#include "mult.h"

int main(int argc, char const *argv[])
{
	printf("This is main.c\n");
	printf("3 * 5 = %d\n",mult2(3,5));
	printf("3 * 5 * 6 = %d\n",mult3(3,5,6) );

	return 0;
}