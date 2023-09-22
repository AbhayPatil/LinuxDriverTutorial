## How to use this lab

- Build dev_nr.c
`make`

- Insert dev_nr module into kernel
`sudo insmod dev_nr.ko`

- Check the module is added to kernel
`sudo dmesg | tail`

- See dev_nr listed in devices
```
cat /proc/devices
sudo mknod /dev/mydevice3 c 100 0
sudo chmod 666 /dev/mydevice3
```

- Test
```
gcc test.c -o test
./test
sudo dmesg | tail
```


## Miscellaneous

- MAJOR number refers to the driver. And the MINOR number refers to instance name.

- register_chrdev() registers the device call with the VFS.

- printk must end in newline "\n" in order to print the log to dmesg - https://stackoverflow.com/questions/38822599/why-printk-doesnt-print-message-in-kernel-logdmesg

- Other useful kernel APIs/utilities and their header files.
```
#include include/linuyx/fs.h
alloc_chrdev_region()
unregister_chrdev_region()

#include include/linuyx/cdev.h
cdev_init(), cdev_del()
cdev_add()

#include include/linuyx/device.h
class_create(), class_destroy()
device_create(), device_destory()

#include include/linux/uaccess.h
copy_to_user(), copy_from_user()

#include include/linux/fs.h
VFS structure definitions
```

