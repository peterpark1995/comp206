main : main.c parse.o syntax.o parse.h syntax.h
	gcc -g -o main main.c parse.o syntax.o

parse.o : parse.c parse.h 
	gcc -c parse.c

syntax.o : syntax.c syntax.h parse.o parse.h
	gcc -c syntax.c

clean :
	rm -f *.o
	rm -f main
	
	
