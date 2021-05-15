factorial.o: factorial.s
	nasm -f elf32 factorial.s -o factorial.o

factorial: factorial.o
	ld -m elf_i386 factorial.o -o factorial
