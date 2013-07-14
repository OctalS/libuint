PROG = big_nums
OUT = libuint

CC = gcc
CFLAGS =

SRC = ./src
INC = ./include
BUILD = ./build

FLAGS = -g -I $(INC)

libuint:	clean

	mkdir $(BUILD)

	$(CC) -c $(FLAGS) $(CFLAGS)-o $(BUILD)/add.o $(SRC)/add.c
	$(CC) -c $(FLAGS) $(CFLAGS)-o $(BUILD)/mul.o $(SRC)/mul.c
	$(CC) -c $(FLAGS) $(CFLAGS)-o $(BUILD)/io.o $(SRC)/io.c
	$(CC) $(FLAGS) $(CFLAGS)-o $(OUT) $(SRC)/libuint.c $(BUILD)/*.o

example:
	make libuint

clean:
	rm -rf $(PROG) $(BUILD)

	
