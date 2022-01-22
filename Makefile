#Compilers
CC = gcc
CXX = g++

#Target Executable
TARGET = Main



#Compile-time Flags
CPPFLAGS = -g -Wall -std=c++2a
BIN = $(CURDIR)/bin/

DEBUG_FLAGS = -DDEBUG -g $(CPPFLAGS)
DEBUGEXE = Main_debug
DEBUGDIR = $(CURDIR)/debug/

#Make Release build
all: $(TARGET)
	@echo Buidling $(TARGET)
	$(RUN)

#Make Debug Build
debug: $(DEBUGEXE)

#includes
INCLUDES = -I $(CURDIR)/include/

#Library paths
LDFLAGS =

#libraries to link with executable
LIBS = -lm

#Source files
SRCS =	 $(CURDIR)/src/*.cpp

OBJS = $(SRCS: .cpp = .o)

.PHONY: all clean

$(TARGET): $(OBJS)
	$(CXX) $(CPPFLAGS) $(INCLUDES) -o $(BIN)$(TARGET) $(OBJS) $(LDFLAGS) $(LIBS)

$(DEBUGEXE): $(OBJS)
	$(CXX) $(CPPFLAGS) $(DEBUG_FLAGS) $(INCLUDES) -o $(DEBUGDIR)$(DEBUGEXE) $(OBJS) $(LDFLAGS) $(LIBS)

.cpp.o:
	$(CXX) $(CPPFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf *.o *~ $(BIN)$(TARGET)
	rm -rf $(DEBUGDIR)$(DEBUGEXE)

LEAKS:
	valgrind --leak-check=full $(BIN)$(TARGET)

print-%  : ; @echo $* = $($*)


