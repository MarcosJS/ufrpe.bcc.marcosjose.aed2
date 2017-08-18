all:arvoreRN

arvoreRN:main.o argumento.o arvoreRN.o
	gcc arvoreRN.o argumento.o main.o -o rn -g

arvoreAVL.o:arvoreRN.c
	gcc -g -c arvoreRN.c -o arvoreRN.o
	
argumento.o:argumento.c
	gcc -g -c argumento.c -o argumento.o

main.o:main.c
	gcc -g -c main.c -o main.o

clean:
	rm -f rn *.txt *.o
