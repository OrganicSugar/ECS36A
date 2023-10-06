connectn.out: main.o board_creation.o play_game.o input_valid.o
	gcc -g -Werror -Wall main.o board_creation.o play_game.o input_valid.o -o connectn.out
board_creation.o: board_creation.c connectn.h
	gcc -c -g -Werror -Wall board_creation.c -o board_creation.o
play_game.o: play_game.c connectn.h
	gcc -c -g -Werror -Wall play_game.c -o play_game.o
input_valid.o: input_valid.c connectn.h
	gcc -c -g -Werror -Wall input_valid.c -o input_valid.o
main.o: main.c connectn.h
	gcc -c -g -Werror -Wall main.c -o main.o
clean:
	rm *.o connectn.out
