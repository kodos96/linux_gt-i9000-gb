#!/bin/sh
echo "Swapping off zram2..."
swapoff /dev/block/zram2
echo "Swapping off zram1..."
swapoff /dev/block/zram1
echo "Swapping off zram0..."
swapoff /dev/block/zram0
/sbin/zramconfig /dev/block/zram0 --reset
/sbin/zramconfig /dev/block/zram1 --reset
/sbin/zramconfig /dev/block/zram2 --reset
rmmod zram.ko
rmmod lzo_compress.ko
rmmod lzo_decompress.ko
rmmod mfc50.ko
/bin/insmod /lib/modules/mfc50.ko
echo "Done"
