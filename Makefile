CC = g++
CFLAGS = -Wall -std=c++17 -g
STRUCT = structures
OBJS = main.o triey.o inputy.o
TARGET = main

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

triey.o: $(STRUCT)/triey.cpp
	$(CC) $(CFLAGS) -c $(STRUCT)/triey.cpp

inputy.o: inputy.cpp
	$(CC) $(CFLAGS) -c inputy.cpp

clean:
	rm -f $(OBJS) $(TARGET)
