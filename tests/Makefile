CC=cc
CFLAGS=-Wall -Wextra -pedantic -I../include


SOURCES=test_cartridge.c

OBJS=$(SOURCES:%.c=%.o)
all: $(OBJS)
	echo "Building tests..."
	$(CC) $(CFLAGS) $^ -o $(basename $^)

%.c%.o: $(SOURCES)
	$(CC) $(CFLAGS) -c $< 


.phony clean:
	rm -rf *.o $(basename $(SOURCES))

 