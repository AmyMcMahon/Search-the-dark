CC = g++
CFLAGS = -Wall -std=c++17 -g
STRUCT = ../structures
OBJS = indexer.o mappy.o
TARGET = indexer

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

indexer.o: indexer.cpp
	$(CC) $(CFLAGS) -c indexer.cpp

mappy.o: $(STRUCT)/mappy.cpp
	$(CC) $(CFLAGS) -c $(STRUCT)/mappy.cpp

clean:
	rm -f $(OBJS) $(TARGET)
