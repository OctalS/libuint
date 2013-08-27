PROG = example
OUT = libuint

CC = gcc
CFLAGS =

SRC = ./src
INC = ./include
BUILD = ./build

FLAGS = -O3 -Wall -g -fPIC -I $(INC)

libuint:	clean

	mkdir $(BUILD)


	$(CC) -c $(FLAGS) $(CFLAGS) -o $(BUILD)/io.o $(SRC)/io.c
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(BUILD)/bit.o $(SRC)/bit.c
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(BUILD)/or.o $(SRC)/or.c
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(BUILD)/xor.o $(SRC)/xor.c
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(BUILD)/and.o $(SRC)/and.c
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(BUILD)/shift.o $(SRC)/shift.c
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(BUILD)/add.o $(SRC)/add.c
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(BUILD)/sub.o $(SRC)/sub.c
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(BUILD)/mul.o $(SRC)/mul.c
	$(CC) -c $(FLAGS) $(CFLAGS) -o $(BUILD)/div.o $(SRC)/div.c

	$(CC) -g -shared $(FLAGS) $(CFLAGS) -o $(OUT).so $(BUILD)/*.o

static:
	$(CC) -g $(FLAGS) $(CFLAGS) -o $(PROG) $(SRC)/libuint.c $(BUILD)/*.o

example:
	make libuint
	$(CC) -g -I$(INC) -L. -luint -Wl,-rpath,./ $(CFLAGS) -o $(PROG) $(SRC)/$(PROG).c

clean:
	rm -rf $(PROG) $(OUT) $(BUILD)
