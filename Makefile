CC=gcc

all: 
	$(CC) -g -Wall *.c -o result

test:
	./result

clean:
	rm result
