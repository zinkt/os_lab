#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched/signal.h> //for_each_process()

int t3_entry(void)
{
	struct task_struct* curr;
	int count = 0;
	for_each_process(curr)
	{
		printk(KERN_INFO "PID: %d, Name: %s, state: %ld\n",curr->pid,curr->comm,curr->state);
		count++;
	}
	printk(KERN_INFO "Total: %d processes\n",count);
	return 0;
}
void t3_exit(void)
{
	printk(KERN_INFO "exit...");

}
module_init(t3_entry);
module_exit(t3_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("kernel module test: ps");
MODULE_AUTHOR("zhj,");