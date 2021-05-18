#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>

int pid1;
int pid2;
module_param(pid1, int, S_IRUGO); //parameter name; parameter type; parameter access permission
module_param(pid2, int, S_IRUGO); //S_IRUGO: can be read by UGO but cannot be modified


int module_load(void)
{
	struct task_struct *p;   
    	for_each_process(p) {  
       	if(p->pid == pid1 || p->pid == pid2)   
                	printk("Process found!\n");  
    	}     
   	return 0; 
}

void module_rm(void) {

	printk(KERN_INFO "Module removed!\n");
}

module_init(module_load);
module_exit(module_rm);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("execution time");
MODULE_AUTHOR("zhaohj");
