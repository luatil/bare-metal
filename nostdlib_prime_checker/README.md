# README

Aluno: Luã Nowacki Scavacini Santilli 
Nusp:  11795492

Esse projeto implementa uma função que checa se números são primos em diferentes
níves de abstração. 

O programa implementado em sieve.c age é comum. Ele chama stdio.h, e é um simples 
programa que checa primos. 

Já em sieve_asm.c a função is_prime é implementada em x86, como pode ser vista 
no arquivo is_prime.s.

E em sieve_nostdlib.c são removidas a função printf, e é criada uma rotina _start 
que chama main. Assim essa parte está associada aos arquivos print.s e _start.s.

O funcionamento de cada função compilada pelo Makefile é: 

    $ ./{nome_do_binario} <NUMBER> 

E imprime 1 em stdout caso o número seja primo, e 0 caso contrário. 

