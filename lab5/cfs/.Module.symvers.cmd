cmd_/home/zinkt/Documents/codes/os_lab/lab5/cfs/Module.symvers := sed 's/ko$$/o/' /home/zinkt/Documents/codes/os_lab/lab5/cfs/modules.order | scripts/mod/modpost -m -a   -o /home/zinkt/Documents/codes/os_lab/lab5/cfs/Module.symvers -e -i Module.symvers   -T -
