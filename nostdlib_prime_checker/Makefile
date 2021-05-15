all: sieve is_prime.o sieve_asm print.o sieve_nostdlib clean

sieve: sieve.c
	gcc -Wall -g sieve.c -o sieve

is_prime.o: is_prime.s
	nasm -f elf32 is_prime.s -o is_prime.o

sieve_asm: is_prime.o sieve_asm.c
	gcc -m32 is_prime.o sieve_asm.c	-o sieve_asm

print.o: print.s
	nasm -f elf32 print.s -o print.o

start.o: _start.s
	nasm -f elf32 _start.s -o start.o

sieve_nostdlib: start.o print.o is_prime.o sieve_nostdlib.c
	gcc -m32 -nostdlib start.o print.o is_prime.o sieve_nostdlib.c -o sieve_nostdlib
	
clean:
	rm *.o
