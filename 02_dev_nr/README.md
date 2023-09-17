## How to use this lab

- Build dev_nr.c
 make

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

- printk must end in newline "\n" in order to print the log to dmesg - https://stackoverflow.com/questions/38822599/why-printk-doesnt-print-message-in-kernel-logdmesg
