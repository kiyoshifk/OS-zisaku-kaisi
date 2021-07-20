#!/bin/sh

rm gonbe_main.o
rm boot_loader.bin
rm boot_loader.lst
rm os_start.o
rm os_start.lst
rm gonbe_rear.elf
rm gonbe_rear.srec
rm gonbe_rear.img
rm gonbe.img
rm gonbe_rear.map
rm font_lib.o
rm sjis.o

nasm -f bin -o boot_loader.bin -l boot_loader.lst boot_loader.nasm
nasm -f elf32 -o os_start.o -l os_start.lst os_start.nasm
###gcc -x c -c -O1 -Werror -Wall -o gonbe_main.o gonbe_main.c 
gcc -x c -c -O0 -Werror -Wall -o gonbe_main.o gonbe_main.c 
gcc -x c -c -O0 -Werror -Wall -o font_lib.o font_lib.c 
gcc -x c -c -O0 -Werror -Wall -o sjis.o sjis.c 
gcc -o gonbe_rear.elf os_start.o gonbe_main.o sjis.o font_lib.o -nostdlib -nostartfiles -nodefaultlibs -nolibc -Tlinker.ld -Wl,-Map=gonbe_rear.map
objcopy -O srec gonbe_rear.elf gonbe_rear.srec
C:/work/OS自作/win-build/tools/srec_to_img/srec_to_img-0x00280000.exe gonbe_rear.srec gonbe_rear.img	# gonbe_rear.img は 0x8000番地からの生データ
cat boot_loader.bin gonbe_rear.img > gonbe.img


