all: os-image
run: all
	bochs

os-image: boot_sect.bin kernel.bin
	cat $^ > os-image

kernel.bin: kernel_entry.o kernel.o
	ld -o kernel.bin -Ttext 0x1000 $^ --oformat binary

kernel.o: kernel.c
	gcc -ffreestanding -c $< -o $@

kernel_entry.o: kernel_entry.asm
	nasm $< -f elf64 -o $@

boot.bin: boot.asm
	nasm $< -f bin -o $@

clean:
	rm -fr *.bin *.dis *.o os-image *.map

kernel.dis: kernel.bin
	ndisasm -b 32 $< > $@