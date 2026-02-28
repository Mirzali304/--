CC = gcc
CFLAGS = -Wall -g
SRC = src/main.c src/game.c
OBJ = $(SRC:.c=.o)
TARGET = minesweeper

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
