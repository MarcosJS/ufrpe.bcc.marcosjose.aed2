all:arvoreAVL

arvoreAVL:main.o arvoreAVL.o
	gcc arvoreAVL.o main.o -o avl

arvoreAVL.o:arvoreAVL.c
	gcc -g -c arvoreAVL.c -o arvoreAVL.o

main.o:main.c
	gcc -g -c main.c -o main.o

clean:
	rm -f avl saida.txt *.o
