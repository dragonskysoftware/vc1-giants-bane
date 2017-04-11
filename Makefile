# Makefile for Validian Chronicles 1: Giant's Bane
# Compiles code for the RPG
# Created by Andrew Davis
# Created on 3/9/2017
# All rights reserved

# define the compiler
CXX=clang++

# define the compiler flags
CPPFLAGS=-c -Wall -std=c++14 -Wno-unused-value

# define the library flags
LIBS=-lSDL2 -lSDL2_image -lSDL2_ttf -lm

# define the state-specific library flags
debug: CPPFLAGS += -g

# retrieve the source code
MAIN=$(shell ls src/*.cpp)
TEX=$(shell ls src/texture/*.cpp)
COMP=$(shell ls src/component/*.cpp)
UTIL=$(shell ls src/util/*.cpp)
EXCE=$(shell ls src/except/*.cpp)
DICE=$(shell ls src/dice/*.cpp)
DATA=$(shell ls src/data/*.cpp)
EVNT=$(shell ls src/event/*.cpp)
CORE=$(shell ls src/core/*.cpp)
STAT=$(shell ls src/stat/*.cpp)
ENTY=$(shell ls src/entity/*.cpp)

# compile the source code into a list
SOURCES=$(MAIN) $(TEX) $(COMP) $(UTIL) $(EXCE) $(DICE) $(DATA) $(EVNT) $(CORE) $(STAT) $(ENTY)

# map the source files to object files
OBJECTS=$(SOURCES:.cpp=.o)

# define the name of the executable
EXECUTABLE=GiantsBane

# start of build targets

# target to build the entire project without debug symbols
all: $(SOURCES) $(EXECUTABLE)

# target to compile the code
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LIBS)
	mkdir bin
	mkdir obj
	mv -f $@ bin/
	mv -f $(OBJECTS) obj/

# target to compile the code with debug symbols
debug: $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXECUTABLE) $(LIBS)
	mkdir bin
	mkdir obj
	mv -f $(EXECUTABLE) bin/
	mv -f $(OBJECTS) obj/

# target to compile the source code into object code
.cpp.o:
	$(CXX) $(CPPFLAGS) $< -o $@

# target to clean the workspace
clean:
	rm -rf bin
	rm -rf obj

# target to install the executable
install:
	cp bin/$(EXECUTABLE) /usr/bin/

# end of Makefile
