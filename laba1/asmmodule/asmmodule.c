#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/io.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Egor Moroz");
MODULE_DESCRIPTION("Simple Linux module with Assembler");
MODULE_VERSION("0.1");

int readPort(int reg) 
{
	outb_p(reg, 0x70);
	return inb(0x71);	
}

static int value;

int init_module(void) 
{
	printk(KERN_INFO "ASMModule loaded.\n");
	
	asm("cli");
	value = readPort(0x14);
	asm("sti");
	
	printk(KERN_INFO "%x", value);
	
	if (value & 1)
	{		
		printk(KERN_INFO "Присутствует дисковод гибких дисков\n");
	}
	else
	{
		printk(KERN_INFO "Отсутствует дисковод гибких дисков \n");
	}
	
	
	if (value & 2)
	{
		printk(KERN_INFO "Присутствует блок процессора для операций с плавающей точкой \n");
    }
    else
    {
        printk(KERN_INFO "Отсутсвует блок процессора для операций с плавающей точкой  \n");
	}
	
	
	if (value & 4)
	{
		printk(KERN_INFO "Есть клавиатура \n");
    }
    else
    {
    	printk(KERN_INFO "Нет клавиатуры\n");
    }
	
	
	if (value & 8)
	{
		printk(KERN_INFO "Есть дисплей \n");
    }
    else
    {
        printk(KERN_INFO "Отсутствует дисплей \n");
    }
    
    
	if ((value & 48) == 0)
	{
		printk(KERN_INFO "Основной видеоадаптер: EGA\n");
	}
	else if  ((value & 48) == 16)
	{
		printk(KERN_INFO "Основной видеоадаптер: VGA\n");
	} 
	else if ((value & 48) == 32)
	{
		printk(KERN_INFO "Основной видеоадаптер: CGA\n");
	}
	else if ((value & 48) == 48) 
	{
		printk(KERN_INFO "Основной видеоадаптер: текстовый монохромный дисплей\n");
	}
	
		
	if ((value & 192) == 0) 
	{
		printk(KERN_INFO "Кол-во дисководов: 1\n");
	}
	else if ((value & 192) == 64) 
	{
		printk(KERN_INFO "Кол-во дисководов: 2\n");
	}
	else if ((value & 192) == 128) 
	{
		printk(KERN_INFO "Кол-во дисководов: 3\n");
	}
	else if ((value & 192) == 192) 
	{
		printk(KERN_INFO "Кол-во дисководов: 4\n");
	}
	else
	{
		printk(KERN_INFO "Количество дисководов гибких дисков: неизвестное значение\n");
	} 
		
	
	return 0;
}

void cleanup_module(void)
{
    printk(KERN_ALERT "ASMModule unloaded.\n");
}
