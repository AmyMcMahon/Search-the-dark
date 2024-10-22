CC = g++
CFLAGS = -Wall -std=c++17 -g
STRUCT = structures
TOOL = tools
OBJS = main.o triey.o inputy.o indexy.o mappy.o bubblySort.o syntaxy.o
TARGET = main

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

triey.o: $(STRUCT)/triey.cpp
	$(CC) $(CFLAGS) -c $(STRUCT)/triey.cpp

mappy.o: $(STRUCT)/mappy.cpp
	$(CC) $(CFLAGS) -c $(STRUCT)/mappy.cpp

inputy.o: $(TOOL)/inputy.cpp
	$(CC) $(CFLAGS) -c $(TOOL)/inputy.cpp

indexy.o: $(TOOL)/indexy.cpp
	$(CC) $(CFLAGS) -c $(TOOL)/indexy.cpp

bubblySort.o: $(TOOL)/bubblySort.cpp
	$(CC) $(CFLAGS) -c $(TOOL)/bubblySort.cpp

syntaxy.o: $(TOOL)/syntaxy.cpp
	$(CC) $(CFLAGS) -c $(TOOL)/syntaxy.cpp
	
clean:
	rm -f $(OBJS) $(TARGET)
