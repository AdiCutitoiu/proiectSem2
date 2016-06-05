StringLibrary: main.o myString.o cmdHandler.o
	gcc -std=c99 main.o myString.o cmdHandler.o -o StringLibrary

main.o: main.c
	gcc -std=c99 -c main.c

myString.o: myString.c myString.h
	gcc -std=c99 -c myString.c

cmdHandler.o: cmdHandler.c cmdHandler.h
	gcc -std=c99 -c cmdHandler.c

clean:
	del *.o