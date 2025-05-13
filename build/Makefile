CC = g++
CXXFLAGS = -std=c++20 -fPIC -I$(INCLUDE_DIR)
LDFLAGS = -shared

SRC_DIR = ../src
INCLUDE_DIR = ../include

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

BUILD_DIR = cppl
TARGET = $(BUILD_DIR)/libcppl.so

all: clean precomp $(TARGET)

precomp:
	mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(TARGET)
	cp $(INCLUDE_DIR)/cppl.hpp $(BUILD_DIR)
	cp ../LICENSE $(BUILD_DIR)

%.o: %.cpp
	$(CC) $(CXXFLAGS) -MMD -MP -c -o $@ $<

-include $(DEPS)

clean:
	rm -rf $(BUILD_DIR)
	rm -f $(OBJS) $(DEPS)

.PHONY: all precomp clean
