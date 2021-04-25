#Compilers 
CC = gcc
CXX = g++

#Target Executable
BIN = ../bin

TARGET = CPPConcept
all: $(TARGET)
	@echo Buidling $(TARGET)

#Compile-time Flags
CPPFLAGS = -g -Wall -std=c++20

CUR_DIR = $(CURDIR)

#includes 
INCLUDES = -I../include/

#Library paths
LDFLAGS = 

#libraries to link with executable 
LIBS = -lm

#Source files 
SRCS = MoveCtr.cpp Main.cpp

OBJS = $(SRCS: .cpp = .o)

.PHONY: clean 

$(TARGET): $(OBJS)
	$(CXX) $(CFLAGS) $(INCLUDES) -o $(BIN)/$(TARGET) $(OBJS) $(LDFLAGS) $(LIBS)

.cpp.o: 
	$(CXX) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean: 
	rm -rf *.o *~ $(BIN)/$(TARGET)

print-%  : ; @echo $* = $($*)


