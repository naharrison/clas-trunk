#! gnumake

#---------------------------------------------------
# The stripped down genr8 Makefile 
#---------------------------------------------------
#


INCLUDE := -I. -Iinc  
CC = cc

PROGRAM= genr8

lib: genr8.o genkin.o

exe: genr8
	mv genr8 $(TOP_DIR)/bin

genr8: genr8.o genkin.o
	$(CC) -v  -o $@  $^  -lm

genr8.o: genr8.c
	$(CC) -c -o genr8.o   genr8.c $(INCLUDE)

genkin.o: genkin.c
	$(CC) -c -o genkin.o   genkin.c $(INCLUDE)


clean:
	@rm  *.o 


install: genr8
	mv genr8 $(CLAS_BIN)/genr8
















