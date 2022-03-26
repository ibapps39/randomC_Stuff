CC = gcc
CFLAGS = -Wall -Wno-unused-variable 
LDFLAGS = -lm
CFILES = $(wildcard *.c)
OBJFILES = $(CFILES:.c=.o)
OUT = main

$(OUT): $(OBJFILES)
	$(CC) $(LDFLAGS) -o $@ $^

# Note: This is essentially the built-in Make rule for C projects, and so could be omitted with no issues
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

.PHONY: clean
clean:
	rm -f $(OBJFILES) $(OUT)
