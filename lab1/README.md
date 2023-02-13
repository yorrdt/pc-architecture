# lab 1

Linux kernel module development

## Installing dependencies

To compile you need to install linux-headers

```
sudo pacman -S linux-headers
```

Header version must match your kernel version. To check kernel version:

```
sudo hostnamectl
```
Or

```
uname -r
```

To check all headers

```
pacman -Q | grep headers
```

You may need to reboot your system to start using the kernel headers.

```
reboot
```

## Compile linux_kernel_module.c

To compile you need Makefile.

```sud
make -C /lib/modules/$(uname -r)/build M=`pwd` modules
```

## Run module

```
sudo insmod linux_kernel_module.ko
```

## Kernel log

```
sudo dmesg
```

## Checking if a module exists in memory

```
lsmod | grep linux_kernel_module
```

## Delete module

```
sudo rmmod linux_kernel_module
```
