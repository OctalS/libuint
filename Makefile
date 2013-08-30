PROG = example
OUT = libuint

CC = gcc
AR = ar
CFLAGS =
SRC = ./src
INC = ./include
BUILD = ./build
OBJS = $(SRC)/add.o $(SRC)/and.o $(SRC)/bit.o $(SRC)/div.o $(SRC)/io.o $(SRC)/mul.o $(SRC)/or.o $(SRC)/shift.o $(SRC)/sub.o $(SRC)/xor.o

FLAGS = -O3 -Wall -fPIC -I $(INC)

prefix = /usr

shared: $(OBJS)
	$(CC) -shared -fPIC -I$(INC) $(CFLAGS) -o $(OUT).so $(OBJS) -lc

static: $(OBJS)
	$(AR) cr $(OUT).a $(OBJS)

example: $(OUT).so
	$(CC) -g -I$(INC) -L. -luint -Wl,-rpath,./ $(CFLAGS) -o $(PROG) $(SRC)/$(PROG).c

debug:
	make static CFLAGS=-g
	$(CC) -g -o $(PROG) $(SRC)/$(PROG).c $(OUT).a

%.o: %.c
	$(CC) -c $(FLAGS) -I $(INC) $(CFLAGS) -o $@ $<

install $(OUT).so:
	cp $(OUT).so $(prefix)/lib
	cp $(INC)/$(OUT).h $(prefix)/include

clean:
	rm -rf $(PROG) $(OUT)* $(OBJS)
