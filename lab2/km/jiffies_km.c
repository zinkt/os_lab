#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/jiffies.h>
//called when module is loaded
unsigned long jiffies_temp;

int jiffies_entry(void)
{
	jiffies_temp = jiffies;
	printk(KERN_INFO "The jiffies: %lu (entry)\n",jiffies_temp);
	printk(KERN_INFO "The HZ: %d \n",HZ);
	
	return 0;
}

//called when module is removed
void jiffies_exit(void)
{
	printk(KERN_INFO "The delta jiffies: %lu\n",jiffies-jiffies_temp);
	printk(KERN_INFO "The time elapsed: %ld",(jiffies-jiffies_temp)/HZ);
	printk(KERN_INFO "exit");
}

//macros(宏) for registering module entry and exit points
module_init(jiffies_entry);
module_exit(jiffies_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("kernel module example : jiffies");
MODULE_AUTHOR("zhj,");