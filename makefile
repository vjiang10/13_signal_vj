all: main.o
	gcc -o signal main.o

main.o: main.c
	gcc -c main.c

run:
	./signal

clean:
	rm *.o *.txt
