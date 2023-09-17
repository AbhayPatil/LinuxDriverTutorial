#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Abhay Patil");
MODULE_DESCRIPTION("Registers a devvice nr. and implement some callback functions");


/**
 * @brief Thsi function is called, when the devvice file is opened.
 */
 static int driver_open(struct inode *devvice_file, struct file *instance) {
     printk("devv_nr: - open was called!\n");
     return 0;
 }

/**
 * @brief Thsi function is called, when the devvice file is closed.
 */
 static int driver_close(struct inode *devvice_file, struct file *instance) {
     printk("devv_nr: - close was called!\n");
     return 0;
 }

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = driver_open,
    .release = driver_close
};

#define MYMAJOR 100

/**
 * @brief This func tis called when the module is loadd into the kernel
 */
static int __init ModuleInit(void) {
    int retval;
    printk("devv_nr: ModuleInit: Hello!\n");
    /* register devvice nr. */
    retval = register_chrdev(MYMAJOR, "my_devv_nr", &fops);
    if(retval == 0) {
        printk("devv_nr - registerd devvice number Major:%d, Minor:%d\n", MYMAJOR, 0);

    } else if (retval > 0) {
        printk("devv_nr - registerd devvice number Major:%d, Minor:%d\n", retval>>20, retval & 0xFFFFF);

    } else {
    	printk("Could not register devvice number! retval=%d\n", retval);
	return -1;

    }
    return 0;
}

/**
 * @brief This func is called when the module is removed from kernel
 */
static void __exit ModuleExit(void) {
    unregister_chrdev(MYMAJOR, "my_devv_nr");
    printk("devv_nr: ModuleInit: Goodbye!\n");
} 

module_init(ModuleInit);
module_exit(ModuleExit);
