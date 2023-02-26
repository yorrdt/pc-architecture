#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/io.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Egor Moroz");
MODULE_DESCRIPTION("Simple Linux module with Assembler");
MODULE_VERSION("0.1");

int readPort(int reg) 
{
	outb(reg, 0x70);
	return inb(0x71);	
}

int init_module(void) 
{
	printk(KERN_INFO "ASMModule loaded.\n");
	
	char value;
	asm("cli");
	value = readPort(0x06);
	asm("sti");
	
	printk(KERN_INFO "ASMModule: %d\n", value);
	
	return 0;
}

void cleanup_module(void)
{
    printk(KERN_ALERT "ASMModule unloaded.\n");
}
