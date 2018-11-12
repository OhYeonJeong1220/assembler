myas: main.o check.o trans.o
	gcc -o myas main.o check.o trans.o 
main.o: myas.h main.c
	gcc -c main.c
check.o: myas.h check.c
	gcc -c check.c
trans.o: myas.h trans.c
	gcc -c trans.c
clean:
	rm -f main.o check.o trans.o myas
