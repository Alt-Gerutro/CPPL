CC = g++

BUILD_DIR = ../build

CFLAGS = -Wall -I../build/cppl -L../build/cppl -lcppl -std=c++20 -Wl,-rpath=$(BUILD_DIR)/cppl

all: precomp compile

precomp:
	cd $(BUILD_DIR) && make

compile:
	$(CC) $(CFLAGS) default_test.cpp -o default_test
	$(CC) $(CFLAGS) file_logging_test.cpp -o file_logging_test

clean:
	cd $(BUILD_DIR) && make clean
	rm -rf default_test file_logging_test
	rm -f "file_test.log"

test: all
	./default_test
	./file_logging_test
