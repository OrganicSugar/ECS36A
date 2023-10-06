mat_multiply.out: mat_multiply.c main.o
	gcc -g -Werror -Wall main.o mat_multiply.c -o mat_multiply.out
main.o: main.c mat_multiply.h
	gcc -c -g -Werror -Wall main.c -o main.o
clean:
	rm *.o mat_multiply.out
