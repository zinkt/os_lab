#include <linux/module.h>
#include <linux/kernel.h>

//called when module is loaded
int hello_entry(void)
{
	printk(KERN_INFO "This is hello_km.c\n");
	return 0;
}

//called when module is removed
void hello_exit(void)
{
	printk(KERN_INFO "Exit hello_km.c\n");
}

//macros(宏) for registering module entry and exit points
module_init(hello_entry);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("kernel module example");
MODULE_AUTHOR("zhj,");