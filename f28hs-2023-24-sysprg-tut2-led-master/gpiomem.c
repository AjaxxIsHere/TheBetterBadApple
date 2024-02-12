/*
 From: https://www.iot-programmer.com/index.php/books/22-raspberry-pi-and-the-iot-in-c/chapters-raspberry-pi-and-the-iot-in-c/59-raspberry-pi-and-the-iot-in-c-memory-mapped-gpio?showall=&start=1
 "Raspberry Pi And The IoT In C - Memory Mapped GPIO"
 by Harry Fairhead, IO Press, ISBN: 978-1871962468.
 harry.fairhead@iot-programmer.com
 Code listings at: http://iopress.info/index.php/books/raspberry-pi-iot-in-c
 Retrieved 23.1.2018

 Stand-alone version Hans-Wolfgang Loidl, developed for the course 
 F28HS "Hardware-Software Interface", Heriot-Watt University, Edinburgh
 http://www.macs.hw.ac.uk/~hwloidl/Courses/F28HS
 January 2018
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

void main () {
 uint32_t *bcm2835_peripherals_base;

 bcm2835_peripherals_base =  (uint32_t *)0x20000000;  
 FILE * fp;
 fprintf(stdout, "Retrieving GPIO memory base address from device tree file: /proc/device-tree/soc/ranges ...\n");
 if ((fp = fopen("/proc/device-tree/soc/ranges" , "rb")))
 {
  unsigned char buf[8];
  if (fread(buf, 1, sizeof(buf), fp) == sizeof(buf))
     bcm2835_peripherals_base = 
        (uint32_t *)(buf[4] << 24 |
                     buf[5] << 16 | 
                     buf[6] << 8  | 
                     buf[7] << 0);
  fprintf(stdout, "GPIO mem starts at: %x\n", bcm2835_peripherals_base);
  fclose(fp);
 }
}
