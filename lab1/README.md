# lab 1

## Compile some.c

```
make -C /lib/modules/$(uname -r)/build M=`pwd` modules
```

## Run module

```
sudo insmod some
```

## Kernel log

```
sudo dmesg
```

## Checking if a module exists in memory

```
lsmod | grep some
```

## Delete module

```
sudo rmmod some
```
