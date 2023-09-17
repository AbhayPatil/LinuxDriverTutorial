#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Abhay Patil");
MODULE_DESCRIPTION("Hello World for LKM");

/**
 * @brief This func tis called when the module is loadd into the kernel
 */

static int __init ModuleInit(void) {
    printk("Hello Kernel !\n");
    return 0;
}

/**
 * @brief This func is called when the module is removed from kernel
 */

static void __exit ModuleExit(void) {
    printk("Goodbye, Kernel!\n");
} 

module_init(ModuleInit);
module_exit(ModuleExit);
