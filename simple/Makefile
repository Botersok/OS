boot.bin: boot.asm
	nasm -f bin boot.asm -o boot.bin

run: *.bin
	qemu-system-i386 -fda $<

clean: 
	rm -fr *.bin