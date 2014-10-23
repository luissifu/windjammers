#Source files
OBJS = $(wildcard *.cpp) $(wildcard */*.cpp) $(wildcard */*/*.cpp)

#Compiler
CC = g++

#Compiler Flags
COMP_FLAG = -w -std=c++11

#Linker Flags
LINK_FLAG = -lSDL2 -lGLU -lGL

#Name
NAME = build/windjammers

#Target
all : $(OBJS) 
	$(CC) $(OBJS) $(COMP_FLAG) $(LINK_FLAG) -o $(NAME)