CC = gcc
CFLAGS = -Wall
TARGET = app1
SRC = main.c utils.c metricas.c
OBJ = $(SRC:.c=.o)


all: $(TARGET)


$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)


%.o: %.c
	$(CC) $(CFLAGS) -c $<


clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean 