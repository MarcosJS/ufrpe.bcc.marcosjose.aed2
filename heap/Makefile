all:heap

heap:main.o argumento.o auxiliar.o heap.o
	gcc heap.o argumento.o auxiliar.o main.o -o heap

heap.o:heap.c
	gcc -g -c heap.c -o heap.o

argumento.o:argumento.c
	gcc -g -c argumento.c -o argumento.o
	
auxiliar.o:auxiliar.c
	gcc -g -c auxiliar.c -o auxiliar.o

main.o:main.c
	gcc -g -c main.c -o main.o

clean:
	rm -f heap *.o saidai.dat
