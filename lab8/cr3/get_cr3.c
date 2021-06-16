#include <linux/module.h>    
#include <linux/kernel.h>    
#include <linux/init.h>     
#include <linux/sched/signal.h>

int PID;
module_param(PID, int, S_IRUGO); //parameter name; parameter type; parameter access permission

/* This function is called when the module is loaded. */
int simple_init(void)
{
	struct task_struct *p;

	unsigned long *this_pgd = NULL;
	
	unsigned long vir_pd1;
	unsigned long phy_pd1;
		
	for_each_process(p)
	{
		if(p->pid == PID)
			this_pgd = (unsigned long*)(p->mm->pgd);
	}
		 
	vir_pd1 = (unsigned long)this_pgd; //address to integer
	phy_pd1 = __pa(vir_pd1);

	//printk("virtual address of pgd: 0x%lx\n", vir_pd1);
	printk("cr3 value of process %d: 0x%lx\n", PID, phy_pd1);

	return 0;
}	

/* This function is called when the module is removed. */
void simple_exit(void)
{
	printk(KERN_INFO "Removing Module\n");
}

/* Macro for registering module entry and exit points. */
MODULE_LICENSE("GPL");
module_init(simple_init);
module_exit(simple_exit);





