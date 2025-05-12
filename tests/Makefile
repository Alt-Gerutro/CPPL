CC = g++
CFLAGS = -Wall -I../build/cppl -L../build/cppl -lcppl

TESTS = $(wildcard *.cpp)
OBJS = $(TESTS:.cpp=.o)

all: compile test_all

%.o: %.cpp
	$(CC) $(CFLAGS) -c $@ $<
