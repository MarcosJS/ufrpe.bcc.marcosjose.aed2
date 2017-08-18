all:arvoreAVL

arvoreAVL:main.o argumento.o arvoreAVL.o
	gcc arvoreAVL.o argumento.o main.o -o avl

arvoreAVL.o:arvoreAVL.c
	gcc -g -c arvoreAVL.c -o arvoreAVL.o

argumento.o:argumento.c
	gcc -g -c argumento.c -o argumento.o

main.o:main.c
	gcc -g -c main.c -o main.o

clean:
	rm -f avl *.txt *.o
