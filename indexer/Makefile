CC = g++
CFLAGS = -Wall -std=c++11 -g
STRUCT = ./structures
OBJS = indexer.o mappy.o vectory.o
TARGET = main

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

indexer.o: indexer.cpp
	$(CC) $(CFLAGS) -c indexer.cpp

mappy.o: $(STRUCT)/mappy.h
	$(CC) $(CFLAGS) -c $(STRUCT)/mappy.h

vectory.o: vectory.h
	$(CC) $(CFLAGS) -c vectory.h

clean:
	rm -f $(OBJS) $(TARGET)