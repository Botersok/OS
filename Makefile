C_SOURCES = $(wildcard kernel/*.c drivers/*.c cpu/*.c)
HEADERS = $(wildcard kernel/*.h drivers/*.h cpu/*.h)

#list of object files
OBJ = ${C_SOURCES:.c=.o cpu/interrupt.o} 

CC = /usr/local/i386elfgcc/bin/i386-elf-gcc
LC = /usr/local/i386elfgcc/bin/i386-elf-ld

all: os-image.bin
run: os-image.bin
	qemu-system-i386 -drive format=raw,file=$^,if=floppy

os-image.bin: boot/boot.bin kernel.bin
	cat $^ > os-image.bin

kernel.bin: kernel/kernel_entry.o ${OBJ}
	${LC} -o $@ -Ttext 0x1000 $^ --oformat binary

%.o: %.c ${HEADERS}
	${CC} -std=c99 -ffreestanding -c $< -o $@

%.o: %.asm
	nasm $< -f elf -o $@

%.bin: %.asm
	nasm $< -f bin -o $@

clean:
	rm -fr *.bin *.dis *.o os-image
	rm -fr kernel/*.o boot/*.bin drivers/*.o cpu/*.o

kernel.dis: kernel.bin
	ndisasm -b 32 $< > $@
