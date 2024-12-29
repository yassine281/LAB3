CC = gcc
CFLAGS = -Wall -Wextra -g
INCLUDE = -I./include

SRC = src/main.c src/container.c src/sort.c src/io.c src/data.c src/utils.c
OBJ = $(SRC:.c=.o)
TARGET = program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)