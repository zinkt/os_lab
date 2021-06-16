#include <stdio.h>  
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
        unsigned long temp = 0x00123456AABBCCDD; //to be read from physical memory by page table walk

	printf("pid: %d\n", getpid());
	printf("virtual address: %p\n", &temp);
	
	unsigned long viradd = (unsigned long)&temp;
		
	short offset1 = (viradd >> 39) & 0x1FF;
	short offset2 = (viradd >> 30) & 0x1FF;
	short offset3 = (viradd >> 21) & 0x1FF;
	short offset4 = (viradd >> 12) & 0x1FF;
	short offset5 = viradd & 0xFFF;
	
	printf("=======================================\n");
	
	printf("offset1: %x\n", offset1 * 8);
	printf("offset2: %x\n", offset2 * 8);
	printf("offset3: %x\n", offset3 * 8);
	printf("offset4: %x\n", offset4 * 8);
	printf("offset5: %x\n", offset5);
	
	while(1)
	{
		sleep(10);
	}
	
	return 0;
	
}
