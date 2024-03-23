CXX = gcc
CFLAGS = -Wall -g

all: countdown

countdown: countdown.o
	$(CXX) $(CFLAGS) -o countdown countdown.o

clean:
	rm countdown

.PHONY: all clean
