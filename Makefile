CC = g++

all: bst

bst: bst.o
	$(CC) $(CFLAGS) -o bst bst.o

bst.o:
	$(CC) $(CFLAGS) -c bst.cpp

clean:
	rm -f *.o try bst

test: clean all
	./try
