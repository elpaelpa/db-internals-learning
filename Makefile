CC = gcc
CFLAGS = -Wall -Wextra -g


db: main.c input_buffer.c input_buffer.h
	$(CC) $(CFLAGS) main.c input_buffer.c -o db

clean: 
	rm -f db