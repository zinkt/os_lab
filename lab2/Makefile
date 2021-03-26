main:	mult.o main.o
	gcc mult.o main.o -o main

main.o:	main.c mult.h
	gcc -c main.c

mult.o:	mult.c
	gcc -c mult.c

clean:
	rm *.o
	rm main