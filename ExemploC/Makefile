all:lista.exe

lista.exe:main.o lista.o
	gcc lista.o main.o -o lista.exe

lista.o:lista.c
	gcc -c lista.c -o lista.o

main.o:main.c
	gcc -c main.c -o main.o

clean:
	rm -f lista.exe *.o
