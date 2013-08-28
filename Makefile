PROG = example
OUT = libuint

CC = gcc
AR = ar
CFLAGS =

SRC = ./src
INC = ./include
BUILD = ./build

FLAGS = -O3 -Wall -fPIC -I $(INC)

prefix = /usr

shared:
	make files
	$(CC) -shared -I$(INC) $(CFLAGS) -Wl,-soname,$(OUT).so -o $(OUT).so $(BUILD)/*.o -lc

static:
	make files
	$(AR) cr $(OUT).a $(BUILD)/*.o

example: $(OUT).so
	$(CC) -g -I$(INC) -L. -luint -Wl,-rpath,./ $(CFLAGS) -o $(PROG) $(SRC)/$(PROG).c

debug:
	make static CFLAGS=-g
	$(CC) -g -o $(PROG) $(SRC)/$(PROG).c $(OUT).a

files:	clean

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

install $(OUT).so:
	cp $(OUT).so $(prefix)/lib
	cp $(INC)/$(OUT).h $(prefix)/include

clean:
	rm -rf $(PROG) $(OUT)* $(BUILD)
