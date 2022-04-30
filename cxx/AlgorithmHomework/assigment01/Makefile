CC=g++
CFLAG=-g -Og
obj=main.o 
.PHONY:test01
test01:$(obj)
	$(CC) $(CFLAG) $(obj)
main.o:main.cpp QuickFindUF.h
	$(CC) $(CFLAG) -c main.cpp -o main.o
.PHONY:clean
clean:
	rm -rf *.o test01
