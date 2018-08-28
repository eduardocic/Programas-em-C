funcao:	funcao.c funcao.h
	gcc -c funcao.c

funcao_static_void:	funcao_static_void.c
	gcc -c funcao_static_void.c

main:	funcao.o funcao_static_void.o
	gcc funcao.o funcao_static_void.o -o main

clean:
	rm *.o