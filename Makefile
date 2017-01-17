CC = g++
CFLAGS = -std=c++11 -stdlib=libc++

all: bst

bst: clean
	$(CC) $(CFLAGS) -o bst bst.cc
	./bst

clean:
	rm -f *.o bst

test: clean all
	./try
