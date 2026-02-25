CC = gcc
CFLAGS = -Wall -g

FILES = main.c services/service.c
OBJ = main.o services/service.o
TARGET = webserver

all: $(TARGET)
	
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

start:
	./webserver
	
clean:
	rm -f $(OBJ) $(TARGET)