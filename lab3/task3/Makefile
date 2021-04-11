# declare the name of the kernel module
# the same name as the *.c source file
# e.g.: compile the kernel module hello.ko form hello.o
# and hello.o will be compiled from hello.c

obj-m += task3.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean 