CC = g++
CFLAGS = -Wall -I../build/cppl -L../build/cppl -lcppl

BUILD_DIR = ../build

TESTS = $(wildcard *.cpp)
OBJS = $(TESTS:.cpp=.o)

all: precomp compile test_all

precomp:
	cd $(BUILD_DIR) && make
	mv $(BUILD_DIR)/cppl .
	cd $(BUILD_DIR) && make clean

%.o: %.cpp
	$(CC) $(CFLAGS) -c $@ $<
