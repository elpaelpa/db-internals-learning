CC = gcc
CFLAGS = -Wall -Wextra -g

SRCS = main.c input_buffer.c statement.c command.c row.c

db: $(SRCS) *.h
	$(CC) $(CFLAGS) $(SRCS) -o db

clean:
	rm -f db
