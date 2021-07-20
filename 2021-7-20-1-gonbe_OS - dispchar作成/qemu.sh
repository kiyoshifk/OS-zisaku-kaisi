#!/bin/sh

cp gonbe.img C:/work/OS自作/OS自作-CD/tolset/z_tools/qemu

cd C:/work/OS自作/OS自作-CD/tolset/z_tools/qemu

#set SDL_VIDEODRIVER=windib
#set QEMU_AUDIO_DRV=none
#set QEMU_AUDIO_LOG_TO_MONITOR=0
./qemu.exe -L . -m 32 -localtime -std-vga -fda gonbe.img
