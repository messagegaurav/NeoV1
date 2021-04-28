#Compilers 
CC = gcc
CXX = g++

#Target Executable
TARGET = Main

all: $(TARGET)
	@echo Buidling $(TARGET)

#Compile-time Flags
CPPFLAGS = -g3 -Wall -std=c++2a

DEBUG_FLAGS = -DDEBUG -g $(CPPFLAGS)
DEBUGEXE = Main

debug: $(DEBUGEXE)



CUR_DIR = $(CURDIR)

#includes 
INCLUDES = -I$(CUR_DIR)/include/

#Library paths
LDFLAGS = 

#libraries to link with executable 
LIBS = -lm

#Source files 
SRCS =	 $(CUR_DIR)/src/Main.cpp $(CUR_DIR)/src/MoveCtr.cpp

OBJS = $(SRCS: .cpp = .o)

.PHONY: clean 

$(TARGET): $(OBJS)
	$(CXX) $(CPPFLAGS) $(INCLUDES) -o $(CUR_DIR)/bin/$(TARGET) $(OBJS) $(LDFLAGS) $(LIBS)

$(DEBUGEXE): $(OBJS)
	$(CXX) $(CPPFLAGS) $(DEBUG_FLAGS) $(INCLUDES) -o $(CUR_DIR)/debug/$(DEBUGEXE) $(OBJS) $(LDFLAGS) $(LIBS)

.cpp.o: 
	$(CXX) $(CPPFLAGS) $(INCLUDES) -c $< -o $@

clean: 
	rm -rf *.o *~ ../bin/$(TARGET) ../debug/$(DEBUGEXE)

print-%  : ; @echo $* = $($*)


