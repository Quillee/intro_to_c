- [Environment](#environment)
    - [Purpose of this document?](#purpose-of-this-document)
    - [Arch linux](#arch-linux)
    - [Why linux over windows?](#why-linux-over-windows)
    - [Why arch over other distros](#why-arch-over-other-distros)
- [Steps](#steps)
    - [Disk Partitions](#disk-partitions)
        - [BOOT](#boot)
        - [SWAP(optional)](#swapoptional)
        - [ROOT](#root)
        - [HOME](#home)
    - [Mounting drives](#mounting-drives)
    - [Installation](#installation)
    - [Switching to your machine](#switching-to-your-machine)

# Environment

## Purpose of this document?
    because I'll forget. but if some random person finds it and it can be useful, that's cool too.

## Arch linux
- arch linux is a distribution of GNU/Linux [arch](https://www.archlinux.org/) that follows a rolling-release model. 
    - this means that 
- Taken straight from Arch Wiki:
> ...Arch Linux, a lightweight and flexible Linux® distribution that tries to Keep It Simple.


## Why linux over windows?
- There is nothing wrong with programming on windows or mac and there are even plenty of easier/user friendly distributions of GNU/Linux, like Ubuntu for example
- My main reasons for choosing arch for my learning process is as follows:
    - one platform
        - Windows doesn't have a native C compiler and I don't want to seperate console applications and other applications
    - simplicity
        - no extra bells and whistles, only the original GNU platform and whatever else I choose to install
    - customizability
        - going further on the above point, I can customize this installation from the bottom up
    - learning
        - the biggest reason however is to learn. I've played around plenty with other GNU/Linux(mostly debian systems) and thought this would be an interesting change of pace

## Why arch over other distros
    Just to learn and cause it's small. That's it, you can do all the same stuff with Ubuntu or Mint and even apply the later mentioned ricing stuff with a lot less of a hassle. And if you're looking for a small distro that's easier to install: xubuntu, puppy linux or ubuntu mate are all small distros with much easier install steps.

# Steps

## Disk Partitions
- No character identifiers like in Windows: **C:**, or **D:**
    - these are arbitrary and tell you no information about what you're looking at, however much easier to remember and identify
    - in GNU/Linux systems, if you type lsblk you will see things like /dev/sda, expanded it looks like this
        - / ___device___ / ___storage_device___{___driveByLetter___}{___partitionByNumber___}
        - so if you have 2 drives where one is cut in half you would have **/dev/sda, /dev/sdb1, /dev/sdb2**
- there are 4 common disk partitions
    - **boot**
    - **swap**
    - **root**
    - **home**
- mkfs.ext4 {filesystem} ->make filesystem format extended (linux) files system (ver 4.) do this for all partitions


### BOOT
- contains boot loader
    - def : boots arch. runs the set of applications under /boot/* directory 
        - => kernel, initrd, GRUB, etc.
    -  more info [bootloader](#boot-loader)
### SWAP(optional)
- used as additional ram in case of ram overflow and special cases like hibernation
- good if you don't have a lot of ram, which allows you to leverage some of your HDD space to continue using whatever applications and proccesses you have up
    NOTE: this is not a replacement, RAM is much faster then HDD and even SSD. Also the data has to travel a greater distance to get to it.
- This is entireley optional and depends on if you need the extra RAM space and have the extra HDD space or if you want a hibernate mode option, etc.

### ROOT
- also known as system
- /* -> root is / and the whole filesystem exists underneath it, so every file and directory is a child of root
    - programs and other files that have to do with the configuration or management of the machine in general
### HOME
- where everything else goes

## Mounting drives
- each partition has to be placed in the correct folder and mounted under /
- mkswap {filesystem you want to be cosidsered swap} && swapon {same filesystem}
    - sets up swap partition
- mount {filesystem}
    - when installing, you want to place these filesystemss relative to /mnt
        - **ROOT** fs goes under /mnt
        - **HOME** fs goes under /mnt/home
        - **BOOT** fs goes under /mnt/boot
## Installation
- pacstring /mnt base {other packages}
    - base is what you want
    - basedevel is a good starting point for developers
- fstab
    - maps partitions to their value and locations
    - fstab -U >> {mountable drive}/etc/fstab
    - it should look something like this:
    > UUID={some-long-hex}  {directory} {filesystem} {type} {other stuff}
- now your install is properly mounted
## Switching to your machine
- don't turn off the machine just yet
- instead run the command arch-chroot /mnt
- now you are in the root directory, try ls and check it out
- pacman -S networkmanager
    - so that your network settings work
    - systemctl enable NetworkManager
- pacman -S grub
    - grub is the nice menu that helps boot into your os
    - a few more things have to be done to make this work
        - grub-install --target=i386-pc {partition}
        - grub-mkconfig > /boot/grub/grub.cfg
            - creates a grub config file in that location
- pacman -S {emacs, vim, neovim, etc.}
    - get your favorite text editor
- {editor} /etc/hostname
    - enter the name you want your computer to go by
