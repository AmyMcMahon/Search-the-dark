CC = g++
CFLAGS = -Wall -std=c++17 -g
STRUCT = ../structures
TOOL = ../tools
OBJS = indexer.o mappy.o indexy.o bubblySort.o
TARGET = indexer

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

indexer.o: indexer.cpp
	$(CC) $(CFLAGS) -c indexer.cpp

mappy.o: $(STRUCT)/mappy.cpp
	$(CC) $(CFLAGS) -c $(STRUCT)/mappy.cpp

indexy.o: $(TOOL)/indexy.cpp
	$(CC) $(CFLAGS) -c $(TOOL)/indexy.cpp

bubblySort.o: $(TOOL)/bubblySort.cpp
	$(CC) $(CFLAGS) -c $(TOOL)/bubblySort.cpp
	
clean:
	rm -f $(OBJS) $(TARGET)
