all:arvoreRN

arvoreRN:main.o arvoreRN.o
	gcc arvoreRN.o main.o -o rn -g

arvoreAVL.o:arvoreRN.c
	gcc -g -c arvoreRN.c -o arvoreRN.o

main.o:main.c
	gcc -g -c main.c -o main.o

clean:
	rm -f rn *.txt *.o
