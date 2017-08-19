all:prim

prim:main.o prim.o
	gcc prim.o main.o -o prim -g

prim.o:prim.c
	gcc -g -c prim.c -o prim.o

main.o:main.c
	gcc -g -c main.c -o main.o

clean:
	rm -f prim *.txt *.o
