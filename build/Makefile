CC = g++
CFLAGS = -shared -fPIC
LDFLAGS = -fPIC -I$(INCLUDE_DIR) -std=c++20 

SRC_DIR = ../src
INCLUDE_DIR = ../include

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:.cpp=.o)

BUILD_DIR = cppl
TARGET = $(BUILD_DIR)/libcppl.so

all: clean precomp $(TARGET)

precomp:
	mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)
	cp $(INCLUDE_DIR)/cppl.hpp $(BUILD_DIR)

%.o: %.cpp
	$(CC) $(LDFLAGS) -c -o $@ $<

clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(OBJS)