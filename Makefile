PROG = big_nums
OUT = libuint

CC = gcc
CFLAGS =

SRC = ./src
INC = ./include
BUILD = ./build

FLAGS = -Wall -I $(INC)

libuint:	clean

	mkdir $(BUILD)

	$(CC) $(FLAGS) $(CFLAGS)-o $(OUT) $(SRC)/libuint.c

example:
	make libuint

clean:
	rm -rf $(PROG) $(BUILD)

	
