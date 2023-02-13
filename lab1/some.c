#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Egor Moroz");
MODULE_DESCRIPTION("Simple Linux module");
MODULE_VERSION("0.1");

int init_module(void)
{
    printk(KERN_INFO "Hello world.\n");
    return 0;
}

void cleanup_module(void)
{
    printk(KERN_ALERT "Goodbye world.\n");
}
