CC = gcc
CFLAGS = -Og -Wall -g
LIBS = ./lib
INCLUDE = ./include
SRC = ./src

PROGS = alarm\
	fork\
	kill\
	myecho\
	snooze\
	waitpid1\
	waitpid2\
	shellex_cp\
	sigint\
	signal_v1\
	signal_v2\
	shell_v1

all: $(PROGS) $(LIBS)\libcsapp.so


# %.o:%.c
# 	$(CC) $(CFLAGS) -o $@ -c $^ 

$(PROGS): $(LIBS)/libcsapp.so

$(LIBS)/libcsapp.so: $(SRC)/csapp.c $(INCLUDE)/csapp.h
	gcc -shared -fpic -pthread -o $(LIBS)/libcsapp.so $(SRC)/csapp.c 


# clean up
clean:
	rm -f $(PROGS) *.o 